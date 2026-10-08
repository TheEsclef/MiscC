#ifndef BACKPACK_H
#define BACKPACK_H

typedef struct Item
{
    char *itemName;
    char *description;
    int weight;
    int value;
} Item;

typedef struct Backpack
{
    int slotsUsed;
    int weight;
    int value;
    int coins;
    Item *items;
} Backpack;

void addItemToBag(Item itemToAdd, Backpack *bagToAdd);
void showInventory(Backpack bag1);
void removeItemFromBag(Backpack *bag, int index);

#endif