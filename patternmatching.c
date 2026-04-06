#include<stdio.h>
#include<string.h>

int main(){
    FILE *fp;
    char name[50];
    char guest[50];
    int found = 0;

    printf("Enter guest name to search: ");
    scanf("%s",name);

    fp=fopen("guestlist.txt","r");
    while(fscanf(fp,"%s",guest)!=EOF){
        if (strcmp(name,guest)==0) {
            found = 1;
            break;
        }
    }
    fclose(fp);

    if(found==1){
        printf("Guest Found\n");
    }else{
        printf("Guest Not Found\n");
    }
    return 0;
}
