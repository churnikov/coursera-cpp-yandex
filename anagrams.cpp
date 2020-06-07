#include <iostream>
#include <vector>
#include <map>


using namespace std;


bool is_anogramm(string w1, string w2) {
    map<char, int> m1;
    map<char, int> m2;
    for (const auto &c : w1) {
        m1[c]++;
    }
    for (const auto &c : w2) {
        m2[c]++;
    }
    return m1 == m2;
}


int main() {
    int q;
    cin >> q;

    for (int i=0; i<q; i++) {
        string w1;
        string w2;

        cin >> w1;
        cin >> w2;

        if (is_anogramm(w1, w2)) {
            cout << "YES";
        } else {
            cout << "NO";
        }
        cout << endl;
    }

    return 0;
}
