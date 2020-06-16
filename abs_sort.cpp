#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>


using namespace std;


void print_vector(const vector<int> &vec) {
    for (const auto &e : vec) {
        cout << e << " ";
    }
    cout << endl;
}


int main() {
    vector<int> values;
    int n_vals;
    cin >> n_vals;
    for (int k = 0; k < n_vals; ++k) {
        int val;
        cin >> val;

        values.push_back(val);
    }

    sort(begin(values), end(values), [](int a, int b){return abs(a) < abs(b);});
    print_vector(values);

    return 0;
}
