#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//1. Escreva uma função que recebe dois pontos x,y (Point) e devolve a distância entre os mesmos.

typedef struct point{
    float x;
    float y;
} Point; //apelido

float distance(Point p1, Point p2){
    float d = sqrt(pow((p1.x - p1.y),2) + pow((p2.x - p2.y),2));
    return d;
}

//2. Considerando a estrutura Point do exercício anterior, escreva uma função que recebe um vetor de
//pontos, bem como seu tamanho, e informa a distância a cada dois pontos consecutivos do vetor.

float distance_vector(int n, Point v[]){
    float d;
    for(int i=0; i<n-1; i++){ //n-1 para que no loop, i+1 n extrapole o tam do vetor
        d = distance(v[i], v[i+1]);
        printf("A distancia entre os pontos v[%d] e v[%d] eh: %f\n", i, i+1, d);
    }
}

//3. Escreva uma função que recebe um vetor de Point e os inicia com valores float aleatórios -50 e 50.

void random_points(int n, Point v[]){
    for (int i=0; i<n; i++){
        v[i].x = ((rand()/(float)RAND_MAX) * 101) - (101/2);
        v[i].y = ((rand()/(float)RAND_MAX) * 101) - (101/2);
    }
    printf("O vetor randomico eh:\n");
    for(int i=0; i<n; i++){
        printf("v[%d] = {%f, %f}\n", i, v[i].x, v[i].y);
    }
}

int main(){
    Point p1 = {5, 7};
    Point p2 = {3, 9};
    printf("A distancia entre os pontos e: %f\n", distance(p1,p2));
    printf("\n");
    Point vet[3] = {{0,1},{0,2},{0,4}};
    distance_vector(3, vet);
    printf("\n");
    Point v[5];
    random_points(5, v);
    printf("\n");
}
