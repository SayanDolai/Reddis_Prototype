#ifndef PERSISTENCE_H
#define PERSISTENCE_H

#include <string>
#include "StorageEngine.h"

class Persistence{
private:
    std::string filename;

public:

    Persistence(const std::string& file = "dump.rdb");

    void save(const StorageEngine& storage);

    void load(StorageEngine& storage);
};

#endif