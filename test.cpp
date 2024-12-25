#include <iostream>
#include <vector>
#include <string> 
#include <fstream> 
#include <iomanip>

using namespace std; 

int main()
{
    int arr15[11];
    cout << "Enter the value of arr15: ";
    for (int i = 0; i < 11; i++)
    {
        cin >> arr15[i];
    }

    cout << "arr15 = ";
    for (int i = 0; i < 11; i++)
    {
        cout << arr15[i]; 
    }
    cout << endl; 

    if (arr15[0] == 0)
    {
        string lastLine = "+1"; 
        for (int i = 2; i < 11; i++)
        {
            lastLine += to_string(arr15[i]);
        }
        cout << lastLine; 
        ofstream write_sdt("sdt.txt");
        write_sdt << lastLine; 
        write_sdt.close();
    }
    else
    {
        string lastLine = "+84";
        for (int i = 2; i < 11; i++)
        {
            lastLine += to_string(arr15[i]);
        }
        cout << lastLine;
        ofstream write_sdt("sdt.txt"); 
        write_sdt << lastLine; 
        write_sdt.close();
    }
    cout << endl << "----------------------------------" << endl;
}


