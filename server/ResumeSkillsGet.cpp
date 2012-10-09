#include "ResumeSkillsGet.h"
#include <ResumeJSONStreamer.h>
#include <client/dbclient.h>
#include <DateTimeLogger.h>

ResumeSkillsGet::ResumeSkillsGet()
: c2s::C2SRestMethodPrototypeGET<const char*>("skills")
{
    installEntityStreamer(new ResumeJSONStreamer<const char*>());

    addQueryParameter("callback", &jsonpCallback, "");
}

c2s::C2SHttpResponse * ResumeSkillsGet::process()
{
    c2s::io::DateTimeLogger log("skills");
    mongo::DBClientConnection mongo;
    mongo::BSONObj skills;

    try
    {
        mongo.connect("localhost");
        skills = mongo.findOne("test.resume.skills", mongo::Query());
    }
    catch(mongo::ConnectException ex)
    {
        log.error(std::string("Connection Exception: ") + ex.what());
        skills = BSON("DB Connection Failed." << ex.toString() << "isError" << true);
    }
    catch(mongo::DBException ex)
    {
        log.error(std::string("Database Exception: ") + ex.what());
        log.error(mongo.getLastError());
        skills = BSON("DB Query Failed." << ex.toString()  << "isError" << true);
    }

    std::string skillsJson = skills.jsonString();

    if (jsonpCallback.size())
    {
        jsonpCallback += "(" + skillsJson + ");";
        skillsJson = jsonpCallback;
    }

    return buildResponse(c2s::OK, skillsJson.c_str());
}

ResumeSkillsGet * ResumeSkillsGet::clone() const
{
    return new ResumeSkillsGet();
}
