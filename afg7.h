#ifndef AFG7_H
#define AFG7_H
#include "odometry.h"

struct RingbufferOdo
{
    struct Odometry *Felds; // Zeiger auf Feld
    int Anfang;             // Der Zeiger Anfang zeigt auf den Ringpuffer, der die erste
    int Ende;               // Der Zeiger Ende zeigt auf den Ringpuffer, der die letzte
    int length;             // Länge des Puffers
};

// Erstellen dynamischer Puffer und Initialisierung von Zeigern
void initRingbufferOdo(struct RingbufferOdo *rbOdo, int length);
// Löschen des dynamischen Felds des Ringpuffers
void eraseRingbufferOdo(struct RingbufferOdo *rbOdo);
// Schreiben in Daten
void pushRingbufferOdo(struct RingbufferOdo *rbOdo, struct Odometry *odoVal);
// Daten auslesen
struct Odometry popRingbufferOdo(struct RingbufferOdo *rbOdo);
// Rückgabe der zeitlich nächstgelegenen Daten
struct Odometry *getTemporalClosestSample(struct RingbufferOdo *rbOdo, float time);

#endif // AFG7_H
