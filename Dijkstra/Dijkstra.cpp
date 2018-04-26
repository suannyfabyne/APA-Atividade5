#include <stdio.h>
#include <vector>
#include <list>	
 
#define fori(i, b, n) for(int i = b; i<n; ++i)
#define inf 10000002 

 
using namespace std;
 
int pesos[251][251];
list<int> index;	
list<int>::iterator it, aux;
 
int main(){
 
	int n, m, v1, v2, peso, explorando, menor, inicio, fim, custo, vis;
 
	scanf("%d %d", &n, &m);
 
	inicio = 0;
	fim = n;
 
	vector<int> adj[n+1];
	int estimativa[n+1];
	bool aberto[n+1];
 
	fori(i, 0, n+1){
		estimativa[i] = inf;
		aberto[i] = true;
	}
 
	fori(i, 0, m){
		scanf("%d %d %d", &v1, &v2, &peso); 
 
		pesos[v1][v2] = peso;
		pesos[v2][v1] = peso;
 
		adj[v2].push_back(v1);
		adj[v1].push_back(v2);	
	}
 
 
 
 
 
	estimativa[inicio] = 0;
	index.push_back(inicio);
 
	while( !index.empty()){
		menor = inf;
		for( it = index.begin(); it != index.end(); ++it){
			vis = (*it);
			if(estimativa[vis] < menor){
				menor = estimativa[vis];
				explorando = vis;
				aux = it;
			}			
		}
 
		index.erase(aux);
		aberto[explorando] = false;
 
 
		fori(i, 0, int(adj[explorando].size())){
			vis = adj[explorando][i];
 
			if(aberto[vis]){
				custo = pesos[explorando][vis] + estimativa[explorando];
 
				if(estimativa[vis] == inf){
					estimativa[vis] = custo;
					index.push_back(vis);
				}
				else{
					if(custo < estimativa[vis]){
						estimativa[vis] = custo;
					}
				}
			}
		}
	}
 
 
 
 
	//imprimindo o resultado:
	if(estimativa[fim] == inf){
		printf("NO\n");	//informar que o vertice inicial nao chega no final
	}
	else{
		printf("%d\n", estimativa[fim]);
	}
 
	index.clear();
 
}
