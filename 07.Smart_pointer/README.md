# MordenCPP_EX

## 스마트 포인터

### 이동(Move semantics)
- 소유권 이동
- syntax(문법 측면) vs. semantics (실제 내부적인 의미)
- value semantics (copy semantics)
- reference semantics (pointer)
- move semantics (move)

### RAII : resource acquisition is initialization 
- "흭득된 자원을 초기화 한다."
- C++설계 패턴중 하나
- 개발자가 직접 메모리를 관리하는 언어에서 메모리 누수(memory leak)를 방지하기 위한 중요한 패턴
- 메모리 사용후 자동으로 메모리 해제를 해주며 예외(exception)가 발생하는 경우에도 획득한 자원이 해제됨을 보장 해야함

### 오른쪽-값 참조(R-value References)
- 문장이 끝나면 사라질 운명...
-  






