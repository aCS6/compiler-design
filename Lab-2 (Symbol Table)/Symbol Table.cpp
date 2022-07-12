#include<bits/stdc++.h>
#include<string.h>


struct symbo{
    char token[100];
    char classs[100];
};

struct symbo s[200];
int i=0;

void inserts(){
    printf("Enter Token Name : ");
    scanf("%s",s[i].token);
    printf("Enter Class Name : ");
    scanf("%s",s[i].classs);
    i++;

}
void show(){
    printf("\t*****Symbol Table is*****\n");
    printf("SL\tToken Name\tClass Name\n");
    for(int j=0;j<i;j++){
        printf("%d\t%s\t\t%s\n",(j+1),s[j].token,s[j].classs);
    }

}
void update(){
    char temp[100];
    int m,lock=-1;
    printf("press to choose \n1.Update Token\n 2.Update Class\n");
    scanf("%d",&m);
    if(m==1){
        printf("Enter the token name : ");
        scanf("%s",temp);
        for(int j=0;j<i;j++){
            if(strcmp(s[j].token,temp)==0){
            lock=j;
                break;
            }
        }
        if(lock==-1){
            printf("Nothing to show\n");
        }
        else{
            printf("Enter Updated Token Name : ");
            scanf("%s",temp);
            strcpy(s[lock].token,temp);
            printf("Updated!!\n");
        }
    }
    else if(m==2){
        printf("Enter the Class name : ");
        scanf("%s",temp);
        for(int j=0;j<i;j++){
            if(strcmp(s[j].classs,temp)==0){
            lock=j;
                break;
            }
        }
        if(lock==-1){
            printf("Nothing to show\n");
        }
        else{
            printf("Enter Updated Class Name : ");
            scanf("%s",temp);
            strcpy(s[lock].classs,temp);
            printf("Updated!!\n");
        }
    }
    else{
        printf("Wrong Choice !\n");
    }

}

void deletes(){
    int sl;
    printf("Enter the Serial Number to delete : ");
    scanf("%d",&sl);
    if(sl>=i){
        printf("Out of Bound !\n");
    }
    else{
       for(int j=sl;j<i;j++){
            strcpy(s[j].token,s[j+1].token);
            strcpy(s[j].classs,s[j+1].classs);
        }
        i--;
        printf("Deleted!!\n");
    }

}
void searchs(){
    char temp[100];
    int sl=1,flag=0;
    printf("Enter the Token name : ");
    scanf("%s",temp);
    printf("SL\tToken Name\tClass Name\n");
    for(int j=0;j<i;j++){
        if(strcmp(temp,s[j].token)==0){
            printf("%d\t%s\t\t%s\n",sl,s[j].token,s[j].classs);
            flag=1;
        }
    }
    if(flag==0){
        printf("Token not found!\n");
    }

}

int main(){
    // system("clear"); //*nix
    // system("cls"); // windows
    printf("Enter to choose \n1.Insert\n2.Show\n3.Update\n4.delete\n5.Search\n\n");
    int choice;
    scanf("%d",&choice);
    if(choice==1){
        inserts();
    }
    else if(choice==2){
        show();
    }
    else if(choice==3){
        update();
    }
    else if(choice==4){
        deletes();
    }
    else if(choice==5){
        searchs();
    }
    else{
    printf("Wrong choice!\n");
    }
    printf("\n");
    main();
}
