struct pq{
    int size;
    int *arr;
};
struct pq *q;

void swap(int *arr, int a, int b)
{
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}

void heapify_down(int *arr, int p_idx, int size)
{
    int largest = p_idx;
    int l_idx = p_idx * 2 + 1;
    int r_idx = p_idx * 2 + 2;
    
    if (l_idx < size && arr[l_idx] > arr[largest])
        largest = l_idx;
    if (r_idx < size && arr[r_idx] > arr[largest])
        largest = r_idx;
    if (largest != p_idx) {
        swap(arr, largest, p_idx);
        heapify_down(arr, largest, size);
    }
}

void heapify_up(int *arr, int cur_idx)
{
    int p_idx = (cur_idx - 1) / 2;
    if (cur_idx < 1)
        return;
    if (arr[cur_idx] > arr[p_idx]) {
        swap(arr, cur_idx, p_idx);
        heapify_up(arr, p_idx);
    }
}

void heap_push(struct pq *q, int val)
{
    q->arr[q->size] = val;
    q->size++;
    heapify_up(q->arr, q->size-1);
}

void heap_add(struct pq *q, int val, int kth)
{
    if (q->size < kth) {
        heap_push(q, val);
    } else if (val < q->arr[0]) {
        q->arr[0] = val;
        heapify_down(q->arr, 0, q->size);
    }
}

int kthSmallest(int** matrix, int matrixSize, int* matrixColSize, int k){
    int ret = 0;
    int hsize = k;
    q = (struct pq *)malloc(sizeof(struct pq));
    q->arr = (int *)malloc(hsize * sizeof(int));
    q->size = 0;
    
    for (int i = 0; i < matrixSize; i++)
        for (int j = 0; j < *matrixColSize; j++)
            heap_add(q, matrix[i][j], k); // Max Heap
    return q->arr[0];
}