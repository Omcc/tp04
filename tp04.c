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

	p = splayProcess(p,data);

	tempNode = newNode(data);

	if(data < p->data)
	{
		tempNode->rChild=p;
		tempNode->lChild = p->lChild;
		p->lChild = NULL;
	}
	else
	{
		tempNode->lChild = p;
		tempNode->rChild = p->rChild;
		p->rChild = NULL;
	}


	return tempNode;

}

struct Node* splayProcess(struct Node *p,int data)
{

	if(p==NULL || p->data == data)
	{
		return p;
	}

	if( data > p->data )
	{
		if( !p->rChild) return p;

		if( data > p->rChild->data)
		{
			p->rChild->rChild = splayProcess(p->rChild->rChild,data);
			p = leftRotate(p);
		}
		else if ( data < p->rChild->data)
		{
			p->rChild->lChild = splayProcess(p->rChild->lChild,data);

			if(!p->rChild->lChild)
			p->rChild = rightRotate(p->rChild);

		}

		if(!p->rChild)
			return p;
		else
			return leftRotate(p);


	}

	else
	{
		if(!p->lChild) return p;

		if(data < p->lChild->data)
		{
			p->lChild->lChild = splayProcess(p->lChild->lChild,data);

			p=rightRotate(p);
		}

		else if(data > p->lChild->data)
		{
			p->lChild->rChild = splayProcess(p->lChild->rChild,data);

			if(p->lChild->rChild)
			{
				p->lChild = leftRotate(p->lChild);
			}


		}

		if(!p->lChild)
			return p;
		else
			return rightRotate(p);



	}



}

struct Node* deleteNode(struct Node* p, int data)
{
	if(p==NULL)
	{
		printf("\n Agac bos \n");
	
		return NULL;
	}

	struct Node* lSubTree;
	struct Node* rSubTree;

	struct Node *rootCandidate;

	p = splayProcess(p,data);
	


	

	lSubTree = p->lChild;
	rSubTree = p->rChild;

	if(!lSubTree)
		return rSubTree;

	rootCandidate = findMaxAndPop(&lSubTree);

	rootCandidate->lChild = lSubTree;
	rootCandidate->rChild = rSubTree;
	
	return rootCandidate;




}

struct Node* findMaxAndPop(struct Node **root)
{
	struct Node *q=NULL;

	struct Node *p=*root;

	while(p->rChild)
	{
		q=p;
		p=p->rChild;
	}

	if(q)
	{
		q->rChild=NULL;
	}

	
	if(p==*root)
	{
		*root = p->lChild;

	}

	return p;


	


}





void preorder(struct Node *p)
{
	if(!p)
		return;
	printf("%d ",p->data);
	preorder(p->lChild);
	preorder(p->rChild);
}

void postorder(struct Node *p)
{
	if(!p)
		return;

	postorder(p->lChild);
	postorder(p->rChild);
	printf("%d ",p->data);
}

void inorder(struct Node *p)
{
	if(!p)
		return;
	inorder(p->lChild);
	printf("%d ",p->data);
	inorder(p->rChild);
}



struct Node* searchNode(struct Node *p,int data)
{
	return splayProcess(p,data);
}

