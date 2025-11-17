#include "DynamicArray.h"

double findMedian(const DynamicArray& arr) {
    int n = arr.size();
    if (n == 0) {
        return 0; // or handle error
    }

    if (n % 2 == 1) {
        // odd
        return arr.get(n / 2);
    } else {
        // even – average middle two
        int mid1 = arr.get(n / 2 - 1);
        int mid2 = arr.get(n / 2);
        return (mid1 + mid2) / 2.0;
    }
}
