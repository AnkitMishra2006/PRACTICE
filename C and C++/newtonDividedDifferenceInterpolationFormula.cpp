#include <iostream>
#include <iomanip>
using namespace std;

void calculateDividedDifference(double x[], double y[], double table[][10], int n)
{
    for (int i = 0; i < n; i++)
    {
        table[i][0] = y[i];
    }
    for (int j = 1; j < n; j++)
    {
        for (int i = 0; i < n - j; i++)
        {
            table[i][j] = (table[i + 1][j - 1] - table[i][j - 1]) / (x[i + j] - x[i]);
        }
    }
}
double interpolate(double x[], double table[][10], double value, int n)
{
    double result = table[0][0];
    double term = 1.0;
    for (int i = 1; i < n; i++)
    {
        term *= value - x[i - 1];
        result += term * table[0][i];
    }
    return result;
}
int main()
{
    int n;
    cout << "Enter the number of data points: ";
    cin >> n;

    double x[10], y[10];
    cout << "Enter the values of x and y:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "x[" << i << "]: ";
        cin >> x[i];
        cout << "y[" << i << "]: ";
        cin >> y[i];
    }
    double table[10][10] = {0, 0};
    calculateDividedDifference(x, y, table, n);
    cout << "\nDivided Difference Table:\n";
    for (int i = 0; i < n; i++)
    {
        cout << setw(10) << x[i] << " ";
        for (int j = 0; j < n - i; j++)
        {
            cout << setw(10) << table[i][j] << " ";
        }
        cout << endl;
    }
    double value;
    cout << "\nEnter the value to Interpolate: ";
    cin >> value;
    double result = interpolate(x, table, value, n);
    cout << "Interpolated value at x = " << value << " is " << result << endl;
    return 0;
}