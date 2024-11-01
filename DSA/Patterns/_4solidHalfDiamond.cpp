#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of columns: ";
    cin >> n;
    for (int row = 0, k = 0; row < 2 * n - 1; row++)
    {
        if (row < n)
        {
            for (int col = 0; col <= k; col++)
            {
                cout << "*";

            }
            k++;
        }
        else
        {
            k--;
            for(int col = 0; col < k; col++)
            {
                cout<<"*";
            }
        }

        cout << endl;
    }
}