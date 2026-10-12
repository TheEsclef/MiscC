#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "graph.h"

// Create the dummy data structures
Point A = {"A", {NULL}};
Point B = {"B", {NULL}};
Point C = {"C", {NULL}};
Point D = {"D", {NULL}};
Point E = {"E", {NULL}};
Point F = {"F", {NULL}};

void initialize()
{
    // A Is connected to B and C
    A.children[0] = &B;
    A.children[1] = &C;

    // B Is connected to D and E
    B.children[0] = &D;
    B.children[1] = &E;

    // C Is connected to F
    C.children[0] = &F;
}

// Function for a Breadth-First Search
void bfs(Point *start)
{
    // Create a Point data object for a queue
    Point *queue[100];
    int front = 0; // initialize value for front
    int rear = 0;  // initialize value for rear

    // Add the starting node to the end of the queue and advance rear
    queue[rear++] = start;

    while (front < rear)
    {
        // Create data object for checking current Point
        Point *current = queue[front++];

        // Print out the current point's name
        printf("%s ", current->name);

        // Add all existing children of the current node to the queue
        for (int i = 0; i < 10; i++)
        {
            if (current->children[i] != NULL)
            {
                queue[rear++] = current->children[i];
            }
        }
    }

    printf("\n");
}

int main()
{
    initialize();
    bfs(&A);
    return 0;
}