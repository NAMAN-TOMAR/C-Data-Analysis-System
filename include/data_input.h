//
// data_input.h - Data structures and prototypes for input
// I defined Dataset here as a struct - key course concept.
// (Kept the struct simple so it's easy to pass around.)
//

#ifndef DATA_INPUT_H
#define DATA_INPUT_H

#define MAX_DATA_POINTS 1000    // Probably more than enough for this project
#define MAX_VARIABLES 10        // Limiting to keep memory use predictable
#define MAX_STRING 100          // Just a safe buffer size for names

// Basic dataset container.
// I kept everything in fixed-size arrays — simpler than juggling malloc/free for now.
typedef struct {
    char variable_name[MAX_STRING];   // Name of the variable (user-defined)
    double data[MAX_DATA_POINTS];     // Actual numeric values
    int count;                        // How many items are currently stored
} Dataset;

// Global list of all datasets — yeah, globals aren't perfect but they simplify this project.
extern Dataset datasets[MAX_VARIABLES];
extern int dataset_count;             // Tracks how many datasets have been filled or created

// Main menu for interacting with the dataset system
void data_input_menu(void);

// Manual input routine — straightforward number entry
void manual_data_entry(void);

// File loader — reads values from a user-provided file
void load_from_file(void);

// Generates random or sample values (useful during testing)
void generate_sample_data(void);

// Displays all available datasets (names + basic information)
void display_datasets(void);

#endif // DATA_INPUT_H

