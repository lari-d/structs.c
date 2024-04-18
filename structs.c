#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct point{
    float x;
    float y;
} Point; //apelido

//1. Escreva uma função que recebe dois pontos x,y (Point) e devolve a distância entre os mesmos.

float distance(Point p1, Point p2){
    float d = sqrt(pow((p2.x - p1.x),2) + pow((p2.y - p1.y),2));
    return d;
}

//2. Considerando a estrutura Point do exercício anterior, escreva uma função que recebe um vetor de
//pontos, bem como seu tamanho, e informa a distância a cada dois pontos consecutivos do vetor.

void distance_vector(int n, Point v[]){
    float d;
    for(int i=0; i<n-1; i++){ //n-1 para que no loop, i+1 n extrapole o tam do vetor
        d = distance(v[i], v[i+1]);
        printf("A distancia entre os pontos v[%d] e v[%d] eh: %f\n", i, i+1, d);
    }
}

//3. Escreva uma função que recebe um vetor de Point e os inicia com valores float aleatórios -50 e 50.

void random_points(int n, Point v[]){
    for(int i=0; i<n; i++){
        v[i].x = ((rand()/(float)RAND_MAX) * 101) - (101/2);
        v[i].y = ((rand()/(float)RAND_MAX) * 101) - (101/2);
    }
    printf("O vetor randomico eh:\n");
    for(int i=0; i<n; i++){
        printf("v[%d] = {%f, %f}\n", i, v[i].x, v[i].y);
    }
}

//4. Escreva uma função que recebe um vetor de Point e encontra os dois pontos mais próximos, isto é,
//aqueles que possuem a menor distância. A função deve imprimir os dois pontos mais próximos - (X1,Y1) e (X2,Y2)- além da distância.

//função que calcula fatorial
int fatorial(int n){
    int a=1;
    for(int i=n; i>=1; i--){
        a = a*i;
    }
    return a;
}

//função que faz a combinação de todos os pontos 
int combinacao(int n){
    int a = fatorial(n);
    int c = a/(2 * fatorial(n-2));
    return c;
}

//algoritmo de ordenação
void bubbleSort(int* v, int n){
    int aux;
    for(int i=0; i<n; i++){

    }
}

//função que encontra menores distâncias
void nearest_points(int n, Point v[]){
    int a = combinacao(n);
    //criando um vetor que vai receber todas as distancias possíveis
    float vector_dist[a];
    int count=0;
    //calcular distancia entre os pontos
    for(int i=0; i<n-1; i++){//para não calcular a distancia de um numero à ele mesmo
        for(int j=i+1; j<n; j++){
            float d = distance(v[i], v[j]);
            vector_dist[count] = d;
            printf("%f\t",vector_dist[count]);
            count++;
        }
    }
    printf("\nvetor de distancias: v = { ");
    for(int i=0; i<a;i++){
        printf("%f ", vector_dist[i]);
    }
    printf("}");

}

int main(){
    //Point p1 = {5, 7};
    //Point p2 = {3, 9};
    //printf("A distancia entre os pontos e: %f\n", distance(p1,p2));
    //printf("\n");
    Point vet[3] = {{0,1},{0,2},{0,4}};
    //distance_vector(3, vet);
    //printf("\n");
    //Point v[5];
    //random_points(5, v);
    //printf("\n");
    nearest_points(3, vet);

    return 0;
}
