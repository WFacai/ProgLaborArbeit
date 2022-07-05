#ifndef AFG4_H
#define AFG4_H
#include "afg3.h"

// Decalaration of function
Person *pfind(Person *headOfList, char *name, int age, float size); // Suche nach einer Person
int pdelete(Person **headOfList, char *name, int age, float size);  // Löschen der Daten einer Person

#endif // AFG4_H
