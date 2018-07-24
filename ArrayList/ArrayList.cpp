//
// Created by kim dae young on 7/24/18.
//

#include <iostream>

#define MAX_ITEM 100

using namespace std;

template <typename T>
class ArrayList {
private:
    T items[MAX_ITEM];
    int count = 0;

public:
    void Add(T value) {
        if (count > MAX_ITEM) {
            cout << "ArrayList is full!" << endl;
            return;
        }

        items[count++] = value;
    }

    void Insert(int index, T value) {
        if (index < 0 && index > count) {
            cout << "Please enter the valid index." << endl;
            return;
        }

        if (count > MAX_ITEM) {
            cout << "ArrayList is full!" << endl;
            return;
        }

        for (int i = count - 1; i >= index; i--) {
            items[i + 1] = items[i];
        }
        items[index] = value;
        count++;
    }

    void Remove(T value) {
        int idx = IndexOf(value);

        if (idx == -1) {
            return;
        } else {
            for (int i = idx; i < count; i++) {
                items[i] = items[i + 1];
            }
            count--;
        }
    }

    int IndexOf(T value) {
        for (int i = 0; i < count; i++) {
            if (value == items[i]) return i;
        }
        return -1;
    }

    T ElementAt(int index) {
        if (index < 0 && index > count) {
            cout << "Please enter the valid index." << endl;
            return NULL;
        }
        return items[index];
    }

    int Count() {
        return count;
    }
};

int main() {
    ArrayList<int> arrayList;

    arrayList.Add(10);
    arrayList.Add(20);
    arrayList.Add(30);
    arrayList.Add(40);
    arrayList.Add(50);
    arrayList.Add(60);
    cout << "ElementAt 1: " << arrayList.ElementAt(1) << endl << endl;

    arrayList.Insert(1, 100);
    cout << "Inserted 100, ElementAt 1: " << arrayList.ElementAt(1) << endl << endl;

    cout << "IndexOf 100: " << arrayList.IndexOf(100) << ", Current Count: " << arrayList.Count() << endl << endl;

    arrayList.Remove(100);
    cout << "Removed 100, Current Count: " << arrayList.Count() << endl << endl;

    cout << "ElementAt 1: " << arrayList.ElementAt(1) << endl;

    return 0;
}