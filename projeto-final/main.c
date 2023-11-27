#include <stdio.h>
struct Carro {
    char placa[9];
    char modelo[51];
    char marca[51];
    int ano;
};
void ler(struct Carro *p_carro);
void imprimir(struct Carro c);
int main() {
    struct Carro carro;
    ler(&carro);
    imprimir(carro);
    return 0;
}
void imprimir(struct Carro c){
    printf("Apresentado os dados do carro: \n");
    printf("Modelo: %s \n", c.modelo);
    printf("Placa: %s \n", c.placa);
    printf("Marca: %s \n", c.marca);
    printf("Ano Fabricacao: %d \n", c.ano);
}
void ler(struct Carro *p_carro){
    fflush(stdin);
    printf("Digite a placa do veiculo: \n");
    gets(p_carro->placa);
    fflush(stdin);
    printf("Digite o modelo do veiculo: \n");
    gets(p_carro->modelo);
    printf("Digite a marca do veiculo: \n");
    fflush(stdin);
    gets(p_carro->marca);
    printf("Digite o ano do veiculo: \n");
    scanf("%d", &p_carro->ano);
}