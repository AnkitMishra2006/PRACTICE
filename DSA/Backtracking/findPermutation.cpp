#include <iostream>
#include <vector>
#include <string>
using namespace std;

void printPermutation(string str, string ans)
{
    int n = str.size();
    if (n == 0)
    {
        cout << ans << endl;
    }
    for (int i = 0; i < n; i++)
    {
        char ch = str[i];
        string nextStr = str.substr(0, i) + str.substr(i + 1, n - i - 1);
        printPermutation(nextStr, ans + ch);
    }
}

int main()
{
    string str = "Ankit";
    string ans = "";
    printPermutation(str, ans);
    return 0;
}