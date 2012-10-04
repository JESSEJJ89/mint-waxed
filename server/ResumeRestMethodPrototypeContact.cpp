#include <ResumeJSONHttpEntityStreamer.h>
#include <ResumeRestMethodPrototypeContact.h>

#include <string>
#include <sstream>
#include <map>

ResumeRestMethodPrototypeContact::ResumeRestMethodPrototypeContact()
    : c2s::C2SRestMethodPrototypeGET<const char*>("contact"),
      pLogger(new c2s::io::DateTimeLogger("contact"))
{
    installEntityStreamer(new ResumeJSONHttpEntityStreamer<const char*>());

    addQueryParameter("callback", &callbackParameter, "");

    data["name"] = "Charles Fordyce";
    data["email"] = "charlesfordyce@gmail.com";
    data["phone"] = "360-821-1630";
    data["address"] = "215 Clayton PL NW";
    data["city"] = "Bainbridge Island";
    data["state"] = "WA";
    data["zip"] = "98110";
}


ResumeRestMethodPrototypeContact::~ResumeRestMethodPrototypeContact()
{
    delete pLogger;
}


c2s::C2SHttpResponse * ResumeRestMethodPrototypeContact::process()
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

    pLogger->info(contactJson);

    return buildResponse(c2s::OK, contactJson.c_str());
}


ResumeRestMethodPrototypeContact * ResumeRestMethodPrototypeContact::clone() const
{
    return new ResumeRestMethodPrototypeContact();
}
