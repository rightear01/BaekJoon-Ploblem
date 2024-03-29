#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int treesNum, wannaHeight, optCutHeight;
long long temp = 0;

int compare(const void* first, const void* second) {
    int x = *(int*)first;
    int y = *(int*)second;
    if (x > y) return 1;
    else return 0;
}

int calcurateOpt(int* treesArr, int begin, int end) {
    if (begin > end) { return; } // 연산을 중단하는 중단점.(최적값 발견)
    int middle = (begin + end) / 2;
    // 배열의 전체의 중앙값으로 설정
    temp = 0;
    for (int i = 0; i < treesNum; i++) {
        if (treesArr[i] > middle) { temp += treesArr[i] - middle; }
        // 전체 배열에서 중앙값보다 큰 값들을 계산하여 middle이 최적의 높이인지 계산.
    }

    if (temp >= wannaHeight) {
        // temp값이 wannaHeight보다 크거나 같다는 의미는 middle이 최적의 절단기 높이라는 뜻.
        optCutHeight = middle;
        return calcurateOpt(treesArr, middle + 1, end);
        // 더 나은 값을 찾아본다.(범위 조정)
    }
    else { return calcurateOpt(treesArr, begin, middle - 1); }
    // 또한 더 나은 최적값을 찾기 위함.(재귀)
}

int main() {
    scanf("%d %d", &treesNum, &wannaHeight);
    int* treeArr = (int*)malloc(sizeof(int) * treesNum);
    for (int i = 0; i < treesNum; i++) { scanf("%d", &treeArr[i]); }
    qsort(treeArr, treesNum, sizeof(int), compare);
    calcurateOpt(treeArr, 0, treeArr[treesNum - 1]);
    // 탐색을 시작하는 값은 양수의 값만 가지는 조건을 이용하여, 0 ~ 해당 배열의 최댓값으로 설정
    printf("%d", optCutHeight);
    free(treeArr);
}