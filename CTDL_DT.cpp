#include<stdio.h>
#include<conio.h>
#include<malloc.h>
typedef struct{
	int HS;
	int SM;
}ElementType;
typedef struct Node{
	ElementType Element;
	Node* Next;
};
typedef Node* Position;
typedef Position List;
void MakeNull_List(List *Header){
	(*Header)=(Node*)malloc(sizeof(Node));
	(*Header)->Next=NULL;
	
}
int Empty_List(List L){
	return (L->Next==NULL);
}
void Insert_List(ElementType X,Position P,List *L){
	Position T;
	T=(Node*)malloc(sizeof(Node));
	T->Element=X;
	T->Next=P->Next;
	P->Next=T;
}
void Delete_List(Position P,List *L){
	Position T;
	if(P->Next!=NULL){
	
		T=P->Next;
		P->Next=T->Next;
		free(T);
	}
	else 
		printf("Thong bao loi");
}
Position First(List L){
	return L;
}
Position End(List L){
	Position P;
	P=First(L);
	while(P->Next!=NULL){
		P=P->Next;
	}
	return P;
}
void Read(List *L){
	int n,i;
	Position P;
	ElementType X;
	printf("Nhap so luong phan tu: ");scanf("%d",&n);
	for(i=1;i<=n;i++){
		printf("Nhap He so thu %d: ",i);scanf("%d",&X.HS);
		fflush(stdin);
		printf("Nhap So mu thu %d: ",i);scanf("%d",&X.SM);
		fflush(stdin);
		Insert_List(X,End(*L),L);
	}
	
}
void Print(List L){
	Position P;
	P=First(L);
	while(P!=End(L)){
		printf("%dX^%d ",P->Next->Element.HS,P->Next->Element.SM);
		P=P->Next;
	}
}
void DaoHam(List *L){
	Position P;
	P=First(*L);
	while(P!=End(*L)){
		if(P->Next->Element.SM==0){
			P->Next->Element.HS*=0;
		}
		else{
			P->Next->Element.HS*=(P->Next->Element.SM);
			P->Next->Element.SM-=1;
		}
		P=P->Next;
	}
}
void SUM(List L1,List L2,List *L){
	Position P,Q,A;
	ElementType Z;
	MakeNull_List(L);
	P=First(L1);
	Q=First(L2);
	A=End(*L);
	while((P!=End(L1))&&(Q!=End(L2))){
		if(P->Next->Element.SM==Q->Next->Element.SM){
			Z.HS=P->Next->Element.HS+Q->Next->Element.HS;
			Z.SM=Q->Next->Element.SM;
			Insert_List(Z,A,L);
			P=P->Next;
			Q=Q->Next;
			A=A->Next;
			}
		else
			if(P->Next->Element.SM>Q->Next->Element.SM){
				Insert_List(P->Next->Element,A,L);
				P=P->Next;
				A=A->Next;
				}
			else
				{
				Insert_List(Q->Next->Element,A,L);
				Q=Q->Next;
				A=A->Next;
				}
	}
	while(Q!=End(L2)){
		Insert_List(Q->Next->Element,A,L);
		Q=Q->Next;
		A=A->Next;
	}
	while(P!=End(L1)){
		Insert_List(P->Next->Element,A,L);
		P=P->Next;
		A=A->Next;
	}
}
void Multiply(List L1,List L2,List *L){
	Position P,Q,A;
	ElementType Z;
	MakeNull_List(L);
	P=First(L1);
	Q=First(L2);
	A=End(*L);
	while(P!=End(L1)){
		while(Q!=End(L2)){
			Z.HS=P->Next->Element.HS * Q->Next->Element.HS;
			Z.SM=P->Next->Element.SM + Q->Next->Element.SM;
			Insert_List(Z,A,L);
			A=A->Next;
			Q=Q->Next;
		}
		P=P->Next;
		Q=First(L2);
	}
}
int main(){
	List L,L1,L2;
	Position P;
	ElementType X;
	MakeNull_List(&L1);
	MakeNull_List(&L2);
	printf("Nhap da thuc thu 1:\n");
	Read(&L1);
	Print(L1);
	printf("\nNhap da thuc thu 2:\n");
	Read(&L2);
	Print(L2);
//	DaoHam(&L);
//	printf("\n");
//	Print(L);
	SUM(L1,L2,&L);
	printf("\nTong hai Da thuc la:");
	Print(L);
	Multiply(L1,L2,&L);
	printf("\nTich hai Da thuc la:");
	Print(L);
}
