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
    vector<int> arr1(8, 0); 
    vector<int> arr2 = {2, 3, 1, 4, 7, 9};
    arr2[4] = 5; 
    for (int i = 0; i < 5; i++)
    {
        int temp = 0; 
        int min = arr2[i]; 
        int position = i; 
        for (int j = i + 1; j < arr2.size(); j++)
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

    for (int i = arr1.size(); i > 1; i--)
    {
        arr1[i] = arr2[i - 2]; 
    }
    arr1.push_back(6); // Thêm 1 phần tử vào cuối mảng arr1
    arr1.push_back(7); // Thêm 1 phần tử vào cuối mảng arr1
    arr1.erase(arr1.begin() + 3); // Xoá phần tử ở vị trí thứ 4 (arr1[3])
    arr1.resize(20); // Thay đổi kích thước của mảng arr1 thành 20 phần tử, chỗ nào không có mặc định là 0
    arr1.insert(arr1.begin() + 5, 6, 11); // Thêm 6 phần tử có giá trị là 11 bắt đầu từ vị trí thứ 6 (arr1[5]) 
    for (int i = 0; i < arr1.size(); i++)
    {
        cout << arr1[i] << " "; 
    }
}