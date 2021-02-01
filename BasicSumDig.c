//Ethan Kupka C code sum of numbers
#include<stdio.h>

//basic main functionof sum print off between number

int main() {
    int sum = 0, i;
    int num;
    printf("Enter one positive number: ");
    scanf("%d", &num);

    for(i=0; i<num; i++){
      sum=sum+i;
    } //for loop
    printf("The Sum of numbers between 0 and %d are: %d ",num, sum);
} //end of main
