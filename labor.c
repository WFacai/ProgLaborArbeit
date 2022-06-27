#include "labor.h"
#include <stdlib.h>
#include <stdio.h>

void append(Point **headOfList, double x, double y)
{
    Point *currentElem = *headOfList;
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
    { // Anderenfalls neues Element anfügen (Otherwise add new element)
        while (currentElem->next != NULL)
        {
            currentElem = currentElem->next;
        }
        currentElem->next = newPoint;
    }
}

void printList(Point *headOfList)
{
    Point *currentElem = headOfList;
    if (currentElem) // Feststellen, ob die Liste leer ist
    {
        while (currentElem != NULL)
        {
            printf("x: %.2f, y: %.2f\n", currentElem->x, currentElem->y);
            currentElem = currentElem->next;
        }
        printf("EOL\n");
    }
    else
    {
        printf("Dies ist eine leere Liste!");
    }
}

void add(Point **headOfList, double x, double y)
{
    // Eingabekoordinaten erhalten
    printf("\nBitte geben Sie ein Koordinatenpaar ein.\nx-Koordinate: ");
    scanf("%lf", &x);
    printf("y-Koordinate: ");
    scanf("%lf", &y);
    append(headOfList, x, y); // Eingabekoordinaten speichern
    printf("\nList:\n");       // Die Liste ausgegeben
    printList(*headOfList);
}

void delLast(Point **headOfList)
{
    if (headOfList) // Feststellen, ob die Liste leer ist
    {
        printf("Loesche letztes Listenelement");
        headOfList = headOfList->next; // Kopfzeiger aktualisieren
        if (headOfList)                // Feststellen, ob die Liste leer ist
        {
            printList(headOfList); // Ja, um die Liste anzuzeigen
        }
        else
        {
            printf("Dies ist eine leere Liste!"); // Wenn nicht, wird angezeigt
        }
    }
    else // Wenn er bereits leer ist, wird eine Aufforderung
    {
        printf("Dies ist bereits eine leere Liste!");
    }
}
