#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;

const int Row = 5;
const int Col = 4;

typedef float TableType[Row][Col];
void TableChoice(TableType, string &);
void MakeNumChoice(TableType, string, int, int, int &);
void NumChoice(TableType, int, int &);
void MakeArray(TableType, string, int, int, int, int *&, int &);
void MakeColArray(TableType, int, int, int *&);
void MakeRowArray(TableType, int, int, int *&);
void MakeAllArray(TableType, int *&, int, int, int &);
void NumChoice2(TableType, int, int &, int &);
void PreCalculation(TableType, string &, int, int, int &, int *&, int &);

float Min(int *, int);
float Max(int *, int);
float Median(int *, int);
float Mean(int *, int);
float Variance(int *, int, float);
void Correlation(int *, int *, int, float &, string &);
void Distinct(int *&, int *&, int *&, int &);
void MakeFreqTable(int *&, int *&, int);
void Histogram(int, int, int *&, int *&, int *&);

/*
int main()
{
    TableType Table = {{5,6,3,6}, {9,5,7,2}, {2,8,5,9}, {8, 3 , 6, 4}, {8,1,7,3}};

    int numCol = Col - 1 ;
    int numRow = Row - 1 ;
    int numChoice;
    int numChoice2;
    string tableChoice;
    int *valArray = nullptr;
    int *valArray2 = nullptr;
    int arraySize;
    int userChoice;

    cout << "numCol : " << numCol <<endl;
    cout << "numRow : " << numRow <<endl;


    cout << "watchu wanna do?" << endl;
    cin >> userChoice;

    if(userChoice == 1)
    {
        float minNum;

        TableChoice(Table, tableChoice);
        cout << "which " << tableChoice << " do you want?" <<endl;
        MakeNumChoice(Table, tableChoice, numRow, numCol, numChoice);
        MakeArray(Table, tableChoice, numChoice, numRow, numCol, valArray, arraySize);        

        minNum = Min(valArray, arraySize);
        cout << "the min value of " << tableChoice << " " << numChoice  << " is " << minNum;

    }
    else if (userChoice == 2)
    {
        float maxNum;

        TableChoice(Table, tableChoice);
        cout << "which " << tableChoice << " do you want?" <<endl;
        MakeNumChoice(Table, tableChoice, numRow, numCol, numChoice);
        MakeArray(Table, tableChoice, numChoice, numRow, numCol, valArray, arraySize);  

        maxNum = Max(valArray, arraySize);
        cout << "the max value of " << tableChoice << " " << numChoice  << " is " << maxNum;
    }
    else if (userChoice == 3)
    {
        float medianNum;

        TableChoice(Table, tableChoice);
        cout << "which " << tableChoice << " do you want?" <<endl;
        MakeNumChoice(Table, tableChoice, numRow, numCol, numChoice);
        MakeArray(Table, tableChoice, numChoice, numRow, numCol, valArray, arraySize);  

        medianNum = Median(valArray, arraySize);
        cout << "the median value of " << tableChoice << " " << numChoice  << " is " << medianNum;
    }
    else if (userChoice == 4)
    {
        float meanNum;

        TableChoice(Table, tableChoice);
        cout << "which " << tableChoice << " do you want?" <<endl;
        MakeNumChoice(Table, tableChoice, numRow, numCol, numChoice);
        MakeArray(Table, tableChoice, numChoice, numRow, numCol, valArray, arraySize);  

        meanNum = Mean(valArray, arraySize);
        cout << "the mean value of " << tableChoice << " " << numChoice  << " is " << meanNum;
    }
    else if(userChoice == 5)
    {
        float varianceNum;
        float meanNum;

        TableChoice(Table, tableChoice);
        cout << "which " << tableChoice << " do you want?" <<endl;
        MakeNumChoice(Table, tableChoice, numRow, numCol, numChoice);
        MakeArray(Table, tableChoice, numChoice, numRow, numCol, valArray, arraySize);  

        meanNum = Mean(valArray, arraySize);
        varianceNum = Variance(valArray, arraySize, meanNum);
        cout << "the variance value of " << tableChoice << " " << numChoice  << " is " << varianceNum;
    }
    else if(userChoice == 6)
    {
        float varianceNum;
        float meanNum;
        float stdNum;

        TableChoice(Table, tableChoice);
        cout << "which " << tableChoice << " do you want?" <<endl;
        MakeNumChoice(Table, tableChoice, numRow, numCol, numChoice);
        MakeArray(Table, tableChoice, numChoice, numRow, numCol, valArray, arraySize);  

        meanNum = Mean(valArray, arraySize);
        varianceNum = Variance(valArray, arraySize, meanNum);
        stdNum = sqrt(varianceNum);
        cout << "the standard deviation of " << tableChoice << " " << numChoice  << " is " << stdNum;
    }
    
    else if(userChoice == 7)
    {
        float correlationNum;
        string corMessage;
        tableChoice = "col";

        NumChoice2(Table, numCol, numChoice, numChoice2);
        MakeArray(Table, tableChoice, numChoice, numRow, numCol, valArray, arraySize);  
        MakeArray(Table, tableChoice, numChoice2, numRow, numCol, valArray2, arraySize);  

        for (int i =0; i < numRow ; i++)
        {
            cout << valArray[i] << " ";
        }

        cout <<endl;

        for (int i =0; i < numRow ; i++)
        {
            cout << valArray2[i] << " ";
        }
        cout <<endl;

        Correlation(valArray, valArray2, arraySize, correlationNum, corMessage);
        cout << "the correlation of column " << numChoice << " and " << numChoice2  << " is " << correlationNum;
        delete[] valArray2;
    }
    else if(userChoice == 8)
    {
        int *frequency = nullptr;
        int *distNumbers   = nullptr;

        MakeAllArray(Table, valArray,  numRow, numCol, arraySize);
        frequency = new int[arraySize];
        distNumbers = new int[arraySize];

        Distinct(valArray, frequency, distNumbers, arraySize);
        MakeFreqTable(distNumbers,frequency,arraySize);

        delete[] frequency, distNumbers;
    }
    /*else if(userChoice == 9)
    {
        int

    }
*/

void PreCalculation(TableType Table, string &tableChoice, int numRow, int numCol, int &numChoice, int *&valArray, int &arraySize)
{
    TableChoice(Table, tableChoice);
    cout << "which " << tableChoice << " do you want?" << endl;
    MakeNumChoice(Table, tableChoice, numRow, numCol, numChoice);
    MakeArray(Table, tableChoice, numChoice, numRow, numCol, valArray, arraySize);
}

void TableChoice(TableType Table, string &Choice) //remember to change the heading after this
{
    cout << "Do you want to compute col or row?" << endl;
    cin >> Choice;

    while (Choice != "row" && Choice != "col")
    {
        cout << "Invalid input, please input only row or col" << endl;
        cin >> Choice;
    }

    cout << "you have selected : " << Choice << endl;
}

void MakeNumChoice(TableType Table, string Choice, int Row, int Col, int &numChoice)
{
    cout << Choice << endl;

    if (Choice == "row")
    {
        NumChoice(Table, Row, numChoice);
    }
    else if (Choice == "col")
    {
        NumChoice(Table, Col, numChoice);
    }
}

void NumChoice(TableType Table, int size, int &Choice)
{
    int input;
    cin >> input;

    while (input < 1 || input > size)
    {
        cout << "Invalid input, please input within a range of " << 1 << " and " << size << endl;
        cin >> input;
    }

    cout << "you have selected : " << input << endl;
    Choice = input;
}

void NumChoice2(TableType Table, int size, int &Choice1, int &Choice2)
{
    int input;
    cout << "Please input the first column you want" << endl;
    cin >> input;

    while (input < 1 || input > size)
    {
        cout << "Invalid input, please input within a range of " << 1 << " and " << size << endl;
        cin >> input;
    }
    cout << "you have selected : " << input << endl;
    Choice1 = input;

    cout << "Please input the second column you want" << endl;
    cin >> input;

    while (input < 1 || input > size || input == Choice1)
    {
        cout << "Invalid input, please input within a range of " << 1 << " and " << size << " and not equal to first column" << endl;
        cin >> input;
    }
    cout << "you have selected : " << input << endl;
    Choice2 = input;
}

void MakeArray(TableType Table, string Choice, int numChoice, int Row, int Col, int *&valArray, int &arraySize)
{
    if (Choice == "col")
    {
        arraySize = Row;
        valArray = new int[arraySize];
        MakeColArray(Table, numChoice, arraySize, valArray);
    }

    else if (Choice == "row")
    {
        arraySize = Col;
        valArray = new int[arraySize];
        MakeRowArray(Table, numChoice, arraySize, valArray);
    }
}

void MakeColArray(TableType Table, int numChoice, int size, int *&ColArray)
{
    for (int i = 0; i < size; i++)
    {
        *(ColArray + i) = Table[i + 1][numChoice];
    }
}

void MakeRowArray(TableType Table, int numChoice, int size, int *&RowArray)
{
    for (int i = 0; i < size; i++)
    {
        *(RowArray + i) = Table[numChoice][i + 1];
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
        cout << mid << endl;
        cout << valArray[mid] << " " << valArray[mid - 1] << endl;
        median = (valArray[mid] + valArray[mid - 1]) / 2.00;
    }
    else
    {
        mid = size / 2;
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

    for (int i = 0; i < size; i++)
    {
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumXsquared += pow(x[i], 2);
        sumYsquared += pow(y[i], 2);
    }

    cout << "Sum X = " << sumX << " Sum Y = " << sumY << " SumXY = " << sumXY << " SumX squared = " << sumXsquared << " SumY squared = " << sumYsquared << endl;

    correlation = ((size * sumXY) - (sumX * sumY)) / sqrt(((size * sumXsquared) - (pow(sumX, 2))) * ((size * sumYsquared) - (pow(sumY, 2))));
}

void MakeAllArray(TableType Table, int *&valArray, int row, int col, int &size)
{
    size = row * col;
    valArray = new int[size];

    int j = 0;
    for (int i = 0; i < row; i++)
    {
        for (int count = 0; count < col; count++)
        {
            *(valArray + j) = Table[i + 1][count + 1];
            j++;
        }
    }
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

    cout << "=----------------------------=-----------------------------=" << endl;
    cout << "|           Data             |          Frequency          |" << endl;
    cout << "=----------------------------=-----------------------------=" << endl;

    for (int i = 0; i < size; i++)
    {
        cout << "|" << setw(27) << numbers[i] << " |" << setw(28) << frequency[i] << " |" << endl;
    }
    cout << "=----------------------------=-----------------------------=" << endl;
}