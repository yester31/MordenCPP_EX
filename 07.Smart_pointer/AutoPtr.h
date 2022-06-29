#pragma once
#include <iostream>

// XX std::auto_ptr<int>; // c++98 때 생김, c++ 11 에서 부터 사용 하지 않기로 함, c++17 완전 제거 (복잡한 경우 작동하지 않음)
template<class T>
class AutoPtr
{
    //private:
public:
    T *m_ptr = nullptr;

public:
    AutoPtr(T *ptr = nullptr) 
        : m_ptr(ptr)
    {
    }

    ~AutoPtr()
    {
        if (m_ptr != nullptr) delete m_ptr;
    }

    AutoPtr(AutoPtr &a) 
    {
        m_ptr = a.m_ptr;
        a.m_ptr = nullptr;
    }

    AutoPtr& operator = (AutoPtr &a) // move semantics (소유권 이동) 구현
    {
        if (&a == this)
            return *this;
        delete m_ptr;
        m_ptr = a.m_ptr;
        a.m_ptr = nullptr;
        return *this;
    }

    T& operator*() const { return *m_ptr; }
    T* operator->() const { return m_ptr; }
    bool isNull() const { return m_ptr == nullptr; }
};

// RAII : resource acquisition is initialization (동적 할당한 곳에서 자원 해제를 해야한다)

void doSomething2()
{
    try{
        //Resource *res = new Resource; // dull pointer
        //AutoPtr<Resource> res = new Resource; // smart pointer
        AutoPtr<Resource> res (new Resource); // smart pointer
        return;
        // work with res
        if (false) 
        {
            throw - 1; // exception
        }
        //delete res;
    }
    catch (...){}
    return;
}

// AutoPtr 한계

void doSomething3()
{
    //int i; 
    //int *ptr1(&i); 
    //int *ptr2 = nullptr;
    AutoPtr<Resource> res1(new Resource); 
    AutoPtr<Resource> res2; 

    std::cout << std::boolalpha;

    std::cout << res1.m_ptr << std::endl;
    std::cout << res2.m_ptr << std::endl;

    //res2 = res1; // = 대입 연산자(assignment operator) 
    res2 = res1; // move semantics (소유권 이동)

    std::cout << res1.m_ptr << std::endl;
    std::cout << res2.m_ptr << std::endl;
}


//int main() {
//
//    doSomething2();
//    doSomething3();
//    return 0;
//}