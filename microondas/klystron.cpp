#include <xinu.h>

shellcmd xsh_klystron(int nargs, char *args[]) {
    char comando;
    bool klystron=false;
    kprintf("Digite 'l' para ligar o klystron ou 'd' para desligar:\n");
    while (1) {
        kprintf("Comando: ");
        comando = getc(CONSOLE);
        while (getc(CONSOLE) != '\n');

        if (comando=='l') {
            klystron=true;
            kprintf("Klystron ligado.\n");
        } else if (comando=='d') {
            klystron=false;
            kprintf("Klystron desligado.\n");
        } else {
            kprintf("Comando invalido, tente novamente.\n");
        }
    }

    return 0;
}