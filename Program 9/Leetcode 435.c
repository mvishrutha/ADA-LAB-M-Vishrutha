int compare(const void* a, const void* b) {

    int* x = *(int**)a;
    int* y = *(int**)b;

    return x[1] - y[1];
} 
 int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize) {
    if(intervalsSize == 0)
        return 0;

    qsort(intervals, intervalsSize,
          sizeof(int*), compare);

    int count = 0;

    int prevEnd = intervals[0][1];

    for(int i = 1; i < intervalsSize; i++) {

        if(intervals[i][0] < prevEnd) {
            count++;
        }
        else {
            prevEnd = intervals[i][1];
        }
    }

    return count;
}
