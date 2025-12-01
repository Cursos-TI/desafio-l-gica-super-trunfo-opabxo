#include <stdio.h>
#include <string.h>

int main() {
    // Declaração das variáveis da Carta 1
    // Strings para estado, código e cidade
    char estado1[30], codigo1[10], cidade1[30];
    // Valores numéricos
    int populacao1, pontosTuristicos1;
    float area1, pib1;

    // Declaração das variáveis da Carta 2
    char estado2[30], codigo2[10], cidade2[30];
    int populacao2, pontosTuristicos2;
    float area2, pib2;

    // Entrada dos dados da Carta 1
    printf("Carta 1\n");

    printf("Estado: ");
    fgets(estado1, 30, stdin);  // Lê o estado com espaços

    printf("Codigo: ");
    fgets(codigo1, 10, stdin);  // Lê o código

    printf("Cidade: ");
    fgets(cidade1, 30, stdin);  // Lê o nome da cidade

    printf("Populacao: ");
    scanf("%d", &populacao1);   // Lê população

    printf("Area: ");
    scanf("%f", &area1);        // Lê área

    printf("PIB: ");
    scanf("%f", &pib1);         // Lê PIB

    printf("Pontos turisticos: ");
    scanf("%d", &pontosTuristicos1);   // Lê pontos turísticos

    getchar();  // Consumir o ENTER após o scanf para evitar problemas no fgets

    // Entrada dos dados da Carta 2
    printf("\nCarta 2\n");

    printf("Estado: ");
    fgets(estado2, 30, stdin);

    printf("Codigo: ");
    fgets(codigo2, 10, stdin);

    printf("Cidade: ");
    fgets(cidade2, 30, stdin);

    printf("Populacao: ");
    scanf("%d", &populacao2);

    printf("Area: ");
    scanf("%f", &area2);

    printf("PIB: ");
    scanf("%f", &pib2);

    printf("Pontos turisticos: ");
    scanf("%d", &pontosTuristicos2);

    // Cálculo da densidade demográfica
    float densidade1 = populacao1 / area1;
    float densidade2 = populacao2 / area2;

    // Cálculo do PIB per capita
    float pibPerCapita1 = pib1 / populacao1;
    float pibPerCapita2 = pib2 / populacao2;

    // Atributo que será comparado (definido no código, como pedido no desafio)
    char atributo[] = "PIB per capita";

    // Exibição dos valores comparados
    printf("\nComparacao de cartas (Atributo: %s)\n", atributo);
    printf("Carta 1 - %s: %.2f\n", cidade1, pibPerCapita1);
    printf("Carta 2 - %s: %.2f\n", cidade2, pibPerCapita2);

    // Estrutura de decisão para determinar a carta vencedora
    if (pibPerCapita1 > pibPerCapita2) {
        printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
    } 
    else if (pibPerCapita2 > pibPerCapita1) {
        printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
    } 
    else {
        // Caso os valores sejam iguais
        printf("Resultado: Empate!\n");
    }

    return 0;
}