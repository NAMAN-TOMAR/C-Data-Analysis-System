//
// main.c - Entry point for Data Analysis System
// Created by [Your Name] on 30-11-2025.
// I started with the main loop here, then modularized other parts.
// (I may reorganize the flow later if things get too tangled.)
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "utils.h"      // For clear_screen, wait_for_input (I always double-check this header)
#include "data_input.h" // For data_input_menu — moved here early on so main.c stays readable
#include "stats.h"      // For statistical_analysis_menu (and a few other bits I haven't cleaned up yet)

#define MAX_VARIABLES 10
extern Dataset datasets[MAX_VARIABLES];  // Global datasets from data_input.h — yeah, globals aren't ideal but fine for now
extern int dataset_count;                // Tracks how many datasets we currently have (note: might later store metadata too)

void display_main_menu(void);
void simple_visualization(void);  // Stub for viz menu
void ml_basics_info(void);        // Stub for ML menu
void export_summary(void); // From stats.h

void display_main_menu() {
    clear_screen();  // Keeps the interface clean — otherwise text piles up fast
    printf("\n=================== MAIN MENU ===================\n");
    printf("1. Data Input & Management\n");
    printf("2. Statistical Analysis\n");
    printf("3. Data Visualization\n");
    printf("4. Machine Learning Basics\n");
    printf("5. Export Results\n");
    printf("6. Exit\n");
    printf("================================================\n");
    
}

int main() {
    int choice;

    printf("=================================================\n");
    printf(" DATA ANALYSIS & STATISTICS SYSTEM v1.0\n");
    printf(" Professional Data Science Tool in C\n");
    printf("=================================================\n\n");

    // I added this seed for reproducibility in testing — might switch to a constant one during debugging sessions
    srand((unsigned int)time(NULL));

    do {
        display_main_menu();

        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            // Happens when someone types letters or random stuff — scanf really doesn't like that
            printf("\nInvalid input! Please enter a number.\n");
            clear_input_buffer();  // From utils.h — clears leftover characters so scanf works properly next time
            wait_for_input();
            continue;
        }

        switch (choice) {
            case 1:
                data_input_menu();  // Basic dataset operations
                break;

            case 2:
                statistical_analysis_menu();  // Stats stuff lives here
                break;

            case 3: {
                // Simple viz call — still debating if this belongs in its own module
                if (dataset_count == 0) {
                    printf("\nNo datasets for visualization!\n");
                } else {
                    // Placeholder — more detailed visualizations exist under stats for now
                    printf("Visualization stub: Use stats menu for histograms.\n");
                }
                break;
            }

            case 4:
                // ML basics are minimal for now — just pointing users to the relevant stats tools
                printf("\nML Basics: See stats for regression/correlation.\n");
                break;

            case 5:
                // Export functionality — lives in stats since summaries live there
                export_summary();
                break;

            case 6:
                printf("\nThank you for using Data Analysis System!\n");
                printf("Goodbye!\n");
                break;

            default:
                // Anything outside 1–6 ends up here — probably a typo from the user
                printf("\nInvalid choice! Please enter 1-6.\n");
        }

        if (choice != 6) {
            wait_for_input();  // Pause so the user can read the output before the screen clears
        }

    } while (choice != 6);

    return 0;
}

void display_main_menu() {
    clear_screen();  // Keeps the interface clean — otherwise text piles up fast
    printf("\n=================== MAIN MENU ===================\n");
    printf("1. Data Input & Management\n");
    printf("2. Statistical Analysis\n");
    printf("3. Data Visualization\n");
    printf("4. Machine Learning Basics\n");
    printf("5. Export Results\n");
    printf("6. Exit\n");
    printf("================================================\n");
    
}

// Stub implementations (integrate full from original code/stats.c)
void simple_visualization() {
    if (dataset_count == 0) {
        printf("\nNo datasets for visualization! Add data first.\n");
        wait_for_input();
        return;
    }
    printf("\n========== DATA VISUALIZATION ==========\n");
    // Call histogram function from stats.h (implement if not already)
    // For now: Placeholder - expand with ASCII histogram code from original
    printf("Visualization: ASCII Histogram (stub - see stats.c for full).\n");
    wait_for_input();
}

void ml_basics_info() {
    printf("\n======== MACHINE LEARNING BASICS ========\n");
    printf("This section demonstrates basic ML concepts:\n");
    printf("1. DATA PREPROCESSING: Cleaning, normalization.\n");
    printf("2. DESCRIPTIVE ANALYTICS: Stats summaries.\n");
    printf("3. PREDICTIVE MODELING: Regression (see analysis menu).\n");
    printf("Note: Foundations in C; advanced needs libs like TensorFlow.\n");
    wait_for_input();
}
