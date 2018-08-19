#include<stdio.h>
#define MaxLength 30
typedef int ElementType;
typedef int Position;
typedef struct{
	ElementType Elements[MaxLength];
	Position Last;
}List;
void MakeNull_List(List *L)
{
	L->Last=0;
}
int Empty_List(List L)
{
	return L.Last==0;
}
int Full_List(List L)
{
	return L.Last==MaxLength;
}
int EndList(List L){
	return L.Last+1;
}
int First(List L){
	return 1;
}
int Retrieve(Position P,List L){
	return L.Elements[P-1];
}
int Next(Position P,List L){
	return P+1;
}
void insert_List(ElementType X,Position P,List *L){
	if(L->Last==MaxLength)
		printf("Danh sach day!");
	else if ((P<1 ||(P>L->Last+1)))
		printf("Vi tri khong hop le!");
	else{
		Position Q;
		for(Q=(L->Last-1)+1;Q>P-1;Q--)
			L->Elements[Q]=L->Elements[Q-1];
		L->Elements[P-1]=X;
		L->Last++;
	}
	
}
void Delete_List(Position P,List *L){
	if((P<1) ||(P>L->Last))
		printf("Vi tri khong hop le!");
	else if (Empty_List(*L))
		printf("Danh sach rong!");
	else{
		Position Q;
		for(Q=P-1;Q<L->Last-1;Q++)
			L->Elements[Q]=L->Elements[Q+1];
		L->Last--;
	}
		
}int Locate(ElementType X,List L){
	Position P;
	int Found=0;
	P=First(L);
	while(P!=EndList(L) && Found==0){
		if(Retrieve(P,L)==X) Found=1;
		else P=Next(P,L);
	return P;
		
	}
	
}
void ReadList(List *L){
	int i,N;
	ElementType X;
	MakeNull_List(L);
	printf("So phan tu muon nhap N= ");
	scanf("%d",&N);
	for(i=0;i<N;i++){
		printf("Nhap phan tu thu %d= ",i+1);
		scanf("%d",&X);
		insert_List(X,EndList(*L),L);
	}
}
void PrintList(List L){
	Position P;
	P=First(L);
	while(P!=EndList(L)){
		printf("%d ",Retrieve(P,L));
		P=Next(P,L);
	}
	printf("\n");
}
int main(){
	List L;
	Position P;
	ElementType X;
	ReadList(&L);
	printf("Danh sach vua nhap: ");
	PrintList(L);
	printf("Nhap phan tu can them: ");scanf("%d",&X);
	printf("\nNhap vi tri can them: ");scanf("%d",&P);
	insert_List(X,P,&L);
	PrintList(L);
	printf("Nhap vi tri phan tu muon xoa: ");scanf("%d",&P);
	Delete_List(P,&L);
	PrintList(L);
	printf("Nhap phan tu muon tim kiem: ");scanf("%d",&P);
	printf("Phan tu la: %d",Retrieve(P,L));
}









