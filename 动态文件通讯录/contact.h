#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<errno.h>
#include<ctype.h>
#define NAME 20
#define SEX 5
#define TELE 12
#define ADDR 30
#define AGE 4
typedef struct friend
{
    char name[NAME];
    char age[AGE];
    char sex[SEX];
    char tele[TELE];
    char addr[ADDR];
    struct friend*next;
}F;
void add(F*,int*);
void dell(F**,int*);
void change(F*,int);
void del(F*,int);
void show(F*,int);
void search(F*,int);
void sys();
void freeall(F*);
void save(F*);
