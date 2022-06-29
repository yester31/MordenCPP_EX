#pragma once
#include <iostream>

class Resource
{
    //private:
public:
    int m_data[100];

public:
    Resource()
    {
        std::cout << "Resource constructed" << std::endl;
    }

    ~Resource()
    {
        std::cout << "Resource destroyed" << std::endl;
    }
};

// RAII : resource acquisition is initialization (동적 할당한 곳에서 자원 해제를 해야한다)

void doSomething()
{
    try
    {
        Resource *res = new Resource;

        // work with res
        if (false) {
            //delete res;
            //return; // early return
            throw - 1; // exception
        }

        delete res;
    }
    catch (...)
    {

    }

    return;
}

//int main() {
//
//    doSomething();
//
//    return 0;
//}