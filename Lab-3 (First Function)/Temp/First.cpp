#include<bits/stdc++.h>

int total_input;

struct prod
{
    char start;
    char production[100];
    int ff_complete=0;
    char ff[100];
};
struct prod p[100];

int main()
{
    int total_production,capitalFlag=0,temp_ff_loc=0,all_ff_complete=1,paisi=-1,match=0,while_ends=0,epsilon=0;
    char productions[100],temp_ff[100],demo[100];
    printf("Enter The number of Non-Terminal : ");
    scanf("%d",&total_input);
    getchar();
    for(int i=1; i<=total_input; i++)
    {
        printf("%d no Non-Terminal : ",i);
        scanf("%c",&p[i-1].start);

        printf("Enter total production : ");
        scanf("%d",&total_production);
        getchar();

        for(int j=1; j<=total_production; j++)
        {
            printf("%c -> ",p[i-1].start);
            gets(productions);
            strcat(p[i-1].production,productions);
            if(j<total_production)
            {
                strcat(p[i-1].production,"|");
            }
            else if(j==total_production)
            {
                strcat(p[i-1].production,"\0");
            }
        }
    }
    printf("\t***** Following the List ******\n");
    for(int i=0; i<total_input; i++)
    {
        printf("%c -> ",p[i].start);
        puts(p[i].production);
    }
    printf("\t***** Following the First Function ******\n");


    int A,B,C;
    /* Generating first function from top to bottom */
    for(A=0; A<total_input; A++)
    {
        if(p[A].ff_complete==0)
        {
            temp_ff_loc=0;
            strcpy(temp_ff,"");
            strcpy(productions,p[A].production);
            B=0;
            while(1)
            {
                if(productions[B]=='\0')
                {
                    break;
                }
                else if((isalpha(productions[B])==2)||(productions[B]=='(')||(productions[B]==')')||(productions[B]=='+')||(productions[B]=='-')||(productions[B]=='/')||(productions[B]=='*')||(productions[B]=='#'))
                {
                    temp_ff[temp_ff_loc++]=productions[B];
                    while(1)
                    {
                        B++;
                        if(productions[B]=='|')
                        {
                            B++;
                            break;
                        }
                        else if(productions[B]=='\0')
                        {
                            break;
                        }
                    }
                }
                else if(isalpha(productions[B])==1)
                {
                    for(int m=0; m<total_input; m++)
                    {
                        if(p[m].start==productions[B])
                        {
                            paisi=m;
                            break;
                        }
                    }
                    if(p[paisi].ff_complete==1)
                    {
                        strcpy(demo,p[paisi].ff);
                        C=0;
                        while(1)
                        {
                            if(demo[C]=='\0')
                            {
                                break;
                            }
                            else if(demo[C]!='#')
                            {
                                temp_ff[temp_ff_loc++]=demo[C];
                            }
                            else
                            {
                                epsilon=1;
                                if(productions[B+1]=='|')
                                {
                                    B++;
                                    temp_ff[temp_ff_loc++]='#';
                                    break;
                                }
                                else if(productions[B+1]=='\0')
                                {
                                    B++;
                                    temp_ff[temp_ff_loc++]='#';
                                    break;
                                }
                                else
                                {
                                    B++;
                                    break;
                                }
                            }
                            C++;
                        }
                        if(epsilon==1)
                        {
                            epsilon=0;
                        }
                        else if(epsilon==0)
                        {
                            while(1)
                            {
                                B++;
                                if(productions[B]=='|')
                                {
                                    B++;
                                    break;
                                }
                                else if(productions[B]=='\0')
                                {
                                    break;
                                }
                            }
                        }
                    }
                    else
                    {
                        while_ends=1;
                    }

                }
                if(while_ends==1)
                {
                    while_ends=0;
                    break;
                }
            }
            if(productions[B]=='\0')
            {

                temp_ff[temp_ff_loc]='\0';
                strcpy(p[A].ff,temp_ff);
                p[A].ff_complete=1;
            }
        }
    }

    /* Generating first function from bottom to top */
    while(1)
    {
        for(A=(total_input-1); A>=0; A--)
        {
            if(p[A].ff_complete==0)
            {
                break;
            }
        }
        if(A==-1)
        {
            break;
        }
        else
        {
            temp_ff_loc=0;
            strcpy(temp_ff,"");
            strcpy(productions,p[A].production);
            B=0;
            while(1)
            {
                if(productions[B]=='\0')
                {
                    break;
                }
                else if((isalpha(productions[B])==2)||(productions[B]=='(')||(productions[B]==')')||(productions[B]=='+')||(productions[B]=='-')||(productions[B]=='/')||(productions[B]=='*')||(productions[B]=='#'))
                {
                    temp_ff[temp_ff_loc++]=productions[B];
                    while(1)
                    {
                        B++;
                        if(productions[B]=='|')
                        {
                            B++;
                            break;
                        }
                        else if(productions[B]=='\0')
                        {
                            break;
                        }
                    }
                }
                else if(isalpha(productions[B])==1)
                {
                    for(int m=0; m<total_input; m++)
                    {
                        if(p[m].start==productions[B])
                        {
                            paisi=m;
                            break;
                        }
                    }
                    if(p[paisi].ff_complete==1)
                    {
                        strcpy(demo,p[paisi].ff);
                        C=0;
                        while(1)
                        {
                            if(demo[C]=='\0')
                            {
                                break;
                            }
                            else if(demo[C]!='#')
                            {
                                temp_ff[temp_ff_loc++]=demo[C];
                            }
                            else
                            {
                                epsilon=1;
                                if(productions[B+1]=='|')
                                {
                                    B++;
                                    B++;
                                    temp_ff[temp_ff_loc++]='#';
                                    break;
                                }
                                else if(productions[B+1]=='\0')
                                {
                                    B++;
                                    temp_ff[temp_ff_loc++]='#';
                                    break;
                                }
                                else
                                {
                                    B++;
                                    break;
                                }
                            }
                            C++;
                        }
                        if(epsilon==1)
                        {
                            epsilon=0;
                        }
                        else if(epsilon==0)
                        {
                            while(1)
                            {
                                B++;
                                if(productions[B]=='|')
                                {
                                    B++;
                                    break;
                                }
                                else if(productions[B]=='\0')
                                {
                                    break;
                                }
                            }
                        }
                    }
                    else
                    {
                        while_ends=1;
                    }

                }
                if(while_ends==1)
                {
                    while_ends=0;
                    break;
                }
            }
            if(productions[B]=='\0')
            {

                temp_ff[temp_ff_loc]='\0';
                strcpy(p[A].ff,temp_ff);
                p[A].ff_complete=1;
            }
        }
    }


    temp_ff_loc=0;
    int uniques=1;
    for(int i=0; i<total_input; i++)
    {
        strcpy(productions,p[i].ff);
        for(int j=0; j<strlen(productions); j++)
        {
            for(int k=j+1; k<strlen(productions); k++)
            {
                if(productions[j]==productions[k])
                {
                    uniques=0;
                    break;
                }
            }
            if(uniques==1)
            {
                temp_ff[temp_ff_loc++]=productions[j];
            }
            else
            {
                uniques=1;
            }
        }
        temp_ff[temp_ff_loc]='\0';
        strcpy(p[i].ff,temp_ff);
        strcpy(temp_ff,"");
        temp_ff_loc=0;
        uniques=1;
    }
    for(int i=0; i<total_input; i++)
    {
        printf("First(%c) = ",p[i].start);
        strcpy(productions,p[i].ff);
        printf("{ ");
        for(int j=0; j<strlen(productions); j++)
        {
            printf("%c ",productions[j]);
            if(!(j==(strlen(productions)-1)))
            {
                printf(", ");
            }
        }
        printf("}\n");
    }
    return 0;
}
