#include <stdio.h>
#include "odometry.h"

// Definition of function print odo
void printOdo(struct Odometry *odo)
{
    printf("Odo t: %.2f x: %.2f y: %.2f v: %.2f phi: %.2f \n",
           odo->t, odo->x, odo->y, odo->v, odo->phi);
}
