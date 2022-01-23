#include <chrono>
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



    // Record start time
    auto start = std::chrono::high_resolution_clock::now();
    matcher.load(puzzleData, answer);
    matcher.calculate();
    matcher.printResult();

    // Record end time
    auto finish = std::chrono::high_resolution_clock::now();


    // Calculate duration
    chrono::duration<double> elapsed = finish - start;
    cout << "Waktu perhitungan: " << elapsed.count() * 1000 << " ms\n";

    return 0;
}