// ���� ������ �����ε� ����

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

	// ����Լ��� ���� ������ �����ε�
	Point operator+(const Point &ref) // operator+ ��� �̸��� �Լ� 
	{
		Point pos(xpos + ref.xpos, ypos + ref.ypos);
		return pos;
	}

	//���� �Լ����� Point Ŭ������ private ������ �����ϱ� ���� friend ���
	friend Point operator-(const Point &pos1, const Point &pos2);
};

//�����Լ��� ���� ������ �����ε�
Point operator-(const Point &pos1, const Point &pos2) // operator- ��� �̸��� �Լ� 
{
	Point pos(pos1.xpos - pos2.xpos, pos1.xpos - pos2.ypos);
	return pos;
}

int main() {

	Point pos1(3, 4);
	Point pos2(10, 20);
	pos1.ShowPosition();
	pos2.ShowPosition();

	// ����Լ��� ���� ������ �����ε�
	Point pos3 = pos1.operator+(pos2);
	Point pos4 = pos1 + pos2;		// pos1+pos2 =(�ؼ�)=> pos1.operator+(pos2)
	pos3.ShowPosition();
	pos4.ShowPosition();

	// �����Լ��� ���� ������ �����ε�
	Point pos5 = operator-(pos2, pos1);
	Point pos6 = pos2 - pos1;		// pos2-pos1 =(�ؼ�)=> operator-(pos2,pos1)
	pos5.ShowPosition();
	pos6.ShowPosition();
}