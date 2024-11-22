#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

void cronometro() {
    time_t tempo;
    struct tm *tempoinfo;

    time(&tempo);
    tempoinfo = localtime(&tempo);

    while (1) {
        time(&tempo);
        tempoinfo = localtime(&tempo);
        printf("%02d:%02d:%02d\n", tempoinfo->tm_hour, tempoinfo->tm_min, tempoinfo->tm_sec);
        sleep(1);
    }
}

int main() {
    char opcao[4];

    printf("Ligar micro-ondas na tomada? (s/n): ");
    fgets(opcao, sizeof(opcao), stdin);
    opcao[strcspn(opcao, "\n")] = 0;

    if (strcmp(opcao, "s") == 0 || strcmp(opcao, "SIM") == 0) {
        printf("Micro-ondas ligado.\n");
        printf("Deseja usar o micro-ondas? (s/n): ");
        fgets(opcao, sizeof(opcao), stdin);
        opcao[strcspn(opcao, "\n")] = 0;

        if (strcmp(opcao, "n") == 0 || strcmp(opcao, "n") == 0) {
            printf("Micro-ondas nao em uso. Iniciando cronometro...\n");
            cronometro();
        } else {
            printf("Micro-ondas em funcionamento...\n");
        }
    } else {
        printf("Micro-ondas nao ligado.\n");
    }

    return 0;
}