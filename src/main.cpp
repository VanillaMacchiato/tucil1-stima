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

    int status = loader.load();
    if (status == 0) return -1;

    // Record start time
    auto start = std::chrono::high_resolution_clock::now();

    matcher.load(loader.getPuzzleData(), loader.getAnswer());
    matcher.calculate();

    // Record end time
    auto finish = std::chrono::high_resolution_clock::now();
    matcher.printResult();

    // Calculate duration
    chrono::duration<double> elapsed = finish - start;
    cout << "Waktu eksekusi: " << elapsed.count() * 1000 << " ms\n";

    return 0;
}