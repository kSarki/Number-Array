#include "NumberArray.h"
#include <iostream>
#include <limits>  // For min and max limits
using namespace std;

// Initialize static constants
const double NumberArray::DEFAULT_VALUE = 10000.0;

// Constructor: Dynamically allocates an array and fills with 0.0
NumberArray::NumberArray(int s) {
    size = (s > 0) ? s : MAX_SIZE;  // Ensure size is positive
    array = new double[size];

    for (int i = 0; i < size; i++)
        array[i] = 0.0;
}

// Destructor: Frees allocated memory
NumberArray::~NumberArray() {
    delete[] array;
    cout << "The destructor is running" << endl;
}

// Stores a number in the array (validates index)
void NumberArray::setNumber(int index, double value) {
    if (index >= 0 && index < size)
        array[index] = value;
    else
        cout << "The index is out of bounds, number not stored" << endl;
}

// Retrieves a number from the array (validates index)
double NumberArray::getNumber(int index) const {
    if (index >= 0 && index < size)
        return array[index];

    cout << "The index is out of bounds, returning default" << endl;
    return DEFAULT_VALUE;
}

// Returns the minimum value in the array
double NumberArray::getMin() const {
    double minVal = numeric_limits<double>::max();
    for (int i = 0; i < size; i++)
        if (array[i] < minVal)
            minVal = array[i];
    return minVal;
}

// Returns the maximum value in the array
double NumberArray::getMax() const {
    double maxVal = numeric_limits<double>::lowest();
    for (int i = 0; i < size; i++)
        if (array[i] > maxVal)
            maxVal = array[i];
    return maxVal;
}

// Calculates and returns the average of the array values
double NumberArray::getAverage() const {
    double sum = 0;
    for (int i = 0; i < size; i++)
        sum += array[i];
    return (size > 0) ? (sum / size) : 0;
}

// Prints all elements in the array
void NumberArray::printArray() const {
    for (int i = 0; i < size; i++)
        cout << fixed << setprecision(1) << array[i] << " ";
    cout << endl;
}
