#include <bits/stdc++.h>
using namespace std;

long long max_additional_diners(long long N, long long K, long long M, vector<long long> S) {
    vector<bool> occupied(N + 1, false);
    try
    {
        for (long long seat : S) {
        if (seat < 1 || seat > N) continue;
        occupied[seat] = true;
        for (long long i = max(1LL, seat - K); i < seat; ++i) {
            occupied[i] = true;
        }

        for (long long i = seat + 1; i <= std::min(N, seat + K); ++i) {
            occupied[i] = true;
        }
    }

    long long additional_diners = 0;
    for (long long i = 1; i <= N; ) {
        if (!occupied[i]) {
            additional_diners++;
            i += K + 1;
        } else {
            i++;
        }
    }

    return additional_diners;
    }
    catch(exception e)
    {
        return 0;
    }
}

int main() {
    // Sample test cases
    std::cout << max_additional_diners(10, 1, 2, {2, 6}) << std::endl;  // Expected output: 3
    std::cout << max_additional_diners(15, 2, 3, {11, 6, 14}) << std::endl;  // Expected output: 1
    return 0;
}