#include<stdio.h>
#include<stdlib.h>
#define ok 1
#define error 0
typedef struct Node{
	int data;
	struct Node *next;
}Node,*Linklist;
//头插法建立单链表，i表示元素个数 
int creat_list_head(Linklist &L,int n){
	Linklist p;
	L=(Linklist)malloc(sizeof(Node));
	L->next=NULL;//头结点
	for(int j=0;j<n;j++){
		p=(Linklist)malloc(sizeof(Node));//建立新节点
		printf("input %d number of Node is ",j+1);
		scanf("%d",&p->data);
		p->next=L->next;
		L->next=p; 
	} 
	return ok;
} 
//尾插法建立单链表
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
//输出单链表的元素
int print_list(Linklist &L,int n){
	Linklist r;
	r=L;
	for(int i=0;i<n;i++){
		r=r->next;
		printf("output %d number of list is %d\n",i+1,r->data);
	}
	return ok;
}
//取第i个位置的元素并显示,单链表的读取 
int getnumber_list(Linklist &L,int k){
	Linklist p;
	p=L->next;
	for(int i=1;i<k;i++)
		p=p->next;
	printf("第%d个元素的数为：%d\n",k,p->data);
	return ok;
} 
//单链表的插入：在第i个位置前插入
//i表示插入的位置，e表示需要插入的值 
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
//在第i个位置后插入一个元素
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
//删除第i个元素
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
//修改元素
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
	printf("修改前元素的值为：%d\n",p->data); 
	p->data=e;
	printf("修改后元素的值为：%d\n",p->data);
	return ok;
} 
//整表删除
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
    printf("---------------------------------1.头插法建链表---------------------------------\n");
    printf("---------------------------------2.尾插法建链表---------------------------------\n");
    int m;
    printf("选择为：");
    scanf("%d",&m);
    switch(m){
    	case 1:creat_list_head(p,n);break;
    	case 2:creat_list_tail(p,n);break;
	}
    printf("---------------------------------1.打印单链表-----------------------------------\n");
    printf("---------------------------------2.取数-----------------------------------------\n");
    printf("---------------------------------3.位置前插入元素-------------------------------\n");
    printf("---------------------------------4.位置后插入元素-------------------------------\n");
    printf("---------------------------------5.删除元素-------------------------------------\n");
    printf("---------------------------------6.修改元素-------------------------------------\n");
    printf("---------------------------------7.整表删除-------------------------------------\n");
    printf("---------------------------------8.创建单链表-----------------------------------\n");
	while(1){
		int count;
	    printf("选择数为：");
    	scanf("%d",&count);
		switch(count){
			case 1:{
				print_list(p,n);
				printf("\n");
				break;
			}
			case 2:{
				int i;
				printf("取数的位置为：");
				scanf("%d",&i);
				getnumber_list(p,i);;
				print_list(p,n);
				printf("\n");
				break;
			}
			case 3:{
				int a,b;
				printf("插入的位置为：");
				scanf("%d",&a);
				printf("插入的元素为：");
				scanf("%d",&b);
				insert_list_front(p,a,n,b); 
				print_list(p,n);
				printf("\n");
				break;
			}
			case 4:{
				int a,b;
				printf("插入的位置为：");
				scanf("%d",&a);
				printf("插入的元素为：");
				scanf("%d",&b);
				insert_list_behind(p,a,&n,b);
				print_list(p,n);
				printf("\n");
				break;
			} 
			case 5:{
				int a,b;
				printf("删除的位置为："); 
				scanf("%d",&a);
				delete_list(p,a,n,&b);
				printf("删除的元素为：%d\n",b);
				print_list(p,n);
				printf("\n"); 
				break;
			}
			case 6:{
				int a,b;//a表示位置，b表示修改元素的值
				printf("修改的位置为：");
				scanf("%d",&a);
				printf("修改的元素为：");
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
				printf("---------------------------------1.头插法建链表---------------------------------\n");
   				printf("---------------------------------2.尾插法建链表---------------------------------\n");
   				int m;
    			printf("选择为：");
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
