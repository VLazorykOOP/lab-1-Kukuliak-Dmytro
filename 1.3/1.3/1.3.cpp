#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

void fillTheFile(int n) {
    ofstream file("input.txt");
    srand(time(NULL));
    if (!file.is_open()) {
        cout << "Error opening file " << "input.txt" << endl;
        return;
    }
    
    for (int i = 0; i < 2*n; i++) {
        file << rand() % 20 - 10 << " ";
    }
    file.close();
}

vector<int> readToArray() {
    ifstream file("input.txt");
    vector<int> arr;

    if (!file.is_open()) {
        cout << "Error opening file " << "input.txt" << endl;
        return arr; 
    }

    int element;
    while (file >> element) {
        arr.push_back(element);
    }

    file.close();
    return arr;
}

int main() {
    
    int n;
    cout << "Insert the size of array (2*n): ";
    cin >> n;
    fillTheFile(n);
    vector<int> A = readToArray();
    vector<int> B;

    ofstream file("output.txt");
       if (!file.is_open()) {
        cout << "Error opening file " << "output.txt" << endl;
        
    }
    
    for (int i = 0; i < n; i++) {
        if (A[i] < A[2 * n - i - 1]) {
            B.push_back(A[i]);
        } else {
            B.push_back(A[2 * n - i - 1]);
        }
        cout << B[i] << " ";
        file << B[i]<< " ";
    }
    file << endl;
    file << *max_element(B.begin(), B.end());
    file.close();
   
    return 0;
}
