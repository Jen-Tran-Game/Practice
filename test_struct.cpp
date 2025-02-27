#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "json.hpp"

using namespace std; 
using ordered_json = nlohmann::ordered_json;
struct Person
{
    string name;
    int age; 
    float height; 
    string school; 
    string username;
    string password;
};

int main ()
{
    string inputName; 
    ordered_json outData; 
    ifstream inFile ("test_struct.json");
    inFile >> outData;
    inFile.close();

    cout << outData[2]["height"] << endl;
    cout << outData[0]["school"] << endl;

    cout << "Enter name: ";
    cin >> inputName;

    for (const auto& account : outData)
    {
        if (account["name"].get<string>() == inputName)
        {
            cout << "Name: " << account["name"] << endl; 
            cout << "Age: " << account["age"] << endl; 
            cout << "Height: " << account["height"] << endl;
            cout << "School: " << account["school"] << endl;
            cout << "Username: " << account["username"] << endl; 
            cout << "Password: " << account["password"] << endl; 
            return 0; 
        }
    }
    cout << "User not found !" << endl; 
    // vector<Person> users; 
    // for (const auto& account : outData)
    // {
    //     Person user;
    //     user.name = account["name"].get<string>();
    //     user.age = account["age"].get<int>();
    //     user.height = account["height"].get<float>(); 
    //     user.school = account["school"].get<string>();
    //     user.username = account["username"].get<string>(); 
    //     user.password = account["password"].get<string>();
    //     users.push_back(user);

    // }

    // for (const auto& user : users)
    // {
    //     cout << "Name: " << user.name << endl; 
    //     cout << "Age: " << user.age << endl; 
    //     cout << "Height: " << user.height << endl; 
    //     cout << "School: " << user.school << endl; 
    //     cout << "Username: " << user.username << endl; 
    //     cout << "Password: " << user.password << endl;
    //     cout << "----------------------------" << endl; 
    // }

    return 0;
}