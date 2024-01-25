#include <iostream>
#include <cmath>

using namespace std;

int a[30], count = 0;

bool place(int pos) {
    for (int i = 1; i < pos; i++) {
        if ((a[i] == a[pos]) || (abs(a[i] - a[pos]) == abs(i - pos)))
            return false;
    }
    return true;
}

void print_sol(int n) {
    cout << "\n\nSolution #" << count << ":\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i] == j)
                cout << "Q\t";
            else
                cout << "*\t";
        }
        cout << endl;
    }
}

void queen(int n) {
    int k = 1;
    a[k] = 0;
    while (k != 0) {
        a[k] = a[k] + 1;
        while ((a[k] <= n) && !place(k))
            a[k]++;
        if (a[k] <= n) {
            if (k == n){
                count++;
                print_sol(n);
            }
            else {
                k++;
                a[k] = 0;
            }
        } 
        else
            k--;
    }
}

int main() {
    int n;
    cout << "Enter the number of Queens: ";
    cin >> n;

    queen(n);

    cout << "\nTotal solutions = " << count << endl;

    return 0;
}
