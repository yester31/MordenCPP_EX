// cout << 연산자 오버로딩 예제

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

	//전역 함수에서 Point 클래스의 private 영역을 접근하기 위해 friend 사용
	friend std::ostream&  operator<<(std::ostream& os, const Point &pos);
};

//전역함수에 의한 연산자 오버로딩
std::ostream&  operator<<(std::ostream& os, const Point &pos) // operator<< 라는 이름의 함수 
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