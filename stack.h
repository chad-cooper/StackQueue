//
//  stack.h
//  Project 2
//
//  Created by Chad Cooper on 5/31/17.
//  Copyright © 2017 Chad Cooper. All rights reserved.
//

#ifndef stack_h
#define stack_h

#include <stdexcept>
using namespace std;

template <typename Type>
class DynStack {
    
private:
    
    Type *array = nullptr;
    
    int count;
    
    int initialSize;
    
    int arraySize;
    
public:
    
    // Constructor
    DynStack(int n = 15);
    
    // Destructor
    ~DynStack();
    
    
    // ************* Accessors *************
    
    // Returns the top (most recently added) item in the stack.
    Type top() const throw(underflow_error);
    
    // Current number of items in the stack.
    int size() const;
    
    // Returns true if the size of the stack is 0.
    bool empty() const;
    
    // Returns the number of items the stack can currently hold before needing to double.
    int capacity() const;
    
    // Prints all the items in the stack.
    void display();
    
    
    // ************* Mutators *************
    
    // Adds a new item to the top of the stack.
    void push(Type const &);
    
    // Removes the top item from the stack.
    Type pop() throw(underflow_error);
    
    // Removes all items from the stack.
    void clear();
    
};





/* The constructor takes as an argument the initial
 size of the array and allocates memory for that array. The default number of
 entries is 15. If the argument is either 0 or a negative integer, the initial
 capacity of the array is set to 1. Other class members are assigned as appropriate.*/
template <typename Type>
DynStack<Type>::DynStack(int n) {
    
    if (n < 1) {

        array = new Type[1];
        initialSize = 1;
        arraySize = 1;
        
    } else {
        
        array = new Type[n];
        initialSize = n;
        arraySize = n;

    }
    
    count = 0;
    
}






/* The destructor deletes the memory allocated for the array.*/
template <typename Type>
DynStack<Type>::~DynStack() {
    delete [] array;
}






/* Returns the object at the top of the stack. It may
 throw a underflow exception.*/
template <typename Type>
Type DynStack<Type>::top() const throw(underflow_error) {
    
    if(!empty()){
        return array[count-1];
    } else {
        throw underflow_error("The stack is empty. There are no items to view.\n");
    }
    
}






/* Returns the number of elements currently stored in the
 stack.*/
template <typename Type>
int DynStack<Type>::size() const {
    return count;
}






/* Returns true if the stack is empty, false otherwise.*/
template <typename Type>
bool DynStack<Type>::empty() const {
    
    // if the count is 0, then the stack is empty.
    return (count == 0);
}






/* Returns the current size of the array.*/
template <typename Type>
int DynStack<Type>::capacity() const {
    return arraySize;
}





/* Prints the content of the stack. */
template <typename Type>
void DynStack<Type>::display() {
    
    for (int i = count - 1 ; i >= 0; i--) {
        cout << *(array + i) << endl;
    }
    
}






/* Inserts the new element at the top of
the stack. If the array is full, the size of the array is doubled. */
template<typename Type>
void DynStack<Type>::push(Type const & data) {
    
    
    if(count == arraySize){
        
        // construct new array 2x the size of current array
        arraySize *= 2;
        
        
        Type *replacementArray = nullptr;
    
        replacementArray = new Type[arraySize];
        
        // copy contents of old array to new array
        for (int i = 0; i < count ; i++) {
            replacementArray[i] = array[i];
        }
    
        // destroy old array
        delete [] array;
        
        // array now points to new array.
        array = replacementArray;
        
    }
     
    
    
    array[count++] = data;
    
}





/* Removes the element at the top of the stack. If, after the
 element is removed, the array is 1/4 full and the array size is greater than
 the initial size, the size of the array is halved. This may throw a underflow
 exception. */
template<typename Type>
Type DynStack<Type>::pop() throw(underflow_error) {
    if(!empty()){
        
        Type poppedData = array[(count--) - 1];
        
        // count/arraySize >= 1/4 checks if the array is 1/4 full
        // arraySize/2 >= initalSize ensures that the array size doesn't fall below the inital size given.
        if(((double)count/arraySize <= 0.25) && (arraySize/2 >= initialSize)){
            
            // construct new array 1/2 the size of current array
            arraySize /= 2;
            
            Type *replacementArray = nullptr;
            
            replacementArray = new Type[arraySize];
            
            // copy contents of old array to new array
            for (int i = 0; i < count ; i++) {
                replacementArray[i] = array[i];
            }
            
            // destroy old array
            delete [] array;
            
            // array now points to new array.
            array = replacementArray;
        }
        
        return poppedData;
    } else {
        throw underflow_error("The stack is empty. There are no items to remove.\n");
    }
}





/* Removes all the elements in the stack. The array is resized
to the initial size.*/
template<typename Type>
void DynStack<Type>::clear() {
    
    while(!empty()){
        pop();
    }
    
}


#endif /* stack_h */
