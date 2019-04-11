// A C program to print all anagarms together
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct word
{
    char* str;
    int idx;
    int length;
};

typedef struct word Word;

int charCmp(const void* a,const void* b)
{
    return *(char*)a-*(char*)b;
}

int stringCmp(const void* a,const void* b)
{
    Word* a1=(Word*)a;
    Word* b1=(Word*)b;
    return strcmp(a1->str,b1->str);
}

void printAnagramsTogether(char* arr[],int n)
{
    Word words[n];
    for(int i=0;i<n;i++)
    {
        words[i].str = (char*)malloc(sizeof(char)*(strlen(arr[i])+1));
        strcpy(words[i].str,arr[i]);
        words[i].idx = i;
        words[i].length = strlen(arr[i]);
    }

    for(int i=0;i<n;i++)
        qsort(words[i].str,strlen(words[i].str),sizeof(char),charCmp);

    qsort(words,n,sizeof(words[0]),stringCmp);

    for(int i=0;i<n;i++)
        printf("%s ",arr[words[i].idx]);
}

// Driver program to test above functions
int main()
{
	char* wordArr[] = { "cat", "dog", "tac", "god", "act" };
	int size = sizeof(wordArr) / sizeof(wordArr[0]);
	printAnagramsTogether(wordArr, size);
	return 0;
}
