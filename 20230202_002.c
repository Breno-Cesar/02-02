#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOMES 20
#define MAX_CARACTERES 120

int num_nomes = 0;
char lista_nomes[MAX_NOMES][MAX_CARACTERES];

void imprimir_lista() {
    int i;
    printf("Lista de nomes:\n");
    for (i = 0; i < num_nomes; i++) {
        printf("%d. %s\n", i+1, lista_nomes[i]);
    }
}

void eliminar_nome(int indice) {
    if (indice < 0 || indice >= num_nomes) {
        printf("Indice invalido.\n");
        return;
    }
    int i;
    for (i = indice; i < num_nomes-1; i++) {
        strcpy(lista_nomes[i], lista_nomes[i+1]);
    }
    num_nomes--;
    printf("Nome eliminado com sucesso.\n");
}

void ordenar_lista() {
    int i, j;
    char temp[MAX_CARACTERES];
    for (i = 0; i < num_nomes; i++) {
        for (j = i+1; j < num_nomes; j++) {
            if (strcmp(lista_nomes[i], lista_nomes[j]) > 0) {
                strcpy(temp, lista_nomes[i]);
                strcpy(lista_nomes[i], lista_nomes[j]);
                strcpy(lista_nomes[j], temp);
            }
        }
    }
    printf("Lista ordenada com sucesso.\n");
}

void inserir_nome_ordenado(char nome[MAX_CARACTERES]) {
    if (num_nomes == MAX_NOMES) {
        printf("Lista cheia, nao e possivel adicionar mais nomes.\n");
        return;
    }
    int i;
    for (i = 0; i < num_nomes; i++) {
        if (strcmp(nome, lista_nomes[i]) < 0) {
            break;
        }
    }
    int j;
    for (j = num_nomes-1; j >= i; j--) {
        strcpy(lista_nomes[j+1], lista_nomes[j]);
    }
    strcpy(lista_nomes[i], nome);
    num_nomes++;
    printf("Nome adicionado com sucesso.\n");
}

int main() {
    int opcao;
    char nome[MAX_CARACTERES];
    int indice;
    do {
        printf("\nEscolha uma opcao:\n");
        printf("1. Inserir nome\n");
        printf("2. Imprimir lista de nomes\n");
        printf("3. Eliminar nome\n");
        printf("4. Ordenar lista de nomes\n");
        printf("5. Inserir nome em lista ordenada\n");
        printf("6. Sair\n");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                if (num_nomes == MAX_NOMES) {
                    printf("Lista cheia, nao e possivel adicionar mais nomes.\n");
                    break;
                }
                printf("Digite o nome a ser inserido: ");
                scanf(" %[^\n]s", nome);
                strcpy(lista_nomes[num_nomes], nome);
                num_nomes++;
                printf("Nome adicionado com sucesso.\n");
                break;
            case 2:
                imprimir_lista();
                break;
            case 3:
                printf("Digite o indice do nome a ser eliminado: ");
                scanf("%d", &indice);
                eliminar_nome(indice-1);
                break;
            case 4:
                ordenar_lista();
                break;
            case 5:
                printf("Digite o nome a ser inserido na lista ordenada: ");
                scanf(" %s", nome);
                inserir_nome_ordenado(nome);
                break;
            case 6:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 6);

return 0;
}

