#include <xinu.h>

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
    for (int i = prato.tempo; i > 0; i--) {
        kprintf("%d segundos restantes...\n", i);
        sleepms(1000);
    }
    kprintf("Aquecimento de %s concluido!\n", prato.nome);
}
process main() {
    Prato pratos[] = {
        {"Pipoca", 120},
        {"Lasanha", 180},
        {"Arroz", 300},
        {"Pizza", 240},
        {"Frango", 240},
        {"Legumes", 150},
    };
    int num_pratos = sizeof(pratos) / sizeof(pratos[0]);
    int escolha;
    char entrada[10];
    while (1) {
        menu(pratos, num_pratos);
        kprintf("Digite o numero do prato: ");
        getn(entrada, sizeof(entrada));
        escolha = atoi(entrada);
        if (escolha < 1 || escolha > num_pratos) {
            kprintf("Escolha invalida! Tente outro numero.\n");
        } else {
            break;
        }
    }
    aquecer_prato(pratos[escolha - 1]);

    return 0;
}
