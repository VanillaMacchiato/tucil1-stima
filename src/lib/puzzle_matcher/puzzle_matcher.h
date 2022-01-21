#ifndef _PUZZLE_MATCHER_H
#define _PUZZLE_MATCHER_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef vector<char> row;
enum direction {Right, DownRight, Down, DownLeft, Left, UpLeft, Up, UpRight};

class PuzzleMatcher {
   public:
    PuzzleMatcher();
    void load(vector<row> puzzleData, vector<string> answer);
    void calculateAndPrint();
    static void match(vector<row> puzzleData, string word);
   private:
    vector<row> puzzleData;
    vector<string> answer;
};


#endif