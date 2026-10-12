#ifndef GRAPH_H
#define GRAPH_H

typedef struct Point
{
    char name[5];
    struct Point *children[10];
}Point;

#endif