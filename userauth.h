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
struct User
{
    string username;
    string password;
    bool userType;
    bool status;
};

void clearScreen();
void pauseScreen();

//function prototypes
void readUsername(vector<User> &, fstream &, int &);
void changePassword(vector<User> &, ofstream &, int, int &, string &);
int checkUsername(string, vector<User> &, int);
void deleteAccount(vector<User> &, ofstream &, int, int &);
bool checkPass(string, vector<User> &, int);
void checkPassword(vector<User> &, ofstream &, int, int &, string &);
void checkUser(vector<User> &, ofstream &, int &, string &, string &, string &);
void checkUserType(vector<User> &, ofstream &, int &, string &, string &, string &);
void makeUser(vector<User> &, ofstream &, int &, string &, string &, string &);
bool checkUserSame(string, vector<User> &, int);
void checkPass(vector<User> &, ofstream &, int &, string &, string &, string &);

bool checkPass(string password, vector<User> &usernames, int index)
{
    return usernames[index].password == password;
}

//you can use this to check the index on where to change the password
int checkUsername(string username, vector<User> &usernames, int size)
{
    for (int i = 0; i < size; i++) // have to change this afterwards
        if (usernames[i].username == username)
        {
            if (usernames[i].status == 0)
            {
                // cout << "\nInactive User\n";
                return -2;
            }
            else
            {
                // cout << "\nActive User\n";
                return i;
            }
        }
    return -1;
}

void deleteAccount(vector<User> &usernames, ofstream &file, int index, int &size)
{
    string choice;
    bool accExist = false;
    cout << "who do you want to delete?" << endl;
    cin >> choice;
    for (int i = 0; i < size; i++)
    {
        if (usernames[i].username == choice)
        {
            file.open("users.txt", ios::out);
            accExist = true;
            for (int j = 0; j < size; j++)
            {
                file << usernames[j].username << ',';
                file << usernames[j].password << ',';
                file << usernames[j].userType << ',';
                if (i == j)
                {
                    file << 0 << '\n';
                    cout << usernames[j].username << " has been deleted." << endl;
                }
                else
                {
                    file << usernames[j].status << '\n';
                }
            }
            break;
        }
    }
    if (accExist == false)
    {
        cout << "there is no name similar with " << choice << ", please try again" << endl;
    }
    file.close();
}

void readUsername(vector<User> &usernames, fstream &file, int &size)
{
    file.open("users.txt", ios::in);
    if (!file)
    {
        cout << "\nError opening file...";
    }
    int j = 0; // Here j is used for usernames index number
    string temp;
    getline(file, temp, ',');
    while (!file.eof())
    {
        usernames.push_back(User());
        usernames[j].username = temp;
        getline(file, temp, ',');
        usernames[j].password = temp;
        getline(file, temp, ',');
        istringstream(temp) >> usernames[j].userType;
        getline(file, temp, '\n');
        istringstream(temp) >> usernames[j].status;
        getline(file, temp, ',');
        j++;
    }
    size = j;
    file.close();
}

void changePassword(vector<User> &usernames, ofstream &newFile, int index, int &size, string &newpassword)
{
    newFile.open("users.txt", ios::out);
    for (int i = 0; i < size; i++)
    {
        newFile << usernames[i].username << ',';
        if (i == index)
        {
            newFile << newpassword << ',';
            cout << usernames[i].username << " changed password. please key in your new password when you want to log in again" << endl;
        }
        else
        {
            newFile << usernames[i].password << ',';
        }
        newFile << usernames[i].userType << ',';
        newFile << usernames[i].status << '\n';
    }

    newFile.close();
}

void checkPassword(vector<User> &usernames, ofstream &newFile, int index, int &size, string &newpassword)
{
    bool firstletter = false;
    bool digit = false;
    bool capital = false;
    cout << "enter your new password (must start with letter, must contain a digit and a capital letter)" << endl;
    cin >> newpassword;
    if (isalpha(newpassword[0]))
    {
        firstletter = true;
    }
    for (int i = 0; i < newpassword.length(); i++)
    {
        if (isdigit(newpassword[i]))
        {
            digit = true;
        }
        else if (isupper(newpassword[i]))
        {
            capital = true;
        }
    }
    if (firstletter == true && digit == true && capital == true)
    {
        cout << "password accepted" << endl;
        changePassword(usernames, newFile, index, size, newpassword);
    }
    else
    {
        cout << "password invalid, must start with letter, must contain a digit and a capital letter " << endl;
    }
}

void checkUser(vector<User> &usernames, ofstream &newFile, int &size, string &newpassword, string &newusername, string &newusertype)
{
    bool passwordcheck;
    cout << "please insert a username for the user" << endl;
    cin >> newusername;
    cout << "please insert a password for the user" << endl;
    cin >> newpassword;
    cout << "is the user admin or user? (type 'admin' or 'user')" << endl;
    cin >> newusertype;
    bool sameUserIndex = checkUserSame(newusername, usernames, size);
    if (sameUserIndex == true)
    {
        checkPass(usernames, newFile, size, newpassword, newusername, newusertype);
    }
    else
    {
        cout << "there is already a user named : " << newusername << endl;
        cout << "please try again" << endl;
    }
}

void checkPass(vector<User> &usernames, ofstream &newFile, int &size, string &newpassword, string &newusername, string &newusertype)
{
    bool firstletter = false;
    bool digit = false;
    bool capital = false;
    if (isalpha(newpassword[0]))
    {
        firstletter = true;
    }
    for (int i = 0; i < newpassword.length(); i++)
    {
        if (isdigit(newpassword[i]))
        {
            digit = true;
        }
        else if (isupper(newpassword[i]))
        {
            capital = true;
        }
    }
    if (firstletter == true && digit == true && capital == true)
    {
        checkUserType(usernames, newFile, size, newpassword, newusername, newusertype);
    }
    else
    {
        cout << "password invalid, must start with letter, must contain a digit and a capital letter " << endl;
    }
}

void checkUserType(vector<User> &usernames, ofstream &newFile, int &size, string &newpassword, string &newusername, string &newusertype)
{
    if (newusertype == "admin" || newusertype == "user")
    {
        makeUser(usernames, newFile, size, newpassword, newusername, newusertype);
    }
    else
    {
        cout << "wrong input of usertype, please put in only 'admin' or 'user'" << endl;
    }
}

bool checkUserSame(string username, vector<User> &usernames, int size)
{
    for (int i = 0; i < size; i++)
        if (usernames[i].username == username)
        {
            return false; //if there is same username as the name
        }
    return true; //if no
}

void makeUser(vector<User> &usernames, ofstream &newFile, int &size, string &newpassword, string &newusername, string &newusertype)
{
    newFile.open("users.txt", ios::app);
    newFile << newusername << "," << newpassword << ",";
    if (newusertype == "admin")
    {
        newFile << 1 << ",";
    }
    else
    {
        newFile << 0 << ",";
    }
    newFile << 1 << endl; // since createuser will always be active initially
    newFile.close();
}