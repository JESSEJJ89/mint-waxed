#ifndef RESUMEROLESGET_H
#define RESUMEROLESGET_H

#include <C2SRestMethodPrototypeGET.h>
#include <string>

class ResumeRolesGet : public c2s::C2SRestMethodPrototypeGET<const char*>
{
        std::string jsonpCallback;

    public:

        explicit ResumeRolesGet();

        virtual ~ResumeRolesGet() {}

        c2s::C2SHttpResponse * process();

        ResumeRolesGet * clone() const;

        ResumeRolesGet(const ResumeRolesGet &) = delete;

        ResumeRolesGet & operator=(const ResumeRolesGet &) = delete;
};

#endif // RESUMEROLESGET_H
