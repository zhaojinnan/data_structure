#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 30           //线性表存储空间初始分配量 
#define OK 1
#define ERROR 0

typedef struct{
	int data[MAXSIZE];       //数组存储数据元素 
	int length;              //线性表当前长度 
}Sqlist;
//建空表
int init_list(Sqlist *La,Sqlist *Lb,Sqlist *Lc){
	Lc->length=La->length+Lb->length; 
	for(int i=0;i<Lc->length;i++)
		Lc->data[i]=0;
	return OK;
} 
//建表
void creat_list(Sqlist *L){
	int i;
	printf("input n=");      //n表示length的长度 
	scanf("%d",&L->length);
	for(i=0;i<L->length;i++){
		printf("data[%d]=",i);
		scanf("%d",&L->data[i]);   //输入n个数值 
	}
	printf("\n");
} 
//输出表 
void print_list(Sqlist *L){
	int i;
	printf("The datas of list is ：\n");
	for(int i=0;i<L->length;i++){
	   printf("data[%d]=%d",i,L->data[i]);
	   printf("\n");
	}
}
//返回表的长度 
int length_list(Sqlist *L){
	int i=0;
	i=L->length;
	printf("The length of list is %d\n",i);
	return OK;
}
//取出表中的第i个元素
int  get_data_list(Sqlist *L,int i){
	if(L->length==0 || i<1 || i>L->length)
	   return ERROR;
	return L->data[i-1];
}
//在第i个位置前插入一个元素e 
int insert_front_list(Sqlist *L,int i,int e){
	int a;
	if(L->length==MAXSIZE){
		printf("it is error!\n");
	}
	if(i<1 || i>L->length+1){
		printf("it is error!\n");
	} 
	if(i<=L->length+1){
		for(a=L->length-1;a>=i-1;a--)
		   L->data[a+1]=L->data[a];
		L->data[i-1]=e;
		L->length++;
		return OK;
	}
}
//在第i个位置后插入一个元素e 
int insert_last_list(Sqlist *L,int i,int e){
	int a;
	if(L->length==MAXSIZE){
		printf("it is error!\n");
	}
	if(i<0 || i>L->length){
		printf("it is error!\n");
	} 
	if(i<=L->length){
		for(a=L->length-1;a>i-1;a--)
		   L->data[a+1]=L->data[a];
		L->data[i]=e;
		L->length++;
		return OK;
	}
}
//删除第i个位置前的元素,返回删除的值 
int delete_front_list(Sqlist *L,int i,int e){
	if(L->length==0){
		printf("it is error!\n");
	}
	if(i<=1 || i>L->length+1){
		printf("it is error!\n");
	}
	if(i<=L->length+1){
		e=L->data[i-2];
		printf("The data of delete is %d\n",e);
		for(int m=i-1;m<=L->length;m++)
		   L->data[m-1]=L->data[m];
		L->length--;
		return OK;
	}
} 
//删除第i个位置后的元素,返回删除的值 
int delete_last_list(Sqlist *L,int i,int e){
	if(L->length==0){
		printf("it is error!\n");
	}
	if(i<0 || i>L->length-1){
		printf("it is error!\n");
	}
	if(i<L->length){
		e=L->data[i];
		printf("The data of delete is %d\n",e);
		for(int m=i;m<L->length-1;m++)
		   L->data[m]=L->data[m+1];
		L->length--;
		return OK;
	}
}
//查找相同元素的下标
int equal_list(Sqlist *L,int e){
	printf("The location of equal data is");
	for(int i=0;i<L->length;i++)
		if(L->data[i]==e)
			printf("%4d",i);
	printf("\n");   
	return OK; 
} 
//两个链表的合并
int La_and_Lb_list(Sqlist *La,Sqlist *Lb,Sqlist *Lc){
	int e,a; //两表中相同的数据元素的声明 
	int count;//计数器
	int m;
	m=La->length;//进行Lc的长度表示 
	Lc->length=La->length+Lb->length;
	for(int i=0;i<La->length;i++)
		Lc->data[i]=La->data[i]; 
	for(int i=0;i<Lb->length;i++){
		e=Lb->data[i];
		for(int j=0;j<La->length;j++){
			if(e==La->data[j]){
				a=j;
				count=1; 
				break;
			} 
		}
		if(count==1){ 
			Lc->data[a]=e;
			Lc->length--;
			count=0;
		} 
		else
			Lc->data[m++]=e;
	}
	return OK;
} 
//主函数 
int main(){
	Sqlist L;//定义一个表 
	creat_list(&L);
	printf("\t-----------------------1.表的长度-----------------------\n");
	printf("\t-----------------------2.打印表-------------------------\n");
	printf("\t-----------------------3.取出一个元素-------------------\n");
	printf("\t-----------------------4.位置前插入元素-----------------\n");
	printf("\t-----------------------5.位置后插入元素-----------------\n"); 
	printf("\t-----------------------6.位置前删除元素-----------------\n");
	printf("\t-----------------------7.位置后删除元素-----------------\n");
	printf("\t-----------------------8.相同元素下标的查找-------------\n");
	printf("\t-----------------------9.两个链表的合并-----------------\n");
	while(1){
		int m;
		printf("m=");//选择项 
		scanf("%d",&m);
		switch(m){
			case 1:length_list(&L);break;
			case 2:{
				print_list(&L);
				length_list(&L);
				printf("\n");
				break;
			}
			case 3:{
				int n;
				printf("The location of data is ");
               	scanf("%d",&n);
	            printf("取出的元素为：%d\n",get_data_list(&L,n));
	            print_list(&L);
	            length_list(&L);
	            printf("\n");
				break;
			}
			case 4:{
			    length_list(&L);
				int n;
				printf("The location of insert is ");//插入的位置 
               	scanf("%d",&n);
               	int data;
				printf("data is : ");
				scanf("%d",&data);   //插入的数 
				insert_front_list(&L,n,data);
				print_list(&L);
				length_list(&L); 
				printf("\n");
				break;
			}
			case 5:{
				length_list(&L);
				int n;
				printf("The location of insert is ");//插入的位置 
               	scanf("%d",&n);
               	int data;
				printf("data is : ");
				scanf("%d",&data);   //插入的数 
				insert_last_list(&L,n,data);
				print_list(&L);
				length_list(&L); 
				printf("\n");
				break;
			} 
			case 6:{
				length_list(&L);
				int n,e;
				printf("The location of insert is ");//删除的位置 
               	scanf("%d",&n);
				delete_front_list(&L,n,e);
				print_list(&L);
				length_list(&L); 
				printf("\n");
				break;
			}
			case 7:{
				length_list(&L);
				int n,e;
				printf("The location of insert is ");//删除的位置 
               	scanf("%d",&n);
				delete_last_list(&L,n,e);
				print_list(&L);
				length_list(&L); 
				printf("\n");
				break;
			} 
			case 8:{
				length_list(&L);
				int e;
				printf("The data is ");//输入的元素，根据其找出相同元素的位置
				scanf("%d",&e);
				equal_list(&L,e);
				printf("\n"); 
				break;
			}
			case 9:{
				Sqlist Lb,Lc;
				creat_list(&Lb);
				La_and_Lb_list(&L,&Lb,&Lc);
				length_list(&Lc);
				print_list(&Lc);
				printf("\n");
				break;
			}
		}
	}
	return 0;
}
