#include "exception3.hpp"

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
    catch (ArrayException &e)
    {
        std::cout << "doSomething()" << std::endl;
        e.report();
        //throw 
    }
    catch (Exception &e)
    {
        std::cout << "doSomething()" << std::endl;
        e.report();
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

    return 0;
}