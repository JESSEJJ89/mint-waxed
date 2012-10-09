#ifndef RESUMECOMPANIESGET_H
#define RESUMECOMPANIESGET_H

#include <C2SRestMethodPrototypeGET.h>
#include <string>

class ResumeCompaniesGet : public c2s::C2SRestMethodPrototypeGET<const char *>
{
        std::string jsonpCallback;

    public:

        explicit ResumeCompaniesGet();

        virtual ~ResumeCompaniesGet() {}

        c2s::C2SHttpResponse * process();

        ResumeCompaniesGet * clone() const;

        ResumeCompaniesGet(const ResumeCompaniesGet & ) = delete;

        ResumeCompaniesGet & operator=(const ResumeCompaniesGet & ) = delete;
};

#endif // RESUMECOMPANIESGET_H
