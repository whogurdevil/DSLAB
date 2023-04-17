#include <bits/stdc++.h>
using namespace std;


int main(){
    cout << "Enter number of non zero elements: " ;
    int row;
    cin >> row;
    int arr[row][3];

    int rval, cval, ele;
    for(int i = 0; i < row; i++){
        int j = 0;
        while(j < 3){
            cout << "Enter row value for " << i+1 << "th element: " ;
            cin >> rval;
            arr[i][j++] = rval;
            cout << "Enter column value for " << i+1 << "th element: ";
            cin >> cval;
            arr[i][j++] = cval;
            cout << "Enter value for " << i+1 << "th element: ";
            cin >> ele;
            arr[i][j++] = ele;
        }
        cout << endl;
    }

    cout << "Entered Sparse matrix:" << endl;

    for(int i=0; i < row; i++){
        for(int j = 0; j < 3; j++){
            cout << arr[i][j] << " ";  
        }
        cout << endl;
    }
    cout << endl;
    
    int tran[3][row];
    for(int i=0; i < row; i++){
        for(int j = 0; j < 3; j++){
            tran[j][i] = arr[i][j];
        }
    }

        cout << "Transpose of entered sparse matrix:" << endl;
        for(int i=0; i < 3; i++){
        for(int j = 0; j < row; j++){
            cout << tran[i][j] << " ";  
        }
        cout << endl;
    }
return 0;
}