#include <iostream>
#include "json.hpp"

using namespace std; 
using json = nlohmann::json; 

int main()
{
    json j = json::array({"C++", "Python", "JavaScript"});

    string firstLang = j[0]; 
    string secondLang = j[1]; 
    string thirdLang = j[2];

    cout << "First Language: " << firstLang << endl; 
    cout << "Second Language: " << secondLang << endl; 
    cout << "Third Language: " << thirdLang << endl; 
    
    return 0; 
}