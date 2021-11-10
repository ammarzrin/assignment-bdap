/* Program Information */
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>
#include "userauth.h"	   // Header file containing functions related to User database (F1 User Registration & Authentication) - Sukanya
#include "statfunctions.h" // Header file containing functions for Statistical Analysis (F3 Statistical Computation) - Lutfi Izzat
#include "menusystem.h"	   // Header file containing functions related to the Menu System (F4 Menu System) - Ammar Azrin
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

int main()
{
	// Logging every user transaction from the moment user logged in to logging out/exiting the program.
	ifstream infile;
	ofstream outfile;

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
	bool userType = 1; // Admin = 1, Buyer = 0
	bool fileLoaded = true;
	bool loggedIn = true;
	int choice;

	// Report Generation
	vector<string> calcType;
	vector<string> rowColSelection;
	vector<float> value;

	// Declaration for Statistical Analysis Variables
	TableType Table = {{5, 6, 3, 6}, // Mock table to test calculations.
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
		logTransaction(outfile, currentUser, " proceeded to the Main menu.");
		displayMainMenu(currentUser, currentFile);
		// User inputs choice.
		cin >> choice;
		// Evaluation of user choice to proceed with program functionalities.
		switch (choice)
		{
		case INPUT_FILE:
			clearScreen();
			logTransaction(outfile, currentUser, " proceeded to File Input menu.");
			fileInputMenu(currentUser, currentFile, fileLoaded);
			logTransaction(outfile, currentUser, " successfully loaded a file.");
			break;
		case RENAME_FILE:
			clearScreen();
			if (!fileLoaded)
				loadFileError();
			else
			{
				logTransaction(outfile, currentUser, " proceeded to the File Rename menu.");
				fileRenameMenu(currentUser, currentFile);
				logTransaction(outfile, currentUser, " successfully renamed the file.");
			}
			break;
		case CALC_STATS:
			clearScreen();
			if (!fileLoaded)
				loadFileError();
			else
				do
				{
					displayStatMenu(currentUser, currentFile);
					cin >> choice;
					switch (choice)
					{
					case 1: // Find Minimum
						titleStatMenu();
						cout << "Find Minimum have been selected." << endl;
						cout << endl;
						PreCalculation(Table, tableChoice, numRow, numCol, numChoice, valArray, arraySize);
						minNum = Min(valArray, arraySize);
						cout << "The minimum value of " << tableChoice << " " << numChoice << " is " << minNum << ". " << endl;
						addToReport(calcType, rowColSelection, value, "Min Val", "selected rowcol", minNum);
						delete[] valArray;
						pauseScreen();
						clearScreen();
						break;
					case 2: // Find Maximum
						titleStatMenu();
						cout << "Find Maximum have been selected." << endl;
						cout << endl;
						PreCalculation(Table, tableChoice, numRow, numCol, numChoice, valArray, arraySize);
						maxNum = Max(valArray, arraySize);
						cout << "The maximum value of " << tableChoice << " " << numChoice << " is " << maxNum << ". " << endl;
						addToReport(calcType, rowColSelection, value, "Max Val", "selected rowcol", maxNum);
						delete[] valArray;
						pauseScreen();
						clearScreen();
						break;
					case 3: // Median
						titleStatMenu();
						cout << "Find Median have been selected." << endl;
						cout << endl;
						PreCalculation(Table, tableChoice, numRow, numCol, numChoice, valArray, arraySize);
						medianNum = Median(valArray, arraySize);
						cout << "The median value of " << tableChoice << " " << numChoice << " is " << medianNum << ". " << endl;
						addToReport(calcType, rowColSelection, value, "Median", "selected rowcol", medianNum);
						delete[] valArray;
						pauseScreen();
						clearScreen();
						break;
					case 4: // Mean
						titleStatMenu();
						cout << "Find Mean have been selected." << endl;
						cout << endl;
						PreCalculation(Table, tableChoice, numRow, numCol, numChoice, valArray, arraySize);
						meanNum = Mean(valArray, arraySize);
						cout << "The mean value of " << tableChoice << " " << numChoice << " is " << meanNum << ". " << endl;
						addToReport(calcType, rowColSelection, value, "Mean/Average", "selected rowcol", meanNum);
						delete[] valArray;
						pauseScreen();
						clearScreen();
						break;
					case 5: // Variance
						titleStatMenu();
						cout << "Find Variance have been selected." << endl;
						cout << endl;
						PreCalculation(Table, tableChoice, numRow, numCol, numChoice, valArray, arraySize);
						meanNum = Mean(valArray, arraySize);
						varianceNum = Variance(valArray, arraySize, meanNum);
						cout << "The variance value of " << tableChoice << " " << numChoice << " is " << varianceNum << ". " << endl;
						addToReport(calcType, rowColSelection, value, "Variance", "selected rowcol", varianceNum);
						delete[] valArray;
						pauseScreen();
						clearScreen();
						break;
					case 6: // Standard Deviation
						titleStatMenu();
						cout << "Find Standard Deviation have been selected." << endl;
						cout << endl;
						PreCalculation(Table, tableChoice, numRow, numCol, numChoice, valArray, arraySize);
						meanNum = Mean(valArray, arraySize);
						varianceNum = Variance(valArray, arraySize, meanNum);
						stdNum = sqrt(varianceNum);
						cout << "The standard deviation value of " << tableChoice << " " << numChoice << " is " << stdNum << ". " << endl;
						addToReport(calcType, rowColSelection, value, "Std Dev", "selected rowcol", stdNum);
						delete[] valArray;
						pauseScreen();
						clearScreen();
						break;
					case 7: // Correlation Between 2 Columns
						titleStatMenu();
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
						addToReport(calcType, rowColSelection, value, "Correlation", "2 columns selected", correlationNum);
						delete[] valArray, valArray2;
						pauseScreen();
						clearScreen();
						break;
					case 8: // Distinct Data Members
						titleStatMenu();
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
						titleStatMenu();
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
			if (!fileLoaded) // need to add OR report cart still empty
				loadFileError();
			else if (calcType.empty())
			{
				emptyReportError();
			}
			else
			{
				do
				{
					titleReportMenu(currentUser, currentFile);
					generateReport(calcType, rowColSelection, value);
					displayReportMenu();
					cin >> choice;
					switch (choice)
					{
					case 1:
						cout << "Save Report as (.txt) file has been selected." << endl;
						pauseScreen();
						break;
					case 2:
						cout << "Save Report as (.html) file has been selected." << endl;
						pauseScreen();
						break;
					case 3:
						cout << "Going back to the main menu..." << endl;
						pauseScreen();
						break;
					case 4:
						cout << "Exiting the program..." << endl;
						pauseScreen();
						exitProgram();
						continue;
						break;
					default:
						clearScreen();
						cout << "Invalid input, please try again." << endl;
					}
				} while (choice != 3);
			}
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