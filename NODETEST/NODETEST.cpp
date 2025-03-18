#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//노드 구조체 정의
typedef struct Node {
    int data;
    struct Node* next;
} Node;

//전역 변수: 리스트의 헤드 노트
Node* g_head = NULL;

// 노드 추가 함수 (리스트 앞에 삽입)
void addNode(int value) {
    Node* pAlloc = (Node*)malloc(sizeof(Node));
    if (pAlloc == NULL)
    {
        printf("메모리 할당에 실패\n");
        return;
    }
    pAlloc->data = value;
    pAlloc->next = g_head; //기존 헤드 노드를 다음 노드로 설정
    g_head = pAlloc;   // 새로운 노드를 헤드로 설정
}

//리스트 출력 함수

void printList()
{
    Node* current = g_head;
    while (current)
    {
        printf("%d ->", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

//리스트 메모리 제거
void freeList()
{
    Node* current = g_head;
    while (current)
    {
        Node* temp = current;
        current = current->next;
        free(temp);

    }
}

int main()
{
    addNode(1);
    addNode(2);
    addNode(3);

    printList(); // 출력: 3->2->1->NULL

    freeList(); //메모리 해제
 
    return 0;
}