#include<bits/stdc++.h>
char arithmaitc[50],constant[50],punctuation[10],special[50],logical[50],keyword[100],variable[100],tempString[100];
int aLoc,cLoc,pLoc=0,sLoc=0,lLoc=0,kLoc=0,vLoc=0;


void punc(char ch)
{
    int flag=0;
    for(int m=0; m<strlen(punctuation); m++)
    {
        if(ch!=',')
        {
            if(punctuation[m]==ch)
            {
                flag=1;
                break;
            }
        }
    }
    if(flag==0)
    {
        punctuation[pLoc++]=ch;
    }
}
void arith( char ch)
{
    int flag=0;
    for(int m=0; m<strlen(arithmaitc); m++)
    {
        if(ch!=',')
        {
            if(arithmaitc[m]==ch)
            {
                flag=1;
                break;
            }
        }
    }
    if(flag==0)
    {
        arithmaitc[aLoc++]=ch;
    }
}
void consta( char ch)
{
    if(ch==0){
        for(int m=(strlen(constant)-1);m>=0;m--){
            printf("%c\n",constant[m]);
            if(constant[m]!=','){
                constant[m]='\0';
                --cLoc;
            }
        }
    }
    else{
       constant[cLoc++]=ch;
    }


}
void spec(char ch)
{
    special[sLoc++]=ch;
}
void logic(char ch)
{
    logical[lLoc++]=ch;
}

void keys(char str[])
{
    for(int m=0; m<strlen(str); m++)
    {
        keyword[kLoc++]=str[m];
    }
    keyword[kLoc++]=',';
}
void variab(char str[])
{
    char extra[100];
    strcpy(extra,variable);
    const char s[2] = ",";
    char *token;
    int flag=0;


    token = strtok(extra, s);
    while( token != NULL )
    {
        if(strcmp(token,str)==0)
        {
            flag=1;
            break;
        }
        token = strtok(NULL, s);
    }
    if(flag==0)
    {
        for(int m=0; m<strlen(str); m++)
        {
            variable[vLoc++]=str[m];
        }
        variable[vLoc++]=',';
    }
}

int main()
{
    char mainString[100],keyString[100],subString[100],c;
    int i=0,keyFound=0,temp,strI=0,havingKey[33]= {0},braket[4]= {0},flag;
    gets(mainString);


    for(i=0; i<strlen(mainString); i++)
    {
        c=mainString[i];
        if(c==' ')
        {

        }
        else if(c==9)
        {
            // horijontal tab
        }
        else if(c==';')
        {
            punc(c);
        }
        else if((c=='*')||(c=='/')||(c=='%'))
        {
            arith(c);
        }
        else if(isdigit(c)==1)
        {
            flag=0;

            for(temp=i;; temp++)
            {
                if(isdigit(mainString[temp])==1)
                {
                    if(flag==0)
                    {
                        consta(mainString[temp]);
                    }

                }
                else if(isalpha(mainString[temp])==1)
                {
                    flag=1;
                }
                else if(isalpha(mainString[temp])==2)
                {
                    flag=1;
                }
                else if(mainString[temp]=='_')
                {
                    flag=1;
                }
                else if(mainString[temp]=='-')
                {
                    flag=1;
                }
                else
                {
                    if(flag==0)
                    {
                        i=temp-1;
                        consta(',');
                        break;
                    }
                    else
                    {
                        i=temp-1;
                        consta(0);
                        break;
                    }
                }
            }
        }

        else if((c=='>')||(c=='<')||(c=='!'))
        {
            if(mainString[i+1]=='=')
            {
                logic(c);
                logic(mainString[i+1]);
                logic(',');
                i=i+1;
            }
            else
            {
                logic(c);
                logic(',');
            }
        }
        else if((c=='='))
        {
            if(mainString[i+1]=='=')
            {
                logic(c);
                logic(mainString[i+1]);
                logic(',');
                i=i+1;
            }
            else
            {
                arith(c);
            }
        }
        else if((c=='+'))
        {
            if(mainString[i+1]=='+')
            {
                logic(c);
                logic(mainString[i+1]);
                logic(',');
                i=i+1;
            }
            else
            {
                arith(c);
            }
        }
        else if((c=='-'))
        {
            if(mainString[i+1]=='-')
            {
                logic(c);
                logic(mainString[i+1]);
                logic(',');
                i=i+1;
            }
            else
            {
                arith(c);
            }
        }
        else if(((c=='&')&&(mainString[i+1]=='&')))
        {
            logic(c);
            logic(mainString[i+1]);
            logic(',');
        }
        else if(((c==124)&&(mainString[i+1]==124)))
        {
            logic(c);
            logic(mainString[i+1]);
            logic(',');
        }
        else if((c=='('))
        {
            if(braket[0]>=0)
            {
                ++braket[0];
            }
        }
        else if((c=='{'))
        {
            if(braket[1]>=0)
            {
                ++braket[1];
            }
        }
        else if((c=='['))
        {
            if(braket[2]>=0)
            {
                ++braket[2];
            }
        }
        else if((c==')'))
        {
            if(braket[0]>0)
            {
                --braket[0];
                spec('(');
                spec(')');
                spec(',');
            }
        }
        else if((c=='}'))
        {
            if(braket[1]>0)
            {
                --braket[1];
                spec('{');
                spec('}');
                spec(',');
            }
        }
        else if((c==']'))
        {
            if(braket[2]>0)
            {
                --braket[2];
                spec('[');
                spec(']');
                spec(',');
            }
        }
        else if((isalpha(c)==1)||(isalpha(c)==2))
        {
            int x=0;
            strcpy(tempString, "");
            for(temp=i;; temp++)
            {
                if(isalpha(mainString[temp])==1)
                {
                    tempString[x++]=mainString[temp];
                }
                else if(isalpha(mainString[temp])==2)
                {
                    tempString[x++]=mainString[temp];
                }
                else if(isdigit(mainString[temp])==1)
                {
                    tempString[x++]=mainString[temp];
                }
                else if(mainString[temp]=='_')
                {
                    tempString[x++]=mainString[temp];
                }
                else
                {
                    tempString[x++]='\0';
                    x=0;
                    i=temp-1;

                    if((strcmp(tempString,"auto")==0))
                    {
                        if(havingKey[0]==0)
                        {
                            keys(tempString);
                            havingKey[0]=1;
                        }
                    }
                    else if(strcmp(tempString,"double")==0)
                    {
                        if(havingKey[1]==0)
                        {
                            keys(tempString);
                            havingKey[1]=1;
                        }
                    }
                    else if(strcmp(tempString,"int")==0)
                    {
                        if(havingKey[2]==0)
                        {
                            keys(tempString);
                            havingKey[2]=1;
                        }
                    }
                    else if(strcmp(tempString,"struct")==0)
                    {
                        if(havingKey[3]==0)
                        {
                            keys(tempString);
                            havingKey[3]=1;
                        }
                    }
                    else if(strcmp(tempString,"const")==0)
                    {
                        if(havingKey[4]==0)
                        {
                            keys(tempString);
                            havingKey[4]=1;
                        }
                    }

                    else if(strcmp(tempString,"float")==0)
                    {
                        if(havingKey[5]==0)
                        {
                            keys(tempString);
                            havingKey[5]=1;
                        }
                    }
                    else if(strcmp(tempString,"short")==0)
                    {
                        if(havingKey[6]==0)
                        {
                            keys(tempString);
                            havingKey[6]=1;
                        }
                    }
                    else if(strcmp(tempString,"unsigned")==0)
                    {
                        if(havingKey[7]==0)
                        {
                            keys(tempString);
                            havingKey[7]=1;
                        }
                    }
                    else if(strcmp(tempString,"break")==0)
                    {
                        if(havingKey[8]==0)
                        {
                            keys(tempString);
                            havingKey[8]=1;
                        }
                    }
                    else if(strcmp(tempString,"else")==0)
                    {
                        if(havingKey[9]==0)
                        {
                            keys(tempString);
                            havingKey[9]=1;
                        }
                    }
                    else if(strcmp(tempString,"long")==0)
                    {
                        if(havingKey[10]==0)
                        {
                            keys(tempString);
                            havingKey[10]=1;
                        }
                    }
                    else if(strcmp(tempString,"switch")==0)
                    {
                        if(havingKey[11]==0)
                        {
                            keys(tempString);
                            havingKey[11]=1;
                        }
                    }
                    else if(strcmp(tempString,"continue")==0)
                    {
                        if(havingKey[12]==0)
                        {
                            keys(tempString);
                            havingKey[12]=1;
                        }
                    }
                    else if(strcmp(tempString,"for")==0)
                    {
                        if(havingKey[13]==0)
                        {
                            keys(tempString);
                            havingKey[13]=1;
                        }
                    }
                    else if(strcmp(tempString,"signed")==0)
                    {
                        if(havingKey[14]==0)
                        {
                            keys(tempString);
                            havingKey[14]=1;
                        }
                    }
                    else if(strcmp(tempString,"void")==0)
                    {
                        if(havingKey[15]==0)
                        {
                            keys(tempString);
                            havingKey[15]=1;
                        }
                    }
                    else if(strcmp(tempString,"case")==0)
                    {
                        if(havingKey[16]==0)
                        {
                            keys(tempString);
                            havingKey[16]=1;
                        }
                    }
                    else if(strcmp(tempString,"enum")==0)
                    {
                        if(havingKey[17]==0)
                        {
                            keys(tempString);
                            havingKey[17]=1;
                        }
                    }
                    else if(strcmp(tempString,"register")==0)
                    {
                        if(havingKey[18]==0)
                        {
                            keys(tempString);
                            havingKey[18]=1;
                        }
                    }
                    else if(strcmp(tempString,"typedef")==0)
                    {
                        if(havingKey[19]==0)
                        {
                            keys(tempString);
                            havingKey[19]=1;
                        }
                    }
                    else if(strcmp(tempString,"default")==0)
                    {
                        if(havingKey[20]==0)
                        {
                            keys(tempString);
                            havingKey[20]=1;
                        }
                    }
                    else if(strcmp(tempString,"goto")==0)
                    {
                        if(havingKey[21]==0)
                        {
                            keys(tempString);
                            havingKey[21]=1;
                        }
                    }
                    else if(strcmp(tempString,"sizeof")==0)
                    {
                        if(havingKey[22]==0)
                        {
                            keys(tempString);
                            havingKey[22]=1;
                        }
                    }
                    else if(strcmp(tempString,"volatile")==0)
                    {
                        if(havingKey[23]==0)
                        {
                            keys(tempString);
                            havingKey[23]=1;
                        }
                    }
                    else if(strcmp(tempString,"char")==0)
                    {
                        if(havingKey[24]==0)
                        {
                            keys(tempString);
                            havingKey[24]=1;
                        }
                    }
                    else if(strcmp(tempString,"extern")==0)
                    {
                        if(havingKey[25]==0)
                        {
                            keys(tempString);
                            havingKey[25]=1;
                        }
                    }
                    else if(strcmp(tempString,"return")==0)
                    {
                        if(havingKey[26]==0)
                        {
                            keys(tempString);
                            havingKey[26]=1;
                        }
                    }
                    else if(strcmp(tempString,"union")==0)
                    {
                        if(havingKey[27]==0)
                        {
                            keys(tempString);
                            havingKey[27]=1;
                        }
                    }
                    else if(strcmp(tempString,"do")==0)
                    {
                        if(havingKey[28]==0)
                        {
                            keys(tempString);
                            havingKey[28]=1;
                        }
                    }
                    else if(strcmp(tempString,"if")==0)
                    {
                        if(havingKey[29]==0)
                        {
                            keys(tempString);
                            havingKey[29]=1;
                        }
                    }
                    else if(strcmp(tempString,"static")==0)
                    {
                        if(havingKey[30]==0)
                        {
                            keys(tempString);
                            havingKey[30]=1;
                        }
                    }
                    else if(strcmp(tempString,"while")==0)
                    {
                        if(havingKey[31]==0)
                        {
                            keys(tempString);
                            havingKey[31]=1;
                        }
                    }
                    else
                    {
                        variab(tempString);
                    }
                    break;
                }
            }
        }
    }
    printf("\n\n");
    int commaCount=0;
    if(strlen(arithmaitc)!=0)
    {
        printf("Arithmatic Operator ( %d ): ",strlen(arithmaitc));
        for(int k=0; arithmaitc[k]!='\0'; k++)
        {
            printf("%c,",arithmaitc[k]);
        }
        printf("\n");
    }

    if(strlen(constant)!=0)
    {
        for(int k=0; constant[k]!='\0'; k++)
        {
            if(constant[k]==',')
            {
                commaCount++;
            }
        }
        printf("Constant ( %d ): ",commaCount);
        for(int k=0; constant[k]!='\0'; k++)
        {
            printf("%c",constant[k]);
        }
        printf("\n");

    }

    if(strlen(special)!=0)
    {
        commaCount=0;
        for(int k=0; special[k]!='\0'; k++)
        {
            if(special[k]==',')
            {
                commaCount++;
            }
        }
        printf("Special Operator ( %d ): ",commaCount);
        for(int k=0; special[k]!='\0'; k++)
        {
            printf("%c",special[k]);
        }
        printf("\n");

    }
    if(strlen(logical)!=0)
    {
        commaCount=0;
        for(int k=0; logical[k]!='\0'; k++)
        {
            if(logical[k]==',')
            {
                commaCount++;
            }
        }
        printf("Logical Operator ( %d ): ",commaCount);
        for(int k=0; logical[k]!='\0'; k++)
        {
            printf("%c",logical[k]);
        }
        printf("\n");
    }

    if(strlen(keyword)!=0)
    {
        commaCount=0;
        for(int k=0; keyword[k]!='\0'; k++)
        {
            if(keyword[k]==',')
            {
                commaCount++;
            }
        }
        printf("Keywords ( %d ): ",commaCount);
        for(int k=0; keyword[k]!='\0'; k++)
        {
            printf("%c",keyword[k]);
        }
        printf("\n");
    }
    if(strlen(variable)!=0)
    {
        commaCount=0;
        for(int k=0; variable[k]!='\0'; k++)
        {
            if(variable[k]==',')
            {
                commaCount++;
            }
        }
        printf("Variables ( %d ): ",commaCount);
        for(int k=0; variable[k]!='\0'; k++)
        {
            printf("%c",variable[k]);
        }
        printf("\n");
    }

    if(strlen(punctuation)!=0)
    {
        commaCount=0;
        for(int k=0; punctuation[k]!='\0'; k++)
        {
            if(punctuation[k]==',')
            {
                commaCount++;
            }
        }
        printf("Punctuation ( %d ): ",commaCount);
        for(int k=0; punctuation[k]!='\0'; k++)
        {
            printf("%c",punctuation[k]);
        }
        printf("\n");
    }
    return 0;
}
