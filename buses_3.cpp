#include <iostream>
#include <map>
#include <set>
#include <vector>


using namespace std;


int main() {
    int q;
    cin >> q;

    map<set<string>, int> routes;

    for (int i = 0; i < q; i++) {
        int n_stops;
        cin >> n_stops;

        set<string> route;

        for (int j = 0; j < n_stops; ++j) {
            string station;
            cin >> station;

            route.insert(station);
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
