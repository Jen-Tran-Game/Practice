#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Khai báo cấu trúc User
struct User {
    string username;
    string password;
};

int main() {
    const int MAX_USERS = 100; // Giới hạn số lượng người dùng
    User users[MAX_USERS];
    int userCount = 0;
    int choice;
    bool usernameTaken;
    bool loggedIn;
    string inputUsername, inputPassword, storedPassword;
    char moreUsers = 'n';

    // Đọc dữ liệu từ file JSON nếu tồn tại
    fstream inFile("users.json", fstream::out);
    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            // Duyệt qua từng ký tự trong chuỗi để tìm username và password
            size_t i = 0;
            while (i < line.size()) {
                if (line[i] == '"' && i + 11 < line.size() && line[i + 1] == 'u' && line[i + 2] == 's' && line[i + 3] == 'e' && line[i + 4] == 'r' && line[i + 5] == 'n' && line[i + 6] == 'a' && line[i + 7] == 'm' && line[i + 8] == 'e' && line[i + 9] == '"' && line[i + 10] == ':') {
                    i += 13; 
                    // Bỏ qua phần "username": "
                    string username = "";
                    while (i < line.size() && line[i] != '"') {
                        username += line[i];
                        ++i;
                    }
                    users[userCount].username = username;
                }
                if (line[i] == '"' && i + 11 < line.size() && line[i + 1] == 'p' && line[i + 2] == 'a' && line[i + 3] == 's' && line[i + 4] == 's' && line[i + 5] == 'w' && line[i + 6] == 'o' && line[i + 7] == 'r' && line[i + 8] == 'd' && line[i + 9] == '"' && line[i + 10] == ':') {
                    i += 13; // Bỏ qua phần "password": "
                    string password = "";
                    while (i < line.size() && line[i] != '"') {
                        password += line[i];
                        ++i;
                    }
                    users[userCount].password = password;
                    userCount++;
                }
                ++i;
            }
        }
        inFile.close();
    }

    do {
        cout << "1. Register" << endl;
        cout << "2. Log in" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            do {
                usernameTaken = false;
                cout << "Enter your username: ";
                cin >> users[userCount].username;

                // Kiểm tra xem username đã tồn tại chưa
                for (int i = 0; i < userCount; ++i) {
                    bool isEqual = true;
                    if (users[i].username.size() == users[userCount].username.size()) {
                        for (size_t j = 0; j < users[i].username.size(); ++j) {
                            if (users[i].username[j] != users[userCount].username[j]) {
                                isEqual = false;
                                break;
                            }
                        }
                    } else {
                        isEqual = false;
                    }

                    if (isEqual) {
                        usernameTaken = true;
                        cout << "Username already taken. Please choose another username." << endl;
                        break;
                    }
                }

                if (!usernameTaken) {
                    cout << "Enter your password: ";
                    cin >> users[userCount].password;
                    userCount++;

                    // Ghi dữ liệu vào file JSON
                    fstream outFile("users.json", fstream::app);
                    if (outFile.is_open()) {
                        outFile << "{\n"; 
                        outFile << "  "users": ["
                        outFile << "        {\n";
                        outFile << "            \"username\": \"" << users[userCount - 1].username << "\",\n";
                        outFile << "            \"password\": \"" << users[userCount - 1].password << "\"\n";
                        outFile << "        },\n";
                        outFile.close();
                        cout << "User registered successfully." << endl;
                    } else {
                        cerr << "Unable to open file for writing." << endl;
                    }
                }
            } while (usernameTaken);

        } else if (choice == 2) {
            loggedIn = false;
            do {
                cout << "Enter your username: ";
                cin >> inputUsername;

                // Kiểm tra xem username có tồn tại không
                bool userFound = false;
                for (int i = 0; i < userCount; ++i) {
                    bool isEqual = true;
                    if (users[i].username.size() == inputUsername.size()) {
                        for (size_t j = 0; j < users[i].username.size(); ++j) {
                            if (users[i].username[j] != inputUsername[j]) {
                                isEqual = false;
                                break;
                            }
                        }
                    } else {
                        isEqual = false;
                    }

                    if (isEqual) {
                        storedPassword = users[i].password;
                        userFound = true;
                        break;
                    }
                }

                if (!userFound) {
                    cout << "Wrong username. Please try again." << endl;
                } else {
                    do {
                        cout << "Enter your password: ";
                        cin >> inputPassword;

                        bool passwordMatch = true;
                        if (inputPassword.size() == storedPassword.size()) {
                            for (size_t k = 0; k < inputPassword.size(); ++k) {
                                if (inputPassword[k] != storedPassword[k]) {
                                    passwordMatch = false;
                                    break;
                                }
                            }
                        } else {
                            passwordMatch = false;
                        }

                        if (passwordMatch) {
                            cout << "Log in successfully." << endl;
                            loggedIn = true;
                        } else {
                            cout << "Wrong password. Please try again." << endl;
                        }
                    } while (!loggedIn);
                }
            } while (!loggedIn);

        } else {
            cout << "Invalid choice." << endl;
        }

        cout << "Do you want to perform another operation? (y/n): ";
        cin >> moreUsers;

    } while (moreUsers == 'y' || moreUsers == 'Y');

    return 0;
}
