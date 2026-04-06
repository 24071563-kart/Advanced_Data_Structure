#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int parent[MAX];
int rankArr[MAX];

void makeSet(int n){
    for (int i = 0; i < n; i++){
        parent[i] = i;
        rankArr[i] = 0;
    }
}
int findSet(int x){
    if (parent[x] != x)
        parent[x] = findSet(parent[x]);
    return parent[x];
}
void simpleUnion(int a, int b){
    int rootA = findSet(a);
    int rootB = findSet(b);

    if (rootA != rootB) {
        parent[rootB] = rootA;
    }
}
void smartUnion(int a, int b) {
    int rootA = findSet(a);
    int rootB = findSet(b);

    if (rootA == rootB)
        return;
    if (rankArr[rootA] < rankArr[rootB]) {
        parent[rootA] = rootB;
    } else if (rankArr[rootA] > rankArr[rootB]) {
        parent[rootB] = rootA;
    } else {
        parent[rootB] = rootA;
        rankArr[rootA]++;
    }
}

int main() {
    int n, operations, choice;
    int a, b;

    printf("Enter number of elements : ");
    scanf("%d", &n);
    makeSet(n);

    printf("Enter number of union operations : ");
    scanf("%d", &operations);
    printf("Choose union method :\n");
    printf("1. Simple union\n");
    printf("2. Smart union (union by Rank)\n");
    printf("Enter choice : ");
    scanf("%d", &choice);

    for (int i = 0; i < operations; i++) {
        printf("Enter two elements to union : ");
        scanf("%d %d", &a, &b);
        if (a < 0 || a >= n || b < 0 || b >= n) {
            printf("Invalid elements! Enter values between 0 and %d\n", n - 1);
            i--;
            continue;
        }
        if (choice == 1)
            simpleUnion(a, b);
        else if (choice == 2)
            smartUnion(a, b);
        else {
            printf("Invalid choice!\n");
            return 0;
        }
    }
    printf("Set representative of each element\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d -> Root %d\n", i, findSet(i));
    }

    return 0;
}
