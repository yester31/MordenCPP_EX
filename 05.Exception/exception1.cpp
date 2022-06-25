#include "exception1.hpp"

int exception1::exception1()
{
    // try, catch, throw
    double x;
    std::cin >> x; // double 값 입력

    try
    {
        if (x < 0.0) throw std::string("Negative input"); // 입력값이 0 보다 작으면 계산 불가

        std::cout << std::sqrt(x) << std::endl;
    }
    catch (std::string error_message) // throw 에서 던진 값을 받아서 처리
    {
        std::cout << error_message << std::endl;
    }

    return 0;
}