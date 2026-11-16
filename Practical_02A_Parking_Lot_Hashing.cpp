#include <iostream>
#include <vector>
using namespace std;

int main() {
    int slots, n;
    cout << "Enter number of parking slots: ";
    cin >> slots;

    if (slots <= 0) {
        cout << "Number of slots must be positive.\n";
        return 0;
    }

    vector<int> parking(slots, -1);

    cout << "Enter number of vehicles: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int carNumber;
        cout << "Enter vehicle registration number: ";
        cin >> carNumber;

        int index = ((carNumber % slots) + slots) % slots;
        int start = index;

        while (parking[index] != -1) {
            index = (index + 1) % slots;
            if (index == start) {
                cout << "Parking lot is full!\n";
                break;
            }
        }

        if (parking[index] == -1) {
            parking[index] = carNumber;
            cout << "Vehicle parked at slot " << index + 1 << endl;
        }
    }

    cout << "\n--- Parking Lot ---\n";
    for (int i = 0; i < slots; i++) {
        if (parking[i] == -1)
            cout << "Slot " << i + 1 << ": Empty\n";
        else
            cout << "Slot " << i + 1 << ": " << parking[i] << endl;
    }

    return 0;
}
