# MordenCPP_EX

## 템플릿(Template) 정리

### 함수 템플릿
	함수를 만들어 낸다.
	함수의 기능은 결정되어 있지만, 자료형은 결정되어 있지 않아서 결정해야 함.

	template <typename T> # or template <class T>
	T add(T num1, T num2)
	{
		return num1 + num2;
	}
	
	컴파일러가 함수 템플릿으로 만들어내는 함수를 템플릿 함수라함 (또는 생성된 함수)

	함수 템플릿의 특수화
	- 자료형에 따라 특수하게 함수를 정의 해야하는 경우 사용

### 클래스 템플릿
	클래스 템플릿 기반의 객체생성에는 반드시 자료형 정보를 명시해야함.

	template <typename T>
	class ClassTemplate
	{
	public:
		T func(const T& ref);
	}

	template <typename T> // 클래스 템플릿 외부에서 멤버함수를 정의하는 경우
	T ClassTemplate<T>::func(const T& ref)
	{
		...
	}

	void main()
	{
		ClassTemplate<int> tt;
	}

	컴파일 단계에서 컴파일러에 의해 클래스가 생성되기 때문에..
	파일을 분리하는 경우 템플릿 클래스의 선언과 생성자, 멤버 함수의 정의를 함께 넣어야 한다.
	
