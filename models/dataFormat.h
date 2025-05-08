//
// Created by zhuimeng on 2025/5/4.
//

#ifndef DATAFORMAT_H
#define DATAFORMAT_H

typedef struct {
    char *str;
    int len;
    int size;
}Node;

typedef struct {
    Node **data;
    int len;
    int size;
}Row;

typedef struct {
    Row **data;
    int len;
    int size;
}Col;

#endif //DATAFORMAT_H
