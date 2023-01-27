#include <bits/stdc++.h>
using namespace std;

//function to get index of the value in an array
int indexof(int arr[], int size, int value){
    for(int i = 0; i<size; i++){
        if(arr[i] == value){
            return i;
        }
    }
    cout << "Value not found" << endl;
    return 0;
}

int size = 0;

int main(){
    
    int *arr = NULL; 

    int *temp = NULL;
    int pos = 0;

    int option;

    menu:
    while(true){
        system("cls");
        
        cout<< "1. Create array of n int elements\n2. Display of array elements  with suitable headings\n3. Insert an element at a given valid position\n4. Deleting an element at a given valid position\n5. Exit\n\nEnter a number to choose from option.... ";
        cin >> option;

        switch(option){


            //when case 1 is choosen
            case 1:
            system("cls");

            cout << "Enter size of array: ";
            cin >> size;

            // if size is invalid
            if (size < 1) {
                cout << "Invalid size, please enter a positive number" << endl;
                break;
            }

            cout << "Enter elements of the array: " << endl;
            arr = new int[size]; // dynamically declared array

            for(int i = 0; i<size; i++){
                cin >> *(arr + i);
            }

            cout << "Array created successfully"<< endl;
            break;

            case 2:
            system("cls");

            if (size == 0) {
                cout << "Array is empty, please create an array first" << endl;
                break;
            }

            for(int j = 0; j < size; j++) {
                cout << "Element at " << j <<"th index is " << arr[j] << endl;
            }

            cout << "Array printed successfully" << endl;
            system("pause");
            break;


            //when case 3 is choosen
            case 3:
            insert:
            system("cls");
            cout << "Enter index at which value is to be inserted: ";
            
            cin >> pos;

            if(pos > size-1 || pos < 0){
                cout << "Invalid index" <<endl;
                goto insert;
            }
            cout << "Enter value to insert: ";
            int value;
            cin >> value;


            temp = new int[size + 1];

            for(int i = 0; i< size+1; i++){
                if(i < pos){
                    temp[i] = arr[i];
                }
                else if(i == pos){
                    temp[i] = value;
                }
                else{
                    temp[i] = arr[i-1];
                }
            }

            arr = temp;
            size ++;

            system("pause");
            break;


            //when option 4 is choosen
            case 4:

            system("cls");

            cout << "Enter element to be deleted: ";
            int del;
            cin >> del;

            pos = indexof(arr, size, del);

            temp = new int[size - 1];

            for(int i = 0; i< size-1; i++){
                if(i < pos){
                    temp[i] = arr[i];
                }
                else if(i >= pos){
                    temp[i] = arr[i+1];
                }
            }

            arr = temp;
            size --;

            cout << "Deleted successfully" << endl;

            system("pause");
            break;


            //when option 5 is choosen
            case 5:
            cout << "Exiting program......" << endl;
            return 0;
            break;

            default:
            cout << "Invalid option chosen, please try again" << endl;
            goto menu;
            break;
        }
    }
}
