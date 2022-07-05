#ifndef AFG1_H
#define AFG1_H

// Decalaration of Point data structure
typedef struct _Point
{
    double x;            // Horizontale Koordinaten
    double y;            // Vertikale Koordinaten
    struct _Point *next; // Zeiger auf die nächste Struktur
} Point;

// Funktionsdeklarationen
void append(Point **headOfList, double x, double y);
void printList(Point *headOfList);
void add(Point **headOfList, double x, double y); // Einen neuen Punkt nach einer bestehenden Liste hinzufügen
void delLast(Point **headOfList);                 // Den letzten Punkt der Liste löschen
void freeList(Point **headOfList);                // Allen Speicher freigeben
#endif                                            // AFG1_H
