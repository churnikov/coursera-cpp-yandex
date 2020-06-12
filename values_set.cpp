#include <iostream>
#include <vector>
#include <set>


using namespace std;


int main() {
    int q;
    cin >> q;

    set<string> strings;

    for (int i = 0; i < q; i++) {
        string _str;
        cin >> _str;

        strings.insert(_str);
    }

    cout << strings.size();

    return 0;
}
