#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_TOKEN_LENGTH 100

// Token types
typedef enum {
    TOKEN_KEYWORD,
    TOKEN_IDENTIFIER,
    TOKEN_OPERATOR,
    TOKEN_NUMBER,
    TOKEN_UNKNOWN
} TokenType;

// Keywords list
const char *keywords[] = {
    "int", "float", "return", "if", "else", "while", "for", NULL
};

// Function to check if a token is a keyword
int is_keyword(const char *token) {
    for (int i = 0; keywords[i] != NULL; i++) {
        if (strcmp(token, keywords[i]) == 0) {
            return 1; // Token is a keyword
        }
    }
    return 0; // Token is not a keyword
}

// Function to identify the token type
TokenType identify_token(const char *token) {
    if (is_keyword(token)) {
        return TOKEN_KEYWORD;
    }
    if (isdigit(token[0])) {
        return TOKEN_NUMBER;
    }
    if (isalpha(token[0]) || token[0] == '_') {
        return TOKEN_IDENTIFIER;
    }
    if (strchr("+-*/=;", token[0])) {
        return TOKEN_OPERATOR;
    }
    return TOKEN_UNKNOWN;
}

// Function to print the token type
void print_token(const char *token) {
    TokenType type = identify_token(token);

    switch (type) {
        case TOKEN_KEYWORD:
            printf("Keyword: %s\n", token);
            break;
        case TOKEN_IDENTIFIER:
            printf("Identifier: %s\n", token);
            break;
        case TOKEN_OPERATOR:
            printf("Operator: %s\n", token);
            break;
        case TOKEN_NUMBER:
            printf("Number: %s\n", token);
            break;
        default:
            printf("Unknown token: %s\n", token);
            break;
    }
}

// Main function to read and analyze tokens
int main() {
    char source_code[MAX_TOKEN_LENGTH];
    char token[MAX_TOKEN_LENGTH];
    int i = 0, j = 0;
    printf("Mohan Thapa Mashrangi");
    printf("Enter source code (end with ';'):\n");
    fgets(source_code, sizeof(source_code), stdin);

    // Process each character in the input
    while (source_code[i] != '\0') {
        if (isspace(source_code[i])) {
            i++;
            continue;
        }

        if (isalpha(source_code[i]) || source_code[i] == '_') {
            // Read an identifier or keyword
            j = 0;
            while (isalnum(source_code[i]) || source_code[i] == '_') {
                token[j++] = source_code[i++];
            }
            token[j] = '\0';
            print_token(token);
        } else if (isdigit(source_code[i])) {
            // Read a number
            j = 0;
            while (isdigit(source_code[i])) {
                token[j++] = source_code[i++];
            }
            token[j] = '\0';
            print_token(token);
        } else if (strchr("+-*/=;", source_code[i])) {
            // Read an operator
            token[0] = source_code[i++];
            token[1] = '\0';
            print_token(token);
        } else {
            // Unknown token
            token[0] = source_code[i++];
            token[1] = '\0';
            print_token(token);
        }
    }

    return 0;
}
