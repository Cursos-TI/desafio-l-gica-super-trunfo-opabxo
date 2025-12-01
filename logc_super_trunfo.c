#include <stdio.h>
#include <string.h>

int main() {
    // Dados da Carta 1 (pré-definidos)
    char pais1[30] = "Brasil";
    int populacao1 = 203000000;
    float area1 = 8516000.0;
    float pib1 = 1.9; // PIB em trilhões
    int pontos1 = 50;

    // Dados da Carta 2 (pré-definidos)
    char pais2[30] = "Argentina";
    int populacao2 = 46000000;
    float area2 = 2780000.0;
    float pib2 = 0.6;
    int pontos2 = 30;

    // Cálculo da densidade demográfica (população / área)
    float densidade1 = populacao1 / area1;
    float densidade2 = populacao2 / area2;

    int opcao;

    // Menu interativo
    printf("=== SUPER TRUNFO — COMPARACAO DE CARTAS ===\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turisticos\n");
    printf("5 - Densidade Demografica\n");
    printf("Escolha o atributo: ");
    scanf("%d", &opcao);

    printf("\nComparando %s e %s...\n\n", pais1, pais2);

    switch (opcao) {
        case 1:
            // Comparação por população
            printf("Atributo: Populacao\n");
            printf("%s: %d\n", pais1, populacao1);
            printf("%s: %d\n", pais2, populacao2);

            if (populacao1 > populacao2)
                printf("Vencedor: %s\n", pais1);
            else if (populacao2 > populacao1)
                printf("Vencedor: %s\n", pais2);
            else
                printf("Empate!\n");
            break;

        case 2:
            // Comparação por área
            printf("Atributo: Area\n");
            printf("%s: %.2f\n", pais1, area1);
            printf("%s: %.2f\n", pais2, area2);

            if (area1 > area2)
                printf("Vencedor: %s\n", pais1);
            else if (area2 > area1)
                printf("Vencedor: %s\n", pais2);
            else
                printf("Empate!\n");
            break;

        case 3:
            // Comparação por PIB
            printf("Atributo: PIB\n");
            printf("%s: %.2f trilhoes\n", pais1, pib1);
            printf("%s: %.2f trilhoes\n", pais2, pib2);

            if (pib1 > pib2)
                printf("Vencedor: %s\n", pais1);
            else if (pib2 > pib1)
                printf("Vencedor: %s\n", pais2);
            else
                printf("Empate!\n");
            break;

        case 4:
            // Comparação por pontos turísticos
            printf("Atributo: Pontos Turisticos\n");
            printf("%s: %d\n", pais1, pontos1);
            printf("%s: %d\n", pais2, pontos2);

            if (pontos1 > pontos2)
                printf("Vencedor: %s\n", pais1);
            else if (pontos2 > pontos1)
                printf("Vencedor: %s\n", pais2);
            else
                printf("Empate!\n");
            break;

        case 5:
            // Comparação por densidade demográfica
            // IMPORTANTE: aqui o menor valor vence
            printf("Atributo: Densidade Demografica\n");
            printf("%s: %.5f\n", pais1, densidade1);
            printf("%s: %.5f\n", pais2, densidade2);

            if (densidade1 < densidade2)
                printf("Vencedor: %s\n", pais1);
            else if (densidade2 < densidade1)
                printf("Vencedor: %s\n", pais2);
            else
                printf("Empate!\n");
            break;

        default:
            // Caso o usuário digite uma opção inválida
            printf("Opcao invalida!\n");
    }

    return 0;
}