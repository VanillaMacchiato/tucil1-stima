#ifndef _FILE_LOADER_H
#define _FILE_LOADER_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef vector<char> row;

class FileLoader {
   public:
    FileLoader();
    void load();
    vector<row> getPuzzleData();
    vector<string> getAnswer();
   private:
    string filename;
    vector<row> puzzleData;
    vector<string> answer;
};

#endif