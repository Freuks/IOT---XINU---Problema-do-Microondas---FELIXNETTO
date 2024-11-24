#include <xinu.h> 

#define TEMPO_DE_ATIVACAO 2 
#define TEMPO_DE_DESATIVACAO 3
#define CICLOS 5

void sistemaRefrigeracao() {
    for (int i = 0; i < CICLOS; i++) {
        kprintf("Ventilador ligado: resfriando...\n");
        sleepms(TEMPO_DE_ATIVACAO * 1000);
        kprintf("Ventilador desligado: respirando...\n");
        sleepms(TEMPO_DE_DESATIVACAO * 1000);
    }
}

process main() {
    kprintf("Iniciando resfriamento...\n");
    sistemaRefrigeracao();
    kprintf("Resfriamento concluido.\n");
    return OK;
}
