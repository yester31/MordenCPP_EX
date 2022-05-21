// 단항 연산자 오버로딩 예제

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
	Point& operator++() // 전위증가, operator++ 라는 이름의 함수 
	{
		xpos+=1;
		ypos+=1;
		return *this; // this는 객체자신의 포인터 값을 의미, *this 객체 자신
	}

	Point& operator++(int) // 후위증가, operator++ 라는 이름의 함수 
	{
		xpos += 1;
		ypos += 1;
		return *this; // this는 객체자신의 포인터 값을 의미, *this 객체 자신
	}

	//전역 함수에서 Point 클래스의 private 영역을 접근하기 위해 friend 사용
	friend Point& operator--(Point &ref);
};

//전역함수에 의한 연산자 오버로딩
Point& operator--(Point &ref) // operator-- 라는 이름의 함수 
{
	ref.xpos -= 1;
	ref.ypos -= 1;
	return ref;
}

int main() {

	Point pos1(3, 4);
	pos1.ShowPosition();

	// 멤버함수에 의한 연산자 오버로딩
	++pos1; // ++pos1 =(해석)=> pos1.operator++()
	pos1.ShowPosition();

	pos1++; // pos1++ =(해석)=> pos1.operator++(int)
	pos1.ShowPosition();

	// 전역함수에 의한 연산자 오버로딩
	--pos1; // --pos1 =(해석)=> operator--(pos1)
	pos1.ShowPosition();



}