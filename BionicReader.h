#ifndef BIONIC_READER_H
#define BIONIC_READER_H

#include <string>

class BionicReader {
public:
    BionicReader(); // Constructor
    void cleanAndApplyBionicReadingFilter(std::string &text);
};

#endif