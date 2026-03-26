#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class Node
{
public:
    pair<int, int> data;
    Node *next;
    Node *prev;

    Node(int val1, int val2)
    {
        data = {val1, val2};
        next = prev = NULL;
    }
};
class LRUCache
{
    unordered_map<int, Node *> mpp;
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);
    int cap;

public:
    LRUCache(int capacity)
    {
        mpp.clear();
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void insertFront(Node *node)
    {
        Node *currNextNode = head->next;
        head->next = node;
        node->next = currNextNode;
        node->prev = head;
        currNextNode->prev = node;
    }
    void deleteNode(Node *node)
    {
        Node *pervNode = node->prev;
        Node *nextNode = node->next;

        pervNode->next = nextNode;
        nextNode->prev = pervNode;
    }

    int get(int key)
    {
        if (!mpp.count(key)) return -1;

        Node *node = mpp[key];
        int val = node->data.second;

        deleteNode(node);
        insertFront(node);

        return val;
    }

    void put(int key, int value)
    {
        if (cap == 0) return;

        if (mpp.count(key))
        {
            Node *node = mpp[key];
            node->data.second = value;

            deleteNode(node);
            insertFront(node);
        }
        else
        {
            if (mpp.size() == cap)
            {
                Node *node = tail->prev;
                mpp.erase(node->data.first);

                deleteNode(node);
                delete (node);
            }

            Node *node = new Node(key, value);
            mpp[key] = node;
            insertFront(node);
        }
    }
};

int main()
{
    LRUCache *obj = new LRUCache(4);
    cout << "LRU Cache : " << endl;
    obj->put(1, 1);
    obj->put(2, 2);
    cout << obj->get(1) << endl; // 1
    obj->put(3, 3);
    obj->put(4, 4);
    obj->put(5, 5); // evicts key 2

    cout << obj->get(2) << endl; // -1
    return 0;
}