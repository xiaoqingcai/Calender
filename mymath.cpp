#include "mymath.h"
int month_day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
void menu()
{
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("┃                       万年历查询(1940-2040)                                  ┃\n");
	printf("┃             1 输入一个年份，查询该年的日历                                   ┃\n");
	printf("┃             2 输入一个年份和月份，查询该年该月的日历                         ┃\n");
	printf("┃             3 输入年月日，查询该天距今日还有多少天，星期几                   ┃\n");
	printf("┃             4 退出                                                           ┃\n");
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	printf("请选择：");
}

/*********************************************************************************************/
/* 函数功能：输入一个年份，判断该年是不是闰年                                                */
/* 函数参数：要查询的年                                                                      */
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
/* 函数功能：打印日历头部                                                                    */
/* 函数参数：无                                                                              */
/*********************************************************************************************/
void print_header()
{
	printf("  SUN  MON  TUE  WED  THU  FRI  SAT");
}

/*********************************************************************************************/
/* 函数功能：计算某一天是星期几                                                              */
/* 函数参数：要计算的年月日                                                                  */
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
/* 函数功能：输入一个年份和月份，打印该年该月的日历                                          */
/* 函数参数：要查询的年和月                                                                  */
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
/* 函数功能：输入一个年份，打印该年的日历                                                    */
/* 函数参数：要查询的年份                                                                    */
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
/* 函数功能：输入一个年月日，打印该天距今日还有多少天，星期几                                */
/* 函数参数：要查询的年月日                                                                  */
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
		//日期为2012年
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
		//日期为2013年但是早于今日
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
		//当日期为2013年7月30日等，只有天数大于当前日期的
		if( year == 2013 && month == 7 && day > 26 )
		{
			days += day - 26;
			return days;
		}
		//当日期为2013年9月22等，只有月和天数大于当前日期的
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
		//当日期为2015年2月21日等，年大于当前日期时
		else
		{
			//加上从7月26到12月31日的天数
			days += month_day[7] - 26;
			for( i = 9; i <= 12; i++ )
			{
				days += month_day[i];
			}
			//当日期大于2014年的时候，还有加上当前年的前一年到2014年的年天数
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
			//加上日期大于2014年的月和日的天数
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
/* 函数功能：输入一个年月日，打印该天距今日还有多少天，星期几                                */
/* 函数参数：要查询的年月日                                                                  */
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