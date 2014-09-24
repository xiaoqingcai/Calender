#include "mymath.h"
int month_day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
void menu()
{
	printf("����������������������������������������������������������������������������������\n");
	printf("��                       ��������ѯ(1940-2040)                                  ��\n");
	printf("��             1 ����һ����ݣ���ѯ���������                                   ��\n");
	printf("��             2 ����һ����ݺ��·ݣ���ѯ������µ�����                         ��\n");
	printf("��             3 ���������գ���ѯ�������ջ��ж����죬���ڼ�                   ��\n");
	printf("��             4 �˳�                                                           ��\n");
	printf("����������������������������������������������������������������������������������\n");
	printf("��ѡ��");
}

/*********************************************************************************************/
/* �������ܣ�����һ����ݣ��жϸ����ǲ�������                                                */
/* ����������Ҫ��ѯ����                                                                      */
/*********************************************************************************************/
bool isleapYear( int year )
{
	if( ( year % 4 == 0 && year % 100 != 0 ) || ( year % 400 == 0 ) )
	{
		return true;
	}
	else
	{
		return false;
	}
}
/*********************************************************************************************/
/* �������ܣ���ӡ����ͷ��                                                                    */
/* ������������                                                                              */
/*********************************************************************************************/
void print_header()
{
	printf("  SUN  MON  TUE  WED  THU  FRI  SAT");
}

/*********************************************************************************************/
/* �������ܣ�����ĳһ�������ڼ�                                                              */
/* ����������Ҫ�����������                                                                  */
/*********************************************************************************************/
int weekday( int year, int month, int day )
{
	int w = 0;
	int c = 0;

	if( month == 1 || month == 2 )
	{
		year--;
		month += 12;
	}
	
	c = year / 100;
	year = year % 100;
	w = ( year + (year / 4) + (c / 4) - 2 * c + 26 * ( month + 1) / 10 + day - 1) % 7;
	if( w < 0 )
	{
		w += 7;
	}
	return w;
}

/*********************************************************************************************/
/* �������ܣ�����һ����ݺ��·ݣ���ӡ������µ�����                                          */
/* ����������Ҫ��ѯ�������                                                                  */
/*********************************************************************************************/
void print_month( int year, int month )
{
	int days = 0;
	int w = 0;
	int i = 0;
	int k = 1;

	days = month_day[month];
	if( month == 2 )
	{
		if( isleapYear( year ) )
		{
			days += 1;
		}
	}
	w = weekday( year, month, 1 );
	
	printf("|====The calendar of Year %d month %d====|\n", year, month );
	print_header();
	printf("\n");
	for( i = 0; i < w; i++ )
	{
		printf("     ");
	}
	for( i = 0; w + i < 7; i++ )
	{
		printf("%5d", k);
		k++;
	}
	while( k <= days )
	{
		printf("\n");
		i = 0;
		while( i < 7 && k <= days )
		{
			printf("%5d", k);
			i++;
			k++;
		}
	}
	printf("\n|========================================|\n");
}

/*********************************************************************************************/
/* �������ܣ�����һ����ݣ���ӡ���������                                                    */
/* ����������Ҫ��ѯ�����                                                                    */
/*********************************************************************************************/
void print_year( int year )
{
	int days1 = 0;
	int days2 = 0;
	int m = 1;
	int w1 = 0;
	int w2 = 0;
	int i = 0;
	int j = 0;
	int k1 = 1;
	int k2 = 1;

	printf("|===============================The calendar of Year %d===============================|", year );
	
	while( m <= 6 )
	{
		days1 = month_day[m];
		days2 = month_day[m + 6];
		k1 = k2 = 1;
		printf("\n");
		if( m == 2 )
		{
			if( isleapYear( year ) )
			{
				days1 += 1;
			}
		}
		w1 = weekday( year, m, 1 );
		w2 = weekday( year, m + 6, 1 );
		printf("  %3d", m);
		print_header();
		printf("%10d", m + 6);
		print_header();
		printf("\n     ");
		for( i = 0; i < w1; i++ )
		{
			printf("     ");
		}
		for( i = 0; w1 + i < 7; i++ )
		{
			printf("%5d", k1);
			k1++;
		}
		printf("          ");
		for( j = 0; j < w2; j++ )
		{
			printf("     ");
		}
		for( i = 0; w2 + i < 7; i++ )
		{
			printf("%5d", k2);
			k2++;
		}
		while( k1 <= days1 || k2 <= days2 )
		{
			printf("\n");
			i = 0;
			printf("     ");
			while( i < 7 && k1 <= days1 )
			{
				printf("%5d", k1);
				i++;
				k1++;
			}
			for(; i < 7; i++ )
			{
				printf("     ");
			}
			printf("     ");
			i = 0;
			printf("     ");
			while( i < 7 && k2 <= days2 )
			{
				printf("%5d", k2);
				i++;
				k2++;
			}
		}
		m++;
	}
	printf("\n|========================================================================================|\n");
}

/*********************************************************************************************/
/* �������ܣ�����һ�������գ���ӡ�������ջ��ж����죬���ڼ�                                */
/* ����������Ҫ��ѯ��������                                                                  */
/*********************************************************************************************/
int To_today( int year, int month, int day )
{
	int days = 0;
	int i = 1;

	if( year < 2013 || ( year == 2013 && month <= 7 && day <= 26 ) )
	{
		printf("The day was past!\n");
		while( year < 2012 )
		{
			if( isleapYear( year ) )
			{
				days += 366;
			}
			else
			{
				days += 365;
			}
			year++;
		}
		//����Ϊ2012��
		if( year == 2012 )
		{
			days += month_day[month] - day;
			month++;
			while( month <= 12 )
			{
				days += month_day[month];
				if( month == 2 )
				{
					days++;
				}
				month++;
			}
			for( i = 1; i < 7; i++ )
			{
				days += month_day[i];
				if( i == 2 )
				{
					days++;
				}
			}
			days += 26;
			return days;
		}
		//����Ϊ2013�굫�����ڽ���
		else
		{
			if( month < 7 )
			{
				days += month_day[month] - day;
				month++;
				while( month < 7 )
				{
					days += month_day[month];
					if( month == 2 )
					{
						days++;
					}
					month++;
				}
				days += 26;
				return days;
			}
			else
			{
				days += 26 - day;
				return days;
			}
		}
	}
	else
	{
		printf("The day is not arrrived!\n");
		//������Ϊ2013��7��30�յȣ�ֻ���������ڵ�ǰ���ڵ�
		if( year == 2013 && month == 7 && day > 26 )
		{
			days += day - 26;
			return days;
		}
		//������Ϊ2013��9��22�ȣ�ֻ���º��������ڵ�ǰ���ڵ�
		else if( year == 2013 && month > 7 )
		{
			days += month_day[7] - 26;
			days += day;
			month--;
			while( month > 7 )
			{
				days += month_day[i];
				/*if( i == 2 )
				{
					days++;
				}*/
				month--;
			}
			return days;	
		}
		//������Ϊ2015��2��21�յȣ�����ڵ�ǰ����ʱ
		else
		{
			//���ϴ�7��26��12��31�յ�����
			days += month_day[7] - 26;
			for( i = 9; i <= 12; i++ )
			{
				days += month_day[i];
			}
			//�����ڴ���2014���ʱ�򣬻��м��ϵ�ǰ���ǰһ�굽2014���������
			while( year > 2014 )
			{
				if( isleapYear( year - 1 ) )
				{
					days += 366;
				}
				else
				{
					days += 365;
				}
				year--;
			}
			//�������ڴ���2014����º��յ�����
			for( i = 1; i < month; i++ )
			{
				days += month_day[i];
			}
			days += day;
			return days;
		}
	}
}

/*********************************************************************************************/
/* �������ܣ�����һ�������գ���ӡ�������ջ��ж����죬���ڼ�                                */
/* ����������Ҫ��ѯ��������                                                                  */
/*********************************************************************************************/
void print_day( int year, int month, int day )
{
	int w = -1;
	int dep = 0;

	w = weekday( year, month, day );
	dep = To_today( year, month, day );
	printf("The day you input is apart from today %d. ", dep);
	switch( w )
	{
		case 0:
			printf("Today is Sunday!\n");
		break;
		case 1:
			printf("Today is Monday!\n");
		break;
		case 2:
			printf("Today is Tuesday!\n");
		break;
		case 3:
			printf("Today is Wednesday!\n");
		break;
		case 4:
			printf("Today is Thursday!\n");
		break;
		case 5:
			printf("Today is Friday!\n");
		break;
		case 6:
			printf("Today is Saturday!\n");
		break;
	}
}