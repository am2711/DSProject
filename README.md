## C++ Application to Print all Anagrams for a given word using Stacks and Queues

#### Submitted as part of Data Structures Assignnment 3
![Logo of the college](http://www.technomelange.in/images/MITManipalEducation.png)

## 1 Readme :

### 1.1 Problem Statement :
	To generate all N! permutations of a given word with unique Characters the using
	algorithm given in the Question with the help of Stacks and Queues.

### 1.2 Execution :
	This C++ Program can be Executed by compiling it with any modern C++ compiler
	like gcc , clang or mingw. CodeBlocks uses mingw.
	This Problem has been solved using one Stack and Queue , the Source has been
	included in the Anagram.cpp File.

### 1.3 Input :
	The First Input is the length of the word to be entered by the User.
	The length should be an integer greater than or equal to 1.
	If length entered is greater than or equal to 10 then the Execution time might be in
	in minutes since 10! is of the order 107.
	The next input is the Word and each character of the word should be unique or else
	the Execution is undefined.
	After Entering the input , we can Expect all the Anagrams of the given word in
	Lexicographical order .
	The Program also Prints the number of words printed which is always N!.

### 1.4 Working:
	This Program has two classes the stack and the queue class. The Stack class has
	the following Function :
	void push (char a) -> This Function Pushes a value onto the Stack.
	void pop () -> This Function pops a value from the top of the Stack.
	void disp () -> This Function displays the stack from bottom to top.
	bool empty () -> This is a function which returns true when the stack is empty.
	char Top () -> This Function returns the character on the top of the stack.
	The Queue class has the following Function :

	void push (char a) -> This Function inserts an element at the rear of the queue.
	void pop () -> This Function pops an element from the front of the queue.
	char front () -> This Function returns the element which is at front of the queue.
	bool empty () -> This Function returns true when the queue is empty.
	We have implemented the queue class as a circular queue.
	Utility Function:
	void wordSort(char word[],int len)
	The Above Function sorts the word in Alphabetical order.
	Example :
	char word[] = {’m’,’o’,’n’,’e’,’y’};
	wordSort(word,5);
	Now Word is ”emnoy” .

	This Function is needed beacause the algorithm used here generates the next
	lexicographical sequece of the input word, hence we need to start
	from the first sequence which comes in the lexicographical order.