#include "file_loader.h"

FileLoader::FileLoader() {
    filename = "";
    puzzleData = vector<row>();
    answer = vector<string>();
}

int FileLoader::load() {
    int status = 0;
    bool isAnswer = false;
    string line;
    string filename;

    cout << "Word-Search Puzzle Solver" << endl;
    cout << "Masukkan nama file: ";
    cin >> filename;

    ifstream file(filename);
    if (!file.is_open()) {
        cout << "File dengan nama " << filename <<  " tidak ada atau tidak dapat dibuka" << endl;
        return 0;
    } else {
        cout << "\nBerhasil membuka file " << filename << endl;
    }

    int idx = 0;
    char buf;
    while (getline(file, line)) {
        if (line.size() < 2) {
            isAnswer = true;
            continue;
        };
        if (!isAnswer) {
            puzzleData.push_back(row());
            for (int i = 0; i < line.size(); i++) {
                buf = line[i];
                // jika spasi ditemukan, tidak dimasukkan ke dalam vector
                if (buf == ' ') continue;
                puzzleData[idx].push_back(buf);
            }
        } else {
            answer.push_back(line);
        }
        idx++;
    }
    file.close();

    return 1;
}

vector<row> FileLoader::getPuzzleData() {
    return puzzleData;
}

vector<string> FileLoader::getAnswer() {
    return answer;
}