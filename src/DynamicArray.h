#ifndef HELLO_WORLD_DYNAMICARRAY_H
#define HELLO_WORLD_DYNAMICARRAY_H


class DynamicArray {
private:
    int* data;
    int capacity;
    int length;
public:
    DynamicArray();
    void push_back(int value);
    int size() const;
    int get(int index) const;
    void set(int index, int value);
    ~DynamicArray();
};


#endif //HELLO_WORLD_DYNAMICARRAY_H