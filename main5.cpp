#include <iostream>
#include <vector>


bool is_valid_place(int y, int x, int m, int n, auto & field){
    if (x < 0 || x == n)
        return false;
    if (y < 0 || y == m)
        return false;
    if (field[y][x] == '*')
        return false;
    return true;
}

int main(){

    int m, n, k;
    std::cin >> m >> n >> k;

    std::vector<std::vector<char>> field(m, std::vector<char>(n, '0'));

    for (int i = 0; i < k; ++i){
        int x, y;
        std::cin >> y >> x;
        --x;
        --y;
        field[y][x] = '*';

        if (is_valid_place(y+1, x, m, n, field)) ++field[y+1][x];
        if (is_valid_place(y-1, x, m, n, field)) ++field[y-1][x];
        if (is_valid_place(y+1, x+1, m, n, field)) ++field[y+1][x+1];
        if (is_valid_place(y-1, x+1, m, n, field)) ++field[y-1][x+1];
        if (is_valid_place(y+1, x-1, m, n, field)) ++field[y+1][x-1];
        if (is_valid_place(y-1, x-1, m, n, field)) ++field[y-1][x-1];
        if (is_valid_place(y, x+1, m, n, field)) ++field[y][x+1];
        if (is_valid_place(y, x-1, m, n, field)) ++field[y][x-1];
    }

    for (auto it = field.begin(); it != field.end(); ++it){
        for (auto it2 = (*it).begin(); it2 != (*it).end(); ++it2){
            std::cout << *it2 << (it2 == ((*it).end() - 1 ) ? '\n' : ' ');
        }
    }
    return 0;
}