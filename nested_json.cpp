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
    j["skill"] = json::array({"C++", "Python", "JavaScript"}); 
    j["address"] = {
        {"city", "Ho Chi Minh City"}, 
        {"country", "Vietnam"}
    };

    cout << j.dump(4) << endl; 
    return 0; 
}