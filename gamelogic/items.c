#include "items.h"

Item sword = {
    "Iron Sword",
    "Basic Starter Weapon",
    10,
    60};

Item shield = {
    "Basic Shield",
    "Basic Starter Shield",
    15,
    50};

Item helmet = {
    "Steel Helmet",
    "A beautiful steel helmet",
    20,
    100};

Item chestplate = {
    "Steel Chestplate",
    "A fine steel chestplate",
    55,
    120};

Item apple = {
    "Apple",
    "A juicy fruit",
    5,
    4};

Item bonelesschicken = {
    "Boneless Chicken",
    "A succulent meal for a real black man",
    2,
    30
};
Item koolaid = {
    "Packet of koolaid",
    "A packet of a sweet powder, meant to be mixed with water",
    1,
    7
};

Item *storeOffer[] = {
    &sword,
    &shield,
    &apple,
    &bonelesschicken,
    &koolaid
};