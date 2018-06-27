#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <time.h>

#define LIM 50
int nGlobal = 0;

//USAR O TYPEDEF SO PARA AS OPERAÇÕES E RETORNAR UM STRUCT PRA MANDAR PRA MATRIZ C
typedef struct matriz{
        int linhas;
        int colunas;
    } matriz;

void rand_Matriz(float mat[][LIM],struct matriz m){
    srand(time(NULL)); //SÓ PRA MUDAR O RANDON A CADA TESTE

    for(int i = 0; i< m.linhas; i++){
        for(int j = 0; j < m.colunas; j++){
            mat[i][j] = rand() % 10;
        }
    }
    printf("Matriz preenchida aleatoriamente.\n\n");
}

void manu_Matriz(float mat[][LIM], struct matriz m){
    for(int i = 0; i< m.linhas; i++){
        for(int j = 0; j < m.colunas; j++){
            printf("\nDigite o valor da linha %d e coluna %d: \n", i+1, j+1);
            scanf("%f", &mat[i][j]);
        }
    }
    printf("Matriz preenchida manualmente.\n\n");
}

void imprime_Matriz(float matriz[][LIM], struct matriz m){
    printf("-----------IMPRIMINDO MATRIZ-----------\n");
    for(int i = 0; i < m.linhas; i++){
        for(int j = 0; j < m.colunas; j++){
            printf("%.2f ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

matriz somaMatriz(float matA[][LIM], float matB[][LIM], float matC[][LIM], struct matriz mA){
    for(int i = 0; i < mA.linhas; i++){
        for(int j = 0; j < mA.colunas; j++){
            matC[i][j] = matA[i][j] + matB[i][j];
        }
    }
    printf("Soma executada, selecione a opção 12 pra visualizar a nova matriz C.\n\n");
    return mA;
}
matriz subMatriz(float matA[][LIM], float matB[][LIM], float matC[][LIM], struct matriz mA){
    for(int i = 0; i < mA.linhas; i++){
        for(int j = 0; j < mA.colunas; j++){
            matC[i][j] = matA[i][j] - matB[i][j];
        }
    }
    printf("Subtração executada, selecione a opção 12 pra visualizar a nova matriz C.\n\n");
    return mA;
}
matriz multMatriz(float matA[][LIM], float matB[][LIM], float matC[][LIM], struct matriz mA, struct matriz mB){
    struct matriz mC;
    mC.colunas = mA.colunas;
    mC.linhas = mB.linhas;

    float aux = 0;
    for(int i = 0; i < mA.linhas; i++){
        for(int j = 0; j< mB.colunas; j++){
            matC[i][j] = 0;
            for(int k = 0; k < mB.linhas; k++){
                aux += matA[i][k]*matB[k][j];
            }
            matC[i][j] = aux;
            aux = 0;
        }
    }
    printf("Multiplicação executada, pressione 12 para visualizar a nova matriz.\n");
    return mC;
}

void setaMatArquivo(float mat[][LIM], struct matriz m){
    FILE *f;
    int l, c;

    f = fopen("C:/Users/SALA\ DE\ AULA/Desktop/matrix.txt","r");
    if (f == NULL) {
        printf("O arquivo não foi localizado.");
        return;
    }
    fscanf(f, "%d", &l);
    fscanf(f, "%d", &c);

    m.linhas = l;
    m.colunas = c;

    for(int i = 0; i < m.linhas; i++){
        for(int j = 0; j < m.colunas; j++){
            fscanf(f, "%f", &mat[i][j]);
        }
    }

    printf("A matriz foi preenchida pressione 10(se for A) ou 11(se for B) para visualiza-la");
    fclose(f);
}
void escreveMatC(float matC[][LIM], struct matriz mC){
    FILE *f;
    f = fopen("C:/Users/SALA\ DE\ AULA/Desktop/matrizC.txt","w");

    fprintf(f, "%d %d \n", mC.linhas, mC.colunas);
    for(int i = 0; i < mC.linhas; i++){
        for(int j = 0; j < mC.colunas; j++){
            fprintf(f,"%.2f ", matC[i][j]);
        }
        fprintf(f, "\n");
    }
    printf("Matriz estrita no arquivo, procure o arquivo para visualiza-la.");
    fclose(f);
}
int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "Portuguese");

    struct matriz matrizA;
    struct matriz matrizB;
    struct matriz matrizC;
    float matizA[LIM][LIM];
    float matizB[LIM][LIM];
    float matizC[LIM][LIM];

    FILE *f;
    int l, c;

while(nGlobal != 16){
    printf("\nPROGRAMA DE MANIPULACAO DE MATRIZES\n(1) Definir o tamanho da matriz A\n(2) Definir o tamanho da matriz B\n");
    printf("(3) Preencher a matriz A com valores aleatórios\n(4) Preencher a matriz B com valores aleatórios\n");
    printf("(5) Atribuir valores manualmente para os elementos da matriz A\n(6) Atribuir valores manualmente para os elementos da matriz B\n");
    printf("(7) Calcular A+B\n(8) Calcular A-B\n(9) Calcular A*B\n(10) Imprimir matriz A\n(11) Imprimir matriz B\n(12) Imprimir matriz C\n");
    printf("(13) Ler a matriz A de um arquivo\n(14) Ler a matriz B de um arquivo\n(15) Escrever a matriz C em um arquivo\n(16) Sair\n");
    printf("Digite sua operação: ");
    scanf("%d", &nGlobal);

    switch(nGlobal){
        case 1:
            printf("===> Quantidade de linhas de A:");
            scanf("%d", &matrizA.linhas);
            printf("\n===> Quantidade de colunas de A:");
            scanf("%d", &matrizA.colunas);
            printf("Dimensões da Matriz A definidas, para começar a preenche-la pressione 3 ou 5\n");
            break;
        case 2:
            printf("===> Quantidade de linhas de B:");
            scanf("%d", &matrizB.linhas);
            printf("\n===> Quantidade de colunas de B:");
            scanf("%d", &matrizB.colunas);
            printf("Dimensões da Matriz A definidas, para começar a preenche-la pressione 4 ou 6\n");
            break;
        case 3:
            rand_Matriz(matizA, matrizA);
            break;
        case 4:
            rand_Matriz(matizB, matrizB);
            break;
        case 5:
            manu_Matriz(matizA, matrizA);
            break;
        case 6:
            manu_Matriz(matizB, matrizB);
            break;
        case 7:
            if(matrizA.linhas == matrizB.linhas && matrizA.colunas == matrizB.colunas){
            matrizC = somaMatriz(matizA, matizB, matizC, matrizA);
        }else{
            printf("A dimensões das matrizes são diferentes entre si, tente redefinir seus tamanhos.");
        }
            break;
        case 8:
            if(matrizA.linhas == matrizB.linhas && matrizA.colunas == matrizB.colunas){
            matrizC = subMatriz(matizA, matizB, matizC, matrizA);
        }else{
            printf("A dimensões das matrizes são diferentes entre si, tente redefinir seus tamanhos.");
        }
            break;
        case 9:
            if(matrizA.colunas == matrizB.linhas){
                matrizC = multMatriz(matizA, matizB, matizC, matrizA, matrizB);
            }else{
                printf("A multiplicação não pode ser executada, edite as dimensões das matrizes e tente novamente");
            }
            break;
        case 10:
            imprime_Matriz(matizA, matrizA);
            break;
        case 11:
            imprime_Matriz(matizB, matrizB);
            break;
        case 12:
            imprime_Matriz(matizC, matrizC);
            break;
        case 13:
            setaMatArquivo(matizA, matrizA);
            break;
        case 14:
            setaMatArquivo(matizB, matrizB);
            break;
        case 15:
            escreveMatC(matizC, matrizC);
            break;
        case 16:
            exit(0);
        default :
            printf ("Valor invalido!\n");
    }
}
    return 0;
}
