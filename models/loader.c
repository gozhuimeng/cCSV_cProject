//
// Created by meng on 25-5-7.
//

#include"loader.h"
#include"dataFormat.h"
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

#define INIT_SIZE 100
#define EXTEND_X 1.5


/**
 * 创建节点
 * @return
 */
Node *createNode() {
    Node *node = (Node *) malloc(sizeof(Node));
    node->len = 0;
    node->size = INIT_SIZE;
    node->str = (char *) malloc(node->size * sizeof(char));
    return node;
}

/**
 * 扩展节点空间
 * @param node
 */
void extendNode(Node *node) {
    char *temp = realloc(node->str, ((int) node->size * EXTEND_X) * sizeof(char));
    if (temp == NULL) {
        printf("节点空间拓展失败\n");
        return;
    }
    node->str = temp;
    node->size = (int) node->size * EXTEND_X;
}

/**
 * 清空节点数据
 * @param node
 */
void clearData(Node *node) {
    node->len = 0;
    free(node->str);
    node->size = INIT_SIZE;
    node->str = (char *) malloc(node->size * sizeof(char));
}

/**
 * 释放节点
 * @param node
 */
void freeNode(Node **node) {
    if (*node == NULL) {
        return;
    }
    free((*node)->str);
    free(*node);
}

/**
 * 追加载入数据
 * @param node
 * @param data
 */
void loadData(Node *node, char *data) {
    int data_len = strlen(data);
    if (data_len == 0) {
        return;
    }
    while (node->len + data_len > node->size) {
        extendNode(node);
    }
    strcpy(node->str + node->len, data);
    node->len += data_len;
}

/**
 * 覆写数据
 * @param node
 * @param data
 */
void overwriteData(Node *node, char *data) {
    int data_len = strlen(data);
    if (data_len == 0) {
        clearData(node);
        return;
    }
    if (node->len > (int) node->size * EXTEND_X) {
        clearData(node);
    } else {
        node->len = 0;
    }
    loadData(node, data);
}
