//***************************************************************
// This header file contans all the functions created by:      //
//                                                             //
// Name          : Sukanya A/P Thinakaran                      //
// Student ID    : 1201101315                                  //
// Phone Number  : +60 19-276-5030                             //
// Main Module   : F1 User Registration & Authentication       //
//                                                             //
//***************************************************************
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
//macro defining the number of usernames to be handled by program

#define USERCOUNT 100

using namespace std;

// Username structure
struct currentUser
{
    string username;
    string password;
    bool userType;
    bool status;
};

void clearScreen();
void pauseScreen();

//function prototypes

void readusername(currentUser[], fstream &);

void readpass(string[], fstream &);

bool checkpass(string, string *, int);

int checkusername(string, currentUser[]);

// added-function

void loginpage(string username, string password);

//this function reads all usernames from a file and stores it in an array of strings

void readusername(currentUser usernames[], fstream &file)
{

    //opening the file

    file.open("users.txt", ios::in);

    //check if file was opened successfully

    if (!file)
    {
        cout << "\nError opening file...";
        return;
    }

    int i = 0;
    int j = 0; // Here j is used for usernames index number

    string temp;
    //read the file contents one by one and store in array

    while (file >> temp)
    {

        usernames[j].username = temp;
        file >> temp;
        usernames[j].password = temp;
        file >> temp;
        istringstream(temp) >> usernames[j].userType;
        file >> temp;
        usernames[j].status = stoi(temp); //Convert string to int

        cout << usernames[j].username;
        cout << usernames[j].password;
        cout << usernames[j].userType;
        cout << usernames[j].status;

        j++;
        i++;
    }

    //close the file

    file.close();
}

//this function reads all passwords from a file and stores it in an array of strings

void readpass(string passwords[], fstream &file)
{

    //opening the file

    file.open("password.txt", ios::in);

    //check if file was opened successfully

    if (!file)
    {

        cout << "\nError opening file...";

        return;
    }

    int i = 0;

    string temp;

    //read the file contents one by one and store in array

    while (file >> temp)
    {

        passwords[i] = temp;

        i++;
    }

    //close the file

    file.close();
}

//this function checks the existence of username and returns the index of its position in array

int checkusername(string username, currentUser usernames[])
{

    for (int i = 0; i < USERCOUNT; i++)
        if (usernames[i].username == username)
        {
            if (usernames[i].status == 0)
            {
                cout << "\nInactive User\n";
                return -1;
            }
            else
            {
                cout << "\nActive User\n";
                return i;
            }
        }
    return -1;
}

//this function matches a username against its password

bool checkpass(string password, string passwords[], int index)
{

    return passwords[index] == password;
}

// function that formats the resulting output
void loginpage(string username, string password) // not important
{

    // 'credentialwidth' is the max text length of the two (username or password)

    int credentialwidth = 0;
    // 'tablewidth' is the width of the table

    int tablewidth = 15;
    credentialwidth =
        (username.length() >
         password.length())
            ? username.length()
            : password.length();
    credentialwidth =
        (credentialwidth & 1) ? credentialwidth + 1 : credentialwidth;
    tablewidth += credentialwidth;

    /*

                                                        * | |

                                                        * |LOGIN PAGE |

                                                        *   | |

                                                        */

    cout << right << '+' << setfill('-') << setw(tablewidth) << '+' << endl;

    cout << left << '|' << setfill(' ') << setw(tablewidth - 1) << "LOGIN PAGE" << '|' << endl;

    cout << right << '+' << setfill('-') << setw(tablewidth) << '+' << endl;

    cout << '|' << setfill(' ') << setw(tablewidth / 2 + 5) << "XXX SYSTEM" << setw(tablewidth / 2 - 4) << '|' << endl;

    /*

                                                        * | |

                                                        * | |

                                                        */

    cout << '|' << setfill(' ') << setw(tablewidth) << '|' << endl;

    cout << '|' << setfill(' ') << setw(tablewidth) << '|' << endl;

    /*

                                                        * | username : [username] |

                                                        * | password : [password] |

                                                        */

    cout << left << "| username : " << setfill(' ') << setw(credentialwidth) << username << " |" << endl;

    cout << left << "| password : " << setfill(' ') << setw(credentialwidth) << password << " |" << endl;

    /*+-------------------+*/

    cout << right << '+' << setfill('-') << setw(credentialwidth + 15) << '+' << endl;
}