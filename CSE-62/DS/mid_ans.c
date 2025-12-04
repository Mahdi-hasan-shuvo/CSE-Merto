#include <stdio.h>
void showElement(int *arry,int n){
 for(int i=0 ; i < n; i++){
    printf("%d ",arry[i]);
 }
printf("\n");
}
void bubbleSort(int *arry,int n){
    for(int i = 0 ; i< n-1; i++){
        for( int j= 0 ; j< n -1 - i ;j++){
            if( arry[j]> arry[j+1]){
                int temp = arry[j];;
                arry[j] = arry[j+1];
                arry[j+1] =  temp;
            }
        }
    }

}
void InsertionShrot(int *arry, int n){
 for(int i = 1 ; i < n;i++ ){
    int key = arry[i];
    int j = i - 1;

    while (j >= 0 && arry[j] > key){
            arry[j+1] = arry[j];
        j--;
    }
    arry[j+1]=key;
 }

}

int binarySerch(int arry[],int n,int keys){
    int left = 0 , right = n-1;
    while(left<= right){
        int mid =( left+right)/2;
        if (arry[mid]== keys)
            return mid;
        else if (arry[mid]< keys)
            left = mid+1;
        else
            right = mid -1;
    }
    return -1;

}
int linireSerch(int *arry,int n ,int keys){
    for(int i = 0;i < n;i++){
            if (arry[i]== keys){
                return i;
            }
        //printf("%d\n",arry[i]);
    }
    return -1;
}
int main(){
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int arry[n];
    for (int i =0 ; i < n;i++){
        scanf("%d",&arry[i]);
    }
    printf("The arry is : ");
    showElement(arry,n);
    InsertionShrot(arry,n);
    printf("%d",binarySerch(arry,n,2));
    printf("%d",linireSerch(arry,n,2));
    printf("The Sroted arry is : ");
    bubbleSort(arry,n);
    showElement(arry,n);
}
