#include<iostream>
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
class circularLL{
private:
    Node* head;
    Node* tail;

public:
    circularLL(){
        head = tail = NULL;
    }

    void push_fornt(int val){
      Node* newNode = new Node(val);
      
      if(head == NULL){
        head = tail = newNode;
        tail->next = newNode;
      }else{
        newNode->next = head;
        head = newNode;
        tail->next = head;
      }
    }

    void push_back(int val){
      Node* newNode = new Node(val);
      
      if(head == NULL){
        head = tail = newNode;
        tail->next = newNode;
      }else{
        newNode->next = head;
        tail->next = newNode;
        tail = newNode;
      }
    }
    
    void deleteAtHead(){
      if(head == NULL){
        cout<<"Empty list\n";
        return;
      }

      if(head == tail){
        //single node is present in LL
        delete head;
        head = tail = NULL;
        cout<<"Empty list\n";
        return;
      }
      Node* temp = head;
      head = head->next;
      tail->next = head;
      temp->next = NULL;
      delete temp;
    }

    void deleteAtTail(){
      if(head == NULL){
        cout<<"Empty list";
        return;
      } 

      if(head == tail){
        //single node is present in LL
        delete head;
        head = tail = NULL;
        cout<<"Empty list\n";
        return;
      }

      Node* prev = head;
      while(prev->next != tail){
        prev = prev->next;
      }
      
      delete tail;
      tail = prev;
      tail->next = head;
    }
    void print(){
      if(head == NULL)return;

      cout<<head->data<<" -> ";
      Node* temp = head->next;

      while(temp != head){
        cout<<temp->data<<" -> ";
        temp = temp->next;
      }
      cout<<temp->data<<endl;

    }
};

int main(){
    circularLL cl;
    cl.push_back(1);
    cl.push_back(2);
    cl.push_back(3);
    cl.print();
    cl.deleteAtTail();
    cl.print();
    return 0;
}