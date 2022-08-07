int heap_size;

void swap(int arr[], int a, int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
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

void build_heap(int *arr) {
    for (int i = heap_size / 2 - 1; i >= 0; i--) {
        heapify_down(arr, i, heap_size);
    }
}

// 0 1 2 3 4 5 6
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

void heap_push(int *arr, int val)
{
    arr[heap_size] = val;
    heap_size++;
    heapify_up(arr, heap_size - 1);
}

int heap_pop(int *arr)
{
    int ret = arr[0];
    heap_size--;
    arr[0] = arr[heap_size];
    heapify_down(arr, 0, heap_size);
    return ret;
}

void print_heap(int *arr)
{
    for (int i = 0; i < heap_size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int lastStoneWeight(int* stones, int stonesSize){
    int x = 0, y = 0;
    heap_size = stonesSize;
    build_heap(stones);
    while (heap_size > 1) {
        x = heap_pop(stones);
        y = heap_pop(stones);
        if (x > y)
            heap_push(stones, x - y);
        else if (x < y)
            heap_push(stones, y - x);
    }
    if (heap_size == 1)
        return stones[0];
    else
        return 0;
}