#include <xinu.h>

#define NUM_POSICOES 12

void girarPrato() {
    for (int i = 0; i < NUM_POSICOES; i++) {
        kprintf("Prato girando %d\n", i + 1);
        sleepms(1000);
    }
}

process main() {
    kprintf("Rodando...\n");
    girarPrato();
    kprintf("Parando...\n");
    return 0;
}
