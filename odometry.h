#ifndef ODOMETRY_H
#define ODOMETRY_H

// Decalaration of odometry data structure to
// store one sample of a bicycle model, see
// https://moodle-thu.de/mod/assign/view.php?id=116418
struct Odometry
{
    float t;   // time
    float x;   // x coordinate in [m]
    float y;   // y coordinate in [m]
    float v;   // velocity in [m/s]
    float phi; // yaw angle phi in [rad]
};

// Decalaration of function printOdo
// parameter odo is the Odometry structure we want to print out
void printOdo(struct Odometry *odo);

#endif // ODOMETRY_H
