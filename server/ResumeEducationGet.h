#ifndef RESUMEEDUCATIONGET_H
#define RESUMEEDUCATIONGET_H

#include <C2SRestMethodPrototypeGET.h>
#include <string>

class ResumeEducationGet : public c2s::C2SRestMethodPrototypeGET<const char *>
{
        std::string jsonpCallback;

    public:

        explicit ResumeEducationGet();

        virtual ~ResumeEducationGet() {}

        c2s::C2SHttpResponse * process();

        ResumeEducationGet * clone() const;

        ResumeEducationGet(const ResumeEducationGet&) = delete;

        ResumeEducationGet & operator=(const ResumeEducationGet &) = delete;
};

#endif // RESUMEEDUCATIONGET_H
