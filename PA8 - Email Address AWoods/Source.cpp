#include "myLibraryAKW.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

string emailAddress(string name);
void selSort(string list[], const int length, int order = 0);

int main()
{
	string inFileName = "Employee Directory.txt";				// Input file
	ifstream fin;												// Ifstream object
	string outFileName = "Employee Emails.txt";					// Output file
	ofstream fout;												// Ofstream object

	const int ARRAY_SIZE = 20;									// Array size
	string namesArray[ARRAY_SIZE];								// Stores employee names
	string emailArray[ARRAY_SIZE];								// Stores employee email addresses
	int recordCount;											// Stores actual number of names read
	string::size_type longName = 0;								// Stores longest employee's name
	string tempName;											// Temporarily stores names read from file

	fin.open(inFileName); 
	fout.open(outFileName);
	if (fin.fail() || fout.fail())
	{
		cout << "\nError opening file " << inFileName << " for reading\n";
		cout << "\nError opening file " << outFileName << " for writing\n";
		return EXIT_FAILURE;
	}

	getline(fin, tempName);
	for (recordCount = 0; recordCount < ARRAY_SIZE && !fin.eof(); recordCount++)
	{
		namesArray[recordCount] = tempName;
		if (tempName.length() > longName)
			longName = tempName.length();
		getline(fin, tempName);

	}

	if (!fin.eof())
		cout << "\nExceeded array limitations for " << ARRAY_SIZE << " records.\n"
		<< "More records remain in file.\n";
	else
		cout << "\nProcessing all " << recordCount << " records in file.\n\n";

	fin.close();

	for (int i = 0; i < recordCount; i++)
	{
		emailArray[i] = emailAddress(namesArray[i]);
		selSort(namesArray, recordCount);
		fout << left << setw(longName + 5) << namesArray[i] << emailArray[i] << endl;
	}

	fout.close(); 

	cout << "\nOpen " << outFileName << " to see generated emails.\n";

}

string emailAddress(string name)
{
	string email,					// Email
		last;						// Last name
	int commaPos;					// Comma position
	char first;						// Fits letter of first name

	commaPos = name.find(',');
	if (commaPos)
	{
		first = name.at(commaPos + 2);
		last = name.substr(0, commaPos);
		email = first + last;
		email.append("@company.com");
		transform(email.begin(), email.end(), email.begin(), tolower);
		return email;
	}
	else
		return name.insert(0, "Invalid format: ");
		
}

void selSort(string list[], const int length, int order)
{
	int index; 
	bool compare; 

	for (int passCount = 0; passCount < length - 1; passCount++)
	{
		index = passCount; 

		for (int placeCount = passCount + 1; placeCount < length; placeCount++)
		{
			if (order == 0)
				compare = list[placeCount] < list[index]; // ascending
			else
				compare = list[placeCount] > list[index]; // descending
			if (compare)
				index = placeCount;
		}
		
		swap(list[index], list[passCount]);
	}
}