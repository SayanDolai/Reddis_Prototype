#include "../include/StorageEngine.h"
#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

void StorageEngine::set(const string& key, const string& value) {
    database[key] = value;
}

string StorageEngine::get(const string& key) const {

    auto it = database.find(key);

    if (it != database.end())
        return it->second;

    return "(nil)";
}

bool StorageEngine::del(const string& key) {

    return database.erase(key);
}

bool StorageEngine::exists(const string& key) const {

    return database.contains(key) ;
}

vector<string> StorageEngine::keys() const {

    vector<string> allKeys;

    for (const auto& pair : database)
        allKeys.push_back(pair.first);

    return allKeys;
}

const std::unordered_map<std::string, std::string>&StorageEngine::getDatabase() const{
    return database;
}

void StorageEngine::insert(const std::string& key,const std::string& value){
    database[key] = value;
}