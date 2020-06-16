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
};

//int main() {
//    Person person;
//
//    person.ChangeFirstName(1965, "Polina");
//    person.ChangeLastName(1967, "Sergeeva");
//    for (int year : {1900, 1965, 1990}) {
//        cout << person.GetFullName(year) << endl;
//    }
//
//    person.ChangeFirstName(1970, "Appolinaria");
//    for (int year : {1969, 1970}) {
//        cout << person.GetFullName(year) << endl;
//    }
//
//    person.ChangeLastName(1968, "Volkova");
//    for (int year : {1969, 1970}) {
//        cout << person.GetFullName(year) << endl;
//    }
//
//    return 0;
//}

//int main() {
//    Person person;
//
//    cout << person.GetFullName(2000) << endl;
//
//    person.ChangeLastName(1968, "1968_2nd");
//    person.ChangeLastName(1967, "1967_2nd");
//    person.ChangeLastName(1965, "1965_2nd");
//    person.ChangeLastName(1966, "1966_2nd");
//
//    for (int year : {1900, 1920, 1950, 1965, 1966, 1967, 1968}) {
//        cout << person.GetFullName(year) << endl;
//    }
//
//    person.ChangeFirstName(1920, "1920_1st");
//    person.ChangeFirstName(1900, "1900_1st");
//    person.ChangeFirstName(1965, "1965_1st");
//    person.ChangeFirstName(1950, "1950_1st");
//
//    for (int year : {1900, 1920, 1950, 1965, 1966, 1967, 1968}) {
//        cout << person.GetFullName(year) << endl;
//    }
//
//
//    return 0;
//}
