#ifndef RESUMEJSONSTREAMER_H
#define RESUMEJSONSTREAMER_H

#include <C2SHttpEntityStreamerBase.h>
#include <C2SHttpMediaType.h>
#include <C2SHttpEntity.h>
#include <StringUtils.h>
#include <string>

template<class Type>
class ResumeJSONStreamer : public c2s::C2SHttpEntityStreamerBase<std::string>
{
    public:

        explicit ResumeJSONStreamer()
            : c2s::C2SHttpEntityStreamerBase<std::string>(std::string("application/javascript"))
        {}

        c2s::C2SHttpEntity * entity( const std::string &data ) const
        {
            return new c2s::C2SHttpEntity( data.c_str() , data.size() );
        }

/*
        c2s::C2SHttpEntity * entity( const Type &data ) const
        {
             return new c2s::C2SHttpEntity( data.c_str() , data.size() );
//            std::string sJSON = c2s::util::toString(data);
//            char *cdata = new char[ sJSON.size() ];
//            std::memcpy( cdata , sJSON.c_str() , sJSON.size() );
//            return new c2s::C2SHttpEntity( cdata , sJSON.size() , true );
        }
*/
        ResumeJSONStreamer(const ResumeJSONStreamer &) = delete;
        ResumeJSONStreamer &operator=(const ResumeJSONStreamer &) = delete;
};

#endif // RESUMEJSONSTREAMER_H
