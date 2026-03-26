#include <iostream>
#include <unordered_map>
using namespace std;

struct Node
{
    pair<int, int> data;
    int cnt;
    Node *next;
    Node *prev;

    Node(int val1, int val2)
    {
        data = {val1, val2};
        cnt = 1;
        next = prev = NULL;
    }
};
struct List
{
    Node *head;
    Node *tail;
    int Size;
    List()
    {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        Size = 0;
    }
    void insertFront(Node *node)
    {
        Node *currNextNode = head->next;
        head->next = node;
        node->next = currNextNode;
        node->prev = head;
        currNextNode->prev = node;
        Size++;
    }
    void deleteNode(Node *node)
    {
        Node *pervNode = node->prev;
        Node *nextNode = node->next;

        pervNode->next = nextNode;
        nextNode->prev = pervNode;
        Size--;
    }
};

class LFUCache
{
    unordered_map<int, List *> freqListMap;
    unordered_map<int, Node *> keyNode;
    int maxSizeCache;
    int minFreq;
    int currSize;

public:
    LFUCache(int capacity)
    {
        keyNode.clear();
        freqListMap.clear();
        maxSizeCache = capacity;
        minFreq = 0;
        currSize = 0;
    }
    void updateFreqListMap(Node *node)
    {
        keyNode.erase(node->data.first);
        freqListMap[node->cnt]->deleteNode(node);

        if (node->cnt == minFreq && freqListMap[node->cnt]->Size == 0)
        {
            minFreq++;
        }

        List *nextHeigherFreqList = new List();
        if (freqListMap.count(node->cnt + 1))
        {
            nextHeigherFreqList = freqListMap[node->cnt + 1];
        }

        node->cnt += 1;
        nextHeigherFreqList->insertFront(node);
        freqListMap[node->cnt] = nextHeigherFreqList;
        keyNode[node->data.first] = node;
    }

    int get(int key)
    {
        if (!keyNode.count(key))
        {
            return -1;
        }

        Node *node = keyNode[key];
        int val = node->data.second;

        updateFreqListMap(node);

        return val;
    }

    void put(int key, int value)
    {
        if (maxSizeCache == 0)
        {
            return;
        }

        if (keyNode.count(key))
        {
            Node *node = keyNode[key];
            node->data.second = value;

            updateFreqListMap(node);
        }
        else
        {
            if (maxSizeCache == currSize)
            {
                List *list = freqListMap[minFreq];
                keyNode.erase(list->tail->prev->data.first);
                freqListMap[minFreq]->deleteNode(list->tail->prev);
                currSize--;
            }
            currSize++;

            minFreq = 1;
            List *listFreq = new List();
            if (freqListMap.count(minFreq))
            {
                listFreq = freqListMap[minFreq];
            }

            Node *node = new Node(key, value);
            listFreq->insertFront(node);
            keyNode[key] = node;
            freqListMap[minFreq] = listFreq;
        }
    }
};

int main()
{
    LFUCache *lfu = new LFUCache(2);
    cout << "LFU Cache : " << endl;

    lfu->put(1, 1);
    lfu->put(2, 2);

    cout << lfu->get(1) << endl;

    lfu->put(3, 3);

    cout << lfu->get(2) << endl;
    cout << lfu->get(3) << endl;

    lfu->put(4, 4);

    cout << lfu->get(1) << endl;
    cout << lfu->get(3) << endl;
    cout << lfu->get(4) << endl;

    return 0;
}