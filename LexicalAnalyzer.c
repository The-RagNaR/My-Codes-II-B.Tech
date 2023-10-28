#include<stdio.h>
#include<string.h>
#include<ctype.h>
void main()
{
    int flag=0,i=1;
    char a[20], c, ch[20];
    FILE *finput, *foutput, *foperator, *fkey;
    finput = fopen("input.c","r");
    foutput = fopen("inter.c","w");
    foperator = fopen("operator.c","r");
    fkey = fopen("key.c","r");
    c=getc(finput);
    while (!feof(finput))
    {
        if (isalpha(c) || isdigit(c) || (c=='[' || c==']' || c=='.'==1))
        {
            fputc(c,foutput);
        }
        else
        {
            if (c=='\n')
                fprintf(foutput,"\t$\t");
            else
                fprintf(foutput,"\t%c\t",c);
        }

    }
    fclose(finput);
    fclose(foutput);
    finput = fopen("inter.c","r");
    printf("Lexical Analyzer\n");
    fscanf(finput,a);
    printf("Line :%d",i++);
    while (!feof(finput))
    {
        if (strcmp(a,"$")==0)
        {
            printf("Line:%d",i++);
            fscanf(finput,a);
        }
        fscanf(foperator,ch);
        while (!feof(foperator))
        {
            if(strcmp(ch,a)==0)
            {
                fscanf(foperator,ch);
                printf("\t\t%s\t:\t%s\n",a,ch);
                flag=1;
            }
            fscanf(foperator,ch);
        }
        rewind(foperator);
        fscanf(fkey,ch);
        while (!feof(fkey))
        {
            if (strcmp(ch,a)==0)
            {
                printf("\t\t%c\t:\tKeyword\n");
                flag=1;
            }
            fscanf(fkey,ch);
        }
        rewind(fkey);
        if (flag==0)
        {
            if (isdigit(a))
                printf("\t\t%s\t:\tConstant",a);
            else
                printf("\t\t%s\t:\tIdentifier\n",a);
        }
        fscanf(finput,a);
    }
}