#include <iostream>
using namespace std;

int friendsPairing(int n) // 2xn floor
{
    if (n == 1 || n == 2)
        return n;

    return friendsPairing(n - 1) + (n - 1) * friendsPairing(n - 2);
}

int main()
{
    int n;
    cout << "Enter no of friends: ";
    cin >> n;
    cout << friendsPairing(n);
}