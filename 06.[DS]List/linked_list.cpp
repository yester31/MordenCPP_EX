#include "linked_list.hpp"

/*  ��� ���� */
linked_list::Node* linked_list::SLL_CreateNode(ElementType NewData)
{
    Node* NewNode = new Node;

    NewNode->Data = NewData;  /*  �����͸� �����Ѵ�. */
    NewNode->NextNode = nullptr; /*  ���� ��忡 ���� �����ʹ� NULL�� �ʱ�ȭ �Ѵ�. */

    return NewNode;/*  ����� �ּҸ� ��ȯ�Ѵ�. */
}

/*  ��� �Ҹ� */
void linked_list::SLL_DestroyNode(Node* Node)
{
    delete Node;
}

/*  ��� �߰� */
void linked_list::SLL_AppendNode(Node** Head, Node* NewNode)
{
    /*  ��� ��尡 NULL�̶�� ���ο� ��尡 Head */
    if ((*Head) == nullptr)
    {
        *Head = NewNode;
    }
    else
    {
        /*  ������ ã�� NewNode�� �����Ѵ�. */
        Node* Tail = (*Head);
        while (Tail->NextNode != nullptr)
        {
            Tail = Tail->NextNode;
        }

        Tail->NextNode = NewNode;
    }
}

/*  ��� ���� */
void linked_list::SLL_InsertAfter(Node* Current, Node* NewNode)
{
    // current node -> (insert)new node -> next node
    NewNode->NextNode = Current->NextNode;
    Current->NextNode = NewNode;
}

void linked_list::SLL_InsertNewHead(Node** Head, Node* NewHead)
{
    if (Head == nullptr)
    {
        (*Head) = NewHead;
    }
    else
    {
        NewHead->NextNode = (*Head);
        (*Head) = NewHead;
    }
}

/*  ��� ���� */
void linked_list::SLL_RemoveNode(Node** Head, Node* Remove)
{
    if (*Head == Remove)
    {
        *Head = Remove->NextNode;
    }
    else
    {
        Node* Current = *Head;
        while (Current != nullptr && Current->NextNode != Remove)
        {
            Current = Current->NextNode;
        }

        if (Current != nullptr)
            Current->NextNode = Remove->NextNode;
    }
}

/*  ��� Ž�� */
linked_list::Node* linked_list::SLL_GetNodeAt(Node* Head, int Location)
{
    Node* Current = Head;

    while (Current != nullptr && (--Location) >= 0)
    {
        Current = Current->NextNode;
    }

    return Current;
}

/*  ��� �� ���� */
int linked_list::SLL_GetNodeCount(Node* Head)
{
    int   Count = 0;
    Node* Current = Head;

    while (Current != nullptr)
    {
        Current = Current->NextNode;
        Count++;
    }

    return Count;
}

// �̱� ��ũ�� ����Ʈ ���� ���� ����
void linked_list::execute_sll()
{
    int i = 0;
    int Count = 0;
    linked_list::Node* List = nullptr;
    linked_list::Node* Current = nullptr;
    linked_list::Node* NewNode = nullptr;

    /*  ��� 5�� �߰� */
    for (i = 0; i < 5; i++)
    {
        NewNode = linked_list::SLL_CreateNode(i);
        linked_list::SLL_AppendNode(&List, NewNode);
    }

    NewNode = linked_list::SLL_CreateNode(-1);
    linked_list::SLL_InsertNewHead(&List, NewNode);

    NewNode = linked_list::SLL_CreateNode(-2);
    linked_list::SLL_InsertNewHead(&List, NewNode);

    /*  ����Ʈ ��� */
    Count = linked_list::SLL_GetNodeCount(List);
    for (i = 0; i < Count; i++)
    {
        Current = linked_list::SLL_GetNodeAt(List, i);
        std::cout << "List[" << i << "] : " << Current->Data << std::endl;
    }

    /*  ����Ʈ�� ����° ��� �ڿ� �� ��� ���� */
    std::cout << "\nInserting 3000 After [2]...\n" << std::endl;

    Current = linked_list::SLL_GetNodeAt(List, 2);
    NewNode = linked_list::SLL_CreateNode(3000);

    linked_list::SLL_InsertAfter(Current, NewNode);

    /*  ����Ʈ ��� */
    Count = linked_list::SLL_GetNodeCount(List);
    for (i = 0; i < Count; i++)
    {
        Current = linked_list::SLL_GetNodeAt(List, i);
        std::cout << "List[" << i << "] : " << Current->Data << std::endl;
    }

    /*  ��� ��带 �޸𸮿��� ����     */
    std::cout << "\nDestroying List..." << std::endl;

    for (i = 0; i < Count; i++)
    {
        Current = linked_list::SLL_GetNodeAt(List, 0);

        if (Current != nullptr)
        {
            linked_list::SLL_RemoveNode(&List, Current);
            linked_list::SLL_DestroyNode(Current);
        }
    }
}