#include<stdio.h>
#include<stdlib.h>

int linear_search(int *a,int n,int key)
{
	int i,count=0;
	int res;
	for(i=0;i<n;i++)
	{
		res = *(a+i) == key;
		count++;
		if(res)
		{
			break;
		}
	}
	/*if(i == n)
	{
		printf("Not present!\n");
	}
	else
	{
		printf("Element present at %d\n",i);
	}*/
	return count;
}
	
int binary_search(int *a,int n,int key)
{
	int l=0,u=n-1,m,count=0;
	int res;
	while(l<u)
	{
		m = (l + u)/2;
		res = *(a+m) == key;
		count++;
		if(res)
		{
			//printf("Element present at %d\n",m);
			return count;
		}
		else
		{
			if(key < *(a+m))
			{
				u = m - 1;
			}
			else
			{
				l = m + 1;
			}
		}
	}
	//printf("Element not present!\n");
	return count;
}

int main()
{
	int n,i,tmp;
	int *arr;
	FILE *f1,*f2,*f3,*f4,*f5,*f6;
	
	f1 = fopen("linear_bc.txt","a");
	f2 = fopen("linear_wc.txt","a");
	f3 = fopen("linear_ac.txt","a");
	f4 = fopen("binary_bc.txt","a");
	f5 = fopen("binary_wc.txt","a");
	f6 = fopen("binary_ac.txt","a");
	
	printf("Enter the size of the array:\n");
	scanf("%d",&n);
	arr = (int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		*(arr+i) = rand()%100000;
	}
	
	/*printf("Enter the search element: ");
	scanf("%d",&key);*/
	
	fprintf(f1,"%d %d\n",n,linear_search(arr,n,*(arr+0)));
	fprintf(f2,"%d %d\n",n,linear_search(arr,n,*(arr+n-1)));
	fprintf(f3,"%d %d\n",n,linear_search(arr,n,*(arr+(rand()%n))));
	
	tmp= rand()%n;
	for(i=0;i<n;i++)
	{
	  *(arr+i)=tmp;
	  tmp+=5;
	  }
	fprintf(f4,"%d %d\n",n,binary_search(arr,n,*(arr+(n-1)/2)));
	fprintf(f5,"%d %d\n",n,binary_search(arr,n,*(arr+0)));
	fprintf(f6,"%d %d\n",n,binary_search(arr,n,*(arr+(rand()%n))));
	
	fclose(f1);
	fclose(f2);
	fclose(f3);
	fclose(f4);
	fclose(f5);
	fclose(f6);
	
	
	free(arr);
	return 0;
}
	
	
