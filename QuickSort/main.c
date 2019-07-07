#include <stdio.h>

int Partition(int * a,int low,int high){
    int pivot = a[low];
    while(low<high){
        while(low<high&&a[high]>=pivot)
            high--;
        a[low] = a[high];
        while(high>low&&a[low]<=pivot)
            low++;
        a[high] = a[low];
    }
    a[low] = pivot;
    return low;
}

void QuickSort(int * a, int low, int high){
    if(low<high){
        int pivotpos = Partition(a, low, high);
        QuickSort(a, low, pivotpos-1);
        QuickSort(a, pivotpos+1, high);
    }
}

void Print_array(int * a, int n){
    for(int i=0;i<n;i++)
        printf("%d,",a[i]);
    printf("\n");
}

int main() {

    int a[10] = {34,10,78,9,3,45,100,23,62,1};
    int n = 10;

    Print_array(a,n);

    QuickSort(a, 0, n-1);

    Print_array(a,n);

    return 0;
}