#include <stdio.h>
#include <stdlib.h>
#include "PIQueue.c"

void create(int cashier, int a[]){
	int i;
	for(i=0; i<cashier; i++){
		a[i]=0;
	}
}
void update(int TimeArrive,int customer, Queue *pQ){
	int i;
	for(i=1; i<=customer; i++){
		enQueue(TimeArrive*i, pQ);
	}
}
void AverageCashier(int customer,int cashier,int TimeCashier,int TimeArrive,int TimeWait){
	Queue Q;
	makenullQueue(&Q);
	int i;
	int a[cashier];
	float TimeAverage=0;
	int flag=0;
	for(i=1; i<=cashier && flag==0; i++){
		create(cashier, a);
		update(TimeArrive, customer, &Q);
		int u=1;
		int Total=0;
		while(!emptyQueue(Q)){
			if(u>i)
				u=1;
			int k=front(Q);
			int Timeout;
			if(a[u-1]==0)
				Timeout=a[u-1]+TimeCashier+k;
			else Timeout=a[u-1]+TimeCashier;
			a[u-1]=Timeout;
			Total+=(a[u-1]-k);
			u++;
			deQueue(&Q);
		}
		TimeAverage=Total/customer;
		if(TimeAverage<=TimeWait)
			flag=1;
		printf("So quay: %d; Thoi gian cho trung binh: %.1f\n", i, TimeAverage);
	}
	if(TimeAverage<=TimeWait){
		printf("=> Sieu thi se mo %d quay", i-1);
	}
	else printf("Voi %d quay hien co, khach phai cho it nhat %.1f giay moi duoc phuc vu.", i-1, TimeAverage);
}
int main(){
	int customer, cashier, TimeCashier, TimeArrive, TimeWait;
	scanf("%d%d%d%d%d", &customer, &cashier, &TimeCashier, &TimeArrive, &TimeWait);
	AverageCashier( customer, cashier, TimeCashier, TimeArrive, TimeWait);
	return 0;
}
