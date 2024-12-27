#include <iostream> 

using namespace std; 

int main ()
{
    int n, m; 
    int perimeter = 0; 
    cout << "Nhap so hang va so cot: "; 
    cin >> n >> m; 
    int arr[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 1)
            {
                perimeter += 4; 
                
                if (i > 0 && arr[i - 1][j] == 1)
                {
                    perimeter -= 2; 
                }

                if (j > 0 && arr[i][j - 1] == 1)
                {
                    perimeter -= 2; 
                }
            }
        }
    }
    cout << "perimeter = " << perimeter; 
}