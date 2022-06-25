#include "exception1.hpp"

int exception1::exception1()
{
    // try, catch, throw
    double x;
    std::cin >> x; // double �� �Է�

    try
    {
        if (x < 0.0) throw std::string("Negative input"); // �Է°��� 0 ���� ������ ��� �Ұ�

        std::cout << std::sqrt(x) << std::endl;
    }
    catch (std::string error_message) // throw ���� ���� ���� �޾Ƽ� ó��
    {
        std::cout << error_message << std::endl;
    }

    return 0;
}