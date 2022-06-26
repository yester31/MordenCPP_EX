#pragma once
#include <iostream>

namespace linked_list
{
    using ElementType = int;

    class Node
    {
    public:
        ElementType Data; /* 데이터 필드 */
        Node* NextNode; /* 다음 노드를 가리키는 포인터*/
    };

    /* 함수 원형 선언 */
    Node* SLL_CreateNode(ElementType NewData);
    void  SLL_DestroyNode(Node* Node);
    void  SLL_AppendNode(Node** Head, Node* NewNode);
    void  SLL_InsertAfter(Node* Current, Node* NewNode);
    void  SLL_InsertNewHead(Node** Head, Node* NewHead);
    void  SLL_RemoveNode(Node** Head, Node* Remove);
    Node* SLL_GetNodeAt(Node* Head, int Location);
    int   SLL_GetNodeCount(Node* Head);

    // 예제 실행
    void execute_sll();
}