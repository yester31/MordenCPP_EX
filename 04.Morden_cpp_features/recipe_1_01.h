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
            // Ư�� Ÿ�Կ� Ŀ�� �ϰ� ���� ���� ���
            auto i = 42;        // int
            auto d = 42.5;      // double
            auto s = "text";    // const char*
            auto v = {1, 2, 3}; // std::initializer_list<int>

            // Ư�� Ÿ�Կ� Ŀ���� ���
            auto b = new char[10]{0};            // char*
            auto p = std::make_shared<int>(42);  // std::shared_ptr<int>
            auto s2 = std::string{"text"};       // std::string
            auto v2 = std::vector<int>{1, 2, 3}; // std::vector<int>

            // ���� ���� �Լ�
            auto l = [](char const c)
            { return toupper(c); }; // int(char)
        }

        {
            // �Ͻ��� ��ȯ ������ ���� ������ �ս� ���ɼ� ����
            auto v = std::vector<int>{1, 2, 3};
            int size1 = v.size(); // implicit conversion, possible loss of data
            auto size2 = v.size();
            // auto size3 = int{ v.size() }; // error, narrowing conversion
        }

        {
            // �� �̸��� Ÿ�� ����� ������ �ؼ�
            std::map<int, std::string> m;

            for (std::map<int, std::string>::const_iterator it = m.cbegin(); it != m.cend(); ++it)
            {
            }

            for (auto it = m.cbegin(); it != m.cend(); ++it)
            {
            }
        }

        {
            // �����ڰ� ��ȯ���� ��� auto& ���� ����ؾ���.
            foo f(42);
            auto x = f.get(); // &int �� �ƴ϶� int �� Ÿ�� �ؼ���...
            x = 100;
            std::cout << f.get() << '\n'; // prints 42

            auto &x2 = f.get(); // &int �ؼ�
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
            // decltype Ÿ���� ���ٸ��� �߷�����(c++14)
            auto f = foo{42};
            decltype(auto) x = proxy_get2(f);
        }

        {
            // ���׸� ����
            auto ladd = [](auto const a, auto const b)
            { return a + b; };

            auto i = ladd(40, 2);            // 42
            auto s = ladd("forty"s, "two"s); // "forty two"s
        }
    }

    // c++ 11 ��Ÿ��
    auto func1(int const i) -> int
    {
        return 2 * i;
    }

    // c++ 14 ��Ÿ��
    auto func2(int const i)
    {
        return 2 * i;
    }
}