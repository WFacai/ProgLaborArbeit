#ifndef AFG5_H
#define AFG5_H

// Struktur des Stapelknotens
typedef struct _ListNode
{
    int val;
    struct _ListNode *next; // Zeiger auf nächster Node
} ListNode;

// Struktur des Stapel
struct Stack
{
    void (*pushStack)(struct Stack *stack, int val); // Funktionszeiger
    int (*popStack)(struct Stack *stack, int *val);
    int (*emptyStack)(struct Stack *stack);
    struct _ListNode *list; // Zeiger auf Listenkopf
};

// Decalaration of function
// Deklaration von Zeigerfunktionen innerhalb der Stack-Struktur
// und Initialisierung von Tabellenkopfzeigern
struct Stack *initStack();
////Ausstapeln und drucken
void outputwholeStack(struct Stack *stack);
// die Integerzahl werden val auf den Stapel stack gelegt
void pushStack(struct Stack *stack, int val);
// liefert das oberste val und entfernt es vom Stapel
int popStack(struct Stack *stack, int *val);
// Prüfung auf einen leeren Stapel
int emptyStack(struct Stack *stack);

#endif // AFG5_H
