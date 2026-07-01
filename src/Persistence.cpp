#include "../include/Persistence.h"

#include <fstream>
#include <iostream>

using namespace std;

Persistence::Persistence(const string& file){
    filename = file;
}

void Persistence::save(const StorageEngine& storage){
    ofstream fout(filename);

    if (!fout){
        cout << "Failed to open file!\n";
        return;
    }

    const auto& database = storage.getDatabase();

    for (const auto& pair : database){
        fout << pair.first << "=" << pair.second << endl;
    }

    fout.close();

    cout << "Database Saved Successfully\n";
}

void Persistence::load(StorageEngine& storage){
    ifstream fin(filename);

    if (!fin){
        cout << "No saved database found.\n";
        return;
    }

    string line;

    while (getline(fin, line)){    
        size_t pos = line.find('=');

        if (pos == string::npos)
            continue;

        string key = line.substr(0, pos);
        string value = line.substr(pos + 1);

        storage.insert(key, value);
    }

    fin.close();

    cout << "Database Loaded Successfully\n";
}