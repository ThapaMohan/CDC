#include <stdio.h>
#include <ctype.h>
#include<string.h>
int main() {
    char a[10];
    int flag = 0, i = 0;  
    printf("Mohan Thapa Mashrangi\n");
    printf("Enter an identifier: ");
    fgets(a, sizeof(a), stdin); 
    size_t len = strlen(a);
    if (len > 0 && a[len - 1] == '\n') {
        a[len - 1] = '\0';
    }
    if (isalpha(a[0]) || a[0] == '_') {
        flag = 1;  
        while (a[i] != '\0') {
            if (!isdigit(a[i]) && !isalpha(a[i]) && a[i] != '_') {
                flag = 0;  
                break;
            }
            i++;
        }
    } else {
        printf("Not a valid identifier");
        return 0; 
    }
    if (flag == 1) {
        printf("Valid identifier");
    } else {
        printf("Not a valid identifier");
    }
    return 0;
}