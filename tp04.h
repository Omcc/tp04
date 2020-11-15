#include <stdio.h>

struct Node{
	struct Node *lChild;
	struct Node *rChild;
	int data;
}*root;

struct Node* sTreeInsert(struct Node *p,int data);
struct Node* splayProcess(struct Node *p,int data);
struct Node* deleteNode(struct Node *p,int data);
struct Node* searchNode(struct Node*p,int data);
struct Node* newNode(int data);

struct Node* leftRotate(struct Node *p);

struct Node* rightRotate(struct Node *p);

struct Node* findMaxAndPop(struct Node **p);


