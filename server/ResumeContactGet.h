#ifndef RESUMECONTACTGET_H
#define RESUMECONTACTGET_H

#include <C2SRestMethodPrototypeGET.h>

class string;
class map;

class ResumeContactGet : public c2s::C2SRestMethodPrototypeGET<const char*>
{
    public:

        ResumeContactGet();

        virtual ~ResumeContactGet() {}

        c2s::C2SHttpResponse * process();

        ResumeContactGet * clone() const;

        ResumeContactGet(const ResumeContactGet & ) = delete;

        ResumeContactGet & operator=(const ResumeContactGet & ) = delete;

    private:

        std::map<std::string, std::string> data;
        std::string callbackParameter;
};

#endif // RESUMECONTACTGET_H
