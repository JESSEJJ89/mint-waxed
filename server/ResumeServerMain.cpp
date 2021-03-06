#include <C2SSettings.h>
#include <C2SRestResourcePrototype.h>
#include <C2SHttpServer.h>

#include <ResumeContactGet.h>
#include <ResumeSummaryGet.h>
#include <ResumeCompaniesGet.h>
#include <ResumeRolesGet.h>
#include <ResumeEducationGet.h>
#include <ResumeSkillsGet.h>

#include <string>

int main(int arg, char** argv)
{
    c2s::C2SSettings serverSettings;
    serverSettings.iPort = 8080;
    c2s::C2SHttpServer httpServer(serverSettings);

    // memory managed by C2SHttpServer::registerResourcePrototype
    c2s::C2SRestResourcePrototype * pRestResources = c2s::C2SRestResourcePrototype::createRestResourceWithContextRoot("resume");

    // memory managed by C2SRestResourcePrototype::registerMethodPrototype
    pRestResources->registerMethodPrototype(new ResumeContactGet());
    pRestResources->registerMethodPrototype(new ResumeSummaryGet());
    pRestResources->registerMethodPrototype(new ResumeCompaniesGet());
    pRestResources->registerMethodPrototype(new ResumeRolesGet());
    pRestResources->registerMethodPrototype(new ResumeEducationGet());
    pRestResources->registerMethodPrototype(new ResumeSkillsGet());

    httpServer.registerResourcePrototype(pRestResources);

    httpServer.run();

    return 0;
}
