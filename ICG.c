#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int i = 0, j = 0, no = 0, tmpch = 'Z';
char str[100], left[15], right[15];
struct exp {
    int pos;
    char op;
} k[15];
void findopr();
void explore();
void fleft(int);
void fright(int);
int main() {
    printf("Mohan Thapa Mashrangi\n");
    printf("\t\t INTERMEDIATE CODE GENERATION\n\n");
    printf("Enter the Expression: ");
    scanf("%s", str);
    printf("The intermediate code:\n\n\tIntermediate Code\t\tExpression\n");
    findopr();
    explore();
    return 0;
}
void findopr() {
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == ':' || str[i] == '/' || str[i] == '*' || str[i] == '+' || str[i] == '-') {
            k[j].pos = i;
            k[j++].op = str[i];
        }
    }
}
void explore() {
    i = 0;
    while (i < j) {
        fleft(k[i].pos);
        fright(k[i].pos);
        printf("\t%c := %s %c %s\t\t", tmpch, left, k[i].op, right);
        str[k[i].pos] = tmpch--;
        for (int l = 0; l < strlen(str); l++) {
            if (str[l] != '$') {
                printf("%c", str[l]);
            }
        }
        printf("\n");
        i++;
    }
    if (no == 0) {
        fleft(strlen(str));
        printf("\t%s := %s\n", right, left);
        exit(0);
    }
    printf("\t%s := %c\n", right, str[k[--i].pos]);
}
void fleft(int x) {
    int w = 0;
    x--;
    while (x != -1 && str[x] != '+' && str[x] != '*' && str[x] != '=' && str[x] != '\0' && str[x] != '/' && str[x] != ':') {
        if (str[x] != '$') {
            left[w++] = str[x];
            left[w] = '\0';
            str[x] = '$';
        }
        x--;
    }
}
void fright(int x) {
    int w = 0;
    x++;
    while (x != -1 && str[x] != '+' && str[x] != '*' && str[x] != '\0' && str[x] != '=' && str[x] != ':' && str[x] != '-' && str[x] != '/') {
        if (str[x] != '$') {
            right[w++] = str[x];
            right[w] = '\0';
            str[x] = '$';
        }
        x++;
    }
}
