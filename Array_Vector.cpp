#include <iostream>
#include <vector>
#include <string> 
#include <fstream> 
#include <iomanip>

using namespace std; 

void change_func (vector<int> vector_2, int arr[], int n)
{
    cout << "Enter the value of arr_func: "; 
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector_2.push_back(2);
    vector_2.push_back(9);
    cout << "vector_func = ";
    for (int i = 0; i < vector_2.size(); i++)
    {
        cout << vector_2[i] << " ";
    }

    cout << endl; 
    cout << "arr_func = ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " "; 
    }
}

int main()
{    
    vector<int> vector_1 = {2, 3, 5, 6, 7, 8}; 
    int n; 
    cout << "Enter the number of elements of array: "; 
    cin >> n; 

    cout << "Enter the value of array: "; 
    int array[n]; 
    for (int i = 0; i < n; i++)
    {
        cin >> array[i]; 
    }
    
    change_func (vector_1, array, n);
    cout << endl;
    cout << "vector_1_main = "; 
    for (int i = 0; i < vector_1.size(); i++)
    {
        cout << vector_1[i] << " "; 
    }

    cout << endl; 
    cout << "array_main = "; 
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
}


