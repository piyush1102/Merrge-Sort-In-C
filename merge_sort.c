#include<stdio.h>
void merge(int *a,int* temp,int start,int right,int end)
{
	 int i,size,left,position;
	 size=end-start+1;
	 left=right-1;
	 position=start;
	 while((start<=left) && (right<=end))
	 {
		 if(a[start]<=a[right])
		 {
			 temp[position]=a[start];
			 position+=1;
			 start+=1;
		 }
		else
		{
			temp[position]=a[right];
			position+=1;
			right+=1;
		}
		
		
	}
	while(start<=left)
		{
			 temp[position]=a[start];
			 position+=1;
			 start+=1;
		}
		while(right<=end)
		{
			temp[position]=a[right];
			position+=1;
			right+=1;
		}
		for(i=0;i<=size;i++)
		{
			a[end]=temp[end];
			end-=1;
		}
}
void mergesort(int *a,int* temp,int start,int end)
{
	int mid;
	if(end>start)
	{ 
		mid=start+(end-start)/2;
		mergesort(a,temp,start,mid);
		mergesort(a,temp,mid+1,end);
		merge(a,temp,start,mid+1,end);
	}
}

int main(){
		int n,a[100],temp[100],i;
		puts("Enter the number of element");
		scanf("%d",&n);
		puts("Enter the elements");
		for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		mergesort(a,temp,0,n-1);
		puts("Sorted elements are:");
		for(i=0;i<n;i++)
		printf("%d\t",a[i]);
		return 0;

}
