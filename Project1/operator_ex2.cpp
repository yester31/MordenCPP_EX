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
	Point& operator++() // ��������, operator++ ��� �̸��� �Լ� 
	{
		xpos+=1;
		ypos+=1;
		return *this; // this�� ��ü�ڽ��� ������ ���� �ǹ�, *this ��ü �ڽ�
	}

	Point& operator++(int) // ��������, operator++ ��� �̸��� �Լ� 
	{
		xpos += 1;
		ypos += 1;
		return *this; // this�� ��ü�ڽ��� ������ ���� �ǹ�, *this ��ü �ڽ�
	}

	//���� �Լ����� Point Ŭ������ private ������ �����ϱ� ���� friend ���
	friend Point& operator--(Point &ref);
};

//�����Լ��� ���� ������ �����ε�
Point& operator--(Point &ref) // operator-- ��� �̸��� �Լ� 
{
	ref.xpos -= 1;
	ref.ypos -= 1;
	return ref;
}

int main() {

	Point pos1(3, 4);
	pos1.ShowPosition();

	// ����Լ��� ���� ������ �����ε�
	++pos1; // ++pos1 =(�ؼ�)=> pos1.operator++()
	pos1.ShowPosition();

	pos1++; // pos1++ =(�ؼ�)=> pos1.operator++(int)
	pos1.ShowPosition();

	// �����Լ��� ���� ������ �����ε�
	--pos1; // --pos1 =(�ؼ�)=> operator--(pos1)
	pos1.ShowPosition();



}