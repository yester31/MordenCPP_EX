#include "exception3.hpp"
// 사용자 정의 예외 클래스 

class Exception
{
public:
    void report()
    {
        std::cerr << "Exception report" << std::endl;
    }
};

class ArrayException : public Exception
{
public:
    void report()
    {
        std::cerr << "Array Exception report" << std::endl;
    }
};

class MyArray
{
private:
    int m_data[5];

public:
    int & operator[] (const int & index)
    {
        //if (index < 0 || index >= 5) throw - 1;
        if (index < 0 || index >= 5) throw ArrayException();

        return m_data[index];
    }
};

void doSomething()
{
    MyArray my_array;

    try
    {
        my_array[100];
    }
    catch (const int &x)
    {
        std::cout << "doSomething()" << std::endl;
        std::cerr << "Exception " << x << std::endl;
    }
    //catch (ArrayException &e)
    //{
    //    std::cout << "doSomething()" << std::endl;
    //    e.report();
    //    throw e; // re-throw
    //}
    catch (Exception &e)
    {
        std::cout << "doSomething()" << std::endl;
        e.report();
        //throw e; // re-throw
        throw; // re-throw
    }
}

int exception3::exception3()
{
    try
    {
        doSomething();
    }
    catch (ArrayException &e)
    {
        std::cout << "main()" << std::endl;
        e.report();
    }
    catch (Exception &e)
    {
        std::cout << "main()" << std::endl;
        e.report();
    }
    return 0;
}