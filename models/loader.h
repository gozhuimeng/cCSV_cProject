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

Row *createRow();

void extendRow(Row *row);

void clearRow(Row *row);

void freeRow(Row **row);

void appendRow(Row *row, Node *node);

void overwriteRow(Row *row, Node *node);

Col *createCol();

void extendCol(Col *col);

void clearCol(Col *col);

void freeCol(Col **col);

void appendCol(Col *col, Row *row);

void overwriteCol(Col *col, Row *row);

#endif //LOADER_H
