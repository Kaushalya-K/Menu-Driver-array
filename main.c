#include <stdio.h>
#include <stdlib.h>

struct array
{
    int a[10];
    int size,len;
};
void displaythearray(struct array arr)
{
    int i;
    for(i=0;i<arr.len;i++)
    {
        printf("%d ",arr.a[i]);
    }
    printf("\n");
}
struct array* merge(struct array *arr1,struct array *arr2)
{
    int i=0,j=0,k=0;
    struct array *arr3=(struct array *)malloc(sizeof(struct array));
    while(i < arr1->len && j < arr2->len)
    {
        if(arr1->a[i] < arr2->a[j])
        {
            arr3->a[k++]=arr1->a[i++];
        }
        else{
            arr3->a[k++]=arr2->a[j++];
        }
    }
    for(;i<arr1->len;i++)
        arr3->a[k++]=arr1->a[i];
    for(;j<arr2->len;j++)
        arr3->a[k++]=arr2->a[j];
    arr3->len=arr1->len+arr2->len;
    arr3->size=10;
    return arr3;
}
struct array* unionn (struct array *arr1,struct array *arr2)
{
    int i=0,j=0,k=0;
    struct array *arr3=(struct array *)malloc(sizeof(struct array));
    while(i < arr1->len && j < arr2->len)
    {
        if(arr1->a[i] < arr2->a[j])
        {
            arr3->a[k++]=arr1->a[i++];
        }
        else if(arr2->a[j] < arr1->a[i])
        {
            arr3->a[k++]=arr2->a[j++];
        }
        else{
            arr3->a[k++]=arr1->a[i++];
            j++;
        }
    }
    for(;i<arr1->len;i++)
        arr3->a[k++]=arr1->a[i];
    for(;j<arr2->len;j++)
        arr3->a[k++]=arr2->a[j];

    arr3->len=k;
    arr3->size=10;
    return arr3;
}
struct array* intersection (struct array *arr1,struct array *arr2)
{
    int i=0,j=0,k=0;
    struct array *arr3=(struct array *)malloc(sizeof(struct array));
    while(i < arr1->len && j < arr2->len)
    {
        if(arr1->a[i] < arr2->a[j])
        {
             i++;
        }
        else if(arr2->a[j] < arr1->a[i])
        {
            j++;
        }
        else{
            arr3->a[k++]=arr1->a[i++];
            j++;
        }
    }
    for(;i<arr1->len;i++)
        arr3->a[k++]=arr1->a[i];

    arr3->len=k;
    arr3->size=10;
    return arr3;
}
struct array* difference (struct array *arr1,struct array *arr2)
{
    int i=0,j=0,k=0;
    struct array *arr3=(struct array *)malloc(sizeof(struct array));
    while(i < arr1->len && j < arr2->len)
    {
        if(arr1->a[i] < arr2->a[j])
        {
            arr3->a[k++]=arr1->a[i++];
        }
        else if(arr2->a[j] < arr1->a[i])
        {
            j++;
        }
        else{
            i++;
            j++;
        }
    }

    arr3->len=k;
    arr3->size=10;
    return arr3;
}
int main()
{
   struct array arr1={{5,11,28,34,48},10,5};
   struct array arr2={{11,12,48,51,72},10,5};
   struct array *arr3;
   arr3=merge(&arr1,&arr2);
   displaythearray(*arr3);
   arr3=unionn(&arr1,&arr2);
   displaythearray(*arr3);
   arr3=intersection(&arr1,&arr2);
   displaythearray(*arr3);
   arr3=difference(&arr1,&arr2);
   displaythearray(*arr3);

}
