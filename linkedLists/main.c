#include <stdio.h>
#include <stdlib.h>
#define RELEASE

struct Node; //remover warnings

 struct Node{
    int content;
    struct Node *next;
};

struct Node *create_node(int data) //retorna um ponteiro para a struct Node
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); //aloca memória para o novo tamanho da struct
    if(newNode == NULL)
    {
        printf("Erro ao alocar no.\n");
        exit(1);
    }
    #ifdef DEBUG
    printf("New Node addr: %p\n\n", newNode);
    #endif
    newNode->content = data;
    newNode->next = NULL;
    return newNode; //retorna um novo endereço da estrutura
}

void printNodes(struct Node* head)
{
    struct Node* current = head;

    while(current != NULL)
    {
        #ifdef DEBUG
        printf("current addr: %p\n\n", current);
        #endif
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

    #ifdef DEBUG
    printf("%p\n\n", head);
    printf("%p\n\n", second);
    printf("%p\n\n", third);
    #endif

    printf("Lista encadeada original: \n\n");
    printNodes(head);

    freeList(head);

    return 0;
}

