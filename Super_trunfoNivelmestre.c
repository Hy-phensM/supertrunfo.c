#include <stdio.h>
#include <string.h>
#include <stdlib.h> // Para atof

// Definição da estrutura da carta
typedef struct {
    char estado[50];
    char codigo[10];
    char nome[50];
    unsigned long int populacao;
    float area;
    float pib;
    int num_pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
    float super_poder;
} Carta;

// Função para calcular a densidade populacional
float calcularDensidade(unsigned long int populacao, float area) {
    if (area > 0) {
        return (float)populacao / area;
    } else {
        return 0;
    }
}

// Função para calcular o PIB per capita
float calcularPIBPerCapita(float pib, unsigned long int populacao) {
    if (populacao > 0) {
        return pib / populacao;
    } else {
        return 0;
    }
}

// Função para calcular o Super Poder de uma carta
float calcularSuperPoder(Carta carta) {
    return (float)carta.populacao + carta.area + carta.pib + carta.num_pontos_turisticos + carta.pib_per_capita + (carta.densidade_populacional > 0 ? 1.0f / carta.densidade_populacional : 0);
}

int main() {
    Carta carta1, carta2;

    // Leitura dos dados da Carta 1
    printf("Digite os dados da Carta 1:\n");
    printf("Estado: ");
    fgets(carta1.estado, sizeof(carta1.estado), stdin);
    carta1.estado[strcspn(carta1.estado, "\n")] = 0; // Remover newline

    printf("Código: ");
    fgets(carta1.codigo, sizeof(carta1.codigo), stdin);
    carta1.codigo[strcspn(carta1.codigo, "\n")] = 0; // Remover newline

    printf("Nome: ");
    fgets(carta1.nome, sizeof(carta1.nome), stdin);
    carta1.nome[strcspn(carta1.nome, "\n")] = 0; // Remover newline

    printf("População: ");
    scanf("%lu", &carta1.populacao);
    getchar(); // Consumir o newline deixado pelo scanf

    printf("Área (em km²): ");
    scanf("%f", &carta1.area);
    getchar(); // Consumir o newline deixado pelo scanf

    printf("PIB (em milhões de R$): ");
    scanf("%f", &carta1.pib);
    getchar(); // Consumir o newline deixado pelo scanf

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta1.num_pontos_turisticos);
    getchar(); // Consumir o newline deixado pelo scanf

    // Cálculo dos atributos da Carta 1
    carta1.densidade_populacional = calcularDensidade(carta1.populacao, carta1.area);
    carta1.pib_per_capita = calcularPIBPerCapita(carta1.pib, carta1.populacao);
    carta1.super_poder = calcularSuperPoder(carta1);

    printf("\nDigite os dados da Carta 2:\n");
    printf("Estado: ");
    fgets(carta2.estado, sizeof(carta2.estado), stdin);
    carta2.estado[strcspn(carta2.estado, "\n")] = 0; // Remover newline

    printf("Código: ");
    fgets(carta2.codigo, sizeof(carta2.codigo), stdin);
    carta2.codigo[strcspn(carta2.codigo, "\n")] = 0; // Remover newline

    printf("Nome: ");
    fgets(carta2.nome, sizeof(carta2.nome), stdin);
    carta2.nome[strcspn(carta2.nome, "\n")] = 0; // Remover newline

    printf("População: ");
    scanf("%lu", &carta2.populacao);
    getchar(); // Consumir o newline deixado pelo scanf

    printf("Área (em km²): ");
    scanf("%f", &carta2.area);
    getchar(); // Consumir o newline deixado pelo scanf

    printf("PIB (em milhões de R$): ");
    scanf("%f", &carta2.pib);
    getchar(); // Consumir o newline deixado pelo scanf

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta2.num_pontos_turisticos);
    getchar(); // Consumir o newline deixado pelo scanf

    // Cálculo dos atributos da Carta 2
    carta2.densidade_populacional = calcularDensidade(carta2.populacao, carta2.area);
    carta2.pib_per_capita = calcularPIBPerCapita(carta2.pib, carta2.populacao);
    carta2.super_poder = calcularSuperPoder(carta2);

    // Comparação das cartas e exibição dos resultados
    printf("\nComparação de Cartas:\n");

    printf("População: Carta %d venceu (%d)\n", (carta1.populacao > carta2.populacao) ? 1 : 2, (carta1.populacao > carta2.populacao));
    printf("Área: Carta %d venceu (%d)\n", (carta1.area > carta2.area) ? 1 : 2, (carta1.area > carta2.area));
    printf("PIB: Carta %d venceu (%d)\n", (carta1.pib > carta2.pib) ? 1 : 2, (carta1.pib > carta2.pib));
    printf("Pontos Turísticos: Carta %d venceu (%d)\n", (carta1.num_pontos_turisticos > carta2.num_pontos_turisticos) ? 1 : 2, (carta1.num_pontos_turisticos > carta2.num_pontos_turisticos));
    printf("Densidade Populacional: Carta %d venceu (%d)\n", (carta1.densidade_populacional < carta2.densidade_populacional) ? 1 : 2, (carta1.densidade_populacional < carta2.densidade_populacional));
    printf("PIB per Capita: Carta %d venceu (%d)\n", (carta1.pib_per_capita > carta2.pib_per_capita) ? 1 : 2, (carta1.pib_per_capita > carta2.pib_per_capita));
    printf("Super Poder: Carta %d venceu (%d)\n", (carta1.super_poder > carta2.super_poder) ? 1 : 2, (carta1.super_poder > carta2.super_poder));

    return 0;
}