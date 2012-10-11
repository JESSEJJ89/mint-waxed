#include <ResumeRolesGet.h>
#include <ResumeJSONStreamer.h>
#include <client/dbclient.h>
#include <DateTimeLogger.h>
#include <memory>


ResumeRolesGet::ResumeRolesGet()
    : c2s::C2SRestMethodPrototypeGET<std::string>(std::string("roles"))
{
    installEntityStreamer(new ResumeJSONStreamer<std::string>());
    addQueryParameter("callback", &jsonpCallback, "");
}

c2s::C2SHttpResponse * ResumeRolesGet::process()
{
    c2s::io::DateTimeLogger log("roles");
    mongo::DBClientConnection mongo;
    mongo::BSONObj roles;

    try
    {
        mongo.connect("localhost");
        std::unique_ptr<mongo::DBClientCursor> cursor = mongo.query("test.resume.roles", mongo::Query());

        mongo::BSONObjBuilder objBuilder;
        mongo::BSONObjBuilder subObjBuilder(objBuilder.subarrayStart("roles"));

        while( cursor->more() )
            subObjBuilder.append("roles", cursor->next());

        subObjBuilder.done();

        roles = objBuilder.obj();
    }
    catch(mongo::ConnectException ex)
    {
        log.error(std::string("Connection Exception: ") + ex.what());
        roles = BSON("DB Connection Failed." << ex.toString() << "isError" << true);
    }
    catch(mongo::DBException ex)
    {
        log.error(std::string("Database Exception: ") + ex.what());
        log.error(mongo.getLastError());
        roles = BSON("DB Query Failed." << ex.toString()  << "isError" << true);
    }

    std::string rolesJson = roles.jsonString();

    if (jsonpCallback.size())
    {
        jsonpCallback += "(" + rolesJson + ");";
        rolesJson = jsonpCallback;
    }

    c2s::C2SHttpResponse * pResponse = buildResponse(c2s::OK, rolesJson);
    pResponse->header().Fields.set("Access-Control-Allow-Origin", "*");
    pResponse->header().Fields.set("Content-Type", "application/json; charset=utf-8");
    return pResponse;
}

ResumeRolesGet * ResumeRolesGet::clone() const
{
    return new ResumeRolesGet();
}
