#include <iostream>
using namespace std;

struct bst {
    int data;
    bst* left; 
    bst* right;
    
    public:
    bst() {
        data = 0;
        left = NULL;
        right = NULL;
    }
    
    bst(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
    
    bst* insert(bst* root, int value) {
        
        
        if(!root) {
            
            bst* node = new bst(value);
            return (node);
        }
        
        if(value > root->data) {
            root->right = insert(root->right, value);
        }
        else if(value < root->data) {
            root->left = insert(root->left, value);
        }
        
        return root;
    }
    
    void print(bst* root) {
        if(!root) {
            return;
        }
        
        print(root->left);
        cout << root->data << " " << endl;
        
        print(root->right);
    }
    
    bst* search(bst* root, int key) {
        if(root == NULL || root->data == key) {
            return root;
        }
        
        if(key > root->data) {
            return search(root->right, key);
        }
        
        return (search(root->left, key));
    }
    
    
    
};

int main() {
	bst b;
	bst* root = NULL;
	
	root = b.insert(root, 10);
	
	b.insert(root, 20);
	b.insert(root, 50);
	b.insert(root, 30);
	
	b.print(root);
	
	bst* res = b.search(root, 45);
	
    if(!res) {
        cout << "\nNot found" << endl;
    }
    else {
        cout << "Found, res->data: " << res->data << endl;
    }
	
	return 0;
}