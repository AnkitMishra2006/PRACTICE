#include <iostream>
using namespace std;

int getIndex(int i, int j)
{
    return (i*(i-1)/2) + j - 1;
}
class Matrix
{
    int *A;
    int n;

public:
    Matrix(int x) : n(x)
    {
        A = new int[n*(n+1)/2];
    }
    void set(int i, int j, int x);
    int get(int i, int j);
    void display();
    ~Matrix()
    {
        delete[] A;
    }
};

void Matrix::set(int i, int j, int x)
{
    if (i >= j)
    {
        A[getIndex(i,j)] = x;
    }
}

int Matrix::get(int i, int j)
{
    if (i >= j)
    {
        return A[getIndex(i,j)];
    }
    else
    {
        return 0;
    }
}

void Matrix::display()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i < j)
            {
                cout << "0 ";
            }
            else
            {
                cout << A[getIndex(i,j)] << " ";
            }
        }
        cout << endl;
    }
}

// struct Matrix
// {
//     int A[10];
//     int n;
// };

// void set(struct Matrix *m, int i, int j, int x)
// {
//     if (i >= j)
//     {
//         m->A[getIndex(i, j)] = x;
//     }
// }

// int get(struct Matrix m, int i, int j)
// {
//     if (i >= j)
//     {
//         return m.A[getIndex(i,j)];
//     }
//     else
//     {
//         return 0;
//     }
// }

// void display(struct Matrix m)
// {
//     for (int i = 1; i <= m.n; i++)
//     {
//         for (int j = 1; j <= m.n; j++)
//         {
//             if (i < j)
//             {
//                 cout << "0 ";
//             }
//             else
//             {
//                 cout << m.A[getIndex(i,j)] << " ";
//             }
//         }
//         cout << endl;
//     }
// }
