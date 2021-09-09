#include<iostream>
using namespace std;

int main(){
    // POINTER vs POINTER REFERENCE
    
    /*
        In cpp passing pointer is different thing and passing pointer reference is different thing

        PASSING POINTER:
            Let start with function declaration
                void func(Node * root) // Let's say this is our function
            so when we call this function with passing a pointer as param 
                i.e func(r);
            it creates a copy of r and stores it in root variable in func
                i.e root= r;
            and now root is also pointing to same location as of r

        PASSING POINTER REFERENCE:
            Let's start with same function declaration
                void func(Node * & root)
            so when we call this function with passing a pointer as param
                i.e func(r);
            it takes its reference which it doesn't create a copy it's take that same variable we pass i.e r and name it root 
            means r and root are same pointer variable.
            This affects in recursinve call with pointers.

            EXAMPLE CODE:
            // In this code if you use prev without call by reference you get false output

            void flatten3(Node * root, Node* &prev){
                if(root==NULL) return;
                flatten3(root->right, prev);
                flatten3(root->left, prev);
                root->right = prev;
                root->left = NULL;
                prev = root;
            }

            // src:flattentree.cpp
}
    */


}