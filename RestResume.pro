QMAKE_CXXFLAGS += -std=c++11
TEMPLATE = app
CONFIG += console
CONFIG -= qt

INCLUDEPATH += \
    /home/chas/seomoz/c2s/mint-waxed/server \
    /home/chas/seomoz/c2s/mint-waxed/client \
    /home/chas/seomoz/c2s/mint-waxed/test \
    /home/chas/c2serve/include/c2s/c2s-log \
    /home/chas/c2serve/include/c2s/c2s-util \
    /home/chas/c2serve/include/c2s/c2s-util/io \
    /home/chas/c2serve/include/c2s/c2s-core \
    /home/chas/c2serve/include/c2s/c2s-http \
    /home/chas/c2serve/include/c2s/c2s-rest

LIBS += \
    /home/chas/c2serve/lib/libc2s_rest.a \
    /home/chas/c2serve/lib/libc2s_http.a \
    /home/chas/c2serve/lib/libc2s_util.a \
    /home/chas/c2serve/lib/libc2s_core.a \
    /home/chas/c2serve/lib/libc2s_socket.a \
    /home/chas/c2serve/lib/libc2s_log.a \
    -pthread

SOURCES +=  \
    server/ResumeRestMethodPrototypeContact.cpp \
    server/ResumeServerMain.cpp
#    test/test.cpp



HEADERS += \
    server/ResumeJSONHttpEntityStreamer.h \
    server/ResumeRestMethodPrototypeContact.h

