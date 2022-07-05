#include <stdio.h>
#include <stdlib.h>

#include "afg4.h"
#include "afg3.h"

Person *pfind(Person *headOfList, char *name, int age, float size)
{
    Person *currentPerson = headOfList; // Ein temporärer Zeiger wird erstellt
    if (name != NULL)
    {
        if (name != NULL) // Suche nach Namen, wenn name ist nicht NULL
        {
            while (currentPerson != NULL) // Durchqueren der Liste
            {
                if (currentPerson->name == name)
                { // wenn die Übereinstimmung finden.Druckt die Informationen der Person
                    printf("Name: %s, Alter: %i, Groesse: %.2f\n", currentPerson->name, currentPerson->age, currentPerson->size);
                    return currentPerson; // Rückgabe des Zeigers
                }
                currentPerson = currentPerson->next; // Wechseln der aktuellen Person
            }
        }
    }
    else
    {
        currentPerson = headOfList; // Bewegen den Mauszeiger an den Kopf der Liste
        if (age >= 0)
        {
            while (currentPerson != NULL) // Durchqueren der Liste
            {                             // Suche nach age
                if (currentPerson->age == age)
                { // wenn die Übereinstimmung finden. Druckt die Informationen der Person
                    printf("Name: %s, Alter: %i, Groesse: %.2f\n", currentPerson->name, currentPerson->age, currentPerson->size);
                    return currentPerson; // Rückgabe des Zeigers
                }
                currentPerson = currentPerson->next; // Wechseln der aktuellen Person
            }
        }
        else if (size > 0)
        {
            currentPerson = headOfList; // Bewegen den Mauszeiger an den Kopf der Liste
            {
                while (currentPerson != NULL) // Durchqueren der Liste
                {                             // Suche nach size
                    if (currentPerson->size == size)
                    { // wenn die Übereinstimmung finden.Druckt die Informationen der Person
                        printf("Name: %s, Alter: %i, Groesse: %.2f\n", currentPerson->name, currentPerson->age, currentPerson->size);
                        return currentPerson; // Rückgabe des Zeigers
                    }
                    currentPerson = currentPerson->next; // Wechseln der aktuellen Person
                }
            }
        }
    }
    if (name != NULL)
    {
        printf("%s wurde nicht gefunden\n", name);
    }
    else if (age >= 0)
    {
        printf("Der %i-Jährige wurde nicht gefunden\n", age);
    }
    else if (size > 0)
    {
        printf("%.2fm groß nicht gefunden\n", size);
    }
    return NULL;
}

int pdelete(Person **headOfList, char *name, int age, float size)
{
    // temporärer Zeiger wird erstellt
    Person *currentPerson = *headOfList;
    Person *prevPerson = NULL;
    if (*headOfList) // Feststellen, ob die Liste leer ist
    {
        if (name != NULL)
        {
            if (name != NULL) // Suche nach Namen, wenn name ist nicht NULL
            {
                while (currentPerson != NULL) // Durchqueren der Liste
                {
                    if (currentPerson->name == name)
                    { // wenn die Übereinstimmung finden
                        if (prevPerson != NULL)
                        {
                            free(prevPerson->next);                 // Speicher freigeben
                            prevPerson->next = currentPerson->next; // Personen löschen und die Liste aktualisieren
                        }
                        else // Wenn der Tabellenkopf gelöscht werden soll
                        {
                            free(*headOfList);
                            *headOfList = currentPerson->next;
                        }
                        return 1; // Gelöscht, Rückgabemarkierung
                    }
                    // Zeiger aktualisieren
                    prevPerson = currentPerson;
                    currentPerson = currentPerson->next;
                }
            }
        }
        else
        {
            // Zeiger aktualisieren
            currentPerson = *headOfList;
            prevPerson = NULL;
            if (age >= 0)
            {
                while (currentPerson != NULL) // Durchqueren der Liste
                {                             // Suche nach age
                    if (currentPerson->age == age)
                    { // wenn die Übereinstimmung finden
                        if (prevPerson)
                        {
                            free(prevPerson->next);                 // Speicher freigeben
                            prevPerson->next = currentPerson->next; // Personen löschen und die Liste aktualisieren
                        }
                        else // Wenn der Tabellenkopf gelöscht werden soll
                        {
                            free(*headOfList);
                            *headOfList = currentPerson->next;
                        }
                        return 1; // Gelöscht, Rückgabemarkierung
                    }
                    // Zeiger aktualisieren
                    prevPerson = currentPerson;
                    currentPerson = currentPerson->next;
                }
            }
            else if (size > 0)
            {
                currentPerson = *headOfList; // Bewegen den Mauszeiger an den Kopf der Liste
                {
                    while (currentPerson != NULL) // Durchqueren der Liste
                    {                             // Suche nach size
                        if (currentPerson->size == size)
                        { // wenn die Übereinstimmung finden
                            if (prevPerson)
                            {
                                free(prevPerson->next);                 // Speicher freigeben
                                prevPerson->next = currentPerson->next; // Personen löschen und die Liste aktualisieren
                            }
                            else // Wenn der Tabellenkopf gelöscht werden soll
                            {
                                free(*headOfList);
                                *headOfList = currentPerson->next;
                            }
                            return 1; // Gelöscht, Rückgabemarkierung
                        }
                        // Zeiger aktualisieren
                        prevPerson = currentPerson;
                        currentPerson = currentPerson->next;
                    }
                }
            }
        }
    }
    else // Wenn er bereits leer ist, wird eine Aufforderung
    {
        printf("Dies ist eine leere Liste!\n");
    }
    return 0;
}
