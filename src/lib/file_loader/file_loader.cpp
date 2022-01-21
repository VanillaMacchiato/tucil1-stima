#include "file_loader.h"

FileLoader::FileLoader() {
    filename = "";
    puzzleData = vector<row>();
    answer = vector<string>();
}

int FileLoader::load(string filename) {
    int status = 0;
    bool isAnswer = false;
    string line;

    ifstream file(filename);
    if (!file.is_open()) {
        cout << "File tidak dapat dibuka" << endl;
        return 0;
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