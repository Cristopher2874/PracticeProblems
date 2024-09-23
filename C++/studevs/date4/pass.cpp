#include <iostream>
#include <bitset>

using namespace std;

int main() {
    int N;
    cin >> N;
    long long sum = 0;
    for (int i = 1; i <= N; ++i) {
        int value = 2 * i;
        bitset<32> binary(value);
        sum += binary.to_ulong();
    }
    cout << sum << endl;
    return 0;
}
