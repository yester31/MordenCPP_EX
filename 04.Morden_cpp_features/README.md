# MordenCPP_EX

## 4) 모던 CPP 특징

### auto
- 자동 타입 추론은 컴파일타임에 컴파일러에 의해 실제 타입이 추론된다.
- 변수의 타입 결정을 컴파일러에 맡김 사용
- 반환 타입 또는 함수의 반환 표현식 타입에 사용
* 이점 :
  - 변수를 초기화 하지않고 사용 할 수 없음.
  - 항상 올바른 타입을 사용하는 것을 보장(암시적인 변환 발생하지 않음, 데이터 손실 가능성 없음)
  - 객체지향적인 방식을 향상(지정된 타입의 수가 적을 수록 코드는 일반화)
  - 긴 이름의 타입을 사용되는 시간을 절약

### using
- 타입별칭 및 별칭 탬플릿
- 타입 이름 대신 사용할 수 있는 동의어 생성 가능

### uniform initialization
- 괄호 초기화 또는 균일한 초기화라 부름
- 데이터를 초기화 하는 균일한 방법
- 축소 변환을 허용하지 않는다. 

### non staic member variabel initialization
- 비정적 멤버 초기화

### 객체 정렬 제어 및 쿼리
- 정렬 요구 사항을 제어하기 위한 alignas 지정자
- 타입의 정렬 요구 사항을 검색하는  alignof 연산자

### 범위가 지정된 열거형 사용
- 열거형(enumeration) : 값의 컬렉션을 정의하는 타입
- 열거자(enumerator) : 상수인 명명된 값

- 범위가 지정되지 않은 열거형(unscoped enumeration) : 키워드 enum으로 선언된 열거형
- 문제점 : 
  - 동일 네임스페이스에 두 개의 열거형이 있는경우 이름 충돌이 발생 할 수 있어 정규화된 이름 사용 불가
  - 암시적으로 int로 변환

- 범위가 지정된 열거형(scoped enumeration) : enum class or enum struct로 선언된 열거형
- 해결 : 이름 충돌이 일어나지 않음 정규화된 이름 사용 가능 
  - 기본타입을 지정
  - 암시적으로 int로 변환 되지 않음

### 가상 메소드에 override와 final 사용하기
- 가상 함수를 선언할때 항상 virtual 키워드 사용한 다음 항상 override 특별 식별자 사용
- 더 이상 함수를 재정의하거나 클래스를 파생 시킬수 없도록 final 특별 식별자 사용

### 범위 기반 for 루프를 사용해 범위 반복(for each)

     for (range_declaration : range_expression ) loop_statement
_

