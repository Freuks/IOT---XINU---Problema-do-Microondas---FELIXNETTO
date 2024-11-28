#include <xinu.h>
#include <stdbool.h>

bool emergencia = false;

bool verificar_emergencia() {
    return emergencia;
}

process monitorar_emergencia() {
    char opcao;
    while (1) {
        kprintf("Pressione 'x' para cancelar: ");
        opcao = getc(CONSOLE);
        if (opcao == 'x') {
            emergencia = true;
            kprintf("Botao cancelar acionado.\n");
            break;
        }
    }
    return OK;
}

void operacao() {
    for (int i = 10; i > 0; i--) {
        if (verificar_emergencia()) {
            kprintf("Aquecimento cancelado.\n");
            return;
        }
        kprintf("%d segundos restantes...\n", i);
        sleepms(1000);
    }
    kprintf("Aquecimento concluido.\n");
}

shellcmd xsh_cancelar(int nargs, char *args[]) {
    resume(create(monitorar_emergencia, 1024, 20, "Monitorando Emergencia", 0)); 
    operacao();
    return 0;
}
