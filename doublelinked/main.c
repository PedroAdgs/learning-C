#include <stdio.h>
#include <stdlib.h>

struct nodes;

struct nodes{
    int data;
    struct nodes* next;
    struct nodes* previous;
};

struct nodes* createNode(int value)
{
    struct nodes* newNode = (struct nodes*)malloc(sizeof(struct nodes));
    if(newNode == NULL)
    {
        printf("ERRO AO ALOCAR MEMORIA");
        exit(1);
    }

    newNode->data = value;
    newNode->previous = NULL;
    newNode->next = NULL;

    return newNode;
}

void printNodes(struct nodes* head)
{
    struct nodes* current = head;
    while(current != NULL)
    {
        printf("%d-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main(int argc, char const *argv[])
{
    struct nodes* head = createNode(12);
    struct nodes* second = createNode(4);
    struct nodes* third = createNode(78);

    head->next = second;
    second->next = third;

    second->previous = head;
    third->previous = second;

    printf("Lista ligada original: \n\n");
    printNodes(head);

    struct nodes* current = head;
    struct nodes* next;
    while(current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    return 0;
}