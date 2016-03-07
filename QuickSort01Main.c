#include<stdio.h>
/**
 * 文件名称：快速排序QuickSort01(不含哨兵变量)
 * 时间：2016-3-7 21:32
 * 说明：1、快速排序QuickSort概念：通过一趟排序将待排序列记录分割成对立的两部分，
 * 其中一部分记录的关键字均比另外一部分记录的关键字小，则可以对这两部分记录继续进行排序，
 * 已达到整个序列有序的目的。
 *2、时间复杂度：快速排序时间复杂度在最坏的情况下为o(n^2),平均时间复杂度为o(nlogn).
 *3、使用递归时一定要有递归结束退出条件。
 * */

void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

/**分组*/
int partition(int *a,int low,int high)
{
	int pivotkey=a[low];
	while(low<high)
	{
		while((low<high)&&(a[high]>pivotkey))
		{
			high--;
		}
		swap(&a[low],&a[high]);

		while((low<high)&&(a[low]<pivotkey))
		{
			low++;
		}
		swap(&a[low],&a[high]);
	}
	return low;
}


void quickSort(int *a,int low,int high)
{
	int mid;
	if(low<high)/*注意递归的结束条件*/
	{	
		mid=partition(a,low,high);
		quickSort(a,low,mid-1);
		quickSort(a,mid+1,high);
	}
}




void arrayTraversal(int *a,int length)
{
	int i;
	for(i=0;i<length;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}

void main()
{
	int a[7]={5,4,3,2,1,7,6};
	quickSort(a,0,6);
	arrayTraversal(a,7);

	int b[5]={5,3,4,6,2};
	quickSort(b,0,4);
	arrayTraversal(b,5);
}

