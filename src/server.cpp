#include <cpprest/http_listener.h>
#include <cpprest/json.h>

using namespace web;
using namespace web::http;
using namespace web::http::experimental::listener;
using namespace web::json; 

#include <iostream>
#include <string>
using namespace std;

#define TRACE(msg)            wcout << msg

void handle_get(http_request request)
{
    TRACE(L"\nhandle GET\n");

    json::value j;
    j["message"] =  json::value::string(U("hello there"));
    j["pi"] = 3.141;
    request.reply(status_codes::OK, j);
}

void handle_post(http_request request)
{
    TRACE("\nhandle POST\n");
}

void handle_put(http_request request)
{
    TRACE("\nhandle PUT\n");
}

void handle_del(http_request request)
{
    TRACE("\nhandle DEL\n");
}

int main()
{
    http_listener listener(U("http://127.0.0.1:39249"));

    listener.support(methods::GET, handle_get);
    listener.support(methods::POST, handle_post);
    listener.support(methods::PUT, handle_put);
    listener.support(methods::DEL, handle_del);

    try
    {
        listener
            .open()
            .then([&listener]() {TRACE(L"\nstarting to listen\n"); })
            .wait();

        while (true);
    }
    catch (exception const& e)
    {
        wcout << e.what() << endl;
    }

    return 0;
}