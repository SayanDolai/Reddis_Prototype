#include "../include/TTLManager.h"

using namespace std;

void TTLManager::setExpiry(const string& key, int seconds){
    expiryMap[key] = time(nullptr) + seconds;
}

bool TTLManager::isExpired(const string& key){
    auto it = expiryMap.find(key);

    if (it == expiryMap.end())
        return false;

    return time(nullptr) >= it->second;
}

int TTLManager::ttl(const string& key){
    auto it = expiryMap.find(key);

    if (it == expiryMap.end())
        return -1;

    int remaining = static_cast<int>(it->second - time(nullptr));

    if (remaining < 0)
        return 0;

    return remaining;
}

void TTLManager::remove(const string& key){
    expiryMap.erase(key);
}