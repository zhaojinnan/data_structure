//栈是限定在仅在表尾进行插入和删除的线性表
//又被称为后进先出的线性表，是表的一种特殊形式（LIFO）
#include<stdio.h>
#define error 0
#define ok 1
#define maxsize 30
//栈的数据结构 
typedef struct Sqstack{
	int data[maxsize];
	int top;
}Sqstack;
//创建一个栈
int bulid_stack(Sqstack *p,int n){
	p->top=-1;               //栈的初始化 
	for(int i=0;i<n;i++){
		printf("p->data[%d]=",i);
		scanf("%d",&p->data[i]);
		p->top++;
	}
	printf("p->top=%d\n",p->top);
	return ok;
}
//打印栈内的元素
int print_stack(Sqstack *p,int n){
	for(int i=n-1;i>-1;i--){
		printf("p->data[%d]=%d\n",i,p->data[i]);
	}
	printf("p->top=%d\n",p->top);
	printf("\n");
	return ok;
}
//插入元素
int push_stack(Sqstack *p,int e){
	if(p->top==maxsize){
		printf("栈满！\n");
		return error;
	} 
	p->top++;
	p->data[p->top]=e;
	print_stack(p,p->top+1);
	return ok;
} 
//出栈
int pop_stack(Sqstack *p){
	int e;
	if(p->top==-1){
		printf("栈空！\n"); 
		return error; 
	}
	e=p->data[p->top];
	printf("出栈的值为：e=%d",e);
	printf("\n");
	p->top--;
	print_stack(p,p->top+1);
	return ok;
} 
//访问值
int get_stack(Sqstack *p,int i){
	return p->data[i-1];
} 
//修改值
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
	printf("建立k个元素的栈！\n");
	printf("k=");
	scanf("%d",&k);
	bulid_stack(&s,k);
	printf("---------------------------------1.输出栈元素----------------------------------\n");
	printf("---------------------------------2.进栈----------------------------------------\n");
	printf("---------------------------------3.出栈----------------------------------------\n");
	printf("---------------------------------4.访问值--------------------------------------\n");
	printf("---------------------------------5.修改----------------------------------------\n");
	while(1){
		int j;
		printf("选择序号为：j=");
		scanf("%d",&j);
		switch(j){
			case 1:{
				print_stack(&s,k);
				break;
			}
			case 2:{
				int kee;
				printf("进栈的元素为：");
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
				printf("取数的位置为：");
				scanf("%d",&i);
				printf("取出的数为：%d\n",get_stack(&s,i)); 
				printf("\n"); 
				break;
			}
			case 5:{
				int i,j;
				printf("修改的位置为：");
				scanf("%d",&i);
				printf("修改的数为：");
				scanf("%d",&j);
				xiugai_stack(&s,i,j); 
				break;
			}
		}
	}
	return 0;
}
