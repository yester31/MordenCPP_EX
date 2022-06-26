#pragma once
#include <iostream>

namespace linked_list
{
    using ElementType = int;

    class Node
    {
    public:
        ElementType Data; /* ������ �ʵ� */
        Node* NextNode; /* ���� ��带 ����Ű�� ������*/
    };

    /* �Լ� ���� ���� */
    Node* SLL_CreateNode(ElementType NewData);
    void  SLL_DestroyNode(Node* Node);
    void  SLL_AppendNode(Node** Head, Node* NewNode);
    void  SLL_InsertAfter(Node* Current, Node* NewNode);
    void  SLL_InsertNewHead(Node** Head, Node* NewHead);
    void  SLL_RemoveNode(Node** Head, Node* Remove);
    Node* SLL_GetNodeAt(Node* Head, int Location);
    int   SLL_GetNodeCount(Node* Head);

    // ���� ����
    void execute_sll();
}