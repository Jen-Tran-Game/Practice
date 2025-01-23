#include <iostream> 
#include <fstream> 
#include <iomanip>
#include <sstream>
#include "json.hpp"
#include "sha.h"

using namespace std; 
using ordered_json = nlohmann::ordered_json; // Để giữ thứ tự trong lúc đọc và ghi file 

std::string sha256(const std::string &data)
{
    unsigned char hash[SHA256_DIGEST_LENGTH];

    SHA256_CTX sha256; 
    SHA256_Init(&sha256); 
    SHA256_Update(&sha256, data.c_str(), data.size()); 
    SHA256_Final(hash,&sha256);

    std::ostringstream hex_stream;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        hex_stream << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(hash[i]);
    }
    return hex_stream.str(); 
}
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

    // Use SHA256 to hash the password
    std::string hashedPassword = sha256(newPassword);

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