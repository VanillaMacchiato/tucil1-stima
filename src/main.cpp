#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "lib/file_loader/file_loader.h"
#include "lib/puzzle_matcher/puzzle_matcher.h"

using namespace std;

typedef vector<char> row;

int main() {
    FileLoader loader;
    PuzzleMatcher matcher;
    string filename;

    cout << "Masukkan nama file: ";
    cin >> filename;

    int status = loader.load(filename);
    if (status == 0) {
        return 0;
    }

    vector<row> puzzleData = loader.getPuzzleData();
    vector<string> answer = loader.getAnswer();

    // print puzzle data
    for (int i = 0; i < puzzleData.size(); i++) {
        for (int j = 0; j < puzzleData[i].size(); j++) {
            cout << puzzleData[i][j] << " ";
        }
        cout << endl;
    }

    matcher.load(puzzleData, answer);
    matcher.calculateAndPrint();


    return 0;
}