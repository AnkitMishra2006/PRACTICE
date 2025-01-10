#include <iostream>
using namespace std;

void binaryStrings(int n, int lastPlace, string ans)
{
    if (n == 0)
    {
        cout << ans << endl;
        return;
    }

    if (lastPlace != 1)
    {
        binaryStrings(n - 1, 0, ans + '0');
        binaryStrings(n - 1, 1, ans + '1');
    }
    else
    {
        binaryStrings(n - 1, 0, ans + '0');
    }
}

int main()
{
    binaryStrings(6, 0, "");
}