#include "puzzle_matcher.h"

PuzzleMatcher::PuzzleMatcher() {
    puzzleData = vector<row>();
    answer = vector<string>();
    currentColor = 0;
    individiualComparison = vector<int>();
}

void PuzzleMatcher::load(vector<row> puzzleData, vector<string> answer) {
    this->puzzleData = puzzleData;
    this->answer = answer;

    for (int i = 0; i < puzzleData.size(); i++) {
        colorCodesMatrix.push_back(vector<int>());
        for (int j = 0; j < puzzleData[i].size(); j++) {
            colorCodesMatrix[i].push_back(-1);
        }
    }
}

void PuzzleMatcher::calculate() {
    for (int i = 0; i < answer.size(); i++) {
        match(puzzleData, answer[i]);
    }
}

void PuzzleMatcher::match(vector<row> puzzleData, string word) {
    int wordLength = word.length();
    bool isFound = false;
    int rowIdx = 0;
    int colIdx = 0;
    int comparisonCount = 0;
    direction dir;

    // Pencarian ke 8 arah jika huruf pertama dari vector tersebut adalah huruf yang sama dengan variable word
    int rowCount = puzzleData.size();
    int colCount;
    for (int i = 0; i < rowCount; i++) {
        colCount = puzzleData[i].size();
        for (int j = 0; j < colCount; j++) {
            comparisonCount++;
            if (puzzleData[i][j] != word[0]) continue;

            for (int dirNum = 0; dirNum < 8; dirNum++) {
                int tmpRow = i;
                int tmpCol = j;
                // bandingkan pada 8 arah
                for (int k = 1; k < wordLength; k++) {
                    tmpRow += rowDirs[dirNum];
                    tmpCol += colDirs[dirNum];
                    if (tmpRow < 0 || tmpRow >= rowCount || tmpCol < 0 || tmpCol >= colCount) break;

                    comparisonCount++;
                    if (puzzleData[tmpRow][tmpCol] != word[k]) break;

                    if (k == wordLength - 1) {
                        isFound = true;
                        rowIdx = i;
                        colIdx = j;
                        dir = (direction)dirNum;

                        individiualComparison.push_back(comparisonCount);
                        break;
                    }
                }
            }
            if (isFound) break;
        }
        if (isFound) break;
    }

    if (isFound) {
        int colorCycle = currentColor % 6;
        // set the word to the result
        for (int i = 0; i < wordLength; i++) {
            colorCodesMatrix[rowIdx][colIdx] = colorCycle;

            rowIdx += rowDirs[dir];
            colIdx += colDirs[dir];
        }

        currentColor++;
    } else {
        cout << word << " tidak ditemukan pada puzzle.\n";
    }
}

void PuzzleMatcher::printResult() {
    for (int i = 0; i < puzzleData.size(); i++) {
        for (int j = 0; j < puzzleData[i].size(); j++) {
            switch (colorCodesMatrix[i][j]) {
                case Red:
                    cout << RED << puzzleData[i][j] << RESET << " ";
                    break;
                case Green:
                    cout << GREEN << puzzleData[i][j] << RESET << " ";
                    break;
                case Blue:
                    cout << BLUE << puzzleData[i][j] << RESET << " ";
                    break;
                case Yellow:
                    cout << YELLOW << puzzleData[i][j] << RESET << " ";
                    break;
                case Magenta:
                    cout << MAGENTA << puzzleData[i][j] << RESET << " ";
                    break;
                case Cyan:
                    cout << CYAN << puzzleData[i][j] << RESET << " ";
                    break;
                default:
                    cout << RESET << puzzleData[i][j] << " ";
                    break;
            }
        }
        cout << endl;
    }

    cout << "\n";
    int N = 0;
    for (int i = 0; i < individiualComparison.size(); i++) {
        cout << answer[i] << ": " << individiualComparison[i] << " perbandingan" << endl;
        N += individiualComparison[i];
    }

    cout << "\nTotal perbandingan: " << N << endl;
}