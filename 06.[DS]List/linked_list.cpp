#include "linked_list.hpp"

/*  노드 생성 */
linked_list::Node* linked_list::SLL_CreateNode(ElementType NewData)
{
    Node* NewNode = new Node;

    NewNode->Data = NewData;  /*  데이터를 저장한다. */
    NewNode->NextNode = nullptr; /*  다음 노드에 대한 포인터는 NULL로 초기화 한다. */

    return NewNode;/*  노드의 주소를 반환한다. */
}

/*  노드 소멸 */
void linked_list::SLL_DestroyNode(Node* Node)
{
    delete Node;
}

/*  노드 추가 */
void linked_list::SLL_AppendNode(Node** Head, Node* NewNode)
{
    /*  헤드 노드가 NULL이라면 새로운 노드가 Head */
    if ((*Head) == nullptr)
    {
        *Head = NewNode;
    }
    else
    {
        /*  테일을 찾아 NewNode를 연결한다. */
        Node* Tail = (*Head);
        while (Tail->NextNode != nullptr)
        {
            Tail = Tail->NextNode;
        }

        Tail->NextNode = NewNode;
    }
}

/*  노드 삽입 */
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

/*  노드 제거 */
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

/*  노드 탐색 */
linked_list::Node* linked_list::SLL_GetNodeAt(Node* Head, int Location)
{
    Node* Current = Head;

    while (Current != nullptr && (--Location) >= 0)
    {
        Current = Current->NextNode;
    }

    return Current;
}

/*  노드 수 세기 */
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

// 싱글 링크드 리스트 실행 예제 실행
void linked_list::execute_sll()
{
    int i = 0;
    int Count = 0;
    linked_list::Node* List = nullptr;
    linked_list::Node* Current = nullptr;
    linked_list::Node* NewNode = nullptr;

    /*  노드 5개 추가 */
    for (i = 0; i < 5; i++)
    {
        NewNode = linked_list::SLL_CreateNode(i);
        linked_list::SLL_AppendNode(&List, NewNode);
    }

    NewNode = linked_list::SLL_CreateNode(-1);
    linked_list::SLL_InsertNewHead(&List, NewNode);

    NewNode = linked_list::SLL_CreateNode(-2);
    linked_list::SLL_InsertNewHead(&List, NewNode);

    /*  리스트 출력 */
    Count = linked_list::SLL_GetNodeCount(List);
    for (i = 0; i < Count; i++)
    {
        Current = linked_list::SLL_GetNodeAt(List, i);
        std::cout << "List[" << i << "] : " << Current->Data << std::endl;
    }

    /*  리스트의 세번째 노드 뒤에 새 노드 삽입 */
    std::cout << "\nInserting 3000 After [2]...\n" << std::endl;

    Current = linked_list::SLL_GetNodeAt(List, 2);
    NewNode = linked_list::SLL_CreateNode(3000);

    linked_list::SLL_InsertAfter(Current, NewNode);

    /*  리스트 출력 */
    Count = linked_list::SLL_GetNodeCount(List);
    for (i = 0; i < Count; i++)
    {
        Current = linked_list::SLL_GetNodeAt(List, i);
        std::cout << "List[" << i << "] : " << Current->Data << std::endl;
    }

    /*  모든 노드를 메모리에서 제거     */
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