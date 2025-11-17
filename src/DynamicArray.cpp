#include "DynamicArray.h"
DynamicArray::DynamicArray() {
    capacity = 10;
    length = 0;
    data = new int[capacity];
}

DynamicArray::~DynamicArray() {
    delete[] data;
}

void DynamicArray::push_back(int value) {
    if (length == capacity) {
        // resize
        capacity *= 2;
        int* newData = new int[capacity];
        for (int i = 0; i < length; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }
    data[length++] = value;
}

int DynamicArray::size() const {
    return length;
}

int DynamicArray::get(int index) const {
    return data[index];
}