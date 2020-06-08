#include <iostream>
#include <vector>
#include <map>


using namespace std;


void dump(const map<string, string> &countries) {
    if (countries.size() == 0) {
        cout << "There are no countries in the world";
    } else {
        for (auto[country, capital] : countries) {
            cout << country << "/" << capital << " ";
        }
    }
}

void about(map<string, string> &countries, const string &country) {
    if (countries.count(country) == 0) {
        cout << "Country " << country << " doesn't exist";
    } else {
        cout << "Country " << country << " has capital " << countries[country];
    }
}


void rename(map<string, string> &countries, string &old_country_name, string &new_country_name) {
    if (old_country_name == new_country_name || countries.count(old_country_name) == 0 ||
        countries.count(new_country_name) != 0) {
        cout << "Incorrect rename, skip";
    } else {
        cout << "Country " << old_country_name << " with capital " << countries[old_country_name]
             << " has been renamed to " << new_country_name;
        countries[new_country_name] = countries[old_country_name];
        countries.erase(old_country_name);
    }
}


void change_capital(map<string, string> &countries, const string &country_name, const string &new_capital_name) {
    if (countries.count(country_name) == 0) {
        cout << "Introduce new country " << country_name << " with capital " << new_capital_name;
        countries[country_name] = new_capital_name;
    } else if (countries[country_name] == new_capital_name) {
        cout << "Country " << country_name << " hasn't changed its capital";
    } else if (countries[country_name] != new_capital_name) {
        cout << "Country " << country_name << " has changed its capital from " << countries[country_name] << " to "
             << new_capital_name;
        countries[country_name] = new_capital_name;
    }
}


int main() {
    int q;
    cin >> q;

    map<string, string> countries;

    for (int i = 0; i < q; i++) {
        string command;
        cin >> command;

        if (command == "CHANGE_CAPITAL") {
            string country_name;
            string new_capital_name;

            cin >> country_name >> new_capital_name;

            change_capital(countries, country_name, new_capital_name);

        } else if (command == "RENAME") {
            string old_country_name;
            string new_country_name;
            cin >> old_country_name >> new_country_name;

            rename(countries, old_country_name, new_country_name);

        } else if (command == "ABOUT") {
            string country_name;
            cin >> country_name;
            about(countries, country_name);

        } else if (command == "DUMP") {
            dump(countries);
        }
        cout << endl;
    }

    return 0;
}
