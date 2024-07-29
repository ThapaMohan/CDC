#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 10
// Function prototypes
void findFirst(char, int, int);
void addToResultSet(char);
// Global variables
int numOfProductions;
char productionSet[MAX][MAX];
char first[MAX];
int firstCount;
// Main function
int main() {
    int i;
    char choice;
    char c, ch;
    printf("Mohan Thapa Mashrangi\n");
    printf("Enter the number of productions: ");
    scanf("%d", &numOfProductions);

    printf("Enter the productions (e.g., S=ABc, A=aB, etc.):\n");
    for (i = 0; i < numOfProductions; i++) {
        scanf("%s", productionSet[i]);
    }

    do {
        firstCount = 0; // Initialize first count
        printf("Enter the symbol to find the first set: ");
        scanf(" %c", &c);
        findFirst(c, 0, 0);
        
        printf("First(%c) = { ", c);
        for (i = 0; i < firstCount; i++) {
            printf("%c ", first[i]);
        }
        printf("}\n");

        printf("Do you want to find first of another symbol? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    return 0;
}

// Function to find the First set
void findFirst(char c, int q1, int q2) {
    int j;

    // If c is a terminal, add it to the first set
    if (!(isupper(c))) {
        addToResultSet(c);
        return;
    }

    // Iterate through all productions
    for (j = 0; j < numOfProductions; j++) {
        if (productionSet[j][0] == c) {
            if (productionSet[j][2] == '#') {
                if (productionSet[q1][q2] == '\0')
                    addToResultSet('#');
                else if (productionSet[q1][q2] != '\0' && (q1 != 0 || q2 != 0))
                    findFirst(productionSet[q1][q2], q1, (q2 + 1));
                else
                    addToResultSet('#');
            } else if (!isupper(productionSet[j][2])) {
                addToResultSet(productionSet[j][2]);
            } else {
                findFirst(productionSet[j][2], j, 3);
            }
        }
    }
    return;
}

// Function to add a character to the first set
void addToResultSet(char c) {
    int i;
    for (i = 0; i < firstCount; i++) {
        if (first[i] == c)
            return;
    }
    first[firstCount++] = c;
}
