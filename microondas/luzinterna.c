#include <xinu.h>

process main(void) {
    int buttonState = 0;
    char inputBuffer[2];
    kprintf("Digite 1 para porta aberta, e 0 para porta fechada: \n");
    while (1) {
        int n = read(CONSOLE, inputBuffer, 1);
        if (n > 0) {
            inputBuffer[n] = '\0';
            buttonState = inputBuffer[0] - '0';
            if (buttonState == 1) {
                kprintf("Porta aberta: 1\n");
            } else if (buttonState == 0) {
                kprintf("Porta fechada: 0\n");
            } else {
                kprintf("VOCE DESTRUIU O MICROONDAS, pressione 1 ou 0.\n");
            }
        }
    }
    return OK;
}
