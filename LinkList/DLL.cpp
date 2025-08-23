#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data = val;
        next = prev = NULL;
    }
};

class DoublyList{
private:
    Node* head;
    Node* tail;

public: 
    DoublyList(){
        head = tail = NULL;
    }
    void push_front(int val){
        Node* newNode = new Node(val);
        
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void push_back(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            tail = head = newNode;
        }else{
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front(){
        if(head == NULL){
            cout<<"empty !!";
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
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
    }

    void pop_back(){
        if(head == NULL){
            cout<<"empty !!";
            return;
        }
        if(head == tail){
            head = tail = NULL;
            delete head;
            delete tail;
            return;
        }

        Node* temp = tail;

        tail = tail->prev;
        tail->next = NULL;
        temp->next = NULL;
        delete temp;
    }

    void printDll(){
        Node* temp = head;

        while(temp != NULL){
            cout<<temp->data<<" <=> ";
            temp = temp->next;
        }
        cout<<"NULL\n";
    }

};

int main(){
    DoublyList DLL;
    DLL.push_back(1);
    DLL.push_back(2);
    DLL.push_back(3);
    DLL.printDll();
    DLL.pop_back();
    DLL.printDll();
    return 0;
}