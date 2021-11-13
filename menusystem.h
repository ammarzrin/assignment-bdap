//***************************************************************
// This header file contans all the functions created by:      //
//                                                             //
// Name          : Muhammad Ammar bin Muhamad Azrin            //
// Student ID    : 1191102915                                  //
// Phone Number  : +60 19-892 7574                             //
// Main Module   : F4 Menu System                              //
//                                                             //
//***************************************************************
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>
using namespace std;

// void clearScreen();
// void pauseScreen();

// Function Prototypes a.k.a. List of functions made for this module.

void displayLoginPage(string &, string &);
void displayMainMenu(string &, string &);                                                     // The Main Menu to bbe displayed upon logging in.
void fileInputMenu(string &, string &, bool &);                                               // File Input Menu to be displayed.
void fileRenameMenu(string &, string &);                                                      // File Rename Menu to be displayed.
void adminAccountSettings(string &);                                                          // Account Settings for Admins.
void buyerAccountSettings(string &);                                                          // Account Settings for Buyers.
void titleStatMenu(string &, string &);                                                       // Displays title at all times while performing calculations in Statistical Analysis.
void generateDataTable();                                                                     // Generates data table for user's view at Stat Analysis Menu.
void displayStatMenu();                                                                       // Statistical Analysis Menu to be displayed.
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

//****************************************************************
// displayLoginPage
//
// Task         : Displays the main menu options available
//                for the user.
//
// Data in      : currentUser, currentFile ("none" if no file loaded).
// Data returned: none - displays Main Menu.
//
//****************************************************************
void displayLoginPage(string &username, string &password)
{
    cout << "=----------------------------------------------------------=" << endl;
    cout << "|               Basic Data Analysis Program                |" << endl;
    cout << "=----------------------------------------------------------=" << endl;
    cout << "|                    -> Login Page <-                      |" << endl;
    cout << "=----------------------------------------------------------=" << endl;
    cout << endl
         << "                         Welcome.                           " << endl
         << endl
         << endl;
    cout << "Enter Username ---> ";
    cin >> username;
    cout << endl
         << "Enter Password ---> ";
    cin >> password;
}

//****************************************************************
// displayMainMenu
//
// Task         : Displays the main menu options available
//                for the user.
//
// Data in      : currentUser, currentFile ("none" if no file loaded).
// Data returned: none - displays Main Menu.
//
//****************************************************************
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

//****************************************************************
// fileInputMenu
//
// Task         : Displays the menu for loading a file
//                into the program ("Load New Data File" option).
//
// Data in      : currentUser
// Data returned: none - displays File Input menu.
//
//*********************************************************
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
    cout << "|  >  Input a dash (-) to cancel operation.                |" << endl;
    cout << "|  >  Input example: file name                             |" << endl;
    cout << "|  >  Input name without the file extension (.txt)         |" << endl;
    cout << "=----------------------------------------------------------=" << endl;
    cout << endl;
    cout << "Enter file name ---> ";
    cin.ignore();
    getline(cin, input);
    // To proceed with operation if (-) is not the input.
    if (input != "-")
    {
        file = input + ".txt";
        loaded = true;
    }
    clearScreen();
}

//****************************************************************
// fileRenameMenu
//
// Task         :
//
// Data in      :
// Data returned:
//
//****************************************************************
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
    cout << "|  >  Input example: file name                             |" << endl;
    cout << "|  >  Input name without the file extension (.txt)         |" << endl;
    cout << "=----------------------------------------------------------=" << endl;
    cout << endl;
    cout << "Enter a new name for current file ---> ";
    cin.ignore();
    renameFile(file);
    clearScreen();
}

//****************************************************************
// titleStatMenu
//
// Task         : Displays the program title on top at all times during
//                calculations in the Statistical Analysis menu.
//
// Data in      : none
// Data returned: none
//
//****************************************************************
void titleStatMenu(string &user, string &file)
{
    clearScreen();
    cout << "=----------------------------------------------------------=" << endl;
    cout << "|               Basic Data Analysis Program                |" << endl;
    cout << "=----------------------------------------------------------=" << endl;
    cout << "|                -> Statistical Analysis <-                |" << endl;
    cout << "=----------------------------------------------------------=" << endl;
    cout << endl;
    cout << "Logged in as " << user << "." << endl;
    cout << "Current file: " << file << endl;
    cout << endl;
}

//****************************************************************
// displayStatMenu
//
// Task         : Displays the available options for Statistical
//                analysis.
//
// Data in      :
// Data returned:
//
//****************************************************************
void displayStatMenu()
{
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
    cout << "|     10. Return to Main Menu                              |" << endl;
    cout << "=----------------------------------------------------------=" << endl;
    cout << endl;
    cout << "Select an integer from 1 to 10" << endl;
    cout << "---> ";
}

//****************************************************************
// generateDataTable
//
// Task         : Displays the data file on screen to ease user's choice in calculation.
//
// Data in      :
// Data returned:
//
//****************************************************************
void generateDataTable(vector<vector<int>> table, vector<string> columnTitles)
{
    int columns = columnTitles.size(); // Number of columns
    int rows = table.size();           // Number of rows

    cout << setw(5) << right << "No";
    for (int i = 0; i < columns; i++)
    {
        cout << setw(12) << right << columnTitles[i]; // Shows column titles
    }

    // cout << endl;
    cout << endl;
    for (int row = 0; row < rows; row++)
    {
        cout << setw(5) << right << row + 1; // Shows row number
        for (int col = 0; col < columns; col++)
        {
            cout << setw(12) << right << table[row][col];
        }
        cout << endl;
    }
    cout << endl
         << endl;
}

//****************************************************************
// displayReportMenu
//
// Task         :
//
// Data in      :
// Data returned:
//
//****************************************************************
void displayReportMenu()
{
    cout << endl;
    cout << "=----------------------------------------------------------=" << endl;
    cout << "|  What would you like to do now?                          |" << endl;
    cout << "|      1. Save Report as text file (.txt)                  |" << endl;
    cout << "|      2. Save Report as HTML file (.html)                 |" << endl;
    cout << "|      3. Clear All Calculations (Empty the Report)        |" << endl;
    cout << "|      4. Return to Main Menu                              |" << endl;
    cout << "=----------------------------------------------------------=" << endl;
    cout << endl;
    cout << "Select an integer from 1 to 4" << endl;
    cout << "---> ";
}

//****************************************************************
// adminAccountSettings
//
// Task         :
//
// Data in      :
// Data returned:
//
//****************************************************************
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
    cout << "|      5. Return to Main Menu                              |" << endl;
    cout << "=----------------------------------------------------------=" << endl;
    cout << endl;
    cout << "Select an integer from 1 to 5" << endl;
    cout << "---> ";
}

//****************************************************************
// buyerAccountSettings
//
// Task         :
//
// Data in      :
// Data returned:
//
//****************************************************************
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
    cout << "|      3. Return to Main Menu                              |" << endl;
    cout << "=----------------------------------------------------------=" << endl;
    cout << endl;
    cout << "Select an integer from 1 to 3" << endl;
    cout << "---> ";
}

//****************************************************************
// exitProgram
//
// Task         :
//
// Data in      :
// Data returned:
//
//****************************************************************
void exitProgram()
{
    clearScreen();
    cout << "Goodbye!";
}

//****************************************************************
// emptyReportError
//
// Task         :
//
// Data in      :
// Data returned:
//
//****************************************************************
void emptyReportError()
{
    cout << endl
         << "Report currently has no data to generate." << endl
         << "Please do calculations in the Statistical Analysis menu"
         << " before generating a report." << endl;
    pauseScreen();
    clearScreen();
}

//****************************************************************
// loadFileError
//
// Task         :
//
// Data in      :
// Data returned:
//
//****************************************************************
void loadFileError()
{
    cout << endl
         << "There is currently no file loaded in the program." << endl
         << "Please load the data file at the File Input menu"
         << " before proceeding." << endl;
    pauseScreen();
    clearScreen();
}

//****************************************************************
// addToReport
//
// Task         :
//
// Data in      :
// Data returned:
//
//****************************************************************
void addToReport(vector<string> &calcType, vector<string> &selection, vector<float> &calcValue, string type, string rowcol, float value)
{
    calcType.push_back(type);
    selection.push_back(rowcol);
    calcValue.push_back(value);
}

//****************************************************************
// addDistinctTableToReport
//
// Task         :
//
// Data in      :
// Data returned:
//
//****************************************************************
void addDistinctTableToReport()
{
}

//****************************************************************
// addHistogramToReport
//
// Task         :
//
// Data in      :
// Data returned:
//
//****************************************************************
void addHistogramToReport()
{
}

//****************************************************************
// removeFromReport
//
// Task         : Clears all the vector arrays related to report generation.
//
// Data in      : 3 Vector Arrays of calculation details (type of calculation,
//                column/row selection, the value)
// Data returned: none
//
//****************************************************************
void removeFromReport(vector<string> &calcType, vector<string> &selection, vector<float> &calcValue)
{
    calcType.clear();
    selection.clear();
    calcValue.clear();
}

//****************************************************************
// generateReport
//
// Task         : Creates the report table to display for the user
//
// Data in      : 3 Vector Arrays of calculation details (type of calculation,
//                column/row selection, the value)
// Data returned: A report table generated within the program.
//
//****************************************************************
void generateReport(vector<string> &calcType, vector<string> &selection, vector<float> &calcValue)
{
    cout << "=-------------------=------------------=-------------------=" << endl;
    cout << "|    Calculation    |     Selection    |       Value       |" << endl;
    cout << "=-------------------=------------------=-------------------=" << endl;
    for (int i = 0; i < calcType.size(); i++)
    {
        cout << "|                   |                  |                   |" << endl;
        cout << "| " << setw(18) << left << calcType[i] << "|" << setw(18) << left << selection[i] << "|" << setw(18) << right << calcValue[i] << " |" << endl;
        cout << "|                   |                  |                   |" << endl;
        cout << "=-------------------=------------------=-------------------=" << endl;
    }
}

//****************************************************************
// titleReportMenu
//
// Task         : Displays the program title along with header for
//                report generator. +username and filename
//
// Data in      : currentUser, currentFile
// Data returned: ta-daaa
//
//****************************************************************
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

//****************************************************************************
// inputValidation
//
// Task         : Validates the input from user to make sure it is an integer
//                during most cases of inputting choice in menu navigation.
//
// Data in      : boolean value of int choice when cin >> choice
// Data returned: clears the latest input and ignores until an endline
//
//****************************************************************************
void inputValidation()
{
    while (!cin)
    {
        cin.clear();
        cin.ignore(10, '\n');
    }
}