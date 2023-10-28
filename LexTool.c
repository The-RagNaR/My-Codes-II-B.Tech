#include<stdio.h>
#include<ctype.h>
#include<string.h>

char vars[100][100];
int vcnt;
char input[1000],c;
char token[50],tlen;
int state =0,pos=0,i=0,id;

char *getAddress(char str[])
{
    for (i=0;i<vcnt;i++)
        if (strcmp(str,vars[i])==0)
            return vars[i];
    strcpy(vars[vcnt],str);
    return vars[vcnt++];
}

int isoperator(char c)
{
    if (c=='+'|| c=='-' || c=='*' || c== '/' || c== '%' || c=='^')
        return 1;
    else
        return 0;
}

int main(void)
{
    printf("Enter the input string: ");
    scanf("%s",&input);
    do
    {
        c=input[pos];
        printf("%c",c);
        switch (state)
        {
        case 0:
            if (isspace(c))
                printf('\b');
            if (isalpha(c))
                {
                    token[0]=c;
                    tlen=1;
                    state=1;
                }
            if(isdigit(c))
                state =2;
            if (isoperator(c))
                state =3;
            if (c==';')
                printf("\t<3,3>\n");
            if (c=='=')
                printf("\t<4,4>\n");
            break;

        case 1:
            if(!isalnum(c))
            {
                token[tlen] = '\0';
                printf("\b\t<1,%p>\n",getAddress(token));
                state =0 ;
                pos--;
            }
            else
                token[tlen++] = c;
            break; 

        case 2:
            if(isdigit(c))
            {
                printf("\b\t<2,%p>\n",&input[pos]);
                state = 0;
                pos--;
            }
            break;

        case 3:
            id = input[pos-1];
            if(c=='=')
                printf("\t<%d,%d>\n",id*10,id*10);
            else
            {
                printf("\b\t<%d,%d>\n",id,id);
                pos--;
            }
            state=0;
            break;
        }

        pos++;
    } while (c!=0);
    return 0;
}