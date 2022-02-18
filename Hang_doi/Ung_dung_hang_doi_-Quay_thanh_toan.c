#include <stdio.h>
#include <stdlib.h>
#include "PIQueue.c"
void update(int customer, int TimeArrive, Queue *pQ){
	makenullQueue(pQ);
	int i;
	for(i=1; i<=customer; i++){
		enQueue(TimeArrive*i, pQ);
	}
}
void createTime(float a[], int cashier){
	int i;
	for(i=0; i<cashier; i++){
		a[i]=0;
	}
}
void QuayThuNgan(int customer , int cashier, int TimeCashier, int TimeArrive, int TimeWait){
	Queue QTimeArrive;
	makenullQueue(&QTimeArrive);
	float a[cashier];
	float  TimeAverage=0;
	int i=1, Total=0,u;
	int flag=0;
	while(i<=cashier && flag==0){
		createTime(a, cashier);
		update(customer,TimeArrive, &QTimeArrive);
		Total=0;
		while(!emptyQueue(QTimeArrive)){
			for(u=1; u<=i; u++){
				if(!emptyQueue(QTimeArrive)){
				
				int k=front(QTimeArrive);
				float Timeout=0;
				if(a[u-1]==0){
					Timeout=TimeCashier+a[u-1]+k;
				}
				else Timeout=TimeCashier+a[u-1];
				a[u-1]=Timeout;
				Total+=(a[u-1]-k);
				deQueue(&QTimeArrive);
				}
			}
		}
		TimeAverage=Total/customer;
		if(TimeAverage<=TimeWait)
			flag=1;
		printf("So quay: %d; Thoi gian cho trung binh: %.1f\n", i,TimeAverage);
		i++;
	}
	if(TimeAverage<=TimeWait){
		printf("=> Sieu thi se mo %d quay", i-1);
	}
	else printf("Voi %d quay hien co, khach phai cho it nhat %.1f giay moi duoc phuc vu.", cashier, TimeAverage);
}
int main(){
	int customer , cashier, TimeCashier, TimeArrive, TimeWait;
	scanf("%d%d%d%d%d", &customer, &cashier, &TimeCashier, &TimeArrive, &TimeWait);
	QuayThuNgan(customer , cashier, TimeCashier, TimeArrive, TimeWait);
	return 0;
}
