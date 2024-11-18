#include <stdio.h>

int main() {
    int buttonState = 0;

    printf("Digite 1 para porta aberta, e 0 para porta fechada: \n");

    while (1) {
        scanf("%d", &buttonState);

        if (buttonState == 1) {
            printf("Porta aberta: 1\n");
        } else if (buttonState == 0) {
            printf("Porta fechada: 0\n");
        } else {
            printf("VOCE DESTRUIU O MICROONDAS, pressione 1 ou 0.\n");
        }
    }

    return 0;
}