/* 
Program Title: Basic Data Analysis Program
Subject: TCP1101 Programming Fundamentals
Trimester 1, 2021/2022
Group 2, TT1V
=-------------------------------=----------------------------------------------=
| No |          Module          |                     Name                     |
=-------------------------------=----------------------------------------------=
| F1 | User Authentication      | Sukanya A/P Thinakaran                       |
=-------------------------------=----------------------------------------------=
| F2 | Data File Reader         | Kheryl Amalia Dania binti Khairul Affendie   |
=-------------------------------=----------------------------------------------=
| F3 | Statistical Analysis     | Muhammad Lutfi bin Mohd Izzat                |
=-------------------------------=----------------------------------------------=
| F4 | Menu System              | Muhammad Ammar bin Muhamad Azrin             |
=-------------------------------=----------------------------------------------=
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>
#include "userauth.h"	   // Header file containing functions related to User database (F1 User Registration & Authentication) - Sukanya
#include "filereader.h"	   // Header file containing functions relating data files and the program (F2 File Reader) - Kheryl Amalia
#include "statfunctions.h" // Header file containing functions for Statistical Analysis (F3 Statistical Computation) - Lutfi Izzat
#include "menusystem.h"	   // Header file containing functions related to the Menu System (F4 Menu System) - Ammar Azrin
#include "validation.h"	   // Header file containing functions related specifically for loading the data file into the program. :)
using namespace std;

// Functions to clear and pause the screen. Must be checked for OS compatibility.
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
	string currentFile = "none";
	bool fileLoaded = false;
	string username;
	string password;
	bool userExist;
	fstream usernamefile;
	ofstream newFile;

	User currentUser;
	int userSize;
	int currentUserIndex;
	bool isLoggedIn = false;
	vector<User> usernames;
	string newPassword;
	string newpassword;
	string newusername;
	string newusertype;

	// Report Generation
	vector<string> calcType;
	vector<string> rowColSelection;
	vector<float> value;

	// Declaration for Statistical Analysis Variables
	vector<vector<int>> Table;
	vector<bool> canCompute;
	vector<string> columnTitles;
	bool dataError;
	int Col;
	int Row;
	int numCol;
	int numRow;
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

	int choice; // For accepting user input for navigation throughout the program.

	while (!isLoggedIn)
	{
		displayLoginPage(username, password);
		readUsername(usernames, usernamefile, userSize);
		currentUserIndex = checkUsername(username, usernames, userSize);
		if (currentUserIndex == -1)
		{
			cout << endl
				 << "Username does not exist, please try again." << endl;
			pauseScreen();
			clearScreen();
			isLoggedIn = false;
		}
		else if (currentUserIndex == -2)
		{
			cout << endl
				 << "User is deleted and inactive, please contact your administrator if you think this is a mistake." << endl;
			pauseScreen();
			clearScreen();
			isLoggedIn = false;
		}
		else
		{
			if (checkPass(password, usernames, currentUserIndex) == true)
			{
				cout << endl
					 << "Login is successful! Directing you to the main menu..." << endl;
				pauseScreen();
				clearScreen();
				currentUser.username = username;
				currentUser.password = password;
				currentUser.userType = usernames[currentUserIndex].userType;
				currentUser.status = usernames[currentUserIndex].status;
				logTransaction(outfile, currentUser.username, " has successfully logged in.");
				isLoggedIn = true;
			}
			else
			{
				cout << endl
					 << "Incorrect password! Please enter your username and password again." << endl;
				pauseScreen();
				clearScreen();
				isLoggedIn = false;
			}
		}
	}

	if (isLoggedIn)
	{
		do
		{
			// The main menu is displayed to the user.
			logTransaction(outfile, currentUser.username, " proceeded to the Main Menu.");
			displayMainMenu(currentUser.username, currentFile);
			// User inputs choice.
			cin >> choice;
			inputValidation();
			// Evaluation of user choice to proceed with program functionalities.
			switch (choice)
			{
			case INPUT_FILE:
				clearScreen();
				logTransaction(outfile, currentUser.username, " proceeded to File Input menu.");
				fileInputMenu(currentUser.username, currentFile, fileLoaded);
				LoadDataFile(currentFile, Table, Row, Col, columnTitles, dataError, canCompute);

				if (dataError == false)
					fileLoaded = false;
				else
				{
					fileLoaded = true;
					numRow = Row;
					numCol = Col - 1;

					cout<<numRow<<endl;
					cout<<numCol<<endl;
				}
				break;
			case RENAME_FILE:
				if (!fileLoaded)
					loadFileError();
				else
				{
					clearScreen();
					logTransaction(outfile, currentUser.username, " proceeded to the File Rename menu.");
					fileRenameMenu(currentUser.username, currentFile);
					logTransaction(outfile, currentUser.username, " successfully renamed the file.");
				}
				break;
			case CALC_STATS:
				if (!fileLoaded)
					loadFileError();
				else
				{
					clearScreen();
					logTransaction(outfile, currentUser.username, " proceeded to the Statistical Analysis menu.");
					do
					{
						displayStatMenu(currentUser.username, currentFile);
						cin >> choice;
						inputValidation();
						switch (choice)
						{
						case 1: // Find Minimum
							logTransaction(outfile, currentUser.username, " has selected to Find Minimum Value.");
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
							logTransaction(outfile, currentUser.username, " has selected to Find Maximum Value.");
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
							logTransaction(outfile, currentUser.username, " has selected to Find Median Value.");
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
							logTransaction(outfile, currentUser.username, " has selected to" + currentFile + "Find Mean Value.");
							titleStatMenu();
							cout << "Find Mean have been selected." << endl;
							cout << endl;
							PreCalculation(Table, tableChoice, numRow, numCol, numChoice, valArray, arraySize);
							meanNum = Mean(valArray, arraySize);
							cout << "The mean value of " << tableChoice << " " << numChoice << " is " << setprecision(4) << meanNum << ". " << endl;
							addToReport(calcType, rowColSelection, value, "Mean/Average", "selected rowcol", meanNum);
							delete[] valArray;
							pauseScreen();
							clearScreen();
							break;
						case 5: // Variance
							logTransaction(outfile, currentUser.username, " has selected to Find Variance Value.");
							titleStatMenu();
							cout << "Find Variance have been selected." << endl;
							cout << endl;
							PreCalculation(Table, tableChoice, numRow, numCol, numChoice, valArray, arraySize);
							meanNum = Mean(valArray, arraySize);
							varianceNum = Variance(valArray, arraySize, meanNum);
							cout << "The variance value of " << tableChoice << " " << numChoice << " is " << setprecision(4) << varianceNum << ". " << endl;
							addToReport(calcType, rowColSelection, value, "Variance", "selected rowcol", varianceNum);
							delete[] valArray;
							pauseScreen();
							clearScreen();
							break;
						case 6: // Standard Deviation
							logTransaction(outfile, currentUser.username, " has selected to Find the Standard Deviation Value.");
							titleStatMenu();
							cout << "Find Standard Deviation have been selected." << endl;
							cout << endl;
							PreCalculation(Table, tableChoice, numRow, numCol, numChoice, valArray, arraySize);
							meanNum = Mean(valArray, arraySize);
							varianceNum = Variance(valArray, arraySize, meanNum);
							stdNum = sqrt(varianceNum);
							cout << "The standard deviation value of " << tableChoice << " " << numChoice << " is " << setprecision(4) << stdNum << ". " << endl;
							addToReport(calcType, rowColSelection, value, "Std Dev", "selected rowcol", stdNum);
							delete[] valArray;
							pauseScreen();
							clearScreen();
							break;
						case 7: // Correlation Between 2 Columns
							logTransaction(outfile, currentUser.username, " has selected to Find Correlation Between 2 Columns.");
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
								 << setprecision(4) << correlationNum << endl;
							addToReport(calcType, rowColSelection, value, "Correlation", "2 columns selected", correlationNum);
							delete[] valArray, valArray2;
							pauseScreen();
							clearScreen();
							break;
						case 8: // Distinct Data Members
							logTransaction(outfile, currentUser.username, " has selected to Find Distinct Data Members.");
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
							logTransaction(outfile, currentUser.username, " has selected to Create a Histogram chart.");
							titleStatMenu();
							cout << "Plot a Histogram is under construction...." << endl;
							cout << endl;
							pauseScreen();
							clearScreen();
							break;
						case 10: // Return to Main Menu
							clearScreen();
							break;
						default:
							cout << endl
								 << "Invalid input, please try again by selecting an integer from 1 to 10." << endl;
							pauseScreen();
							clearScreen();
						}
					} while (choice != 10);
				}
				break;
			case GEN_REPORT:
				if (!fileLoaded)
					loadFileError();
				else if (calcType.empty())
					emptyReportError();
				else
				{
					clearScreen();
					logTransaction(outfile, currentUser.username, " has selected to Generate the Report.");
					do
					{
						titleReportMenu(currentUser.username, currentFile);
						generateReport(calcType, rowColSelection, value);
						displayReportMenu();
						cin >> choice;
						inputValidation();
						switch (choice)
						{
						case 1: // Create report.txt
							logTransaction(outfile, currentUser.username, " has saved the report as a text file.");
							cout << "Save Report as (.txt) file has been selected." << endl;
							saveReportTxt(outfile, currentUser.username, currentFile, calcType, rowColSelection, value);
							pauseScreen();
							break;
						case 2: // Create report.html
							logTransaction(outfile, currentUser.username, " has saved the report as a HTML file.");
							cout << "Save Report as (.html) file has been selected." << endl;
							saveReportHTML(outfile, currentUser.username, currentFile, calcType, rowColSelection, value);
							pauseScreen();
							break;
						case 3: // Clearing the report array to do new calculations.
							cout << "Are you sure you want to clear the report? [y] to confirm." << endl
								 << "Input any other key to cancel operation." << endl
								 << "---> ";
							char yeno;
							cin >> yeno;
							if (yeno == 'y')
							{
								cout << "Clearing all calculations from the report..." << endl;
								removeFromReport(calcType, rowColSelection, value);
								logTransaction(outfile, currentUser.username, " cleared all calculations and empty the report.");
								pauseScreen();
							}
							break;
						case 4: // Return to Main Menu
							clearScreen();
							break;
						default:
							cout << endl
								 << "Invalid input, please try again by selecting an integer from 1 to 4." << endl;
							pauseScreen();
							clearScreen();
						}
					} while (choice != 4);
				}
				break;
			case ACC_SETTINGS:
				clearScreen();
				logTransaction(outfile, currentUser.username, " proceeded to their Account Settings.");
				if (currentUser.userType == 0) // Buyer account settings
				{
					do
					{
						buyerAccountSettings(currentUser.username);
						cin >> choice;
						inputValidation();
						switch (choice)
						{
						case 1: // Change Password
							readUsername(usernames, usernamefile, userSize);
							checkPassword(usernames, newFile, currentUserIndex, userSize, newPassword);
							pauseScreen();
							clearScreen();
							logTransaction(outfile, currentUser.username, " successfully changed their password.");
							break;
						case 2: // Log Out
							cout << "Logging Out from the session..." << endl;
							logTransaction(outfile, currentUser.username, " has logged out from the session.");
							pauseScreen();
							clearScreen();
							main();
							break;
						case 3: // Return to Main Menu
							clearScreen();
							break;
						default:
							cout << endl
								 << "Invalid input, please try again by selecting an integer from 1 to 3." << endl;
							pauseScreen();
							clearScreen();
						}
					} while (choice != 3);
				}
				else // Admin account settings (+ create/delete user)
				{
					do
					{
						adminAccountSettings(currentUser.username);
						cin >> choice;
						inputValidation();
						switch (choice)
						{
						case 1: // Change Password
							readUsername(usernames, usernamefile, userSize);
							checkPassword(usernames, newFile, currentUserIndex, userSize, newPassword);
							logTransaction(outfile, currentUser.username, " successfully changed their password.");
							pauseScreen();
							clearScreen();
							break;
						case 2: // Log Out
							cout << "Logging Out from the session..." << endl;
							logTransaction(outfile, currentUser.username, " has logged out from the session.");
							pauseScreen();
							clearScreen();
							main();
							break;
						case 3: // Create New User
							readUsername(usernames, usernamefile, userSize);
							cout << "Function to create a new user has been called" << endl;
							checkUser(usernames, newFile, userSize, newpassword, newusername, newusertype);
							pauseScreen();
							clearScreen();
							logTransaction(outfile, currentUser.username, " has created a new user.");
							break;
						case 4: // Delete Existing User (aka Change userStatus to Inactive)
							readUsername(usernames, usernamefile, userSize);
							cout << "Function to delete an existing user has been called" << endl;
							deleteAccount(usernames, newFile, currentUserIndex, userSize);
							pauseScreen();
							clearScreen();
							logTransaction(outfile, currentUser.username, " has deleted an existing user.");
							break;
						case 5: // Return to Main Menu
							clearScreen();
							break;
						default:
							cout << endl
								 << "Invalid input, please try again by selecting an integer from 1 to 5." << endl;
							pauseScreen();
							clearScreen();
						}
					} while (choice != 5);
				}
				break;
			case EXIT_PROGRAM:
				logTransaction(outfile, currentUser.username, " exited the program.");
				exitProgram();
				break;
			default:
				cout << endl
					 << "Invalid input, please try again by selecting an integer from 1 to 6." << endl;
				pauseScreen();
				clearScreen();
			}
		} while (choice != EXIT_PROGRAM);
	}
	return 0;
}