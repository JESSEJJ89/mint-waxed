#ifndef RESUMESUMMARYGET_H
#define RESUMESUMMARYGET_H

#include <C2SRestMethodPrototypeGET.h>

class string;
class map;

class ResumeSummaryGet : public c2s::C2SRestMethodPrototypeGET<const char*>
{
    public:
        ResumeSummaryGet();

        virtual ~ResumeSummaryGet() {}

        c2s::C2SHttpResponse * process();

        ResumeSummaryGet * clone() const;

        ResumeSummaryGet(const ResumeSummaryGet &) = delete;

        ResumeSummaryGet & operator=(const ResumeSummaryGet & ) = delete;

    private:

        std::map<std::string, std::string> data;
        std::string callbackParameter;

};

#endif // RESUMESUMMARYGET_H
