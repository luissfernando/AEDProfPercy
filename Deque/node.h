#ifndef NODE_H
#define NODE_H
class Node{
    public:
        int data;
        Node *next;
        Node *prev;
        Node(int);
        Node();
        ~Node();
};

#endif // !NODE_H