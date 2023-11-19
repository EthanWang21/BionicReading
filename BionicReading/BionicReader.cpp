#include "BionicReader.h"
#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>

bool BionicReader::endsWithNumber(const std::string &word) {
    return word.size() >= 3 && word.back() == ']' && std::isdigit(word[word.size() - 2]) && word[word.size() - 3] == '[';
}

BionicReader::BionicReader() {
    // Constructor implementation
}

void BionicReader::cleanAndApplyBionicReadingFilter(std::string &text) {
    std::ostringstream oss;
    std::istringstream iss(text);
    std::string line;
    while (std::getline(iss, line)) {
        std::istringstream lineStream(line);
        std::string word;
        while (lineStream >> word) {
            std::string cleanedWord;
            for (char c : word) {
                if (std::isspace(c) || std::isalpha(c) || c == '.') {
                    cleanedWord += c;
                }
            }

            if (!cleanedWord.empty() && !endsWithNumber(cleanedWord)) {
                size_t mid = cleanedWord.length() / 2;
                cleanedWord = "\033[1m" + cleanedWord.substr(0, mid + (cleanedWord.length() % 2 == 0 ? 0 : 1)) + "\033[0m" + cleanedWord.substr(mid + (cleanedWord.length() % 2));
                oss << cleanedWord << " ";
            } else {
                oss << cleanedWord << " ";
            }
        }
        oss << '\n';
    }

    text = oss.str();
}
