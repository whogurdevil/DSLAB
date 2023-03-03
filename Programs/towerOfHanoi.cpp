#include <bits/stdc++.h>
using namespace std;

void print(stack<int>& s){
    if(s.empty()){
        return;
    }
    else{
        int x = s.pop();
        cout << x << " ";
        print(s);
    }
    cout << endl;
}

// void solve(int n, stack<int> &from, stack<int> &to, stack<int> &temp,){
//     if(n == 0){
//         return;

//     }
//     int x = from.pop();
//     to.push(x);

//     solve(n-1, from, temp, to);
//     solve(n-1, from, to, temp);

// }

int main(){
    stack<int> a;
    stack<int> b;
    stack<int> c;

    a.push(1);
    a.push(2);
    a.push(3);

    print(a);



return 0;
}