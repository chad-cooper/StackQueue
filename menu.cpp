// Chad Cooper and Kin Ng
// menu.cpp

#include <iostream>
#include <string>
#include "stack.h"
#include "queue.h"
using namespace std;

int main() {
    
    int code;
   	char letter;
    int initSize;

    
    cout << "Enter 's' for a stack or 'q' for a queue: ";
   	cin >> letter;
    cout << endl;
    
   	switch (letter) {
        case 's':
        {
            bool incorrectInput = true;
            
            while(incorrectInput){
                cout << "Enter the initial size of the stack: ";
                cin >> initSize;
                if(cin.fail()){
                    cin.clear();
                    cin.ignore();
                    cout << "Invalid size.\n";
                } else {
                   incorrectInput = false;
                }
            }

            cout << "\nOperation Code: \n";
            cout << "1. Return Capacity\n" // this is really number of items in the structure.
            "2. Return size of data structure\n" // this is really the capacity it can store.
            "3. View first item\n"
            "4. Insert item\n"
            "5. Delete item\n"
            "6. Display\n"
            "7. Clear\n"
            "8. Exit\n\n";


        
            
            DynStack<string> myStack(initSize);
            
            for (;;) {
                
                    cout << "Enter operation code: ";
                    cin >> code;
                 
                
                
                switch (code) {
                        
                    case 1:
                    {
                       	cout << "There are " <<  myStack.size() << " items in your stack." << endl;
                       	break;
                    }
                    case 2:
                    {
                       	cout << "Your stack can currently hold " << myStack.capacity() << " items." << endl;
                       	break;
                    }
                    case 3:
                    {
                       	try {
                            myStack.top();
                            cout << "Top of the stack: '" << myStack.top() << "'" << endl;
                       	}
                       	catch (const exception& e) {
                            cout << e.what();
                       	}
                       	break;
                    }
                    case 4:
                    {
                        string item;
                        cout << "Enter an item to push to the stack: ";
                        
                        cin.ignore();
                        getline(cin, item);
                        
                        //cout << "You entered: " << item << endl;
                        
                        myStack.push(item);
                       	break;
                    }
                    case 5:
                    {
                        try {
                            // if the stack is empty, this will throw the exception without printing the " ' ".
                            string temp = myStack.pop();
                            
                            cout << "'" << temp << "' was removed from the stack.\n";
                        }
                       	catch (const exception& e) {
                            cout << e.what();
                       	}
                    
                       	break;
                    }
                    case 6:
                    {
                        cout << "Displaying the stack: \n\n";
                        myStack.display();
                       	break;
                    }
                    case 7:
                    {
                        myStack.clear();
                        cout << "The stack was cleared. It now contains " << myStack.size() << " items.\n";
                       	break;
                    }
                    case 8:
                    {
                        cout << "Exit succesful." << endl;
                       	return 0;
                    }
                    default:
                    {
                        cout << "Invalid code." << endl;
                    }
                }
                cout << endl;
            }
            break;
    }
    
        
        case 'q':
        {
         
        bool incorrectInput = true;
         
        while(incorrectInput){
            cout << "Enter the initial size of the queue: ";
            cin >> initSize;
            if(cin.fail()){
                cin.clear();
                cin.ignore();
                cout << "Invalid size.\n";
            } else {
                incorrectInput = false;
            }
        }
         
         cout << "\nOperation Code: \n";
         cout << "1. Return Capacity\n" // this is really number of items in the structure.
         "2. Return size of data structure\n" // this is really the capacity it can store.
         "3. View first item\n"
         "4. Insert item\n"
         "5. Delete item\n"
         "6. Display\n"
         "7. Clear\n"
         "8. Exit\n\n";
         
            DynQueue<string> myQueue(initSize);
            
            for (;;) {
                cout << "Enter operation code: ";
                cin >> code;
                
                switch (code) {
                        
                    case 1:
                    {
                       	cout << "There are " <<  myQueue.size() << " items in your queue." << endl;
                       	break;
                    }
                    case 2:
                    {
                       	cout << "Your queue can currently hold " << myQueue.capacity() << " items." << endl;
                       	break;
                    }
                    case 3:
                    {
                       	try {
                            // in case the queue is empty, the exception is thrown before printing anything.
                            myQueue.front();
                            cout << "Front of the queue: '" << myQueue.front() << "'" << endl;
                       	}
                       	catch (const exception& e) {
                            cout << e.what();
                       	}
                       	break;
                    }
                    case 4:
                    {
                         string item;
                         cout << "Enter an item to push to the queue: ";
                         
                         cin.ignore();
                         getline(cin, item);
                         
                         //cout << "You entered: " << item << endl;
                         
                         myQueue.enqueue(item);
                         break;

                    }
                    case 5:
                    {
                        try {
         
                            // if the queue is empty, this will throw the exception without printing the " ' ".
                            string temp = myQueue.dequeue();
         
                            cout << "'" << temp << "' was removed from the queue.\n";
                        }
                       	catch (const exception& e) {
                            cout << e.what();
                       	}
                       	break;
                    }
                    case 6:
                    {
                        try {
                            cout << "Displaying the queue: \n";
                            myQueue.display();
                        }
                        catch (const exception& e) {
                            cout << e.what();
                       	}
                       	break;
                    }
                    case 7:
                    {
                        myQueue.clear();
                        cout << "The queue was cleared. It now contains " << myQueue.size() << " items.\n";
                       	break;
                    }
                    case 8:
                    {
                        cout << "Exit succesful." << endl;
                       	return 0;
                    }
                    default: cout << "Invalid code." << endl;
                }
                cout << endl;
            }
            break;
            
        }
        default:
            cout << "Invalid code." << endl;
            
   	}
    
   	return 0;
    
};
