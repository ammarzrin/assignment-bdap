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
#include <conio.h>
#include <stdio.h>
using namespace std;

void saveReportTxt(ofstream &outputFile, string user, string file, vector<string> &calcType, vector<string> &selection, vector<float> &calcValue)
{
    outputFile.open("report-" + file + ".txt", ios::app);
    outputFile << endl
               << "Report generated for " << file << " made by " << user << "." << endl;
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

void saveReportHTML(ofstream &outputFile, string user, string file, vector<string> &calcType, vector<string> &selection, vector<float> &calcValue)
{
    outputFile.open(("report-" + file + ".html"), ios::app);

    outputFile << "<!DOCTYPE html>" << endl
               << "<head>" << endl
               << "<title> Report for " << file << "</title>" << endl
               << "</head>" << endl
               << "<body>" << endl
               << "<h3>Report generated for " << file << " made by " << user << ".</h3>"
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

void renameFile()
{
    char oldname[100];
    char newname[100];

    cout << "Enter file name: ";
    cin >> oldname;
    cout << endl;
    cout << "Enter new file name: ";
    cin >> newname;
    if (rename(oldname, newname) != 0)
        cout << "Error renaming file, returning to main menu ..." << endl;
    else
        cout << "File renamed successfully.";
}
