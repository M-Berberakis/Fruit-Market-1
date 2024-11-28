#include<stdio.h>
#include<stdlib.h>

int price[3] = {0, 0, 0};
int budget = 0;
char csmtch;
char fruit[3] = { 'A', 'O', 'P' };
char fruitname[3][20] = { "Apple", "Orange", "Pear" };
char ch = 156;


void ItemPrefixes()
{
	printf("*** ItemPrefixes ***\n");
	for (int i = 0; i <= 2; i++)
	{
		printf("%c: %s\n", fruit[i], fruitname[i]);
	}
	printf("********************\n");
	printf("\n");

}

void Shopkeeper()
{
	printf("*** SHOPKEEPER PANEL ***\n");

	for (int i = 0; i <= 2; i++)
	{
		printf("Please enter %s price:%c", fruitname[i], ch);
		scanf_s("%i", &price[i]);
	}
	printf("\n");
}

void ShopMenu()
{
	printf("***** Shop Menu *****\n");
	printf("Item:	Price\n");
	for (int i = 0; i <= 2; i++)
	{
		printf("%c: %c%d\n",fruit[i], ch, price[i]);
	}
	printf("\n\n");
}

void Customer()
{
	int index = 5;
	
	printf("*** CUSTOMER PANEL ***\n");
	printf("Please enter your budget:%c", ch);
	scanf_s("%i", &budget);
	printf("\n");
	printf("Please enter ItemPrefix from the Menu to purchase:");
	scanf_s(" %c", &csmtch, 1);
	printf("\n");

	if (csmtch == 'a' || csmtch == 'A')
	{
		index = 0;
	}

	else if (csmtch == 'o' || csmtch == 'O')
	{
		index = 1;
	}

	else if (csmtch == 'p' || csmtch == 'P')
	{
		index = 2;
	}

	else 
	{
		printf("\nPURCHASE FAILED!\n");
		printf("Low budget or missing item.\n");
		printf("\n\nThanks for shopping with us!\n");
		exit(0);
	}

	if (budget < price[index]) 
	{
		printf("\nPURCHASE FAILED!\n");
		printf("Low budget or missing item.\n");
		printf("\n\nThanks for shopping with us!\n");
		exit(0);
	}

	else
	{
		printf("\nPURCHASE SUCCESS!\n");
		printf("Purchase details\n");
		printf("--------------------\n");
		printf("Item: %c\n", csmtch);
		printf("Price: %c%i\n",ch, price[index]);
		printf("Remaining budget: %c%i",ch, budget - price[index]);
		printf("\n\nThanks for shopping with us!\n");
	}

}

int main()
{
	ItemPrefixes();
	Shopkeeper();
	ShopMenu();
	Customer();

	return 0;
}



