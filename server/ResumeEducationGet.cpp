#include <ResumeEducationGet.h>
#include <ResumeJSONStreamer.h>
#include <client/dbclient.h>
#include <DateTimeLogger.h>


ResumeEducationGet::ResumeEducationGet()
    : C2SRestMethodPrototypeGET<const char*>("education")
{
    installEntityStreamer(new ResumeJSONStreamer<const char*>());

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

    return buildResponse(c2s::OK, educationJson.c_str());
}


ResumeEducationGet * ResumeEducationGet::clone() const
{
    return new ResumeEducationGet();
}
