#pragma once

#include <string>
#include <memory>
#include <vector>
#include <map>
#include <iostream>

namespace recipe_1_01
{
    using namespace std::string_literals;

    class foo
    {
        int x_;

    public:
        foo(int const x = 0) : x_{x} {}
        int &get() { return x_; }
    };

    auto proxy_get(foo &f) { return f.get(); }

    decltype(auto) proxy_get2(foo &f) { return f.get(); }

    struct
    {
        template <typename T, typename U>
        auto operator()(T const a, U const b) const { return a + b; }
    } L;

    void execute()
    {
        {
            // 특정 타입에 커밋 하고 싶지 않은 경우
            auto i = 42;        // int
            auto d = 42.5;      // double
            auto s = "text";    // const char*
            auto v = {1, 2, 3}; // std::initializer_list<int>

            // 특정 타입에 커밋할 경우
            auto b = new char[10]{0};            // char*
            auto p = std::make_shared<int>(42);  // std::shared_ptr<int>
            auto s2 = std::string{"text"};       // std::string
            auto v2 = std::vector<int>{1, 2, 3}; // std::vector<int>

            // 명명된 람다 함수
            auto l = [](char const c)
            { return toupper(c); }; // int(char)
        }

        {
            // 암시적 변환 방지를 통해 데이터 손실 가능성 제거
            auto v = std::vector<int>{1, 2, 3};
            int size1 = v.size(); // implicit conversion, possible loss of data
            auto size2 = v.size();
            // auto size3 = int{ v.size() }; // error, narrowing conversion
        }

        {
            // 긴 이름의 타입 사용의 불편함 해소
            std::map<int, std::string> m;

            for (std::map<int, std::string>::const_iterator it = m.cbegin(); it != m.cend(); ++it)
            {
            }

            for (auto it = m.cbegin(); it != m.cend(); ++it)
            {
            }
        }

        {
            // 참조자가 반환형일 경우 auto& 으로 사용해야함.
            foo f(42);
            auto x = f.get(); // &int 가 아니라 int 로 타입 해석됨...
            x = 100;
            std::cout << f.get() << '\n'; // prints 42

            auto &x2 = f.get(); // &int 해석
            x2 = 100;
            std::cout << f.get() << '\n'; // prints 100
        }

        {
            // auto l1 = long long{ 42 }; // error

            using llong = long long;
            auto l2 = llong{42}; // OK
            auto l3 = 42LL;      // OK
        }

        {
            auto f = foo{42};
            // auto& x = proxy_get(f); // cannot convert from 'int' to 'int &'
        }

        {
            // decltype 타입을 볼바르게 추론해줌(c++14)
            auto f = foo{42};
            decltype(auto) x = proxy_get2(f);
        }

        {
            // 제네릭 람다
            auto ladd = [](auto const a, auto const b)
            { return a + b; };

            auto i = ladd(40, 2);            // 42
            auto s = ladd("forty"s, "two"s); // "forty two"s
        }
    }

    // c++ 11 스타일
    auto func1(int const i) -> int
    {
        return 2 * i;
    }

    // c++ 14 스타일
    auto func2(int const i)
    {
        return 2 * i;
    }
}