/* 
 * Stack.h
 *
 * Description: Stack data collection ADT class.
 *              Implementation of an int sequence with push/pop ...
 * Class Invariant: ... in a LIFO order
 *
 * Author: Arsen Nurshaikhy
 * Date: 30th of September, 2019
 */
 
class Stack {

    private:

        // Description: Nodes for a singly-linked list
        class StackNode {
            public:
                int data;
                StackNode * next;
        };
        

        // Description: head = ptr to the first StackNode (NULL if empty)
        //              tail = ptr to the last StackNode (NULL if empty)
        StackNode * head;
        StackNode * tail;

    public:

        // Description: Constructor
        // Postcondition: Stack is empty
        Stack();


        // Description: Destructor 
        // Postcondition: All memory released
        ~Stack();


        // Description: Insert newElement to the top of the stack. 
        void push(int newElement);


        // Description: Remove and return element at the top of the stack.
        // Precondition: Stack is not empty   
        int pop();


        // Description: Return the topmost element of the stack.
        // Precondition: Stack is not empty   
        int peek() const;


        // Description: Is stack empty? 
        bool isEmpty() const;
};

