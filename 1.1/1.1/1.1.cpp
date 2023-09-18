#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<int> inputArray() {
    srand(time(NULL));
    vector<int> arr;
    int n = rand()%10+3;
    for (int i = 0; i < n; i++) {
        arr.push_back(rand()%20-10);
    }
        return arr;
}


void writeArrayToFile(const vector<int>& arr, const string& filename) {
    ofstream file(filename);

    if (!file.is_open()) {
        cout << "Error opening file " << filename << endl;
        return ;
    }

    for (const int& element : arr) {
        file << element << " ";
    }

    file.close();
}

void readAndRemovePositive(vector<int>& arr, const string& filename) {
    ifstream file(filename);
    arr.clear();

    if (!file.is_open()) {
        cout << "Error opening file " << filename << endl;
        return;
    }

    int element;
    while (file >> element) {
        if (element <= 0) {
            arr.push_back(element);
        }
    }

    file.close();
}

int main() {
    vector<int> A = inputArray();
    cout << "The initial array: " << endl;
    for (int i : A) {
        cout << i << " ";
    }
    writeArrayToFile(A, "input.txt");
    readAndRemovePositive(A, "input.txt");

    cout << endl<< "The resulting array: " << endl;
    for (int i : A) {
        cout << i << " ";
    }
    cout << endl;
      writeArrayToFile(A, "output.txt");

    return 0;
}
