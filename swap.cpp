#include <iostream>
using namespace std;

void swap(int &a, int &b);  // Function prototype

int main() {
    int intOne, intTwo;

    cout << "Enter 2 ints: ";
    cin >> intOne >> intTwo;

    swap(intOne, intTwo);  // Call swap function

    cout << "Swapped: " << intOne << ", " << intTwo << endl;

    return 0;
}

void swap(int &a, int &b) {  // Function definition using reference parameters
    int t = a;
    a = b;
    b = t;
}
