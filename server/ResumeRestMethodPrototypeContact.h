#ifndef RESUMERESTMETHODPROTOTYPECONTACT_H
#define RESUMERESTMETHODPROTOTYPECONTACT_H

#include <C2SRestMethodPrototypeGET.h>
#include <DateTimeLogger.h>

class string;
class map;

class ResumeRestMethodPrototypeContact : public c2s::C2SRestMethodPrototypeGET<const char*>
{

    public:

        ResumeRestMethodPrototypeContact();

        virtual ~ResumeRestMethodPrototypeContact();

        c2s::C2SHttpResponse * process();

        ResumeRestMethodPrototypeContact * clone() const;

        ResumeRestMethodPrototypeContact(const ResumeRestMethodPrototypeContact & ) = delete;

        ResumeRestMethodPrototypeContact &operator=(const ResumeRestMethodPrototypeContact & ) = delete;

    private:

        c2s::io::DateTimeLogger *pLogger;
        std::map<std::string, std::string> data;
        std::string callbackParameter;
};

#endif // RESUMERESTMETHODPROTOTYPECONTACT_H
