#ifndef REDIS_SERVER_H
#define REDIS_SERVER_H

#include "../include/CommandParse.h"
#include "../include/CommandExecutor.h"
#include "../include/StorageEngine.h"

class RedisServer{
private:
    StorageEngine storage;
    CommandParser parser;
    CommandExecutor executor;
    Persistence persistence;

public:
    RedisServer();

    void start();
};

#endif