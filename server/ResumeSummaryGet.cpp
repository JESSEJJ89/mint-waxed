#include <ResumeSummaryGet.h>
#include <ResumeJSONStreamer.h>

ResumeSummaryGet::ResumeSummaryGet()
    : c2s::C2SRestMethodPrototypeGET<const char*>("summary")
{
    installEntityStreamer(new ResumeJSONStreamer<const char*>());

    addQueryParameter("callback", &callbackParameter, "");

    std::stringstream ss;
    ss <<  "Innovative software development and integration professional adept at " <<
           "designing, building and testing software applications, hiring and managing testing " <<
           "teams and helping deliver accurate, customer-focused products.  Practiced at developing, " <<
           "debugging and testing tiered applications; focused on products written in C++, Java, Perl.  " <<
           "Strong Agile experience and certified Scrum Master.  Recent projects include management and " <<
           "contributing work on functional, integration and load testing enterprise-scale Java SOA and " <<
           "RESTful web services and multimedia web applications.";

    data["summary"] = ss.str();
    data["objective"] = "Software Engineer";
}

c2s::C2SHttpResponse * ResumeSummaryGet::process()
{
    std::stringstream ss;

    ss << "{";

    for (auto field : data)
        ss << "\"" << field.first << "\":\"" << field.second << "\",";

    std::string summaryJson = ss.str();

    summaryJson.replace(summaryJson.size()-1, (size_t) 1, "}");

    if (callbackParameter.size())
    {
        callbackParameter += "(" + summaryJson + ");";
        summaryJson = callbackParameter;
    }

    return buildResponse(c2s::OK, summaryJson.c_str());
}


ResumeSummaryGet * ResumeSummaryGet::clone() const
{
    return new ResumeSummaryGet();
}
