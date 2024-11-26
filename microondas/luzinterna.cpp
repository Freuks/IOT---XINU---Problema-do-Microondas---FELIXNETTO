#include <xinu.h>

process main(void) {
    int buttonState = 0;
    char inputBuffer[3];
    bool heating = FALSE;

    kprintf("Digite 1 para porta aberta, 0 para porta fechada, e 2 para simular aquecimento:\n");

    while (1) {
        int n = read(CONSOLE, inputBuffer, 1);
        if (n > 0) {
            inputBuffer[n] = '\0';
            buttonState = inputBuffer[0] - '0';

            if (inputBuffer[0] == '1') {
                kprintf("Porta aberta.\n");
                heating = TRUE;
                kprintf("Luz interna ligada.\n");
            } else if (inputBuffer[0] == '0') {
                kprintf("Porta fechada.\n");
                heating = FALSE;
                kprintf("Luz interna desligada.\n");
            } else if (inputBuffer[0] == '2') {
                kprintf("Aquecendo...\n");
                heating = FALSE;
                kprintf("Luz interna ligada.\n");
            } else {
                kprintf("VOCE DESTRUIU O MICROONDAS, pressione 1 ou 0.\n");
            }
        }
    }
    return OK;
}
