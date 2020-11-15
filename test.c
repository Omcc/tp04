#include <stdio.h>
#include "tp04.h"

int main()
{
	root = NULL;
	
	int choice=999;
	int sayi;
	int found;

	while(choice)
	{
		printf(" \n");
		printf(" Agaca sayi eklemek icin 1'e\n");
		printf(" Agactan sayi silmek icin 2'e \n");
		printf(" Agacta sayı aramak icin 3'e \n");
		printf(" preorder icin 4'e \n");
		printf(" postorder icin 5 'e \n");
		printf(" inorder icin 6'ya \n");
		printf(" Cikmak icin 0'a basiniz \n");

		printf(" Input: ");scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				printf("\n sayi: \n");
				scanf("%d",&sayi);
				root=sTreeInsert(root,sayi);
				break;

			case 2:
				found=0;

				printf("\n Silmek istediğiniz sayı: \n");
				scanf("%d",&sayi);
				root=deleteNode(root,sayi);
				break;
			case 3:
				found=0;
				printf("\n Aramak istediginiz sayi: \n");
				scanf("%d",&sayi);
				root=searchNode(root,sayi);
				if(root && root->data == sayi)
					printf("\n Sayi %d bulundu roota tasindi\n ",sayi);
				else
					printf("\n Sayi %d bulunamadi.\n",sayi);
				break;
			case 4:
				printf("\n Preorder: ");
				preorder(root);
				printf("\n");
				break;
			case 5:
				printf("\n Postorder: ");
				postorder(root);
				printf("\n");
				break;
			case 6:
				printf("\n Inorder: ");
				inorder(root);
				printf("\n");
				break;


		}





	}

	


}




