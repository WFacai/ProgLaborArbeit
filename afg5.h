#ifndef AFG5_H
#define AFG5_H

// Decalaration of function printOdo
// die Integerzahl werden val auf den Stapel stack gelegt
void pushStack(struct Stack *stack, int val);
// liefert das oberste val und entfernt es vom Stapel
int popStack(struct Stack *stack, int *val);
// Prüfung auf einen leeren Stapel
int emptyStack(struct Stack *stack);

#endif // AFG5_H
