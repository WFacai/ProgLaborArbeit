#include "trajectory.h"

// here the definitions with realy memory
float tra_t[LEN] = {0.00, 0.20, 0.40, 0.60, 0.80, 1.00, 1.20, 1.40, 1.60, 1.80, 2.00, 2.20, 2.40, 2.60, 2.80, 3.00, 3.20, 3.40, 3.60, 3.80, 4.00, 4.20, 4.40, 4.60, 4.80, 5.00, 5.20, 5.40, 5.60, 5.80, 6.00, 6.20, 6.40, 6.60, 6.80, 7.00, 7.20, 7.40, 7.60, 7.80, 8.00, 8.20, 8.40, 8.60, 8.80, 9.00, 9.20, 9.40, 9.60, 9.80, 10.00, 10.20, 10.40, 10.60, 10.80, 11.00, 11.20, 11.40, 11.60, 11.80, 12.00, 12.20, 12.40, 12.60, 12.80, 13.00, 13.20, 13.40, 13.60, 13.80, 14.00, 14.20, 14.40, 14.60, 14.80, 15.00, 15.20, 15.40, 15.60, 15.80, 16.00, 16.20, 16.40, 16.60, 16.80, 17.00, 17.20, 17.40, 17.60, 17.80, 18.00, 18.20, 18.40, 18.60, 18.80, 19.00, 19.20, 19.40, 19.60, 19.80, 20.00, 20.20, 20.40, 20.60, 20.80, 21.00, 21.20, 21.40, 21.60, 21.80, 22.00, 22.20, 22.40, 22.60, 22.80, 23.00, 23.20, 23.40, 23.60, 23.80, 24.00, 24.20, 24.40, 24.60, 24.80, 25.00, 25.20, 25.40, 25.60, 25.80, 26.00, 26.20, 26.40, 26.60, 26.80, 27.00, 27.20, 27.40, 27.60, 27.80, 28.00, 28.20, 28.40, 28.60, 28.80, 29.00, 29.20, 29.40, 29.60, 29.80, 30.00, 30.20, 30.40, 30.60, 30.80, 31.00, 31.20, 31.40, 31.60, 31.80, 32.00, 32.20, 32.40, 32.60, 32.80, 33.00, 33.20, 33.40, 33.60, 33.80, 34.00, 34.20, 34.40, 34.60, 34.80, 35.00, 35.20, 35.40, 35.60, 35.80, 36.00, 36.20, 36.40, 36.60, 36.80, 37.00, 37.20, 37.40, 37.60, 37.80, 38.00, 38.20, 38.40, 38.60, 38.80, 39.00, 39.20, 39.40, 39.60, 39.80, 40.00, 40.20, 40.40, 40.60, 40.80, 41.00, 41.20, 41.40, 41.60, 41.80, 42.00, 42.20, 42.40};

float tra_x[LEN] = {0.00, 0.06, 0.42, 0.87, 1.38, 1.90, 2.44, 2.99, 3.52, 4.05, 4.60, 5.18, 5.76, 6.33, 6.93, 7.57, 8.26, 8.95, 9.64, 10.37, 11.15, 11.91, 12.69, 13.51, 14.35, 15.15, 15.93, 16.74, 17.56, 18.34, 19.10, 19.84, 20.56, 21.23, 21.84, 22.42, 22.97, 23.45, 23.86, 24.20, 24.46, 24.65, 24.76, 24.78, 24.71, 24.53, 24.29, 23.99, 23.62, 23.16, 22.64, 22.06, 21.41, 20.69, 19.99, 19.26, 18.48, 17.64, 16.78, 15.89, 14.97, 14.03, 13.08, 12.16, 11.28, 10.44, 9.65, 8.89, 8.14, 7.44, 6.80, 6.20, 5.62, 5.04, 4.52, 4.03, 3.55, 3.07, 2.62, 2.17, 1.72, 1.26, 0.82, 0.40, -0.04, -0.49, -0.93, -1.36, -1.80, -2.28, -2.74, -3.20, -3.70, -4.23, -4.75, -5.29, -5.83, -6.42, -7.06, -7.70, -8.35, -9.04, -9.79, -10.52, -11.29, -12.11, -12.97, -13.80, -14.62, -15.48, -16.37, -17.25, -18.11, -19.00, -19.90, -20.78, -21.67, -22.55, -23.42, -24.27, -25.08, -25.83, -26.52, -27.16, -27.73, -28.27, -28.72, -29.11, -29.42, -29.65, -29.81, -29.88, -29.87, -29.77, -29.58, -29.33, -29.04, -28.67, -28.22, -27.73, -27.18, -26.56, -25.94, -25.26, -24.53, -23.74, -22.94, -22.09, -21.19, -20.23, -19.31, -18.39, -17.43, -16.46, -15.46, -14.51, -13.58, -12.67, -11.79, -10.94, -10.11, -9.32, -8.59, -7.88, -7.18, -6.50, -5.86, -5.28, -4.71, -4.15, -3.60, -3.10, -2.63, -2.19, -1.80, -1.43, -1.09, -0.77, -0.48, -0.21, 0.03, 0.25, 0.45, 0.63, 0.79, 0.92, 1.04, 1.13, 1.20, 1.26, 1.29, 1.30, 1.29, 1.27, 1.22, 1.15, 1.06, 0.95, 0.82, 0.68, 0.55, 0.44, 0.33, 0.24, 0.16, 0.10, 0.05, 0.00, -0.03, -0.06, -0.08, -0.10, -0.12};

float tra_y[LEN] = {0.00, -0.88, -1.68, -2.46, -3.14, -3.77, -4.39, -5.02, -5.62, -6.18, -6.74, -7.29, -7.80, -8.25, -8.66, -9.03, -9.34, -9.59, -9.77, -9.90, -9.95, -9.95, -9.89, -9.76, -9.57, -9.35, -9.09, -8.78, -8.40, -8.00, -7.56, -7.09, -6.57, -6.04, -5.50, -4.92, -4.28, -3.65, -3.01, -2.32, -1.59, -0.88, -0.19, 0.47, 1.14, 1.83, 2.47, 3.08, 3.69, 4.30, 4.88, 5.45, 6.01, 6.55, 7.04, 7.50, 7.94, 8.35, 8.71, 9.02, 9.28, 9.48, 9.61, 9.71, 9.72, 9.69, 9.58, 9.40, 9.13, 8.84, 8.49, 8.09, 7.64, 7.11, 6.58, 6.03, 5.44, 4.79, 4.16, 3.50, 2.80, 2.05, 1.34, 0.64, -0.08, -0.82, -1.53, -2.21, -2.89, -3.58, -4.24, -4.86, -5.48, -6.09, -6.66, -7.18, -7.67, -8.14, -8.57, -8.95, -9.28, -9.56, -9.80, -9.98, -10.11, -10.19, -10.21, -10.20, -10.15, -10.06, -9.91, -9.73, -9.52, -9.27, -8.94, -8.61, -8.23, -7.81, -7.34, -6.83, -6.33, -5.80, -5.27, -4.73, -4.16, -3.59, -3.02, -2.44, -1.85, -1.23, -0.62, -0.02, 0.56, 1.17, 1.80, 2.37, 2.92, 3.47, 4.02, 4.55, 5.07, 5.58, 6.06, 6.53, 6.98, 7.42, 7.83, 8.23, 8.58, 8.92, 9.22, 9.48, 9.70, 9.87, 9.99, 10.09, 10.12, 10.09, 10.01, 9.87, 9.67, 9.46, 9.20, 8.88, 8.48, 8.01, 7.54, 7.04, 6.49, 5.90, 5.25, 4.62, 3.99, 3.39, 2.80, 2.25, 1.73, 1.23, 0.77, 0.35, -0.05, -0.41, -0.74, -1.04, -1.30, -1.53, -1.72, -1.88, -2.00, -2.09, -2.15, -2.17, -2.16, -2.11, -2.03, -1.91, -1.76, -1.58, -1.36, -1.13, -0.91, -0.72, -0.55, -0.40, -0.27, -0.16, -0.07, 0.00, 0.06, 0.11, 0.14, 0.17, 0.20};

float tra_phi[LEN] = {-1.50, -1.15, -1.05, -0.93, -0.88, -0.86, -0.85, -0.84, -0.83, -0.80, -0.75, -0.72, -0.66, -0.61, -0.52, -0.42, -0.34, -0.27, -0.17, -0.07, 0.00, 0.08, 0.15, 0.23, 0.26, 0.32, 0.37, 0.43, 0.48, 0.52, 0.57, 0.63, 0.67, 0.72, 0.79, 0.87, 0.91, 1.00, 1.11, 1.24, 1.31, 1.41, 1.53, 1.68, 1.83, 1.93, 2.02, 2.12, 2.23, 2.29, 2.36, 2.43, 2.50, 2.53, 2.58, 2.63, 2.69, 2.75, 2.80, 2.86, 2.93, 3.01, 3.04, 3.12, 3.18, 3.27, 3.38, 3.48, 3.55, 3.64, 3.72, 3.80, 3.88, 3.94, 3.98, 4.03, 4.07, 4.10, 4.12, 4.14, 4.16, 4.16, 4.17, 4.17, 4.16, 4.16, 4.15, 4.13, 4.11, 4.10, 4.07, 4.04, 3.99, 3.97, 3.92, 3.87, 3.81, 3.74, 3.67, 3.61, 3.53, 3.45, 3.38, 3.31, 3.24, 3.17, 3.13, 3.08, 3.03, 2.98, 2.94, 2.90, 2.86, 2.79, 2.78, 2.74, 2.70, 2.65, 2.60, 2.58, 2.53, 2.48, 2.44, 2.36, 2.33, 2.24, 2.16, 2.05, 1.92, 1.83, 1.70, 1.55, 1.41, 1.27, 1.17, 1.08, 0.98, 0.89, 0.82, 0.76, 0.69, 0.65, 0.60, 0.56, 0.51, 0.48, 0.44, 0.37, 0.34, 0.32, 0.27, 0.23, 0.17, 0.12, 0.10, 0.04, -0.03, -0.10, -0.16, -0.23, -0.27, -0.34, -0.43, -0.52, -0.60, -0.64, -0.70, -0.76, -0.82, -0.87, -0.90, -0.92, -0.95, -0.97, -0.99, -0.99, -1.00, -1.01, -1.01, -1.02, -1.02, -1.02, -1.03, -1.03, -1.04, -1.04, -1.04, -1.04, -1.04, -1.04, -1.04, -1.04, -1.04, -1.04, -1.04, -1.03, -1.03, -1.03, -1.03, -1.03, -1.03, -1.03, -1.03, -1.03, -1.03, -1.03, -1.03, -1.03, -1.03, -1.03, -1.03, -1.03, -1.03};

float tra_v[LEN] = {4.40, 4.40, 4.48, 4.28, 4.08, 4.10, 4.20, 4.00, 3.86, 3.92, 4.02, 3.82, 3.68, 3.60, 3.68, 3.82, 3.64, 3.57, 3.72, 3.92, 3.78, 3.93, 4.13, 4.33, 4.13, 4.14, 4.32, 4.52, 4.42, 4.36, 4.36, 4.46, 4.26, 4.11, 4.12, 4.18, 3.98, 3.82, 3.83, 3.88, 3.68, 3.48, 3.28, 3.38, 3.58, 3.41, 3.39, 3.59, 3.79, 3.88, 4.08, 4.28, 4.48, 4.30, 4.32, 4.46, 4.66, 4.66, 4.73, 4.78, 4.80, 4.80, 4.60, 4.40, 4.20, 4.00, 3.93, 3.98, 3.78, 3.64, 3.59, 3.71, 3.89, 3.73, 3.68, 3.83, 4.03, 3.88, 3.99, 4.18, 4.38, 4.18, 4.12, 4.18, 4.36, 4.16, 4.00, 4.08, 4.20, 4.00, 3.88, 3.95, 4.06, 3.86, 3.74, 3.66, 3.75, 3.89, 3.70, 3.62, 3.74, 3.93, 3.78, 3.91, 4.11, 4.31, 4.11, 4.13, 4.32, 4.52, 4.47, 4.45, 4.61, 4.81, 4.71, 4.80, 4.89, 4.94, 4.97, 4.77, 4.57, 4.37, 4.17, 4.07, 3.87, 3.67, 3.47, 3.33, 3.35, 3.15, 3.00, 2.95, 3.08, 3.28, 3.12, 3.11, 3.31, 3.51, 3.61, 3.81, 4.01, 3.94, 4.11, 4.31, 4.51, 4.51, 4.66, 4.86, 5.06, 4.86, 4.80, 4.88, 4.96, 5.01, 4.81, 4.61, 4.58, 4.43, 4.31, 4.26, 4.06, 3.86, 3.91, 4.02, 4.16, 3.96, 3.85, 3.94, 4.09, 4.23, 4.03, 3.92, 3.72, 3.52, 3.32, 3.12, 2.92, 2.72, 2.52, 2.32, 2.12, 1.92, 1.72, 1.52, 1.32, 1.12, 0.92, 0.72, 0.52, 0.32, 0.12, -0.08, -0.28, -0.48, -0.68, -0.88, -1.08, -1.28, -1.37, -1.25, -1.11, -0.99, -0.88, -0.76, -0.63, -0.52, -0.42, -0.34, -0.27, -0.22, -0.18, -0.14, -0.12};
