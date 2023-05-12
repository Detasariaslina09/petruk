//DETA SARI ASLINA
//2217051117
//STACK

#include <iostream>
#include <stack>

using namespace std;

void printStack(stack <int> myStack){
	stack <int> ms = myStack;
	if(myStack.empty()){
		cout << "Error: stack kosong";
	}
	else{
		while(!myStack.empty()){
			cout << "[>]" << myStack.top() << endl;
			myStack.pop();
		}
		cout << endl;
	}
}

int main(){
	stack<int> myStack;
	
	myStack.push(10);
	myStack.push(20);
	myStack.push(30); 
	
	printStack(myStack);
	
	cout << "Top element: " << myStack.top() << endl;
	
	myStack.pop();
	cout << endl;
	
	printStack(myStack);
	
	cout << "Top element after pop: " << myStack.top() << endl;
	
	cout << "Stack size: " << myStack.size() << endl;
	
	//fungsi clear stack
	while(!myStack.empty()){
		myStack.pop();
	}
	
	printStack(myStack);
	return 0;
}

//queue

#include <iostream>
#include <queue>

using namespace std;

void printQueue(queue <int> myQueue){
	queue <int> mq = myQueue;
	if(myQueue.empty()){
		cout << "Error: queue kosong";
	}
	else{
		while(!myQueue.empty()){
			cout << "[>]" << myQueue.front() << endl;
			myQueue.pop();
		}
		cout << endl;
	}
}

int main(){
	queue<int> myQueue;
	
	myQueue.push(10);
	myQueue.push(20);
	myQueue.push(30); 
	
	printQueue(myQueue);
	
	cout << "Front element: " << myQueue.front() << endl;
	
	myQueue.pop();
	cout << endl;
	
	printQueue(myQueue);
	
	cout << "Front element after pop: " << myQueue.front() << endl;
	
	cout << "Queue size: " << myQueue.size() << endl;
	
	//fungsi clear stack
	while(!myQueue.empty()){
		myQueue.pop();
	}
	
	printQueue(myQueue);
	return 0;
}
