//ջ����ʽ�ṹ
#include<stdio.h>
#include<stdlib.h>//malloc()��free()������ͷ���� 
#define error 0
#define ok 1
typedef struct Nodestack{
	int data;
	struct Nodestack *next;
}Nodestack,*Nodeofstack;//������ݽṹ
typedef struct Linkstack{
	int count;
	Nodeofstack top;//�൱��ͷָ�� 
}Linkstack;//ջ�����ݽṹ
//������ջ��ͷ�巨�� 
int bulid_lian_stack(Linkstack *p){
	Nodeofstack s;
	int n;
	printf("����n��Ԫ�ص�����\n");
	printf("n=");
	scanf("%d",&n);
	p->count=0;
	p->top=NULL;
	for(int i=0;i<n;i++){
		s=(Nodeofstack)malloc(sizeof(Nodestack));
		printf("��%d��Ԫ�ص�ֵΪ��",i+1);
		scanf("%d",&s->data);
		s->next=p->top;
		p->top=s;
		p->count++;
	}
	return ok;
} 
//��ӡ��ջ
int print_lian_stack(Linkstack *p){
	int s;
	for(s=p->count;s>0;s--){
		printf("��%d��Ԫ�ص�ֵΪ��%d\n",s,p->top->data);
		p->top=p->top->next;
	}
	printf("\n");
	return ok;
} 
//������ջ
int insert_lian_stack(Linkstack *p,int e){
	Nodeofstack s;
	s=(Nodeofstack)malloc(sizeof(Nodestack));
	s->data=e;
	s->next=p->top;
	p->top=s;
	p->count++;
	print_lian_stack(p);
	return ok;
} 
//ɾ����ջ
int delete_lian_stack(Linkstack *p){
	Nodeofstack s;
	printf("ɾ����Ԫ��Ϊ��%d\n",p->top->data);
	s=p->top; 
	p->top=s->next;
	free(s);
	p->count--;
	print_lian_stack(p); 
	return ok; 
} 
//������ 
int main(){
	Linkstack L;
	bulid_lian_stack(&L);
	printf("-----------------------------------1.��ӡ��ջ-----------------------------------\n");
	printf("-----------------------------------2.����---------------------------------------\n");
	printf("-----------------------------------3.ɾ��---------------------------------------\n");
	while(1){
		int pp;
		printf("ѡ�����Ϊ��");
		scanf("%d",&pp);
		switch(pp){
			case 1:{
				print_lian_stack(&L);
				break;
			}
			case 2:{
				int e;
				printf("�����Ԫ���ǣ�");
				scanf("%d",&e);
				insert_lian_stack(&L,e);
				break;
			} 
			case 3:{
				delete_lian_stack(&L);
				break;
			}
		}
	}
	return 0;
}
