#include <iostream>
#include <fstream>

using namespace std;

/**
 * ArrayStack
 *
 * Description:
 *      Array based stack
 *
 * Public Methods:
 * Usage:
 */
class ArrayStack {
private:
	int* A;                     // pointer to array of int's
	int size;                   // current max stack size
	int top;                    // top of stack
	int timesResized;           // times stack resized
	int MaxSize;                // the max size the stack reaches


public:
	/**
	 * ArrayStack
	 * Description:
	 *      Constructor no params
	 * Params:None
	 *
	 * Returns:
	 */
	ArrayStack() {
		size = 10;
		A = new int[size];
		top = -1;
		timesResized = 0;
		MaxSize = size;
	}

	/**
	 * ArrayStack
	 *
	 * Description: Constructor size param
	 *
	 * Params: int size
	 *
	 * Returns:
	 */
	ArrayStack(int s) {
		size = 10;
		A = new int[s];
		top = -1;
		timesResized = 0;
		MaxSize = size;
	}

	/**
	 * Public bool: Empty
	 * Description:check Stack empty
	 * Params:
	 * Returns: bool true = empty
	 */
	bool Empty() {
		return (top <= -1);
	}

	/**
	 * Public bool: Full
	 * Description:check full
	 * Params:
	 * Returns: [bool] true = full
	 */
	bool Full() {
		return (top >= size - 1);
	}

	/**
	 * Public int: Peek
	 * Description: Returns top value on stack
	 * Params:
	 * Returns int top value
	 */
	int Peek() {
		if (!Empty()) {
			return A[top];
		}

		return -99; // some sentinel value
                // not a good solution
					
	}

	/**
	 * Public int: Pop
	 * Description:   Returns top value and removes it from stack, checks if it needs to be resized
	 *
	 * Params:
	 * Returns:  int top value
	 */
	int Pop() {
		if (!Empty()) {
			CheckResize();
			return A[top--];
		}

		return -99; // some sentinel value
                // not a good solution
	}

	/**
	 * Public void: Print
	 * Description:   Prints stack standard out
	 * Params:
	 * Returns:
	 */
	void Print() {
		for (int i = 0; i <= top; i++) {
			cout << A[i] << " ";
		}
		cout << endl;
	}

	/**
	 * Public bool: Push
	 *
	 * Description: Adds an item to top of stack and check it
	 *
	 * Params:  int item to be added
	 *
	 * Returns:  bool; success = true
	 */
	bool Push(int x)
	{
		A[++top] = x;
		CheckResize();
		return true;
	}

	/**
	 * Public void: ContainerGrow
	 *
	 * Description:Resizes stack by 2
	 * Params:
	 * Returns:
	 */
	void ContainerGrow()
	{
		int newSize = size * 2;			    // 2 size of original
		int* B = new int[newSize];			// allocate new memory

		for (int i = 0; i < size; i++) {    // copy values  in new array
			B[i] = A[i];
		}

		delete[] A;							// delete old array

		size = newSize;						

		A = B;								// reset the pointer

		if (MaxSize < newSize)
		{
			MaxSize = size;					// checks if maxsize needs 
											// increase
		}
	}

	/**
	 * Public void: ContainerShrink
	 *
	 * Description: Resizes the stack by /2
	 * Params:
	 * Returns:
	 */
	void ContainerShrink()
	{
		int newSize = size / 2;				// halves size of original
		if (newSize < 10)
		{
			newSize = 10;
		}
		int* B = new int[newSize];			// allocate new memory

		for (int i = 0; i <= top; i++) {    // copy values to new array
			B[i] = A[i];
		}

		delete[] A;							// delete old array

		size = newSize;						// save new size

		A = B;								// reset array pointer
	}

	/**
	 * Public void: CheckResize
	 *
	 * Description: checks if the stack needs to be resized
	 * Params:
	 * Returns:
	 */
	void CheckResize()
	{
		if (Full())
		{
			ContainerGrow();			//shrinks
			timesResized++;				//increments times resized
		}
		else if (top < (size / 2) && size > 10)
		{
			ContainerShrink();			//grows
			timesResized++;				//increments times resized
		}
	}

	/**
	 * Public void: getSize
	 *
	 * Description:size of the stack
	 * Params:
	 * Returns:
	 */
	int getSize()
	{
		return size;
	}

	/**
	 * Public void: getTimesResized
	 *
	 * Description:gets the times the stack was resized
	 * Params:
	 * Returns:
	 */
	int getTimesResized()
	{
		return timesResized;
	}

	/**
	 * Public void: getMaxSize
	 *
	 * Description: gets the max size of the stack
	 * Params:
	 * Returns:
	 */
	int getMaxSize()
	{
		return MaxSize;
	}

	/**
	 * Public void: getMaxSize
	 * Description:top of the stack
	 * Params:
	 * Returns:
	 */
	int getTop()
	{
		return top;
	}
};

// MAIN DRIVER
int main()
{
	ArrayStack stack;				
	ifstream infile;				
	ofstream outfile;				
	infile.open("nums_test.dat");
	outfile.open("output.txt");

	int num;						

	while (!infile.eof())
	{
		infile >> num;
		if (num % 2 == 0)			//pushes evens
		{
			stack.Push(num);
		}
		else						//pops when odd is read
		{
			stack.Pop();
		}
	}
	outfile << "################################################################"<<endl;
	outfile << "\tAssignment 4 - Resizing the Stack"<< endl;
	outfile << "\tCMPS 3013" << endl;
	outfile << "\tyi zhang" <<endl;
	outfile << "\tMax Stack Size: " << stack.getMaxSize() << endl;
	outfile << "\tEnd Stack Size: " << stack.getSize() << endl;
	outfile << "\tStack Resized:  " << stack.getTimesResized() << " Times" << endl;
	outfile << "################################################################\n";
}