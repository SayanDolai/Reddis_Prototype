#ifndef COMMAND_EXECUTOR_H
#define COMMAND_EXECUTOR_H

#include <vector>
#include <string>
#include "StorageEngine.h"
#include "Persistence.h"
#include<iostream>

class CommandExecutor{
private:
    StorageEngine& storage;
    Persistence& persistence;
public:
    CommandExecutor(StorageEngine& storage,Persistence& persistence) ;
    void execute(const vector<string>& tokens);
};

#endif