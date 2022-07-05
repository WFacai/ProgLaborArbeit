#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "afg7.h"

// Erstellen eines dynamischen Puffers
void initRingbufferOdo(struct RingbufferOdo *rbOdo, int length)
{
    rbOdo->Felds = (struct Odometry *)malloc(length * sizeof(struct Odometry)); // Speicher für Array-Zeiger zuweisen
    rbOdo->Anfang = 0;
    rbOdo->Ende = 0;
    rbOdo->length = length;
}

// Löschen des dynamischen Felds des Ringpuffers
void eraseRingbufferOdo(struct RingbufferOdo *rbOdo)
{
    free(rbOdo->Felds); // Freigeben des Speichers, auf den der Zeiger des Felds zeigt
    free(rbOdo);        // Freigeben des Speichers, auf den der Zeiger des buffer zeigt
    rbOdo = NULL;       // Der Zeiger des Warteschlangen-Arrays wird auf NULL umgeleitet um zu vermeiden, dass er zu einem Jokerzeiger wird
}

// Schreiben in Daten
void pushRingbufferOdo(struct RingbufferOdo *rbOdo, struct Odometry *odoVal)
{
    rbOdo->Felds[rbOdo->Ende] = *odoVal;
    rbOdo->Ende = (rbOdo->Ende + 1) % rbOdo->length; // Der Endezeiger wird auf das nächste Position im queue verschoben.
}

// Daten auslesen
struct Odometry popRingbufferOdo(struct RingbufferOdo *rbOdo)
{
    struct Odometry val;
    val = rbOdo->Felds[rbOdo->Anfang];                   // FIFO
    rbOdo->Anfang = (rbOdo->Anfang + 1) % rbOdo->length; // Der Anfangszeiger wird auf das nächste Position im queue verschoben.
    return val;
}

// Rückgabe der zeitlich nächstgelegenen Daten
struct Odometry *getTemporalClosestSample(struct RingbufferOdo *rbOdo, float time)
{
    static struct Odometry *Sample;
    //i ist temporäre Durchlauf-Zeiger
    int i = rbOdo->Anfang;
    float Diff;
    while (i != rbOdo->Ende)
    {
        // Durchlaufen und den nächstgelegenen Wert finden
        Sample = &rbOdo->Felds[i];
        // Da das Zeitintervall 0,2 ist, ist ein Unterschied von weniger als 0,1 der nächstliegende Sample.
        Diff = fabs(Sample->t - time);
        if (Diff <= 0.10)
        {
            return Sample;
        }
        i = (i + 1) % rbOdo->length; // Index i plus Eins
    }
    // Befindet sich nicht in der Mitte des Puffers, bestimmen, welche Seite näher an einer der beiden Seiten ist
    if (fabs((rbOdo->Felds[rbOdo->Anfang].t) - time) <= fabs((rbOdo->Felds[rbOdo->Ende-1].t) - time))
    {
        Sample = &rbOdo->Felds[rbOdo->Anfang];
    }
    else
    {
        Sample = &rbOdo->Felds[rbOdo->Ende-1];
    }
    return Sample;
}
