#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TRUE 1
#define FALSE 0
#define MAX_QUEUE_SIZE 100
#define MAX_SIMULATION_TIME 100
#define MAX_SERVICE_TIME 5
#define ARRIVAL_PROB 0.6
#define DEPARTURE_PROB 0.8
typedef int element;

typedef struct _customer {
	int id;
	int arrival_time;
	int waiting_time_interval;
	int departure_time;

}customer;

typedef struct _queue {
	customer queue[MAX_QUEUE_SIZE];
	int front, rear;

}Queue;
Queue waiting_queue;

void init_queue(Queue* q) {
	q->front = q->rear = 0;
}

int is_empty(Queue* q) {
	return (q->front == q->rear);
}

int is_full(Queue* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void enqueue(Queue* q, customer item) {
	if (is_full(q)) {
		printf("Queue is Full.");
		exit(1);
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
}

customer dequeue(Queue* q) {
	if (is_empty(q)) {
		printf("Queue is Empty.");
		exit(1);
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
}

customer peek(Queue* q) {
	if (is_empty(q)) {
		printf("Queue is Empty.");
		exit(1);
	}
	return q->queue[(q->front + 1) % MAX_QUEUE_SIZE];
}

float random() {

	return rand() / (float)RAND_MAX;

}

int t = 0;
int service_completed;
int waited_time;
int arrival_id;
int response_time_interval;
int bernoulli(float p) {
	if (random()<p) {
		return TRUE;
	}
	else return FALSE;
}
void customer_arrived(int time) {
	customer customer;
	customer.id = arrival_id++;
	customer.arrival_time = time;
	customer.departure_time = t;
	enqueue(&waiting_queue, customer);
	customer.waiting_time_interval = t-time;
	response_time_interval += (customer.departure_time - customer.arrival_time);
}

void customer_depart(int worker) {
	customer customer;
	int service_time = 0;
	if (is_empty(&waiting_queue)) return 0;
	customer = dequeue(&waiting_queue);
	service_time = customer.departure_time - 1;
	service_completed++;
	waited_time += MAX_SERVICE_TIME - customer.arrival_time;
}

void main() {
	int in_service = 0;
	init_queue(&waiting_queue);

	for (t = 0; t < MAX_SIMULATION_TIME; t++) {
		if (bernoulli(ARRIVAL_PROB)) {
			customer_arrived(t);
			
		}
		if (in_service && bernoulli(DEPARTURE_PROB)) {
			in_service = 0;
			customer_depart(1);
		}

		if (is_empty(&waiting_queue)) {
			in_service = 1;
			customer_depart(1);
		}
		

	}
	printf("The average waiting time_interval for customers : %f\n",(double)waited_time/service_completed);
	printf("The average response_time_interval for customers : %f\n",(double)response_time_interval/service_completed);
	
}