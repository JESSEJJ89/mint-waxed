#include <ResumeSummaryGet.h>
#include <ResumeJSONStreamer.h>
#include <client/dbclient.h>
#include <DateTimeLogger.h>


ResumeSummaryGet::ResumeSummaryGet()
    : c2s::C2SRestMethodPrototypeGET<const char*>("summary")
{
    installEntityStreamer(new ResumeJSONStreamer<const char*>());

    addQueryParameter("callback", &jsonpCallback, "");
}

c2s::C2SHttpResponse * ResumeSummaryGet::process()
{
    c2s::io::DateTimeLogger log("summary");
    mongo::DBClientConnection mongo;
    mongo::BSONObj summary;

    try
    {
        mongo.connect("localhost");
        summary = mongo.findOne("test.resume.summaries", mongo::Query());
    }
    catch(mongo::ConnectException ex)
    {
        log.error(std::string("Connection Exception: ") + ex.what());
        summary = BSON("DB Connection Failed." << ex.toString() << "isError" << true);
    }
    catch(mongo::DBException ex)
    {
        log.error(std::string("Database Exception: ") + ex.what());
        log.error(mongo.getLastError());
        summary = BSON("DB Query Failed." << ex.toString()  << "isError" << true);
    }

    std::string summaryJson = summary.jsonString();

    if (jsonpCallback.size())
    {
        jsonpCallback += "(" + summaryJson + ");";
        summaryJson = jsonpCallback;
    }

    return buildResponse(c2s::OK, summaryJson.c_str());
}


ResumeSummaryGet * ResumeSummaryGet::clone() const
{
    return new ResumeSummaryGet();
}
