#include <iostream>

int main(){
    std::string word;
    std::cin >> word;
    //step 2
    for (auto it = word.begin() + 1; it != word.end(); ++it){
        switch(*it){
            case 'a':
            case 'e':
            case 'h':
            case 'i':
            case 'o':
            case 'u':
            case 'w':
            case 'y':
                word.erase(it);
                --it;
                break;
            }
    }
    //step 3
    for (auto it = word.begin() + 1; it != word.end(); ++it){
        switch (*it){
            case 'b':
            case 'f':
            case 'p':
            case 'v':
                *it = '1';
                break;
            case 'c':
            case 'g':
            case 'j':
            case 'k':
            case 'q':
            case 's':
            case 'x':
            case 'z':
                *it = '2';
                break;
            case 'd':
            case 't':
                *it = '3';
                break;
            case 'l':  
                *it = '4';
                break;
            case 'm':
            case 'n':
                *it = '5';
                break;
            case 'r':
                *it = '6';
                break;
            default:
                break;
        }
    }
    //step 4
    if (word.size() > 2){
        auto it = word.begin() + 1;
        char cur_ch = *it;
        ++it;
        do{
            if (*it == cur_ch)
                word.erase(it);
            else{
                cur_ch = *it;
                ++it;
            }
        } while (it != word.end());
    }

    if (word.size() < 4){
        size_t s = 4 - word.size() ;
        for (size_t i = 0; i < s; ++i)
            word.insert(word.end(), '0');
    }
    else{
        word.resize(4);
    }
    std::cout << word << '\n';
    return 0;
}