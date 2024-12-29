#include <iostream> 
#include <string> 
#include <fstream> 
#include <vector> 

using namespace std; 

int main ()
{ 
    // Nhập password
    string password; 
    cout << "Enter your password: ";
    cin >> password;
    
    // Ghi password vào file txt
    fstream write_pw("password.txt", fstream::out);
    write_pw << password; 
    write_pw.close(); 

    // Nhập lại password
    string inputPassword; 
    cout << "Your password is: "; 
    cin >> inputPassword; 

    // Đọc password trong file txt
    string storedPassword;
    fstream read_pw("password.txt", fstream::in);
    getline (read_pw, storedPassword);
    read_pw.close();

    // Kiểm tra xem password nhập vào có giống với password được tạo không 
    if (inputPassword == storedPassword)
    {
        cout << "Login successfully";
    }
    else
    {
        cout << "Unauthorized";
        
    }    
}