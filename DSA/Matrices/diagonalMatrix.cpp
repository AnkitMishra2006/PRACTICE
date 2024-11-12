#include <iostream>
using namespace std;

class Matrix
{
    int *A;
    int n;

public:
    Matrix(int x) : n(x)
    {
        A = new int[n];
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
    if (i == j)
    {
        A[i - 1] = x;
    }
}

int Matrix::get(int i, int j)
{
    if (i == j)
    {
        return A[i - 1];
    }
    else
    {
        return 0;
    }
}

void Matrix::display()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                cout << "0 ";
            }
            else
            {
                cout << A[i - 1] << " ";
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
//     if (i == j)
//     {
//         m->A[i - 1] = x;
//     }
// }

// int get(struct Matrix m, int i, int j)
// {
//     if (i == j)
//     {
//         return m.A[i - 1];
//     }
//     else
//     {
//         return 0;
//     }
// }

// void display(struct Matrix m)
// {
//     for (int i = 0; i < m.n; i++)
//     {
//         for (int j = 0; j < m.n; j++)
//         {
//             if (i != j)
//             {
//                 cout << "0 ";
//             }
//             else
//             {
//                 cout << m.A[i - 1] << " ";
//             }
//         }
//         cout << endl;
//     }
// }
