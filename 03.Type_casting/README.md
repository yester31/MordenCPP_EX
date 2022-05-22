# MordenCPP_EX

## 형변환 연산자
    형변환연산자<T>(expr)

### static_cast
    기본자료형 간의 형변환 과 클래스의 상속관계에서의 형변환
    형변환은 되지만 책임은 프로그래머에게 있음

### dynamic_cast
    클래스의 상속관계에서 안전한 형변환
    형변환이 적절하지 않은 경우 컴파일시 에러 발생

### const_cast
    포인터와 참조자의 const 성향을 제거

### reinterpret_cast
    상관없는 자료형으로 형 변환 가능