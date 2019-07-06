#include <bits/stdc++.h>
#include <unistd.h> 
#include <random>

#define FIELD_SIZE 5

using namespace std;


vector<vector<int>> createInitField() {
    vector<vector<int>> field(FIELD_SIZE);
    std::random_device rnd;
    for (auto itr = field.begin(); itr != field.end(); ++itr) {
        vector<int> f;
        for (int i = 0; i < FIELD_SIZE; i++) {
            f.push_back(rnd() % 2);
        }
        *itr = f;
    }
    return field;
}

void printField(vector<vector<int>> field) {
    for (int x = 0; x < FIELD_SIZE; x++) {
        for (int y = 0; y < FIELD_SIZE; y++) {
            cout << (field[y][x] ? "🦄 " : "🌱 ");
        }
        cout << endl;
    }
    cout << "---" << endl;
}

int countAlive(vector<vector<int>> field, int x, int y) {
    int sum = 0;
    for (int i = x > 0 ? x - 1 : 0; i < (x < FIELD_SIZE - 1 ? x + 2 : FIELD_SIZE); i++) {
        for (int j = y > 0 ? y - 1 : 0; j < (y < FIELD_SIZE - 1 ? y + 2 : FIELD_SIZE); j++) {
            sum += field[j][i];
        }
    }
    return sum -= field[y][x];
}

void updateField(vector<vector<int>>& field) {
    vector<vector<int>> next_field(field);
    for (int x = 0; x < FIELD_SIZE; x++) {
        for (int y = 0; y < FIELD_SIZE; y++) {
            int count = countAlive(field, x, y);
            if (field[y][x] == 0 && count == 3) next_field[y][x] = 1;
            if (field[y][x] == 1 && (count < 2 || count > 3)) next_field[y][x] = 0;
        }
    }    
    field = next_field;
}

int main() {
    vector<vector<int>> field = createInitField();
    while (true) {
        printField(field);
        updateField(field);
        sleep(1);
    }
    return 0;
}