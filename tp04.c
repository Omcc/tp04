#include <stdio.h>
#include "tp04.h"
#include <stdlib.h>

struct Node* newNode(int data)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->lChild=NULL;
	temp->rChild=NULL;
	temp->data = data;
		
	return temp;
}

struct Node* rightRotate(struct Node *p)
{

	struct Node* lChild = p->lChild;
	p->lChild = lChild->rChild;
	lChild->rChild = p;
	
	return lChild;
}

struct Node* leftRotate(struct Node *p)
{
	struct Node* rChild = p->rChild;
	p->rChild = rChild->lChild;
	rChild->lChild = p;
	return rChild;
}



struct Node* sTreeInsert(struct Node *p,int data)
{
	struct Node* tempNode;

	if(!p)
	{
		return newNode(data);
	}

	p = sprayProcess(p,data);

	tempNode = newNode(data);

	if(data < p->data)
	{
		tempNode->rChild=p;
		tempNode->lChild = p->left;
		p->lChild = Null;
	}
	else
	{
		tempNode->lChild = p;
		tempNode->rChild = p->rChild;
		p->rChild = NULL;
	}


	return tempNode;

}

struct Node* splayProcess(struct SprayNode *p,int data)
{

	if( p == NULL || p->data == data)
		return p;
	if( data > p->data )
	{
		if( !p->rChild) return p;

		if( data > p->rChild->data)
		{
			p->right->right = splayProcess(p->right->right,data);
			p = leftRotate(p);
		}
		else if ( data < p->rChild->data)
		{
			p->right->left = splayProcess(p->rChild->lChild,data);

			if(!p->rChild->lChild)
			p->rChild = rightRotate(p->rChild);

		}

		if(!p->rChild)
			return p;
		else
			return leftRotate(p);


	}

}



