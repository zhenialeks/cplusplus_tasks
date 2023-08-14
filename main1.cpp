#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>

int main(){

    std::string line;
    std::set<char> res_set;
    std::set<char> buf_set;
    bool first_time = true;

    while(std::getline(std::cin, line)){
        std::set<char> last_set;
        std::copy(line.begin(), line.end(), std::inserter(last_set, last_set.begin()));

        if (first_time){
            res_set = last_set;
            first_time = false;
            continue;
        }
        

        std::set_intersection(last_set.begin(),
                              last_set.end(),
                              res_set.begin(),
                              res_set.end(),
                              std::inserter(buf_set, buf_set.begin()));
        res_set = buf_set;
        buf_set.clear();
    }

    for (auto & el: res_set){
        std::cout << el;
    }
    std::cout << std::endl;

    return 0;
}