#ifndef NUMBERARRAY_H
#define NUMBERARRAY_H

#include <iostream>
#include <iomanip>

class NumberArray {
private:
    static const int MAX_SIZE = 10;  // Default size
    static const double DEFAULT_VALUE;  // Default value for out-of-bounds access
    int size;  // Size of the array
    double* array;  // Pointer to the dynamically allocated array

public:
    // Constructor with default parameter
    NumberArray(int size = MAX_SIZE);

    // Destructor
    ~NumberArray();

    // Mutator function to store a value
    void setNumber(int index, double value);

    // Accessor function to retrieve a value
    double getNumber(int index) const;

    // Find the minimum value in the array
    double getMin() const;

    // Find the maximum value in the array
    double getMax() const;

    // Calculate the average of the array
    double getAverage() const;

    // Print all elements in the array
    void printArray() const;
};

#endif
