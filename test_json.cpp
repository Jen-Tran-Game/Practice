#include <iostream> 
#include <fstream> 
#include <iomanip>
#include "json.hpp"
#include "sha256.h"

using namespace std; 
using ordered_json = nlohmann::ordered_json; // Để giữ thứ tự trong lúc đọc và ghi file 

int main()
{   
    // Read and Print username and password you want 
    // int targetIndex; 
    // cout << "Position of array you want to know: "; 
    // cin >> targetIndex; 

    // json outData; 
    // ifstream inFile("users.json"); 
    // inFile >> outData; 
    // inFile.close(); 

    // auto user = outData["users"][targetIndex]; 
    // string username = user["Username"].get<string>(); 
    // string password = user["Password"].get<string>(); 

    // cout << "Username: " << username << endl; 
    // cout << "Password: " << password << endl; 

    // Add new User to json file use C++ code
    string newUsername, newPassword; 
    cout << "Enter your new username: "; 
    cin >> newUsername;
    cout << "Enter your new password: "; 
    cin >> newPassword;  

    ordered_json outData; 
    ifstream inFile ("test_users.json"); 
    inFile >> outData; 
    inFile.close(); 

    ordered_json newUser; 
    newUser["Username"] = newUsername; 
    newUser["Password"] = hashedPassword; 

    outData["users"].push_back(newUser); 

    ofstream outFile ("test_users.json"); 
    outFile << outData.dump(4); 
    outFile.close(); 
    return 0; 
}