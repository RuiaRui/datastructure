
#include<iostream>

using namespace std;

 class Stack
{

public:
	Stack()
	{
		top = 1;
		flag = 1;
		memset(stack, 0, sizeof(stack));
		memset(output, 0, sizeof(output));
	}

	//模拟pop
	void pop() {
		output[flag] = stack[top];
		top--;
		flag++;
	}
	//模拟push
	void push(int a) {
		top++;
		stack[top] = a;
		
	}

	//display thw reasult
	void display() {

		while (!isEmpty()) {
			pop();
		}

		for (int i = 1; i < 5; i++) {
			cout << output[i];
	 }
		cout << endl;
		
	}


	//if the stack is empty
	bool isEmpty() {
		return top == 1;
	}
	


private: 
	int top = 0;
	int flag = 1;
	int stack[6];
	int output[6];

};

 class Sequence {
 public:
	 //constructer
	 Sequence() {
		 memset(sequence, 0, sizeof(sequence));

		 for (int i = 1; i < 5; i++) {
			 sequence[i] = i;
		 }
	 }

	 // the sequence finishes pushing into stack
	 int isFinish() {
		 return top==4;
	 }
	 
	 //write in
	 int write() {
		 top++;
		 return sequence[top];
		 
	 }
	 

 private:
	 int top = 0;
	 int sequence[6];
	 

 };

 
 void outputAll(Stack stack,Sequence sequence,bool pop);//模拟过程


int main()
{
	Stack stack;
	Sequence sequence;
	outputAll(stack, sequence, false);

	system("pause");
}


void outputAll(Stack stack, Sequence sequence, bool pop) {
	if (!pop) {
		stack.push(sequence.write());
		if (sequence.isFinish()) {
			stack.display();
			return;
		}
	}
	else {
		stack.pop();
	}

	if (!stack.isEmpty()) {
		outputAll(stack, sequence, true);
	}
	outputAll(stack, sequence, false);
}