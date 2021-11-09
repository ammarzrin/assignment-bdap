/* Program Information */

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <fstream>
#include "statfunctions.h" // Header file that contains functions for Statistical Computations (F3 Statistical Analysis)
#include "userauth.h"	   // Header file containing functions related to User database (F1 User Authentication)
using namespace std;

// Main Menu function prototypes. (F4 Menu System)
void clearScreen()
{
	system("cls"); // Function to clear the screen.
}
void pauseScreen()
{
	cout << endl;
	system("PAUSE"); // Function to pause, and wait for any key from user to continue.
}
void programTitle() // Function to display program title at all times while performing calculations in Statistical Analysis.
{
	clearScreen();
	cout << "=----------------------------------------------------------=" << endl;
	cout << "|               Basic Data Analysis Program                |" << endl;
	cout << "=----------------------------------------------------------=" << endl;
	cout << "|                -> Statistical Analysis <-                |" << endl;
	cout << "=----------------------------------------------------------=" << endl;
	cout << endl;
}
void displayMainMenu(string &, string &);			  // The Main Menu to bbe displayed upon logging in.
void fileInputMenu(string &, string &, bool &);		  // File Input Menu to be displayed.
void fileRenameMenu(string &, string &);			  // File Rename Menu to be displayed.
void displayStatMenu(string &, string &);			  // Statistical Analysis Menu to be displayed.
void displayReportMenu(string &, string &, string &); // Report Generation Menu to be displayed.
void adminAccountSettings(string &);				  // Account Settings for Admins.
void buyerAccountSettings(string &);				  // Account Settings for Buyers.
void loadFileError();								  // Error message for missing input file in program.
void exitProgram();									  // Clears the screen and displays a goodbye message.

// Main Program
int main()
{
	// Constants for Main Menu choices
	const int INPUT_FILE = 1,
			  RENAME_FILE = 2,
			  CALC_STATS = 3,
			  GEN_REPORT = 4,
			  ACC_SETTINGS = 5,
			  EXIT_PROGRAM = 6;

	// Declaration of Variables relating to the User
	string currentUser = "username";
	string currentFile = "filetest.txt";
	string generatedReport = "The report lol";
	bool userType = 1; // Admin = 1, Buyer = 0
	bool fileLoaded = true;
	int choice;

	// Declaration for Statistical Analysis Variables
	TableType Table = {{5, 6, 3, 6},
					   {9, 5, 7, 2},
					   {2, 8, 5, 9},
					   {8, 3, 6, 4},
					   {8, 1, 7, 3}};
	int numCol = Col - 1;
	int numRow = Row - 1;
	int numChoice;
	int numChoice2;
	string tableChoice;
	int *valArray = nullptr;
	int *valArray2 = nullptr;
	int arraySize;
	int userChoice;
	float minNum;
	float maxNum;
	float medianNum;
	float meanNum;
	float varianceNum;
	float stdNum;
	float correlationNum;
	string corMessage;
	int *frequency = nullptr;
	int *distNumbers = nullptr;

	do
	{
		// The main menu is displayed to the user.
		displayMainMenu(currentUser, currentFile);
		// User inputs choice.
		cin >> choice;
		// Evaluation of user choice to proceed with program functionalities.
		switch (choice)
		{
		case INPUT_FILE:
			clearScreen();
			fileInputMenu(currentUser, currentFile, fileLoaded);
			break;
		case RENAME_FILE:
			clearScreen();
			if (fileLoaded == false)
				loadFileError();
			else
				fileRenameMenu(currentUser, currentFile);
			break;
		case CALC_STATS:
			clearScreen();
			if (fileLoaded == false)
				loadFileError();
			else
				do
				{
					displayStatMenu(currentUser, currentFile);
					cin >> choice;
					switch (choice)
					{
					case 1: // Find Minimum
						programTitle();
						cout << "Find Minimum have been selected." << endl;
						cout << endl;
						PreCalculation(Table, tableChoice, numRow, numCol, numChoice, valArray, arraySize);
						minNum = Min(valArray, arraySize);
						cout << "The minimum value of " << tableChoice << " " << numChoice << " is " << minNum << ". " << endl;
						delete[] valArray;
						pauseScreen();
						clearScreen();
						break;
					case 2: // Find Maximum
						programTitle();
						cout << "Find Maximum have been selected." << endl;
						cout << endl;
						PreCalculation(Table, tableChoice, numRow, numCol, numChoice, valArray, arraySize);
						maxNum = Max(valArray, arraySize);
						cout << "The maximum value of " << tableChoice << " " << numChoice << " is " << maxNum << ". " << endl;
						delete[] valArray;
						pauseScreen();
						clearScreen();
						break;
					case 3: // Median
						programTitle();
						cout << "Find Median have been selected." << endl;
						cout << endl;
						PreCalculation(Table, tableChoice, numRow, numCol, numChoice, valArray, arraySize);
						medianNum = Median(valArray, arraySize);
						cout << "The median value of " << tableChoice << " " << numChoice << " is " << medianNum << ". " << endl;
						delete[] valArray;
						pauseScreen();
						clearScreen();
						break;
					case 4: // Mean
						programTitle();
						cout << "Find Mean have been selected." << endl;
						cout << endl;
						PreCalculation(Table, tableChoice, numRow, numCol, numChoice, valArray, arraySize);
						meanNum = Mean(valArray, arraySize);
						cout << "The mean value of " << tableChoice << " " << numChoice << " is " << meanNum << ". " << endl;
						delete[] valArray;
						pauseScreen();
						clearScreen();
						break;
					case 5: // Variance
						programTitle();
						cout << "Find Variance have been selected." << endl;
						cout << endl;
						PreCalculation(Table, tableChoice, numRow, numCol, numChoice, valArray, arraySize);
						meanNum = Mean(valArray, arraySize);
						varianceNum = Variance(valArray, arraySize, meanNum);
						cout << "The variance value of " << tableChoice << " " << numChoice << " is " << varianceNum << ". " << endl;
						delete[] valArray;
						pauseScreen();
						clearScreen();
						break;
					case 6: // Standard Deviation
						programTitle();
						cout << "Find Standard Deviation have been selected." << endl;
						cout << endl;
						PreCalculation(Table, tableChoice, numRow, numCol, numChoice, valArray, arraySize);
						meanNum = Mean(valArray, arraySize);
						varianceNum = Variance(valArray, arraySize, meanNum);
						stdNum = sqrt(varianceNum);
						cout << "The standard deviation value of " << tableChoice << " " << numChoice << " is " << stdNum << ". " << endl;
						delete[] valArray;
						pauseScreen();
						clearScreen();
						break;
					case 7: // Correlation Between 2 Columns
						programTitle();
						cout << "Find Correlation Between 2 Columns have been selected." << endl;
						cout << endl;
						tableChoice = "column";
						choose2Columns(Table, numCol, numChoice, numChoice2);
						MakeArray(Table, tableChoice, numChoice, numRow, numCol, valArray, arraySize);
						MakeArray(Table, tableChoice, numChoice2, numRow, numCol, valArray2, arraySize);
						Correlation(valArray, valArray2, arraySize, correlationNum, corMessage);
						cout << endl
							 << "Correlation between column " << numChoice << " and " << numChoice2 << " is " << endl
							 << correlationNum << endl;
						delete[] valArray, valArray2;
						pauseScreen();
						clearScreen();
						break;
					case 8: // Distinct Data Members
						programTitle();
						cout << "Find Distinct Data have been selected." << endl;
						cout << endl;
						MakeAllArray(Table, valArray, numRow, numCol, arraySize);
						frequency = new int[arraySize];
						distNumbers = new int[arraySize];
						Distinct(valArray, frequency, distNumbers, arraySize);
						MakeFreqTable(distNumbers, frequency, arraySize);
						delete[] frequency, distNumbers, valArray;
						pauseScreen();
						clearScreen();
						break;
					case 9: // Plot a Histogram
						programTitle();
						cout << "Plot a Histogram is under construction...." << endl;
						cout << endl;
						pauseScreen();
						clearScreen();
						break;
					case 10: // Go Back to Main Menu
						clearScreen();
						break;
					default:
						clearScreen();
						cout << "Invalid input, please try again." << endl;
					}
				} while (choice != 10);
			break;
		case GEN_REPORT:
			clearScreen();
			if (fileLoaded == false) // need to add OR report cart still empty
				loadFileError();
			else
				displayReportMenu(currentUser, currentFile, generatedReport);
			break;
		case ACC_SETTINGS:
			clearScreen();
			if (userType == 0)
			{
				do
				{
					buyerAccountSettings(currentUser);
					cin >> choice;
					switch (choice)
					{
					case 1: // Change Password
						cout << "Function to change password has been called" << endl;
						pauseScreen();
						clearScreen();
						break;
					case 2: // Log Out
						cout << "Function to log the user out has been called" << endl;
						pauseScreen();
						clearScreen();
						break;
					case 3: // Go Back to Main Menu
						clearScreen();
						break;
					default:
						clearScreen();
						cout << "Invalid input, please try again." << endl;
					}
				} while (choice != 3);
			}
			else
			{
				do
				{
					adminAccountSettings(currentUser);
					cin >> choice;
					switch (choice)
					{
					case 1: // Change Password
						cout << "Function to change password has been called" << endl;
						pauseScreen();
						clearScreen();
						break;
					case 2: // Log Out
						cout << "Function to log the user out has been called" << endl;
						pauseScreen();
						clearScreen();
						break;
					case 3: // Create New User
						cout << "Function to create a new user has been called" << endl;
						pauseScreen();
						clearScreen();
						break;
					case 4: // Delete Existing User (aka Change userStatus to Inactive)
						cout << "Function to delete an existing user has been called" << endl;
						pauseScreen();
						clearScreen();
						break;
					case 5: // Go Back to Main Menu
						clearScreen();
						break;
					default:
						clearScreen();
						cout << "Invalid input, please try again." << endl;
					}
				} while (choice != 5);
			}
			break;
		case EXIT_PROGRAM:
			exitProgram();
			break;
		default:
			clearScreen();
			cout << "Invalid input, please try again." << endl;
		}
	} while (choice != EXIT_PROGRAM);
	return 0;
}

// Functions are defined below this comment.

void displayMainMenu(string &user, string &file)
{
	cout << "=----------------------------------------------------------=" << endl;
	cout << "|               Basic Data Analysis Program                |" << endl;
	cout << "=----------------------------------------------------------=" << endl;
	cout << "|                     -> Main Menu <-                      |" << endl;
	cout << "=----------------------------------------------------------=" << endl;
	cout << endl;
	cout << "Welcome, " << user << "." << endl;
	cout << "Current file: " << file << endl;
	cout << endl;
	cout << "=----------------------------------------------------------=" << endl;
	cout << "|  What would you like to do?                              |" << endl;
	cout << "|      1. Load New Data File                               |" << endl;
	cout << "|      2. Rename Current File                              |" << endl;
	cout << "|      3. Perform Statistical Analysis                     |" << endl;
	cout << "|      4. Generate a Report                                |" << endl;
	cout << "|      5. Manage my Account                                |" << endl;
	cout << "|      6. Exit program                                     |" << endl;
	cout << "=----------------------------------------------------------=" << endl;
	cout << endl;
	cout << "Select an integer from 1 to 6" << endl;
	cout << "---> ";
}

void fileInputMenu(string &user, string &file, bool &loaded)
{
	string input;
	cout << "=----------------------------------------------------------=" << endl;
	cout << "|               Basic Data Analysis Program                |" << endl;
	cout << "=----------------------------------------------------------=" << endl;
	cout << "|                   -> New File Input <-                   |" << endl;
	cout << "=----------------------------------------------------------=" << endl;
	cout << endl;
	cout << "Logged in as " << user << "." << endl;
	cout << endl;
	cout << "=----------------------------------------------------------=" << endl;
	cout << "| Guidelines:                                              |" << endl;
	cout << "|  >  Load a data file for the program to analyze.         |" << endl;
	cout << "|  >  File must be in the same directory as the program.   |" << endl;
	cout << "|  >  Program reads data files in (.txt) format.           |" << endl;
	cout << "|  >  Input example: file name.txt                         |" << endl;
	cout << "|  >  Input a dash (-) to cancel operation.                |" << endl;
	cout << "=----------------------------------------------------------=" << endl;
	cout << endl;
	cout << "Enter file name ---> ";
	cin.ignore();
	getline(cin, input);
	// To proceed with operation if (-) is not the input.
	if (input != "-")
	{
		file = input;
		loaded = true;
	}
	clearScreen();
}

void fileRenameMenu(string &user, string &file)
{
	string input;
	cout << "=----------------------------------------------------------=" << endl;
	cout << "|               Basic Data Analysis Program                |" << endl;
	cout << "=----------------------------------------------------------=" << endl;
	cout << "|                -> Rename Current File <-                 |" << endl;
	cout << "=----------------------------------------------------------=" << endl;
	cout << endl;
	cout << "Logged in as " << user << "." << endl;
	cout << "Current file: " << file << endl;
	cout << endl;
	cout << "=----------------------------------------------------------=" << endl;
	cout << "| Guidelines:                                              |" << endl;
	cout << "|  >  Replace current file name with a new name.           |" << endl;
	cout << "|  >  File name cannot be the same as an existing file.    |" << endl;
	cout << "|  >  Input example: file name.txt                         |" << endl;
	cout << "|  >  Input a dash (-) to cancel operation.                |" << endl;
	cout << "=----------------------------------------------------------=" << endl;
	cout << endl;
	cout << "Enter a new name for current file ---> ";
	cin.ignore();
	getline(cin, input);
	// To proceed with operation if (-) is not the input.
	if (input != "-")
		file = input;
	clearScreen();
}

void displayStatMenu(string &user, string &file)
{
	cout << "=----------------------------------------------------------=" << endl;
	cout << "|               Basic Data Analysis Program                |" << endl;
	cout << "=----------------------------------------------------------=" << endl;
	cout << "|                -> Statistical Analysis <-                |" << endl;
	cout << "=----------------------------------------------------------=" << endl;
	cout << endl;
	cout << "Logged in as " << user << "." << endl;
	cout << "Current file: " << file << endl;
	cout << endl;
	cout << "=----------------------------------------------------------=" << endl;
	cout << "|  What would you like to calculate from your file?        |" << endl;
	cout << "|      1. Find Minimum                                     |" << endl;
	cout << "|      2. Find Maximum                                     |" << endl;
	cout << "|      3. Median Value                                     |" << endl;
	cout << "|      4. Mean Value (Average)                             |" << endl;
	cout << "|      5. Variance                                         |" << endl;
	cout << "|      6. Standard Deviation                               |" << endl;
	cout << "|      7. Correlation Between 2 Columns                    |" << endl;
	cout << "|      8. Distinct Data Members                            |" << endl;
	cout << "|      9. Plot a Histogram                                 |" << endl;
	cout << "|     10. Go Back to Main Menu                             |" << endl;
	cout << "=----------------------------------------------------------=" << endl;
	cout << endl;
	cout << "Select an integer from 1 to 10" << endl;
	cout << "---> ";
}

void displayReportMenu(string &user, string &file, string &report)
{
	cout << "=----------------------------------------------------------=" << endl;
	cout << "|               Basic Data Analysis Program                |" << endl;
	cout << "=----------------------------------------------------------=" << endl;
	cout << "|                  -> Report Generator <-                  |" << endl;
	cout << "=----------------------------------------------------------=" << endl;
	cout << endl;
	cout << "Logged in as " << user << "." << endl;
	cout << "Report for " << file << " is generated below:" << endl;
	cout << endl;
	cout << report;
	cout << endl;
	cout << "=----------------------------------------------------------=" << endl;
	cout << "|  What would you like to do now?                          |" << endl;
	cout << "|      1. Save Report as text file (.txt)                  |" << endl;
	cout << "|      2. Save Report as HTML file (.html)                 |" << endl;
	cout << "|      3. Go Back to Main Menu                             |" << endl;
	cout << "|      4. Exit Program                                     |" << endl;
	cout << "=----------------------------------------------------------=" << endl;
	cout << endl;
	cout << "Select an integer from 1 to 4" << endl;
	cout << "---> ";
}

void adminAccountSettings(string &user)
{
	cout << "=----------------------------------------------------------=" << endl;
	cout << "|               Basic Data Analysis Program                |" << endl;
	cout << "=----------------------------------------------------------=" << endl;
	cout << "|                  -> Account Settings <-                  |" << endl;
	cout << "=----------------------------------------------------------=" << endl;
	cout << endl;
	cout << "Logged in as " << user << "." << endl;
	cout << endl;
	cout << "=----------------------------------------------------------=" << endl;
	cout << "|  What would you like to do?                              |" << endl;
	cout << "|      1. Change Password                                  |" << endl;
	cout << "|      2. Log Out                                          |" << endl;
	cout << "|      3. Create a New User                                |" << endl;
	cout << "|      4. Delete an Existing User                          |" << endl;
	cout << "|      5. Go Back to Main Menu                             |" << endl;
	cout << "=----------------------------------------------------------=" << endl;
	cout << endl;
	cout << "Select an integer from 1 to 5" << endl;
	cout << "---> ";
}

void buyerAccountSettings(string &user)
{
	cout << "=----------------------------------------------------------=" << endl;
	cout << "|               Basic Data Analysis Program                |" << endl;
	cout << "=----------------------------------------------------------=" << endl;
	cout << "|                  -> Account Settings <-                  |" << endl;
	cout << "=----------------------------------------------------------=" << endl;
	cout << endl;
	cout << "Logged in as " << user << "." << endl;
	cout << endl;
	cout << "=----------------------------------------------------------=" << endl;
	cout << "|  What would you like to do?                              |" << endl;
	cout << "|      1. Change Password                                  |" << endl;
	cout << "|      2. Log Out                                          |" << endl;
	cout << "|      3. Go Back to Main Menu                             |" << endl;
	cout << "=----------------------------------------------------------=" << endl;
	cout << endl;
	cout << "Select an integer from 1 to 3" << endl;
	cout << "---> ";
}

void exitProgram()
{
	clearScreen();
	cout << "Goodbye!";
}

void loadFileError()
{
	cout << "There is currently no file loaded." << endl;
	pauseScreen();
}