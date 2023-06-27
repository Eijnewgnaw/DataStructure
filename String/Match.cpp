#include <iostream>

//朴素模式匹配算法
int Index(char S[], char T[], int pos){
    int i = pos, j = 1;
    while (i <= S[0] && j <= T[0]){
        if (S[i] == T[j]){
            ++i;
            ++j;
        }
        else{
            i = i - j + 2;  // i退回到上次匹配首位的下一位
            j = 1;
        }
    }
    if (j > T[0])
        return i - T[0];    // T[0]为模式串T的长度,匹配成功
    else
        return 0;
}
// 时间复杂度：O(n*m)，空间复杂度：O(1)

// KMP模式匹配算法
void get_next(char T[], int next[]){
    int i = 1, j = 0;
    next[1] = 0;
    while (i < T[0]){
        if (j == 0 || T[i] == T[j]){
            ++i;
            ++j;
            next[i] = j;
        }
        else
            j = next[j];
    }
}

int Index_KMP(char S[], char T[], int pos){
    int i = pos, j = 1;
    int next[255];
    get_next(T, next);
    while (i <= S[0] && j <= T[0]){
        if (j == 0 || S[i] == T[j]){
            ++i;
            ++j;
        }
        else
            j = next[j];
    }
    if (j > T[0])
        return i - T[0];
    else
        return 0;
}
// 时间复杂度：O(n+m)，空间复杂度：O(m)

//kmp改进
void get_nextval(char T[], int nextval[]){
    int i = 1, j = 0;
    nextval[1] = 0;
    for(int j=2;j<=T[0];j++){
        if(T.ch[next[j]]==T.ch[j])
            nextval[j]=nextval[next[j]];
        else
            nextval[j]=next[j];
    }
}