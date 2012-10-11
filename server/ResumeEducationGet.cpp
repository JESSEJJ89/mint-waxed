#include <ResumeEducationGet.h>
#include <ResumeJSONStreamer.h>
#include <client/dbclient.h>
#include <DateTimeLogger.h>


ResumeEducationGet::ResumeEducationGet()
    : C2SRestMethodPrototypeGET<std::string>(std::string("education"))
{
    installEntityStreamer(new ResumeJSONStreamer<std::string>());
    addQueryParameter("callback", &jsonpCallback, "");
}

c2s::C2SHttpResponse * ResumeEducationGet::process()
{
    c2s::io::DateTimeLogger log("education");
    mongo::DBClientConnection mongo;
    mongo::BSONObj education;

    try
    {
        mongo.connect("localhost");
        education = mongo.findOne("test.resume.education", mongo::Query());
    }
    catch(mongo::ConnectException ex)
    {
        log.error(std::string("Connection Exception: ") + ex.what());
        education = BSON("DB Connection Failed." << ex.toString() << "isError" << true);
    }
    catch(mongo::DBException ex)
    {
        log.error(std::string("Database Exception: ") + ex.what());
        log.error(mongo.getLastError());
        education = BSON("DB Query Failed." << ex.toString()  << "isError" << true);
    }

    std::string educationJson = education.jsonString();

    if (jsonpCallback.size())
    {
        jsonpCallback += "(" + educationJson + ");";
        educationJson = jsonpCallback;
    }

    c2s::C2SHttpResponse * pResponse = buildResponse(c2s::OK, educationJson);
    pResponse->header().Fields.set("Access-Control-Allow-Origin", "*");
    pResponse->header().Fields.set("Content-Type", "application/json; charset=utf-8");
    return pResponse;
}


ResumeEducationGet * ResumeEducationGet::clone() const
{
    return new ResumeEducationGet();
}
