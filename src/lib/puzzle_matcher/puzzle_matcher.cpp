#include "puzzle_matcher.h"

PuzzleMatcher::PuzzleMatcher() {
    puzzleData = vector<row>();
    answer = vector<string>();
}

void PuzzleMatcher::load(vector<row> puzzleData, vector<string> answer) {
    this->puzzleData = puzzleData;
    this->answer = answer;
}

void PuzzleMatcher::calculateAndPrint() {
    for (int i = 0; i < answer.size(); i++) {
        match(puzzleData, answer[i]);
    }
}

void PuzzleMatcher::match(vector<row> puzzleData, string word) {
    int wordLength = word.length();
    bool isFound = false;
    int rowIdx = 0;
    int colIdx = 0;
    direction dir;

    // right
    for (int i = 0; i < puzzleData.size(); i++) {
        for (int j = 0; j < puzzleData[i].size() - wordLength + 1; j++) {
            for (int k = 0; k < wordLength; k++) {
                if (puzzleData[i][j + k] != word[k]) break;
                if (k == wordLength - 1) {
                    isFound = true;
                    rowIdx = i;
                    colIdx = j;
                    dir = Right;
                }
            }
        }
    }
    // down
    if (!isFound) {
        for (int i = 0; i < puzzleData.size() - wordLength + 1; i++) {
            for (int j = 0; j < puzzleData[i].size(); j++) {
                for (int k = 0; k < wordLength; k++) {
                    if (puzzleData[i + k][j] != word[k]) break;
                    if (k == wordLength - 1) {
                        isFound = true;
                        rowIdx = i;
                        colIdx = j;
                        dir = Down;
                    }
                }
            }
        }
    }
    // left
    if (!isFound) {
        for (int i = 0; i < puzzleData.size(); i++) {
            for (int j = puzzleData[i].size() - 1; j > puzzleData[i].size() - wordLength  - 1; j--) {
                for (int k = 0; k < wordLength; k++) {
                    if (puzzleData[i][j - k] != word[k]) break;
                    if (k == wordLength - 1) {
                        isFound = true;
                        rowIdx = i;
                        colIdx = j;
                        dir = Left;
                    }
                }
            }
        }
    }

    // up
    if (!isFound) {
        for (int i = puzzleData.size() - 1; i > wordLength - 2; i--) {
            for (int j = 0; j < puzzleData[i].size(); j++) {
                for (int k = 0; k < wordLength; k++) {
                    if (puzzleData[i - k][j] != word[k]) break;
                    if (k == wordLength - 1) {
                        isFound = true;
                        rowIdx = i;
                        colIdx = j;
                        dir = Up;
                    }
                }
            }
        }
    }
    // down right
    if (!isFound) {
        for (int i = 0; i < puzzleData.size() - wordLength + 1; i++) {
            for (int j = 0; j < puzzleData[i].size() - wordLength + 1; j++) {
                for (int k = 0; k < wordLength; k++) {
                    if (puzzleData[i + k][j + k] != word[k]) break;
                    if (k == wordLength - 1) {
                        isFound = true;
                        rowIdx = i;
                        colIdx = j;
                        dir = DownRight;
                    }
                }
            }
        }
    }
    // down left
    if (!isFound) {
        for (int i = 0; i < puzzleData.size() - wordLength + 1; i++) {
            for (int j = puzzleData[i].size() - 1; j > wordLength - 2; j--) {
                for (int k = 0; k < wordLength; k++) {
                    if (puzzleData[i + k][j - k] != word[k]) break;
                    if (k == wordLength - 1) {
                        isFound = true;
                        rowIdx = i;
                        colIdx = j;
                        dir = DownLeft;
                    }
                }
            }
        }
    }
    // up left
    if (!isFound) {
        for (int i = puzzleData.size() - 1; i > wordLength - 2; i--) {
            for (int j = puzzleData[i].size() - 1; j > wordLength - 2; j--) {
                for (int k = 0; k < wordLength; k++) {
                    if (puzzleData[i - k][j - k] != word[k]) break;
                    if (k == wordLength - 1) {
                        isFound = true;
                        rowIdx = i;
                        colIdx = j;
                        dir = UpLeft;
                    }
                }
            }
        }
    }
    // up right
    if (!isFound) {
        for (int i = puzzleData.size() - 1; i > wordLength - 2; i--) {
            for (int j = 0; j < puzzleData[i].size() - wordLength + 1; j++) {
                for (int k = 0; k < wordLength; k++) {
                    if (puzzleData[i - k][j + k] != word[k]) break;
                    if (k == wordLength - 1) {
                        isFound = true;
                        rowIdx = i;
                        colIdx = j;
                        dir = UpRight;
                    }
                }
            }
        }
    }

    if (isFound) {
        // create empty 2d vector
        vector<row> result;
        for (int i = 0; i < puzzleData.size(); i++) {
            result.push_back(row());
            for (int j = 0; j < puzzleData[i].size(); j++) {
                result[i].push_back('-');
            }
        }

        int rowLength = puzzleData.size();
        int colLength = puzzleData[0].size();

        switch (dir) {
            case Right:
                for (int i = 0; i < wordLength; i++) {
                    result[rowIdx][colIdx + i] = word[i];
                }
                break;
            case DownRight:
                for (int i = 0; i < wordLength; i++) {
                    result[rowIdx + i][colIdx + i] = word[i];
                }
                break;
            case Down:
                for (int i = 0; i < wordLength; i++) {
                    result[rowIdx + i][colIdx] = word[i];
                }
                break;
            case DownLeft:
                for (int i = 0; i < wordLength; i++) {
                    result[rowIdx + i][colIdx - i] = word[i];
                }
                break;
            case Left:
                for (int i = 0; i < wordLength; i++) {
                    result[rowIdx][colIdx - i] = word[i];
                }
                break;
            case UpLeft:
                for (int i = 0; i < wordLength; i++) {
                    result[rowIdx - i][colIdx - i] = word[i];
                }
                break;
            case Up:
                for (int i = 0; i < wordLength; i++) {
                    result[rowIdx - i][colIdx] = word[i];
                }
                break;
            case UpRight:
                for (int i = 0; i < wordLength; i++) {
                    result[rowIdx - i][colIdx + i] = word[i];
                }
                break;
            default:
                break;
        }

        // print result

        cout << endl << word << endl;
        for (int i = 0; i < result.size(); i++) {
            for (int j = 0; j < result[0].size(); j++) {
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << word << " tidak ditemukan pada puzzle.\n";
    }
}