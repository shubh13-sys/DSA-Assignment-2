#include <iostream>
#include <vector>
using namespace std;

struct Product {
    int code = -1;
    int stock = 0;
    float price = 0;
};

int main() {
    int tableSize, n;
    cout << "Enter hash table size: ";
    cin >> tableSize;

    if (tableSize <= 0) {
        cout << "Table size must be positive.\n";
        return 0;
    }

    vector<Product> hashTable(tableSize);

    cout << "Enter number of products: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int code, stock;
        float price;

        cout << "\nEnter product code: ";
        cin >> code;
        cout << "Enter stock: ";
        cin >> stock;
        cout << "Enter price: ";
        cin >> price;

        int index = ((code % tableSize) + tableSize) % tableSize;
        int start = index;

        while (hashTable[index].code != -1) {
            index = (index + 1) % tableSize;
            if (index == start) {
                cout << "Hash table is full!\n";
                break;
            }
        }

        if (hashTable[index].code == -1) {
            hashTable[index].code = code;
            hashTable[index].stock = stock;
            hashTable[index].price = price;
            cout << "Product stored at index " << index << endl;
        }
    }

    cout << "\n--- Inventory ---\n";
    for (int i = 0; i < tableSize; i++) {
        if (hashTable[i].code == -1) {
            cout << "Index " << i << ": Empty\n";
        } else {
            cout << "Index " << i
                 << " | Code: " << hashTable[i].code
                 << " | Stock: " << hashTable[i].stock
                 << " | Price: " << hashTable[i].price << endl;
        }
    }

    int searchCode;
    cout << "\nEnter product code to search: ";
    cin >> searchCode;

    int index = ((searchCode % tableSize) + tableSize) % tableSize;
    int start = index;
    bool found = false;

    while (hashTable[index].code != -1) {
        if (hashTable[index].code == searchCode) {
            cout << "Product Found!\n";
            cout << "Stock: " << hashTable[index].stock << endl;
            cout << "Price: " << hashTable[index].price << endl;
            found = true;
            break;
        }

        index = (index + 1) % tableSize;
        if (index == start)
            break;
    }

    if (!found)
        cout << "Product not found.\n";

    return 0;
}
