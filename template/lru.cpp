#include <unordered_map>

class Node
{
public:
    int key, val;
    Node next, prev;
    Node(int k, int v) {
        this.key = k;
        this.value = v;
    }
};

class DoubleList
{
private:
    Node head, tail;
public:
    int size;
    DoubleList() {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head.next = tail;
        tail.prev = head;
        size = 0;
    }
    
    void addLast(Node x) {
        x.prev = tail.prev;
        x.next = tail;
        tail.prev.next = x;
        tail.prev = x;
        ++size;
    }

    void remove(Node x) {
        x.prev.next = x.next;
        x.prev.prev = x.prev;
        --size;
    }

    Node removeFirst() {
        if (head.next = tail) return nullptr;

        Node first = head.next;
        remove(first);
        return first;
    }
};

class LRUCache {
private:
    unordered_map<int, node> hash;
    DoubleList cache;
    int cap;

public:
    LRUCache(int capacity) {
        this.cap = capacity;
        map = new 
    }
}