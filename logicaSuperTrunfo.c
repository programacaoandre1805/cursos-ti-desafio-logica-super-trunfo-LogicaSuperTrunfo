#include <stdio.h>
#include <string.h>

typedef struct {
    char estado[10];
    char codigo[12];
    char nome[50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
    float super_poder;
} Carta;
