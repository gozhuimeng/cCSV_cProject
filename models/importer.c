//
// Created by meng on 25-5-13.
//

#include"importer.h"
#include"dataFormat.h"
#include"loader.h"
#include"reader.h"

/**
 * 打开文件
 * @param filename
 * @return 文件指针
 */
FILE *openFile(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("无法打开文件%s", filename);
        return NULL;
    }
    return file;
}

Node *loadNode(FILE *file) {
    Node *node = createNode();
    int ch = 0;
    while ((ch = fgetc(file)) != EOF && ch != '\n' && ch != ',') {
        appendChar(node, ch);
    }
    if (ch != EOF) {
        ungetc(ch, file);
    }
    node->str[node->len] = '\0';
    return node;
}

Row *loadRow(FILE *file) {
    Row *row = createRow();
    int ch = 0;
    while ((ch = fgetc(file)) != EOF && ch != '\n') {
        if (ch != ',') {
            ungetc(ch, file);
        }
        Node * node = loadNode(file);
        appendRow(row, node);
    }
    if (ch!=EOF) {
        ungetc(ch, file);
    }
    return row;
}

Grid *loadGrid(FILE *file) {
    Grid *grid = createGrid();
    int ch = 0;
    while ((ch = fgetc(file)) != EOF ) {
        if (ch != '\n') {
            ungetc(ch, file);
        }
        Row * row = loadRow(file);
        appendGrid(grid, row);
    }
    return grid;
}

void test() {
    char *filename = "..\\test\\1.csv";
    FILE * file = openFile(filename);
    Grid * grid = loadGrid(file);
    for (int i = 0; i < grid->len; i++) {
        Row * row = grid->data[i];
        for (int j = 0; j < row->len; j++) {
            Node * node = row->data[j];
            printf("%s|", node->str);
        }
        printf("\n");
    }
}

