#include<stdio.h>
void sequence(int n){

    while(n!=1){
    if(n%2==0){
        n=n/2;
    }
}
}
int shellsort(int arr[], int n){
    for (int gap = n/2; gap > 0; gap = gap/2){

        for (int i = gap; i < n; i++){
            int temp = arr[i];
            int j;

            for (j = i; j >= gap && arr[j - gap] > temp; j = j - gap)
                arr[j] = arr[j - gap];

            arr[j]=temp;

        }
    }
    return 0;
}
void array(int arr[], int n){
    for(int i =0; i<n; i++)
        printf("%d  ",arr[i]);
    printf("  \n");
}
int main(){
    int arr[] = {1,11,8,33,22,111,101,69,0};
    int n = sizeof(arr)/ sizeof(arr[0]);
    printf("array before sorting: \n");
    array(arr, n);
    shellsort(arr, n);
    printf("array after sorting: \n");
    array(arr, n);

    return 0;

}

