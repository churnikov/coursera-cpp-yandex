#include <iostream>
#include <vector>
#include <map>


using namespace std;


void print_vector(const vector<string> &vec, const string& exclude = "") {
    for (const auto &e : vec) {
        if (e != exclude) {
            cout << e << " ";
        }
    }
    cout << endl;
}


int main() {
    int q;
    cin >> q;

    map<vector<string>, int> routes;

    for (int i = 0; i < q; i++) {
        int n_stations;
        cin >> n_stations;

        vector<string> route;

        for (int j = 0; j < n_stations; ++j) {
            string station;
            cin >> station;

            route.push_back(station);
        }

        if (routes.count(route) == 0) {
            int new_bus = routes.size() + 1;
            routes[route] = new_bus;
            cout << "New bus " << new_bus << endl;
        } else {
            cout << "Already exists for " << routes[route] << endl;
        }
    }

    return 0;
}
