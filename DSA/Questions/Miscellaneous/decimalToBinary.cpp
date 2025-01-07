#include <iostream>
using namespace std;

void DtoB(int decNum)
{
    int rem, ans = 0, pow = 1;
    while (decNum > 0)
    {
        rem = decNum % 2;
        decNum = decNum / 2;
        ans += (rem * pow);
        pow *= 10;
    }
    cout << ans;
}

int main()
{
    int n = 10;
    DtoB(n);
    return 0;
}