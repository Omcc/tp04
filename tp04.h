#include <stdio.h>

struct Node{
	struct SprayNode *lChild;
	struct SprayNode *rChild;
	int data;
}*root;

struct Node* sTreeInsert(struct Node *p,int data);
struct Node* newNode(int data);

struct Node* leftRotate(struct Node *p);

struct Node* rightRotate(struct Node *p);


