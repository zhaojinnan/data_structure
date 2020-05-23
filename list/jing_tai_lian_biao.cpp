//��̬�����ʵ�֣�����������ʾ
//��̬��ʵ����Ҫ�Լ�����дmalloc��free���� 
#include<stdio.h>
#include<stdlib.h>
#define maxsize 100
#define error 0
#define ok 1
typedef struct static_Node{
	int data;
	int cur;
}static_Node,static_list[maxsize];//��̬����Ĵ洢�ṹ
//��ʼ����̬����
int init_static_list(static_list &space){
	int i;
	for(i=0;i<maxsize;i++){
		space[i].cur=i+1;
		space[i].data=0;
	}
	space[maxsize-1].cur=0;
	return ok;
} 
//������̬����
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
//malloc������ʵ��
int malloc_static_list(static_list space){
	int i=space[0].cur;
	if(space[0].cur){
		space[0].cur=space[i].cur;
	}
	return i;
} 
//free������ʵ��,�ͷŵ�i���ڵ� 
int free_static_list(static_list &space,int i){
	int k=space[i].cur;
	space[i-1].cur=k;
	space[i].cur=space[0].cur;
	space[0].cur=i;
	return ok;
}
//����λ��ǰ����data 
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
			j=space[j].cur;//�ҵ��±� 
		space[i].cur=space[j].cur;
		space[j].cur=i;//������
		n++;
		return ok; 
	}
	else
		return error;
}
//ɾ��
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
//��ȡԪ��
int get_static_list(static_list &space,int k){
	int j;
	j=maxsize-1;
	for(int l=1;l<=k;l++)
		j=space[j].cur;
	return space[j].data;
} 
//�����̬����
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
	printf("����n��Ԫ�صľ�̬����");
	printf("������n=");
	scanf("%d",&n);
	jianli_static_list(p,n);
	printf("-------------------------------------1.�����̬����-----------------------------");
	printf("-------------------------------------2.ȡ��-------------------------------------");
	printf("-------------------------------------3.����-------------------------------------");
	printf("-------------------------------------4.ɾ��-------------------------------------");
	while(1){
		int m;
		printf("���Ϊ��m=");
		scanf("%d",&m);
		switch(m){
			case 1:print_static_list(p,n);break;
			case 2:{
				int i,j;
				printf("ȡ����λ��Ϊ��i=");
				scanf("%d",&i);
				j=get_static_list(p,i);
				printf("ȡ������Ϊ��j=%d\n",j);
				printf("\n");
				break;
			} 
			case 3:{
				int i,j;
				printf("�����λ��Ϊ��i=");
				scanf("%d",&i); 
				printf("�������Ϊ��j=");
				scanf("%d",&j);
				insert_static_list(p,i,j,n);
				print_static_list(p,n);
				printf("\n");
				break;
			}
			case 4:{
				int i;
				printf("ɾ����λ��Ϊ��i=");
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

