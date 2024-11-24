#include <xinu.h>

process main(void) {
    int tempo_aquecimento, minutos, segundos;
    kprintf("Digite o tempo de aquecimento:\n");

    while (1) {
        kprintf("Tempo: ");
        tempo_aquecimento = kgetint();
        if (tempo_aquecimento >= 0 && tempo_aquecimento <= 999) {
            minutos = tempo_aquecimento / 100;
            segundos = tempo_aquecimento % 100;

            if (segundos >= 0 && segundos < 60) {
                kprintf("Tempo de aquecimento: %d:%02d\n", minutos, segundos);
                break;
            } else {
                kprintf("Segundos invalidos. Por favor, insira um valor entre 0 e 59 para os segundos.\n");
            }
        } else {
            kprintf("Entrada invalida, insira um valor entre 0 e 999.\n");
        }
    }

    return 0;
}