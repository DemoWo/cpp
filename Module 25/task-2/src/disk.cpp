#include "disk.h"
#include "ram.h"
#include <fstream>
#include <iostream>

using namespace std;

void save (){
    ofstream saveFile ("save.txt");
    if (!saveFile){
        cout <<"Error.The file did not open";
        return;
    }
    for (int i = 0; i < 8; i++) {
        saveFile << read (i) <<" ";
    }
    cout <<"Saving successfully!"<<endl;
    saveFile.close();
}

void load (){
    ifstream loadFile ("save.txt");
    if (!loadFile){
        cout <<"Error.The file did not open";
        return;
    }
    for (int i = 0; i < 8; i++){
        int num;
        loadFile >> num;
        write(i, num);
    }
    cout <<"Loading successfully!"<<endl;
    loadFile.close();
}