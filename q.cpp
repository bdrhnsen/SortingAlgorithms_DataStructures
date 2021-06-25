#include <iostream>
using namespace std;

class QueueNode{
public:
    char data;
    QueueNode *nextNode;
    QueueNode(char a){
        data=a;
        nextNode=NULL;
    }
};
class Queue{
public:
    QueueNode *front, *back;
    Queue(){ // constructor function
        back=NULL;//initializing back and front to NULL
        front=NULL;
    }
void enQueue(char x);
void deQueue();
char frontE();
bool isEmpty();
void clear();
};
class Stack{
    char top;
public:

    Stack(){top=-1;} // contrustor function initially top=-1
    void clear();
    void pop();
    void push(char x);
    bool IsEmpty();
    char topEntity();
    Queue q1,q2;
};
// Q FUNCTIONS
void Queue::enQueue(char x) { // add a new node after back and move back to next node
QueueNode* temp= new QueueNode(x);
temp->data=x;
temp->nextNode=NULL;
if(isEmpty()){
    front =temp; 
}
else back->nextNode=temp;
back=temp;
}
void Queue::clear() {
    while (!isEmpty())
        deQueue();
}
void Queue::deQueue() {

   QueueNode* tmp = front;

   if(front==back){

       back=NULL;
       front=NULL;
   }
   else front=front->nextNode;// front moves one unit down
   delete(tmp); // poping the element at the top

}
char Queue::frontE() {
 return front->data;
}
bool Queue::isEmpty() {
    if(back==NULL){
        return true;
    }
    else return false;
}
// STACK FUNCTIONS
void Stack::push(char x) {
q2.enQueue(x);
while(!q1.isEmpty()) { // while q1 is not empty add elements of q1 to q2 and dequeue one element from q1
    q2.enQueue(q1.frontE());
    q1.deQueue();
}
// I have to swap 2 q's
Queue tmp = q1;
q1=q2;
q2=tmp;

}
bool Stack::IsEmpty() {
    return q1.isEmpty(); //if q1 is empty stack is empty
}
char Stack::topEntity(){
    return q1.frontE(); // stacks top entity is q1 is front
}
void Stack::pop() {
    if(q1.isEmpty()) cout<<"q is empty";
    q1.deQueue();
}
void Stack::clear() {
    while (!q1.isEmpty())
        q1.deQueue();
}
class Driver{
public:
    Stack s1;
    bool IsPalindrom(string word);
};
bool Driver::IsPalindrom(string word) {
     //abcdcba palindrom // if string length is even no problem but if it is odd I have to not take into account the middle char
     //so if length is odd ,variable i have to hold mid+1
        int length = word.length();
        int i;

        for (i=0; i<length/2;i++){//first push the first half of the elements of word to stack
            s1.push(word[i]);
        }
    if (length %2 == 0) i=length/2;
    else i=length/2+1;
        while(word[i]!='\0'){ // until EOF is reached.
            char temp = s1.topEntity();  // hold the element at the top of the stack
            s1.pop(); // poping the top element
            if(word[i]!=temp){ // comparing the second half of the string with the top element of the stack
                // increasing index holding word
                cout<<word<<" is not a palindrome"<<endl;
                return false;
                // if even one of the comparisons is false return false word is not a polindrom
            }
            i++;

        }
    cout<<word<<" is a palindrome"<<endl;
        return true;

    }

int main() {
    Driver driver;

    string command;
while(true){
    getline(cin,command);
    if(command.compare("q")==0) break;

    else driver.IsPalindrom(command);

}



    return 0;
}
