#include<stdio.h>
#include<stdbool.h>
bool checkTPrime(int number)
{
    int flag=0,i;
    for(i=1;i<=number;i++)
    {
        if (number%i==0)
        {
            flag++;
        }
    }
    if (flag==3)
        return true;
    else
        return false;
}
int main()
{
    int size,i,arr[100];
    printf("Size of your array: ");
    scanf("%d",&size);
    printf("Enter elements of array : ");
    for (i = 0; i < size; i++)
    {
        scanf("%d",&arr[i]);
    }
    for (i = 0; i < size; i++)
    {
        bool verify=checkTPrime(arr[i]);
        if (verify==true)
            printf("%d is T-prime\n",arr[i]);
        else
            printf("%d is not T-prime \n",arr[i]);
    }
}
