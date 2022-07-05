#ifndef AFG3_H
#define AFG3_H

// Decalaration of Person data structure
typedef struct _Person
{
    char *name;           // Name
    int age;              // Alter
    float size;           // Größe
    struct _Person *next; // Zeiger auf die nächste Struktur
} Person;

// Decalaration of function
void insert(Person **headOfList, char *name, int age, float size); // Neue Personen an der Liste bringen
void printpList(Person *headOfList);                               // Exportieren von Listendaten in die Konsole
void freepList(Person **headOfList);                // Allen Speicher freigeben

#endif // AFG3_H
