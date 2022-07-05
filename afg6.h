#ifndef AFG6_H
#define AFG6_H

struct Ringbuffer
{
    char *Feld; // Zeiger auf Feld
    int Anfang; // Der Zeiger Anfang zeigt auf den Ringpuffer, der die erste
    int Ende;   // Der Zeiger Ende zeigt auf den Ringpuffer, der die letzte
    int length; // Länge des Puffers
};

void init(struct Ringbuffer *buffer, int length); // Erstellen eines dynamischen Puffers
void erase(struct Ringbuffer *buffer);            // Löschen des dynamischen Felds des Ringpuffers.
void push(struct Ringbuffer *buffer, char val);   // Schreiben eines Zeichens an der Position Ende in den Ringpuffer
char pop(struct Ringbuffer *buffer);              // Lesen und Zurückgeben eines Zeichens von der Position Anfang.
void write(struct Ringbuffer *buffer, char Contents);

#endif // AFG6_H
