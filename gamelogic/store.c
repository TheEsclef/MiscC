#include <stdlib.h>
#include <stdio.h>
#include "items.h"
#include "backpack.h"

int storeLength = sizeof(storeOffer) / sizeof(storeOffer[0]);

void buyItem(Item *item, Backpack *bag)
{
    if (bag->coins >= item->value)
    {
        addItemToBag(*item, bag);
        bag->coins -= item->value;
        printf("Sucessfully bought the Item\n");
    }
    else{
        printf("Ya aint got da money bigman\n");
    }
    Sleep(1000);
}

void sellItem(Backpack *bag, int index){
    bag->coins += bag->items[index].value;
    removeItemFromBag(bag, index);
    printf("Sucessfully sold the Item for %d", bag->items[index].value);
    Sleep(1000);
}


void openStore(Backpack *bag)
{
    int storeIsOpen = 1;
    int x;
    while (storeIsOpen)
    {
        system("cls");
        printf("You currently have: %d COINS\n", bag->coins);

        for (int i = 0; i < storeLength; i++)
        {
            printf("%d | %-20s | %-50s | weight: %3d | value: %3d \n",
                   i + 2,
                   storeOffer[i]->itemName,
                   storeOffer[i]->description,
                   storeOffer[i]->value,
                   storeOffer[i]->weight);
        }
        printf("\nChoose a mofuckin shiieet you wanna buy ya feel me\n");
        printf("0 - leaves the store and dips tf out\n");
        printf("1 - Open your inventory to sell some stuff\n");
        scanf("%d", &x);
        
        if (x == 0)
        {
            storeIsOpen = 0;
        } else if (x == 1){
            int bagIsOpened = 1;
            while(bagIsOpened == 1){
                system("cls");
                showInventory(*bag);
                printf("\n0 - Close your inventory\n");
                printf("1 - Sell an Item\n\n");
                scanf("%d", &x);
                if (x == 0){
                    bagIsOpened = 0;
                } else if (x == 1){
                    printf("choose an item from your inventory to sell\n\n");
                    scanf("%d", &x);
                    sellItem(bag, x);
                }else{
                    printf("invalid\n");
                }
            }
        }
        else
        {
            buyItem(storeOffer[x - 2], bag);
        }
    }
}