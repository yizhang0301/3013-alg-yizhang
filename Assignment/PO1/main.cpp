///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           YI ZHANG
// Email:            zy19950301@126.com
// Label:            PO1
// Title:            Resizing the Stack
// Course:           3013-alg
// Semester:         Spring 2020
//
// Description:  Overview the class,Resizing an array of stack, and pop push 
//               it check it full or empty
//       
//
// Files:  main.cpp          
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
using namespace std;

class ArrayStack
{
private:
	int* array;   
	int size; 
	int top;  
	int maxsize;	 		 			   		 		 			   
	int numResize;   		 			  
public:

	ArrayStack()
	{
		size = 10;
		array = new int[size];
		top = -1;
		numResize = 0;
		maxsize =size;
	}

	ArrayStack(int s)
	{
		size = s;
		maxsize = size;
		array = new int[s];
		top = -1;
		numResize = 0;
	}
	int getnum()
	{
		return numResize;
	}
	int getmax()
	{
		return maxsize; 	 			  
	}
	int getSize()
	{
		return size;
	}
	/**
	* bool: Empty
	*
	* Description:empty stack check
	* Return:true(empty)
	*/
	bool Empty()
	{
		return (top <= -1);
	}

	/**
	*bool: Full
	*
	* Descript: check stack full
	* Return: ture
	*/
	bool Full()
	{
		return (top >= size - 1);
	}

	/**
	*int: Peek
	*
	* Description:return top value
	* Return:value
	*/
	int Peek()
	{
		if (!Empty())
		{
			return array[top];
		}

		return -99; 
	}

	/**
	*int: Pop
	* Description:return top value
	* Return:top num remove
	*/
	int Pop()
	{
		if (!Empty())
		{
			return array[top--];
		}

		return -99; 
	}

	/**
	*void: Print
	*
	* Description:print
	*/
	void Print()
	{
		for (int i = 0; i <= top; i++)
		{
			cout << array[i] << " ";
		}
		cout << endl;
	}

	/**
	*bool: Push
	*
	* Description:push to top
	* Return:ture
	*/
	bool Push(int x)
	{
		if (Full())
		{
			ContainerGrow();
		}
		if (!Full())
		{
			array[++top] = x;
			return true;
		}

		return false;
	}

	/**
	*void: ContainerGrow
	*
	* Description:times 1.75for stack
	*/
	void ContainerGrow()
	{
		int newSize = size * 1.75; 
		int* array1 = new int[newSize]; 

		for (int i = 0; i < size; i++)
		{                         
			array1[i] = array[i];
		}

		delete[] array;
		size = newSize;           
		array = array1;
	}

	/**
	* void: ContainerShrink
	*
	* Description:to move and copy
	*     
	*/
	void ContainerShrink()
	{
		int newSize = size / 2;  
		int* array1 = new int[newSize]; 

		for (int i = 0; i < top; i++)
		{                           
			array1[i] = array[i];
		}

		delete[] array;
		size = newSize;            
		array = array1;
	}

	/**
	*bool: Check
	*
	* Description:check change
	* Returns:true(change)
	*/
	bool CheckResize()
	{
		if (top == Full())
		{
			ContainerGrow();
			return true;
		}
		else if (top == size / 2)
		{
			ContainerShrink();
			return true;
		}
		return false;
	}

	/**
	* int: getSize
	*
	* Description:got the size
	*
	* Return:size
	*/
	
};

void openFiles(ifstream& infile, ofstream& outfile);
void printhead(ifstream& infile, ofstream& outfile);
int changestack(ifstream& infile, ArrayStack& stack, int changes);

int main()
{
	int getend = 0;
	ifstream infile;           
	ofstream outfile;           
	ArrayStack stack;          
	          

	openFiles(infile, outfile);
	printhead(infile, outfile);
	outfile << "Max Stack Size: " << stack.getSize() << endl;
	getend = changestack(infile, stack, getend);
	outfile << "End Stack Size: " << stack.getSize() << endl;
	outfile << "Stack Resized: " << getend << endl;
	outfile << "###############################################################"<<endl;

	infile.close();
	outfile.close();
	return 0;
}
int changestack(ifstream& infile, ArrayStack& stack, int changes)
{
	int num = 0;
	infile >> num;
	while (infile >> num)
	{
		if (num % 2 == 0)
		{
			stack.Push(num);
		}
		else
		{
			stack.Pop();
		}
		if (stack.CheckResize() == true)
		{
			changes++;
		}
		//return changes;
	}
	return changes;
}

void openFiles(ifstream& infile, ofstream& outfile)
{
	char infileName[40];
	char outfileName[40];
	cout << "enter the name of input file:";
	cin >> infileName;
	infile.open(infileName);
	cout << "enter the name of output file:";
	cin >> outfileName;
	outfile.open(outfileName);

}

void printhead(ifstream& infile, ofstream& outfile) 
{
	outfile << "###############################################################" << endl;
	outfile << "CMPS-3013" << endl;
	outfile << "PO1  Resizing the Stack" << endl;
	outfile << "YI ZHANG" << endl;
	
}
