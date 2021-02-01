//Ethan Kupka C Code for PrimeNumber

#include <stdio.h>

int PrimeNumber(int number);
int PrimeNumber(int number) {
    int j, flag = 1;
    for (j = 2; j <= number / 2; ++j) {
        if (number % j == 0) {
            flag = 0;
            break;
        } // if statement
    } // for loop
    return flag;
} //end of PrimeNumber

int main() {
    int num, i, flag;
    printf("Enter a positive number: ");
    scanf("%d", &num);
    printf("Prime numbers between 0 and %d are: ", num);
    for (i = 1 + 1; i < num; ++i) {

        flag = PrimeNumber(i);

        if (flag == 1)
            printf("%d ", i);
    } //for loop
    return 0;
} //end of main
