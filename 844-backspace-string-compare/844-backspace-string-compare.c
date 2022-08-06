struct stack {
    int size;
    char *arr;
    int top;
};

struct stack *stack_init(int size)
{
    struct stack *s = malloc(sizeof(struct stack));
    s->arr = (char *)calloc(size, sizeof(char));
    s->top = -1;
    s->size = size;
    return s;
}

void stack_push(struct stack *s, char str)
{
    if (s->top == s->size) {
        printf("stack full\n");
        return;
    }
    s->arr[++s->top] = str;
}

char stack_pop(struct stack *s)
{
    if (s->top < 0)
        return '\0';
    return s->arr[s->top--];
}

void del_space(struct stack *s, char *str)
{
    while (*str != '\0') {
        if (*str == '#')
            stack_pop(s);
        else
            stack_push(s, *str);
        *str++;
    }
    stack_push(s, '\0');
}

bool backspaceCompare(char * s, char * t){
    struct stack *st = stack_init(201);
    struct stack *tt = stack_init(201);
    del_space(st, s);    
    del_space(tt, t);    
    int st_size = strlen(st->arr);
    int tt_size = strlen(tt->arr);
    if (st_size != tt_size)
        return false;
    for (int i = 0; i < st_size; i++) {
        //printf("(%c,%c)", st->arr[i], tt->arr[i]);
        if (st->arr[i] != tt->arr[i])
            return false;
    }
    return true;    
}