#include <chrono>
#include <iostream>

class TimerGuard{
private:
    std::chrono::_V2::system_clock::time_point tp;
    std::string msg;
    std::ostream &o;

public:
    TimerGuard(std::string msg = "", std::ostream& out = std::cout):
        tp(std::chrono::high_resolution_clock::now()),
        msg(msg),
        o(out){}
    ~TimerGuard(){
        std::chrono::duration<double> dur = std::chrono::high_resolution_clock::now() - tp;
        o << msg << " " << dur.count();
    }
};