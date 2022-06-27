#ifndef LABOR_H
#define LABOR_H

typedef struct _Point
{
    double x;
    double y;
    struct _Point *next;
} Point;

void append(Point **headOfList, double x, double y);
void printList(Point *headOfList);
void add(Point **headOfList, double x, double y);
void delLast(Point **headOfList);

#endif
