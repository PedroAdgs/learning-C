#include <stdio.h>
#include <stdlib.h>

struct Node; //remover warnings

 struct Node{
    int content;
    struct Node *next;
};

struct Node *create_node(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL)
    {
        printf("Erro ao alocar no.\n");
        exit(1);
    }
    newNode->content = data;
    newNode->next = NULL;
    return newNode;
}

void printNodes(struct Node* head)
{
    struct Node* current = head;

    while(current != NULL)
    {
        printf("%d\t", current->content);
        current = current->next;
    }
    printf("NULL\n");
}

void freeList(struct Node* head) {
    struct Node* current = head;
    struct Node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main(int argc, char const *argv[])
{

    struct Node* head = create_node(13);
    struct Node* second = create_node(2);
    struct Node* third = create_node(3);

    head->next = second;
    second->next = third;

    printf("Lista encadeada original: \n");
    printNodes(head);

    freeList(head);

    return 0;
}
