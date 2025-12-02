//
// utils.h - Utility functions for screen/input handling
// I wrote these to make the program feel more professional.
// (Still thinking about whether some of these belong in separate files.)
//

#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <math.h>
#include <time.h>

// Clears the screen — nothing fancy, just keeps the UI from getting cluttered.
void clear_screen(void);

// Simple pause so the user can actually read the output before continuing.
// (I sometimes forget to call this and the screen flashes by too quickly.)
void wait_for_input(void);

// Gets rid of leftover characters when scanf misbehaves — super handy for invalid user input.
void clear_input_buffer(void);

// I added this sorting function mainly so I wouldn't have to rewrite it everywhere.
// Not the fastest thing in the world, but it does the job.
void sort_array(double arr[], int n);

// Computes the median of a subsection of an array.
// I ended up using this more than expected, so it made sense to keep it here.
double median_of_range(double arr[], int start, int end);

#ifndef M_PI
#define M_PI 3.14159265358979323846   // In case math.h doesn't define it (happened on one compiler)
#endif

#endif // UTILS_H

