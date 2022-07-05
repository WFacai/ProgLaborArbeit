#include <stdio.h>
#include <stdlib.h>

#include "afg3.h"

// Definition of function insert and sort up
void insert(Person **headOfList, char *name, int age, float size)
{
    Person *currentPerson = *headOfList; // Ein temporärer Zeiger wird erstellt
    // Listenelement allozieren
    Person *newPerson = (Person *)malloc(sizeof(Person));
    newPerson->name = name; // Personaldaten zuweisen
    newPerson->age = age;
    newPerson->size = size;
    newPerson->next = NULL;    // Nullzeiger: Markiert Ende der Liste (Zero pointer: Marks end of list)
    if (currentPerson == NULL) // Falls Liste leer: Listenkopf erzeugen
    {
        *headOfList = newPerson;
    }
    else // Kein leere Liste also:
    {
        Person *prevPerson = NULL;
        Person *tempPerson = currentPerson;
        int flag = 0; // Markierungssymbol, ob neue Daten eingefügt wurden
        while (!flag) // Die Liste wird durchlaufen und das Ende der Tabelle wird gefunden
        {
            tempPerson = currentPerson;
            // Sortiert
            if (newPerson->age < currentPerson->age)
            { // Ist das Alter der hinzuzufügenden Person kleiner als das der aktuellen Person?
                if (prevPerson)
                {
                    prevPerson->next = newPerson;
                    newPerson->next = currentPerson;
                }
                else
                { // Wenn die hinzuzufügende Person die erste sein soll
                    *headOfList = newPerson;
                    newPerson->next = tempPerson;
                }
                flag = 1; // Neue Person wurde eingefügt
            }
            else if (newPerson->age == currentPerson->age && newPerson->size < currentPerson->size)
            { // Ist das Alter der hinzuzufügenden Person gleich dem der vorherigen Person?
                if (prevPerson)
                {
                    prevPerson->next = newPerson;
                    newPerson->next = currentPerson;
                }
                else
                { // Wenn die hinzuzufügende Person die erste sein soll
                    currentPerson = newPerson;
                    newPerson->next = tempPerson;
                }
                flag = 1; // Neue Person wurde eingefügt
            }
            if (!flag)
            {
                if (currentPerson->next == NULL)     // Nach der Durchfahrt wird die neue Person,
                {                                    // deren Alter nicht kleiner oder gleich ist,
                    currentPerson->next = newPerson; // an das Ende der Liste gesetzt.
                    flag = 1;                        // Neue Person wurde eingefügt
                }
                else
                {
                    prevPerson = currentPerson;          // Der Zeiger der vorletzten Person wird gespeichert
                    currentPerson = currentPerson->next; // Aktualisieren des aktuellen Zeigers
                }
            }
        }
    }
}

// Definition of function printpList
void printpList(Person *headOfList)
{
    Person *currentPerson = headOfList;
    if (currentPerson) // Feststellen, ob die Liste leer ist
    {
        while (currentPerson != NULL) // Feststellen, ob der Durchlauf abgeschlossen ist
        {
            printf("Name: %s\nAlter: %i\nGroesse: %.2f\n\n", currentPerson->name, currentPerson->age, currentPerson->size);
            currentPerson = currentPerson->next;
        }
        printf("EOL\n"); // Zeigt das Ende einer Liste an
    }
    else
    {
        printf("Dies ist eine leere Liste!");
    }
}

void freepList(Person **headOfList)
{
    Person *currentElem = *headOfList;
    while (currentElem == NULL)
    {
        currentElem = *headOfList;
        *headOfList = (*headOfList)->next;
        free(currentElem);
    }
}
