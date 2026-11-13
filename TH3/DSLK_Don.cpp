#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
	char Hten[30];
	int masv;
	float d1, d2, d3;
}SV;

typedef struct tagNode{
	SV infor;
	struct tagNode *link;
}Node;

typedef struct{
	Node *pHead;
	Node *pTail;
	int ssv;
}LList;

void initList(LList *L){
    	L->pHead = NULL;
    	L->pTail = NULL;
    	L->ssv = 0;
}

int emptyList(LList L){
    	return (L.ssv == 0); 
}

void insert_Head(LList *L, SV x){
    	Node *pp;
    	pp = (Node*) malloc(sizeof(Node));
    	pp->infor = x;
    	pp->link = NULL;
    	if(emptyList(*L)){
    			L->pHead = pp;
    			L->pTail = pp;
    		}  	
        else {
    		pp->link = L->pHead;
    		L->pHead = pp;
    		}
    	L->ssv++;
}

void insert_Tail(LList *L, SV x){
    	Node *pp;
    	pp = (Node*) malloc(sizeof(Node));
    	pp->infor = x;
    	pp->link = NULL;
    	if(emptyList(*L)){
    			L->pHead = pp;
    			L->pTail = pp;
    		}  	
        else {
    		L->pTail->link = pp;
    		L->pTail = pp;
    		}
    	L->ssv++;
}

Node* searchNode(LList L, int maSV) {
    Node *pp = L.pHead;
    while(pp != NULL) {
        if(pp->infor.masv == maSV)
            return pp;
        pp = pp->link;
    }
    return NULL;
}

void insert_After(LList *L, Node *q, SV x) {
    if(q == NULL) return;
    Node *pp = (Node*) malloc(sizeof(Node));
    pp->infor = x;
    pp->link = q->link;
    q->link = pp;


    if(L->pTail == q) {
        L->pTail = pp;
    }
    L->ssv++;
}

void nhap(SV *x){
    printf("Nhap ma sv: ");
    scanf("%d", &(x->masv));
    if(x->masv > 0){
        printf("Nhap ho ten sv: ");
        scanf(" %[^\n]", (x->Hten));
        printf("Nhap diem mon 1: ");
        scanf("%f", &(x->d1));
        printf("Nhap diem mon 2: ");
        scanf("%f", &(x->d2));
        printf("Nhap diem mon 3: ");
        scanf("%f", &(x->d3));
    }
}

void in(SV x){
    printf("Ten: %s, Ma: %d, Diem 1: %.2f, Diem 2: %.2f, Diem 3: %.2f\n", 
            x.Hten, x.masv, x.d1, x.d2, x.d3);
}

void processList(LList L){
    Node *pp = L.pHead;
    while( pp != NULL ){
        	in(pp->infor);
        	pp = pp->link;
    	}
}

int main(){
    LList L;
	int kt = 0;
	SV x;
	initList(&L);
	do{
	    printf("\nChuong trinh lam viec voi DSLK don SV\n");
	    printf("\n1: Them nut vao dau danh sach");
	    printf("\n2: Them nut vao cuoi danh sach");
	    printf("\n3: Them nut vao sau mot nut khac trong danh sach");
	    printf("\n4: Duyet ds");
	    printf("\n5: Thoat");
	    printf("\nMoi ban chon: ");
	    int chon;
	    scanf("%d", &chon);
	    switch(chon){
	        case 1:
		        printf("Nhap thong tin sv can them vao DAU\n");
		        nhap(&x);
		        if(x.masv > 0) 
	                insert_Head(&L, x);
            	break;
            case 2:	
	            printf("Nhap thong tin sv can them vao CUOI\n");
	            nhap(&x);
	            if(x.masv > 0) 
                	insert_Tail(&L, x);
            	break;
            case 3:
            	{
	            	if (emptyList(L)) {
	                	printf("Danh sach dang trong, khong the them vao sau!\n");
	                	break;
	                }
	                int maSV;
	                printf("Nhap Ma SV cua sinh vien ban muon them vao SAU: ");
	                scanf("%d", &maSV);
	                Node *q = searchNode(L, maSV);
	                if(q != NULL) {
	                    printf("--- Nhap thong tin sv can them ---\n");
	                    nhap(&x);
	                    if(x.masv > 0)
	                        insert_After(&L, q, x);
	                } 
					else {
	                    printf("Khong tim thay sinh vien co Ma SV: %d\n", maSV);
	                }
            	}
                break;
            case 4:
            	printf("Thong tin sv da luu: \n");
                processList(L);
                break;   
            case 5: 
                printf("Dang thoat chuong trinh...\n");
                while(L.pHead != NULL) {
                    Node *temp = L.pHead;
                    L.pHead = L.pHead->link;
                    free(temp);
                }
	            kt = 1;
	        	break;	
	        default:
	        	printf("Lua chon khong hop le\n");
        }
	}while(kt==0);
}
