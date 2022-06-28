// https://velog.io/@soopsaram/Leetcode-155.-Min-Stack

struct elem {
    int val;
    int min;
};

typedef struct {
    struct elem *arr;
    int top;
    int size;
} MinStack;

MinStack* minStackCreate() {
    MinStack *s = malloc(sizeof(MinStack));
    s->size = 30001;
    s->arr = (struct elem *)calloc(s->size, sizeof(struct elem));
    s->top = -1;
    return s;
}
#define min(a,b) (((a) < (b)) ? (a): (b))
void minStackPush(MinStack* obj, int val) {
    if (obj->top == obj->size) {
        fprintf(stderr, "stack is full\n");
        return;
    }
    obj->top++;
    int top = obj->top;
    obj->arr[top].val = val;
    if (top == 0) {
        obj->arr[top].min = val;
    } else {
        obj->arr[top].min = min(val, obj->arr[top-1].min);
    }
}

void minStackPop(MinStack* obj) {
    if (obj->top == -1) {
        fprintf(stderr, "stack is empty\n");
        return;
    }
    obj->top--;
}

int minStackTop(MinStack* obj) {
    return obj->arr[obj->top].val;
}

int minStackGetMin(MinStack* obj) {
    return obj->arr[obj->top].min;
}

void minStackFree(MinStack* obj) {
    free(obj->arr);
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);

 * minStackPop(obj);

 * int param_3 = minStackTop(obj);

 * int param_4 = minStackGetMin(obj);

 * minStackFree(obj);
*/
