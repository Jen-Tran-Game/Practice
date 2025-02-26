#include <iostream>
#include <vector>
#include <fstream> // Thư viện để thao tác với file 
#include <string> // Thư viện để làm việc với chuỗi
#include <iomanip> // Thư viện của setw để căn thẳng hàng 

using namespace std; 

void enterArray (int arr[], int n, string name_in);
void printString (int arr[], int n, string &lastLine);
void testFirst (int arr[], int n, string &lastLine);
void writeFile_func (string lastLine, string name_file);
void printArray (int arr[], int n, string name_out);

void enterArray (int arr[], int n, string name_in)
{
    cout << "Enter the value of " << name_in << ": "; 

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; 
    }
}

void printArray (int arr[], int n, string name_out)
{
    cout << name_out;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl << "----------------------------------" << endl
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

int main ()
{
    int arr1[8] = {};
    int arr2[6] = {2, 3, 1, 4, 7, 9};

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

    // In giá trị của mảng arr1
    cout << "arr1 = ";
    for (int i = 0; i < 8; i++)
    {
        cout << arr1[i] << " "; 
    }
    cout << endl << "----------------------------------" << endl;

    // In giá trị của mảng arr2
    printArray (arr2, 6, "arr2 = ");

    vector<int> arr3 = {1, 6, 9, 5, 4, 3, 8};
    arr3.resize(10); // Thay đổi kích thước của mảng arr3 thành 10 phần tử, chỗ nào không có mặc định là 0
    arr3.push_back(4); // Thêm 1 phần tử vào cuối mảng arr3
    arr3.push_back(2); // Thêm 1 phần tử vào cuối mảng arr3
    arr3.insert(arr3.begin() + 4, 5, 56); // Thêm 5 phần tử có giá trị là 56 bắt đầu từ vị trí thứ 5 (arr3[4])
    arr3.erase(arr3.begin() + 4); // Xoá phần tử vị trí thứ 3 (arr3[4])
    arr3.pop_back(); // Xoá phần tử ở cuối mảng

    // In giá trị của vector arr3
    printArray (arr3, arr3.size(), "arr3 = ");
    cout << endl; 
    cout << "Size of arr3: " << arr3.size() << endl; // In ra số phần tử trong mảng arr3
    cout << "Sizeof of arr3: " << sizeof(arr3) << endl; // In ra kích thước của mảng arr3 tính theo byte
    cout << "----------------------------------" << endl; 

    // Nhập nội dung vào file Test_1.txt
    ofstream writeFile_1("Test_1.txt"); 
    writeFile_1 << "Hello! I'm Jen_Tran"; 
    writeFile_1.close(); 

    // In ra nội dung trong file Test_1.txt
    string Text_1;
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

    // In ra nội dung trong file Test_2.txt   
    string Text_2; 
    cout << "Content of Test_2.txt: ";
    fstream readFile_2("Test_2.txt", fstream::in); 
    getline(readFile_2, Text_2); 
    cout << Text_2; 
    readFile_2.close();
    cout << endl << "----------------------------------" << endl; 
    
    // Nhập số lượng phần tử và giá trị của mảng từ bàn phím, sau đó ghi vào file
    vector<int> arr4; 
    int n, value; 
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

    // In giá trị của vector arr4
    printArray (arr4, arr4.size(), "arr4 = ");

    // Gán mảng arr2 làm dòng đầu tiên cho mảng arr5
    int arr5[2][6];
    for (int i = 0; i < 6; i++)
    {
        arr5[0][i] = arr2[i]; 
    } 

    // Gán mảng arr4 làm dòng thứ 2 cho mảng arr5
    for (int i = 0; i < 6; i++)
    {
        arr5[1][i] = arr4[i];
    }

    // In giá trị của mảng arr5
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
    int m, position_6; 
    cout << "Enter the number of elements of arr6: ";
    cin >> m; 
    int arr6[m];
    enterArray (arr6, m, "arr6");

    // Xoá một phần tử trong arr6   
    cout << "Enter the position you want to delete in arr6: "; 
    cin >> position_6; 
    for (int i = position_6; i < m - 1; i++)
    {
        arr6[i] = arr6[i + 1]; 
    }
    m--; 

    // In giá trị của mảng arr6 sau khi xoá 1 phần tử 
    printArray (arr6, m, "arr6 = ");

    // Nhập số phần tử và giá trị cho mảng arr7
    int a; 
    cout << "Enter the number of elements of arr7: "; 
    cin >> a; 
    int arr7[a];
    enterArray (arr7, a, "arr7");
    
    // Nhập mảng chứa các vị trí cần xoá trong mảng arr7
    int b; 
    cout << "Enter number of position you want to delete: "; 
    cin >> b; 
    int positions_7[b]; 
    cout << "Enter array of position of arr7 you want to delete: ";
    for (int i = 0; i < b; i++)
    {
        cin >> positions_7[i];
    }

    // Xoá từng phần tử trong mảng arr7
    int numPosition_7 = sizeof(positions_7) / sizeof(positions_7[0]); // Số phần tử trong mảng positions_7
    for (int i = 0; i < numPosition_7; i++)
    {
        int pos_7 = positions_7[i] - i;

        // Di chuyển các phần tử để lấp khoảng trống
        for (int j = pos_7; j < a - 1; j++)
        {
            arr7[j] = arr7[j + 1]; 
        }
        a--; 
    }

    // In ra màn hình mảng arr7 sau khi đã xoá các phần tử
    printArray (arr7, a, "arr7 = ");

    // Nhập số phần tử và giá trị cho mảng arr8
    int c;
    cout << "Enter the number of elements of arr8: "; 
    cin >> c; 
    int arr8[c]; 
    enterArray (arr8, c, "arr8");

    // Nhập mảng chứa các vị trí cần xoá trong mảng arr8
    int d; 
    cout << "Enter number of position you want to delete: "; 
    cin >> d; 
    int positions_8[d]; 
    cout << "Enter array of position of arr8 you want to delete: ";
    for (int i = 0; i < d; i++)
    {
        cin >> positions_8[i];
    }

    // Sắp xếp mảng chứa các vị trí cần xoá trong mảng arr8 theo thứ tự tăng dần
    for (int i = 0; i < d - 1; i++)
    {
        int temp = 0; 
        int position = i; 
        int min = positions_8[i];
        for (int j = i + 1; j < d; j++)
        {
            int temp = 0; 
            if (positions_8[j] < min)
            {
                position = j; 
                min = positions_8[j]; 
            }

        }
        temp = positions_8[i]; 
        positions_8[i] = positions_8[position]; 
        positions_8[position] = temp; 
    }

    // In ra mảng chứa các vị trí cần xoá trong mảng arr8 theo thứ tự tăng dần
    cout << "positions_8 = "; 
    for (int i = 0; i < d; i++)
    {
        cout << positions_8[i] << " ";
    }

    // Xoá từng phần tử trong mảng arr8
    int numPosition_8 = sizeof(positions_8) / sizeof(positions_8[0]); 
    for (int i = 0; i < numPosition_8; i++)
    {
        int pos_8 = positions_8[i] - i; 
        for (int j = pos_8; j < c - 1; j++)
        {
            arr8[j] = arr8[j + 1]; 
        }
        c--;
    }
    cout << endl; 
    
    // In ra mảng arr8 sau khi xoá các phần tử
    printArray (arr8, c, "arr8 = ");

    // Nhập số phần tử và giá trị cho mảng arr9
    int e;
    cout << "Enter the number of elements of arr9: "; 
    cin >> e; 
    int arr9[e]; 
    enterArray (arr9, e, "arr9");

    // Chèn số 0 vào phía sau khi 2 mảng không bằng nhau 
    int length_2 = sizeof(arr2) / sizeof(arr2[0]); 
    int length_9 = sizeof(arr9) / sizeof(arr9[0]); 
    int max_length_10 = length_2 > length_9 ? length_2 : length_9; 
    int arr10[2][max_length_10]; 
    for (int i = 0; i < max_length_10; i++)
    {
        if (i < length_2)
        {
            arr10[0][i] = arr2[i];
        }
        else 
        {
            arr10[0][i] = 0; 
        }
    }

    for (int i = 0; i < max_length_10; i++)
    {
        if (i < length_9)
        {
            arr10[1][i] = arr9[i];
        }
        else
        {
            arr10[1][i] = 0; 
        }
    }

    // In ra màn hình mảng arr10
    cout << "arr10 = " << endl; 
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < max_length_10; j++)
        {
            cout << setw(4) << arr10[i][j] << " "; 
        }
        cout << endl; 
    }
    cout <<  "----------------------------------" << endl; 

    // Nhập số phần tử cho mảng arr13
    int f;
    cout << "Enter the number of elements: "; 
    cin >> f; 

    int max_length_14 = f > 6 ? f : 6; 
    int arr11[max_length_14] = {}; // Tạo ra một mảng rỗng
    int arr12[max_length_14] = {}; // Tạo ra một mảng rỗng
    int arr13[f] = {};
    int arr14[2][max_length_14];

    // Gán giá trị cho mảng arr11 theo arr2
    for (int i = max_length_14 - 6; i < max_length_14; i++)
    {
        arr11[i] = arr2[i - (max_length_14 - 6)]; 
    }
   
    // Nhập giá trị cho mảng arr13
    enterArray (arr13, f, "arr13");

    // Gán giá trị cho arr12 theo arr13
    for (int i = max_length_14 - f; i < max_length_14; i++)
    {
        arr12[i] = arr13[i - (max_length_14 - f)]; 
    }

    // Gán giá trị của mảng arr11 cho dòng 1 của mảng arr14
    for (int i = 0; i < max_length_14; i++)
    {
        arr14[0][i] = arr11[i];
    }

    // Gán giá trị của mảng arr12 cho dòng 2 của mảng arr14
    for (int i = 0; i < max_length_14; i++)
    {
        arr14[1][i] = arr12[i]; 
    }

    // In ra mảng 2 chiều arr14
    cout << "arr14 =  "; 
    cout << endl; 
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < max_length_14; j++)
        {
            cout << setw(4) << arr14[i][j] << " ";
        }
        cout << endl; 
    }
    cout <<  "----------------------------------" << endl;

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