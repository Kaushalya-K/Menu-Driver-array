#include <stdio.h>
#include <stdlib.h>

struct array
{
    int *a;
    int size,len;
};
void displaythearray(struct array arr1)
{
    int i;
    for(i=0;i<arr1.len;i++)
    {
        printf("%d ",arr1.a[i]);
    }
    printf("\n");
}
void append(struct array *arr1,int x)
{
    if(arr1->len < arr1->size)
    {
        arr1->a[arr1->len++]=x;
    }
}
void insert(struct array *arr1,int index,int x)
{
    if(index>=0 && index<=arr1->len)
    {
        for(int i=arr1->len;i>index;i--)
        {
            arr1->a[i]=arr1->a[i-1];
        }
        arr1->a[index]=x;
        arr1->len++;
    }
}
void deletee(struct array *arr1,int index)
{
    int x=0;
    if(index>=0 && index<arr1->len)
    {
        x=arr1->a[index];
        for(int i=index;i<arr1->len-1;i++)
        {
            arr1->a[i]=arr1->a[i+1];
        }
        arr1->len--;
        return x;
    }
}
int linear(struct array arr1,int key)
{
    for(int i=0;i<arr1.len;i++)
    {
        if(key==arr1.a[i])
        {
            return i;
        }

    }
    return -1;
}
void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
int imp2linear(struct array *arr1,int key)
{
    for(int i=0;i<arr1->len;i++)
    {
        if(key==arr1->a[i])
        {
            swap(&arr1->a[i],&arr1->a[0]);
            return i;
        }
    }
}
int imp1linear(struct array *arr1,int key)
{
    for(int i=0;i<arr1->len;i++)
    {
        if(key==arr1->a[i])
        {
            swap(&arr1->a[i],&arr1->a[i-1]);
            return i-1;
        }
    }
}
int binary(struct array arr1,int key)
{
    int l,mid,h;
    l=0;
    h=arr1.len-1;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(key==arr1.a[mid])
        {
            return mid;
        }
        else if(key<arr1.a[mid])
        {
            h=mid-1;
        }
        else
        {
             l=mid+1;
        }
    }
    return -1;
}
int binsearch(int a[],int l,int h,int key)
{
    int mid;
    if(l<=h){
    mid=(l+h)/2;
    if(key==a[mid])
    {
        return mid;
    }
    else if(key<a[mid])
    {
        return binsearch(a,l,mid-1,key);
    }
    else{
        return binsearch(a,mid+1,h,key);
    }
    }
    return -1;
}
int get(struct array arr1,int index)
{
    if(index>=0 && index<arr1.len)
    {
        return arr1.a[index];

    return -1; //for invalid index
    }
}
void set(struct array *arr1,int index,int x)
{
    if(index>=0 && index<arr1->len)
    {
        arr1->a[index]=x;
    }
}
int max(struct array arr1)
{
    int max=arr1.a[0];
    for(int i=1;i<arr1.len;i++)
    {
        if(arr1.a[i]>max)
        {
            max=arr1.a[i];
        }
    }
    return max;
}
int sum(struct array arr1)
{
    int sum=0;
    for(int i=0;i<arr1.len;i++)
    {
        sum=sum+arr1.a[i];
    }
    return sum;
}

float avg(struct array arr1)
{
    return (float)sum(arr1)/arr1.len;
}
void reverse (struct array *arr1)
{
    int *b;
    b=(int *)malloc(arr1->len * sizeof(int));
    for(int i=arr1->len-1,j=0;i>=0;i--,j++)
    {
        b[j]=arr1->a[i];
    }
    for(int i=0;i<arr1->len;i++)
    {
        arr1->a[i]=b[i];
    }
}
void rev(struct array *arr1)
{
    for(int i=0,j=arr1->len-1;i<j;i++,j--)
    {
        int temp=arr1->a[i];
        arr1->a[i]=arr1->a[j];
        arr1->a[j]=temp;
    }
}
void lshift(struct array *arr1)
{
    int b;
    for(int i=0;i<arr1->len;i++)
    {
       if(i==0)
       {
           b=arr1->a[0];
       }
        arr1->a[i]=arr1->a[i+1];
    }
   arr1->a[arr1->len-1]=b;
}
void rshift(struct array *arr1)
{
    int b;
    for(int i=arr1->len-1;i>=0;i--)
    {
      if(i==arr1->len-1)
       {
           b=arr1->a[arr1->len-1];
       }
      arr1->a[i+1]=arr1->a[i];
    }
   arr1->a[0]=b;
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
   struct array arr1;
   struct array arr2;
   struct array *arr3;
   arr1.len=0,arr2.len=0;
   int ch;

   printf("Enter the size of array 1");
   scanf("%d",&arr1.size);
   arr1.a=(int*)malloc(arr1.size * (sizeof(int)));

   int n,x,index;
   printf("enter the len of array 1 ");
   scanf("%d",&n);
   printf("enter n elements for array 1\n");
   for(int i=0;i<n;i++)
   {
       scanf("%d",&(arr1.a[i]));
   }
   arr1.len=n;
   displaythearray(arr1);

   do{
   printf("Menu\n");
   printf("1. append\n");
   printf("2. insert\n");
   printf("3. delete\n");
   printf("4. linear search\n");
   printf("5. binary search\n");
   printf("6. get\n");
   printf("7. set\n");
   printf("8. max\n");
   printf("9. reverse\n");
   printf("10. left shift\n");
   printf("11. right shift\n");
   printf("12. merge\n");
   printf("13. union\n");
   printf("14. intersection\n");
   printf("15. difference\n");
   printf("16. display\n");
   printf("17. exit\n");

   printf("enter ur choice\n");
   scanf("%d",&ch);

   switch(ch)
   {
       case 1: printf("enter an element to append ");
               scanf("%d",&x);
               append(&arr1,x);
               break;
       case 2: printf("enter the index num and the element ");
               scanf("%d %d",&index,&x);
               insert(&arr1,index,x);
               break;
       case 3: printf("enter the index to delete ");
               scanf("%d",&index);
               deletee(&arr1,index);
               break;
       case 4: printf("enter the key to search ");
               scanf("%d",&x);
               printf("%d\n",imp2linear(&arr1,x));
               break;
       case 5: printf("enter the key to search ");
               scanf("%d",&x);
               printf("%d\n",binary(arr1,x));
               break;
       case 6: printf("enter the index of the no to be got ");
               scanf("%d",&index);
               printf("%d\n",get(arr1,index));
               break;
       case 7: printf("enter the index and the element to replace ");
               scanf("%d %d",&index,&x);
               set(&arr1,index,x);
               break;
       case 8: printf("max operation ");
               printf("%d\n",max(arr1));
               break;
       case 9: printf("reverse operation ");
               rev(&arr1);
               break;
       case 10: printf("left shift ");
                lshift(&arr1);
                break;
       case 11: printf("right shift ");
                rshift(&arr1);
                break;
       case 12: printf("merge operation ");
                printf("enter the size of array 2\n");
                scanf("%d",&(arr2.size));
                arr2.a=(int*)malloc((arr2.size)*sizeof(int));

                printf("enter the elements in the array 2");
                for(int i=0;i<n;i++)
                {
                   scanf("%d",&(arr2.a[i]));
                }
                arr2.len=n;
                arr3=merge(&arr1,&arr2);
                displaythearray(*arr3);
                break;
       case 13: printf("union operation ");
                printf("enter the size of array 2\n");
                scanf("%d",&(arr2.size));
                arr2.a=(int*)malloc((arr2.size)*sizeof(int));

                printf("enter the elements in the array 2");
                for(int i=0;i<n;i++)
                {
                    scanf("%d",&(arr2.a[i]));
                }

                arr2.len=n;
                unionn(&arr1,&arr2);
                displaythearray(*arr3);
                break;
      case 14:  printf("intersection ");
                printf("enter the size of array 2\n");
                scanf("%d",&(arr2.size));
                arr2.a=(int*)malloc((arr2.size)*sizeof(int));

                printf("enter the elements in the array 2");
                for(int i=0;i<n;i++)
                {
                    scanf("%d",&(arr2.a[i]));
                }

                arr2.len=n;
                intersection(&arr1,&arr2);
                displaythearray(*arr3);
                break;
     case 15 : printf("difference ");
               printf("enter the size of array 2\n");
                scanf("%d",&(arr2.size));
                arr2.a=(int*)malloc((arr2.size)*sizeof(int));

                printf("enter the elements in the array 2");
                for(int i=0;i<n;i++)
                {
                    scanf("%d",&(arr2.a[i]));
                }

                arr2.len=n;
                difference(&arr1,&arr2);
                displaythearray(*arr3);
                break;
     case 16: displaythearray(arr1);

}

}while(ch<15);

}
