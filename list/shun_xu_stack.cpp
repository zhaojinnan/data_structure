//ջ���޶��ڽ��ڱ�β���в����ɾ�������Ա�
//�ֱ���Ϊ����ȳ������Ա��Ǳ��һ��������ʽ��LIFO��
#include<stdio.h>
#define error 0
#define ok 1
#define maxsize 30
//ջ�����ݽṹ 
typedef struct Sqstack{
	int data[maxsize];
	int top;
}Sqstack;
//����һ��ջ
int bulid_stack(Sqstack *p,int n){
	p->top=-1;               //ջ�ĳ�ʼ�� 
	for(int i=0;i<n;i++){
		printf("p->data[%d]=",i);
		scanf("%d",&p->data[i]);
		p->top++;
	}
	printf("p->top=%d\n",p->top);
	return ok;
}
//��ӡջ�ڵ�Ԫ��
int print_stack(Sqstack *p,int n){
	for(int i=n-1;i>-1;i--){
		printf("p->data[%d]=%d\n",i,p->data[i]);
	}
	printf("p->top=%d\n",p->top);
	printf("\n");
	return ok;
}
//����Ԫ��
int push_stack(Sqstack *p,int e){
	if(p->top==maxsize){
		printf("ջ����\n");
		return error;
	} 
	p->top++;
	p->data[p->top]=e;
	print_stack(p,p->top+1);
	return ok;
} 
//��ջ
int pop_stack(Sqstack *p){
	int e;
	if(p->top==-1){
		printf("ջ�գ�\n"); 
		return error; 
	}
	e=p->data[p->top];
	printf("��ջ��ֵΪ��e=%d",e);
	printf("\n");
	p->top--;
	print_stack(p,p->top+1);
	return ok;
} 
//����ֵ
int get_stack(Sqstack *p,int i){
	return p->data[i-1];
} 
//�޸�ֵ
int xiugai_stack(Sqstack *p,int i,int e){
	int dee;
	p->data[i-1]=e;
	print_stack(p,p->top+1);
	printf("\n");
	return ok; 
} 
int main(){
	Sqstack s;
	int k;
	printf("����k��Ԫ�ص�ջ��\n");
	printf("k=");
	scanf("%d",&k);
	bulid_stack(&s,k);
	printf("---------------------------------1.���ջԪ��----------------------------------\n");
	printf("---------------------------------2.��ջ----------------------------------------\n");
	printf("---------------------------------3.��ջ----------------------------------------\n");
	printf("---------------------------------4.����ֵ--------------------------------------\n");
	printf("---------------------------------5.�޸�----------------------------------------\n");
	while(1){
		int j;
		printf("ѡ�����Ϊ��j=");
		scanf("%d",&j);
		switch(j){
			case 1:{
				print_stack(&s,k);
				break;
			}
			case 2:{
				int kee;
				printf("��ջ��Ԫ��Ϊ��");
				scanf("%d",&kee);
				push_stack(&s,kee);
				break;
			} 
			case 3:{
				pop_stack(&s);
				break;
			}
			case 4:{
				int i;
				printf("ȡ����λ��Ϊ��");
				scanf("%d",&i);
				printf("ȡ������Ϊ��%d\n",get_stack(&s,i)); 
				printf("\n"); 
				break;
			}
			case 5:{
				int i,j;
				printf("�޸ĵ�λ��Ϊ��");
				scanf("%d",&i);
				printf("�޸ĵ���Ϊ��");
				scanf("%d",&j);
				xiugai_stack(&s,i,j); 
				break;
			}
		}
	}
	return 0;
}
