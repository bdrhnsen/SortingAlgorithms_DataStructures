#include <iostream>
#include <string>
using namespace std;
class ItemNode
{
public:
    int value;
    int position;
    ItemNode *next;
};
class Node{
public:
    int totalValue;
    Node *next;
    ItemNode *tailItem;
    ItemNode *headItem;
    Node *prev;

};
// detected but unresolved bugs: first trucks 2nd item cannot be added I couldnt understand why depart does not work
Node* g_tail=NULL;
Node* g_head=NULL;
int numberOfTrucks;
Node* pushTruck(Node** head_ref);
void pushItem(int value) {
    ItemNode *new_node = new ItemNode();
    Node* tmp=g_head;

    if (tmp == NULL){ // for adding the very first item, there is no truck, and so we create one

        tmp=pushTruck(&tmp);

    }
    else{
    while (tmp->tailItem->position==8){ // searching a truck to add Item and if the tail item's position is 8 it means truck is full and we pass to new one
            tmp=tmp->next;

    }
        if(tmp->next == NULL) {
            tmp= pushTruck(&tmp);

            // if all the trucks  are full tmp-> next will return NULL, so I need to create a new Truck else I am already inside the truck
        }

    }
    ItemNode *last = tmp->headItem; // reaching for the first item
        new_node->value = value;
        new_node->next = NULL;
        if (tmp->headItem == NULL) { // if there are no items in the truck new_node will be the first
            tmp->headItem = new_node;
        }
        if(tmp->tailItem==NULL){
            tmp->tailItem=new_node;
        }

    if(tmp->tailItem==new_node){ //this will be true if the new node is the first item of the truck
        new_node->position=1;//and hence it should have position 1
    }
    else new_node->position=(tmp->tailItem->position)+1; // if new node is not the first element it's posiition should be position of the current tail' position +1
    tmp->tailItem->next = new_node; // new_node is what the old tail points to
    tmp->tailItem=new_node; // new_node is the new tail


        tmp->totalValue+=new_node->value; // truck's total value increases by the new item's value

        return ;
}
 Node* pushTruck(Node** head_ref){// returns a pointer to new node // will be called only from inside the pushItem
    if(g_tail == NULL && g_head == NULL){//this means this is the first truck
        Node *new_node= new Node();//create a tuck node and this node is both g_tail and g_head
        g_tail=new_node;
        g_head=new_node;

        numberOfTrucks++;
        return new_node;
    }
    else{
    Node *new_node= new Node();
    Node *temp=g_tail;
    temp->next=new_node; // new node should be old tail->next
    g_tail=new_node; // new node is the new tail

        numberOfTrucks++;
 return new_node;
}}
int getNumOfTrucks(Node* head){ //unused function
    int counter=0;
    Node* current=head;
    while(current!= NULL){
        counter++;
        current=current->next;
    }
    return counter;
}
void ri(Node **head_ref, int truckPosition,int ItemPosition){
    if(*head_ref==NULL){
    cout<< "Reached empty node";
}
Node* temp=*head_ref;
if (truckPosition == 0){
    cout<<"enter valid number";}
        for(int i = 0;temp !=NULL && i <truckPosition-1;i++){
            temp=temp->next;}
    /*if(truckPosition<numberOfTrucks/2){ // if we have 1000 trucks and we want to delete something in truck 999 we shouldn't start from 0 instead we start at the end and approach to truckPosition
    for(int i = 0;temp !=NULL && i <truckPosition-1;i++){
        temp=temp->next;
    }}
    if(truckPosition>numberOfTrucks/2) {
    for(int i=numberOfTrucks;temp!=NULL && i>truckPosition;i--){
        temp=temp->prev; // using doubly linked list property and trying to find correct position by starting at the end.
    }
    */
    if(temp==NULL || temp->next == NULL)
        cout<<"Something is wrong";
    ItemNode* ItemTemp = temp->headItem;
    for (int k=0;ItemTemp!=NULL && k<ItemPosition-1;k++){
        ItemTemp=ItemTemp->next;} //traversing the items

    if(ItemTemp==NULL || ItemTemp->next == NULL) cout<<"Something is wrong";

    ItemNode *next= ItemTemp->next->next; //deleting the item
    int deletedValue=ItemTemp->next->value;
    free(ItemTemp->next);
    ItemTemp->next=next;

    while(ItemTemp->next != NULL){
        ItemTemp=ItemTemp->next;
        ItemTemp->position -= 1; // item's positions need to be corrected
    }
    temp->totalValue -= deletedValue; // substracting the value of the deleted item
}

void depart(){
    Node* temp=g_head;
    while (temp->next!=NULL){
        if(temp->tailItem->position == 8){ // if tail's position is 8 it means we have to depart that truck and I delete the node
            cout<<"here!";
           temp->prev->next = temp->next;
           temp->next->prev=temp->prev;
        }
        else temp=temp->next; // if it is not, continue traversing
    }

}

void rd(Node **head_ref){
    int totalValue=0;
    int valueCounter=0;
    int i = 1;
    string truck="Cargo Truck ";
    string with ="with ";

    if(*head_ref==NULL){
        cout<< "Reached empty node";
    }
    Node* temp=g_head;

    while (temp->next!=NULL){
        ItemNode* ItemTemp = temp->headItem;
        cout << truck<< i << with << (temp->tailItem->position) << " item ->" ;
        for (int k=0;k<(temp->tailItem->position);k++){
            cout<<ItemTemp->value<<"("<<k+1<<")"<<"+";
            valueCounter+=ItemTemp->value;
            ItemTemp=ItemTemp->next;
        }
        temp=temp->next;
        cout<< "=" << valueCounter<<endl;
        totalValue+=valueCounter;
        valueCounter=0;
    i++;
    }
}
void rs(Node** head_ref){
    int valueCounter=0;
    int totalValue=0;
    string truck="Cargo Truck ";
    int i = 1;
    if(head_ref==NULL){
        cout<< "Reached empty node";
    }
    cout<<"Summary: ";
    Node* temp=g_head;
    while (temp->next!=NULL){
        ItemNode* ItemTemp = temp->headItem;
        cout << truck<< i << " ";
        for (int k=0;k<(temp->tailItem->position);k++){
            valueCounter+=ItemTemp->value;

            ItemTemp=ItemTemp->next;
        }
        cout<< "("<<valueCounter<<")";
        temp=temp->next;
        totalValue+=valueCounter;
        valueCounter=0;
        i++;
    }
    cout<< "=" << totalValue;
}
int main() {
    Node* head=nullptr;
    string command1,command;


    while (true) {
        getline(cin, command1); // lets say example input is ai 5
        int length = command1.length(); // length of ai 5 is 4
        string temp = command1;
        string code(temp, 0, 2); // command will be first the characters of temp and that is ai
        if (length == 1 && command1.compare("q") == 0) {
            break;
        }
        if (code.compare("ai") == 0) { // checking if the first 2 chars of input is ai// so ai 5 will enter here
            if (length == 4) {// means item value is single digit
                char num = command1[3];
                int number = num -
                             '0';// converting the char num to integer number 5 note that stoi gives an error if there is only one character so I divided the possibilities to 2

                pushItem(
                        number); // function does not need head pointer because it is used with global pointer head of trucks
            } else { //means item value is more than one digit
                string num(command1, 3, (length) - 3);//num will be '5'
                int number = stoi(
                        num); // converting the string num to integer number 5 note that stoi gives an error if there is only one character

                pushItem(number); // function does not need head pointer because it is used with global pointer head of trucks
            }
        }
        if ((code.compare("ri") == 0))// checking if the first 2 chars of input is ri
        {
            if (length == 6) { // length 6 means ri 4 5 trucks position is single digits
                char T_pos = command1[3]; // position of truck the 4th element of string command1
                char I_pos = command1[5];
                int TruckPos = T_pos - '0';//converting to integer
                int ItemPos = I_pos - '0';

                ri(&g_head, TruckPos, ItemPos);//function call with global head pointer
            } else // trucks position is more than single digit
            {
                int howManyDigitsOfTruck = length -
                                           6;//when it is single digit length is 6 when it is multiple I can take the diffrence with 6
                string T_pos(command1, 3, howManyDigitsOfTruck);
                char I_pos = command1[length - 1]; // last digit will always give item's position
                int ItemPos = I_pos - '0';
                int TruckPos = stoi(T_pos); // converting to int
                cout << "position" << TruckPos << ItemPos;
                ri(&g_head, TruckPos, ItemPos);//function call with global head pointer

            }
        }
        if (command1.compare("rd") == 0) {
            rd(&g_head);//function call with global head pointer

        }
        if (command1.compare("rs") == 0) {
            rs(&g_head);//function call with global head pointer
        }
        if (command1.compare("depart") == 0) {
            depart();
            cout << "depart";
        }

        cout << endl;
    }
    }
