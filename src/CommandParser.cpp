#include "../include/CommandParse.h"
#include<iostream>
#include<vector>
#include<string>
#include<sstream>

using namespace std ;

vector<string> CommandParser::parse(const string& s){
    vector<string> tokens ;
    stringstream ss(s) ;
    string token ;
    while(ss>>token){
        tokens.push_back(token) ;
    }
    return tokens ;
}