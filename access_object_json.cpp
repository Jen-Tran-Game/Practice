#include <iostream> 
#include "json.hpp"

using namespace std; 
using json = nlohmann::json; 

int main()
{
    json j; 
    j["name"] = "Jen"; 
    j["age"] = 21; 
    j["school"] = "HCMUTE";

    string name = j["name"]; 
    int age = j["age"]; 
    string school = j["school"]; 

    cout << "Name: " << name << endl; 
    cout << "Age: " << age << endl; 
    cout << "School: " << school << endl; 
    return 0; 
}      