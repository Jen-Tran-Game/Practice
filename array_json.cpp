#include <iostream>
#include "json.hpp"

using namespace std; 
using json = nlohmann::json;

int main()
{
    json j = json::array({"C++", "Python", "JavaScript"}); 

    cout << j.dump(4) << endl; 
    return 0; 
}