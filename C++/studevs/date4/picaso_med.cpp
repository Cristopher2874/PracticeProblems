#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int ways = (N * (N + 1) / 2) * (M * (M + 1) / 2);

    cout << ways << endl;
    return 0;
}
