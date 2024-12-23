#include <iostream>
#include <vector>
#include <string> 
#include <fstream> 
#include <iomanip>

using namespace std; 

int main()
{
    int arr2[6] = {2, 3, 1, 4, 7, 9};
    int e;
    cout << "Enter the number of elements of arr9: "; 
    cin >> e; 
    int arr9[e]; 
    cout << "Enter the value of arr9: "; 
    for (int i = 0; i < e; i++)
    {
        cin >> arr9[i]; 
    } 

    int length_2 = sizeof(arr2) / sizeof(arr2[0]); 
    int length_9 = sizeof(arr9) / sizeof(arr9[0]); 
    int max_length = length_2 > length_9 ? length_2 : length_9; 
    int arr11[2][max_length]; 
    
    for (int i = max_length - 1; i > max_length - length_2; i--)
    {
        if (i > max_length - length_2 - 1)
        { 
            arr11[0][i] = arr2[max_length - length_2]
        }
    }

    cout << "arr11 = " << endl; 
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < max_length; j++)
        {
            cout << setw(4) << arr10[i][j] << " "; 
        }
        cout << endl; 
    }
    cout <<  "----------------------------------" << endl; 

}