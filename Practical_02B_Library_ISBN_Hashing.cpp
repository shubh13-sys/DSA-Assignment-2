#include <iostream>
#include <vector>
using namespace std;

int main() {
    int tableSize, n;
    cout << "Enter table size: ";
    cin >> tableSize;

    if (tableSize <= 0) {
        cout << "Table size must be positive.\n";
        return 0;
    }

    vector<int> hashTable(tableSize, -1);

    cout << "Enter number of books: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int isbn;
        cout << "Enter ISBN number: ";
        cin >> isbn;

        int index = ((isbn % tableSize) + tableSize) % tableSize;
        int start = index;

        while (hashTable[index] != -1) {
            index = (index + 1) % tableSize;
            if (index == start) {
                cout << "Hash table is full!\n";
                break;
            }
        }

        if (hashTable[index] == -1) {
            hashTable[index] = isbn;
            cout << "Book stored at index " << index << endl;
        }
    }

    cout << "\n--- Library Hash Table ---\n";
    for (int i = 0; i < tableSize; i++) {
        if (hashTable[i] == -1)
            cout << "Index " << i << ": Empty\n";
        else
            cout << "Index " << i << ": ISBN " << hashTable[i] << endl;
    }

    return 0;
}
