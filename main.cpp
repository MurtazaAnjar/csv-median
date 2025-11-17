#include <iostream>
#include <fstream>
#include <string>
#include "src/DynamicArray.h"
#include "src/CSVParser.h"

int main() {
    std::string filename;
    std::cout << "Enter the filename: ";
    std::cin >> filename;

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error: Could not open file " << filename << "\n";
        return -1;
    }

    CSVParser parser(file);
    std::cout << "Median is " << parser.findMedian() << "\n";
    return 0;
}