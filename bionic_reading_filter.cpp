#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#include <algorithm>

bool isSpecialCharacter(char c) {
    // Define special characters to filter out
    const std::string specialCharacters = "[];'<>,(){}\\|/.`'!@#$%^&*-_=+:\"";
    return specialCharacters.find(c) != std::string::npos;
}

bool endsWithNumber(const std::string &word) {
    // Check if the word ends with a number enclosed in square brackets
    return word.size() >= 3 && word.back() == ']' && std::isdigit(word[word.size() - 2]) && word[word.size() - 3] == '[';
}

void cleanAndApplyBionicReadingFilter(std::string &text) {
    // Remove punctuation and numbers
    text.erase(std::remove_if(text.begin(), text.end(), [](char c) {
        return std::ispunct(c) || std::isdigit(c);
    }), text.end());

    // Apply bionic reading filter
    std::ostringstream oss;
    std::istringstream iss(text);
    std::string line;
    while (std::getline(iss, line)) {
        std::istringstream lineStream(line);
        std::string word;
        while (lineStream >> word) {
            // Check if the word contains special characters or is empty
            if (!word.empty() && std::all_of(word.begin(), word.end(), [](char c) {
                return std::isalpha(c) || isSpecialCharacter(c);
            }) && !endsWithNumber(word)) {
                // Calculate the midpoint of the word
                size_t mid = word.length() / 2;

                // Bolden the first half for even-lettered words
                // Bolden the first half plus one extra letter for odd-lettered words
                word = "\033[1m" + word.substr(0, mid + (word.length() % 2 == 0 ? 0 : 1)) + "\033[0m" + word.substr(mid + (word.length() % 2));

                oss << word << " ";
            } else {
                // If the word contains special characters or ends with [some number], add it without modification
                oss << word << " ";
            }
        }
        // Add a newline to separate lines
        oss << '\n';
    }

    // Update the original text
    text = oss.str();
}

int main() {
    std::string inputData;
    std::string line;
    while (std::getline(std::cin, line)) {
        inputData += line + '\n';
    }

    cleanAndApplyBionicReadingFilter(inputData);

    std::cout << inputData;

    return 0;
}
