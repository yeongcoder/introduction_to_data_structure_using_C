#include <stdio.h>

void SelSort(int arr[], int n){
    int i, j;
    int maxIdx;
    int temp;

    for(i=0; i<n-1; i++){
        maxIdx = i;

        for(j=i+1; j<n; j++){
            if(arr[j] < arr[maxIdx]) // arr[maxIdx]보다 작은 값이 존재하면
                maxIdx = j;         // 해당 값의 인덱스를 maxIdx로 저장 왜냐면 arr[maxIdx]값은 배열 순서상 arr[j]보다 작아야 하기 떄문
        }
        temp = arr[i];
        arr[i] = arr[maxIdx];
        arr[maxIdx] = temp;
    }
}

int main(void){
    int arr[4] = {3,4,2,1};
    int i;

    SelSort(arr, sizeof(arr)/sizeof(int));

    for(i=0; i<4; i++){
        printf("%d", arr[i]);
    }
    printf("\n");
    return 0;
}
