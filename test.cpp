#include <iostream> 
#include <string> 
#include <fstream>
#include <iomanip> 

using namespace std; 

struct User {
    string username; 
    string password; 
};

int main ()
{
    vector<User> users; 
    User user; 
    string inputUsername, inputPassword, storedPassword;  
    int mode;
    cout << "Press 0: Sign up" << endl << "Press 1: Log in " << endl; 
    cin >> mode;
    fstream create_file ("Users.json", fstream::out);
    create_file.close(); 
    if (mode == 0)
    {
        cout << "Create username: "; 
        cin >> inputUsername;
        for (int i = 0; i < users.size(); i++)
        {
            if (inputUsername == users[i].username)
            {
                cout << "Username is already taken. Please choose another username" << endl; 
                
            }
        }

        fstream write_usr_pw ("Users.txt", fstream::app);
        write_usr_pw << "Username: " << username; 
        write_usr_pw.close(); 

    }

}