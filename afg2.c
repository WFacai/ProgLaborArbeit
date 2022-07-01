#include <stdlib.h>
#include <stdio.h>

#include "afg2.h"
#include "afg1.h"

// Definition of function ask, then add a point to the last of Liste
void add(Point **headOfList, double x, double y)
{
    // Eingabekoordinaten erhalten
    printf("\nBitte geben Sie ein Koordinatenpaar ein.\nx-Koordinate: ");
    scanf("%lf", &x);
    printf("y-Koordinate: ");
    scanf("%lf", &y);
    append(headOfList, x, y); // Eingabekoordinaten speichern
    printf("\nList:\n");      // Die Liste ausgegeben
    printList(*headOfList);
}

// Definition of function delete the last point of list, then print out
void delLast(Point **headOfList)
{
    Point *chkPtr = *headOfList; // Ein temporärer Zeiger wird erstellt
    if (*headOfList)             // Feststellen, ob die Liste leer ist
    {
        if (chkPtr->next == NULL) // Spezialfall: nur ein Punkt
        {
            *headOfList = NULL; // Listenkopf löschen
        }
        else
        {
            while (chkPtr->next->next != NULL) // Durchlaufen der Liste
            {
                chkPtr = chkPtr->next; // Speichern des Zeigers auf den Punkt nach dem Offset
            }
            free(chkPtr->next);  // Speicher freigeben
            chkPtr->next = NULL; // Löschen des letzten Punktes
        }
        printf("\nLoesche letztes Listenelement\n");
        printf("\nList:\n"); // Die Liste ausgegeben
        printList(*headOfList);
    }
    else // Wenn er bereits leer ist, wird eine Aufforderung
    {
        printf("Dies ist bereits eine leere Liste!\n");
    }
}
