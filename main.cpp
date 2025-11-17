#include <iostream>
#include <fstream>
#include <string>
#include "src/DynamicArray.h"
#include "src/CSVParser.h"

int main() {
    std::string filename;
    std::cout << "Enter the filename: ";//entering "../src/filename" if stored in source folder
    std::cin >> filename;

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error opening file.\n";
        return 1;
    }

    DynamicArray arr;
    std::string number;

    // Read integers separated by commas
    while (getline(file, number, ',')) {
        if (!number.empty()) {
            arr.push_back(stoi(number));
        }
    }

    double median = findMedian(arr);
    std::cout << "The median of the dataset is " << median << std::endl;

    return 0;
}
