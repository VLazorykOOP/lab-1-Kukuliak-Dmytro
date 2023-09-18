#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> inputArray() {
    srand(time(NULL));
    vector<int> arr;
    int n = rand() % 10 + 3;
    for (int i = 0; i < n; i++) {
        arr.push_back(rand() % 20 - 10);
    }
    return arr;
}


void writeArrayToFile(const vector<int>& arr, const string& filename) {
    ofstream file(filename);

    if (!file.is_open()) {
        cout << "Error opening file " << filename << endl;
        return;
    }

    for (const int& element : arr) {
        file << element << " ";
    }

    file.close();
}


int main() {
    int min;
    vector<int> A = inputArray();
    cout << "The initial array: " << endl;
    for (int i : A) {
        cout << i << " ";
    }
    writeArrayToFile(A, "input.txt");
    for (auto it = A.begin(); it != A.end();++it) {
        if (*it % 2 == 0) {
            min = *min_element(it+1, A.end());
            cout << endl<< "The minimum element located to the right of " <<*it<<" is: " << min;
            break;
        }
    }
    ofstream file1("output.txt");
    if (!file1.is_open()) {
        cout << "Error opening file " << "output.txt" << endl;
        return 1;
    }
    file1 << min;
    return 0;
}
