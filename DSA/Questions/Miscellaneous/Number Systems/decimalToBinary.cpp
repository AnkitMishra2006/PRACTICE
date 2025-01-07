#include <iomanip>
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
    cout << setw(10) << right << ans << endl;
}
void DectoBinary(int decNum)
{
    int i;
    for (i = 0; i <= decNum; i++)
    {
        DtoB(i);
    }
}

int main()
{
    int n = 100;
    DectoBinary(n);
    return 0;
}