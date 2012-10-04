#ifndef RESUMEJSONHTTPENTITYSTREAMER_H
#define RESUMEJSONHTTPENTITYSTREAMER_H

#include <C2SHttpEntityStreamerBase.h>
#include <C2SHttpMediaType.h>
#include <C2SHttpEntity.h>
#include <StringUtils.h>
#include <string>

template<class Type>
class ResumeJSONHttpEntityStreamer : public c2s::C2SHttpEntityStreamerBase<Type>
{
    public:

        ResumeJSONHttpEntityStreamer()
            : c2s::C2SHttpEntityStreamerBase<Type>(c2s::C2SHttpMediaType::application__json+"; charset=utf-8")
        {}

        c2s::C2SHttpEntity *entity( const Type &data ) const
        {
            std::string sJSON = c2s::util::toString(data);
            char *cdata = new char[ sJSON.size() ];
            std::memcpy( cdata , sJSON.c_str() , sJSON.size() );
            return new c2s::C2SHttpEntity( cdata , sJSON.size() , true );
        }

        ResumeJSONHttpEntityStreamer(const ResumeJSONHttpEntityStreamer &) = delete;

        ResumeJSONHttpEntityStreamer &operator=(const ResumeJSONHttpEntityStreamer &) = delete;
};

#endif // RESUMEJSONHTTPENTITYSTREAMER_H