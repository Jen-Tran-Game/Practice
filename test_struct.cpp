#include <iostream>
#include <string>

using namespace std; 

struct Person
{
    string name;
    int age; 
    float height; 
};

int main ()
{
    Person person1; 
    person1.name = "Jen_Tran"; 
    person1.age = 21; 
    person1.height = 150; 

    cout << "Name: " << person1.name << endl; 
    cout << "Age: " << person1.age << endl; 
    cout << "Height: " << person1.height << endl;

    return 0; 
}