#include "exception2.hpp"


void last()
{
    std::cout << "last" << std::endl;
    std::cout << "Throws exception" << std::endl;

    throw - 1;

    std::cout << "end last" << std::endl;
}

void third()
{
    std::cout << "third" << std::endl;

    last();

    std::cout << "end third" << std::endl;
}

void second()
{
    std::cout << "second" << std::endl;
    try
    {
        third();
    }
    catch (double)
    {
        std::cerr << "second caught double exception" << std::endl;
    }

    std::cout << "end second" << std::endl;
}

void first()
{
    std::cout << "first" << std::endl;
    try
    {
        second();
    }
    catch (...) // catch-all handlers
    {
        std::cerr << "first caught int exception" << std::endl;
    }

    std::cout << "end first" << std::endl;
}

int exception2::exception2()
{
    std::cout << "start" << std::endl;
    try
    {
        first();
    }
    catch (int) // throw 에서 던진 값을 받아서 처리
    {
        //std::clog << "main caught int exception" << std::endl;
        //std::cout << "main caught int exception" << std::endl; // 버퍼에서 처리후 
        std::cerr << "main caught int exception" << std::endl; // 버퍼 안통하고 바로 콘솔에 출력
    }

    std::cout << "end main" << std::endl;

    return 0;
}