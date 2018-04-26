#include <stdio.h>
#include <stack>
 
#define fori(i, b, n) for(int i = b; i<n; ++i)


using namespace std;
 
 
struct aresta{
    int v1;
    int v2;
    int peso;
};
 
int ciclo[101];	
void unir(int v1, int v2); 
int pai(int x);				
void countSort( aresta *A, int tamanhoVetor );	
 
 
 
 
 
int main (){
 
    int n, m;
 
    scanf("%d %d", &n, &m);

    aresta arestas[m];
 

	fori(i, 0, n){ 
		ciclo[i] = i;
	}
 
 
	fori(i, 0, m){
		scanf("%d %d %d", &arestas[i].v1, &arestas[i].v2, &arestas[i].peso);
	}
 
 	countSort(arestas, m);
 
 
	fori(i, 0, m){
 
		if ( pai(arestas[i].v1) != pai(arestas[i].v2) ){ 
 
			if(arestas[i].v1 < arestas[i].v2){
				printf("%d %d\n", arestas[i].v1, arestas[i].v2);
			}
			else{
				printf("%d %d\n", arestas[i].v2, arestas[i].v1);
			}
 
			unir(arestas[i].v1, arestas[i].v2);
		}
 
	}
	printf("\n");
}
 
 
 
 
 
void unir(int v1, int v2){
    ciclo[pai(v1)] = pai(v2);
}
 
 
 
 
int pai(int v){
 
    if (ciclo[v] == v){
        return v;
	}
 
    ciclo[v] = pai(ciclo[v]);
 
    return ciclo[v];
}
 
 
 
 
void countSort( aresta *A, int tamanhoVetor ){
	stack<aresta> peso[101]; 
 
 
	fori(i, 0, tamanhoVetor){
		peso[A[i].peso].push(A[i]);
	}
 
	int j=0;
	for(int i=0; i<tamanhoVetor; i++){
		while( peso[j].empty() ){ 
			j++;
		}
 
		A[i] = peso[j].top();
		peso[j].pop();
		j--;
	}
 
 
}

