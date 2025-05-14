//
// Created by meng on 25-5-13.
//

#ifndef IMPORTER_H
#define IMPORTER_H
#include <stdio.h>
#include"dataFormat.h"

FILE *openFile(char *filename);

Node *loadNode(FILE *file);

Row *loadRow(FILE *file);

Grid *loadGrid(FILE *file);

void test();

#endif //IMPORTER_H
