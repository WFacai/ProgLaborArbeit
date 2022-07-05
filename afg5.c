#include <stdio.h>
#include <stdlib.h>

#include "afg5.h"

struct Stack *initStack()
{
    // Deklarationen von Funktionszeigern auf Funktionen
    struct Stack *Stack = (struct Stack *)malloc(sizeof(struct Stack));
    Stack->pushStack = pushStack; // Das speicher "pushStack" in der Struktur *struck verweist auf die Funktion pushstack
    Stack->popStack = popStack;
    Stack->emptyStack = emptyStack;
    Stack->list = NULL; // Zeiger auf Listenkopf
    return Stack;       // Rückgabezeiger "Stack"
}

void outputwholeStack(struct Stack *stack)
{
    int val;
    while (!stack->emptyStack(stack)) // wenn der Stapel nicht leer ist
    {
        stack->popStack(stack, &val); // Der Pop-Out-Wert wird in val gespeichert
        printf("%i\n", val);
    }
    printf("Empty Stack\n");
}

void pushStack(struct Stack *stack, int val)
{
    ListNode *newNode;
    newNode = (ListNode *)malloc(sizeof(ListNode)); // malloc allokiert neuen Knotenspeicher
    newNode->val = val;                             // Neue Knoten werden im Listekopf platziert
    newNode->next = stack->list;
    stack->list = newNode; // Der neue Knoten newNode wird dem obersten Node des Stapelzeigers zugewiesen
}

int popStack(struct Stack *stack, int *val)
{
    if (stack->emptyStack(stack))
    {
        return 0; // Ist der Stapel leer, wird 0 zurückgegeben und nichts in die Variable val
    }
    else
    {
        ListNode *top;
        *val = stack->list->val;         // val zeigt auf den Wert, der vom Stapel geliefert wird
        top = stack->list;               // top wird verwendet, um den obersten Knoten des zu löschenden Stapels zu speichern
        stack->list = stack->list->next; // Der zweite Knoten wird auf den ersten verschoben
        free(top);                       // der oberste Knoten freigaben wird
        return 1;                        // Gibt 1 zurück, wenn es einen Popwert gibt
    }
}

int emptyStack(struct Stack *stack)
{
    if (stack->list == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
