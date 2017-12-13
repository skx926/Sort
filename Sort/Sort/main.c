//
//  main.c
//  Sorting
//
//  Created by KK on 2017/12/13.
//  Copyright © 2017年 Kyle Sun. All rights reserved.
//

#include <stdio.h>

static const int count = 11;

void swap(int *nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

// 冒泡排序
void bubbleSort(int *nums, int count) {
    for (int i = 0; i < count; i++) {
        for (int j = count - 1; j > i; j--) {
            if (nums[j] < nums[j - 1]) {
                swap(nums, j, j - 1);
            }
        }
    }
}

// 选择排序
void selectionSort(int *nums, int count) {
    for (int i = 0; i < count; i++) {
        int min = i;
        for (int j = i + 1; j < count; j++) {
            if (nums[j] < nums[min]) {
                min = j;
            }
        }
        if (min != i) {
            swap(nums, i, min);
        }
    }
}

// 插入排序
void insertionSort(int *nums, int count) {
    for (int i = 0; i < count; i++) {
        int min = i;
        for (int j = i + 1; j < count; j++) {
            if (nums[j] < nums[min]) {
                min = j;
            }
        }
        if (min != i) {
            int temp = nums[min];
            for (int j = min; j > i; j--) {
                nums[j] = nums[j-1];
            }
            nums[i] = temp;
        }
    }
}

// 快速排序
void partition(int *nums, int left, int right) {
    if (left >= right) {
        return;
    }
    int low = left, high = right;
    int pivot = nums[low];
    while (low < high) {
        while (low < high && nums[high] >= pivot) {
            high--;
        }
        if (low < high) {
            nums[low++] = nums[high];
        }
        while (low < high && nums[low] <= pivot) {
            low++;
        }
        if (low < high) {
            nums[high--] = nums[low];
        }
    }
    nums[low] = pivot;
    partition(nums, left, low - 1);
    partition(nums, high + 1, right);
}

void quickSort(int *nums, int count) {
    partition(nums, 0, count - 1);
}

// 堆排序
void maxHeapify(int *nums, int start, int end) {
    int left = start * 2 + 1;
    if (left < end && nums[left] > nums[start]) {
        swap(nums, left, start);
        maxHeapify(nums, left, end);
    }
    int right = left + 1;
    if (right < end && nums[right] > nums[start]) {
        swap(nums, right, start);
        maxHeapify(nums, right, end);
    }
}

void heapSort(int *nums, int count) {
    // 构建初始堆，从最后一个父节点开始
    for (int i = count / 2 - 1; i >= 0; i--) {
        maxHeapify(nums, i, count - 1);
    }
    // 把最大值放到堆尾部
    for (int i = count - 1; i > 0; i--) {
        swap(nums, i, 0);
        maxHeapify(nums, 0, i - 1);
    }
}

int main(int argc, const char * argv[]) {
    int nums[count] = {2, 1, 3, 6, 4, 4, 1, 0, 5, 8, 7};
    
    //    bubbleSort(nums, count);
    //    selectionSort(nums, count);
    //    insertionSort(nums, count);
    //    quickSort(nums, count);
    heapSort(nums, count);
    
    for (int i = 0; i < count; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    
    return 0;
}




