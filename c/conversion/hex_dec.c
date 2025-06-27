#include <stdio.h>

int hexCharToDecimal(char ch) {
    if (ch >= '0' && ch <= '9')
        return ch - '0';
    else if (ch >= 'A' && ch <= 'F')
        return ch - 'A' + 10;
    else if (ch >= 'a' && ch <= 'f')
        return ch - 'a' + 10;
    else
        return -1; // Invalid character
}

int main() {
    char hex[20];
    int i = 0, decimal = 0, digit;

    printf("Enter a hexadecimal number (e.g., F2): ");
    scanf("%s", hex);

    while (hex[i] != '\0') {
        digit = hexCharToDecimal(hex[i]);
        if (digit == -1) {
            printf("Invalid hex character: %c\n", hex[i]);
            return 1;
        }
        decimal = decimal * 16 + digit;
        i++;
    }

    printf("Decimal value: %d\n", decimal);
    return 0;
}

