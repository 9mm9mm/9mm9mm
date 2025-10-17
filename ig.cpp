#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <string>

using namespace std;

// Класс T
class T {
public:
    int P;                 // Число P_i
    vector<int> values;    // Вектор целых чисел

    // Конструктор
    T(int p, const vector<int>& vals) : P(p), values(vals) {}

    // Сортировка строки
    void sortRow() {
        if (P == 1)
            sort(values.begin(), values.end(), greater<int>()); // По убыванию
        else
            sort(values.begin(), values.end());                 // По возрастанию
    }

    // Получение последнего элемента строки
    int last() const {
        if (values.empty()) return 0;
        return values.back();
    }
};

// Функция чтения данных
bool readData(const string& filename, vector<T*>& arr) {
    ifstream fin(filename);
    if (!fin.is_open())
        return false;

    string line;
    while (getline(fin, line)) {
        if (line.empty()) continue;

        istringstream iss(line);
        int P;
        if (!(iss >> P)) return false;

        vector<int> row;
        int x;
        while (iss >> x) row.push_back(x);

        // Если строка пуста — ошибка
        if (row.empty()) return false;

        arr.push_back(new T(P, row));
    }

    fin.close();
    return !arr.empty();
}

int main() {
    vector<T*> matrix;

    // Чтение из файла
    if (!readData("data.dat", matrix)) {
        ofstream fout("data.res");
        fout << "ERROR";
        fout.close();
        return 0;
    }

    // Сортировка каждой строки
    for (auto& row : matrix)
        row->sortRow();

    // Сортировка строк по последнему элементу
    sort(matrix.begin(), matrix.end(),
         [](T* a, T* b) { return a->last() < b->last(); });

    // Запись результата
    ofstream fout("data.res");
    if (!fout.is_open()) {
        cerr << "Cannot open data.res\n";
        return 0;
    }

    for (auto& row : matrix) {
        fout << row->P;
        for (int val : row->values)
            fout << " " << val;
        fout << "\n";
    }

    fout.close();

    // Очистка памяти
    for (auto& row : matrix)
        delete row;

    return 0;
}