// Arial Woods

#include <iostream>
#include <cctype>
#include <cmath>
#include <iomanip>
#include <string>
#include "myLibraryAKW.h"

using namespace std;

// Checks if the input is within range of min and max
int readInt(string inputType, int min, int max)
{
	int anyInt;				// Any integer that the user inputs
	bool valid;				// Boolean variable used to test if input is valid

	do {
		cin >> anyInt;

		valid = anyInt >= min && anyInt <= max;

		// Fails if out of valid range or input fails state or
		// if a valid integer is folowed by a non-integer char
		if (!valid || cin.fail() || !isspace(cin.peek())) {

			cout << "\nINVALID INPUT! " << inputType << " must be a whole number"
				<< " between " << min << " and " << max << "." << " Please try again ----->  ";
			cin.clear(); // Clears fail state

			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		
			valid = false;

		}

	} while (!valid);

	cin.ignore(100, '\n');

	return anyInt;
}

// Checks if the input is within range of min and max
double readDouble(string inputType, double min, double max)
{
	double anyDouble;
	bool valid;

	do {
		cin >> anyDouble;
		// What is vallid input of total seconds for 1 day
		valid = anyDouble >= min && anyDouble <= max;

		// Fails if out of valid range or input fails state or
		// if a valid integer is folowed by a non-integer char
		if (!valid || cin.fail() || !isspace(cin.peek())) {

			cout << setprecision(6) << endl;
			cout << "\nINVALID INPUT! " << inputType << " must be a decimal or whole number"
				<< " between "
				<< (min >= -1e6 && min <= -1e-6 || min == 0 || min >= 1e-6 && min <= 1e6 ? fixed : scientific)
				<< min << " and "
				<< (max >= -1e6 && max <= -1e-6 || max == 0 || max >= 1e-6 && max <= 1e6 ? fixed : scientific)
				<< max << "." << endl << "Please try again ----->  ";

			cin.clear(); // Clears fail state

			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			//            cin.ignore(100, '\n');
			valid = false;
		}

	} while (!valid);

	cin.ignore(100, '\n');

	return anyDouble;
}

// Checks if input is either ch1 or ch2
char readChar(string inputType, char ch1, char ch2)
{
	char anyChar;			// Any integer that the user inputs
	bool valid;				// Boolean variable used to test if input is valid

	do {
		cin >> anyChar;

		anyChar = toupper(anyChar);
		ch1 = toupper(ch1);
		ch2 = toupper(ch2);

		
		valid = anyChar == ch1 || anyChar == ch2;

		// Fails if out of valid range or input fails state or
		// if a valid integer is folowed by a non-integer char
		if (!valid || cin.fail() || !isspace(cin.peek())) {

			cout << "\nINVALID INPUT! " << inputType << " must be either " << ch1 << " or " << ch2
				<< " Please try again ----->  ";
			cin.clear(); // Clears fail state

			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			
			valid = false;

		}

	} while (!valid);

	cin.ignore(100, '\n');

	return anyChar;
}

// This function finds the area of a rectangle, given length / width
double area(double length, double width)
{
	return length * width;
}

// Finds the area of a circle, given its radius
double area(double radiusA)
{

	const float PI = 3.14159f;			// Value of PI

	return PI * pow(radiusA, 2);

}

// Finds the average of a number of values
double average(double sum, int numOfValues)
{
	if (sum == 0 || numOfValues <= 0)
	{
		return 0.0;
	}

		return sum / numOfValues;
}

// Finds the minimum value between 4 values
int min(int one, int two, int three, int four)
{

	int smallest;			// The smallest grade out of 4 test scores

	if (one <= two && one <= three && one <= four)
	{
		smallest = one;
	}

	else if (two <= one && two <= three && two <= four)
	{
		smallest = two;
	}

	else if (three <= one && three <= two && three <= four)
	{
		smallest = three;
	}

	else if (four <= one && four <= two && four <= three)
	{
		smallest = four;
	}

	return smallest;
}

// Rounds a number to the number of places given
double round(double number, int numDigits)
{
	double newRoundedNumber,			// The value of the original number after math
		place;							// Place value to do rounding

	place = pow(10.0, numDigits);

	newRoundedNumber = floor(fabs(number) * place + 0.5) / place;

	if (number < 0)
	{
		return  newRoundedNumber * -1;
	}

	return newRoundedNumber;
}

// Gives letter grade based on given average
char grade(double gradeAvg)
{
	if (gradeAvg >= 0 && gradeAvg <= 100)
	{
		gradeAvg = round(gradeAvg, 0);
	}
	else {
		return '*';
	}

	switch (static_cast<int>(gradeAvg) / 10)
	{
	case 10:
	case 9: return 'A';
	case 8: return 'B';
	case 7: return 'C';
	case 6: return 'D';
	default: return 'F';
	}
}

// Reverses the name given
string reverseName(string fullName)
{
	string::size_type commaPosition;

	commaPosition = fullName.find(',');

	if (commaPosition == string::npos)
	{
		return fullName.insert(0,"Invalid: ");
	}
	else 
	{
		string lastName = fullName.substr(0, commaPosition);

		string firstName = fullName.substr(commaPosition + 1);

		return string(firstName + " " + lastName);
	}
}

// Finds sum of all elements in array
int sum(const int array[], const int sizeOfArray)
{
	int sum1 = 0;

	for (int i = 0; i < sizeOfArray; i++)
		sum1 += array[i];

	return sum1;
}

// Finds average of all elements in array
double average(const int array[], const int sizeOfArray)
{

	return average(sum(array, sizeOfArray), sizeOfArray);
}

// Find min value in array
int min(const int array[], const int sizeOfArray)
{
	int minValue = array[0];

	for (int i = 1; i < sizeOfArray; i++)
	{
		if (minValue > array[i])
			minValue = array[i];
	}

	return minValue;
}