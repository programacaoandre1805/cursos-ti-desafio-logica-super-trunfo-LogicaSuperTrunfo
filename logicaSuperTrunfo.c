#include <stdio.h>
#include <string.h>

typedef struct {
    char estado[3];
    char codigo[5];
    char nome[50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
    float super_poder;
} Carta;

float calcular_densidade_populacional(unsigned long int populacao, float area) {
    return populacao / area;
}

float calcular_pib_per_capita(float pib, unsigned long int populacao) {
    return pib * 1e9 / populacao; // PIB em bilhões e população em número inteiro
}

float calcular_super_poder(Carta carta) {
    float inverso_densidade = 1 / carta.densidade_populacional;
    return (float)carta.populacao + carta.area + carta.pib * 1e9 + carta.pontos_turisticos + carta.pib_per_capita + inverso_densidade;
}

void comparar_atributos(Carta carta1, Carta carta2) {
    printf("Comparação de Cartas:\n");

    // Comparação População
    printf("População: Carta 1 venceu (%d)\n", (carta1.populacao > carta2.populacao) ? 1 : 0);
    
    // Comparação Área
    printf("Área: Carta 1 venceu (%d)\n", (carta1.area > carta2.area) ? 1 : 0);
    
    // Comparação PIB
    printf("PIB: Carta 1 venceu (%d)\n", (carta1.pib > carta2.pib) ? 1 : 0);
    
    // Comparação Pontos Turísticos
    printf("Pontos Turísticos: Carta 1 venceu (%d)\n", (carta1.pontos_turisticos > carta2.pontos_turisticos) ? 1 : 0);
    
    // Comparação Densidade Populacional
    printf("Densidade Populacional: Carta 1 venceu (%d)\n", (carta1.densidade_populacional < carta2.densidade_populacional) ? 1 : 0);
    
    // Comparação PIB per Capita
    printf("PIB per Capita: Carta 1 venceu (%d)\n", (carta1.pib_per_capita > carta2.pib_per_capita) ? 1 : 0);
    
    // Comparação Super Poder
    printf("Super Poder: Carta 1 venceu (%d)\n", (carta1.super_poder > carta2.super_poder) ? 1 : 0);
}

int main() {
    Carta carta1, carta2;

    // Leitura da Carta 1
    printf("Digite os dados da Carta 1:\n");
    printf("Estado: ");
    scanf("%s", carta1.estado);
    printf("Código: ");
    scanf("%s", carta1.codigo);
    printf("Nome da Cidade: ");
    getchar(); // Limpa o buffer
    fgets(carta1.nome, 50, stdin);
    carta1.nome[strcspn(carta1.nome, "\n")] = '\0'; // Remove o caractere de nova linha
    printf("População: ");
    scanf("%lu", &carta1.populacao);
    printf("Área: ");
    scanf("%f", &carta1.area);
    printf("PIB: ");
    scanf("%f", &carta1.pib);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta1.pontos_turisticos);

    // Calcular a Densidade Populacional e PIB per Capita da Carta 1
    carta1.densidade_populacional = calcular_densidade_populacional(carta1.populacao, carta1.area);
    carta1.pib_per_capita = calcular_pib_per_capita(carta1.pib, carta1.populacao);

    // Calcular o Super Poder da Carta 1
    carta1.super_poder = calcular_super_poder(carta1);

    // Leitura da Carta 2
    printf("\nDigite os dados da Carta 2:\n");
    printf("Estado: ");
    scanf("%s", carta2.estado);
    printf("Código: ");
    scanf("%s", carta2.codigo);
    printf("Nome da Cidade: ");
    getchar(); // Limpa o buffer
    fgets(carta2.nome, 50, stdin);
    carta2.nome[strcspn(carta2.nome, "\n")] = '\0'; // Remove o caractere de nova linha
    printf("População: ");
    scanf("%lu", &carta2.populacao);
    printf("Área: ");
    scanf("%f", &carta2.area);
    printf("PIB: ");
    scanf("%f", &carta2.pib);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta2.pontos_turisticos);

    // Calcular a Densidade Populacional e PIB per Capita da Carta 2
    carta2.densidade_populacional = calcular_densidade_populacional(carta2.populacao, carta2.area);
    carta2.pib_per_capita = calcular_pib_per_capita(carta2.pib, carta2.populacao);

    // Calcular o Super Poder da Carta 2
    carta2.super_poder = calcular_super_poder(carta2);

    // Comparar as Cartas
    comparar_atributos(carta1, carta2);

    return 0;
}
