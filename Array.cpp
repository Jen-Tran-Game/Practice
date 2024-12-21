#include <iostream>
#include <vector>
#include <fstream> // Thư viện để thao tác với file 
#include <string> // Thư viện để làm việc với chuỗi
#include <iomanip>

using namespace std; 

int main ()
{
    int arr1[8] = {};
    int arr2[6] = {2, 3, 1, 4, 7, 9};
    int arr5[2][6];
    vector<int> arr3 = {1, 6, 9, 5, 4, 3, 8};
    vector<int> arr4; 
    string Text_1;
    string Text_2; 
    string Array;
    int n, value, m, d; 

    // Xuất giá trị của mảng arr1
    cout << "arr1 = ";
    for (int i = 0; i < 8; i++)
    {
        cout << arr1[i] << " "; 
    }
    cout << endl << "----------------------------------" << endl; 
    
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

    // Xuất giá trị của mảng arr2
    cout << "arr2 = ";
    for (int i = 0; i < 6; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl << "----------------------------------" << endl;  

    arr3.resize(10); // Thay đổi kích thước của mảng arr3 thành 10 phần tử, chỗ nào không có mặc định là 0
    arr3.push_back(4); // Thêm 1 phần tử vào cuối mảng arr3
    arr3.push_back(2); // Thêm 1 phần tử vào cuối mảng arr3
    arr3.insert(arr3.begin() + 4, 5, 56); // Thêm 5 phần tử có giá trị là 56 bắt đầu từ vị trí thứ 5 (arr3[4])
    arr3.erase(arr3.begin() + 4); // Xoá phần tử vị trí thứ 3 (arr3[4])
    arr3.pop_back(); // Xoá phần tử ở cuối mảng

    // Xuất giá trị của vector arr3
    cout << "arr3 = ";
    for (int i = 0; i < arr3.size(); i++)
    {
        cout << arr3[i] << " ";
    }
    cout << endl; 
    cout << "Size of arr3: " << arr3.size() << endl; // Xuất ra số phần tử trong mảng arr3
    cout << "Sizeof of arr3: " << sizeof(arr3) << endl; // Xuất ra kích thước của mảng arr3 tính theo byte
    cout << "----------------------------------" << endl; 

    // Nhập nội dung vào file Test_1.txt
    ofstream writeFile_1("Test_1.txt"); 
    writeFile_1 << "Hello! I'm Jen_Tran"; 
    writeFile_1.close(); 

    // Xuất ra nội dung trong file Test_1.txt
    cout << "Content of Test_1.txt: ";
    ifstream readFile_1("Test_1.txt"); 
    while(getline(readFile_1, Text_1))
    {
        cout << Text_1; 
    }
    readFile_1.close(); 
    cout << endl << "----------------------------------" << endl; 

    // Nhập nội dung vào file Test_2.txt
    fstream writeFile_2("Test_2.txt", fstream::out); // out bao gồm luôn cả trunc
    writeFile_2 << "Hi! I'm Jen._.Tran"; 
    writeFile_2.close(); 

    // Xuất ra nội dung trong file Test_2.txt    
    cout << "Content of Test_2.txt: ";
    fstream readFile_2("Test_2.txt", fstream::in); 
    getline(readFile_2, Text_2); 
    cout << Text_2; 
    readFile_2.close();
    cout << endl << "----------------------------------" << endl; 
    
    // Nhập số lượng phần tử và giá trị của mảng từ bàn phím, sau đó ghi vào file
    cout << "Enter the number of elements for the arr4: ";
    cin >> n; 
    cout << "Enter the value of the arr4: ";
    fstream writeFile_array("Array.txt", fstream::out); 
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        writeFile_array << value << " "; 
    }
    writeFile_array.close();

    // Đọc giá trị từ file và lưu vào arr4
    fstream readFile_array("Array.txt", fstream::in);
    while (readFile_array >> value)
    {
        arr4.push_back(value); 
    }
    readFile_array.close(); 

    // Xuất giá trị của vector arr4
    cout << "arr4 = ";
    for (int i = 0; i < arr4.size(); i++)
    {
        cout << arr4[i] << " ";
    }
    cout << endl << "----------------------------------" << endl; 

    // Gán mảng arr2 làm dòng đầu tiên cho mảng arr5
    for (int i = 0; i < 6; i++)
    {
        arr5[0][i] = arr2[i]; 
    } 

    // Gán mảng arr4 làm dòng thứ 2 cho mảng arr5
    for (int i = 0; i < 6; i++)
    {
        arr5[1][i] = arr4[i];
    }

    // Xuất giá trị của mảng arr5
    cout << "arr5 = ";
    cout << endl;  
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cout << setw(4) << arr5[i][j] << " ";
        }
        cout << endl; 
    }
    cout << "----------------------------------" << endl; 

    // Nhập số phần tử và giá trị mảng cho arr6
    cout << "Enter the number of elements of arr6: ";
    cin >> m; 
    int arr6[m];
    cout << "Enter the value of arr6: ";
    for (int i = 0; i < m; i++)
    {
        cin >> arr6[i] ; 
    }

    // Xuất giá trị của mảng arr6
    cout << "arr6 = "; 
    for (int i = 0; i < m; i++)
    {
        cout << arr6[i] << " "; 
    }
    cout << endl; 

    // Xoá một phần tử trong arr6
    cout << "Enter the position you want to delete in arr6: "; 
    cin >> d; 
    for (int i = d; i < m - 1; i++)
    {
        arr6[i] = arr6[i + 1]; 
    }
    m--; 

    // Xuất giá trị của mảng arr6 sau khi xoá 1 phần tử 
    cout << "arr6 = "; 
    for (int i = 0; i < m; i++)
    {
        cout << arr6[i] << " ";
    }
    cout << endl << "----------------------------------" << endl; 







    









}