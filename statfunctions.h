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
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

void PreCalculation(vector<vector<int>>, string &, int, int, int &, int *&, int &);
void TableChoice(vector<vector<int>>, string &);
void MakeNumChoice(vector<vector<int>>, string, int, int, int &);
void NumChoice(vector<vector<int>>, string, int, int &);
void choose2Columns(vector<vector<int>>, int, int &, int &);
void inputRangeValidation(int &, bool, int, int);
void MakeArray(vector<vector<int>>, string, int, int, int, int *&, int &);
void MakeColArray(vector<vector<int>>, int, int, int *&);
void MakeRowArray(vector<vector<int>>, int, int, int *&);
void MakeAllArray(vector<vector<int>>, int *&, int, int, int &);

float Min(int *, int);
float Max(int *, int);
float Median(int *, int);
float Mean(int *, int);
float Variance(int *, int, float);
void Correlation(int *, int *, int, float &, string &);
void Distinct(int *&, int *&, int *&, int &);
void MakeFreqTable(int *&, int *&, int);
void Histogram(int*&, int, int, vector<vector<int>>&);
void Interval(int*&, vector<vector<int>>&, int*&, int);

void PreCalculation(vector<vector<int>> Table, string &tableChoice, int numRow, int numCol, int &numChoice, int *&valArray, int &arraySize)
{
    TableChoice(Table, tableChoice);
    cout << "Select a " << tableChoice << " to compute ---> ";
    MakeNumChoice(Table, tableChoice, numRow, numCol, numChoice);
    MakeArray(Table, tableChoice, numChoice, numRow, numCol, valArray, arraySize);
}

void TableChoice(vector<vector<int>> Table, string &Choice) //remember to change the heading after this
{
    cout << "Do you want to compute a column or a row? (col/row)" << endl;
    cout << "---> ";
    cin >> Choice;
    cout << endl;

    while (Choice != "col" && Choice != "row")
    {
        cout << "Invalid input, please enter either col or row." << endl;
        cout << "---> ";
        cin >> Choice;
        cout << endl;
    }

    if (Choice == "col")
        Choice = "column";
}

void MakeNumChoice(vector<vector<int>> Table, string Choice, int Row, int Col, int &numChoice)
{
    if (Choice == "row")
    {
        NumChoice(Table, Choice, Row, numChoice);
    }
    else if (Choice == "column")
    {
        NumChoice(Table, Choice, Col, numChoice);
    }
}

void NumChoice(vector<vector<int>> Table, string tableChoice, int size, int &Choice)
{
    int input;
    cin >> input;
    cout << endl;

    while (input < 1 || input > size)
    {
        cout << "Invalid input, please enter an integer within a range of 1 and " << size << "." << endl;
        cout << "---> ";
        cin >> input;
    }

    Choice = input - 1;
    cout << endl
         << "You have selected " << tableChoice << " " << input << "." << endl
         << endl;
}

void choose2Columns(vector<vector<int>> Table, int size, int &firstChoice, int &secondChoice)
{
    int input;
    bool choice1 = false;

    cout << "Please choose the first column for comparison ---> ";
    cin >> input;
    inputRangeValidation(input, choice1, size, firstChoice);
    firstChoice = input;
    choice1 = true;
    cout << endl
         << "You have selected column " << input << " as the first column." << endl
         << endl;

    cout << "Please choose the second column for comparison ---> ";
    cin >> input;
    inputRangeValidation(input, choice1, size, firstChoice);
    secondChoice = input;
    cout << endl
         << "You have selected column " << input << " as the second column." << endl
         << endl;
}

void inputRangeValidation(int &input, bool choice1, int size, int first)
{
    if (choice1 = true) // This means first column for comparison has been chosen.
    {
        while (input < 1 || input > size || input == first)
        {
            cout << "Invalid input, please enter an integer within a range of 1 and " << size << " and is not equal to the first choice of column." << endl;
            cout << "---> ";
            cin >> input;
        }
    }
    else // First column has not been chosen yet.
    {
        while (input < 1 || input > size)
        {
            cout << "Invalid input, please enter an integer within a range of 1 and " << size << "." << endl;
            cout << "---> ";
            cin >> input;
        }
    }
}

void MakeArray(vector<vector<int>> Table, string Choice, int numChoice, int Row, int Col, int *&valArray, int &arraySize)
{
    if (Choice == "column")
    {
        arraySize = Row;
        valArray = new int[arraySize];
        MakeColArray(Table, numChoice, arraySize, valArray);
    }
    else if (Choice == "row")
    {
        arraySize = Col;
        cout << arraySize << endl;
        valArray = new int[arraySize];
        MakeRowArray(Table, numChoice, arraySize, valArray);
    }
}

void MakeColArray(vector<vector<int>> Table, int numChoice, int size, int *&ColArray)
{
    for (int i = 0; i < size; i++)
    {
        *(ColArray + i) = Table[i][numChoice];
    }
}

void MakeRowArray(vector<vector<int>> Table, int numChoice, int size, int *&RowArray)
{
    for (int i = 0; i < size; i++)
    {
        *(RowArray + i) = Table[numChoice][i + 1];
        cout << *(RowArray + i) << endl;
    }
}

void MakeAllArray(vector<vector<int>> Table, int *&valArray, int row, int col, int &size)
{
    size = row * col;
    valArray = new int[size];

    int j = 0;
    for (int i = 0; i < row; i++)
    {
        for (int count = 0; count < col; count++)
        {
            *(valArray + j) = Table[i][count + 1];
            j++;
        }
    }
}

float Min(int *valArray, int size)
{
    float min = valArray[0];

    for (int i = 1; i < size; i++)
    {
        if (min > valArray[i])
        {
            min = valArray[i];
        }
    }

    return min;
}

float Max(int *valArray, int size)
{
    float max = valArray[0];

    for (int i = 1; i < size; i++)
    {
        if (max < valArray[i])
        {
            max = valArray[i];
        }
    }

    return max;
}

float Mean(int *valArray, int size)
{
    float sum;
    float mean;

    for (int i = 0; i < size; i++)
    {
        sum += valArray[i];
    }

    mean = sum / size;

    return mean;
}

float Median(int *valArray, int size)
{
    int mid;
    float median;
    float total = size;
    sort(valArray, valArray + size);

    if (size % 2 == 0)
    {
        mid = round(total / 2);
        // cout << "Number of Values = " << total << endl
        //      << "Position of Middle Values = " << mid << " and " << (mid + 1) << endl
        //      << "Mid Value #1 = " << valArray[mid - 1] << endl
        //      << "Mid Value #2 = " << valArray[mid] << endl;
        median = (valArray[mid] + valArray[mid - 1]) / 2.00;
    }
    else
    {
        mid = size / 2;
        // cout << "Number of Values = " << total << endl
        //      << "Position of Middle Value = " << mid << endl
        //      << endl;
        median = valArray[mid];
    }
    return median;
}

float Variance(int *valArray, int size, float mean)
{
    float totalMean = 0;
    float variance;
    float x;

    cout << "Mean is " << mean << endl;

    for (int i = 0; i < size; i++)
    {
        x = valArray[i] - mean;
        totalMean += pow(x, 2);
    }

    variance = totalMean / (size - 1);
    return variance;
}

void Correlation(int *x, int *y, int size, float &correlation, string &message)
{
    float sumX = 0, sumY = 0, sumXY, sumXsquared = 0, sumYsquared = 0;
    float sizer = size;
    cout << size << endl;
    stringstream temp;

    cout << "=---------------------------------------------=" << endl;
    temp << "=---------------------------------------------=" << endl;
    cout << "|   x   |   y   |   x*y   |   x^2   |   y^2   |" << endl;
    temp << "|   x   |   y   |   x*y   |   x^2   |   y^2   |" << endl;
    temp << "=---------------------------------------------=" << endl;
    cout << "=---------------------------------------------=" << endl;

    for (int i = 0; i < size; i++)
    {
        cout << "|" << setw(6) << x[i] << " |" << setw(6) << y[i] << " |" << setw(6) << x[i] * y[i] << "  |" << setw(6) << pow(x[i], 2) << "  |" << setw(6) << pow(y[i], 2) << " |" << endl;
        temp << "|" << setw(6) << x[i] << " |" << setw(6) << y[i] << " |" << setw(6) << x[i] * y[i] << "  |" << setw(6) << pow(x[i], 2) << "  |" << setw(6) << pow(y[i], 2) << " |" << endl;
        temp << "=---------------------------------------------=" << endl;
        cout << "=---------------------------------------------=" << endl;

        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumXsquared += pow(x[i], 2);
        sumYsquared += pow(y[i], 2);
    }

    cout << "Sum X     = " << sumX << endl
         << "Sum Y     = " << sumY << endl
         << "Sum (X*Y) = " << sumXY << endl
         << "Sum (X^2) = " << sumXsquared << endl
         << "Sum (Y^2) = " << sumYsquared << endl;

    correlation = ((sizer * sumXY) - (sumX * sumY)) / sqrt(((sizer * sumXsquared) - (pow(sumX, 2))) * ((sizer * sumYsquared) - (pow(sumY, 2))));
}

void Distinct(int *&valArray, int *&frequency, int *&numbers, int &size)
{
    sort(valArray, valArray + size);

    int x;
    int i = 0;
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        x = valArray[i];
        frequency[count] = 1;
        numbers[count] = x;

        while (valArray[i + 1] == x)
        {
            frequency[count] += 1;
            i++;
        }
        count++;
    }

    size = count;
}

void MakeFreqTable(int *&numbers, int *&frequency, int size)
{
    stringstream temp;

    cout << "=----------------------------=-----------------------------=" << endl;
    temp << "=----------------------------=-----------------------------=" << endl;
    cout << "|           Data             |          Frequency          |" << endl;
    temp << "|           Data             |          Frequency          |" << endl;
    cout << "=----------------------------=-----------------------------=" << endl;
    temp << "=----------------------------=-----------------------------=" << endl;

    for (int i = 0; i < size; i++)
    {
        cout << "|" << setw(27) << numbers[i] << " |" << setw(28) << frequency[i] << " |" << endl;
        temp << "|" << setw(27) << numbers[i] << " |" << setw(28) << frequency[i] << " |" << endl;
    }

    string freq(temp.str());
}

void Histogram(int *&valArray, int min, int max, vector<vector<int>> &classInterval)
{
    float range = max - min;

    vector<int> row;
    int classWidth = ceil(range /6.0);
    int start = min;

    row.push_back(start);
    start = start + classWidth;
    row.push_back(start);
    classInterval.push_back(row);

    for (int i = 1; i < 6; i++)
    {
        start += 1;
        vector<int> row;
        row.push_back(start);
        start += classWidth;
        row.push_back(start);
        

        classInterval.push_back(row);
    }
}

void Interval(int*& valArray, vector<vector<int>>& classInterval, int*& frequency, int size)
{
    sort(valArray, valArray + size);
    cout <<size <<endl;
    int j = 0;

    // for (int i = 0; i <classInterval.size(); i++)
    // {
    //     cout << classInterval[i][0] << " " << classInterval[i][1] <<endl;
    // }

    for (int i = 0; i < classInterval.size(); i++)
    {    
        if ( classInterval[i][0] >= valArray[j] && valArray[j] <= classInterval[i][1] && j < size + 1)
        {
            cout << valArray[j] <<endl;
            frequency[i] = 1;
            j++;

            while( classInterval[i][0] >= valArray[j] && valArray[j] <= classInterval[i][1] && j < size + 1)
            {
                cout<<valArray[j]<<endl;
                frequency[i] += 1;
                j++;
            }
        }
    }

    // for(int i = 0; i < 9; i++)
    // {
    //     cout << frequency[i] <<endl;
    // }
}
