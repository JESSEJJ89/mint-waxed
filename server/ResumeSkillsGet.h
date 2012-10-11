#ifndef RESUMESKILLSGET_H
#define RESUMESKILLSGET_H

#include <C2SRestMethodPrototypeGET.h>
#include <string>

class ResumeSkillsGet : public c2s::C2SRestMethodPrototypeGET<std::string>
{
        std::string jsonpCallback;

    public:
        explicit ResumeSkillsGet();

        virtual ~ResumeSkillsGet() {}

        c2s::C2SHttpResponse * process();

        ResumeSkillsGet * clone() const;

        ResumeSkillsGet(const ResumeSkillsGet &) = delete;

        ResumeSkillsGet & operator=(const ResumeSkillsGet &) = delete;
};

#endif // RESUMESKILLSGET_H
