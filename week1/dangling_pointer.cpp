#include <iostream>

// here count function is returning a pointer of a variable that is locally scoped.
int* count(){
    int a = 24;
    return &a;
};


int main(){

// here I initialized a pointer ptr, and pointed it to the address of the local variable
    int *ptr;
    ptr = count(); 

// to fix the dangling pointer issue I set it to null
    ptr = NULL;


     
    return 0;
}