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

void saveReportTxt()
{
    ifstream infile("report.txt");
    ofstream outfile("txtFile.txt");
    string temp;

    if (infile.good() && outfile.good())
    {
        cout << "Now saving report as txt file ..." << endl;
        getline(infile, temp);
        outfile << temp;
        cout << "Your file has been saved successfully." << endl;
    }
}

void saveReportHTML()
{
    ifstream infile("report.txt");
    ofstream outfile("report.html");
    string temp;

    if (infile.good() && outfile.good())
    {
        cout << "Now saving report as HTML file ..." << endl;
        getline(infile, temp);
        outfile << temp;
        cout << "Your file has been saved successfully." << endl;
    }
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
