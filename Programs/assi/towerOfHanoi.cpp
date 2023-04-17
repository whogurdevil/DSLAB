#include <bits/stdc++.h>
using namespace std;

void print(stack<int> s){
    if(s.empty()){
        return;
    }
    int x =  s.top();
    cout << x << endl;
    s.pop();
    print(s);
    s.push(x);

}

void move(stack<int>& from, stack<int>& to){
    int x = from.top();
    from.pop();
    to.push(x);
    return;
}

void solve(int n, stack<int>& a, stack<int>& b, stack<int>& c){
    
}
int main(){
    stack<int> a;
    stack<int> b;    
    stack<int> c;

    a.push(1);
    a.push(2);
    a.push(3);

    int n = a.size();
    solve(n, a, b, c);

    print(a);
    print(b);
    print(c);



return 0;
}

//  temp code
// #include <iostream>
// #include <stack>
// using namespace std;

// void tower_of_hanoi(int n, stack<int>& source, stack<int>& destination, stack<int>& auxiliary) {
//     if (n == 1) {
//         destination.push(source.top());
//         source.pop();
//         return;
//     }
//     tower_of_hanoi(n - 1, source, auxiliary, destination);
//     destination.push(source.top());
//     source.pop();
//     tower_of_hanoi(n - 1, auxiliary, destination, source);
// }

// int main() {
//     int n = 3; // number of disks
//     stack<int> source, destination, auxiliary;
//     for (int i = n; i >= 1; i--) {
//         source.push(i);
//     }
//     tower_of_hanoi(n, source, destination, auxiliary);
//     cout << "Disks moved from source to destination:" << endl;
//     while (!destination.empty()) {
//         cout << destination.top() << " ";
//         destination.pop();
//     }
//     cout << endl;
//     return 0;
// }
