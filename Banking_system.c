#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
void displayRecord();
void addNewData();
void change_password();
void view_statement();
void deleteRecord();
void login();

struct account
{
	long int account_no;
	char name[30];
	long int password[10];
	double balance;
	long int phone_no;
	char Address[100];
};
struct account ban;
int main()
{
	int ch;
	while (ch !=3)
	{

		printf("\n\n\t\t--------WE WELCOME YOU TO OUR BANK MANAGEMENT SYSTEM--------\n\n");

		printf("\t\t\t1.........USER PANEL..........");

		printf("\n\t\t\t2..........ADMIN PANEL..........");
		printf("\n\t\t\t3..........EXIT...............");
	
		printf("\n\n\t\t....Enter your choice (1-3): ");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			user_panel();
			break;
		case 2:
			admin_panel();
			break;
		case 3:
			printf("\n\n\t\t-----Thank you for using the Banking Management System!-----");
			break;
		default:
			printf("\nInvalid choice! Please try again.");
		}
	}
}
user_panel()
{
	int ch;
	while (ch != 4)
	{
		printf("\n\n\t\t------Welcome to The User Panel-------");

		printf("\n\n\t\t1.... ALREADY A USER? SIGN IN");


		printf("\n\t\t2..... Changing Password");

		printf("\n\t\t3..... View Account Statement");

		printf("\n\t\t4.... EXIT\n\n");

		printf("\n\n......Enter your choice (1-4): ");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			login();
			break;
		case 2:
		change_password();
			break;
		case 3:
		view_statement();
			break;
		case 4:
			printf("\n\n\t\t-----Thank you for using the Banking Management System!-----");
			break;
		default:
			printf("\nInvalid choice! Please try again.");
	
}
}
}
admin_panel()
{
	int ch;
	while (ch != 4)
	{
		printf("\n\n\t\t------Welcome to The Admin Panel-------\n");
		printf("\n\n\t\t1.... CREATE A BANK ACCOUNT");



		printf("\n\t\t2..... Display Accounts Record");


		printf("\n\t\t3..... Delete Accounts Record");

		printf("\n\t\t4.......... EXIT\n\n");

		printf("\n\n......Enter your choice (1-4): ");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			addNewData();
			break;
		case 2:
			displayRecord();
			break;
		case 3:
		deleteRecord();
			break;
		case 4:
			printf("\n\n\t\t-----Thank you for using the Banking Management System!-----");
			break;
		default:
			printf("\nInvalid choice! Please try again.");

}
}
}
void addNewData()
{
	FILE *fp;

	fp = fopen("Ban.txt", "r");
	if (fp == NULL)
	{
		printf("\n\t\tError: Cannot open The File!!!");
	}
	printf("\n\n\t----Enter New Account details\n");

	printf("\n----Enter Account no : ");
	scanf("%ld", &ban.account_no);
	fflush(stdin);

	printf("\n----Enter Account Holder Name : ");
	gets(ban.name);

	printf("\n----Enter Account Holder Address : ");
	gets(ban.Address);

	printf("\n-----Enter Account Holder Phone no : ");
	scanf("%ld", &ban.phone_no);

	printf("\n------Enter Password : ");
	scanf("%ld", &ban.password);

	printf("\n-----Enter the reamainng balance : ");
	scanf("%lf", &ban.balance);
	int flag = 0;
	fclose(fp);

	fp = fopen("Ban.txt", "a+");
	flag = fwrite(&ban, sizeof(ban), 1, fp);
	if (flag)
	{
		printf("Contents of theā structure written "
					 "successfully");
	}
	else
		printf("Error Writing to File!");

	fclose(fp);
	printf("\n\t\t----Updated Record-------");
	displayRecord();
}
void displayRecord()
{
	FILE *fp;
	fp = fopen("Ban.txt", "r+");
	if (fp == NULL)
	{
		printf("\n\t\tError: Cannot open The File!!!");
		return;
	}
	printf("\n\n\t-----Bank Account Details are as Follow---\n");
	printf("\n\nAccount_no\t\tAc_holder_name\t\tPhone Number\t\t\tAddress\n");
	while (fread(&ban, sizeof(ban), 1, fp) == 1)
	{
		printf("\n%ld\t\t%s\t\t\t%ld\t\t\t%s", ban.account_no, ban.name, ban.phone_no, ban.Address);
	}
	fclose(fp);
}
void view_statement()
{
	long int id, flag = 0;
	FILE *fp;
	fp = fopen("Ban.txt", "rb");
	if (fp == NULL)
	{
		printf("\n\t\tError: Cannot open The File!!!");
		return;
	}
	printf("\n\n\tEnter Account no Which You Want to Search: ");
	scanf("%ld", &id);
	while (fread(&ban, sizeof(ban), 1, fp) > 0 && flag == 0)
	{
		if (ban.account_no == id)
		{
			flag = 1;
			printf("\n\n\tSearch Sucessfully and Bank Details is as Follow:\n\n");
			printf("\n\nAccount_no\t\tAc_holder_name\t\tPhone Number\t\tAddress\t\t\tAvailable Balance");
			printf("\n%ld\t\t\t%s\t\t%ld\t\t%s\t\t\t%lf", ban.account_no, ban.name, ban.phone_no, ban.Address, ban.balance);
		}
		if (flag == 0)
		{
			printf("\n\n\tNo Such Record Found !!!!\n");
		}
	
	}
	fclose(fp);
}
void deleteRecord()
{

	FILE *fp, *fp1;
	int j, rn, found = 0, rno;
	fp = fopen("Ban.txt", "r");
	fp1 = fopen("Ban1.txt", "w");
	printf("\t -----Previous Account Records-----");
	displayRecord();

	printf("\n\n\t\tEnter Account number to be deleted: ");
	
	scanf("%d", &rno);
	fflush(stdin);

	while (fread(&ban, sizeof(ban), 1, fp))
	{
		if (ban.account_no == rno)
		{
			found = 1;
		}
		else
			fwrite(&ban, sizeof(ban), 1, fp1);
	}

	fclose(fp);
	fclose(fp1);
	if (found)
	{
		fp1 = fopen("Ban1.txt", "r");
		fp = fopen("Ban.txt", "w");

		while (fread(&ban, sizeof(ban), 1, fp1))
		{
			fwrite(&ban, sizeof(ban), 1, fp);
		};
		fclose(fp1);
		fclose(fp);
	}
	else
	{
		printf("\nRecord Not Found");
	}
	displayRecord();
}
void change_password()
{
    long int id, flag = 0;
    long int old_pass, new_pass;
    int i;
    FILE *fp;
    struct account acc;

    fp = fopen("Ban.txt", "rb+");
    if (fp == NULL)
    {
        printf("\n\t\tError: Cannot open the file!!!");
        return;
    }

    printf("\n\n\tEnter account number for which you want to update the password: ");
    scanf("%ld", &id);

    while (fread(&acc, sizeof(acc), 1, fp) > 0 && flag == 0)
    {
        if (acc.account_no == id)
        {
            flag = 1;
            printf("\n\t\t-----Your request for changing the password has been accepted.\n");
            printf("\n\t\t----Enter previous password: ");
            scanf("%ld", &old_pass);

            if (acc.password[0] == old_pass)
            {
                printf("\n---- Now enter the new password ---\n\n");
                printf("\n------Updated password: ");
                scanf("%ld", &new_pass);
                fflush(stdin);

                for(i=0; i<10; i++){
                    if(new_pass == acc.password[i]){
                        printf("\n------New password cannot be same as old password. Please enter a different password.-----\n");
                        return;
                    }
                }

                acc.password[0] = new_pass;

                fseek(fp, -(long)sizeof(acc), SEEK_CUR); 
                fwrite(&acc, sizeof(acc), 1, fp);  
                printf("\n\t-------Password changed successfully!!!!!\n");
            }
            else
            {
                printf("\n\t------Incorrect previous password.------\n");
            }
        }
    }

    if (flag == 0)
    {
        printf("\nAccount not found.\n");
    }

    fclose(fp);
}



void login()
{

	char username[50];
	char password[50];

	int i, j, k;
	char ch;
	FILE *fp, *fu;

	fp = fopen("Ban.txt",
						 "rb");

	if (fp == NULL)
	{
		printf("ERROR IN OPENING FILE");
	}
	printf(" \n\n\t\tACCOUNT LOGIN ");
	printf("\n\t***********************************************"
				 "********************************");

	printf("\n\t\t===== LOG IN ====");

	printf("\n\t\tUSERNAME : ");
	scanf("%s", &username);

	printf("\n\t\tPASSWORD : ");

	for (i = 0; i < 10; i++)
	{
		ch = getch();
		if (ch != 11)
		{
			password[i] = ch;
			ch = '*';
			printf("%c", ch);
		}

		else
			break;
	}

	while (fread(&ban, sizeof(ban),
							 1, fp))
	{
		if (strcmp(username, ban.name) == 0)
		{
			printf("\n\n\t\tFetching account details.....\n");
			for (i = 0; i < 20000; i++)
			{
				i++;
				i--;
			}
			printf("\n\t\tLOGIN SUCCESSFUL....");
			printf("Press enter to continue");
		}
		
	}

	fclose(fp);
}

