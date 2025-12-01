#include <stdio.h>
#include <string.h>

/* ------------------------------------------
   Estrutura da carta do Super Trunfo
------------------------------------------ */
typedef struct {
    char nome[50];
    int populacao;
    int area;
    int pib;
    int densidade;
} Carta;


/* ------------------------------------------------
   Função para exibir os menus de atributos
   Cada atributo recebe um número fixo:
   1 - População
   2 - Área
   3 - PIB
   4 - Densidade Demográfica
------------------------------------------------- */
void exibirMenuAtributos(int bloqueado) {
    printf("\nEscolha um atributo:\n");

    if (bloqueado != 1) printf("1 - População\n");
    if (bloqueado != 2) printf("2 - Área\n");
    if (bloqueado != 3) printf("3 - PIB\n");
    if (bloqueado != 4) printf("4 - Densidade Demográfica\n");

    printf("Sua escolha: ");
}


/* ------------------------------------------------
   Função para retornar o valor de um atributo
   baseado no número selecionado.
------------------------------------------------- */
int obterValor(Carta c, int atributo) {
    switch (atributo) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return c.densidade;
        default: return -1;
    }
}

/* ------------------------------------------------
   Função para obter o nome textual do atributo
------------------------------------------------- */
char* nomeAtributo(int atributo) {
    switch (atributo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Densidade Demográfica";
        default: return "Desconhecido";
    }
}


/* =====================================================
                     PROGRAMA PRINCIPAL
===================================================== */
int main() {

    /* ----------------------------------------------
       CARTAS PRÉ-CADASTRADAS
       (você pode alterar pelos seus próprios valores)
    ---------------------------------------------- */
    Carta carta1 = {"Brasil", 203000000, 8510000, 1800000, 25};
    Carta carta2 = {"Canadá", 38000000, 9980000, 1600000, 4};

    int atributo1, atributo2;
    int valor1_c1, valor1_c2;
    int valor2_c1, valor2_c2;
    int soma1, soma2;

    /* ----------------------------------------------
       MENU – ESCOLHA DO PRIMEIRO ATRIBUTO
    ---------------------------------------------- */
    exibirMenuAtributos(0);
    scanf("%d", &atributo1);

    if (atributo1 < 1 || atributo1 > 4) {
        printf("Opção inválida!\n");
        return 0;
    }

    /* ----------------------------------------------
       MENU DINÂMICO – O SEGUNDO ATRIBUTO NÃO PODE
       SER O MESMO DO PRIMEIRO
    ---------------------------------------------- */
    exibirMenuAtributos(atributo1);
    scanf("%d", &atributo2);

    if (atributo2 < 1 || atributo2 > 4 || atributo2 == atributo1) {
        printf("Opção inválida!\n");
        return 0;
    }

    /* ----------------------------------------------
       COLETANDO VALORES DAS CARTAS
    ---------------------------------------------- */
    valor1_c1 = obterValor(carta1, atributo1);
    valor1_c2 = obterValor(carta2, atributo1);

    valor2_c1 = obterValor(carta1, atributo2);
    valor2_c2 = obterValor(carta2, atributo2);

    /* ----------------------------------------------
       EXIBINDO INFORMAÇÕES ORGANIZADAS
    ---------------------------------------------- */
    printf("\n================= COMPARAÇÃO =================\n");
    printf("Carta 1: %s\n", carta1.nome);
    printf("Carta 2: %s\n\n", carta2.nome);

    printf("Atributo 1: %s\n", nomeAtributo(atributo1));
    printf("%s: %d\n", carta1.nome, valor1_c1);
    printf("%s: %d\n\n", carta2.nome, valor1_c2);

    printf("Atributo 2: %s\n", nomeAtributo(atributo2));
    printf("%s: %d\n", carta1.nome, valor2_c1);
    printf("%s: %d\n\n", carta2.nome, valor2_c2);

    /* ----------------------------------------------
       REGRA ESPECIAL: DENSIDADE DEMOGRÁFICA
       - Menor vence
       - Outros atributos: maior vence
       Usando operador ternário
    ---------------------------------------------- */
    int pontosCarta1 = 0;
    int pontosCarta2 = 0;

    // Comparação do atributo 1
    int vencedor1 = (atributo1 == 4)
                    ? (valor1_c1 < valor1_c2 ? 1 : 2)
                    : (valor1_c1 > valor1_c2 ? 1 : 2);
    if (valor1_c1 == valor1_c2) vencedor1 = 0;

    if (vencedor1 == 1) pontosCarta1++;
    else if (vencedor1 == 2) pontosCarta2++;

    // Comparação do atributo 2
    int vencedor2 = (atributo2 == 4)
                    ? (valor2_c1 < valor2_c2 ? 1 : 2)
                    : (valor2_c1 > valor2_c2 ? 1 : 2);
    if (valor2_c1 == valor2_c2) vencedor2 = 0;

    if (vencedor2 == 1) pontosCarta1++;
    else if (vencedor2 == 2) pontosCarta2++;

    /* ----------------------------------------------
       SOMA FINAL DOS ATRIBUTOS
    ---------------------------------------------- */
    soma1 = valor1_c1 + valor2_c1;
    soma2 = valor1_c2 + valor2_c2;

    printf("\nSoma dos atributos:\n");
    printf("%s: %d\n", carta1.nome, soma1);
    printf("%s: %d\n", carta2.nome, soma2);

    printf("\n=============== RESULTADO FINAL ===============\n");

    if (soma1 > soma2) {
        printf("Vencedor: %s!\n", carta1.nome);
    }
    else if (soma2 > soma1) {
        printf("Vencedor: %s!\n", carta2.nome);
    }
    else {
        printf("Empate!\n");
    }

    return 0;
}