#include <stdio.h>

#include "labor.h"
#include "odometry.h"
#include "trajectory.h"

void Aufgabe1()
{
    // Zeiger auf Listenkopf
    Point *List1 = NULL;
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
}

void Aufgabe4()
{
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
