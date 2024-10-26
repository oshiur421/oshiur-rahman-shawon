
#include <stdio.h>
#include <math.h>

int main() {
    int base, exponent, result;

    printf("Enter the base number: ");
    scanf("%d", &base);
    printf("Enter the exponent number: ");
    scanf("%d", &exponent);


    result = pow(base, exponent);

    printf("result= %d\n", result);

    return 0;
}
