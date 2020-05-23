//静态链表的实现，用数组来表示
//静态的实现需要自己来编写malloc和free函数 
#include<stdio.h>
#include<stdlib.h>
#define maxsize 100
#define error 0
#define ok 1
typedef struct static_Node{
	int data;
	int cur;
}static_Node,static_list[maxsize];//静态链表的存储结构
//初始化静态链表
int init_static_list(static_list &space){
	int i;
	for(i=0;i<maxsize;i++){
		space[i].cur=i+1;
		space[i].data=0;
	}
	space[maxsize-1].cur=0;
	return ok;
} 
//建立静态链表
int jianli_static_list(static_list &space,int i){
	int k;
	for(k=1;k<=i;k++){
		printf("a[%d]=",k);
		scanf("%d",&space[k].data);
		space[k].cur=k+1;
	}
	space[i].cur=0;
	space[maxsize-1].cur=1;
	space[0].cur=i+1;
	return ok;
} 
//malloc函数的实现
int malloc_static_list(static_list space){
	int i=space[0].cur;
	if(space[0].cur){
		space[0].cur=space[i].cur;
	}
	return i;
} 
//free函数的实现,释放第i个节点 
int free_static_list(static_list &space,int i){
	int k=space[i].cur;
	space[i-1].cur=k;
	space[i].cur=space[0].cur;
	space[0].cur=i;
	return ok;
}
//插入位置前数据data 
int insert_static_list(static_list space,int k,int da,int &n){
	int i,j;
	j=maxsize-1;
	if(k<1||k>n+1)
		return error;
	i=malloc_static_list(space);
	printf("%d\n",i);
	if(i){
			printf("%d\n",da);
		space[i].data=da;
		for(int l=1;l<k;l++)
			j=space[j].cur;//找到下标 
		space[i].cur=space[j].cur;
		space[j].cur=i;//重连接
		n++;
		return ok; 
	}
	else
		return error;
}
//删除
int delete_static_list(static_list &space,int k,int &n){
	int i,j;
	j=maxsize-1;
	if(k<1||k>n){
		return error;
	}
	for(int l=1;l<k;l++)
		j=space[j].cur;
	i=space[j].cur;
	space[j].cur=space[i].cur;
	free_static_list(space,i);
	n--;
	return ok;
}
//获取元素
int get_static_list(static_list &space,int k){
	int j;
	j=maxsize-1;
	for(int l=1;l<=k;l++)
		j=space[j].cur;
	return space[j].data;
} 
//输出静态链表
int print_static_list(static_list space,int k){
	int j;
	j=maxsize-1;
	for(int i=1;i<=k;i++){
		j=space[j].cur;
		printf("a[%d]=%d\n",i,j);
	}
	return ok;
} 
int main(){
	static_list p;
	int n;
	printf("建立n个元素的静态链表！");
	printf("请输入n=");
	scanf("%d",&n);
	jianli_static_list(p,n);
	printf("-------------------------------------1.输出静态链表-----------------------------");
	printf("-------------------------------------2.取数-------------------------------------");
	printf("-------------------------------------3.插入-------------------------------------");
	printf("-------------------------------------4.删除-------------------------------------");
	while(1){
		int m;
		printf("序号为：m=");
		scanf("%d",&m);
		switch(m){
			case 1:print_static_list(p,n);break;
			case 2:{
				int i,j;
				printf("取数的位置为：i=");
				scanf("%d",&i);
				j=get_static_list(p,i);
				printf("取出的数为：j=%d\n",j);
				printf("\n");
				break;
			} 
			case 3:{
				int i,j;
				printf("插入的位置为：i=");
				scanf("%d",&i); 
				printf("插入的数为：j=");
				scanf("%d",&j);
				insert_static_list(p,i,j,n);
				print_static_list(p,n);
				printf("\n");
				break;
			}
			case 4:{
				int i;
				printf("删除的位置为：i=");
				scanf("%d",&i);
				delete_static_list(p,i,n);
				print_static_list(p,n);
				printf("\n");
				break;
			}
		}
	} 
	return 0;
}

