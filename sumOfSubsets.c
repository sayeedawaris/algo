#include<stdio.h>
#include<stdbool.h>
bool isSubset(int set[], int size, int sum)
{
    if (sum==0)
        return true;
    else if (size==0)
        return false;
    else if (set[size-1]>sum)
        return isSubset(set, size-1,sum);
    else    
        return isSubset(set, size-1,sum) || isSubset(set, size-1,sum-set[size-1]);
}
int main()
{
    int size, i, set[100], sum;
    printf("Size of your array: ");
    scanf("%d",&size);
    printf("Enter elements of array : ");
    for (i = 0; i < size; i++)
    {
        scanf("%d",&set[i]);
    }
    printf("Enter sum: ");
    scanf("%d",&sum);
    bool check = isSubset(set,size,sum);
    if (check==true)
        printf("Subset exists with the given sum");
    else
        printf("No subset exists with the give sum");
}
