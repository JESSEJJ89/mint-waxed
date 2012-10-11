#ifndef RESUMECONTACTGET_H
#define RESUMECONTACTGET_H

#include <C2SRestMethodPrototypeGET.h>
#include <string>

class ResumeContactGet : public c2s::C2SRestMethodPrototypeGET<std::string>
{
        std::string jsonpCallback;

    public:

        explicit ResumeContactGet();

        virtual ~ResumeContactGet() {}

        c2s::C2SHttpResponse * process();

        ResumeContactGet * clone() const;

        ResumeContactGet(const ResumeContactGet & ) = delete;

        ResumeContactGet & operator=(const ResumeContactGet & ) = delete;
};

#endif // RESUMECONTACTGET_H
