#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h> 
 
#define MAX 100 
 
typedef struct {     
    char op; 
    char arg1[MAX];     
    char arg2[MAX];     
    char result[MAX]; 
} Instruction; 
 
Instruction code[MAX]; 
int code_count = 0; 
 
void generate_code(char op, char* arg1, char* arg2, char* result) {     
    code[code_count].op = op;     
    strcpy(code[code_count].arg1, arg1);     
    strcpy(code[code_count].arg2, arg2);     
    strcpy(code[code_count].result, result); 
    code_count++; 
} 
 
void print_intermediate_code() { 
    for (int i = 0; i < code_count; i++) { 
        printf("%s = %s %c %s\n", code[i].result, code[i].arg1, code[i].op, code[i].arg2); 
    } 
} 
 
void generate_final_code() {     
    printf("\nFinal Code:\n");     
    for (int i = 0; i < code_count; i++) {         
        if (isalpha(code[i].arg1[0])) {             
            printf("LOAD %s\n", code[i].arg1); 
        } else { 
            printf("PUSH %s\n", code[i].arg1); 
        } 
 
        if (isalpha(code[i].arg2[0])) {             
            printf("LOAD %s\n", code[i].arg2); 
        } else { 
            printf("PUSH %s\n", code[i].arg2); 
        } 
 
        switch (code[i].op) { 
            case '+': 
                printf("ADD\n"); 
                break;             
            case '-': 
                printf("SUB\n"); 
                break;             
            case '*': 
                printf("MUL\n"); 
                break;             
            case '/': 
                printf("DIV\n"); 
                break; 
        } 
 
        printf("STORE %s\n", code[i].result); 
    } 
} 
 
void expression(char* input, int* i, char* result); 
 
void factor(char* input, int* i, char* result) { 
    if (input[*i] == '(') {         
        (*i)++;         
        expression(input, i, result); 
        (*i)++; 
    } else if (isalpha(input[*i])) {        
        char id[2] = { input[*i], '\0' };         
        strcpy(result, id); 
        (*i)++; 
    } 
} 
 
void term(char* input, int* i, char* result) { 
    char left[MAX], right[MAX], temp[MAX]; 
    factor(input, i, left); 
 
    while (input[*i] == '*' || input[*i] == '/') {         
        char op = input[*i];         
        (*i)++;         
        factor(input, i, right);         
        strcpy(temp, left);         
        generate_code(op, temp, right, left); 
    } 
 
    strcpy(result, left); 
} 
 
void expression(char* input, int* i, char* result) { 
    char left[MAX], right[MAX], temp[MAX]; 
    term(input, i, left); 
 
    while (input[*i] == '+' || input[*i] == '-') {         
        char op = input[*i];         
        (*i)++;         
        term(input, i, right);         
        strcpy(temp, left);         
        generate_code(op, temp, right, left); 
    } 
 
    strcpy(result, left); 
} 
 
int main() {     
    char input[MAX];     
    printf("Mohan Thapa Mashrangi\n");
    printf("Enter an arithmetic expression: ");     
    scanf("%s", input); 
    int i = 0; 
    char result[MAX];     
    expression(input, &i, result); 
 
    printf("\nIntermediate Code:\n");     
    print_intermediate_code(); 
 
    generate_final_code(); 
 
    return 0; 
}
