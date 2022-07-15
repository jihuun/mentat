// https://velog.io/@soopsaram/Leetcode-346.-Moving-Average-from-Data-Stream

#define DATA_SIZE 10001

typedef struct {
    int cur_size;
    int size;
    int idx;
    int total;
    int *data;
} MovingAverage;


MovingAverage* movingAverageCreate(int size) {
    MovingAverage *obj = malloc(sizeof(MovingAverage));
    obj->total = 0;
    obj->size = size;
    obj->cur_size = 0;
    obj->idx = 0;
    obj->data = (int *)calloc(DATA_SIZE, sizeof(int));
    return obj;
}

double movingAverageNext(MovingAverage* obj, int val) {
    int sum = 0;
    if (obj->cur_size < obj->size)
        obj->cur_size++;
    obj->data[obj->idx] = val;

    if (obj->idx - obj->size < 0)
        sum += obj->total + obj->data[obj->idx];
    else
        sum += obj->total - obj->data[obj->idx - obj->size] + obj->data[obj->idx];
    obj->total = sum;
    obj->idx++;

    return (double)sum / obj->cur_size;
}

void movingAverageFree(MovingAverage* obj) {
    free(obj->data);
    free(obj);
}

