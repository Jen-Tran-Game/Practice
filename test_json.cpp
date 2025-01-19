#include <iostream> 
#include "json.hpp"
#include <fstream> 

using namespace std; 
using json = nlohmann::json; 

int main()
{
    int targetIndex; 
    cout << "Position of array you want to know: "; 
    cin >> targetIndex; 

    json outData; 
    fstream outFile ("users.json", fstream::in); 
    getline (outFile, outData); 
    outFile.close(); 

    auto user = outData["users"][targetIndex]; 
    string username = user["Username"].get<string>(); 
    string password = user["Password"].get<string>(); 

    cout << "Username: " << username << endl; 
    cout << "Password: " << password << endl; 

    return 0; 
}