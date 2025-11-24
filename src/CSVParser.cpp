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

    bubbleSort();
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

double CSVParser::findMean() {
    if (data.size() == 0) {
        return 0.0;
    }

    long long sum = 0;
    for (int i = 0; i < data.size(); i++) {
        sum += data.get(i);
    }

    return static_cast<double>(sum) / data.size();
}

double CSVParser::findMode() {
    if (data.size() == 0) {
        return 0.0;
    }
    int currentValue = data.get(0), currentCount = 1;
    int modeValue = currentValue, modeCount = 1;

    for (int i = 1; i < data.size(); i++) {
        if (data.get(i) == currentValue) {
            currentCount++;
        } else {
            if (currentCount > modeCount) {
                modeCount = currentCount;
                modeValue = currentValue;
            }
            currentValue = data.get(i);
            currentCount = 1;
        }
    }
    if (currentCount > modeCount) {// If mode is at the end
        modeValue = currentValue;
    }
    return static_cast<double>(modeValue);// if no mode, returns first value
}

void CSVParser::bubbleSort() {
    int n = data.size();
    if (n <= 1) return;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            int a = data.get(j);
            int b = data.get(j + 1);

            if (a > b) {
                // swap
                data.set(j, b);
                data.set(j + 1, a);
            }
        }
    }
}