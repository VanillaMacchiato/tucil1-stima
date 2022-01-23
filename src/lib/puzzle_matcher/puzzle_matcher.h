#ifndef _PUZZLE_MATCHER_H
#define _PUZZLE_MATCHER_H

#include <stdlib.h>

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define RESET "\033[0m"
#define RED "\033[31m"     /* Red */
#define GREEN "\033[32m"   /* Green */
#define YELLOW "\033[33m"  /* Yellow */
#define BLUE "\033[34m"    /* Blue */
#define MAGENTA "\033[35m" /* Magenta */
#define CYAN "\033[36m"    /* Cyan */

typedef vector<char> row;
enum direction { Right,
                 DownRight,
                 Down,
                 DownLeft,
                 Left,
                 UpLeft,
                 Up,
                 UpRight };
enum colorNames { Red,
                  Green,
                  Blue,
                  Yellow,
                  Magenta,
                  Cyan };

class PuzzleMatcher {
   public:
    PuzzleMatcher();
    void load(vector<row> puzzleData, vector<string> answer);
    void calculate();
    void match(vector<row> puzzleData, string word);
    void printResult();

   private:
    vector<row> puzzleData;
    vector<string> answer;
    vector<vector<int>> colorCodesMatrix;
    vector<int> individiualComparison;
    int currentColor;
    int rowDirs[8] = {0, 1, 1, 1, 0, -1, -1, -1};  // right, down-right, down, down-left, left, up-left, up, up-right
    int colDirs[8] = {1, 1, 0, -1, -1, -1, 0, 1};
};

#endif