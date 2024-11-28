#include <xinu.h>
#include <stdlib.h>

typedef struct {
    int tempo;
    char nome[50];
} Prato;
void menu(Prato pratos[], int num_pratos) {
    kprintf("Escolha um tipo de prato:\n");
    for (int i = 0; i < num_pratos; i++) {
        kprintf("%d. %s (Aquecimento: %d segundos)\n", i + 1, pratos[i].nome, pratos[i].tempo);
    }
}
void aquecer_prato(Prato prato) {
    kprintf("Aquecendo %s por %d segundos...\n", prato.nome, prato.tempo);
    for (int i=prato.tempo; i > 0; i--) {
        kprintf("%d segundos restantes...\n", i);
        sleepms(1000);
    }
    kprintf("Aquecimento de %s concluido!\n", prato.nome);
}
shellcmd xsh_ciclos(int nargs, char *args[]) {
    Prato pratos[] = {
        {.nome = "Pipoca", .tempo = 120},
        {.nome = "Lasanha", .tempo = 180},
        {.nome = "Arroz", .tempo = 300},
        {.nome = "Pizza", .tempo = 240},
        {.nome = "Frango", .tempo = 240},
        {.nome = "Legumes", .tempo = 150},
    };
    int num_pratos=sizeof(pratos)/sizeof(pratos[0]);
    int escolha;
    char entrada[10];

    while (1) {
        menu(pratos, num_pratos);
        kprintf("Digite o numero do prato: ");
        
        for (int i = 0; i < sizeof(entrada) - 1; i++) {
            entrada[i] = getc(CONSOLE);
            if (entrada[i] == '\n') {
                entrada[i] = '\0';
                break;
            }
        }
        escolha=atoi(entrada);
        if (escolha < 1 || escolha > num_pratos) {
            kprintf("Escolha invalida! Tente outro numero.\n");
        } else {
            break;
        }
    }
    aquecer_prato(pratos[escolha - 1]);

    return 0;
}
