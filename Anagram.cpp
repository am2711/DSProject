#include<iostream>
#include<stdlib.h>
#define MAX 1000
using namespace std;

/* Stack Class */
class stack   
{

	char s[MAX];

	int top;
public:
	stack ()
	{

		top = -1;
	}
	void push (char a);

	void pop ();

	void disp ();

	bool empty ();

	char Top ();
};

/* Function : push
 * --------------------------------
 * Pushes input data onto the Stack.
 */
void stack :: push (char a)  
{

	if (top == MAX -1)
		return;

	else
		s[++top] = a;
}

/*  Function : pop
 *  ----------------------------
 *  Pops elements from the Stack
 */
void stack :: pop ()        
{

	if (empty())
		return;

	else
		top--;
}

/* Function : disp
 * ----------------------------
 *  displays the stack content
 */
void stack :: disp ()          
{
	for (int i = 0; i <= top; i++)
		cout << s[i];

	cout << endl;
}

/* Function : empty
 * ------------------------------
 * returns true if stack is empty
 */
bool stack :: empty ()
{
	return (top == -1);
}

/* Function : Top 
 * ----------------------------------
 * returns the top value in the stack
 */
char stack :: Top ()                 
{
	return s[top];
}
/* end of stack class methods */

/* Queue class begins */
class queue
{

	char Q[MAX];

	int f,rear,count;

public:

    queue()
    {

    	count = 0;
    	f = 0;
    	rear = -1;
    }
    void push (char a);

    void pop ();

    char front ();

    bool empty ();

};

/* Function : push 
 * --------------------------------------------
 * Function pushes an element on into the Queue.
 */
void queue :: push (char a)
{

	if (count == MAX)
		return;

	rear = (rear + 1) % MAX ;
	Q[rear] = a;
	count++;
}

/* Function : pop
 * -------------------------------------------
 * Fucntion deletes an element from the front.
 */
void queue :: pop ()
{

	if(empty())
		return;
	
	f = (f + 1) % MAX ;
	count--;
}

/* Function  : empty
 * ----------------------------------
 * returns true if the queue is empty
 */
bool queue :: empty ()
{
	
	return (count == 0) ;
}

/* Function : front 
 * ------------------------------
 * return the element in the front of the queue
 */
char queue :: front ()
{

	if (!empty())
		return Q[f] ;
	return '#';
}
/* queue methods end */


/* Function : wordSort
 * ----------------------------------------------
 * Function to sort the word in Alphabetcial order.
 */
void wordSort (char word[], int len)  
{

	for (int i = 0; i < len; i++) {

		for (int j = 0; j < len - 1 - i; j++) {

			if (word[j] > word[j + 1]) {

				char temp = word[j];
				word[j] = word[j + 1];
				word[j + 1] = temp;

			}
		}
	}
}

/* main function begins */
int main ()
{
    
    /* getting length */
	int length,wordCount=1;
	cout << "Enter length of Word : ";   
	cin >> length;

    /* Reading the word from user input */
	cout << "Enter the Word with unique Characters \n";
	char *word = new char[length];
    cin >> word;                         

	wordSort (word, length);

    /* printing the 1st word in lexographical order */
	cout << "The permutations are : " << endl;
	cout << word << endl;                          

	stack s;
	queue q;

    /* stacking the 1st word ( word in reverse order ) */
	for (int i = 0; i < length; i++)
		s.push (word[i]);       

	while (1)
	{
		char c, pc = 0;

		while (!s.empty ())
		{

            /* getting the 1st character from stack */
			c = s.Top ();  
			/* repeatedly poping a character from stack */ 
			s.pop ();         

			if (c <= pc)
				break;
            /* enqueueing the character if it does not come alphabetically 
             * before the one that is enqueued just before it 
             */

			q.push (c);       

			if (!s.empty ())
				pc = c;
		}

		if (s.empty () && c > pc)
			break;

        /* last element dequeued called pivot */
		char pivot = c, temp; 
		while (1)
		{

			temp = q.front ();
			q.pop ();

            /* breaking if the value is alphabeticaly after pivot */
			if (temp >= pivot)
				break;            

			q.push (temp);
		}

		s.push (temp);  
		/* enqueueing pivot */
		q.push (pivot);          

		while (1)
		{

            /* repeatedly dequeueing */
			temp = q.front ();
			q.pop ();             

            /* dequeueing until dequeued value is alphabetically before the pivot */
			if (temp <= pivot)   
				break;

            /* repeatedly enqueueing */
			q.push (temp);    
		}

        /* pushing into stack */
		s.push (temp);           

        /* loop running till queue is empty */
		while (!q.empty ())     
		{

			temp = q.front ();
			q.pop ();
			/* repeated dequeing and pushing onto stack */
			s.push (temp);    
		}

        /* displaying the stack content */
		s.disp ();                
		wordCount++;
	}
    
    /* displaying total number of words Printed */
	cout << "Total number of words printed is " << wordCount << " which is " <<   // 
	length << "!" << endl;

	return 0;
}
/* End of File*/	