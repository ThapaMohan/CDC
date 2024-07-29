#include <stdio.h>
int main() {
    int intVar = 10;
    float floatVar = 5.5;
    double doubleVar = 12.34;
    float result1 = intVar + floatVar; 
    printf("Mohan Thapa Mashrangi\n");
    printf("Implicit Conversion Result (int to float): %.2f\n", result1);
    double result2 = intVar + doubleVar; 
    printf("Implicit Conversion Result (int to double): %.2f\n", result2);
    float floatVar2 = 9.99;
    int intVar2;
    intVar2 = (int)floatVar2; 
    printf("Explicit Conversion Result (float to int): %d\n", intVar2);
    float floatVar3;
    double doubleVar2 = 123.456;
    floatVar3 = (float)doubleVar2; 
    printf("Explicit Conversion Result (double to float): %.2f\n", floatVar3);
    int num1 = 10;
    double num2 = 20.5;
    double result3 = num1 / num2; 
    printf("Calculation Result with implicit conversion: %.2f\n", result3);
    int result4 = (int)(num1 / num2);
    printf("Calculation Result with explicit conversion to int: %d\n", result4);
    return 0;
}
