#include <iomanip>
#include <iostream>
using namespace std;

void BinarytoDec(int binNum)
{
    int rem, ans, pow = 1;
    while (binNum > 0)
    {
        rem = binNum % 10;
        binNum = binNum / 10;
        ans += (rem * pow);
        pow *= 2;
    }
    cout << ans << endl;
}

int main()
{
    int n = 100;
    BinarytoDec(n);
    return 0;
}