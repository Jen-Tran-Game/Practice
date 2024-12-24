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
    cout << "Enter the number of elements: "; 
    cin >> e; 

    int max_length = e > 6 ? e : 6; 
    int arr11[max_length] = {}; // Tạo ra một mảng rỗng
    int arr12[max_length] = {}; // Tạo ra một mảng rỗng
    int arr13[e] = {};
    int arr14[2][max_length];

    
    for (int i = max_length - 6; i < max_length; i++)
    {
        arr11[i] = arr2[i - (max_length - 6)]; 
    }
   
    cout << "Enter the value of elements of array10: "; 
    for (int i = 0; i < e; i++)
    {
        cin >> arr13[i]; 
    }
    for (int i = max_length - e; i < max_length; i++)
    {
        arr12[i] = arr13[i - (max_length - e)]; 
    }

    for (int i = 0; i < max_length; i++)
    {
        arr14[0][i] = arr11[i];
    }

    for (int i = 0; i < max_length; i++)
    {
        arr14[1][i] = arr12[i]; 
    }

    cout << "arr14 =  "; 
    cout << endl; 
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < max_length; j++)
        {
            cout << setw(4) << arr14[i][j] << " ";
        }
        cout << endl; 
    }

}


