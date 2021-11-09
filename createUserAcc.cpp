#include <iostream>
#include <iomanip>
#include <fstream>
#include <unistd.h>
#include <string>
//macro defining the number of usernames to be handled by program

#define USER_COUNT 100

using namespace std;

// Username structure
struct User
{
    string username;

    bool status;
};

//function prototypes

void read_username(User[], fstream &);

void read_pass(string[], fstream &);

bool check_pass(string, string *, int);

int check_username(string, User[]);

// added-function

void login_page(string username, string password);

int main()
{
    //defining variables

    fstream username_file, pass_file;

    User usernames[100]; /*CHANGE HERE*/
    string passwords[100];

    //reading usernames from a file

    read_username(usernames, username_file);

    //reading passwords from a file

    read_pass(passwords, pass_file);

    string username, password;

    int index;

    //prompt to enter username

    cout << "\nEnter username: ";
    cin >> username;

    //check if username exists, if it exists store the index number

    //of username in a variable

    index = check_username(username, usernames);

    //if username exists, ask for password

    if (index != -1)
    {

        cout << "Enter password: ";
        cin >> password;

        //chek password

        if (check_pass(password, passwords, index))
        {

            cout << "Verified. Username and password match";

            int sec = 3;

            while (sec >= 0)
            {

                system("cls");

                cout << "You will be redirected to another page in " << sec << " seconds ...";

                sleep(1);

                sec--;
            }

            system("cls");

            // redirecting to following page

            login_page(username, password);
        }
        else

            cout << "Invalid password";
    }

    //if username does not exixt
    else

        cout << "Invalid username...\nExiting...";

    return 0;
}

//this function reads all usernames from a file and stores it in an array of strings

void read_username(User usernames[], fstream &file)
{

    //opening the file

    file.open("username.txt", ios::in);

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
        if (i % 2 == 0)
        {
            usernames[j].username = temp;
        }
        else
        {
            usernames[j].status = stoi(temp); //Convert string to int
            j++;
        }

        i++;
    }

    //close the file

    file.close();
}

//this function reads all passwords from a file and stores it in an array of strings

void read_pass(string passwords[], fstream &file)
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

int check_username(string username, User usernames[])
{

    for (int i = 0; i < USER_COUNT; i++)
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

bool check_pass(string password, string passwords[], int index)
{

    return passwords[index] == password;
}

// function that formats the resulting output
void login_page(string username, string password)
{

    // 'credential_width' is the max text length of the two (username or password)

    int credential_width = 0;
    // 'table_width' is the width of the table

    int table_width = 15;
    credential_width =
        (username.length() >
         password.length())
            ? username.length()
            : password.length();
    credential_width =
        (credential_width & 1) ? credential_width + 1 : credential_width;
    table_width += credential_width;

    /*

                                                        * | |

                                                        * |LOGIN PAGE |

                                                        *   | |

                                                        */

    cout << right << '+' << setfill('-') << setw(table_width) << '+' << endl;

    cout << left << '|' << setfill(' ') << setw(table_width - 1) << "LOGIN PAGE" << '|' << endl;

    cout << right << '+' << setfill('-') << setw(table_width) << '+' << endl;

    cout << '|' << setfill(' ') << setw(table_width / 2 + 5) << "XXX SYSTEM" << setw(table_width / 2 - 4) << '|' << endl;

    /*

                                                        * | |

                                                        * | |

                                                        */

    cout << '|' << setfill(' ') << setw(table_width) << '|' << endl;

    cout << '|' << setfill(' ') << setw(table_width) << '|' << endl;

    /*

                                                        * | username : [username] |

                                                        * | password : [password] |

                                                        */

    cout << left << "| username : " << setfill(' ') << setw(credential_width) << username << " |" << endl;

    cout << left << "| password : " << setfill(' ') << setw(credential_width) << password << " |" << endl;

    /*+-------------------+*/

    cout << right << '+' << setfill('-') << setw(credential_width + 15) << '+' << endl;
}