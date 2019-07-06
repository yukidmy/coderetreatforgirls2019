#include <bits/stdc++.h>
#include <unistd.h> 
#include <random>

using namespace std;

int FIELD_SIZE = 10;

int position(int x, int y) {
    return y * FIELD_SIZE + x;
}

int count(map<int, bool>& field, int x, int y) {
    int sum = 0;
    for (int i = x > 0 ? x - 1 : 0; i < (x < FIELD_SIZE - 1 ? x + 2 : FIELD_SIZE); i++) { for (int j = y > 0 ? y - 1 : y; j < (y < FIELD_SIZE - 1 ? y + 2 : FIELD_SIZE); j++) { if (i == x && j == y) continue; sum += field[position(i, j)]; } } 
    return sum;
}

void update(map<int, bool>& field) {
    map<int, bool> updated_field(field);
    for (int i = 0; i < FIELD_SIZE; i++) { for (int j = 0; j < FIELD_SIZE; j++) { int alive = count(field, i, j); if ((field[position(i, j)] && (alive < 2 || alive > 3)) || (!field[position(i, j)] && alive == 3)) updated_field[position(i, j)] = !field[position(i, j)]; } }
    field = updated_field;
}

void show(map<int, bool>& field) {
    for (int i = 0; i < FIELD_SIZE; i++) { for (int j = 0; j < FIELD_SIZE; j++) { field[position(i, j)] ? cout << "■ " : cout << "□ "; } cout << endl; }
    cout << "---" << endl;
}

map<int, bool> init() {
    map<int, bool> mp; std::random_device rnd;
    for (int i = 0; i < FIELD_SIZE; i++) { for (int j = 0; j < FIELD_SIZE; j++) { mp[position(i, j)] = rnd() % 2; } }
    return mp;
}

int main() {
    map<int, bool> life = init();
    while (true) { show(life); update(life); sleep(1); }
    return 0;
}