#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter number : ";
    cin >> n;
    cout << "Factoring Result : ";
    while (n > 1) {
        for (int i = 2; i <= n; i++) {
            if (n % i == 0) {
                cout << i;
                if (n != i) {
                    cout << " x ";
                }
                n /= i;
                break;
            }
        }
    }
}