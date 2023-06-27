#include <iostream>

// 串的定长顺序存储表示
#define MAXLEN 255
typedef struct{
    char ch[MAXLEN];
    int length;
}SString;

// 串的堆分配存储表示
typedef struct{
    char * ch;
    int length;
}HString;

// 串的块链存储表示
#define CHUNKSIZE 80
typedef struct Chunk{
    char ch[CHUNKSIZE];
    struct Chunk * next;
}Chunk;

//求子串
bool SubString(SString & Sub, SString S, int pos, int len){
    if (pos + len - 1 > S.length)
        return false;
    for (int i = pos; i < pos + len; i++)
        Sub.ch[i - pos + 1] = S.ch[i];
    Sub.length = len;
    return true;
}

//比较
int StrCompare(SString S, SString T){
    for (int i = 1; i <= S.length && i <= T.length; i++)
        if (S.ch[i] != T.ch[i])
            return S.ch[i] - T.ch[i];
    return S.length - T.length;
}

//定位
int Index(SString S, SString T){
    int i = 1, n = S.length, m = T.length;
    SString sub;
    while (i <= n - m + 1){
        SubString(sub, S, i, m);
        if (StrCompare(sub, T) != 0)
            ++i;
        else
            return i;
    }
    return 0;
}
