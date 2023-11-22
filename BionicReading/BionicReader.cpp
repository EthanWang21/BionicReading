#include "BionicReader.h"
#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>

BionicReader::BionicReader() {
    // Constructor implementation
}

// Cleans the word of any characters besides the ones included in the if statement
std::string BionicReader::cleanWord(const std::string &word) {
    std::string cleanedWord;
    for (char c : word) {
        if (std::isspace(c) || std::isalpha(c) || c == '.' || c == '?' || c == '!' || c == ',' || c == ';' 
        || c == '(' || c == ')' || c == '-' || c == '_' || c == ':') {
            cleanedWord += c;
        }
    }
    return cleanedWord;
}

// Calculates the midpoint of the word and turns the first half bold then 
std::string BionicReader::applyFormatting(const std::string &cleanedWord) {
    size_t mid = cleanedWord.length() / 2;
    return "<span class=\"customBold\">" + cleanedWord.substr(0, mid + (cleanedWord.length() % 2 == 0 ? 0 : 1)) + "</span>" + cleanedWord.substr(mid + (cleanedWord.length() % 2));
}

// Cleans and applies the bionic reading filter
void BionicReader::cleanAndApplyBionicReadingFilter(std::string &text) {
    std::ostringstream oss;
    std::istringstream iss(text);
    std::string line;

    while (std::getline(iss, line)) {
        std::istringstream lineStream(line);
        std::string word;

        while (lineStream >> word) {
            std::string cleanedWord = cleanWord(word);
            std::string formattedWord = applyFormatting(cleanedWord);
            oss << formattedWord << " ";
        }

        oss << '\n';
    }

    text = oss.str();
}