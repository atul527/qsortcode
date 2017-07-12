#include <stdio.h>
int position(int a[],int low,int high){
    int index,i,j;
    index=a[high];
    i=low-1;
    for(j=low;j<=high-1;j++){
        if(a[j]<index){
            ++i;
            a[j]=a[j]+a[i];
            a[i]=a[j]-a[i];
            a[j]=a[j]-a[i];
        }
    }
    a[high]=a[high]+a[i+1];
    a[i+1]=a[high]-a[i+1];
    a[high]=a[high]-a[i+1];
    return (i+1);
}
int sort(int a[],int low,int high){
    int pos;
    if(low<high){
        pos=position(a,low,high);
        sort(a,low,pos-1);
        sort(a,pos+1,high);
    }
    return 0;
}
int main() {
	//code
	int t,n,i,j;
	scanf("%d",&t);
	for(i=0;i<t;i++){
	    scanf("%d",&n);
	    int a[n];
	    for(j=0;j<n;j++){
	        scanf("%d",&a[j]);
	    }
	    sort(a,0,n-1);
	    for(j=0;j<n;j++){
	        printf("%d ",a[j]);
	    }
	    printf("\n");
	}
	return 0;
}
