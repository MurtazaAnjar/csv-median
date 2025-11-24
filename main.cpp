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
    std::cout << "The median of the dataset is " << parser.findMedian() << "\n";
    std::cout << "The mean of the dataset is:   " << parser.findMean() << "\n";
    std::cout << "The mode of the dataset is:   " << parser.findMode() << "\n";
    return 0;
}