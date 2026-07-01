#ifndef COMMAND_PARSER_H
#define COMMAND_PARSER_H

#include <string>
#include <vector>
using namespace std ;
class CommandParser{
public:
    vector<string> parse(const string& input);
};

#endif