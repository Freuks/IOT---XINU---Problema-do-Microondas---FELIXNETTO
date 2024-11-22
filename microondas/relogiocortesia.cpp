#include <xinu.h>

void cronometro() {
    uint32 start_time = gettime();
    
    while (1) {
        uint32 current_time = gettime();
        uint32 elapsed_time = current_time - start_time;

        int horas = elapsed_time / 3600;
        int minutos = (elapsed_time % 3600) / 60;
        int segundos = elapsed_time % 60;

        kprintf("%02d:%02d:%02d\n", horas, minutos, segundos);
        sleep(1);
    }
}

process main() {
    char opcao[4];

    kprintf("Ligar micro-ondas na tomada? (s/n): ");
    read(0, opcao, sizeof(opcao));
    opcao[strcspn(opcao, "\n")] = 0;

    if (strcmp(opcao, "s") == 0 || strcmp(opcao, "s") == 0) {
        kprintf("Micro-ondas ligado.\n");
        kprintf("Deseja usar o micro-ondas? (s/n): ");
        read(0, opcao, sizeof(opcao));
        opcao[strcspn(opcao, "\n")] = 0;

        if (strcmp(opcao, "n") == 0 || strcmp(opcao, "n") == 0) {
            kprintf("Micro-ondas nao em uso. Iniciando cronometro...\n");
            cronometro();
        } else {
            kprintf("Micro-ondas em funcionamento...\n");
        }
    } else {
        kprintf("Micro-ondas nao ligado.\n");
    }

    return 0;
}
