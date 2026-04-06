#include<stdio.h>

int a[10][10],v[10],n;
void dfs(int s,int skip){
    int i;
    v[s]=1;
    for(i=0;i<n;i++){
        if(i!=skip && a[s][i]==1 && v[i]==0)
            dfs(i,skip);
        }
}

int main(){
    int i,j,k,c,start;
    printf("Enter number of vertices: ");
    scanf("%d",&n);
    printf("Enter adjacency matrix:\n");
    for(i=0;i<n;i++) for(j=0;j<n;j++)
        scanf("%d",&a[i][j]);
    printf("Articulation points:\n");
    for(k=0;k<n;k++){
        for(i=0;i<n;i++)
            v[i]=0;
        start=-1;
        for(i=0;i<n;i++){
            if(i!=k){
                start=i;
                break;
            }
        }
        dfs(start,k);
        c=0;
        for(i=0;i<n;i++)
            if(v[i]==1)
        c++;
        if(c<n-1)
            printf("%d ",k);
    }
}
