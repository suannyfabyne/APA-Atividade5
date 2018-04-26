#include <stdio.h>
#include <stdlib.h>


#define INF 9999
#define V 4


void displayMST(int graph[V][V], int markedCell[V][V]) {
	
	int r, c;

	for (r = 0; r < V-1; r++) {
		for (c = r+1; c < V; c++) {
			if(markedCell[r][c]) {
				printf("Edge: %d -- %d\tWeight: %d\n", r, c, graph[r][c]);
			}
		}
	}

}


void prim(int graph[V][V]) {

	int i, r, c,
		solved = 0,
		count = 0,
		min,
		expectedR,
		expectedC;

	int markedCell[V][V] = {{0}};

	int markedVertex[V] = {0};
	markedVertex[0] = 1;

	
	while(!solved) {

		min = INF;
		count = 0;
		expectedR = -1;
		expectedC = -1;

		for (r = 0; r < V; r++) {

			if (markedVertex[r] == 1) {

				for (c = r; c < V; c++) {

					if (graph[r][c] != 0 && graph[r][c] < min && !markedCell[r][c]) {

						min = graph[r][c];
						expectedR = r;
						expectedC = c;

					}

				}

			}

		}


		if (expectedR != -1 && expectedC != -1) {
			markedCell[expectedR][expectedC] = 1;
			markedCell[expectedC][expectedR] = 1;
			markedVertex[expectedR] = 1;
			markedVertex[expectedC] = 1;
		}


		for (i = 0; i < V; i++) {
			if (markedVertex[i]) {
				count++;
			}
		}
		if (count == V) {
			solved = 1;
		}

	}

	displayMST(graph, markedCell);

}


int main(void) {
	
	int graph[V][V] = {
		{0, 23, 17, 19},
		{23, 0, 22, 20},
		{17, 22, 0, 25},
		{19, 20, 25, 0}
	};

	prim(graph);

	return 0;
}
