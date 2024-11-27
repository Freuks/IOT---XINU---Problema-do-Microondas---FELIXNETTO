#include <xinu.h>

void beep() {
    kprintf("\a");
}

shellcmd xsh_timer(int nargs, char *args[]) {
    int timer;
    char inputBuffer[10];

    kprintf("Digite o tempo do timer em segundos: ");
    read(CONSOLE, inputBuffer, sizeof(inputBuffer) - 1)
    inputBuffer[9] = '\0';
    timer = atoi(inputBuffer);

    while (timer > 0) {
        kprintf("Tempo restante: %d segundos\n", timer);
        sleep(1);
        timer--;
    }
    kprintf("BIP BIP BIP\n");
    beep();
    return OK;
}
