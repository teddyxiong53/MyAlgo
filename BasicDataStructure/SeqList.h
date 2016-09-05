#ifndef __SEQ_LIST_H__#define __SEQ_LIST_H__#include <stdio.h>#include <string.h>#define MAXSIZE 100typedef struct {    //data begin with index 1, index 0 not use.    DATA ListData[MAXSIZE+1];    int ListLen;}SeqListType;//----------------misc function void SeqListInit(SeqListType *SL);//get lenint SeqListLength(SeqListType *SL);//-------------data function :add del modify quey . Four kind //add itemint SeqListAdd(SeqListType *SL, DATA data);//insert itemint SeqListInsert(SeqListType *SL, int n, DATA data);int SeqListDelete(SeqListType *SL, int n);DATA *SeqListFindByNum(SeqListType *SL, int n);int SeqListFindByCont(SeqListType *SL, char *key);//int SeqListAll(SeqListType *SL);#endif
