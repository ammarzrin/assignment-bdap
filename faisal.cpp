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

void readusername(vector<User>&, fstream&, int&);
void changepassword(vector<User>&, ofstream&, int, int&);
int checkusername(string, vector<User>&);
void deleteaccount(vector<User>&, ofstream&, int, int&);

int main()
{
    fstream usernamefile;
    ofstream newFile;
    string username;
    int size;
    
    int index;

    vector<User> usernames; // vector to put in all users

    size = usernames.size();

    readusername(usernames, usernamefile, size); // to read the name vaues and put into the array
    
    for (int i = 0 ; i < size; i++ )
    {
        cout << usernames[i].username << ','; 
        cout << usernames[i].password << ',';
        cout << usernames[i].userType << ',';
        cout << usernames[i].status   << '\n';

    }
    
    cout << "\nEnter username: ";
    cin >> username;

    index = checkusername(username, usernames);          // use this function to get the index of which user that wants to change password

    changepassword(usernames, newFile, index, size);     // use this function to create a newfile

    for (int i = 0 ; i < size; i++ )
    {
        cout << usernames[i].username << ','; 
        cout << usernames[i].password << ',';
        cout << usernames[i].userType << ',';
        cout << usernames[i].status   << '\n';

    }
}


void readusername(vector<User>& usernames, fstream &file, int& size)
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
    
    while (!file.eof())
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
    j = size;
    file.close();
}


void changepassword(vector<User>& usernames, ofstream& newFile, int index, int& size)
{
    newFile.open("newFile.txt", ios::out);
    string newpassword;

    cout << "key in your new password" <<endl;
    cin >> newpassword;
    
    size = usernames.size();

    for (int i = 0 ; i < size; i++ )
    {
        newFile << usernames[i].username << ','; 

        if ( i == index)
        {
            newFile << newpassword << ',';
        }
        else
        {
            newFile << usernames[i].password << ','; 
        }

        newFile << usernames[i].userType << ',';
        newFile << usernames[i].status   << '\n';
    }
}


//you can use this to check the index on where to change the password
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
                cout << i << endl;
                return i;
            }
        }
    return -1;
}
void deleteaccount(vector<User>& usernames, ofstream& newFile, int index, int& size)
{
    newFile.open("newFile.txt", ios::out);

    size = usernames.size();

    for (int i = 0 ; i < size; i++ )
    {
        newFile << usernames[i].username << ','; 
        newFile << usernames[i].password << ','; 
        newFile << usernames[i].userType << ',';
        
        if ( i == index)
        {
            newFile << 0 << '\n';
            cout << usernames[i].username << " has been deleted." << endl;
        }
        else
        {
            newFile << usernames[i].status   << '\n';
        }

    }
}