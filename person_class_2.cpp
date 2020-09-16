#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>


using namespace std;


struct PersonInfo {
    string first_name;
    string last_name;
};


class Person {
public:
    void ChangeFirstName(const int& year, const string& first_name) {
        person_info[year].first_name = first_name;
        known_years.insert(year);
    }
    void ChangeLastName(const int& year, const string& last_name) {
        person_info[year].last_name = last_name;
        known_years.insert(year);
    }
    string GetFullName(int year) {
        // получить имя и фамилию по состоянию на конец года year

        string name;
        string surname;

        if (person_info.count(year) != 0){
            name = person_info[year].first_name;
            surname = person_info[year].last_name;
        }

        if (name.empty()) {
            name = GetClosestNotEmptyName(year);
        }

        if (surname.empty()) {
            surname = GetClosestNotEmptySurname(year);
        }

        if (name.empty() && surname.empty()) {
            return "Incognito";
        } else if (name.empty()) {
            return surname + " with unknown first name";
        } else if (surname.empty()) {
            return name + " with unknown last name";
        } else {
            return name + " " + surname;
        }

    }

    string GetFullNameWithHistory(int year) {
        string name;
        string surname;
        vector<string> names = GetAllNotEmptyNames(year);
        vector<string> surnames = GetAllNotEmptySurnames(year);

        if (person_info.count(year) != 0){
            name = person_info[year].first_name;
            surname = person_info[year].last_name;
        }

        if (name.empty()) {
            name = GetClosestNotEmptyName(year);
            int le_year = GetClosestLeftYear(year);
            names = GetAllNotEmptyNames(le_year);
        }

        if (surname.empty()) {
            surname = GetClosestNotEmptySurname(year);
            int le_year = GetClosestLeftYear(year);
            surnames = GetAllNotEmptySurnames(le_year);
        }

        if (!surnames.empty()){
            string prev_surname = surname;
            vector<string> upd_surnames;

            for (const auto& n: surnames){
                if (n != prev_surname){
                    upd_surnames.push_back(n);
                    prev_surname = n;
                }
            }
            if (!upd_surnames.empty()){
                surname += (" (" + upd_surnames[0]);
                for (int i = 1; i < upd_surnames.size(); ++i) {
                    surname += (", " + upd_surnames[i]);
                }
                surname += ")";
            }
        }

        if (!names.empty()){
            string prev_name = name;
            vector<string> upd_names;

            for (const auto& n: names){
                if (n != prev_name){
                    upd_names.push_back(n);
                    prev_name = n;
                }
            }
            if (!upd_names.empty()){
                name += (" (" + upd_names[0]);
                for (int i = 1; i < upd_names.size(); ++i) {
                    name += (", " + upd_names[i]);
                }
                name += ")";
            }
        }

        if (name.empty() && surname.empty()) {
            return "Incognito";
        } else if (name.empty()) {
            return surname + " with unknown first name";
        } else if (surname.empty()) {
            return name + " with unknown last name";
        } else {
            return name + " " + surname;
        }
    }
private:
    set<int> known_years;
    map<int, PersonInfo> person_info;

    int GetClosestLeftYear(const int& year) {
        int previous_le_year = 0;
        for (int y : known_years) {
            if (y >= year) {
                break;
            } else {
                previous_le_year = y;
            }
        }
        return previous_le_year;
    }

    string GetClosestNotEmptyName(const int& year) {
        int perv_year = GetClosestLeftYear(year);
        if (perv_year == 0) {
            return "";
        } else if (person_info[perv_year].first_name.empty()) {
            return GetClosestNotEmptyName(perv_year);
        } else {
            return person_info[perv_year].first_name;
        }
    }

    string GetClosestNotEmptySurname(const int& year) {
        int perv_year = GetClosestLeftYear(year);
        if (perv_year == 0) {
            return "";
        } else if (person_info[perv_year].last_name.empty()) {
            return GetClosestNotEmptySurname(perv_year);
        } else {
            return person_info[perv_year].last_name;
        }
    }

    vector<string> GetAllNotEmptySurnames(const int& qyear){
        vector<string> surnames;
        for (const int& year : known_years) {
            if (year <= qyear){
                string surname = GetClosestNotEmptySurname(year);
                if (!surname.empty()){
                    surnames.push_back(surname);
                }
            }
        }
        reverse(surnames.begin(),surnames.end());
        return surnames;
    }

    vector<string> GetAllNotEmptyNames(const int& qyear){
        vector<string> names;
        for (const int& year : known_years) {
            if (year <= qyear){
                string name = GetClosestNotEmptyName(year);
                if (!name.empty()){
                    names.push_back(name);
                }
            }
        }
        reverse(names.begin(),names.end());
        return names;
    }
};

//int main() {
//    Person person;
//
//    person.ChangeFirstName(1900, "Eugene");
//    person.ChangeLastName(1900, "Sokolov");
//    person.ChangeLastName(1910, "Sokolov");
//    person.ChangeFirstName(1920, "Evgeny");
//    person.ChangeLastName(1930, "Sokolov");
//    cout << person.GetFullNameWithHistory(1940) << endl;
//
//    return 0;
//}

//int main() {
//    Person person;
//
//    person.ChangeFirstName(1965, "Polina");
//    person.ChangeFirstName(1965, "Appolinaria");
//
//    person.ChangeLastName(1965, "Sergeeva");
//    person.ChangeLastName(1965, "Volkova");
//    person.ChangeLastName(1965, "Volkova-Sergeeva");
//
//    for (int year : {1964, 1965, 1966}) {
//        cout << person.GetFullNameWithHistory(year) << endl;
//    }
//
//    return 0;
//}

//int main() {
//    Person person;
//
//    person.ChangeFirstName(1965, "Polina");
//    person.ChangeLastName(1967, "Sergeeva");
//    for (int year : {1900, 1965, 1990}) {
//        cout << person.GetFullNameWithHistory(year) << endl;
//    }
//
//    person.ChangeFirstName(1970, "Appolinaria");
//    for (int year : {1969, 1970}) {
//        cout << person.GetFullNameWithHistory(year) << endl;
//    }
//
//    person.ChangeLastName(1968, "Volkova");
//    for (int year : {1969, 1970}) {
//        cout << person.GetFullNameWithHistory(year) << endl;
//    }
//
//    person.ChangeFirstName(1990, "Polina");
//    person.ChangeLastName(1990, "Volkova-Sergeeva");
//    cout << person.GetFullNameWithHistory(1990) << endl;
//
//    person.ChangeFirstName(1966, "Pauline");
//    cout << person.GetFullNameWithHistory(1966) << endl;
//
//    person.ChangeLastName(1960, "Sergeeva");
//    for (int year : {1960, 1967}) {
//        cout << person.GetFullNameWithHistory(year) << endl;
//    }
//
//    person.ChangeLastName(1961, "Ivanova");
//    cout << person.GetFullNameWithHistory(1967) << endl;
//
//    return 0;
//}

