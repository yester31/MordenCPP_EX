# MordenCPP_EX

## ���ø�(Template) ����

### �Լ� ���ø�
	�Լ��� ����� ����.
	�Լ��� ����� �����Ǿ� ������, �ڷ����� �����Ǿ� ���� �ʾƼ� �����ؾ� ��.

	template <typename T> # or template <class T>
	T add(T num1, T num2)
	{
		return num1 + num2;
	}
	
	�����Ϸ��� �Լ� ���ø����� ������ �Լ��� ���ø� �Լ����� (�Ǵ� ������ �Լ�)

	�Լ� ���ø��� Ư��ȭ
	- �ڷ����� ���� Ư���ϰ� �Լ��� ���� �ؾ��ϴ� ��� ���

### Ŭ���� ���ø�
	Ŭ���� ���ø� ����� ��ü�������� �ݵ�� �ڷ��� ������ ����ؾ���.

	template <typename T>
	class ClassTemplate
	{
	public:
		T func(const T& ref);
	}

	template <typename T> // Ŭ���� ���ø� �ܺο��� ����Լ��� �����ϴ� ���
	T ClassTemplate<T>::func(const T& ref)
	{
		...
	}

	void main()
	{
		ClassTemplate<int> tt;
	}

	������ �ܰ迡�� �����Ϸ��� ���� Ŭ������ �����Ǳ� ������..
	������ �и��ϴ� ��� ���ø� Ŭ������ ����� ������, ��� �Լ��� ���Ǹ� �Բ� �־�� �Ѵ�.
	
