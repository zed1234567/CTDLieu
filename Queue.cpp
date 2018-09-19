#include<stdio.h>
#define Maxlength 20
typedef int ElementType;
typedef struct{
	ElementType Elements[Maxlength];
	int Front,Rear;
}Queue;
Queue Q;
void MakeNull_Queue(Queue *Q){
	Q->Front=-1;
	Q->Rear=-1;
}
int Empty_Queue(Queue Q){
	return (Q.Rear==-1);
}
int Full_Queue(Queue Q){
	return ((Q.Rear-Q.Front+1)==Maxlength);
}
int Full_Queue_O(Queue Q){
	return ((Q.Rear-Q.Front+1)% Maxlength ==0);
}
int FRONT(Queue Q){
	if(Empty_Queue(Q))
		printf("Danh sach rong!");
	else
		return Q.Elements[Q.Front];
}
void DeQueue( Queue *Q){
	if(!Empty_Queue(*Q)){
		Q->Front=Q->Front+1;
		if(Q->Front>Q->Rear){
			MakeNull_Queue(Q);
		}
	}
	else
		printf("Thong bao loi!");
}
void DeQueue_O(Queue *Q){
	if(!Full_Queue_O(*Q)){
		if(Q->Front==Q->Rear) 
			MakeNull_Queue(Q);
		else
			Q->Front=(Q->Front+1) % Maxlength;
			
	}
	else
		printf("Thong Bao Loi!");
}
void EnQueue(ElementType X,Queue *Q){
	if(!Full_Queue(*Q)){
		if(Empty_Queue(*Q)) Q->Front=0;
			if(Q->Rear==Maxlength-1){
				for(int i=Q->Front;i<=Q->Rear;i++)
					Q->Elements[i-Q->Front]=Q->Elements[i];
				Q->Rear=Q->Rear-Q->Front;
				Q->Front=0;
			}
			Q->Rear=Q->Rear+1;
			Q->Elements[Q->Rear]=X;
		}
	else
		printf("thong bao loi!");
}
void EnQueue_O(ElementType X,Queue *Q){
	if(!Full_Queue_O(*Q)){
		if(Empty_Queue(*Q)) Q->Front=0;
			Q->Rear=(Q->Rear+1) % Maxlength;
			Q->Elements[Q->Rear]=X;
	}
	else
		printf("thong bao loi.");
}
void Read(Queue *Q){
	int N,i;
	ElementType X;
	MakeNull_Queue(Q);
	printf("Nhap so phan tu: ");scanf("%d",&N);
	for(i=1;i<=N;i++){
		printf("Nhap phan tu thu %d: ",i);scanf("%d",&X);
		EnQueue(X,Q);
	}
}
void Print(Queue Q){
	int i;
	ElementType X;
	for(i=Q.Front;i<=Q.Rear;i++){
		printf("%d ",Q.Elements[i]);
	}
}

int main(){
	Queue Q;
	ElementType X;
	MakeNull_Queue(&Q);
	Read(&Q);
	Print(Q);
	printf("\nNhap phan tu muon them vao: ");scanf("%d",&X);
//	EnQueue(X,&Q);
	EnQueue_O(X,&Q);
	Print(Q);
	printf("\nMang sau khi xoa phan tu dau tien.\n");
//	DeQueue(&Q);
	DeQueue_O(&Q);
	Print(Q);
	printf("\nPhan tu dau tien la: %d",FRONT(Q));
}
