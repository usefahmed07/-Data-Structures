#include <iostream>
using namespace std;

#define SIZE 100   // حجم الـ Array

int arr[SIZE];
int length = 0;   // عدد العناصر الحقيقية

// -------- Prototypes ----------
void createArray();
void insertElement(int value);
int searchElement(int value);
void deleteElement(int value);
void displayArray();
// --------------------------------


int main()
{
    createArray();      // نبدأ ب Array فاضية

    insertElement(10);
    insertElement(20);
    insertElement(30);
    insertElement(40);

    displayArray();

    cout << "\nSearching for 30:\n";
    int idx = searchElement(30);
    if (idx != -1) cout << "Found at index: " << idx << endl;
    else cout << "Not Found\n";

    cout << "\nDeleting 20...\n";
    deleteElement(20);

    displayArray();

    return 0;
}



// Create empty array
void createArray() {
    length = 0;
}



// Insert new element at end
void insertElement(int value) {

    if (length == SIZE) {
        cout << "Array is FULL\n";
        return;
    }

    arr[length] = value;
    length++;
}



// Search for element
int searchElement(int value) {

    for (int i = 0; i < length; i++) {
        if (arr[i] == value)
            return i;   // يرجع مكانه
    }

    return -1;   // مش موجود
}



// Delete element by value
void deleteElement(int value) {

    int index = searchElement(value);

    if (index == -1) {
        cout << "Element not found\n";
        return;
    }

    // Shift left
    for (int i = index; i < length - 1; i++) {
        arr[i] = arr[i + 1];
    }

    length--;   // قلل حجم الـ Array
}



// Display all elements
void displayArray() {

    if (length == 0) {
        cout << "Array is empty\n";
        return;
    }

    cout << "Array elements: ";
    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
