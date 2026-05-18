#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n = 4;

  vector<vector<int>> M(n, vector<int>(n));

  int top = 0;
  int bottom = n - 1;
  int left = 0;
  int right = n - 1;

  int num = n * n;

  while (top <= bottom && left <= right) {

    // izquierda -> derecha
    for (int j = left; j <= right; j++) {
      M[bottom][j] = num--;
    }
    bottom--;

    // abajo -> arriba
    for (int i = bottom; i >= top; i--) {
      M[i][right] = num--;
    }
    right--;

    // derecha -> izquierda
    for (int j = right; j >= left; j--) {
      M[top][j] = num--;
    }
    top++;

    // arriba -> abajo
    for (int i = top; i <= bottom; i++) {
      M[i][left] = num--;
    }
    left++;
  }

  // Mostrar matriz
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << M[i][j] << "\t";
    }
    cout << endl;
  }

  return 0;
}
