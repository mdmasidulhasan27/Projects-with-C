#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node{
    char name[100];
    char id[100];
}studentData[];

int main()
{
    FILE *file;
    char ch[3][100];
    int rp=0;
    file = fopen("textFile.txt","w+");

    if(file==NULL)
        printf("Not file\n");
    else
    {
        while(!feof(file)){
            fgets(studentData[rp].name,99,file);
            fgets(studentData[rp].id,99,file);
            rp++;
        }
        puts(studentData[0].name);
        puts(studentData[0].id);
        puts(studentData[1].name);
        puts(studentData[1].id);
        puts(studentData[2].name);
        puts(studentData[2].id);
        fclose(file);
    }
    return 0;
}
