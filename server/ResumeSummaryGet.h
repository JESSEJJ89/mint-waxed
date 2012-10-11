#ifndef RESUMESUMMARYGET_H
#define RESUMESUMMARYGET_H

#include <C2SRestMethodPrototypeGET.h>
#include <string>

class ResumeSummaryGet : public c2s::C2SRestMethodPrototypeGET<std::string>
{
        std::string jsonpCallback;

    public:

        explicit ResumeSummaryGet();

        virtual ~ResumeSummaryGet() {}

        c2s::C2SHttpResponse * process();

        ResumeSummaryGet * clone() const;

        ResumeSummaryGet(const ResumeSummaryGet &) = delete;

        ResumeSummaryGet & operator=(const ResumeSummaryGet & ) = delete;
};

#endif // RESUMESUMMARYGET_H
