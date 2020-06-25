/*Food Ordering System*/
#include<stdio.h>
struct details
{
	char uname[100];
	int age;
	char password[100];
	char email[100];
	char mobile[10];
};
struct hotels
{
	char hotel[100];
	char first_food[20];
	char second_food[20];
	char third_food[20];
	char fourth_food[25];
	int first,second,third,fourth;
};
struct hotels m[5];
struct details s[100];
void signup();
void account_check();
int validate();
void login();
void cart();
void search_by_hotels();
void search_by_food();
void food_order(int food);
void hotel_initialize();
void hotels(int hotel_choice);
int flag=1,i,j=0,count=0,caps=0,small=0,special=0,numbers=0,success=0,x,choice;
char temp_name[100],temp_password1[100],temp_password2[100],temp_email[100],temp_mobile[100];
int temp_age,total=0,food_choice,n,hotel_choice,search_choice,confirm;
int ch,food,hotel_id;
int main()
{
	while(1)
	{
		printf("\n\nWelcome to Food Ordering System\n\n1)SIGNUP\n2)LOGIN\n3)EXIT\n\nEnter your choice\t");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			{
				signup();
				break;
			}
			case 2:
			{
				login();
				break;
			}
			case 3:
			{
				exit(1);
			}
			default:
			{
				printf("\nPlease Enter the valid choice\n");
				break;					
			}
					
		}
	}
}
void signup()
{
	printf("Enter Your name\t");
	scanf("%s",temp_name);
	printf("Enter Your Age\t");
	scanf("%d",&temp_age);
	printf("Enter Your Email\t");
	scanf("%s",temp_email);
	printf("Enter Password\t");
	scanf("%s",temp_password1);
	printf("Confirm Password\t");
	scanf("%s",temp_password2);
	printf("Enter Your Mobile Number\t");
	scanf("%s",temp_mobile);
	x=validate();
	if(x==1)
		account_check();

}
void login()
{
	printf("\n\nLOGIN\n\n")
	printf("\nEnter Your Email\t");
	scanf("%s",temp_email);
	printf("Enter Your Password\t");
	scanf("%s",temp_password1);
	for(i=0;i<100;i++)
	{
		if(!strcmp(s[i].email,temp_email))
		{
			if(!strcmp(s[i].password,temp_password1))
			{
				printf("\n\nWelcome %s, Your are successfully logged in\n\nWe Provide two ways of search\n1) Search By Hotels\n2) Search by Food\n3) Exit\n\nPlease Enter your choice\t",s[i].uname);
				scanf("%d",&search_choice);
				switch(search_choice)
				{
					case 1: 
					{
						search_by_hotels();
						break;
					}
					case 2:
					{
						search_by_food();
						break;	
					}
					case 3:
					{
						exit(1);
					}
					default:
					{
						printf("Please Enter the valid choice\n\n");
						break;
					}
				}
				break;
			}
			else
			{
				printf("\n\nInvalid Password! Please Enter the correct password\n\n");
				main();
				break;
			}
		}
		else
		{
			printf("\n\nAccount doesn't exist, Please signup!!\n\n");
			main();
			break;
		}	
	}
}

void search_by_hotels()
{
	hotel_initialize();
	printf("\n\nPlease Choose the hotels\n\n1) %s\n2) %s\n3) %s\n4) Exit\n\nPlease select the hotel\t",m[1].hotel,m[2].hotel,m[3].hotel);
	scanf("%d",&hotel_choice);
	if(hotel_choice>4)
	{
		printf("Please Enter the valid choice\n\n");
		search_by_hotels();
	}
	else if(hotel_choice==4)
		exit(1);
	else
		hotels(hotel_choice);
}
void search_by_food()
{
	total=0;
	hotel_initialize();
	while(1)
	{
		printf("\n\nPlease choose the food\n\n1) %s\t%d\n2) %s\t%d\n3) %s\t%d\n4) %s\t%d\n5) %s\t%d\n6) %s\t%d\n7) %s\t%d\n8) %s\t%d\n9) %s\t%d\n10) Cart\n11) Exit",m[1].first_food,m[1].first,m[1].second_food,m[1].second,m[1].third_food,m[1].third,m[2].first_food,m[2].first,m[2].second_food,m[2].second,m[2].third_food,m[2].third,m[3].first_food,m[3].first,m[3].second_food,m[3].second,m[3].third_food,m[3].third);
		printf("\nPlease Enter Your Choice\t");
		scanf("%d",&food);
		if(food>10)
		{
			printf("Please Enter the valid choice\n\n");
			search_by_food();
		}
		else if(food==10)
			cart();
		else if(food==11)
			exit(1);
		else 
			food_order(food);
	}
		
}
void food_order(int food)
{
	if(food>=1 && food<=3)
		hotel_id=1;
	else if(food>=4 && food<=6)
		hotel_id=2;
	else
		hotel_id=3;
	if((food%3)==1)
	{			
		printf("Please Enter the Count of %s\t",m[hotel_id].first_food);
		scanf("%d",&n);
		total=total+(n*m[hotel_id].first);
	}
	else if((food%3)==2)
	{			
		printf("Please Enter the Count of %s\t",m[hotel_id].second_food);
		scanf("%d",&n);
		total=total+(n*m[hotel_id].second);
	}
	else if((food%3)==0)
	{
		printf("Please Enter the Count of %s\t",m[hotel_id].third_food);
		scanf("%d",&n);
		total=total+(n*m[hotel_id].third);
	}

	
}
void hotels(int hotel_choice)
{
	total=0;
	while(1)
		{
			printf("\n\nList of foods available in %s\n\n1) %s\tRs: %d\n2) %s\tRs: %d\n3) %s\tRs: %d\n4) Cart\n5) Exit\n\nPlease Enter Your Choice\t",m[hotel_choice].hotel,m[hotel_choice].first_food,m[hotel_choice].first,m[hotel_choice].second_food,m[hotel_choice].second,m[hotel_choice].third_food,m[hotel_choice].third);
			scanf("%d",&food_choice);
			if(food_choice==1)
			{			
				printf("Please Enter the Count of %s\t",m[hotel_choice].first_food);
				scanf("%d",&n);
				total=total+(n*m[hotel_choice].first);
			}
			else if(food_choice==2)
			{			
				printf("Please Enter the Count of %s\t",m[hotel_choice].second_food);
				scanf("%d",&n);
				total=total+(n*m[hotel_choice].second);
			}
			else if(food_choice==3)
			{
				printf("Please Enter the Count of %s\t",m[hotel_choice].third_food);
				scanf("%d",&n);
				total=total+(n*m[hotel_choice].third);
			}
			else if(food_choice==4)
			{
				cart();
			}
			else if(food_choice==5)
			{
				search_by_hotels();	
			}
			else
			{
				printf("Please Enter the valid Choice\n\n");
			}

			
		}
	
}
void cart()
{
	printf("\n\n\n\n--------------Cart----------------");
	printf("\nYour Total Order Amount is %d\n",total);
	printf("\n\nDo You wish to order (y=1/n=0):");
	scanf("%d",&ch);
	if(ch==1)
	{
		printf("\n\nThank You for your order!! Your Food is on the way. Welcome again!!\n\n");
		exit(1);
	}
	else if(ch==0)
	{
		printf("Do You want to exit -1 or Go back -0");
		scanf("%d",&confirm);
		if(confirm==1)
		{
			printf("\n\nOops! Your order is cancelled!! Exiting..Thank You visit again!\n");
			exit(1);
		}
		else
		{
			printf("\n\nThank You\n\n");
			login();
		}
	}
	else
	{
		printf("\n\nPlease Enter the correct choice\n\n");
		cart();
	}
}

void account_check()
{
	for(i=0;i<100;i++)
	{
		if(!(strcmp(temp_email,s[i].email) && strcmp(temp_password1,s[i].password)))
		{
			printf("\n\nAccount Already Existed. Please Login !!\n\n");
			main();
			break;		
		}
	}
	if(i==100)
	{
		strcpy(s[j].uname,temp_name);
		s[j].age=temp_age;
		strcpy(s[j].password,temp_password1);
		strcpy(s[j].email,temp_email);
		strcpy(s[j].mobile,temp_mobile);
		j++;
		printf("\n\n\nAccount Successfully Created!!\n\n");
	}

}
int validate()
{
	for(i=0;temp_name[i]!='\0';i++)
	{
		if(!((temp_name[i]>='a' && temp_name[i]<='z')||(temp_name[i]>='A' && temp_name[i]<='Z')))
		{
			printf("\nPlease Enter the valid Name\n");
			flag=0;
			break;
		}
	}
	if(flag==1)
	{
		count=0;
		for(i=0;temp_email[i]!='\0';i++)
		{
			if(temp_email[i]=='@' || temp_email[i]=='.')
			{
				count++;	
			}
		}
		if(count>=2 && strlen(temp_email)>=5)
		{
			if(!strcmp(temp_password1,temp_password2))
			{
				if(strlen(temp_password1)>=8 && strlen(temp_password1)<=12)
				{	
					caps=0;small=0;numbers=0;special=0;	
					for(i=0;temp_password1[i]!='\0';i++)
					{
						if(temp_password1[i]>='A' && temp_password1[i]<='Z')
							caps++;
						else if(temp_password1[i]>='a' && temp_password1[i]<='z')
							small++;
						else if(temp_password1[i]>='0' && temp_password1[i]<='9')
							numbers++;
						else if(temp_password1[i]=='@' || temp_password1[i]=='&' || temp_password1[i]=='#' || temp_password1[i]=='*')
							special++;
					}
					if(caps>=1 && small>=1 && numbers>=1 && special>=1)
					{
						if(temp_age!=0 && temp_age>0)
						{
							if(strlen(temp_mobile)==10)
							{
								for(i=0;i<10;i++)
								{
									if(temp_mobile[i]>='0' && temp_mobile[i]<='9')
									{									
										success=1;
									}
									else
									{
										printf("\n\nPlease Enter Valid Mobile Number\n\n");
										return 0;
										break;
									}	
								}
								if(success==1)
									return 1;
							}
							else
							{
								printf("\n\nPlease Enter the 10 digit mobile number\n\n");
								return 0;
							}
						}
						else
						{
							printf("\n\nPlease Enter the valid age\n\n");
							return 0;
						}
					}
					else
					{
						printf("\n\nPlease Enter the strong password, Your password must contain atleast one uppercase, Lowercase, Number and special character\n\n");
						return 0;
					}
				}
				else
				{
					printf("\nYour Password is very short\nLength must between 8 to 12\n\n");
					return 0;
				}
			}
			else
			{
				printf("\nPassword Mismatch\n\n");
				return 0;
			}	
		}
		else
		{
			printf("\nPlease Enter Valid E-Mail\n\n");
			return 0;
		}
	}
}
void hotel_initialize()
{
	strcpy(m[1].hotel,"Aarya_Bhavan");
	strcpy(m[1].first_food,"Sandwich");
	strcpy(m[1].second_food,"Pizza");
	strcpy(m[1].third_food,"Fried_Rice");
	m[1].first=70;
	m[1].second=100;
	m[1].third=95;

	strcpy(m[2].hotel,"Banu_Hotel");
	strcpy(m[2].first_food,"Parotta");
	strcpy(m[2].second_food,"Noodles");
	strcpy(m[2].third_food,"Chicken_Rice");
	m[2].first=15;
	m[2].second=75;
	m[2].third=80;

	strcpy(m[3].hotel,"SR_Bhavan");
	strcpy(m[3].first_food,"Chicken_Biriyani");
	strcpy(m[3].second_food,"Prawn");
	strcpy(m[3].third_food,"Faloda");
	m[3].first=90;
	m[3].second=120;
	m[3].third=35;
}

