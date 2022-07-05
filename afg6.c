#include <stdio.h>
#include <stdlib.h>

#include "afg6.h"

// Erstellen eines dynamischen Puffers
void init(struct Ringbuffer *buffer, int length)
{
    buffer->Feld = (char *)malloc(length * sizeof(char)); // Speicher für Array-Zeiger zuweisen
    buffer->Anfang = 0;
    buffer->Ende = 0;
    buffer->length = length;
}

// Löschen des dynamischen Felds des Ringpuffers.
void erase(struct Ringbuffer *buffer)
{
    free(buffer->Feld); // Freigeben des Speichers, auf den der Zeiger des Feld zeigt
    free(buffer);       // Freigeben des Speichers, auf den der Zeiger des buffer zeigt
    buffer = NULL;      // Der Zeiger des Warteschlangen-Arrays wird auf NULL umgeleitet
                        // um zu vermeiden, dass er zu einem Jokerzeiger wird
}

// Schreiben eines Zeichens an der Position Ende in den Ringpuffer
void push(struct Ringbuffer *buffer, char val)
{
    buffer->Feld[buffer->Ende] = val;
    buffer->Ende = (buffer->Ende + 1) % buffer->length; // Der Endezeiger wird auf das nächste Position im queue verschoben.
}

// Lesen und Zurückgeben eines Zeichens von der Position Anfang
char pop(struct Ringbuffer *buffer)
{
    if(buffer->Ende!=buffer->Anfang)
    {
        char val;
        val = buffer->Feld[buffer->Anfang];                     // FIFO
        buffer->Anfang = (buffer->Anfang + 1) % buffer->length; // Der Anfangszeiger wird auf das nächste Position im queue verschoben.
        return val;
    }
    else
    {
        printf("\n bereits leer!\n");
        return '\n';
    }
}
