#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int n, m;
vector<string> words;
vector<string> prefixes;
unordered_map<string, int> prefix_num;
string word, prefix;

int main() {
    cin >> n;
    words.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> words[i];
    }

    cin >> m;
    prefixes.resize(m);
    for (int i = 0; i < m; ++i) {
        cin >> prefixes[i];
    }

    for (const string& p : prefixes) {
        if (prefix_num.find(p) != prefix_num.end()) {
            cout << prefix_num[p] << "\n";
            continue;
        }

        int count = 0;
        for (const string& w : words) {
            if (p.size() <= w.size() && w.compare(0, p.size(), p) == 0) {
                count++;
            }
        }
        prefix_num[p] = count;
        cout << count << "\n";
    }

    return 0;
}