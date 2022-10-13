#include <drogon/drogon.h>
int main() {
    //Set HTTP listener address and port
    LOG_INFO << "Create the web server.";
    drogon::app().addListener("0.0.0.0",30001);
    LOG_INFO << "WebServer run on the 0.0.0.0:30001.";
    drogon::app().loadConfigFile("../config.json");
    LOG_INFO << "Loaded config from ../config.json";
    //Run HTTP framework,the method will block in the internal event loop
    drogon::app().run();
    LOG_INFO << "Webserver has finished startup!Try to open the web to confirm its status.";

    return 0;
    drogon::utils::getUuid()  ;
}
