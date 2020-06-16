#include <iostream>
#include <map>
#include <set>
#include <vector>


using namespace std;


int main() {
    int q;
    cin >> q;

    map<string, set<string>> vocab;

    for (int i = 0; i < q; i++) {
        string command;
        cin >> command;

        if (command == "ADD") {
            string word1, word2;
            cin >> word1 >> word2;

            vocab[word1].insert(word2);
            vocab[word2].insert(word1);

        } else if (command == "COUNT") {
            string word;
            cin >> word;

            cout << vocab[word].size() << endl;

        } else if (command == "CHECK") {
            string word1, word2;
            cin >> word1 >> word2;

            if (vocab[word1].count(word2) == 1 && vocab[word2].count(word1) == 1) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}
