#ifndef BIONIC_READER_H
#define BIONIC_READER_H

#include <string>

class BionicReader {
public:
    BionicReader(); // Constructor
    std::string cleanWord(const std::string &word);
    std::string applyFormatting(const std::string &cleanedWord);
    void cleanAndApplyBionicReadingFilter(std::string &text);
};

#endif