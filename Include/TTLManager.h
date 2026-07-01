#ifndef TTL_MANAGER_H
#define TTL_MANAGER_H

#include <unordered_map>
#include <string>
#include <ctime>
using namespace std ;
class TTLManager{
private:
    // Stores the expiration timestamp (in seconds since the Unix epoch)
    unordered_map<string, time_t> expiryMap;

public:
    // Set expiration time
    void setExpiry(const std::string& key, int seconds);

    // Check if a key has expired
    bool isExpired(const std::string& key);

    // Remaining TTL
    int ttl(const std::string& key);

    // Remove TTL entry
    void remove(const std::string& key);
};

#endif