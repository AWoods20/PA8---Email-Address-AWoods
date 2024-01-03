// Arial Woods

#ifndef MY_LIBRARY_AKW_H
#define MY_LIBRARY_AKW_H

#include <iomanip>
#include <string>
#include <limits>

using namespace std;

// Checks if the input is within range of min and max
int readInt(string inputType = "", int min = INT_MIN, int max = INT_MAX);

// Checks if the input is within range of min and max
double readDouble(string inputType = "", double min = -DBL_MAX, double max = DBL_MAX);

// Checks if input is either ch1 or ch2
char readChar(string inputType = "Choice", char ch1 = 'Y', char ch2 = 'N');

// This function finds the area of a rectangle, given length / width
double area(double length, double width);

// Finds the area of a circle, given its radius
double area(double radiusA);

// Finds the average of a number of values
double average(double sum, int numOfValues);

// Finds the minimum value between 4 values
int min(int one, int two, int three, int four);

// Rounds a number to the number of places given
double round(double number, int numDigits);

// Gives letter grade based on given average
char grade(double gradeAvg);

// Reverses the name given
string reverseName(string fullName);

// Finds sum of all elements in array
int sum(const int array[], const int sizeOfArray);

// Finds average of all elements in array
double average(const int array[], const int sizeOfArray2);

// Find min value in array
int min(const int array[], const int sizeOfArray3);

#endif // MY_LIBRARY_AKW_H
