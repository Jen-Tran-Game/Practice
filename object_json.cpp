#include <iostream>
#include "json.hpp"

using namespace std; 
using json = nlohmann::json; 

int main()
{
    json j; 
    j["name"] = "Jen_Tran"; 
    j["age"] = 21; 
    j["is_student"] = true; 

    cout << j.dump(4) << endl;

    return 0;  
}