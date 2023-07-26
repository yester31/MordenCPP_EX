#pragma once

#include <vector>
#include <map>
#include <string>
#include <iostream>

namespace recipe_1_03
{
    void func(int const a, int const b, int const c)
    {
        std::cout << a << b << c << '\n';
    }

    void func(std::initializer_list<int> const list)
    {
        for (auto const &e : list)
            std::cout << e << '\n';
    }

    void execute()
    {
        {
            std::string s1("test");  // 직접 초기화
            std::string s2 = "test"; // 복사 초기화
        }

        {
            int a = 42;
            double b = 1.2;
            bool c = false;
        }

        {
            class foo
            {
                int a_;

            public:
                foo(int a) : a_(a) {}
            };

            foo f1 = 42;
        }

        {
            // 사용자 정의 타입
            class foo
            {
                int a_;
                double b_;

            public:
                foo() : a_(0), b_(0) {}

                foo(int a, double b = 0.0) : a_(a), b_(b) {}
            };

            foo f1; // default initialization
            foo f2(42, 1.2);
            foo f3(42);
            // foo f4();         // function declaration
        }

        {
            // 사용자 정의 POD 타입
            struct bar
            {
                int a_;
                double b_;
            };

            bar b = {42, 1.2};

            int a[] = {1, 2, 3, 4, 5};
        }

        {
            class foo
            {
                int a_;
                double b_;

            public:
                foo() : a_(0), b_(0) {} // 디폴트 생성자 구현

                foo(int a, double b = 0.0) : a_(a), b_(b) {} // 매개변수를 가진 생성자
            };

            struct bar
            {
                int a_;
                double b_;
            };

            int i{42};
            double d{1.2};
            int arr1[3]{1, 2, 3};
            int *arr2 = new int[3]{1, 2, 3};
            foo f0;          // 디폴트 생성자 호출
            foo f1{};        // 디폴트 생성자 호출
            foo f2{42, 1.2}; // 매개변수를 가진 생성자 호출
            foo f3{42};      // 매개변수를 가진 생성자 호출
            bar b{42, 1.2};
            std::vector<int> v{1, 2, 3};
            std::map<int, std::string> m{{1, "one"}, {2, "two"}};
        }

        {
            class foo
            {
                int a_;
                int b_;

            public:
                foo() : a_(0), b_(0) {}

                foo(int a, int b = 0) : a_(a), b_(b) {}
                foo(std::initializer_list<int> l) {}
            };

            foo f{1, 2}; // calls constructor with initializer_list<int>
        }

        {
            func({1, 2, 3}); // calls second overload
        }

        {
            std::vector<int> v1{5}; // 5인 하나의 요소를 가진 벡터 생성
            std::vector<int> v2(5); // 크기가 5인 벡터 생성
        }

        {
            // 괄호초기화는 축소 변환을 허용하지 않는다.
            // int i{ 1.2 };                 // error
            int i{static_cast<int>(1.2)}; // 명시적 변환 수행

            double d = 47 / 13;
            // float f1{ d };                    // error
            float f1{static_cast<float>(d)}; // 명시적 변환 수행
            float f2{47 / 13};               // OK
        }
    }
}