#include <iostream>
using namespace std;

int tp(int n) // 2xn floor
{
    if (n == 0 || n == 1)
        return 1;

    int ans1 = tp(n - 1); // for vertical placements
    int ans2 = tp(n - 2); // for horizontal placements

    return (ans1 + ans2);
}

int main()
{
    int n;
    cout << "Enter n(2xn): ";
    cin >> n;
    cout << tp(n);
}