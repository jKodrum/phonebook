#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16
#define HASH_SIZE 4096

typedef struct __PHONE_BOOK_CONTENT {
    char firstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];
} content;

typedef struct __PHONE_BOOK_ENTRY {
    char lastName[MAX_LAST_NAME_SIZE];
    content *info;
    struct __PHONE_BOOK_ENTRY *pNext;
} entry;

entry *bucket[HASH_SIZE];
int hash(char lastname[]);
entry *findName(char lastname[], entry *pHead);
entry *append(char lastName[], entry *e);

#endif
