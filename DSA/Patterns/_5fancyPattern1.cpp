#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter number of rows: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int startNumIndex = 8 - i;
        int num = i + 1;
        int countNum = num;
        for (int col = 0; col < 17; col++)
        {
            if (col == startNumIndex && countNum > 0)
            {
                cout << num;
                startNumIndex += 2;
                countNum--;
            }
            else
            {
                cout << "*";
            }
        }
        cout << endl;
    }

    return 0;
}