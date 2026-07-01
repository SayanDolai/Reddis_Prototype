#include <iostream>
#include "../include/RedisServer.h"

using namespace std;

int main()
{
    cout << "=========================================\n";
    cout << "        Mini Redis (C++ Clone)\n";
    cout << "=========================================\n\n";

    cout << "Supported Commands\n";
    cout << "-----------------------------------------\n";
    cout << "SET <key> <value>      : Store a value\n";
    cout << "GET <key>              : Retrieve a value\n";
    cout << "DEL <key>              : Delete a key\n";
    cout << "EXISTS <key>           : Check if key exists\n";
    cout << "KEYS                   : Display all keys\n";
    cout << "EXPIRE <key> <seconds> : Set TTL\n";
    cout << "TTL <key>              : Show remaining TTL\n";
    cout << "SAVE                   : Save database to disk\n";
    cout << "LOAD                   : Load database from disk\n";
    cout << "EXIT                   : Exit Mini Redis\n";
    cout << "-----------------------------------------\n\n";

    RedisServer server;
    server.start();

    return 0;
}