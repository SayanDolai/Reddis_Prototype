#include "../include/RedisServer.h"

#include <iostream>
using namespace std;

RedisServer::RedisServer()
    : persistence("dump.rdb"),
      executor(storage, persistence)
{
}

void RedisServer::start(){
    string input;
    while(true){
        cout << "MiniRedis> ";
        getline(cin, input);
        if(input == "EXIT")break;
        auto tokens = parser.parse(input);
        executor.execute(tokens);
    }
}