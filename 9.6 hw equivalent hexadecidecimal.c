
#include <stdio.h>

int main() {
    int num, hexadechiml[32], i = 0;


    printf("Enter a positive integer: ");
    scanf("%d", &num);

    while (num > 0) {
        hexadechimal[i] = num % 16;

       // problem//



        num /= 16;
        i++;
    }

    printf("hexadechimal equivalent: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hexadecimal[j]);
    }
    printf("\n");

    return 0;
}
