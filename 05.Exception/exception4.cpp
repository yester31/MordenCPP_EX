#include "exception4.hpp"
// standard exception 예제

class CustomException : public std::exception
{
public:
    const char * what() const noexcept override // noexcept : cpp 11 이상 컴파일러 사용시 필요(적어도 이 안에서 에러 발생 안함 명시)
    {
        return "Custom exception";
    }
};

int exception4::exception4_1()
{
    try
    {
        //std::string s;
        //s.resize(-1); // 예외 발생
        throw std::runtime_error("Bad thing happened"); // 예외 발생
    }
    //catch (std::length_error &e) // length_error : std::exception의 자식 클래스
    //{
    //    std::cerr << "Length_Error" << std::endl; // class std::length_error
    //    std::cerr << e.what() << std::endl; // string too long
    //}
    catch (std::exception &e)
    {
        std::cout << typeid(e).name() << std::endl; // class std::length_error
        std::cerr << e.what() << std::endl; // string too long
    }

    return 0;
}

int exception4::exception4_2()
{
    try
    {
        throw CustomException();  // 예외 발생
    }
    catch (std::exception &e)
    {
        std::cout << typeid(e).name() << std::endl; // class std::length_error
        std::cerr << e.what() << std::endl; // string too long
    }

    return 0;
}