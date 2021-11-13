//***************************************************************
// This header file contans all the functions created by:      //
//                                                             //
// Name          : Kheryl Amalia Dania binti Khairul Affendie  //
// Student ID    : 1201100662                                  //
// Phone Number  : +60 19-445-5867                             //
// Main Module   : F2 Data File Reader                         //
//                                                             //
//***************************************************************
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <conio.h>
#include <cstdio>
using namespace std;

//****************************************************************
// renameFile
//
// Task         : Allow user to rename files that they have inputted.
//
// Data in      : old filename and new file name
// Data returned: renamed file
//
//****************************************************************
void renameFile(string &file)
{
    // Converting string currentFile into char array oldname
    string filename = file;
    int length = file.length();
    char oldname[length + 1];
    strcpy(oldname, file.c_str());

    // Getting new name input from the user
    char newname[100];
    cin.getline(newname, 100);
    char txt[5] = ".txt";
    strcat(newname, txt);

    // Validation procedure
    if (rename(oldname, newname) != 0)
    {
        cout << endl
             << "Error! Failure in renaming file. File name already exists." << endl;
        pauseScreen();
    }
    else
    {
        cout << endl
             << "File renamed successfully." << endl;
        pauseScreen();
        file = newname;
    }
}

//****************************************************************
// saveReportTxt
//
// Task         : Save log transaction reports as txt file
//
// Data in      : none
// Data returned: report generated is saved as txt file
//
//****************************************************************
void saveReportTxt(ofstream &outputFile, string user, string file, vector<string> &calcType, vector<string> &selection, vector<float> &calcValue)
{
    file.erase(file.length() - 4); // erases last 4 characters (i.e. .txt) from currentfilename
    outputFile.open("report-" + file + ".txt", ios::app);
    outputFile << endl
               << "Report generated for " << file << ".txt made by " << user << "." << endl;
    outputFile << "=-------------------=------------------=-------------------=" << endl;
    outputFile << "|    Calculation    |     Selection    |       Value       |" << endl;
    outputFile << "=-------------------=------------------=-------------------=" << endl;
    for (int i = 0; i < calcType.size(); i++)
    {
        outputFile << "|                   |                  |                   |" << endl;
        outputFile << "| " << setw(18) << left << calcType[i] << "|" << setw(18) << left << selection[i] << "|" << setw(18) << right << calcValue[i] << " |" << endl;
        outputFile << "|                   |                  |                   |" << endl;
        outputFile << "=-------------------=------------------=-------------------=" << endl;
    }
    outputFile.close();
}

//****************************************************************
// saveReportHTML
//
// Task         : Save log transaction reports as HTML file
//
// Data in      : none
// Data returned: report generated is saved as HTML file
//
//****************************************************************
void saveReportHTML(ofstream &outputFile, string user, string file, vector<string> &calcType, vector<string> &selection, vector<float> &calcValue)
{
    file.erase(file.length() - 4); // erases last 4 characters (i.e. .txt) from currentfilename
    outputFile.open(("report-" + file + ".html"), ios::app);
    outputFile << "<!DOCTYPE html>" << endl
               << "<head>" << endl
               << "<style>" << endl
               << "table, th, td { border: 1px solid black; border-collapse: collapse; text-align: center; column-width: 150px; }"
               << "</style>" << endl
               << "<title> Report for " << file << "</title>" << endl
               << "</head>" << endl
               << "<body>" << endl
               << "<h3>Report generated for " << file << ".txt made by " << user << ".</h3>"
               << "<table>" << endl
               << "<tr>" << endl
               << "<th> Calculation </th>" << endl
               << "<th> Selection </th>" << endl
               << "<th> Value </th>" << endl
               << "</tr>" << endl;
    for (int i = 0; i < calcType.size(); i++)
    {
        outputFile << "<tr>" << endl
                   << "<td>" << calcType[i] << "</td>" << endl
                   << "<td>" << selection[i] << "</td>" << endl
                   << "<td>" << calcValue[i] << "</td>"
                   << "</tr>" << endl;
    }
    outputFile << "</table>" << endl
               << "</body>" << endl
               << "</html>" << endl;
    outputFile.close();
}

//****************************************************************
// logTransaction
//
// Task         : Logs every move user makes into userlog.txt
//
// Data in      : currentUser, description of move
// Data returned: output onto new line in userlog.txt
//
//****************************************************************
void logTransaction(ofstream &outputFile, string &user, string description)
{
    outputFile.open("userlog.txt", ios::app);
    outputFile << user << description << endl;
    outputFile.close();
}