


typedef struct {
    long double *arr;
    int top;
    double size;
    long double  min;
    
} MinStack;


MinStack* minStackCreate() {
    MinStack *s=(MinStack *)malloc(sizeof(MinStack));
    s->size=30000;
    s->arr=(long double *)malloc(sizeof(long double)*s->size);
    s->top=-1;
    s->min=0;
    return s;
}

void minStackPush(MinStack* obj, long double value) {
    if(obj->top==-1){
        obj->top++;
        obj->arr[obj->top]=obj->min=value;
    }
    else if(obj->min>value){
        obj->arr[++obj->top]=2*value-obj->min;
        obj->min=value;
    }
    else
    obj->arr[++obj->top]=value;
    return;
}

void minStackPop(MinStack* obj) {
    if(obj->arr[obj->top]<obj->min)
        obj->min=2*obj->min-obj->arr[obj->top];
        --obj->top;
        return;
}

int minStackTop(MinStack* obj) {
    if(obj->arr[obj->top]<obj->min)
    return obj->min;
    else
    return obj->arr[obj->top];
}

int minStackGetMin(MinStack* obj) {
    return obj->min;
}

void minStackFree(MinStack* obj) {
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, value);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/