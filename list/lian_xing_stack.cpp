//栈的链式结构
#include<stdio.h>
#include<stdlib.h>//malloc()和free()函数的头函数 
#define error 0
#define ok 1
typedef struct Nodestack{
	int data;
	struct Nodestack *next;
}Nodestack,*Nodeofstack;//结点数据结构
typedef struct Linkstack{
	int count;
	Nodeofstack top;//相当于头指针 
}Linkstack;//栈的数据结构
//建立链栈（头插法） 
int bulid_lian_stack(Linkstack *p){
	Nodeofstack s;
	int n;
	printf("建立n个元素的链表。\n");
	printf("n=");
	scanf("%d",&n);
	p->count=0;
	p->top=NULL;
	for(int i=0;i<n;i++){
		s=(Nodeofstack)malloc(sizeof(Nodestack));
		printf("第%d个元素的值为：",i+1);
		scanf("%d",&s->data);
		s->next=p->top;
		p->top=s;
		p->count++;
	}
	return ok;
} 
//打印链栈
int print_lian_stack(Linkstack *p){
	int s;
	for(s=p->count;s>0;s--){
		printf("第%d个元素的值为：%d\n",s,p->top->data);
		p->top=p->top->next;
	}
	printf("\n");
	return ok;
} 
//插入链栈
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
//删除链栈
int delete_lian_stack(Linkstack *p){
	Nodeofstack s;
	printf("删除的元素为：%d\n",p->top->data);
	s=p->top; 
	p->top=s->next;
	free(s);
	p->count--;
	print_lian_stack(p); 
	return ok; 
} 
//主函数 
int main(){
	Linkstack L;
	bulid_lian_stack(&L);
	printf("-----------------------------------1.打印链栈-----------------------------------\n");
	printf("-----------------------------------2.插入---------------------------------------\n");
	printf("-----------------------------------3.删除---------------------------------------\n");
	while(1){
		int pp;
		printf("选择序号为：");
		scanf("%d",&pp);
		switch(pp){
			case 1:{
				print_lian_stack(&L);
				break;
			}
			case 2:{
				int e;
				printf("插入的元素是：");
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
