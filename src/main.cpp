#include <chrono>
#include <iostream>
#include <string>

#include "lib/file_loader/file_loader.h"
#include "lib/puzzle_matcher/puzzle_matcher.h"

FileLoader loader;
PuzzleMatcher matcher;

int main() {
    loader.load();

    // Record start time
    auto start = chrono::high_resolution_clock::now();

    matcher.load(loader.getPuzzleData(), loader.getAnswer());
    matcher.calculate();

    // Record end time
    auto finish = chrono::high_resolution_clock::now();
    matcher.printResult();

    // Calculate duration
    chrono::duration<double> elapsed = finish - start;
    cout << "Waktu eksekusi: " << elapsed.count() * 1000 << " ms\n";
}