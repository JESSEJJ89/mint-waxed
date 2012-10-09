#include "ResumeCompaniesGet.h"
#include <ResumeJSONStreamer.h>
#include <client/dbclient.h>
#include <DateTimeLogger.h>
#include <memory>


ResumeCompaniesGet::ResumeCompaniesGet()
    : c2s::C2SRestMethodPrototypeGET<const char*>("companies")
{
    installEntityStreamer(new ResumeJSONStreamer<const char*>());

    addQueryParameter("callback", &jsonpCallback, "");
}

c2s::C2SHttpResponse * ResumeCompaniesGet::process()
{
    c2s::io::DateTimeLogger log("companies");
    mongo::DBClientConnection mongo;
    mongo::BSONObj companies;

    try
    {
        mongo.connect("localhost");
        std::unique_ptr<mongo::DBClientCursor> cursor = mongo.query("test.resume.companies", mongo::Query());

        mongo::BSONObjBuilder objBuilder;
        mongo::BSONObjBuilder subObjBuilder(objBuilder.subarrayStart("companies"));

        while( cursor->more() )
            subObjBuilder.append("companies", cursor->next());

        subObjBuilder.done();

        companies = objBuilder.obj();
    }
    catch(mongo::ConnectException ex)
    {
        log.error(std::string("Connection Exception: ") + ex.what());
        companies = BSON("DB Connection Failed." << ex.toString() << "isError" << true);
    }
    catch(mongo::DBException ex)
    {
        log.error(std::string("Database Exception: ") + ex.what());
        log.error(mongo.getLastError());
        companies = BSON("DB Query Failed." << ex.toString()  << "isError" << true);
    }

    std::string companiesJson = companies.jsonString();

    if (jsonpCallback.size())
    {
        jsonpCallback += "(" + companiesJson + ");";
        companiesJson = jsonpCallback;
    }

    c2s::C2SHttpResponse * pResponse = buildResponse(c2s::OK, companiesJson.c_str());
    pResponse->header().Fields.set("Access-Control-Allow-Origin", "*");
    return pResponse;
}

ResumeCompaniesGet * ResumeCompaniesGet::clone() const
{
    return new ResumeCompaniesGet();
}
