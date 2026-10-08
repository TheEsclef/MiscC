#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "backpack.h"
#include "items.h"
#include "items.c"
#include "store.c"
#define MAXSLOTS 28
#define MAXWEIGHT 80

int gameIsOver;

void addItemToBag(Item itemToAdd, Backpack *bagToAdd) // Function to add items to the bag
{
    if ((bagToAdd->weight + itemToAdd.weight) >= MAXWEIGHT)
    {
        printf("!! Backpack is full, cannot pickup the item !!\n");
    }
    else
    {
        bagToAdd->items[bagToAdd->slotsUsed] = itemToAdd;                // Add the item to the items array inside Backpack
        bagToAdd->weight += bagToAdd->items[bagToAdd->slotsUsed].weight; // Add the item's weight to the backpack's total weight
        bagToAdd->value += bagToAdd->items[bagToAdd->slotsUsed].value;   // Add the item's value to the backpack's total value
        bagToAdd->slotsUsed++;                                           // Increment the slots used by 1
    }
}

// Function to compare the value/weight ratio between two Items
int compareItems(const void *a, const void *b)
{
    const Item *itemA = (const Item *)a;
    const Item *itemB = (const Item *)b;

    float ratioA = (float)itemA->value / itemA->weight;
    float ratioB = (float)itemB->value / itemB->weight;

    if (ratioA < ratioB)
        return 1; // put B before A
    if (ratioA > ratioB)
        return -1; // put A before B

    return 0;
}

// Function to show player inventory
void showInventory(Backpack bag1)
{
    // A function to sort the array
    qsort(
        bag1.items,     // Array
        bag1.slotsUsed, // Count, number of elements in array
        sizeof(Item),   // Size, size of each Item object
        compareItems    // Pointer to the comparison function
    );

    // Prints the info about the bag in the top bar
    printf("Item count: %d |  Coins: %d | Total weight: %d | Total value: %d | Free slots: %d\n",
           bag1.slotsUsed,
           bag1.coins,
           bag1.weight,
           bag1.value,
           MAXSLOTS - bag1.slotsUsed);

    // Prints info about each of the items inside the bag
    for (int i = 0; i < bag1.slotsUsed; i++)
    {
        printf("%d | %-20s | %-50s | weight: %3d | value: %3d \n",
               i,
               bag1.items[i].itemName,
               bag1.items[i].description,
               bag1.items[i].weight,
               bag1.items[i].value);
    }
}

void removeItemFromBag(Backpack *bag, int index)
{
    // Check that the index is valid
    if (index < 0 || index >= bag->slotsUsed)
    {
        printf("Invalid inventory slot!\n");
        return;
    }

    // Remove the item's weight and value from the totals
    bag->weight -= bag->items[index].weight;
    bag->value -= bag->items[index].value;

    // Shift all following items left by one
    for (int i = index; i < bag->slotsUsed - 1; i++)
    {
        bag->items[i] = bag->items[i + 1];
    }

    bag->slotsUsed--;
}

// initialization function, only ran once
void initialize(Backpack *bag1)
{
    bag1->items = malloc(MAXSLOTS * sizeof(Item)); // allocate memory for 10 Item objects

    addItemToBag(sword, bag1);      // Add a sword to player
    addItemToBag(shield, bag1);     // Add a shield to player
    addItemToBag(chestplate, bag1); // Add a chestplate to player
    addItemToBag(helmet, bag1);     // Add a helmet to player
    addItemToBag(apple, bag1);      // Add an apple to player
}

// handles game logic
void update(Backpack *bag1)
{
    while (gameIsOver == 0)
    {
        system("cls");
        printf("You are standing in a windy field\n");
        printf("1 - Show inventory | 2 - Visit a vendor | 3 - Go and gather flowers for coins\n");

        int x;
        scanf("%d", &x);

        if (x == 1)
        { // if player picks show inventory
            int inventoryOpen = 1;
            while (inventoryOpen == 1)
            {
                system("cls");
                showInventory(*bag1);
                printf("\n1 - to return to the windy field | 2 - Remove item from inventory\n");
                scanf("%d", &x);
                if (x == 1)
                {
                    printf("\nReturning.....");
                    Sleep(2);
                    inventoryOpen = 0;
                }
                else if (x == 2)
                {
                    printf("Pick an item based off it's number\n");
                    scanf("%d", &x);
                    removeItemFromBag(bag1, x);
                    printf("\n You successfully threw away the item");
                    Sleep(2);
                }
            }
        }

        else if (x == 2)
        { // if player picks Add item to inventory
            openStore(bag1);
        }

        // if the player picks the go collect flowers option
        else if (x == 3)
        {
            int pickingCoins = 1;
            while (pickingCoins == 1)
            {
                system("cls");
                printf("1 - return to the windy field | 2 - pick flowers for money\n");
                scanf("%d", &x);
                if (x == 1)
                {
                    pickingCoins = 0;
                }
                else if (x == 2)
                {
                    printf("Gather flowers and sell them | +1 Coins\n");
                    bag1->coins += 5;
                    Sleep(500);
                }
            }
        }
        else
        {
            printf("invalid");
        }
    }
}

int main()
{
    Backpack bag1 = {0};
    initialize(&bag1); // Initialize the bag and rest of game logic

    update(&bag1);
    // GAME OVER
    free(bag1.items);
    return 0;
}