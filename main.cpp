/* Program Information */

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
using namespace std;

// Function prototypes go here.
void clearScreen()
{
	system("cls");
}
void displayMainMenu(string, string);
string fileInputMenu(string, string);
string fileRenameMenu(string, string);
void displayStatMenu(string, string);
void displayReportMenu(string, string, string);
void adminAccountSettings(string);
void buyerAccountSettings(string);
void exitProgram();

// Main Program
int main()
{
	// Constants for menu choices
	const int INPUT_FILE = 1,
			  RENAME_FILE = 2,
			  CALC_STATS = 3,
			  GEN_REPORT = 4,
			  ACC_SETTINGS = 5,
			  EXIT_PROGRAM = 6;

	string currentUser = "username";
	string currentFile = "filename.txt";
	string generatedReport = "The report lol";
	bool userType = 0; // Admin = 1, Buyer = 0
	int choice;

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
			fileInputMenu(currentUser, currentFile);
			break;
		case RENAME_FILE:
			clearScreen();
			fileRenameMenu(currentUser, currentFile);
			break;
		case CALC_STATS:
			clearScreen();
			displayStatMenu(currentUser, currentFile);
			break;
		case GEN_REPORT:
			clearScreen();
			displayReportMenu(currentUser, currentFile, generatedReport);
			break;
		case ACC_SETTINGS:
			clearScreen();
			if (userType = 0)
				buyerAccountSettings(currentUser);
			else
				adminAccountSettings(currentUser);
			break;
		case EXIT_PROGRAM:
			exitProgram();
			break;
		default:
			cout << "Invalid input, please try again.";
			clearScreen();
		}
	} while (choice != EXIT_PROGRAM);
	return 0;
}

// Functions are defined below this comment.

void displayMainMenu(string user, string file)
{
	cout << "=---------------------------------=" << endl;
	cout << "|   Basic Data Analysis Program   |" << endl;
	cout << "=---------------------------------=" << endl;
	cout << "|         -> Main Menu <-         |" << endl;
	cout << "=---------------------------------=" << endl;
	cout << "Welcome, " << user << "." << endl;
	cout << "Current file: " << file << endl;
	cout << endl;
	cout << "What would you like to do?" << endl;
	cout << "    1. Load New Data File" << endl;
	cout << "    2. Rename Current File" << endl;
	cout << "    3. Perform Statistical Analysis" << endl;
	cout << "    4. Generate a Report" << endl;
	cout << "    5. Manage my Account" << endl;
	cout << "    6. Exit program" << endl;
	cout << endl;
	cout << "Select an integer from 1 to 6" << endl;
	cout << "---> ";
}

string fileInputMenu(string user, string file)
{
	cout << "=---------------------------------=" << endl;
	cout << "|   Basic Data Analysis Program   |" << endl;
	cout << "=---------------------------------=" << endl;
	cout << "|      -> New File Input <-       |" << endl;
	cout << "=---------------------------------=" << endl;
	cout << "Logged in as " << user << "." << endl;
	cout << endl;
	cout << "Guidelines:" << endl;
	cout << " >  Before performing other functions, please load a data file for the program to analyze." << endl;
	cout << " >  File must be in the same directory as the program." << endl;
	cout << " >  This program reads data files in (.txt) format." << endl;
	cout << " >  Use double quotation marks ('') if there are spaces in the file name." << endl;
	cout << " >  Input example: 'file name.txt'" << endl;
	cout << " >  To cancel operation and go back to main menu, input a dash (-)." << endl;
	cout << endl;
	cout << "Enter file name ---> ";
	cin >> file;
	clearScreen();
	return file;
}

string fileRenameMenu(string user, string file)
{
	cout << "=---------------------------------=" << endl;
	cout << "|   Basic Data Analysis Program   |" << endl;
	cout << "=---------------------------------=" << endl;
	cout << "|    -> Rename Current File <-    |" << endl;
	cout << "=---------------------------------=" << endl;
	cout << "Logged in as " << user << "." << endl;
	cout << "Current file: " << file << endl;
	cout << endl;
	cout << "Guidelines:" << endl;
	cout << " >  Renaming a file will save the loaded file with a new name." << endl;
	cout << " >  If the file name already exists, you will have to input another file name." << endl;
	cout << " >  Input example: 'file name.txt'" << endl;
	cout << " >  To cancel operation and go back to main menu, input a dash (-)." << endl;
	cout << endl;
	cout << "Enter a new name for current file ---> ";
	cin >> file;
	clearScreen();
	return file;
}

void displayStatMenu(string user, string file)
{
	cout << "=---------------------------------=" << endl;
	cout << "|   Basic Data Analysis Program   |" << endl;
	cout << "=---------------------------------=" << endl;
	cout << "|   -> Statistical  Analysis <-   |" << endl;
	cout << "=---------------------------------=" << endl;
	cout << "Logged in as " << user << "." << endl;
	cout << "Current file: " << file << endl;
	cout << endl;
	cout << "What would you like to calculate from your file?" << endl;
	cout << "    1. Find Minimum" << endl;
	cout << "    2. Find Maximum" << endl;
	cout << "    3. Median Value" << endl;
	cout << "    4. Mean Value (Average)" << endl;
	cout << "    5. Variance" << endl;
	cout << "    6. Standard Deviation" << endl;
	cout << "    7. Correlation Between 2 Columns" << endl;
	cout << "    8. Distinct Data Members" << endl;
	cout << "    9. Plot a Histogram" << endl;
	cout << "   10. Go Back to Main Menu" << endl;
	cout << endl;
	cout << "Select an integer from 1 to 10" << endl;
	cout << "---> ";
}

void displayReportMenu(string user, string file, string report)
{
	cout << "=---------------------------------=" << endl;
	cout << "|   Basic Data Analysis Program   |" << endl;
	cout << "=---------------------------------=" << endl;
	cout << "|     -> Report  Generator <-     |" << endl;
	cout << "=---------------------------------=" << endl;
	cout << "Logged in as " << user << "." << endl;
	cout << endl;
	cout << "Report for " << file << " is generated below:" << endl;
	cout << endl;
	cout << report;
	cout << endl;
	cout << "What would you like to do now?" << endl;
	cout << "    1. Save Report as text file (.txt)" << endl;
	cout << "    2. Save Report as HTML file (.html)" << endl;
	cout << "    3. Go Back to Main Menu" << endl;
	cout << "    4. Exit Program" << endl;
	cout << endl;
	cout << "Select an integer from 1 to 4" << endl;
	cout << "---> ";
}

void adminAccountSettings(string user)
{
	cout << "=---------------------------------=" << endl;
	cout << "|   Basic Data Analysis Program   |" << endl;
	cout << "=---------------------------------=" << endl;
	cout << "|     -> Account Settings <-      |" << endl;
	cout << "=---------------------------------=" << endl;
	cout << "Logged in as " << user << "." << endl;
	cout << endl;
	cout << "What would you like to do?" << endl;
	cout << "    1. Change Password" << endl;
	cout << "    2. Log Out" << endl;
	cout << "    3. Create a New User" << endl;
	cout << "    4. Delete an Existing User" << endl;
	cout << "    5. Go Back to Main Menu" << endl;
	cout << endl;
	cout << "Select an integer from 1 to 5" << endl;
	cout << "---> ";
}

void buyerAccountSettings(string user)
{
	cout << "=---------------------------------=" << endl;
	cout << "|   Basic Data Analysis Program   |" << endl;
	cout << "=---------------------------------=" << endl;
	cout << "|     -> Account Settings <-      |" << endl;
	cout << "=---------------------------------=" << endl;
	cout << "Logged in as " << user << "." << endl;
	cout << endl;
	cout << "What would you like to do?" << endl;
	cout << "    1. Change Password" << endl;
	cout << "    2. Log Out" << endl;
	cout << "    3. Go Back to Main Menu" << endl;
	cout << endl;
	cout << "Select an integer from 1 to 3" << endl;
	cout << "---> ";
}

void exitProgram()
{
	clearScreen();
	cout << "Goodbye!";
}