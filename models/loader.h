//
// Created by meng on 25-5-7.
//

#ifndef LOADER_H
#define LOADER_H
#include"dataFormat.h"

Node *createNode();

void extendNode(Node *node);

void clearData(Node *node);

void freeNode(Node **node);

void loadData(Node *node, char *data);

void overwriteData(Node *node, char *data);

#endif //LOADER_H
