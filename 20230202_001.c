#include <stdio.h>
#include <string.h>

#define NUM_EQUIPES 5
#define TAM_NOME 20
#define TAM_SOBRENOME 30
#define TAM_NOME_COMPLETO (TAM_NOME + TAM_SOBRENOME)

int main() {
    char nomes_completos[NUM_EQUIPES][4][TAM_NOME_COMPLETO];
    char nome_busca[TAM_NOME_COMPLETO];
    int i, j, equipe = -1;
    
   
    for (i = 0; i < NUM_EQUIPES; i++) {
        printf("Equipe %d:\n", i+1);
        for (j = 0; j < 4; j++) {
            printf("Digite o nome e sobrenome do aluno %d: ", j+1);
            scanf("%s %s", nomes_completos[i][j], nomes_completos[i][j]+TAM_NOME);
        }
        printf("\n");
    }
    
    
    printf("Digite o nome e sobrenome do aluno que deseja buscar: ");
    scanf("%s %s", nome_busca, nome_busca+TAM_NOME);
    
    for (i = 0; i < NUM_EQUIPES; i++) {
        for (j = 0; j < 4; j++) {
            if (strcmp(nome_busca, nomes_completos[i][j]) == 0) {
                equipe = i+1;
                break;
            }
        }
        if (equipe != -1) {
            break;
        }
    }
    
    
    if (equipe != -1) {
        printf("%s faz parte da equipe %d.\n", nome_busca, equipe);
    } else {
        printf("%s nao foi encontrado nas equipes.\n", nome_busca);
    }
    
    return 0;
}
