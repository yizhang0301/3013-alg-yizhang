///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           YI ZHANG
// Email:            zy19950301@126.com
// Label:            AO3
// Title:            Commenting c++ code
// Course:           3013-alg
// Semester:         Spring 2021
//
// Description:
//       The test about linked list and overloaded operators.
//
// Usage:
//       
//
// Files:  main.cpp          
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>

int A[100];     //array of 100 integers

/**
 * Node
 * 
 * Description:
 *      makes a structured node with a int value and a pointer to a node type
 * 
 * Public Methods:
 *      int     x;
 *      Node    *next;
 *              Node()
 *              Node(int n)
 * 
 * Usage: 
 * 
 *      Node N1;        //makes a node that points to NULL and sets its stored
 *                      //value to -1
 *                     
 *                      //or
 * 
 *      Node N2(5)      //makes a node that points to NULL and sets its stored
 *                      //value to 5
 *      N2.next = NULL  //sets the next pointer in the node to NULL
 *      
 *      
 */
struct Node {
    int x;          //int value of node
    Node *next;     //pointer to point to another node
    /**
     * Public: Node()
     * 
     * Description:
     *      this is a default constructor thata sets defaults for the nodes 
     *      value and pointer
     * 
     * Params:
     *      None
     * 
     * Returns:
     *      None
     */
    Node() {
        x = -1;
        next = NULL;
    }
    /**
     * Public: Node(int n)
     * 
     * Description:
     *      This is a perameterized constructor that takes in an int to store 
     *      it in a node
     * 
     * Params:
     *      int     :   value to store in node
     * 
     * Returns:
     *      None
     */
    Node(int n) {
        x = n;
        next = NULL;
    }
};

/**
 * List
 * 
 * Description:
 *      A simple singly linked list class
 * 
 * Public Methods:
 *                      List() 
 *      void            Push(int val)
 *      void            Insert(int val) 
 *      void            PrintTail()
 *      string          Print()
 *      int             Pop()
 *      List            operator+(const List &Rhs)
 *      int             operator[](int index)
 *      friend ostream  &operator<<(ostream &os, List L)
 *      
 * Private Methods:
 *      Node        *Head;
 *      Node        *Tail;
 *      int         Size;
 * 
 * Usage: 
 * 
 *      List L1,L2          //creates 2 lists of integers
 *      L1.Push(5)          //pushes 5 onto the end of the list 
 *      L1.Insert(23)       //inserts 23 before the head of the list
 *      L1.Pop()            //removes tail value from list
 *      L1.PrintTail()      //prints the value at the last node of the list
 *      L1.Print()          //Prints the list
 *      List L3 = L1 + L2   //makes a new list where the values of the right
 *                          // list is added to the tail of the left list
 *      List L1[3]          //gets the value in the 3rd position in the list
 *      cout << L1          //prints all the values in that list in order
 * 
 */
class List {
private:
    Node *Head;     //node pointer for head of list
    Node *Tail;     //node pointer for tail of list
    int Size;       //int for size of list

public:
    /**
     * Public: List()
     * 
     * Description:
     *      Default constructor that makes a list of NULL and sets size to 0
     * 
     * Params:
     *      None
     * 
     * Returns:
     *      None
     */
    List() {
        Head = Tail = NULL;
        Size = 0;
    }

    /**
     * Public: Push(int val)
     * 
     * Description:
     *      Pushes a value to the end of the list
     * 
     * Params:
     *      int val     //a value to put into the node
     * 
     * Returns:
     *      None
     */
    void Push(int val) {
        // allocate new memory and init node
        Node *Temp = new Node(val);

        if (!Head && !Tail) {
            Head = Tail = Temp;
        } else {
            Tail->next = Temp;
            Tail = Temp;
        }
        Size++;
    }

    /**
     * Public: Insert(int val)
     * 
     * Description:
     *      Describe the functions purpose
     * 
     * Params:
     *      int val     //a value to put into the node
     * 
     * Returns:
     *      None
     */
    void Insert(int val) {
        // allocate new memory and init node
        Node *Temp = new Node(val);

        // figure out where it goes in the list

        Temp->next = Head;
        Head = Temp;
        if (!Tail) {
            Tail = Head;
        }
        Size++;
    }

    /**
     * Public: PrintTail()
     * 
     * Description:
     *      Prints the tail value
     * 
     * Params:
     *      None
     * 
     * Returns:
     *      none
     */
    void PrintTail() {
        cout << Tail->x << endl;
    }

    /**
     * Public/Private/Protected : function_name
     * 
     * Description:
     *      creates a string that has all of the values of the list in it
     *      so that it can be printed
     * 
     * Params:
     *      None
     * 
     * Returns:
     *      string  :   a string of values from the list
     */
    string Print() {
        Node *Temp = Head;
        string list;

        while (Temp != NULL) {
            list += to_string(Temp->x) + "->";
            Temp = Temp->next;
        }

        return list;
    }

    /**
     * Public: Pop()
     * 
     * Description:
     *      removes the tail node from the list
     * 
     * Params:
     *      None
     * 
     * Returns:
     *      Int :   the value in the removed node
     */
    // not implemented
    int Pop() {
        Size--;
        return 0; //
    }

    /**
     * Public: operator+(const List &Rhs)
     * 
     * Description:
     *      allowes user to combine 2 lists into a single list
     * 
     * Params:
     *      const List       &Rhs
     * 
     * Returns:
     *      List    :   Returns a list that has the head of the right list
     *                  attached to the tail of the left list
     */
    List operator+(const List &Rhs) {
        // Create a new list that will contain both when done
        List NewList;

        // Get a reference to beginning of local list
        Node *Temp = Head;

        // Loop through local list and Push values onto new list
        while (Temp != NULL) {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        // Get a reference to head of Rhs
        Temp = Rhs.Head;

        // Same as above, loop and push
        while (Temp != NULL) {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        // Return new concatenated version of lists
        return NewList;
    }

    /**
     * Public: operator[](int index)
     * 
     * Description:
     *      This method allows the user to get the value at a position 
     *      in the list
     * 
     * Params:
     *      int     index
     * 
     * Returns:
     *      int :   This function returns the int value at a given index
     */
    // Implementation of [] operator.  This function returns an
    // int value as if the list were an array.
    int operator[](int index) {
        Node *Temp = Head;

        if (index >= Size) {
            cout << "Index out of bounds, exiting";
            exit(0);
        } else {

            for (int i = 0; i < index; i++) {
                Temp = Temp->next;
            }
            return Temp->x;
        }
    }

    /**
     * Friend : ostream &operator<<(ostream &os, List L)
     * 
     * Description:
     *      allows the user to output the list with os commands 
     *      like cout << L1;
     * 
     * Params:
     *      ostream     &os
     *      List        L
     * 
     * Returns:
     *      ostream :   returns the string made from print to be used 
     *                  with the '<<' operator
     */
    friend ostream &operator<<(ostream &os, List L) {
        os << L.Print();
        return os;
    }
};

int main(int argc, char **argv) {
    List L1;                            //makes 2 lists to store ints
    List L2;

    for (int i = 0; i < 25; i++) {
        L1.Push(i);                     //pushes 1-24 to list 1
    }

    for (int i = 50; i < 100; i++) {
        L2.Push(i);                     //pushes 50-99 to list 2
    }

    //cout << L1 << endl;
    L1.PrintTail();                     //prints tail of list 1
    L2.PrintTail();                     //prints tail of list 2

    List L3 = L1 + L2;                  //combines both lists
    cout << L3 << endl;                 //outputs combined list

    cout << L3[5] << endl;              //outputs position 5 in combined list
    return 0;
}
