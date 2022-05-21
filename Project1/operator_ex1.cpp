// 이항 연산자 오버로딩 예제

#include <iostream>

class Point {
private:
	int xpos, ypos;
public:

	// 사용자 지정 생성자
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)
	{}

	// Point 클래스 멤버 변수 출력
	void ShowPosition() const
	{
		std::cout << "[" << xpos << ", " << ypos << "]" << std::endl;
	}

	// 멤버함수에 의한 연산자 오버로딩
	Point operator+(const Point &ref) // operator+ 라는 이름의 함수 
	{
		Point pos(xpos + ref.xpos, ypos + ref.ypos);
		return pos;
	}

	//전역 함수에서 Point 클래스의 private 영역을 접근하기 위해 friend 사용
	friend Point operator-(const Point &pos1, const Point &pos2);
};

//전역함수에 의한 연산자 오버로딩
Point operator-(const Point &pos1, const Point &pos2) // operator- 라는 이름의 함수 
{
	Point pos(pos1.xpos - pos2.xpos, pos1.xpos - pos2.ypos);
	return pos;
}

int main() {

	Point pos1(3, 4);
	Point pos2(10, 20);
	pos1.ShowPosition();
	pos2.ShowPosition();

	// 멤버함수에 의한 연산자 오버로딩
	Point pos3 = pos1.operator+(pos2);
	Point pos4 = pos1 + pos2;		// pos1+pos2 =(해석)=> pos1.operator+(pos2)
	pos3.ShowPosition();
	pos4.ShowPosition();

	// 전역함수에 의한 연산자 오버로딩
	Point pos5 = operator-(pos2, pos1);
	Point pos6 = pos2 - pos1;		// pos2-pos1 =(해석)=> operator-(pos2,pos1)
	pos5.ShowPosition();
	pos6.ShowPosition();
}