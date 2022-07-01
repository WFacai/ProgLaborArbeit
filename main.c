#include <stdio.h>

#include "afg1.h"
#include "afg2.h"
#include "afg3.h"
#include "afg4.h"
#include "afg5.h"

void Aufgabe1()
{
    // Zeiger auf Listenkopf
    Point *List1 = NULL;
    // Geben Sie die Informationen in die Liste ein
    append(&List1, 1.3, 2.3);
    append(&List1, 2.4, 4.5);
    append(&List1, 5.01, 6.3);
    append(&List1, 1.09, 6);
    append(&List1, 2.21, 2.6);
    printList(List1);
}

void Aufgabe2()
{
    // Zeiger auf Listenkopf
    Point *List2 = NULL;
    while (1)
    {
        int flag = 0;
        double x, y;
        // Eine Operation anfordern
        printf("\nOperation (1: Eingeben, 2: Loeschen, 3: Ende)?");
        scanf("%d", &flag); // Operations flag
        switch (flag)
        {
        case 1: // eingeben
            add(&List2, x, y);
            break;
        case 2: // loeschen
            delLast(&List2);
            break;
        case 3: // ende
            printf("\nAde.\n");
            return;
            break;
        }
    }
}

void Aufgabe3()
{
    // Zeiger auf Listenkopf
    Person *List3 = NULL;
    // Geben Sie die Informationen in die Liste ein
    insert(&List3, "Anton", 21, 1.82);
    insert(&List3, "Berta", 24, 1.74);
    insert(&List3, "Caesar", 20, 1.95);
    insert(&List3, "Dorothea", 21, 1.72);
    insert(&List3, "Emil", 21, 1.76);
    insert(&List3, "Frida", 29, 1.69);
    // Anzeige von Informationen in Listen
    printpList(List3);
}

void Aufgabe4()
{
    // Zeiger auf Listenkopf
    Person *List4 = NULL;
    // Geben Sie die Informationen in die Liste ein
    insert(&List4, "Anton", 21, 1.82);
    insert(&List4, "Berta", 24, 1.74);
    insert(&List4, "Caesar", 20, 1.95);
    insert(&List4, "Dorothea", 21, 1.72);
    insert(&List4, "Emil", 21, 1.76);
    insert(&List4, "Frida", 29, 1.69);
    // Um das Vorhandensein von minderjährigen Babys zu vermeiden,
    // ist der Standardwert für das Alter -1 und der Standardwert für die Größe 0
    pfind(List4, "Emil", -1, 0);   // eine Person mit Namen "Emil"
    pfind(List4, NULL, 24, 0);     // eine mit dem Alter 24
    pfind(List4, NULL, -1, 1.95);  // eine mit der Größe 1,95m
    pfind(List4, "Emilie", -1, 0); // und eine mit dem Namen "Emilie"
    // Löschen die Person mit dem Namen "Caesar" aus der Liste
    pdelete(&List4, "Caesar", -1, 0);
    // geben die verbleibende Liste danach aus
    printf("\n");
    printpList(List4);
}

void Aufgabe5()
{
}

void Aufgabe6()
{
}

void Aufgabe7()
{
}

int main()
{
    int Aufgabe;
    while (1)
    {
        printf("\nAuswahl der Aufgaben: (0 ist ende)");
        scanf("%i", &Aufgabe);
        switch (Aufgabe)
        {
        case 1:
            Aufgabe1();
            break;
        case 2:
            Aufgabe2();
            break;
        case 3:
            Aufgabe3();
            break;
        case 4:
            Aufgabe4();
            break;
        case 5:
            Aufgabe5();
            break;
        case 6:
            Aufgabe6();
            break;
        case 7:
            Aufgabe7();
            break;
        case 0:
            return 0;
            break;
        }
    }
}
