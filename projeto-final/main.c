#include <stdio.h>
#include <stdlib.h>
int main() {
    FILE * fp = NULL;
    int ch;
    printf("Abrindo arquivo chamado frutas.txt \n");
    fp = fopen("projeto-final/frutas.txt", "r");
    if(fp == NULL){
        printf("Caminho errado ou arquivo inexistente, confira\n");
        exit(1);
    }
    while((ch=fgetc(fp))!=EOF){
        putchar(ch);
    }
    printf("\nDados disponiveis no momento foram impresso acima\n");
    fclose(fp);
    return 0;
}