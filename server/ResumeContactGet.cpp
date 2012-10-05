#include <ResumeJSONStreamer.h>
#include <ResumeContactGet.h>

#include <string>
#include <sstream>
#include <map>

ResumeContactGet::ResumeContactGet()
    : c2s::C2SRestMethodPrototypeGET<const char*>("contact")
{
    installEntityStreamer(new ResumeJSONStreamer<const char*>());

    addQueryParameter("callback", &callbackParameter, "");

    data["name"] = "Charles Fordyce";
    data["email"] = "charlesfordyce@gmail.com";
    data["phone"] = "360-821-1630";
    data["address"] = "215 Clayton PL NW";
    data["city"] = "Bainbridge Island";
    data["state"] = "WA";
    data["zip"] = "98110";
}

c2s::C2SHttpResponse * ResumeContactGet::process()
{            
    std::stringstream ss;

    ss << "{";

    for (auto field : data)
        ss << "\"" << field.first << "\":\"" << field.second << "\",";

    std::string contactJson = ss.str();

    contactJson.replace(contactJson.size()-1, (size_t) 1, "}");

    if (callbackParameter.size())
    {
        callbackParameter += "(" + contactJson + ");";
        contactJson = callbackParameter;
    }

    return buildResponse(c2s::OK, contactJson.c_str());
}


ResumeContactGet * ResumeContactGet::clone() const
{
    return new ResumeContactGet();
}
