#include <stdio.h>
#include <stdlib.h>

#define TRUE 0
#define FALSE 1

typedef struct
{
    int front;
    int rear;
    
    int length;
    
    int *queue;
}Queue;

void Init(Queue *q, int length)
{
    q->front = 0;
    q->rear = 0;
    q->length = length;
    q->queue = (int*)malloc(sizeof(int)*length);
    
    for (int i = 0; i < length; i++)
        q->queue[i] = 0;
}

int IsEmpty(Queue *q)
{
    if (q->front == q->rear)
        return TRUE;
    else
        return FALSE;
}

int IsFull(Queue *q)
{
    if (q->front % q->length == (q->rear + 1) % q->length)
        return TRUE;
    else
        return FALSE;
}

void PrintQueue(Queue *q)
{
    for (int i = 0; i < q->length; i++)
    {
        printf("%d ", q->queue[i]);
    }
    printf("\n");
}

void EnQueue(Queue *q, int input)
{
    if (IsFull(q) == TRUE)
    {
        printf("overflow ");
        PrintQueue(q);
        exit(1);
    }
    else
    {
        q->rear = (q->rear + 1) % q->length;
        q->queue[q->rear] = input;
    }
}

void DeQueue(Queue *q)
{
    if (IsEmpty(q) == TRUE)
    {
        printf("underflow");
        exit(1);
    }
    else
    {
        q->front = (q->front + 1) % q->length;
        q->queue[q->front] = 0;
    }
}



int main()
{
    int length;
    int calcNum;
    char calc;
    int input;
    
    Queue q;
    
    scanf("%d", &length);
    scanf("%d", &calcNum);
    
    Init(&q, length);
    
    getchar();
    
    for (int i = 0; i < calcNum; i++)
    {
        scanf("%c", &calc);
        
        switch (calc)
        {
            case 'I':
                scanf("%d", &input);
                EnQueue(&q, input);
                break;
            case 'D':
                DeQueue(&q);
                //큐에 들어간 값 삭제;
                break;
            case 'P':
                PrintQueue(&q);
                //큐에 들어있는 모든 값 출력
                break;
        }
        
        getchar();
    }
}
