#include<iostream>
using namespace std;
//from scrach
class Node{
public:
     int val;
     Node* next;

    Node(int val){
        this->val = val;
        next = NULL;
    }    
};
class LinkedList{
    Node* head;
    Node* tail;
public:
    LinkedList(){
        head =  tail = NULL;
    }
    void push_front(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
        }else{
            newNode->next = head;
            head = newNode;
        }
    }
    void pop_front(){
        if(head == NULL){
           return;
        }
        if(head == tail){
            head = tail = NULL;
            delete head;
            delete tail;
            return;
        }
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    void topPrint(){
        Node* top = head;
        cout<<top->val;
    }
    bool empty(){
        return head == NULL;
    }

};
class Stack{
    LinkedList ll;
public:
    void push(int val){
        ll.push_front(val);
    }

    void pop(){
        ll.pop_front();
    }
    void top(){
       ll.topPrint(); 
       return;
    }
    bool isEmpty(){
       return ll.empty();
    }
};

int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    while(!s.isEmpty()){
        s.top();
        s.pop();
        cout<<" ";
    }
    cout<<endl;
    return 0;
}