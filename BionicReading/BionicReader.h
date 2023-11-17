#ifndef BIONIC_READER_H
#define BIONIC_READER_H

#include <string>

class BionicReader {
public:
    BionicReader(); // Constructor

    bool isSpecialCharacter(char c);
    bool endsWithNumber(const std::string &word);
    void cleanAndApplyBionicReadingFilter(std::string &text);
};

#endif