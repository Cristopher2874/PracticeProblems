#include <bits/stdc++.h>
using namespace std;

// Función para hacer BFS desde una celda dada y contar el tamaño de la isla
int bfs(int R, int C, vector<vector<int>>& G, vector<vector<bool>>& visited, int startX, int startY) {
    // Movimientos para desplazarse en las 4 direcciones (derecha, izquierda, abajo, arriba)
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    queue<pair<int, int>> q;
    q.push({startX, startY});
    visited[startX][startY] = true;  // Marcar el punto inicial como visitado

    int islandSize = 0;  // Para contar el tamaño de la isla

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        islandSize++;  // Cada vez que saquemos un elemento de la cola, contamos una celda de la isla

        // Explorar las 4 direcciones (arriba, abajo, izquierda, derecha)
        for (auto dir : directions) {
            int newX = x + dir.first;
            int newY = y + dir.second;

            // Verificar si la nueva posición está dentro de los límites de la matriz y no ha sido visitada
            if (newX >= 0 && newX < R && newY >= 0 && newY < C && !visited[newX][newY] && G[newX][newY] == 1) {
                q.push({newX, newY});
                visited[newX][newY] = true;  // Marcar la nueva posición como visitada
            }
        }
    }

    return islandSize;  // Retornar el tamaño de la isla encontrada
}

// Función principal para encontrar la isla más grande
int getLargestIsland(int R, int C, vector<vector<int>> G) {
    vector<vector<bool>> visited(R, vector<bool>(C, false));  // Matriz para rastrear celdas visitadas
    int largestIsland = 0;  // Para guardar el tamaño de la isla más grande

    // Recorrer toda la matriz
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            // Si encontramos un `1` no visitado, hacemos BFS para explorar la isla
            if (G[i][j] == 1 && !visited[i][j]) {
                int islandSize = bfs(R, C, G, visited, i, j);
                largestIsland = max(largestIsland, islandSize);  // Actualizar el tamaño de la isla más grande
            }
        }
    }

    return largestIsland;  // Retornar el tamaño de la isla más grande
}

int main() {
    // Definir el grid (matriz)
    vector<vector<int>> G = {
        {0, 0, 1},
        {1, 0, 1}
    };
    
    int R = G.size();     // Número de filas
    int C = G[0].size();  // Número de columnas

    // Llamada a la función que encuentra la isla más grande
    int largestIslandSize = getLargestIsland(R, C, G);

    // Imprimir el resultado
    cout << "El tamaño de la isla más grande es: " << largestIslandSize << endl;

    return 0;
}
