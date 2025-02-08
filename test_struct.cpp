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
    ordered_json outData; 
    ifstream inFile ("test_struct.json");
    inFile >> outData;
    inFile.close();

    vector<Person> users; 
    for (const auto& item : outData)
    {
        Person user;
        user.name = item["name"].get<string>();
        user.age = item["age"].get<int>();
        user.height = item["height"].get<float>(); 
        user.school = item["school"].get<string>();
        user.username = item["username"].get<string>(); 
        user.password = item["password"].get<string>();
        users.push_back(user);

    }
    for (const auto& user : users)
    {
        cout << "Name: " << user.name << endl; 
        cout << "Age: " << user.age << endl; 
        cout << "Height: " << user.height << endl; 
        cout << "School: " << user.school << endl; 
        cout << "Username: " << user.username << endl; 
        cout << "Password: " << user.password << endl;
        cout << "----------------------------" << endl; 
    }

    return 0;
}