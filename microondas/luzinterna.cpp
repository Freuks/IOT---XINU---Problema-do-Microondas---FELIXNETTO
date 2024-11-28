#include <xinu.h>

shellcmd xsh_luz(int nargs, char *args[]) {
    char inputBuffer[2];
    bool isPortOpen = FALSE; 

    kprintf("Digite 1 para porta aberta, 0 para porta fechada, e 2 para simular aquecimento:\n");

    while (1) {
        int n = read(CONSOLE, inputBuffer, 1);
        if (n > 0) {
            inputBuffer[n] = '\0';
            char command = inputBuffer[0];

            while (inputBuffer[0] != '\n') {
                read(CONSOLE, inputBuffer, 1);
            }
            if (command == '1') {
                kprintf("Porta aberta.\n");
                isPortOpen = FALSE;
                kprintf("Luz interna ligada.\n");
            } else if (command == '0') {
                kprintf("Porta fechada.\n");
                isPortOpen = TRUE;
                kprintf("Luz interna desligada.\n");
            } else if (command == '2') {
                if (isPortOpen) {
                    kprintf("Aquecendo...\n");
                    kprintf("Luz interna ligada.\n");
                } else {
                    kprintf("Aquecimento não pode ocorrer com a porta aberta.\n");
                }
            } 
        }
    }
    return OK;
}
