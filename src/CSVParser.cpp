#include "DynamicArray.h"
#include "CSVParser.h"
#include <sstream>

CSVParser::CSVParser(std::istream& inputStream) {
    std::string line;
    while (std::getline(inputStream, line)) {
        std::stringstream ss(line);
        std::string value;
        while (std::getline(ss, value, ',')) {
            if (!value.empty()) {
                data.push_back(std::stoi(value));
            }
        }
    }
}

int CSVParser::size() const { return data.size(); }
int CSVParser::get(int index) const { return data.get(index); }

double CSVParser::findMedian() {
    int n = data.size();
    if (n == 0) {
        return 0; // or handle error
    }

    if (n % 2 == 1) {
        // odd
        return data.get(n / 2);
    } else {
        // even – average middle two
        int mid1 = data.get(n / 2 - 1);
        int mid2 = data.get(n / 2);
        return (mid1 + mid2) / 2.0;
    }
}
