#include <iostream>
int main(){
    std::string str;

    std::getline(std::cin, str);

    for (auto it = str.begin(); it != str.end(); ++it){
        if (*it == ' '){
            str.erase(it);
            --it;
        }
    }

    bool res_flag = true;
    size_t string_size = str.size();

    for (size_t i = 0; i < string_size / 2; ++i){
        if (str[i] != str[string_size - i - 1]){
            res_flag = false;
            break;
        }
    }

    std::cout << (res_flag ? "YES" : "NO") << std::endl;

    return 0;
}