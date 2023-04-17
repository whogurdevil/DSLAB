#include <bits/stdc++.h>
using namespace std;

void printStack(stack<int> s);

//Function to move disks from source to destination
void towersOfHanoi(int n, stack<int>& x, stack<int>& y, stack<int>& z)
{// move the top n disks from tower x to tower y.
// Use tower z tor intermediate storage.
    if(n > 0){
        towersOfHanoi( n-1, x, z, y) ;
        y.push(x.top());
        x.pop();

        cout << "X : ";
        printStack(x);
        cout << endl;
        cout << "Y: ";
        printStack(y);
        cout << endl;
        cout << "Z: ";
        printStack(z);
        cout << endl;
        cout << endl;

        towersOfHanoi(n-1, z, y, x) ;
    }
}


//Function to print stacks
void printStack(stack<int> s)
{
    if (s.empty())
        return;
    int x = s.top();
    s.pop();
    printStack(s);
    cout << x << " ";
    s.push(x);
}


int main(){
    stack<int> x; //source
    stack<int> y; // destination
    stack<int> z; // temp

    cout << "Enter number of disks(n): ";
    int n;
    cin >> n;

    for(int i = n; i > 0; i--){
        x.push(i);
    }
    cout << "Source stack (bottom to top): ";
    printStack(x);
    cout << "\n\n";

    cout << "Started moving... " << endl;
    towersOfHanoi( n, x, y, z);

    cout << "\nAfter moving, Destination Stack(bottom to top): ";
    printStack(y);
return 0;
}