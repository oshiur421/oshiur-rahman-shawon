
#include <stdio.h>

int main() {
    int num, binary[32], i = 0;


    printf("Enter a positive integer: ");
    scanf("%d", &num);


    while (num > 0) {
        binary[i] = num % 2;
        num /= 2;
        i++;
    }

    printf("Binary equivalent: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
    printf("\n");

    return 0;
}
