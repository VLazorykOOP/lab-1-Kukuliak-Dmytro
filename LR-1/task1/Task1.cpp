#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Функція для введення масиву з консолі
vector<int> inputArray() {
    vector<int> arr;
    int n;
    cout << "Введіть розмір масиву: ";
    cin >> n;

    cout << "Введіть " << n << " елементів масиву:" << endl;
    for (int i = 0; i < n; i++) {
        int element;
        cin >> element;
        arr.push_back(element);
    }

    return arr;
}

// Функція для запису масиву у текстовий файл
void writeArrayToFile(const vector<int>& arr, const string& filename) {
    ofstream file(filename);

    if (!file.is_open()) {
        cout << "Помилка відкриття файлу " << filename << endl;
        return;
    }

    for (const int& element : arr) {
        file << element << " ";
    }

    file.close();
    cout << "Масив успішно записано у файл " << filename << endl;
}

int main() {
    vector<int> myArray = inputArray();
    string filename = "output.txt"; // Вкажіть ім'я файлу, у який ви хочете записати масив

    writeArrayToFile(myArray, filename);

    return 0;
}
