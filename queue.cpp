#include <iostream>
using namespace std;
class Stack{
    char top;
public:

    int a[1000]; // max size of stack
    Stack(){top=-1;} // contrustor function initially top=-1 I
    int pop();
    bool push(int x);
    bool IsEmpty();
    int topEntity();
};
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

void Queue::enQueue(char x) { // add a new node after back and move back to next node
QueueNode* temp= new QueueNode(x);
temp->data=x;
temp->nextNode=NULL;
if(isEmpty()){
    front =temp; // if there are no elements before enQ operation both front and back are points to new elemetn
}
else back->nextNode=temp;
back=temp;
}
void Queue::clear() {

}
void Queue::deQueue() {

   QueueNode* tmp = front;

   if(front==back){
       // after I move front down if it become NULL then it means there is only one element
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
int main() {
    Queue q;
    q.enQueue('a');
    cout<<"front :"<< q.frontE()<<endl;
    cout<<"back :"<< q.back->data<<endl;
    q.enQueue('b');
    cout<<"front :"<< q.frontE()<<endl;
    cout<<"back :"<< q.back->data<<endl;
    q.enQueue('c');
    cout<<"front :"<< q.frontE()<<endl;
    cout<<"back :"<< q.back->data<<endl;
    q.deQueue();
    cout<<"front :"<< q.frontE()<<endl;
    cout<<"back :"<< q.back->data<<endl;

    return 0;
}
