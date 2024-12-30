#include <iostream> 
#include <string> 
#include <fstream> 
#include <vector> 

using namespace std; 

void enterPassword_signup (string password);
void write_pw_func (string password);
void enterPassword_login (string &inputPassword); 
void read_pw_func (string storedPassword);

void enterPassword_signup (string password)
{
    cout << "Enter your new password: ";
    cin >> password;
    write_pw_func (password);
}

void write_pw_func (string password)
{
    fstream write_pw("password.txt", fstream::out);
    write_pw << password; 
    write_pw.close();
}

void enterPassword_login (string &inputPassword)
{
    cout << "Enter your password you set: ";
    cin >> inputPassword; 
}

int main ()
{     
    // Lựa chọn đăng nhập hoặc đăng ký 
    int mode; 
    string password; 
    string inputPassword; 
    cout << "Press 0: sign up" << endl; 
    cout << "Press 1: log in" << endl; 
    cout << "Your option: "; 
    cin >> mode; 
    if (mode == 0)
    {
        enterPassword_signup (password);
        cout << "Set password successfully";
    }
    else
    {
        enterPassword_login (inputPassword); 

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

    
    

     
     
}