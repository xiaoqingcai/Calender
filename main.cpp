#include "mymath.h"
#include <stdlib.h>
int main(int argc, char* argv[])
{
	int select = 1;
	
	int year = 0;
	int month = 0;
	int day = 0;
	while( select != 4)
	{
		menu();
		scanf("%d", &select );
		switch( select )
		{
			case 1:
			{
				printf("Please input the year whose calendar you want to know: ");
				scanf("%d", &year);
				print_year( year );
			}
			break;
			case 2:
			{
				printf("Please input the year and month whose calendar you want to know: ");
				scanf("%d", &year);
				scanf("%d", &month);
				print_month( year, month );
			}
			break;
			case 3:
			{
				printf("Please input the year,month and day whose calendar you want to know: ");
				scanf("%d", &year);
				scanf("%d", &month);
				scanf("%d", &day);
				print_day( year, month, day );
			}
			break;
			case 4:
			{
				printf("Bye Bye!\n");
			}
			break;
			default:
			{
				printf("your input is error, please input again!\n");
			}
			break;	
		}
		printf("Please any key to continue\n");
		getchar();
		getchar();
		system("cls");
	}
	return 0;
}