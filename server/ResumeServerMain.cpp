#include <string>

#include "ResumeRestMethodPrototypeContact.h"

#include "C2SSettings.h"
#include "C2SRestResourcePrototype.h"
#include "C2SHttpServer.h"


int main(int arg, char** argv)
{
    c2s::C2SSettings serverSettings;
    serverSettings.iPort = 8080;
    c2s::C2SHttpServer httpServer(serverSettings);
    const std::string contextName = "resume";

    // create contact endpoint
    c2s::C2SRestResourcePrototype *pResourceContact = c2s::C2SRestResourcePrototype::createRestResourceWithContextRoot(contextName);

    pResourceContact->registerMethodPrototype(new ResumeRestMethodPrototypeContact());

    httpServer.registerResourcePrototype(pResourceContact);
    httpServer.run();

    return 0;
}
