/* Đề bài: 
    1.(done) Tạo một mảng rỗng arr1 kích thước 8, 
    một mảng arr2 với 6 phần tử {2, 3, 1, 4, 7, 9}
    2.(done) Thay đổi giá trị phần tử thứ 5 của mảng arr2 từ 7 thành 5
    3.(done) Sắp xếp arr2 the thứ tự tăng dần và gán vào arr1 từ dưới lên
    VD: output arr1 = {0, 0, 1, 2, 3, 4, 5, 9}
    4.(done) Mảng trong C++ có cố định không, trường hợp không biết trước có bao nhiêu phần tử 
    thì có các phương pháp nào để mở rộng mảng ?
    5.(done) Lấy được kích thước của mảng arr1 ra L1
    6. Tạo file txt nhập nội dung mảng từ bàn phím và lưu vào file txt, sau đó load lại chương 
    trình với điều kiện đọc file nếu có file thì lấy giá trị từ file nếu không có thì nhập lại 
    xong thoát 
    7. Khi chạy chương trình có file và đọc được file thì gán chuỗi số đó vào mảng 1 chiều, kết
    hợp với mảng 1 chiều trước đó tạo thành vector 2 chiều 
    8. Tạo 1 mảng hoặc vector kích thước 12 phần tử nhập vào số điện thoại **********, xét ký tự
    đầu nếu là 0 thì +1 (đầu số Mỹ) nếu là 1 thì đầu số Việt Nam +84 sau đó chuyển mảng thành 
    chuỗi số điện thoại bắt đầu từ phần tử 2 đồng thời thay 0 thành +84 hoặc +1. Sau đó lưu vào
    file sdt.txt
    9. Sau khi tạo file thành công thì tách nhữn đoạn code đó ra thành các hàm xử lý 
    VD: -Hàm nhập phần tử
        -Hàm kiểm tra phần tử đầu
        -Hàm chuyển mảng thành string và replace ký tự đầu thành +84 hoặc +1 sử dụng switch case
        -Hàm lưu và đọc file 
    10. Sau đó tạo 1 mảng và 1 vector
    11. Tạo chương trình con với 2 tham số là mảng và vector 
    12. bển trong thay đổi giá trị phần tử mảng truyền vào, thay đổi giá trị vector in ra mảng 
    và vector
    13. Sau khi ra khỏi mảng hàm in lại mảng và vector sau đó nhận xét
 */
#include <iostream>
#include <vector>
#include <fstream> // Thư viện để thao tác với file 
#include <string> // Thư viện để làm việc với chuỗi

using namespace std; 

int main ()
{
    int arr1[8] = {};
    int arr2[6] = {2, 3, 1, 4, 7, 9};
    vector<int> arr3 = {1, 6, 9, 5, 4, 3, 8};
    vector<int> arr4; 
    string filename = "Array.txt";
    ifstream infile (filename);  

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

    arr3.resize(10); // Thay đổi kích thước của mảng arr3 thành 10 phần tử, chỗ nào không có mặc định là 0
    arr3.push_back(4); // Thêm 1 phần tử vào cuối mảng arr3
    arr3.push_back(2); // Thêm 1 phần tử vào cuối mảng arr3
    arr3.insert(arr3.begin() + 4, 5, 56); // Thêm 5 phần tử có giá trị là 56 bắt đầu từ vị trí thứ 5 (arr3[4])
    arr3.erase(arr3.begin() + 4); // Xoá phần tử vị trí thứ 3 (arr3[4])
    arr3.pop_back(); // Xoá phần tử ở cuối mảng

    if (!infile.is_open())
    {
        int n; 
        cin >> n; 
        for (int i = 0; i < n; i++)
        {
            cin >> arr4[i]; 
        }
        ofstream outfile(filename); 
        for (int i = 0; i < arr4.size(); i++)
        {
            outfile << arr4[i] << " "; 
        }
        outfile.close(); 
    }
    else 
    {
        int value; 
        while (infile >> value)
        {
            arr4.push_back(value); 
        }
    }
    infile.close(); 

    // for (int i = 0; i < 8; i++)
    // {
    //     cout << arr1[i] << " "; 
    // }
    // cout << endl; 
    // for (int i = 0; i < 6; i++)
    // {
    //     cout << arr2[i] << " ";
    // }
    // cout << endl; 
    // for (int i = 0; i < arr3.size(); i++)
    // {
    //     cout << arr3[i] << " ";
    // }
    // cout << endl; 
    // cout << arr3.size() << endl; // Xuất ra số phần tử trong mảng arr3
    // cout << sizeof(arr3); // Xuất ra kích thước của mảng arr3 tính theo byte

    for (int i = 0; i < arr4.size(); i++)
    {
        cout << arr4[i] << " "; 
    }
    cout << endl; 
}