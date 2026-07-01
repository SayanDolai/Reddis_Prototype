#include "../include/CommandExecutor.h"
#include<iostream>
#include<vector>
#include<string>

using namespace std ;

CommandExecutor::CommandExecutor(
        StorageEngine& storage,
        Persistence& persistence)
    : storage(storage),
      persistence(persistence)
{
}
void CommandExecutor::execute(const vector<string>& tokens){
    if(tokens.empty()){
        cout<<"Enter a valid syntax ...."<<endl ;
        return ;
    }
    string command = tokens[0] ; // either get set or del
     //SET
     if(command == "SET"){
        if(tokens.size() != 3){
            // command key value
            cout<<" Structer : SET <key , value >" <<endl ;
            return ;
        }
        // nowm call the set() from StorageEngine ... 
        string key = tokens[1] ;
        string value = tokens[2] ;
        CommandExecutor::storage.set(key,value) ;
        cout<<"OK"<<endl ;
     }
     else if(command == "GET"){
        if(tokens.size() != 2){
            // command key
            cout<<" Structer : GET <key> " <<endl ;
            return ;
        }
        // nowm call the set() from StorageEngine ... 
        string key = tokens[1] ;
        string value = CommandExecutor::storage.get(key) ;
        if(not value.empty()) cout<<value<<endl ;
        else cout<<"Key Does not exist ..."<<endl ;
     }
      else if(command == "DEL"){
        if(tokens.size() != 2){
            cout << "Usage: DEL <key>\n";
            return;
        }

        if(storage.del(tokens[1])) cout << "Deleted\n";
        else cout << "Key not found\n";
    }
     else if(command == "EXISTS"){
        if(tokens.size() != 2){
            cout << "Usage: EXISTS <key>\n";
            return;
        }

        cout << storage.exists(tokens[1]) << endl;
    }
    else if(command=="SAVE"){
        persistence.save(storage);
    }
    else if(command=="LOAD"){
        persistence.load(storage);
    }
    else if(command == "KEYS"){
        auto allKeys = storage.keys();

        if(allKeys.empty()){
            cout << "(empty)\n";
            return;
        }

        for(const auto& key : allKeys)
            cout << key << endl;
    }

    else{
        cout << "Unknown Command\n";
    }

}