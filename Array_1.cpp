/* Đề bài: 
    1. Tạo một mảng rỗng arr1 kích thước 8, 
    một mảng arr2 với 6 phần tử {2, 3, 1, 4, 7, 9}
    2. Thay đổi giá trị phần tử thứ 5 của mảng arr2 từ 7 thành 5
    3. Sắp xếp arr2 the thứ tự tăng dần và gán vào arr1 từ dưới lên
    VD: output arr1 = {0, 0, 1, 2, 3, 4, 5, 9}
    4. Mảng trong C++ có cố định không, trường hợp không biết trước có bao nhiêu phần tử 
    thì có các phương pháp nào để mở rộng mảng ?
    5. Lấy được kích thước của mảng arr1 ra L1
 */
#include <iostream>
#include <vector>

using namespace std; 

int main ()
{
    int arr1[8] = {};
    int arr2[6] = {2, 3, 1, 4, 7, 9};
    vector<int> arr3 = {1, 6, 9, 5, 4, 3, 8}; 
    arr2[4] = 5; 
    for (int i = 0; i < 5; i++)
    {
        int temp = 0; 
        int min = arr2[i]; 
        int position = i; 
        for (int j = i + 1; j < 6; j++)
        {
            int temp = 0; 
            if (arr2[j] < min)
            {
                min = arr2[j]; 
                position = j; 
            }
        }
        temp = arr2[i]; 
        arr2[i] = arr2[position]; 
        arr2[position] = temp; 
    }

    for (int i = 7; i > 1; i--)
    {
        arr1[i] = arr2[i - 2]; 
    }

    arr3.resize(10); 
    arr3.push_back(4); 
    arr3.push_back(2);
    arr3.insert(arr3.begin() + 4, 5, 56); 
    arr3.erase(arr3.begin() + 4); 
    arr3.pop_back();

    for (int i = 0; i < 8; i++)
    {
        cout << arr1[i] << " "; 
    }
    cout << endl; 
    for (int i = 0; i < 6; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl; 
    for (int i = 0; i < arr3.size(); i++)
    {
        cout << arr3[i] << " ";
    }
    cout << endl; 
    cout << arr3.size() << endl; //
    cout << sizeof(arr3); 
}