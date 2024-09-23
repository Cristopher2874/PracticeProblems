#include <iostream>
using namespace std;

const int MOD = 1000000007;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N, K;
        cin >> N >> K;
        long long result = (N * (N + 1) / 2) * (K * (K + 1) / 2) % MOD;
        cout << result << endl;
    }
    return 0;
}
