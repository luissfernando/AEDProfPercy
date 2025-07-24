#ifndef NODE_H
#define NODE_H

class Node{
    public:
        int date;
        int peso;
        Node *next;
        Node(int,int);
        ~Node();
};
#endif // DEBUG