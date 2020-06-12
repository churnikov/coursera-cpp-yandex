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


void all_buses(const map<string, vector<string>>& map_stops_for_bus) {
    if (map_stops_for_bus.empty()) {
        cout << "No buses" << endl;
    } else {
        for (const auto& [bus, stops] : map_stops_for_bus) {
            cout << "Bus " << bus << ": ";
            print_vector(stops);
        }
    }
}


void buses_for_stop(map<string, vector<string>>& map_bs, const string &stop) {
    if (map_bs.count(stop) == 0) {
        cout << "No stop" << endl;
    } else {
        print_vector(map_bs[stop]);
    }
}


void stops_for_bus(map<string, vector<string>>& map_stops_for_bus, map<string, vector<string>>& map_buses_for_stop,
                   const string &bus) {

    if (map_stops_for_bus.count(bus) == 0){
        cout << "No bus" << endl;
    } else {
        const vector<string>& stops = map_stops_for_bus[bus];
        for (const auto& stop : stops) {
            cout << "Stop " << stop << ": ";
            if (map_buses_for_stop[stop].size() == 1) {
                cout << "no interchange" << endl;
            } else {
                print_vector(map_buses_for_stop[stop], bus);
            }
        }
    }
}


int main() {
    int q;
    cin >> q;

    map<string, vector<string>> map_buses_for_stop;
    map<string, vector<string>> map_stops_for_bus;

    for (int i = 0; i < q; i++) {
        string command;
        cin >> command;


        if (command == "NEW_BUS") {
            string bus;
            int stops_count;

            cin >> bus;
            cin >> stops_count;

            for (int n = 0; n < stops_count; n++) {
                string stop;
                cin >> stop;
                map_buses_for_stop[stop].push_back(bus);
                map_stops_for_bus[bus].push_back(stop);
            }
        } else if (command == "BUSES_FOR_STOP") {
            string stop;
            cin >> stop;
            buses_for_stop(map_buses_for_stop, stop);
        } else if (command == "STOPS_FOR_BUS") {
            string bus;
            cin >> bus;
            stops_for_bus(map_stops_for_bus, map_buses_for_stop, bus);
        } else if (command == "ALL_BUSES") {
            all_buses(map_stops_for_bus);
        }
    }

    return 0;
}
