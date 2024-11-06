#include <iostream>
using namespace std;

int fibRec(int n) {
    if (n <= 1) return n;
    return fibRec(n - 1) + fibRec(n - 2);
}

void fibNonRec(int n) {
    int a = 0, b = 1;
    int c;
    cout << a << " " << b << " ";
    for (int i = 2; i < n; i++) {
        c = a + b;
        cout << c << " ";
        a = b;
        b = c;
    }
}

int main() {
    int n, ch;
    cout << "Fibonacci Sequence\n";
    cout << "(1) Recursive (Nth term)\n(2) Non-Recursive (First N terms)\n>> ";
    cin >> ch;

    cout << "Enter a number: ";
    cin >> n;

    if (ch == 1) {
        // Recursive approach for the Nth Fibonacci term
        cout << "Recursive: " << fibRec(n) << endl;
    } 
    else if (ch == 2) {
        // Non-recursive approach for the first N terms
        cout << "Non-Recursive: ";
        fibNonRec(n);
        cout << endl;
    } 
    else {
        cout << "Invalid choice. Please select 1 or 2." << endl;
    }
    
    return 0;
}

