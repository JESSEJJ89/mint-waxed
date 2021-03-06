#include <ResumeContactGet.h>
#include <ResumeJSONStreamer.h>
#include <client/dbclient.h>
#include <DateTimeLogger.h>


ResumeContactGet::ResumeContactGet()
    : c2s::C2SRestMethodPrototypeGET<std::string>(std::string("contact"))
{
    installEntityStreamer(new ResumeJSONStreamer<std::string>());
    addQueryParameter("callback", &jsonpCallback, "");
}

c2s::C2SHttpResponse * ResumeContactGet::process()
{            
    c2s::io::DateTimeLogger log("contact");
    mongo::DBClientConnection mongo;
    mongo::BSONObj contact;

    try
    {
        mongo.connect("localhost");
        contact = mongo.findOne("test.resume.contacts", mongo::Query());
    }
    catch(mongo::ConnectException ex)
    {
        log.error(std::string("Connection Exception: ") + ex.what());
        contact = BSON("DB Connection Failed." << ex.toString() << "isError" << true);
    }
    catch(mongo::DBException ex)
    {
        log.error(std::string("Database Exception: ") + ex.what());
        log.error(mongo.getLastError());
        contact = BSON("DB Query Failed." << ex.toString()  << "isError" << true);
    }

    std::string contactJson = contact.jsonString();

    if (jsonpCallback.size())
    {
        jsonpCallback += "(" + contactJson + ");";
        contactJson = jsonpCallback;
    }

    c2s::C2SHttpResponse * pResponse = buildResponse(c2s::OK, contactJson);
    pResponse->header().Fields.set("Access-Control-Allow-Origin", "*");
    pResponse->header().Fields.set("Content-Type", "application/json; charset=utf-8");
    return pResponse;
}


ResumeContactGet * ResumeContactGet::clone() const
{
    return new ResumeContactGet();
}
