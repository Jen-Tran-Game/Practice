#include <iostream> 
#include "json.hpp"
#include <fstream> 
#include <openssl/hmac.h>
#include <openssl/evp.h>
#include <iomanip>

using namespace std; 
using ordered_json = nlohmann::ordered_json; // Để giữ thứ tự trong lúc đọc và ghi file 

std::string encode_password(const std::string &password, const std::string &key)
{
    unsigned char result[EVP_MAX_MD_SIZE];
    unsigned int result_len = 0; 

    //Tạo đối tượng HMAC với key và thuật toán SHA256
    HMAC_CTX *ctx = HMAC_CTX_new(); 
    HMAC_Init_ex(ctx, key.data(), key.size(), EVP_sha256(), nullptr);
    HMAC_Update(ctx, result, &result_len);
    HMAC_CTX_free(ctx);

    //Chuyển đổi giá trị mã hoá sang chuỗi hexadecimal
    std::ostringstream hex_stream; 
    for (unsigned int i = 0; i < result_len; ++i)
    {
        hex_stream << std::hex << std::setw(2) << std::setfill('0') << 
    }
}
int main()
{   
    // Read and Print username and password you want 
    // int targetIndex; 
    // cout << "Position of array you want to know: "; 
    // cin >> targetIndex; 

    // json outData; 
    // ifstream inFile("users.json"); 
    // inFile >> outData; 
    // inFile.close(); 

    // auto user = outData["users"][targetIndex]; 
    // string username = user["Username"].get<string>(); 
    // string password = user["Password"].get<string>(); 

    // cout << "Username: " << username << endl; 
    // cout << "Password: " << password << endl; 

    // Add new User to json file use C++ code
    string newUsername, newPassword; 
    cout << "Enter your new username: "; 
    cin >> newUsername;
    cout << "Enter your new password: "; 
    cin >> newPassword;  

    ordered_json outData; 
    ifstream inFile ("test_users.json"); 
    inFile >> outData; 
    inFile.close(); 

    ordered_json newUser; 
    newUser["Username"] = newUsername; 
    newUser["Password"] = newPassword; 

    outData["users"].push_back(newUser); 

    ofstream outFile ("test_users.json"); 
    outFile << outData.dump(4); 
    outFile.close(); 
    return 0; 
}