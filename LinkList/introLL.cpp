#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class List{
    Node* head;
    Node* tail;
public:
    List(){
        head = tail = NULL;
    }

    void push_front(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
            return;
        }else{
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
            return;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front(){
        if(head == NULL){
            cout<<"emptyList";
            return;
        }

        Node* temp = head;
        head = temp->next;
        temp->next = NULL;

        delete temp;
    }

    void pop_back(){
        if(head == NULL){
            cout<<"emptyList";
            return;
        }
        Node* temp = head;
        while(temp->next != tail){
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;

    }

    void insert(int value, int position){
        if(position < 0){
            return;
        }
        if(position == 0){
           push_front(value);
           return;
        }

        Node* temp = head;
        for(int i = 0;i<position-1;i++){
            if(temp == NULL){
                return;
            }
            temp = temp->next;
        }
        Node* newNode = new Node(value);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void printLL(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

    int search(int key){
        Node* temp = head;
        int index = 0;

        while(temp != NULL){
            if(temp->data == key){
                return index;
            }

            temp = temp->next;
            index++;
        }
        return -1;
    }
};
int main(){
    List ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_front(4);
    ll.push_front(5);
    ll.printLL();
    cout<<ll.search(2)<<endl;
    return 0;
}