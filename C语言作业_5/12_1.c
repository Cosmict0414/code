#include<stdio.h>
struct sta{
    char name[20];
    int sex;//0为女性，1为男性
    union birth{
        int year;
        int month;
        int day;
    }Birth;
    union sit{
        char school[50];
        char occ[50];
        char job[50];
    }Sit;
}Sta[50];