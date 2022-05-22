// cout << ������ �����ε� ����

#include <iostream>

class Point {
private:
	int xpos, ypos;
public:

	// ����� ���� ������
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)
	{}

	// Point Ŭ���� ��� ���� ���
	void ShowPosition() const
	{
		std::cout << "[" << xpos << ", " << ypos << "]" << std::endl;
	}

	//���� �Լ����� Point Ŭ������ private ������ �����ϱ� ���� friend ���
	friend std::ostream&  operator<<(std::ostream& os, const Point &pos);
};

//�����Լ��� ���� ������ �����ε�
std::ostream&  operator<<(std::ostream& os, const Point &pos) // operator<< ��� �̸��� �Լ� 
{
	os << "[" << pos.xpos << ", " << pos.ypos << "]" << std::endl;
	return os;
}

int main() {

	Point pos1(3, 4);
	std::cout << pos1;
	Point pos2(10, 20);
	std::cout << pos2;
    return 0;
}