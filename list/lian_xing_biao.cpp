#include<stdio.h>
#include<stdlib.h>
#define ok 1
#define error 0
typedef struct Node{
	int data;
	struct Node *next;
}Node,*Linklist;
//ͷ�巨����������i��ʾԪ�ظ��� 
int creat_list_head(Linklist &L,int n){
	Linklist p;
	L=(Linklist)malloc(sizeof(Node));
	L->next=NULL;//ͷ���
	for(int j=0;j<n;j++){
		p=(Linklist)malloc(sizeof(Node));//�����½ڵ�
		printf("input %d number of Node is ",j+1);
		scanf("%d",&p->data);
		p->next=L->next;
		L->next=p; 
	} 
	return ok;
} 
//β�巨����������
int creat_list_tail(Linklist &L,int n){
	Linklist p,r;
	L=(Linklist)malloc(sizeof(Node));
	L->next=NULL;
	r=L;
	for(int j=0;j<n;j++){
		p=(Linklist)malloc(sizeof(Node));
		printf("input %d number of Node is ",j+1);
		scanf("%d",&p->data);
		r->next=p;
		r=p;
	}
	return ok; 
} 
//����������Ԫ��
int print_list(Linklist &L,int n){
	Linklist r;
	r=L;
	for(int i=0;i<n;i++){
		r=r->next;
		printf("output %d number of list is %d\n",i+1,r->data);
	}
	return ok;
}
//ȡ��i��λ�õ�Ԫ�ز���ʾ,������Ķ�ȡ 
int getnumber_list(Linklist &L,int k){
	Linklist p;
	p=L->next;
	for(int i=1;i<k;i++)
		p=p->next;
	printf("��%d��Ԫ�ص���Ϊ��%d\n",k,p->data);
	return ok;
} 
//������Ĳ��룺�ڵ�i��λ��ǰ����
//i��ʾ�����λ�ã�e��ʾ��Ҫ�����ֵ 
int insert_list_front(Linklist &L,int i,int &n,int e){
	Linklist p,s;
	p=L;
	if(i>0&&i<=n){ 
		for(int j=1;j<i;j++){
			p=p->next;
		}
	}
	else{
		printf("error!"); 
		return error;
	}
	s=(Linklist)malloc(sizeof(Node));
	s->data=e;
	s->next=p->next;
	p->next=s;
	n++;
	return ok; 	
}
//�ڵ�i��λ�ú����һ��Ԫ��
int insert_list_behind(Linklist &L,int i,int *n,int e){
	Linklist p,s;
	p=L->next;
	if(i>0&&i<=*n){ 
		for(int j=1;j<i;j++){
			p=p->next;
		}
	}
	else{
		printf("error!"); 
		return error;
	}
	s=(Linklist)malloc(sizeof(Node));
	s->data=e;
	s->next=p->next;
	p->next=s;
	(*n)++;
	return ok; 
} 
//ɾ����i��Ԫ��
int delete_list(Linklist &L,int i,int &n,int *e){
	Linklist p,q;
	p=L;
	if(i>=1&&i<=n){
		for(int j=1;j<i;j++)
			p=p->next;
	}
	else{
		printf("error!"); 
		return error;
	}
	q=p->next;
	*e=q->data;
	p->next=q->next;
	free(q);
	n--;
	return ok;
} 
//�޸�Ԫ��
int alter_list(Linklist &L,int i,int n,int e){
	Linklist p;
	p=L->next;
	if(i>0&&i<=n)
		for(int j=1;j<i;j++)
			p=p->next;
	else{
		printf("error!");
		return error;
	}
	printf("�޸�ǰԪ�ص�ֵΪ��%d\n",p->data); 
	p->data=e;
	printf("�޸ĺ�Ԫ�ص�ֵΪ��%d\n",p->data);
	return ok;
} 
//����ɾ��
int delete_all_list(Linklist &L,int &n){
	Linklist p,q;
	p=L->next;
	for(int i=1;i<=n;i++){
		q=p->next;
		free(p);
		p=q;
	}
	L->next=NULL;
	return ok;
} 
int main(){
	Linklist p;
    int n;
    printf("the length of list is ");
    scanf("%d",&n);
    printf("---------------------------------1.ͷ�巨������---------------------------------\n");
    printf("---------------------------------2.β�巨������---------------------------------\n");
    int m;
    printf("ѡ��Ϊ��");
    scanf("%d",&m);
    switch(m){
    	case 1:creat_list_head(p,n);break;
    	case 2:creat_list_tail(p,n);break;
	}
    printf("---------------------------------1.��ӡ������-----------------------------------\n");
    printf("---------------------------------2.ȡ��-----------------------------------------\n");
    printf("---------------------------------3.λ��ǰ����Ԫ��-------------------------------\n");
    printf("---------------------------------4.λ�ú����Ԫ��-------------------------------\n");
    printf("---------------------------------5.ɾ��Ԫ��-------------------------------------\n");
    printf("---------------------------------6.�޸�Ԫ��-------------------------------------\n");
    printf("---------------------------------7.����ɾ��-------------------------------------\n");
    printf("---------------------------------8.����������-----------------------------------\n");
	while(1){
		int count;
	    printf("ѡ����Ϊ��");
    	scanf("%d",&count);
		switch(count){
			case 1:{
				print_list(p,n);
				printf("\n");
				break;
			}
			case 2:{
				int i;
				printf("ȡ����λ��Ϊ��");
				scanf("%d",&i);
				getnumber_list(p,i);;
				print_list(p,n);
				printf("\n");
				break;
			}
			case 3:{
				int a,b;
				printf("�����λ��Ϊ��");
				scanf("%d",&a);
				printf("�����Ԫ��Ϊ��");
				scanf("%d",&b);
				insert_list_front(p,a,n,b); 
				print_list(p,n);
				printf("\n");
				break;
			}
			case 4:{
				int a,b;
				printf("�����λ��Ϊ��");
				scanf("%d",&a);
				printf("�����Ԫ��Ϊ��");
				scanf("%d",&b);
				insert_list_behind(p,a,&n,b);
				print_list(p,n);
				printf("\n");
				break;
			} 
			case 5:{
				int a,b;
				printf("ɾ����λ��Ϊ��"); 
				scanf("%d",&a);
				delete_list(p,a,n,&b);
				printf("ɾ����Ԫ��Ϊ��%d\n",b);
				print_list(p,n);
				printf("\n"); 
				break;
			}
			case 6:{
				int a,b;//a��ʾλ�ã�b��ʾ�޸�Ԫ�ص�ֵ
				printf("�޸ĵ�λ��Ϊ��");
				scanf("%d",&a);
				printf("�޸ĵ�Ԫ��Ϊ��");
				scanf("%d",&b); 
				alter_list(p,a,n,b);
				print_list(p,n);
				printf("\n"); 
				break;
			} 
			case 7:{
				delete_all_list(p,n);
				printf("\n");
				break;
			} 
			case 8:{
				printf("---------------------------------1.ͷ�巨������---------------------------------\n");
   				printf("---------------------------------2.β�巨������---------------------------------\n");
   				int m;
    			printf("ѡ��Ϊ��");
    			scanf("%d",&m);
    			switch(m){
    				case 1:creat_list_head(p,n);break;
    				case 2:creat_list_tail(p,n);break;
				}
				printf("\n");
				break;
			} 
		}
	}
	return 0;
}
