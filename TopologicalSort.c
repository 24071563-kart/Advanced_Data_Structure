#include <stdio.h>
#define MAX 20

int main(){
    int n, i, j;
    int adj[MAX][MAX];
    int indegree[MAX] = {0};
    int visited[MAX] = {0};
    int count = 0;

    printf("Enter number of courses: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(adj[i][j] == 1){
                indegree[j]++;
            }
        }
    }
    printf("Course Order:\n");

    while(count<n){
        int found=0;
        for(i=0; i<n; i++){
            if(indegree[i]==0 && visited[i]==0){
                printf("%d ", i);
                visited[i]=1;

                for(j=0; j<n; j++) {
                    if(adj[i][j]==1) {
                        indegree[j]--;
                    }
                }
                found = 1;
                count++;
            }
        }
        if(found == 0){
            printf("\nCycle detected! No valid course order.\n");
            return 0;
        }
    }
    printf("\nValid course order generated.\n");
    return 0;
}
