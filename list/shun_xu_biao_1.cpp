#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 30           //���Ա�洢�ռ��ʼ������ 
#define OK 1
#define ERROR 0

typedef struct{
	int data[MAXSIZE];       //����洢����Ԫ�� 
	int length;              //���Ա�ǰ���� 
}Sqlist;
//���ձ�
int init_list(Sqlist *La,Sqlist *Lb,Sqlist *Lc){
	Lc->length=La->length+Lb->length; 
	for(int i=0;i<Lc->length;i++)
		Lc->data[i]=0;
	return OK;
} 
//����
void creat_list(Sqlist *L){
	int i;
	printf("input n=");      //n��ʾlength�ĳ��� 
	scanf("%d",&L->length);
	for(i=0;i<L->length;i++){
		printf("data[%d]=",i);
		scanf("%d",&L->data[i]);   //����n����ֵ 
	}
	printf("\n");
} 
//����� 
void print_list(Sqlist *L){
	int i;
	printf("The datas of list is ��\n");
	for(int i=0;i<L->length;i++){
	   printf("data[%d]=%d",i,L->data[i]);
	   printf("\n");
	}
}
//���ر�ĳ��� 
int length_list(Sqlist *L){
	int i=0;
	i=L->length;
	printf("The length of list is %d\n",i);
	return OK;
}
//ȡ�����еĵ�i��Ԫ��
int  get_data_list(Sqlist *L,int i){
	if(L->length==0 || i<1 || i>L->length)
	   return ERROR;
	return L->data[i-1];
}
//�ڵ�i��λ��ǰ����һ��Ԫ��e 
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
//�ڵ�i��λ�ú����һ��Ԫ��e 
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
//ɾ����i��λ��ǰ��Ԫ��,����ɾ����ֵ 
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
//ɾ����i��λ�ú��Ԫ��,����ɾ����ֵ 
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
//������ͬԪ�ص��±�
int equal_list(Sqlist *L,int e){
	printf("The location of equal data is");
	for(int i=0;i<L->length;i++)
		if(L->data[i]==e)
			printf("%4d",i);
	printf("\n");   
	return OK; 
} 
//��������ĺϲ�
int La_and_Lb_list(Sqlist *La,Sqlist *Lb,Sqlist *Lc){
	int e,a; //��������ͬ������Ԫ�ص����� 
	int count;//������
	int m;
	m=La->length;//����Lc�ĳ��ȱ�ʾ 
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
//������ 
int main(){
	Sqlist L;//����һ���� 
	creat_list(&L);
	printf("\t-----------------------1.��ĳ���-----------------------\n");
	printf("\t-----------------------2.��ӡ��-------------------------\n");
	printf("\t-----------------------3.ȡ��һ��Ԫ��-------------------\n");
	printf("\t-----------------------4.λ��ǰ����Ԫ��-----------------\n");
	printf("\t-----------------------5.λ�ú����Ԫ��-----------------\n"); 
	printf("\t-----------------------6.λ��ǰɾ��Ԫ��-----------------\n");
	printf("\t-----------------------7.λ�ú�ɾ��Ԫ��-----------------\n");
	printf("\t-----------------------8.��ͬԪ���±�Ĳ���-------------\n");
	printf("\t-----------------------9.��������ĺϲ�-----------------\n");
	while(1){
		int m;
		printf("m=");//ѡ���� 
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
	            printf("ȡ����Ԫ��Ϊ��%d\n",get_data_list(&L,n));
	            print_list(&L);
	            length_list(&L);
	            printf("\n");
				break;
			}
			case 4:{
			    length_list(&L);
				int n;
				printf("The location of insert is ");//�����λ�� 
               	scanf("%d",&n);
               	int data;
				printf("data is : ");
				scanf("%d",&data);   //������� 
				insert_front_list(&L,n,data);
				print_list(&L);
				length_list(&L); 
				printf("\n");
				break;
			}
			case 5:{
				length_list(&L);
				int n;
				printf("The location of insert is ");//�����λ�� 
               	scanf("%d",&n);
               	int data;
				printf("data is : ");
				scanf("%d",&data);   //������� 
				insert_last_list(&L,n,data);
				print_list(&L);
				length_list(&L); 
				printf("\n");
				break;
			} 
			case 6:{
				length_list(&L);
				int n,e;
				printf("The location of insert is ");//ɾ����λ�� 
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
				printf("The location of insert is ");//ɾ����λ�� 
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
				printf("The data is ");//�����Ԫ�أ��������ҳ���ͬԪ�ص�λ��
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
