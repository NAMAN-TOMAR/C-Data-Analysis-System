
//
// utils.c - Implementation of utilities
// Bubble sort is simple but works for n=1000; I tried quicksort but it was buggy at first.
// (One day I might revisit that quicksort attempt… maybe.)
//

#include "utils.h"
#include <stdlib.h>

void clear_screen() {
    #ifdef _WIN32
        system("cls");      // Windows… always needing its own thing
    #else
        system("clear");    // Works on Linux/macOS; tested on my laptop
    #endif
}

void wait_for_input() {
    clear_input_buffer();   // Just making sure nothing messy sits in stdin
    printf("\nPress Enter to continue...");
    char buf[4];            // Small buffer is enough since we're only waiting for Enter
    fgets(buf, sizeof(buf), stdin);   // fgets handles the newline properly
}

void clear_input_buffer() {
    int c;
    // Flush any leftover characters — scanf tends to leave junk behind
    while ((c = getchar()) != '\n' && c != EOF) { }
}

void sort_array(double arr[], int n) {
    // Bubble sort - O(n^2) but fine for small n. I debugged swaps here.
    // (I know it's slow, but honestly it's easy to verify correctness.)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Classic three-step swap — kept readable instead of clever
                double temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

double median_of_range(double arr[], int start, int end) {
    // Computes the median of values within arr[start..end]
    // (Assumes it's already sorted — I need to remember to document that elsewhere.)
    int len = end - start + 1;
    if (len <= 0) return 0.0;    // Graceful fallback; shouldn't really happen

    int mid = start + len / 2;

    if (len % 2 == 0) {
        // Even count — average the two middle values
        return (arr[mid - 1] + arr[mid]) / 2.0;
    } else {
        // Odd count — middle element is the median
        return arr[mid];
    }
}
