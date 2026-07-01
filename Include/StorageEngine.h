#ifndef STORAGE_ENGINE_H
#define STORAGE_ENGINE_H

#include <string>
#include <unordered_map>
#include <vector>

using namespace std ;

class StorageEngine {
private:
    unordered_map<string,string> database;

public:
    void set(const std::string& key, const std::string& value);
    string get(const std::string& key) const;
    bool del(const std::string& key);
    bool exists(const std::string& key) const;
    vector<string> keys() const;
    const std::unordered_map<std::string, std::string>& getDatabase() const;
    void insert(const std::string& key, const std::string& value);
};

#endif