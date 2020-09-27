#include <iostream>
#define n 8

int nums[n] = {7,3,1,2,6,8,4,5};

void merge(int l, int m, int r){
	int i,j,k;
	int n1=m-l+1, n2=r-m;
	int L[n1], R[n2];
	for(i=0; i<n1; i++)
		L[i]=nums[l+i];
	for(j=0;j<n2;j++)
		R[j]=nums[m+1+j];
	i=j=0;
	k=l;
	while(i<n1 && j<n2){
		if(L[i] >= R[j])
			nums[k++]=L[i++]; //大的放前面
		else
			nums[k++]=R[j++];
	}
	while(i<n1)
		nums[k++]=L[i++];
	while(j<n2)
		nums[k++]=R[j++];	 
}

void sort(int l, int r){
	if(l>=r) return;
	int m=(l+r)/2;
	sort(l,m);
	sort(m+1,r);
	merge(l,m,r);
}

int main(){
	sort(0, n-1);
	for(int i=0; i<n; i++)
		std::cout << nums[i] << " ";
	return 0;
}

/*
	{7,3,1,2,6,8,4,5};
	result: 1,2,3,4,5,6,7,8 (x)
	(o): 8,7,6,5,4,3,2,1
*/