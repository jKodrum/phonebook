#include <stdlib.h>
#include <string.h>

#include "phonebook_opt.h"

int hash(char lastname[])
{
    int value = 0, cnt = 0;
    for (char *c=lastname; *c; c++)
        value += *c << cnt;
    return value % HASH_SIZE;
}

entry *findName(char lastname[], entry *pHead)
{
    int hashValue = hash(lastname);
    for (pHead=bucket[hashValue]; pHead; pHead=pHead->pNext)
        if (strcasecmp(lastname, pHead->lastName) == 0)
            return pHead;
    return NULL;
}

entry *append(char lastName[], entry *e)
{
    int hashValue = hash(lastName);
    entry *newNode = (entry *) malloc(sizeof(entry));
    strcpy(newNode->lastName, lastName);
    newNode->pNext = NULL;
    if (bucket[hashValue] == NULL)
        bucket[hashValue] = newNode;
    else
        bucket[hashValue]->pNext = newNode;
    return newNode;
}
