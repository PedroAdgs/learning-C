#include <stdio.h>
#include <stdlib.h>

struct Stack;

struct Stack{
    int value;
    struct Stack* next;
};

struct Stack* push(struct Stack* top, int data)
{
    struct Stack* newElement = (struct Stack*)malloc(sizeof(struct Stack));
    if(newElement == NULL)
    {
        printf("Erro ao adicionar novo elemento");
        eXit(1);
    }
    newElement->value = data;
    newElement->next = top;
    return newElement;
}

int pop(struct Stack** top)
{
    if(*top == NULL) //verifica se a stack está vazia
    {
        printf("Erro: Pilha vazia!\n");
        exit(1);
    }

    struct Stack* popedElement = *top; // popedElement recebe o endereço de top
    int popValue = popedElement->value; // armazena o valor do elemento

    *top = popedElement -> next; //atualiza o topo para o elemento abaixo do topo atual
    free(popedElement); //remove o topo atual

    return popValue;
}

void printElements(struct Stack* top)
{
    struct Stack* current = top;
    while(current != NULL)
    {
        printf("%d -> ");
        current = current->next;
    }
    printf("NULL\n\n");
}

int main(int argc, char const *argv[])
{
    struct Stack* top = NULL;

    top = push(top, 12);
    top = push(top, 16);
    top = push(top, 3);

    struct Stack* current = top;

    while(current != NULL)
    {
        struct Stack* next = current -> next;
        free(current);
        current = next;
    }

    return 0;
}
