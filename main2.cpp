#include <iostream>

bool is_password_valid(std::string &pass){
    unsigned char ch;
    for (std::size_t i = 0; i != pass.size(); ++i){
        ch = pass[i];
        if (ch < 32 || ch > 126)
            return false;
    }

    if (pass.size() < 8 || pass.size() > 14)
        return false;

    bool lower_flag, upper_flag, num_flag, other_flag;
    lower_flag = upper_flag = num_flag = other_flag = false;
    

    for (std::size_t i = 0; i != pass.size(); ++i)
    {
        ch = pass[i];
        if (ch < 48 || (ch >= 91 && ch <= 96) || ch >= 123 || (ch >= 58 && ch <= 64))
        {
            other_flag = true;
        }
        else if (ch >= 48 && ch <= 57)
        {
            num_flag = true;
        }
        else if (ch >= 65 && ch <= 90)
        {
            upper_flag = true;
        }
        else if (ch >= 97 && ch <= 122)
        {
            lower_flag = true;
        }
    }
    uint8_t total = 0;

    if (other_flag) ++total;
    if (num_flag) ++total;
    if (upper_flag) ++ total;
    if (lower_flag) ++total;

    if (total >= 3)
        return true;
    return false;
}

int main(){
    std::string password;
    std::cin >> password;

    if (is_password_valid(password))
        std::cout << "YES" << '\n';
    else
        std::cout << "NO" << std::endl;

    return 0;
}