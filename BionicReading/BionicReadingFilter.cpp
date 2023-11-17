#include "BionicReader.h"
#include <iostream>

int main() {
    std::string inputData;
    std::string line;
    while (std::getline(std::cin, line)) {
        inputData += line + '\n';
    }

    BionicReader reader;
    reader.cleanAndApplyBionicReadingFilter(inputData);

    std::cout << inputData;

    return 0;
}
