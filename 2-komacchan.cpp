#include <bits/stdc++.h>

using namespace std;

int FIELD_SIZE = 5;

int position(int x, int y) {
    return y * FIELD_SIZE + x;
}

int count(map<int, bool>& field, int x, int y) {
    int sum = 0;
    for (int i = x > 1 ? x - 1 : 0; i < (x < FIELD_SIZE - 2 ? x + 2 : FIELD_SIZE); i++) {
        for (int j = y > 1 ? y - 1 : y; j < (y < FIELD_SIZE - 2 ? y + 2 : FIELD_SIZE); j++) {
            if (i == x && j == y) continue;
            sum += field[position(i, j)];
        }
    }
    return sum;
}

void update(map<int, bool>& field) {
    map<int, bool> updated_field(field);
    for (int i = 0; i < FIELD_SIZE; i++) {
        for (int j = 0; j < FIELD_SIZE; j++) {
            int alive = count(field, i, j);
            if (field[position(i, j)] && (alive < 2 || alive > 3)) updated_field[position(i, j)] = false;
            else if (!field[position(i, j)] && alive == 3) updated_field[position(i, j)] = true;
        }
    }
    field = updated_field;
}

void show(map<int, bool>& field) {
    for (int i = 1; i < FIELD_SIZE - 1; i++) {
        for (int j = 1; j < FIELD_SIZE - 1; j++) {
            if (field[position(i, j)]) cout << "■";
            else cout << "□";
        }
        cout << endl;
    }
}

int main() {
    map<int, bool> life = {
        // position()
    };

    while (true) {
        show(life);
        update(life);
    }
}