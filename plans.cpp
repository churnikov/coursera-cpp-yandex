#include <iostream>
#include <vector>


using namespace std;


void dump(const vector<string> &vec) {
    cout << vec.size() << " ";
    if (vec.size() != 0) {
        for (auto e : vec) {
            cout << e << " ";
        }
    }
    cout << endl;
}


int get_next_month(int cur_month) {
    if (cur_month >= 11) {
        return 0;
    } else {
        return cur_month + 1;
    }
}


int get_days_in_month(int month_idx) {
    int n_days;
    vector<int> tmp = {1, 2};
    if (month_idx == 1) {
        n_days = 28;
    } else {
        n_days = 30;
        n_days += (
                month_idx == 0 ||
                month_idx == 2 ||
                month_idx == 4 ||
                month_idx == 6 ||
                month_idx == 7 ||
                month_idx == 9 ||
                month_idx == 11
        );
    }

    return n_days;
}


void update_todo(int &month_idx, vector<vector<string>> &cur_month) {

    int new_cur_month_idx = get_next_month(month_idx);
    int new_cur_month_size = get_days_in_month(new_cur_month_idx);

    if (new_cur_month_size > cur_month.size()) {
        cur_month.resize(new_cur_month_size);
    } else if (new_cur_month_size < cur_month.size()) {
        vector<vector<string>> new_cur_month = cur_month;
        new_cur_month.resize(new_cur_month_size);
        int last_day_of_new_cur_month = new_cur_month_size - 1;
        for (int i = new_cur_month_size; i < cur_month.size(); i++) {
            new_cur_month[last_day_of_new_cur_month].insert(
                    end(new_cur_month[last_day_of_new_cur_month]),
                    begin(cur_month[i]),
                    end(cur_month[i])
            );
        }
        cur_month = new_cur_month;
    }

    month_idx = new_cur_month_idx;

}


int main() {
    int n_ops;
    int month_idx = 0;
    string op;
    cin >> n_ops;

    vector<vector<string>> plans(31);

    for (int _ = 0; _ < n_ops; _++) {
        cin >> op;
        if (op == "NEXT") {
            update_todo(month_idx, plans);
        } else if (op == "DUMP") {
            int day;
            cin >> day;
            dump(plans[day - 1]);
        } else if (op == "ADD") {
            int day;
            string task;
            cin >> day >> task;
            plans[day - 1].push_back(task);
        }

    }


    return 0;
}
