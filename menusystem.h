#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>
using namespace std;

void clearScreen();
void pauseScreen();

// Function Prototypes a.k.a. List of functions made for this module.

void displayMainMenu(string &, string &);                                                     // The Main Menu to bbe displayed upon logging in.
void fileInputMenu(string &, string &, bool &);                                               // File Input Menu to be displayed.
void fileRenameMenu(string &, string &);                                                      // File Rename Menu to be displayed.
void adminAccountSettings(string &);                                                          // Account Settings for Admins.
void buyerAccountSettings(string &);                                                          // Account Settings for Buyers.
void titleStatMenu();                                                                         // Displays title at all times while performing calculations in Statistical Analysis.
void displayStatMenu(string &, string &);                                                     // Statistical Analysis Menu to be displayed.
void titleReportMenu(string &, string &);                                                     // Displays title above generated report in Report Generator.
void displayReportMenu();                                                                     // Menu to be displayed after Report Generation.
void loadFileError();                                                                         // Error message for missing input file in program.
void emptyReportError();                                                                      // Error message for not doing any calculations yet but trying to generate a report.
void exitProgram();                                                                           // Clears the screen and displays a goodbye message.
void addToReport(vector<string> &, vector<string> &, vector<float> &, string, string, float); // Adds every calculation done into 3 parallel vector arrays that will be used when generating the report.
void addDistinctTableToReport();                                                              // Adds the generated Distinct Data values to the report for table generation.
void addHistogramToReport();                                                                  // Adds the generated Histogram values into an array for graph generation in the generated report?
void removeFromReport(vector<string> &, vector<string> &, vector<float> &);                   // Clears the 3 parallel vector arrays once the user is done with the file or exit program.
void generateReport(vector<string> &, vector<string> &, vector<float> &);                     // Generate the report data onto the screen, at the same time data generated here will be used in exporting to file.
void logTransaction(ofstream &, string &, string);

// Function Definitions

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
    cout << "|     10. Return to Main Menu                             |" << endl;
    cout << "=----------------------------------------------------------=" << endl;
    cout << endl;
    cout << "Select an integer from 1 to 10" << endl;
    cout << "---> ";
}

void displayReportMenu()
{
    pauseScreen();
    cout << "=----------------------------------------------------------=" << endl;
    cout << "|  What would you like to do now?                          |" << endl;
    cout << "|      1. Save Report as text file (.txt)                  |" << endl;
    cout << "|      2. Save Report as HTML file (.html)                 |" << endl;
    cout << "|      3. Return to Main Menu                             |" << endl;
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
    cout << "|      5. Return to Main Menu                             |" << endl;
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
    cout << "|      3. Return to Main Menu                             |" << endl;
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

void emptyReportError()
{
    cout << "Report has no data to generate. Please do calculations in the Statistical Analysis menu before proceeding with report generation." << endl;
    pauseScreen();
}

void loadFileError()
{
    cout << "There is currently no file loaded in the program. Please input file at the File Input menu before proceeding." << endl;
    pauseScreen();
}

void addToReport(vector<string> &calcType, vector<string> &selection, vector<float> &calcValue, string type, string rowcol, float value)
{
    calcType.push_back(type);
    selection.push_back(rowcol);
    calcValue.push_back(value);
}

void addDistinctTableToReport()
{
}

void addHistogramToReport()
{
}

void removeFromReport(vector<string> &calcType, vector<string> &selection, vector<float> &calcValue)
{
    calcType.clear();
    selection.clear();
    calcValue.clear();
}

void generateReport(vector<string> &calcType, vector<string> &selection, vector<float> &calcValue)
{
    cout << calcType[0] << endl;
    cout << selection[0] << endl;
    cout << calcValue[0] << endl;
    cout << endl;
}

void titleStatMenu()
{
    clearScreen();
    cout << "=----------------------------------------------------------=" << endl;
    cout << "|               Basic Data Analysis Program                |" << endl;
    cout << "=----------------------------------------------------------=" << endl;
    cout << "|                -> Statistical Analysis <-                |" << endl;
    cout << "=----------------------------------------------------------=" << endl;
    cout << endl;
}

void titleReportMenu(string &user, string &file)
{
    clearScreen();
    cout << "=----------------------------------------------------------=" << endl;
    cout << "|               Basic Data Analysis Program                |" << endl;
    cout << "=----------------------------------------------------------=" << endl;
    cout << "|                  -> Report Generator <-                  |" << endl;
    cout << "=----------------------------------------------------------=" << endl;
    cout << endl;
    cout << "Logged in as " << user << "." << endl;
    cout << "Report for " << file << " is generated below:" << endl;
    cout << endl;
}

void logTransaction(ofstream &outputFile, string &user, string description)
{
    outputFile.open("userlog.txt", ios_base::app);
    outputFile << user << description << endl;
    outputFile.close();
}