#include <stdio.h>
#include <stdlib.h>

#include "afg1.h"
#include "afg2.h"
#include "afg3.h"
#include "afg4.h"
#include "afg5.h"
#include "afg6.h"
#include "afg7.h"
#include "odometry.h"
#include "trajectory.h"

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
    freeList(&List1);
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
    freeList(&List2);
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
    freepList(&List3);
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
    freepList(&List4);
}

void Aufgabe5()
{
    struct Stack *stack = initStack(); //"Stackstruktur" allozieren
    for (int val = 0; val < 4; val++)  // Stapeln 0…3
    {
        stack->pushStack(stack, val);
    }
    outputwholeStack(stack);
}

void Aufgabe6()
{
    struct Ringbuffer *Puffer1 = (struct Ringbuffer *)malloc(sizeof(struct Ringbuffer));
    // Länge des Ringpuffer ist
    printf("Eingaben: Hello World!\n");
    int len = 20;
    printf("Laenge des Ringpuffer ist %i\nLesen aus: ", len);
    init(Puffer1, len); // initialisieren Puffer1
    char contents[] = "Hello World!";
    for (int i = 0; i < (int)sizeof(contents) - 1; i++)
    {
        push(Puffer1, contents[i]);
    }
    for (int i = 0; i < (int)sizeof(contents) - 1 && i < len; i++)
    {
        // Wenn der Eingabe-String überläuft, stoppt die Ausgabe am Ende des Puffers
        printf("%c", pop(Puffer1));
    }
    erase(Puffer1); // Ringpufferspeicher löschen
    // Länge des Ringpuffer erneuen.
    len = 8;
    printf("\nLaenge des Ringpuffer ist %i\nLesen aus: ", len);
    init(Puffer1, len); // initialisieren Puffer1
    for (int i = 0; i < (int)sizeof(contents) - 1; i++)
    {
        push(Puffer1, contents[i]);
    }
    for (int i = 0; i < (int)sizeof(contents) - 1 && i < len; i++) //
    {
        // Wenn der Eingabe-String überläuft, stoppt die Ausgabe am Ende des Puffers
        printf("%c", pop(Puffer1));
    }
    erase(Puffer1); // Ringpufferspeicher löschen
}

void Aufgabe7()
{
    // Zuweisung von Speicher an den Zeiger rBuffer, der auf die Struktur RingbufferOdo zeigt
    struct RingbufferOdo *rBuffer = (struct RingbufferOdo *)malloc(sizeof(struct RingbufferOdo));
    // Initialisieren die Pufferstruktur, Pufferlänge ist 20
    int length = 20;
    initRingbufferOdo(rBuffer, length);
    for (int i = 0; i < LEN; i++)
    {
        struct Odometry odo;
        odo.t = tra_t[i];
        odo.x = tra_x[i];
        odo.y = tra_y[i];
        odo.v = tra_v[i];
        odo.phi = tra_phi[i];
        // Schreiben der Odometriedaten bei t
        pushRingbufferOdo(rBuffer, &odo);
        // Garantiert immer Odometriedaten für die nächsten 20 geschriebenen Odometry
        // Das Schreiben eines Odometry liefert eines Odometry zur Ausführung
        if (i >= 19)//i=19 bedeutet, dass 20 Elemente geschrieben wurden
        {
            // Nehmen die ältesten Daten und senden sie an den Fahrzeugcomputer
            // Der Fahrzeugcomputer kann diese Daten zur Verarbeitung nutzen
            struct Odometry popOdo = popRingbufferOdo(rBuffer);
            printOdo(&popOdo); // Drucken die ausgelesenen Daten aus
        }
    }
    printf("Oben sind die Daten im Pop-up-Puffer zu sehen\n");

    // testen pop
    printf("\nTesten, ob das Pop-up erfolgreich ist");
    struct Odometry testOdo = popRingbufferOdo(rBuffer);
    printf("\nLesen und Zurueckgen eines Odometry Datensamples:");
    printOdo(&testOdo);
    printf("Nach dem Pop, die Anfang Odo: Odo t: %.2f x: %.2f y: %.2f v: %.2f phi: %.2f \n",
           rBuffer->Felds[rBuffer->Anfang].t, rBuffer->Felds[rBuffer->Anfang].x,
           rBuffer->Felds[rBuffer->Anfang].y, rBuffer->Felds[rBuffer->Anfang].v,
           rBuffer->Felds[rBuffer->Anfang].phi);
    printf("\nDas aelteste Odometry im Puffer ist zu diesem Zeitpunkt: %.2f", rBuffer->Felds[rBuffer->Anfang].t);
    printf("\nDas neueste Odometry: %.2f",rBuffer->Felds[rBuffer->Ende-1].t);

    // testen getTemporalClosestSample. Finden die t=time nächstgelegenen Daten
    printf("\n\nTesten, ob das getTemporalClosestSample erfolgreich ist");
    float time;
    printf("\nWelchen Moment moechten Sie das Odometrt am naechsten finden?(Zwei Nachkommastellen)");
    scanf("%f",&time);
    struct Odometry *TCOdo = getTemporalClosestSample(rBuffer, time); // erhalten TemporalClosestSample
    printf("\nNahestehende OdoSample zu t=%.2f :", time);
    printOdo(TCOdo);
    eraseRingbufferOdo(rBuffer); // Ringpufferspeicher loeschen
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
