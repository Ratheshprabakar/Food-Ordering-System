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
struct details s[100];
void signup();
void account_check();
int validate();
void login();
int flag=1,i,j=0,count=0,caps=0,small=0,special=0,numbers=0,success=0,x,choice;
char temp_name[100],temp_password1[100],temp_password2[100],temp_email[100],temp_mobile[100];
int temp_age;
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
	printf("Enter Your Email\t");
	scanf("%s",temp_email);
	printf("Enter Your Password\t");
	scanf("%s",temp_password1);
	for(i=0;i<100;i++)
	{
		if(!strcmp(s[i].email,temp_email))
		{
			if(!strcmp(s[i].password,temp_password1))
			{
				printf("\n\nWelcome %s, Your are successfully logged in\n\n",s[i].uname);
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

