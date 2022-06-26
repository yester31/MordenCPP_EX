#include "exception4.hpp"
// standard exception ����

class CustomException : public std::exception
{
public:
    const char * what() const noexcept override // noexcept : cpp 11 �̻� �����Ϸ� ���� �ʿ�(��� �� �ȿ��� ���� �߻� ���� ���)
    {
        return "Custom exception";
    }
};

int exception4::exception4_1()
{
    try
    {
        //std::string s;
        //s.resize(-1); // ���� �߻�
        throw std::runtime_error("Bad thing happened"); // ���� �߻�
    }
    //catch (std::length_error &e) // length_error : std::exception�� �ڽ� Ŭ����
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
        throw CustomException();  // ���� �߻�
    }
    catch (std::exception &e)
    {
        std::cout << typeid(e).name() << std::endl; // class std::length_error
        std::cerr << e.what() << std::endl; // string too long
    }

    return 0;
}