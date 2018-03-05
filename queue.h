//queue.h
//Project 2
//Created by Kin NG on 5/31/2017

#ifndef DYNQUEUE_h
#define DYNQUEUE_h
#include <stdexcept>

using namespace std;

template <typename Type>
class DynQueue
{
private:
    
    Type *array = nullptr;        	//pointer to an instance of type, Type *array, to be used as an array.
    int iHead;             			//A head index, int iHead.
    int iTail;             			//A tail index, int iTail.
    int count;             			//Holds the number of elements in the queue, int count.
    int initialSize; 				//The initial size of the array, int initialSize.
    int arraySize;         			//The current size of the array, int arraySize.
    
public:
    
    //Constructor
    DynQueue(int n = 15) {
        if (n < 1) {
            array = new Type[1];
            initialSize = 1;
            arraySize = 1;
        }
        else {
            array = new Type[n];
            initialSize = n;
            arraySize = n;
        }
        
        iTail = 0;
        iHead = 0;
        count = 0;
    }
    
    //Destructor
    ~DynQueue() {
        delete[] array;
    }
    
    //Accessors
    
    /*Returns the object at the front of the queue. It may throw a under
     flow exception.*/
    Type front() const {
        if (!empty()) {
            return array[iHead];
        }
        else {
            throw underflow_error("The queue is empty.\n");
        }
    }
    
    /*Returns the object at the back of the queue. It may throw a under
     flow exception.*/
    Type back() const {
        if (!empty()) {
            return array[iTail - 1];
        }
        else {
            throw underflow_error("The queue is empty.\n");
        }
    }
    
    /*Returns the number of elements currently stored in the queue.*/
    int size() const {
        return count;
    }
    
    /*Returns true if the queue is empty, false otherwise.*/
    bool empty() const {
        return iTail == iHead;
    }
    
    /*Returns the current size of the array.*/
    int capacity() const {
        return arraySize;
    }
    
    /*Displays the contents of the queue*/
    void display() {
        if (!empty()) {
            cout << "Queue: ";
            for (int i = 0; i < count; i++)
            {
                int index = (iHead + i) % arraySize;
                cout << array[index] << " ";
            }
            cout << endl;
        }
        else
            throw underflow_error("The queue is empty.\n");
    }
    
    //Mutators
    
    /*Insert the new element at the back of the queue. If the array is full,
     the size of the array is first doubled.*/
    void enqueue(Type const & data) {
        
        array[iTail] = data;
        iTail = (iTail + 1) % arraySize;
        count++;
        
        if (iTail == iHead) { //check if full
            
            //increment size of the array
            int newCap = arraySize * 2;		//newCap doubles size of new array.
            Type *newArray = nullptr;
            newArray = new Type[newCap];
            
            for (int i = 0; i < count; i++) {
                int index = (iHead + i) % arraySize;	//computes the head index with the old array size.
                newArray[i] = array[index];
            }
            
            delete[] array;
            arraySize = newCap;		//sets array size to newCap.
            array = newArray;
            iHead = 0;
            iTail = count;
        }
    }
    
    /*Removes the element at the front of the queue. If, after the element is removed,
     the array is 1/4 full and the array size is greater than the initial size,
     the size of the array is halved. This may throw a underflow exception.*/
    Type dequeue() {
        
        Type value = array[iHead];
        
        if (empty()) {
            throw underflow_error("The queue is empty.\n");
        }
        else {
            
            iHead = (iHead + 1) % arraySize;
            count--;
            
            if (arraySize > initialSize && count == arraySize / 4) {
                
                int newCap = arraySize / 2;
                Type *newArray = nullptr;
                newArray = new Type[newCap];
                
                for (int i = 0; i < count; i++) {
                    int index = (iHead + i) % arraySize;
                    newArray[i] = array[index];
                }
                
                delete[] array;
                arraySize = newCap;
                array = newArray;
                iHead = 0;
                iTail = count;
            }
        }
        
        return value;
    }
    
    
    /*Clear all the elements stored in the queue.*/
    void clear() {
        
        while (!empty()) {
            dequeue();
        }
    }
    
};
#endif /* queue_h */
