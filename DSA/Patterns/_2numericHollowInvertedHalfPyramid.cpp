// 12345
// 2  5
// 3 5
// 45
// 5
#include <iostream>
using namespace std;

// int main(){
//     int n;
//     cout<<"Enter the number of rows: ";
//     cin>>n;
//     for(int row =0; row<n; row++){
//         for(int col = 0; col<n-row; col++){
//             if(row==0){
//                 cout<<col+1;
//                 continue;
//             }
//             if(col==0){
//                 cout<<row+1;
//                 continue;
//             }
//             if(col==(n-row-1)){
//                 cout<<n;
//             }
//             cout<<" ";
//         }
//     cout<<endl;
//     }
//     return 0;
// }

// ------***OR***-------

int main()
{
    int n;
    cout << "Enter the number of rows: ";
    cin >> n;
    for (int row = 0; row < n; row++)
    {
        for (int col = row + 1; col < n + 1; col++)
        {
            if (col == row + 1 || col == n || row == 0)
            {
                cout << col;
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}