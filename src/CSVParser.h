#ifndef HELLO_WORLD_CSVPARSER_H
#define HELLO_WORLD_CSVPARSER_H
#include "DynamicArray.h"
#include <fstream>
#include <string>
class CSVParser {
private:
    DynamicArray data;
    void bubbleSort();
public:
    // Constructor takes a reference to an open ifstream
    CSVParser(std::istream& inputStream);
    double findMedian();
    double findMean();
    double findMode();
    int size() const;
    int get(int index) const;

};

#endif //HELLO_WORLD_CSVPARSER_H