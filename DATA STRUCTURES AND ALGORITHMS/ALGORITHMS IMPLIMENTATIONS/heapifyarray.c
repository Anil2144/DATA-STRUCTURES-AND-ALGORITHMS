#include<stdio.h>
#include<stdlib.h>
void heapify(int a[100],int n)
{
		int f=1,max,i,loc,j,temp;
		
		while(f==1)
		{
				f=0;
				for(i=1;i<=n/2;i++)
				{
							if(n<2*i+1)
							{
										if(a[2*i]>a[i])
										{
												temp=a[i];
												a[i]=a[2*i];
												a[2*i]=temp;
										}
							}
							else
							{
									if(a[i]<a[2*i]  || a[i]< a[2*i+1])          
									{
												if(a[2*i]<a[2*i+1])
														loc=2*i+1;
												else
														loc=2*i;
												temp=a[loc];
												a[loc]=a[i];
												a[i]=temp;
												f=1;
									}
						}			
				}
		}
}																		
void insert(int a[100],int ele,int *n)
{
				int k,f=1,i;
				*n+=1;
				a[*n]=ele;
				i=*n;
				while(i/2>=1 && f==1)
				{
							f=0;
							if(a[i/2]<a[i])
							{
									 k=a[i];
									a[i]=a[i/2];
									a[i/2]=k;
									f=1;
									i=i/2;
							}
				}
}	
void delete(int a[100],int *n)
{
			int i;
			a[1]=a[*n];
			*n-=1;
			heapify(a,*n);
}
void heapsort(int a[100],int n)
{
			int i,j,m,temp;
			m=n;
			while(m!=1)
			{
					temp=a[m];
					a[m]=a[1];
					a[1]=temp;
					m--;
					heapify(a,m);
			}
			for(i=1;i<=n;i++)
					printf("%d  ",a[i]);
}					
					
																																																						
 void main()
 {
 			int a[100],n,i,ele,opt;
 			printf("Enter size:");
 			scanf("%d",&n);
 			printf("Enter elements:");
 			for(i=1;i<=n;i++)
 			{
 					scanf("%d",&a[i]);
 			}
 			heapify(a,n);
 		printf("1.Insert\t2.Delete\t3.Heapify\t4.Heapsort\t5.Display\t6.Exit\n");
 			do
 			{
 					printf("Enter option:");
 					scanf("%d",&opt);	
 					switch(opt)
 					{
 										case 1:printf("Enter element:");
 													scanf("%d",&ele);
 													insert(a,ele,&n);
 													break;
 										case 2:delete(a,&n);
 													break;
 										case 3:heapify(a,n);
 													break;
 										case 4:heapsort(a,n);
 													break;
 										case 5:	 for(i=1;i<=n;i++)
											 					printf("%d  ",a[i]);
											 		printf("\n");
											 		break;
										case 6:exit(0);
													break;
										default:printf("Invalid choice\n");
					}
			}while(opt!=6);								
 }
 
 
 					
