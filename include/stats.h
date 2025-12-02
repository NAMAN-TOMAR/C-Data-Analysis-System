//
// stats.h - Prototypes for analysis functions
// Includes Statistics struct - I added IQR for extra credit.
// (I might add more metrics later if time allows, like skewness/kurtosis.)
//

#ifndef STATS_H
#define STATS_H

#include "data_input.h"  // For Dataset (stats depends on whatever data_input provides)

// Core container for all summary statistics.
// I packed everything into one struct so it's easier to return from functions.
// The q1/q2/q3 fields follow typical quartile definitions; iqr = q3 - q1.
typedef struct {
    double mean, median, mode,
           std_deviation, variance,
           min, max, range,
           q1, q2, q3, iqr;
} Statistics;

// Main menu for all statistical tools — kept separate to avoid clutter in main.c
void statistical_analysis_menu(void);

// Calculates descriptive stats for a given dataset
// (Most of the heavy lifting happens here: mean, std, quartiles, etc.)
Statistics calculate_descriptive_stats(Dataset *dataset);

// User-driven correlation tool — selects variables and prints results
void correlation_analysis(void);

// Simple regression interface — calls underlying math helpers
void regression_analysis(void);

// Core correlation calculation
double calculate_correlation(double x[], double y[], int n);

// Prints stats in a nice, readable format
void print_statistics(Statistics stats, char *name);

// Writes a summary to file or console (depending on implementation)
void export_summary(void);

// Viz and info functions...
// (Left vague on purpose — still figuring out which visual tools belong here.)

#endif // STATS_H

