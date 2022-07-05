#include <stdlib.h>
#include <stdio.h>

#include "afg1.h"

// Definition of function append a poing
void append(Point **headOfList, double x, double y)
{
    Point *currentElem = *headOfList; // Ein temporärer Zeiger wird erstellt
    // Listenelement allozieren (Allocate list item)
    Point *newPoint = (Point *)malloc(sizeof(Point));
    newPoint->x = x; // Listenelement Daten zuweisen (Assign list element data)
    newPoint->y = y;
    newPoint->next = NULL; // Nullzeiger: Markiert Ende der Liste (Zero pointer: Marks end of list)
    // Falls Liste leer: Listenkopf erzeugen (If list is empty: Create list header)
    if (currentElem == NULL)
    {
        *headOfList = newPoint;
    }
    else
    {
        while (currentElem->next != NULL)
        { // Die Liste wird durchlaufen und das Ende der Tabelle wird gefunden
            currentElem = currentElem->next;
        }
        currentElem->next = newPoint; // Der neue Datenzeiger wird auf den "next" des aktuellen Zeigers gesetzt
    }
}

// Definition of function print a list
void printList(Point *headOfList)
{
    Point *currentElem = headOfList;
    if (currentElem) // Feststellen, ob die Liste leer ist
    {
        while (currentElem != NULL) // Feststellen, ob der Durchlauf abgeschlossen ist
        {
            printf("x: %.2f, y: %.2f\n", currentElem->x, currentElem->y);
            currentElem = currentElem->next;
        }
        printf("EOL\n"); // Zeigt das Ende einer Liste an
    }
    else
    {
        printf("Dies ist eine leere Liste!");
    }
}

void freeList(Point **headOfList)
{
    Point *currentElem = *headOfList;
    while (currentElem == NULL)
    {
        currentElem = *headOfList;
        *headOfList = (*headOfList)->next;
        free(currentElem);
    }
}
