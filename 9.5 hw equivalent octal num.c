
#include <stdio.h>

int main() {
    int num, octal[32], i = 0;

    printf("Enter a positive integer: ");
    scanf("%d", &num);

    while (num > 0) {
        octal[i] = num % 8;
        num /= 8;
        i++;
    }

    printf("Octal equivalent: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", octal[j]);
    }
    printf("\n");

    return 0;
}
