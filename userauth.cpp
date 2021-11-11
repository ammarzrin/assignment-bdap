#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>  
#include <cstdlib>
#include <vector>
//macro defining the number of usernames to be handled by program

#define USERCOUNT 100

using namespace std;



// Username structure
struct User
{
    string username;
    string password;
    bool userType;
    bool status;
};

void clearScreen()
{
	system("cls"); // Function to clear the screen.
}
void pauseScreen()
{
	cout << endl;
	system("PAUSE"); // Function to pause, and wait for any key from user to continue.
}

//function prototypes
void readusername(vector<User>&, fstream&);

void readpass(vector<User>&, fstream &);

bool checkpass(string, vector<User>&, int);

int checkusername(string, vector<User>&);

void changepassword(fstream&, ofstream&, int);

// added-function

void loginpage(User&);

int main()
{
    fstream usernamefile;
    ofstream newFile;
    int bruh = 0;

    changepassword(usernamefile, newFile, bruh);

    vector<User> usernames;
    //bool logIn = false;

    //reading usernames from a file

    readusername(usernames, usernamefile);

    //reading passwords from a file

    //readpass(passwords, passfile);

    string username, password; //variables for user to key in input

  
    int index;

    //prompt to enter username

    cout << "\nEnter username: ";
    cin >> username;

    //check if username exists, if it exists store the index number

    //of username in a variable

    index = checkusername(username, usernames);

    //if username exists, ask for password

    if (index != -1)
    {

        cout << "Enter password: ";
        cin >> password;

        //chek password

        if (checkpass(password, usernames, index))
        {

            cout << "Verified. Username and password match";

            User currentUser;
            currentUser.username = username;
            currentUser.password = password;
            currentUser.userType = usernames[index].userType;
            currentUser.status = usernames[index].status;

            pauseScreen();

            // redirecting to following page

            loginpage(currentUser); // pointer variables
        }
        else
        {
            cout << "Invalid password";
            cout << "Please try again";
        }
    }    
    //if username does not exixt
    else
    {
        cout << "Invalid username...\nExiting...";
    }
    return 0;

}

//this function reads all usernames from a file and stores it in an array of strings

void readusername(vector<User>& usernames, fstream &file)
{

    //opening the file

    file.open("users.txt", ios::in);

    //check if file was opened successfully

    if (!file)
    {
        cout << "\nError opening file...";
        return;
    }

    int j = 0; // Here j is used for usernames index number

    string temp;
    //read the file contents one by one and store in array
    getline(file, temp, ',');
    
    while (file)
    {
        usernames.push_back(User());

        cout << temp << endl;
        usernames[j].username = temp;

        getline(file, temp, ',');
        cout << temp << endl;
        usernames[j].password = temp;

        getline(file, temp, ',');
        cout << temp << endl;
        istringstream(temp) >> usernames[j].userType;

        getline(file, temp, '\n');
        cout << temp << endl;
        istringstream(temp) >> usernames[j].status;

        
        getline(file,temp, ',');
        j++;
    }

    //close the file

    file.close();
}

void changepassword(fstream& oldFile, ofstream& newFile, int bruh)
{
    oldFile.open("users.txt", ios::in);

    newFile.open("newFile.txt", ios::out);

    int i = 0;
    string temp;
    string newpassword;

    // if (!oldFile)
    // {
    //     cout << "\nError opening file...";
    //     return;
    // }

    getline(oldFile, temp, ',');

    while(oldFile)
    {
        newFile << temp << ',';

        getline(oldFile, temp, ',');
        newFile << temp << ',';
        
        getline(oldFile, temp, ',');
        newFile << temp << ',';

        getline(oldFile, temp, '\n');
        newFile << temp << '\n';

        getline(oldFile, temp, ',');

        i++;
    }

}

//this function checks the existence of username and returns the index of its position in array

int checkusername(string username, vector<User>& usernames)
{

    for (int i = 0; i < USERCOUNT; i++) // have to change this afterwards
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

bool checkpass(string password, vector<User>& usernames, int index)
{

    return usernames[index].password == password;
}

// function that formats the resulting output
void loginpage(User& currentUser) // not important
{

    // 'credentialwidth' is the max text length of the two (username or password)

    int credentialwidth = 0;
    // 'tablewidth' is the width of the table

    int tablewidth = 15;
    credentialwidth =
        (currentUser.username.length() >
         currentUser.password.length())
            ? currentUser.username.length()
            : currentUser.password.length();
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

    cout << left << "| username : " << setfill(' ') << setw(credentialwidth) << currentUser.username << " |" << endl;

    cout << left << "| password : " << setfill(' ') << setw(credentialwidth) << currentUser.password << " |" << endl;

    /*+-------------------+*/

    cout << right << '+' << setfill('-') << setw(credentialwidth + 15) << '+' << endl;
}