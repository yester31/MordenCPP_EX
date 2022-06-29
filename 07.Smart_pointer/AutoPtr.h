#pragma once
#include <iostream>

// XX std::auto_ptr<int>; // c++98 �� ����, c++ 11 ���� ���� ��� ���� �ʱ�� ��, c++17 ���� ���� (������ ��� �۵����� ����)
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

    AutoPtr& operator = (AutoPtr &a) // move semantics (������ �̵�) ����
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

// RAII : resource acquisition is initialization (���� �Ҵ��� ������ �ڿ� ������ �ؾ��Ѵ�)

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

// AutoPtr �Ѱ�

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

    //res2 = res1; // = ���� ������(assignment operator) 
    res2 = res1; // move semantics (������ �̵�)

    std::cout << res1.m_ptr << std::endl;
    std::cout << res2.m_ptr << std::endl;
}


//int main() {
//
//    doSomething2();
//    doSomething3();
//    return 0;
//}