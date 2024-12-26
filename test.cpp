#include <iostream>
#include <vector>
#include <string> 
#include <fstream> 
#include <iomanip>

using namespace std; 

void enterArray (int arr[], int n, string name_in);
void printString (int arr[], int n, string &lastLine);
void testFirst (int arr[], int n, string &lastLine);
void writeFile_func (string lastLine, string name_file);

void enterArray (int arr[], int n, string name_in)
{
    cout << "Enter the value of " << name_in << ": "; 

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; 
    }
}

void writeFile_func (string lastLine, string name_file)
{
    cout << lastLine; 
    ofstream write_point(name_file);
    write_point << lastLine; 
    write_point.close(); 
}

void printString (int arr[], int n, string &lastLine)
{
    for (int i = 2; i < n; i++)
    {
        lastLine += to_string(arr[i]);
    }
}

void testFirst (int arr[], int n, string &lastLine, string name_file)
{
    switch (arr[0])
    {
        case 0: 
            lastLine = "+1";
            printString (arr, n, lastLine);
            writeFile_func (lastLine, name_file);
            break;
        case 1: 
            lastLine = "+84";
            printString (arr, n, lastLine);
            writeFile_func (lastLine, name_file);
            break;
    }
}


int main()
{    
    int arr15[11];

    // Nhập giá trị của mảng arr15
    enterArray (arr15, 11, "arr15");
    cout << "arr15 = ";
    for (int i = 0; i < 11; i++)
    {
        cout << arr15[i]; 
    }
    cout << endl; 

    string lastLine;
    string write_sdt;
    testFirst (arr15, 11, lastLine, "sdt.txt");
    cout << endl <<"----------------------------------" << endl;
}


