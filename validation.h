//***************************************************************
// This header file contans all the functions created by:      //
//                                                             //
// Name          : Muhammad Lutfi bin Mohd Izzat               //
// Student ID    : 1201100521                                  //
// Phone Number  : +60 17-260-9255                             //
// Main Module   : F3 Statistical Analysis                     //
//                                                             //
//***************************************************************
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <cctype>

using namespace std;

void CheckColumnSize(fstream &, bool &, string &);
void GetCanCompute(fstream &, bool &, vector<bool> &);
void GetColumnTitles(fstream &, bool &, vector<string> &);
void GetRowSize(fstream &, bool &, string &);
void GetTable(fstream &, bool &, vector<vector<int>> &);
void LoadDataFile(string &, vector<vector<int>> &, int &, int &, vector<string> &, bool &, vector<bool> &);

void LoadDataFile(string &file, vector<vector<int>> &Table, int &Row, int &Col, vector<string> &columnTitles, bool &dataError, vector<bool> &canCompute)
{
    fstream DataFile;
    dataError = true;
    string column;
    string row;

    Table.clear();
    columnTitles.clear();
    canCompute.clear();

    DataFile.open(file, ios::in);

    if (!DataFile)
    {
        cout << endl
             << "Incorrect filename! File does not exist!" << endl
             << endl;
        dataError = false;
    }

    CheckColumnSize(DataFile, dataError, column);

    if (dataError == true) //filters out if column value is invalid
    {
        GetColumnTitles(DataFile, dataError, columnTitles); //gets column titles

        if (columnTitles.size() == stoi(column)) // filters out if column size is not equal to number of columns
        {
            GetCanCompute(DataFile, dataError, canCompute);

            if (dataError == true) // filters out the errors encountered in the canCompute line
            {
                if (canCompute.size() == stoi(column)) // filters out if the number of canCompute line is not equal to number of columns
                {
                    GetRowSize(DataFile, dataError, row);

                    if (dataError == true) // filters out if row value is invalid
                    {
                        GetTable(DataFile, dataError, Table);

                        if (dataError == true)
                        {
                            if (Table.size() == stoi(row)) //check if the table rows are the same as row value given
                            {
                                for (int i = 0; i < Table.size(); i++)
                                {
                                    for (int j = 0; j < Table[i].size(); j++)
                                    {
                                        if (Table[i].size() != stoi(column)) //check if all the table columns are the same as the column given
                                        {
                                            dataError = false;
                                        }
                                    }
                                }

                                if (dataError == true) // last if statement to show that data is valid
                                {
                                    cout << endl
                                         << "Table successfully loaded with no errors." << endl;
                                    Row = stoi(row);
                                    Col = stoi(column);
                                }
                            }
                            else
                            {
                                dataError = false;
                                cout << "Table rows are not the same as the row value given." << endl;
                            }
                        }
                    }
                }
                // else //filters out if the number of canCompute line not equal to number of columns
                // {
                //     cout<<"errors in the canCompute line"<<endl;
                //     cout<<"Invalid input, please try again"<<endl;
                // }
            }
            // else // filters out errors in the can compute line
            // {
            //     cout<<"column size is not equal to number of columns in the column title"<<endl;
            //     cout<<"Invalid input, please try again"<<endl;
            // }
        }
        // else // if column size not equal to number of columns
        // {
        //     cout<<"column size is not equal to number of columns in the column title"<<endl;
        //     cout<<"Invalid input, please try again"<<endl;
        // }
    }
    // else// if column value is invalid
    // {
    //     cout<<"column value must be an integer"<<endl;
    //     cout<<"Invalid input, please try again"<<endl;
    // }

    if (dataError == false) // removes any arrays if dataerror is false
    {
        cout << "Invalid data file input, please try again." << endl;
        file = "none";
        Table.clear();
        columnTitles.clear();
        canCompute.clear();
    }
    DataFile.close();
}

void CheckColumnSize(fstream &file, bool &dataError, string &col)
{
    getline(file, col, '\n'); //for column

    for (int i = 0; i < col.length(); i++)
    {
        if (isdigit(col[i]) == false)
        {
            cout << "The column has a non-digit value." << endl;
            dataError = false;
            break;
        }
    }
}

void GetColumnTitles(fstream &file, bool &dataError, vector<string> &columnTitles)
{

    string segment;
    stringstream temp;
    string temporary;

    getline(file, temporary); //get column names

    temp << temporary;

    while (getline(temp, segment, ','))
    {
        columnTitles.push_back(segment);
    }
}

void GetCanCompute(fstream &file, bool &dataError, vector<bool> &canCompute) //get
{
    stringstream compute;
    string part;

    getline(file, part); // to get 0 and 1's from datafile
    compute << part;

    while (getline(compute, part, ',')) // check for every 0's and 1's
    {
        for (int i = 0; i < part.length(); i++)
        {
            if (isdigit(part[i]) == false)
            {
                cout << "the can compute line has a non-digit value" << endl;
                cout << "Invalid datafile, please try again " << endl;

                dataError = false;
                break;
            }
        }
        if (dataError = false) // if there is non-digit in "can compute" value
        {
            break;
        }
        else if (stoi(part) == 0 || stoi(part) == 1) //check if value is equal to 1 or 0
        {
            canCompute.push_back(stoi(part));
            dataError = true;
        }
        else // if value is not equal to 1 or 0
        {
            cout << "the can compute line has value other than 0 and 1" << endl;
            cout << "Invalid datafile, please try again " << endl;
            dataError = false;
            break;
        }
    }
}

void GetRowSize(fstream &file, bool &dataError, string &row)
{
    getline(file, row); // to get row

    for (int i = 0; i < row.length(); i++)
    {
        if (isdigit(row[i]) == false)
        {
            cout << "the row has a non-digit value" << endl;
            cout << "Invalid datafile, please try again " << endl;

            dataError = false;
            break;
        }
    }
}

void GetTable(fstream &file, bool &dataError, vector<vector<int>> &table)
{
    int allDigit = true;

    while (!file.eof()) //get rows )
    {
        stringstream half;
        string tempo;

        getline(file, tempo);
        half << tempo;
        vector<int> row; //initialise one row

        while (getline(half, tempo, ','))
        {
            for (int i = 0; i < tempo.length(); i++)
            {
                if (isdigit(tempo[i]) == false)
                {
                    allDigit = false;
                    cout << "the row line has a non-digit value" << endl;
                    cout << "Invalid datafile, please try again " << endl;

                    dataError = false;
                    break;
                }
            }
            if (allDigit == true)
            {
                row.push_back(stoi(tempo));
            }
            else
            {
                break;
            }
        }
        if (allDigit == true)
        {
            table.push_back(row);
            
        }
        else
        {
            break;
        }
    }
}
