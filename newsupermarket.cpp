#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#include<regex>
#include<Windows.h>
#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<iostream>
#include<errno.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")
#include<easyx.h>
#include<assert.h>
using namespace std;
struct mail
{
	char email[20];
};
struct save
{
	char username[20];
	char password[12];
};
struct ima
{
	int id;//商品编号
	char name[20];//商品名字
	char produce[30];//商品产地
	int number;//商品数量
	float price;//商品价格（单价）
	int year;
	int mouth;
	int day;
	int hour;
	int minute;
	int second;
	int endday;
};
struct color
{
	int color;
};
struct imb
{
	int id1;//编号
	char zhiwei[20];//职位
	char name[20];//名字
	int  qq;//工钱
};

struct vip
{
	int vipid;//会员ID
	double integral;//会员所得积分
};
typedef struct button
{
	int x;
	int y;
	int h;
	int w;
	COLORREF color;
	char* text;
}BUTTON, * LPBUTTON;

void Buy();//购买
void Append();//录入
void menu();//菜单
void Browse();//浏览
void Change();//修改
void delegoods();//删除
void Endprogram();//退出
void Findin();//查询
int validateID(int _id);//验证
bool checkemail(char* email);
int det(char* email);
int panduan(char* email);
void emailbackpassword();
void menu2();
void menu3();
int FindID(int ID);
void vipmenu();
void IDbrowse();
void IDfindin();
void IDappend();//添加会员ID
int validatevipID(int _id);
void goodsday();
int picture();
void colormenu1();
int color();
void Money();//员工工资
int validateRYID(int _IDD);//员工编号判断
int music();



void vipmenu()//菜单
{
	system("cls");
	int choice;
	printf("\n\t1=====================【           1.ID录入         】\n");
	printf("\n\t2=====================【           2.ID浏览         】\n");
	printf("\n\t3=====================【           3.ID查询         】\n");
	printf("\n\t4=====================【           4.主菜单         】\n");
	printf("\n\t请输入您要选择的菜单......");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		IDappend();
		break;
	case 2:
		IDbrowse();
		break;
	case 3:
		IDfindin();
		break;
	case 4:
		system("cls");
		menu3();
		break;
	default:
		printf("\n\t\t\t\t\t输入无效，请您重新输入......");
		_getch();
		system("cls");
		vipmenu();
	}
}

int picture()
{
	printf("请扫描下方二维码:");
	system("pause");
	initgraph(600, 600);
	IMAGE picture;
	loadimage(&picture, "erweima.png", 600, 600);
	putimage(0, 0, &picture);
	_getch();
	closegraph();
	return 0;
}

void goodsday()
{
	char choice;
	char choice1;
	int index = 0;
	int leap;
	int i = 0;
	int n = 0;
	time_t now = time(NULL);
	struct tm* p;
	p = localtime(&now);
	struct ima z;
	FILE* fp;
	fp = fopen("GOODS", "r");
	if (fp == NULL)
	{
		printf("%s", strerror(errno));
		exit(0);
	}
	fread(&z, sizeof(struct ima), 1, fp);
	while (!feof(fp))
	{
		index++;//第几件商品的信息
		printf("\n\n\t****************物品信息%d*****************", index);
		printf("\n\t物品编号...%30d\n", z.id);
		printf("\n\t-----------------------------------------");
		printf("\n\t物品名称...%30s\n", z.name);
		printf("\n\t-----------------------------------------");
		printf("\n\t生产厂家...%30s\n", z.produce);
		printf("\n\t-----------------------------------------");
		printf("\n\t进口数量...%30d\n", z.number);
		printf("\n\t-----------------------------------------");
		printf("\n\t批发价格...%30g\n", z.price);
		printf("\n\t-----------------------------------------");
		printf("\n\t物品的生产日期...%30d-%2d-%2d", z.year, z.mouth, z.day);
		printf("\n\t-----------------------------------------");
		printf("\n\t物品的保质期天数...%30d\n", z.endday);
		printf("\n\t-----------------------------------------");
		_getch();
		if (z.year == p->tm_year + 1900)
		{
			switch (z.mouth)
			{
			case 1:i = z.day;
				break;
			case 2:i = z.day + 31;
				break;
			case 3:i = z.day + 59;
				break;
			case 4:i = z.day + 90;
				break;
			case 5:i = z.day + 120;
				break;
			case 6:i = z.day + 151;
				break;
			case 7:i = z.day + 181;
				break;
			case 8:i = z.day + 212;
				break;
			case 9:i = z.day + 243;
				break;
			case 10:i = z.day + 273;
				break;
			case 11:i = z.day + 304;
				break;
			case 12:i = z.day + 334;
				break;
			default:
				break;
			}
			if ((z.year % 4 == 0 && z.year % 100 != 0) || (z.year % 400 == 0))
			{
				leap = 1;
			}
			else
			{
				leap = 0;
			}
			if (leap == 1 && z.mouth > 2)
			{
				i++;
			}
			if (z.endday >= p->tm_yday - i)
			{
				printf("没有过期!\n");
			}
			else
			{
				printf("商品已经过期了!\n");

			}
		}
		if (z.year > p->tm_year + 1900)
		{
			printf("商品未过期！\n");
		}
		if (z.year < p->tm_year + 1900)
		{
			if (p->tm_year + 1900 - z.year >= 1)
			{
				switch (z.mouth)
				{
				case 1:i = z.day;
					break;
				case 2:i = z.day + 31;
					break;
				case 3:i = z.day + 59;
					break;
				case 4:i = z.day + 90;
					break;
				case 5:i = z.day + 120;
					break;
				case 6:i = z.day + 151;
					break;
				case 7:i = z.day + 181;
					break;
				case 8:i = z.day + 212;
					break;
				case 9:i = z.day + 243;
					break;
				case 10:i = z.day + 273;
					break;
				case 11:i = z.day + 304;
					break;
				case 12:i = z.day + 334;
					break;
				default:
					break;
				}
				if ((z.year % 4 == 0 && z.year % 100 != 0) || (z.year % 400 == 0))
				{
					leap = 1;
				}
				else
				{
					leap = 0;
				}
				if (leap == 1 && z.mouth > 2)
				{
					i++;
				}
				if (p->tm_year + 1900 - z.year == 1)
				{
					n = p->tm_yday + 365 - i;
				}
				else
				{
					n = p->tm_yday + 365 * (p->tm_year + 1900 - z.year - 1) + 365 - i;
				}
				if (z.endday >= n)
				{
					printf("没有过期!\n");
				}
				else
				{
					printf("商品已经过期了!\n");
				}
			}
		}
		fread(&z, sizeof(struct ima), 1, fp);
	}
	printf("是否需要删除商品?(Y/N)\n");
	scanf(" %c", &choice1);
	if (choice1 == 'y' || choice1 == 'Y')
	{
		delegoods();
	}
	fclose(fp);
	printf("你还要继续吗\n");
	printf("请输入你的选择(Y/N):>");
	scanf(" %c", &choice);
	if (choice == 'y' || choice == 'Y')
	{
		goodsday();
	}
	else
	{
		printf("请按任意键继续:\n");
		_getch();
		system("cls");
		menu3();
	}
}

void IDbrowse()
{
	struct vip c;
	int index = 0;
	char choice;
	FILE* fp;
	fp = fopen("IDinformation", "r");
	if (fp == NULL)
	{
		printf("\t\t\t系统错误，请您重试........");
		exit(0);
	}
	fread(&c, sizeof(struct vip), 1, fp);
	while (!feof(fp))
	{
		index++;
		printf("\n\n\t****************编号信息*****************");
		printf("\n\t...%30d\n", c.vipid);
		printf("\n\t-----------------------------------------");
		printf("\n\n\t****************当前积分*****************");
		printf("\n\t...%30lf\n", c.integral);
		printf("\n\t-----------------------------------------");
		_getch();
		fread(&c, sizeof(struct vip), 1, fp);
	}
	fclose(fp);
	printf("\n您想继续吗?(y/n)");
	scanf(" %c", &choice);
	if (choice == 'Y' || choice == 'y')
	{
		IDbrowse();
	}
	else
	{
		system("cls");
		vipmenu();
	}

}

void IDfindin()
{
	struct vip d;
	int findid;
	char choice;
	FILE* fp;
Flag:
	fp = fopen("IDinformation", "r");
	if (fp == NULL)
	{
		printf("\t\t\t系统错误，请您重试........");
		exit(0);
	}

	printf("请输入查询编号:");
	scanf("%d", &findid);
	fread(&d, sizeof(struct vip), 1, fp);//读文件的数据
	while (!feof(fp))
	{
		if (d.vipid == findid)//如果相等找到了
		{
			printf("此ID存在\n");
			printf("\n\t-----------------------------------------");
			printf("\n您想继续吗?(y/n)");
			scanf(" %c", &choice);
			if (choice == 'Y' || choice == 'y')
			{
				IDfindin();
			}
			else
			{
				system("cls");
				vipmenu();
			}

		}
		fread(&d, sizeof(struct vip), 1, fp);//没有找到再读下一个
	}
	fclose(fp);//关闭文件
	printf("此ID不存在，请重新输入:");//表示都没找到
	goto Flag;//重新跳转到输入界面


}
void menu4()
{
	printf("*****************************\n");
	printf("****1.不修改   2.修改名字****\n");
	printf("****3.修改产地 4.修改数量****\n");
	printf("****5.修改价格 6.修改全部****\n");
	printf("*****************************\n");
}

void Buy()
{
	struct vip s = {};
	struct ima e;
	int find_id;//查询的标号
	double price = 0;//购买总价
	double gopr = 0;//商品单价
	int num1 = 0;//购买商品个数
	char choice;
	int ID;
	double pay = 0;
	char ch, ch1;
	FILE* fp1;
	//	FILE* fp2;
Flag:
	fp1 = fopen("GOODS", "r");//以读的方式打开文件
	//	fp2 = fopen("IDinformation", "w");
	if (fp1 == NULL)
	{
		printf("\t\t\t系统错误，请您重试........");
		exit(0);
	}

Buy:
	printf("请输入购买编号:");
	scanf("%d", &find_id);
	fread(&e, sizeof(struct ima), 1, fp1);//读文件的数据
	while (!feof(fp1))
	{
		if (e.id == find_id)//如果相等找到了
		{
			num1 = 0;
			printf("一共有几件此商品？");
			scanf("%d", &num1);
			gopr = e.price;
			gopr = gopr * num1;
			price += gopr;
			printf("\n您想继续吗?(y/n)\n");
			scanf(" %c", &choice);
			if (choice == 'Y' || choice == 'y')
			{
				goto Buy;
			}
			else
			{
				printf("是否为会员？(y/n)\n");
				scanf(" %c", &ch);
				if (ch == 'Y' || ch == 'y')
				{
					printf("请输入会员id：");
					scanf("%d", &ID);
					if (FindID(ID) == 1)
					{
						price = price * 0.8;
						s.integral += price;
						printf("价格为%g元，请支付\n", price);
						picture();
					Rebuyone:
						printf("支付金额为:");
						scanf("%lf", &pay);
						if (pay >= price)
						{
							printf("找零为%g元", pay - price);
						}
						else
						{
							printf("金额不足，请重新支付");
							goto Rebuyone;
						}
					}
					else
					{
						printf("价格为%g元，请支付", price);
						picture();
					Rebuytwo:
						printf("支付金额为:");
						scanf("%lf", &pay);
						if (pay >= price)
						{
							printf("找零为%g元", pay - price);
						}
						else
						{
							printf("金额不足，请重新支付");
							goto Rebuytwo;
						}
					}
					printf("\n是否为下一位顾客购买(y/n)");
					scanf(" %c", &ch1);
					if (ch1 == 'y' || ch1 == 'Y')
					{
						Buy();
					}
					else
						system("cls");
					menu3();
				}
				else
				{
					printf("价格为%g元，请支付", price);
					picture();
				}
				printf("是否为下一位顾客购买(y/n)");
				scanf(" %c", &ch1);
				if (ch1 == 'y' || ch1 == 'Y')
				{
					Buy();
				}
				else
					system("cls");
				menu3();
			}
		}
		fread(&s, sizeof(struct ima), 1, fp1);//没有找到再读下一个
	}
	fclose(fp1);//关闭文件
	//	fclose(fp2);
	printf("此编号不存在，请重新输入:");//表示都没找到
	goto Flag;//重新跳转到输入界面
}

int FindID(int ID)
{
	struct vip d;
	int find_id;
	find_id = ID;
	int i = 0;
	int ret = 3;
	FILE* fp;
Flag:
	if (i > 0)
	{
		scanf("%d", &d.vipid);
	}
	fp = fopen("IDinformation", "r");
	if (fp == NULL)
	{
		printf("\t\t\t系统错误，请您重试........");
		exit(0);
	}
	fread(&d, sizeof(struct vip), 1, fp);
	while (!feof(fp))
	{
		if (validatevipID(d.vipid) == 1)
		{
			printf("此ID存在\n");
			printf("\n\t-----------------------------------------");
			ret = 1;
			goto Flagone;
		}
		fread(&d, sizeof(struct vip), 1, fp);
	}
	printf("此ID不存在，请重新输入:");
	i = i + 1;
	if (i < 5)
	{
		printf("你还有%d次输入机会", 5 - i);
		goto Flag;
	}
	else
	{
		printf("您已5次输入错误，将按原价购买");
		ret = 0;
	}
Flagone:
	fclose(fp);
	printf("%d\0", ret);
	return ret;
}



int validatevipID(int _id)//将输入编号的传过来
{

	FILE* fp;
	struct vip m = {};
	fp = fopen("IDinformation", "r");//读文件方式打开文件
	if (fp == NULL)
	{
		printf("\t\t\t系统错误，请您重试........");
		exit(0);//读取失败退出
	}
	fread(&m, sizeof(struct vip), 1, fp);//将文件内容读取到缓存
	while (!feof(fp))//读到文件末尾
	{
		if (m.vipid == _id)//如果相等
		{
			fclose(fp);//关闭文件
			return 1;//返回1表示编号重复
			break;//退出循环
		}
		fread(&m, sizeof(struct vip), 1, fp);//不相等就再读
	}
	fclose(fp);//如果都没读到，编号就不重复
	return 0;//返回值可以是不为1的整数

}
void IDappend()
{
	struct vip z = {};
	char choice;
	FILE* fp;
	fp = fopen("IDinformation", "ab");
	if (fp == NULL)
	{
		printf("\t\t\t系统错误，请您重试........");
		exit(0);
	}
labID:
	printf("\n\t请您添加会员ID\n");
	printf("\t\t\t\t   会员ID:");
	scanf(" %d", &z.vipid);
	if (validatevipID(z.vipid) == 1)
	{
		printf("\t\t\t\t此编号已被使用，请您重新输入......");
		goto labID;
	}
	fwrite(&z, sizeof(struct vip), 1, fp);
	fclose(fp);
	printf("\t\t\t\t\t\t  信息已入库成功!!!\n");
	printf("\n您想继续吗?(y/n)");
	scanf(" %c", &choice);
	if (choice == 'Y' || choice == 'y')
	{
		IDappend();
	}
	else
	{
		system("cls");
		vipmenu();
	}

}

void menu2()
{
	printf("\n\n");
	system("color 07");//color 1a  1是背景颜色 a是字体颜色
	printf("\t\3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3\n");
	printf("\t\3                                                               \3\n");
	printf("\t\3                                                               \3\n");
	printf("\t\3                        欢迎使用                               \3\n");
	printf("\t\3                                                               \3\n");
	printf("\t\3                                                               \3\n");
	printf("\t\3                     超市库存管理系统                          \3\n");
	printf("\t\3                      按任意键继续                             \3\n");
	printf("\t\3                                                               \3\n");
	printf("\t\3                                                               \3\n");
	printf("\t\3                                                               \3\n");
	printf("\t\3                                                               \3\n");
	printf("\t\3                                                               \3\n");
	printf("\t\3                                                               \3\n");//\3转义字符此编译器为框
	printf("\t\3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3");
	_getch();//引用头文件conio.h  输入一个字符，不被看见
	system("cls");//清屏头文件stdlib.h
	menu3();//调用菜单
}
void menu3()
{
	int choice;
	printf("\n∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞【超市库存管理系统】∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞\n");
	printf("--------------------------------系统菜单显示如下--------------------------------");
	printf("\n\t1=====================【           新购物品入库         】\n");
	printf("\n\t2=====================【           物品信息浏览         】\n");
	printf("\n\t3=====================【           物品信息查询         】\n");
	printf("\n\t4=====================【           物品信息修改         】\n");
	printf("\n\t5=====================【          物品信息删除         】\n");
	printf("\n\t6=====================【           物品保质期管理         】\n");
	printf("\n\t7=====================【           商品购买         】\n");
	printf("\n\t8=====================【           会员服务         】\n");
	printf("\n\t9=====================【           人员信息管理       】\n");
	printf("\n\t0=====================【           颜色修改         】\n");
	printf("\n\t11====================【           退出         】\n");
	printf("\n\t12====================【           音乐         】\n");


	printf("\n\t请输入您要选择的菜单......");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		Append();//增加商品
		break;
	case 2:
		Browse();//浏览商品信息
		break;
	case 3:
		Findin();//查找商品信息
		break;
	case 4:
		Change();//修改商品信息
		break;
	case 5:
		delegoods();//删除商品信息
		break;
	case 11:
		Endprogram();//退出管理系统
		break;
	case 8:
		vipmenu();
		break;
	case 7:
		Buy();
		break;
	case 6:
		goodsday();
		break;
	case 0:
		color();
		break;
	case 9:
		Money();
		break;
	case 12:
		music();
		break;
	default:
		printf("\n\t\t\t\t\t输入无效，请您重新输入......");
		_getch();
		system("cls");
		menu3();//任意字符到菜单
	}
}
int validateID(int _id)//将输入编号的传过来
{

	FILE* fp;
	struct ima v;
	fp = fopen("GOODS", "r");//读文件方式打开文件
	if (fp == NULL)
	{
		printf("\t\t\t系统错误，请您重试........");
		exit(0);//读取失败退出
	}
	fread(&v, sizeof(struct ima), 1, fp);//将文件内容读取到缓存
	while (!feof(fp))//读到文件末尾
	{
		if (v.id == _id)//如果相等
		{
			fclose(fp);//关闭文件
			return 1;//返回1表示编号重复
			break;//退出循环
		}
		fread(&v, sizeof(struct ima), 1, fp);//不相等就再读
	}
	fclose(fp);//如果都没读到，编号就不重复
	return 0;//返回值可以是不为1的整数

}

void Findin()//查找
{
	struct ima f;
	int find_id;//查询的标号
	char choice;
	FILE* fp;
Flag:
	fp = fopen("GOODS", "r");//以读的方式打开文件
	if (fp == NULL)
	{
		printf("\t\t\t系统错误，请您重试........");
		exit(0);
	}

	printf("请输入查询编号:");
	scanf("%d", &find_id);
	fread(&f, sizeof(struct ima), 1, fp);//读文件的数据
	while (!feof(fp))
	{
		if (f.id == find_id)//如果相等找到了
		{
			printf("\n\n\t***************物品信息******************");//打印相应的数据
			printf("\n\t物品编号...%30d\n", f.id);
			printf("\n\t-----------------------------------------");
			printf("\n\t物品名称...%30s\n", f.name);
			printf("\n\t-----------------------------------------");
			printf("\n\t生产厂家...%30s\n", f.produce);
			printf("\n\t-----------------------------------------");
			printf("\n\t进口数量...%30d\n", f.number);
			printf("\n\t-----------------------------------------");
			printf("\n\t批发价格...%30.3g\n", f.price);
			printf("\n\t-----------------------------------------");
			printf("\n\t物品生产日期...%30d-%3d-%3d\n", f.year, f.mouth, f.day);
			printf("\n\t-----------------------------------------");
			printf("\n\t物品的保质期天数...%30d\n", f.endday);
			printf("\n您想继续吗?(y/n)");
			scanf(" %c", &choice);
			if (choice == 'Y' || choice == 'y')
			{
				Findin();
			}
			else
			{
				system("cls");
				menu3();
			}

		}
		fread(&f, sizeof(struct ima), 1, fp);//没有找到再读下一个
	}
	fclose(fp);//关闭文件
	printf("此编号不存在，请重新输入:");//表示都没找到
	goto Flag;//重新跳转到输入界面
	menu3();

}
/*int determine(int id[]);
int determine(int id[])
{

}*/
void Change()//修改信息
{

	int i;
	int choice1;//修改的具体某一项或者全部
	char choice;
	int  name;//修改的编号名
	int findex = 0;//判断是否有该商品，没有就是0，有为1
	struct ima c[30];//创建结构体数组一个一个拿到结构体里面的数据
	struct ima temp;//创建临时变量拿到c里面的值
	int index = 0;//数组从c[index]即从c[0]开始
	FILE* fp;
	fp = fopen("GOODS", "r");//以读的方式打开文件
	if (fp == NULL)
	{
		printf("%s", strerror(errno));
		exit(0);
	}
	fread(&temp, sizeof(struct ima), 1, fp);//读文件信息到temp中
	while (!feof(fp))//读到文件末尾
	{
		c[index] = temp;//将每一次temp中的数据放入c中
		index++;
		fread(&temp, sizeof(struct ima), 1, fp);//继续读文件
	}
	fclose(fp);//读完关闭文件
ref1:
	printf("请输入要修改的编号:");//开始修改
modify:
	findex = 0;
	scanf("%d", &name);//输入编号

	if (validateID(name) == 0)//验证编号是否存在
	{
		printf("\t\t\t\t没有此编号，请您重新输入......");
		goto ref1;//goto语句跳转
	}

	fp = fopen("GOODS", "w");//以写入的方式打开文件
	menu4();
	printf("请选择你要修改的内容:");
	scanf(" %d", &choice1);//选择菜单1
	for (i = 0; i < index; i++)//i<index是到读到的个数
	{
		if (name == c[i].id)//如果编号相同
		{
			findex = 1;//表示有数据
			if (choice1 == 1)
			{
				fwrite(&c[i], sizeof(struct ima), 1, fp);//将修改内容写入文件
			}

			if (choice1 == 2)
			{
				printf("原名字为%s\n", c[i].name);
				printf("请输入新的名字是:");
				scanf("%s", c[i].name);
				fwrite(&c[i], sizeof(struct ima), 1, fp);
				printf("名字修改成功!\n");
			}
			if (choice1 == 3)
			{
				printf("原产地为%s\n", c[i].produce);
				printf("请输入新的产地:");
				scanf("%s", c[i].produce);
				fwrite(&c[i], sizeof(struct ima), 1, fp);
				printf("产地修改成功!\n");
			}
			if (choice1 == 4)
			{
				printf("原数量为%d\n", c[i].number);
				printf("请输入新的数量:");
				scanf("%d", &c[i].number);
				fwrite(&c[i], sizeof(struct ima), 1, fp);
				printf("数量修改成功!\n");
			}
			if (choice1 == 5)
			{
				printf("原价格为%f\n", c[i].price);
				printf("请输入新的价格:");
				scanf("%f", &c[i].price);
				fwrite(&c[i], sizeof(struct ima), 1, fp);
				printf("价格修改成功!\n");
			}

			if (choice1 == 6)
			{
				/*ref4:
								printf("请输入新的编号是:");
								scanf("%d", &c[i].id);
								if (c[i].id==name)
									goto ref5;
								if (validateID(c[i].id)==1)
								 {
									 printf("----输入的编号已存在，请重新输入....\n");
									 goto ref4;
								 }
				ref5:*/
				printf("原名字为%s\n", c[i].name);
				printf("请输入新的名字是:");
				scanf("%s", c[i].name);
				printf("原产地为%s\n", c[i].produce);
				printf("请输入新的产地是:");
				scanf("%s", c[i].produce);
				printf("原数量为%d\n", c[i].number);
				printf("请输入新的数量是:");
				scanf("%d", &c[i].number);
				printf("原价格为%f\n", c[i].price);
				printf("请输入新的价格:");
				scanf("%f ", &c[i].price);
				fwrite(&c[i], sizeof(struct ima), 1, fp);//修改的全部写入
				printf("所有修改成功!\n");
			}
		}
		else
		{
			//fp = fopen("GOODS", "w");//以写入的方式打开文件
			fwrite(&c[i], sizeof(struct ima), 1, fp);//其他的信息不变
		}
	}
	if (findex == 0)
	{
		printf("没有该商品信息\n");
		printf("请重新输入编号\n");
		goto modify;//重新跳转到输入
	}
	fclose(fp);//关闭文件
	printf("你还要继续修改吗\n");
	printf("请选择(y/n)>:");
	scanf(" %c", &choice);
	if (choice == 'Y' || choice == 'y')
	{
		Change();
	}
	else
	{
		system("cls");
		menu3();
	}
	menu3();
}
void Append()//录入
{
	struct ima a;
	char choice;
	FILE* fp;
	fp = fopen("GOODS", "ab");//以ab追加方式打开文件
	if (fp == NULL)//如果打开文件为空
	{
		printf("\t\t\t系统错误，请您重试........");//打开失败
		exit(0);//退出  头文件stdlib.h
	}
labID:
	printf("\n\t请您输入要入库物品的信息...\n");
	printf("\t\t\t\t   物品的编号:");
	scanf("%d", &a.id);//判断输入的和录入的编号是否重复
	if (validateID(a.id) == 1)//验证编号是否重复，重复重新输入
	{
		printf("\t\t\t\t此编号已被使用，请您重新输入......");
		goto labID;//goto语句跳转
	}
	printf("\t\t\t\t   物品的名称:");
	scanf("%s", a.name);
	printf("\t\t\t\t   物品的生产地:");
	scanf("%s", a.produce);
	printf("\t\t\t\t   物品的数量:");
	scanf("%d", &a.number);
	printf("\t\t\t\t   物品的单价:");
	scanf("%f", &a.price);
	printf("\t\t\t\t   物品的生产日期:");
	scanf("%d%d%d", &a.year, &a.mouth, &a.day);
	printf("\t\t\t\t   物品的保质期天数:");
	scanf("%d", &a.endday);
	fwrite(&a, sizeof(struct ima), 1, fp);//写入方式到文件
	fclose(fp);//关闭文件
	printf("\t\t\t\t\t\t  物品信息已入库成功!!!\n");

	printf("\n您想继续吗?(y/n)");
	scanf(" %c", &choice);
	if (choice == 'Y' || choice == 'y')
	{
		Append();//继续递归调用
	}
	else
	{
		system("cls");
		menu3();//清屏后调用菜单
	}
	menu3();
}
void Browse()//浏览
{
	struct ima b;
	int index = 0;
	char choice;
	FILE* fp;
	fp = fopen("GOODS", "r");
	if (fp == NULL)
	{
		printf("\t\t\t系统错误，请您重试........");
		exit(0);
	}
	fread(&b, sizeof(struct ima), 1, fp);
	while (!feof(fp))
	{
		index++;//第几件商品的信息
		printf("\n\n\t****************物品信息%d*****************", index);
		printf("\n\t物品编号...%30d\n", b.id);
		printf("\n\t-----------------------------------------");
		printf("\n\t物品名称...%30s\n", b.name);
		printf("\n\t-----------------------------------------");
		printf("\n\t生产厂家...%30s\n", b.produce);
		printf("\n\t-----------------------------------------");
		printf("\n\t进口数量...%30d\n", b.number);
		printf("\n\t-----------------------------------------");
		printf("\n\t批发价格...%30g\n", b.price);
		printf("\n\t-----------------------------------------");
		printf("\n\t物品的生产日期...%30d-%2d-%2d", b.year, b.mouth, b.day);
		printf("\n\t-----------------------------------------");
		printf("\n\t物品的保质期天数...%30d\n", b.endday);
		printf("\n\t-----------------------------------------");
		_getch();
		fread(&b, sizeof(struct ima), 1, fp);
	}
	fclose(fp);
	printf("\n您想继续吗?(y/n)");
	scanf(" %c", &choice);
	if (choice == 'Y' || choice == 'y')
	{
		Browse();
	}
	else
	{
		system("cls");
		menu3();
	}
	menu3();
}
void delegoods()//删除
{
	char choice;
	int name;
	int i;
	int index = 0;
	int findex;
	struct ima f;
	struct ima c[20];
	FILE* fp;
	fp = fopen("GOODS", "r");
	if (fp == NULL)
	{
		printf("%s", strerror(errno));
		exit(0);
	}
	fread(&f, sizeof(struct ima), 1, fp);
	while (!feof(fp))
	{
		c[index] = f;
		index++;
		fread(&f, sizeof(struct ima), 1, fp);
	}
	fclose(fp);
	printf("请输入你要删除的编号:");
dele:
	findex = 0;
	scanf("%d", &name);
	fp = fopen("GOODS", "w");//写入的方式打开文件
	for (i = 0; i < index; i++)
	{
		if (name == c[i].id)
		{
			findex = 1;
			printf("删除成功!\n");//读到了不写入，删除成功
		}
		else
		{
			fwrite(&c[i], sizeof(struct ima), 1, fp);//其他的写进去
		}
	}
	if (findex == 0)
	{
		printf("你要删除的信息不存在!\n");
		printf("请重新输入:");
		goto dele;
	}
	fclose(fp);
	printf("你还要继续吗\n");
	printf("请输入你的选择(Y/N):>");
	scanf(" %c", &choice);
	if (choice == 'y' || choice == 'Y')
	{
		delegoods();
		system("cls");
	}
	else
	{
		printf("请按任意键继续:\n");
		_getch();
		system("cls");
		menu3();
	}
	menu3();
}
void Endprogram()//退出
{
	char choice;
	system("cls");

	printf("\n\n\n\n\n\n\n\t\t\t您确定要退出系统吗?\n\n\n\t\t\t如果您想退出请按'y',其它键将返回主菜单.....");
	scanf(" %c", &choice);
	if (choice == 'Y' || choice == 'y')
	{
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t谢谢您的使用!!!");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		exit(0);
	}
	else
	{
		system("cls");
		exit(0);
	}
	//menu3();
}

void menu()
{
	printf("********************************************\n");
	printf("****1.注册                         2.登录***\n");
	printf("****3.邮箱找回密码         4.重新设置密码***\n");
	printf("*************      0.退出       ************\n");
	printf("********************************************\n");
}
int determine(char* _username);
int determine(char* _username)
{
	struct save a;
	FILE* fp;
	fp = fopen("message.txt", "r");
	if (fp == NULL)
	{
		printf("%s", strerror(errno));
		exit(0);
	}
	fread(&a, sizeof(struct save), 1, fp);
	while (!feof(fp))
	{
		if (strcmp(a.username, _username) == 0 || strcmp(a.username, _username) != 0)
		{
			return 1;
			break;
		}
		fread(&a, sizeof(struct save), 1, fp);
	}
	fclose(fp);
	return -1;

}
int determine2(char* _password);
int determine2(char* _password)
{
	struct save a;
	FILE* fp;
	fp = fopen("message.txt", "r");
	if (fp == NULL)
	{
		printf("%s", strerror(errno));
		exit(0);
	}
	fread(&a, sizeof(struct save), 1, fp);
	while (!feof(fp))
	{
		if (strcmp(a.password, _password) == 0 || strcmp(a.password, _password) != 0)
		{
			return 1;
			break;
		}
		fread(&a, sizeof(struct save), 1, fp);
	}
	fclose(fp);
	return -1;

}
void logon()
{
	int st = 0;
	struct save a = {};
	FILE* fp;
	fp = fopen("message.txt", "ab");
	if (fp == NULL)
	{
		printf("%s", strerror(errno));
		exit(0);
	}
	printf("请输入你要存入的20位数以下的账号:");
	scanf("%s", a.username);
	if (determine(a.username) == 1)
	{
		printf("你已经注册过该账号!\n");
	}
	else
	{
		fwrite(&a, sizeof(struct save), 1, fp);
	}
	printf("请输入你要设置的12位数以下的密码:");
	scanf("%s", a.password);
	if (determine2(a.password) == 1)
	{
		printf("你已经注册过该密码!\n");
	}
	else
	{
		fwrite(&a, sizeof(struct save), 1, fp);
		fclose(fp);
	}
	struct mail e = {};
	FILE* fp1;
	fp1 = fopen("email.txt", "ab");
	if (fp1 == NULL)
	{
		printf("%s", strerror(errno));
		exit(0);
	}
st:
	printf("请输入你要预留的邮箱:");
	scanf("%s", e.email);
	if (checkemail(e.email))
	{
		if (panduan(e.email) == 1)
		{
			printf("你已经预留了邮箱!\n");
		}
		else
		{
			fwrite(&e, sizeof(struct mail), 1, fp1);
			printf("录入成功!\n");
		}
	}
	else
	{
		printf("不是邮箱\n");
		goto st;
	}
	fclose(fp1);
}
bool checkemail(char* email)
{
	regex object("^\\w+([-+.]\\w+)*@\\w+([-.]\\w+)*\\.\\w+([-.]\\w+)*$");
	bool result = regex_match(email, object);
	return result;
}
int det(char* email)
{
	struct mail b1 = {};
	FILE* fp;
	fp = fopen("email.txt", "r");
	if (fp == NULL)
	{
		printf("%s", strerror(errno));
		exit(0);
	}
	fread(&b1, sizeof(struct mail), 1, fp);
	while (!feof(fp))
	{
		if (strcmp(email, b1.email) == 0)
		{
			fclose(fp);
			return 1;
		}
		fread(&b1, sizeof(struct mail), 1, fp);
	}
	fclose(fp);
	return -1;
}
int panduan(char* email)
{
	FILE* fp;
	struct mail c = {};
	fp = fopen("email.txt", "r");
	if (fp == NULL)
	{
		printf("%s\n", strerror(errno));
		exit(0);
	}
	fread(&c, sizeof(struct mail), 1, fp);
	while (!feof(fp))
	{
		if (strcmp(c.email, email) == 0 || strcmp(c.email, email) != 0)
		{
			fclose(fp);
			return 1;
		}
		fread(&c, sizeof(struct mail), 1, fp);
	}
	fclose(fp);
	return -1;
}
void syswindows()
{
	system("title 账号验证");
//	system("color 1a");
	system("mode con cols=54 lines=8");
}
void proc()
{
	int i = 0;
	int j;
	string str("■");
	for (j = 0; j <= 25; j++)
	{
		system("cls");
		cout << str << endl;
		cout << j * 4 << "%" << endl;
		if (i >= 0 && i < 4)
		{
			system("color FA");
		}
		if (i >= 4 && i < 8)
		{
			system("color FB");
		}
		if (i >= 8 && i < 12)
		{
			system("color FC");
		}
		if (i >= 12 && i < 16)
		{
			system("color FD");
		}
		if (i >= 16 && i < 20)
		{
			system("color FE");
		}
		if (i >= 20 && i < 24)
		{
			system("color FF");
		}
		if (i >= 24 && i < 28)
		{
			system("color F0");
		}
		if (i >= 28 && i < 32)
		{
			system("color F1");
		}
		if (i >= 32 && i < 36)
		{
			system("color F2");
		}
		if (i >= 36 && i < 40)
		{
			system("color F3");
		}
		if (i >= 40 && i < 44)
		{
			system("color F4");
		}
		if (i >= 44 && i < 48)
		{
			system("color F5");
		}
		if (i >= 48 && i < 52)
		{
			system("color F6");
		}
		if (i >= 52 && i < 56)
		{
			system("color F7");
		}
		if (i >= 56 && i < 60)
		{
			system("color F8");
		}
		if (i >= 60 && i < 64)
		{
			system("color F9");
		}
		if (i >= 64 && i < 68)
		{
			system("color FA");
		}
		if (i >= 68 && i < 72)
		{
			system("color FB");
		}
		if (i >= 72 && i < 76)
		{
			system("color FC");
		}
		if (i >= 76 && i < 80)
		{
			system("color FD");
		}
		if (i >= 80 && i < 84)
		{
			system("color FE");
		}
		if (i >= 84 && i < 88)
		{
			system("color FF");
		}
		if (i >= 88 && i < 92)
		{
			system("color F0");
		}
		if (i >= 92 && i < 96)
		{
			system("color F1");
		}
		if (i >= 96 && i < 100)
		{
			system("color F2");
		}
		if (i == 100)
		{
			system("color FA");
		}
		str += "■";
		i += 4;
		//Sleep(100);
	}
	system("color 1a");
	system("mode con lines=2000 cols=2000");
	menu2();
}
void signin()
{
	struct save b2 = {};
	char putusername[20] = "";
	char putpassword[12] = "";
	FILE* fp;
	syswindows();
start:
	cout << "\t用户名:";
	cin >> putusername;
	cout << "\t密码:";
	char c;
	int i = 0;
	while ((c = _getch()) != '\r')
	{
		if (i < 12)
		{
			putpassword[i++] = c;
			putchar('*');
		}
		else
		{
			cout << "\n\t";
			cout << "密码过长" << endl;
			cout << "请重新输入:";
			Sleep(500);
			system("cls");
			goto start;
		}
	}
	putpassword[i] = '\0';
	cout << endl;
	fp = fopen("message.txt", "r");
	if (fp == NULL)
	{
		printf("%s", strerror(errno));
		exit(0);
	}
	fread(&b2, sizeof(struct save), 1, fp);
	while (!feof(fp))
	{
		if (!strcmp(b2.username, putusername) && !strcmp(b2.password, putpassword))
		{
			proc();
		}
		else
		{
			cout << "用户名或密码错误" << endl;
		}
		fread(&b2, sizeof(struct save), 1, fp);
	}
	fclose(fp);
	system("pause");
	system("mode con cols=1200 lines=1200");
	system("color 1a");
	menu();
}
void menu1()
{
	printf("****************************\n");
	printf("***1.修改用户名 2.修改密码**\n");
	printf("***3.修改全部            ***\n");
}
void repeatsetpassword()
{
	char choice1;
	int findex;
	char yusername[21] = "";
	char ypassword[13] = "";
	int choice;
	FILE* fp;
	int index = 0;
	struct save e[20] = {};
	struct save temp;
	fp = fopen("message.txt", "r");
	if (fp == NULL)
	{
		printf("%s", strerror(errno));
		exit(0);
	}
	fread(&temp, sizeof(struct save), 1, fp);
	while (!feof(fp))
	{
		e[index] = temp;
		index++;
		fread(&temp, sizeof(struct save), 1, fp);
	}
	fclose(fp);
choicey:
	printf("请输入原来的用户名:");
	findex = 0;
	scanf(" %s", yusername);
	printf("\n");
	getchar();
	printf("请输入原来的密码:");
	scanf(" %s", ypassword);
	getchar();
	printf("\n");
	fp = fopen("message.txt", "w");
	menu1();
	printf("请选择你要修改的内容:");
	scanf("%d", &choice);
	for (int i = 0; i < index; i++)
	{
		if ((strcmp(yusername, e[i].username) == 0) && (strcmp(ypassword, e[i].password) == 0))
		{
			findex = 1;
			if (choice == 1)
			{
				printf("请输入新的用户名:");
				scanf("%s", e[i].username);
				fwrite(&e[i], sizeof(struct save), 1, fp);
				printf("用户名修改成功!\n");
			}
			if (choice == 2)
			{
				printf("请输入新的密码:");
				scanf("%s", e[i].password);
				fwrite(&e[i], sizeof(struct save), 1, fp);
				printf("密码修改成功!\n");
			}
			if (choice == 3)
			{
				printf("请输入新的用户名:");
				scanf("%s", e[i].username);
				printf("请输入新的密码:");
				scanf("%s", e[i].password);
				fwrite(&e[i], sizeof(struct save), 1, fp);
				printf("所有都修改成功!\n");
			}
		}
		else
		{
			fwrite(&e[i], sizeof(struct save), 1, fp);
		}
	}
	if (findex == 0)
	{
		printf("没有此用户名或密码\n");
		printf("请重新输入用户名或密码\n");
		goto choicey;
	}
	fclose(fp);
	printf("你还要继续修改吗\n");
	printf("请选择(Y/N)>:");
	scanf(" %c", &choice1);
	if (choice == 'Y' || choice == 'y')
	{
		repeatsetpassword();
	}
	else
	{
		system("cls");
		menu();
	}
	system("color 1a");
}
void emailbackpassword()
{
	system("title 洋少");
	system("mode con cols=53 lines=10");
	system("color 1a");
	int a1 = 0;
	char email1[20] = {};
	int ret = 1000 + rand() % 9000;
	printf("请输入你的预留邮箱:");
	scanf("%s", email1);
	if (checkemail(email1))
	{
		if (det(email1) == 1)
		{
			printf("%d\n", ret);
			printf("请输入屏幕上方验证码:");
			for (int i = 3; i >= 0; i--)
			{
				scanf("%d", &a1);
				if (a1 != ret)
				{
					printf("验证码错误\n");
					if (i > 0)
					{
						printf("你还有%d次机会", i);
					}
					else
					{
						printf("你的机会已经用完!\n");
					}
				}
				else
				{
					printf("验证成功\n");
					struct save d = {};
					FILE* fp;
					fp = fopen("message.txt", "r");
					if (fp == NULL)
					{
						printf("%s\n", strerror(errno));
						exit(0);
					}
					fread(&d, sizeof(struct save), 1, fp);
					while (!feof(fp))
					{
						fread(&d, sizeof(struct save), 1, fp);
					}
					printf("账号是:%s\n", d.username);
					printf("密码是:%s\n", d.password);
					system("pause");
					fclose(fp);
					break;
				}
			}
		}
		else
		{
			printf("验证失败!");
		}
	}
	else
	{
		printf("不是邮箱!\n");
	}
	system("mode con cols=2000 lines=2000");
	system("color 1a");
	system("pause");
}
int main()
{
	srand((unsigned int)time(NULL));
	system("color F0");
	FILE* fp;
	fp = fopen("message.txt", "r");
	struct save msg = {};
	int input = 0;
	menu();
	do
	{
		printf("请选择:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			logon();
			break;
		case 2:
			signin();
			break;
		case 3:
			emailbackpassword();
			menu();
			break;
		case 4:
			repeatsetpassword();
			break;
		case 0:
			printf("退出程序!");
			break;
		default:
			printf("请重新输入\n");
			break;
		}
	} while (input);
	system("pause");
	return 0;
}
void colormenu1()
{
	printf("color x1:为控制台的颜色\n========================\nx2:为控制台字体的颜色\n");
	printf("1====================00还原基础色\n");
	printf("基础色为下一次登录的颜色和原本不改变的颜色一致\n");
	printf("2==========================01黑蓝\n");
	printf("3==========================02黑绿\n");
	printf("4==========================04黑红\n");
	printf("5==========================05黑紫\n");
	printf("6==========================06黑黄\n");
	printf("7==========================07黑白\n");
	printf("8==========================12蓝绿\n");
	printf("9==========================14蓝红\n");
	printf("10=========================15蓝紫\n");
	printf("11=========================16蓝黄\n");
	printf("12=========================21蓝绿\n");
	printf("13=========================24绿红\n");
	printf("14=========================25绿紫\n");
	printf("15=========================26绿黄\n");
	printf("16=========================40红黑\n");
	printf("17=========================41红蓝\n");
	printf("18=========================42红绿\n");
	printf("19=========================46红黄\n");
	printf("20=========================51紫蓝\n");
	printf("21=========================52紫绿\n");
	printf("=================================\n");
}
int color()
{
	char choice;
	char choice2;
	FILE* fp1;
	fp1 = fopen("color.txt", "r");
	struct color a = {};
	if (fp1 == NULL)
	{
		exit(0);
	}
	fread(&a, sizeof(struct color), 1, fp1);

	//printf("%d", a.color);
	switch (a.color) {
	case 1:
		system("color 00");
		break;
	case 2:
		system("color 01");
		break;
	case 3:
		system("color 02");
		break;
	case 4:
		system("color 04");
		break;
	case 5:
		system("color 05");
		break;
	case 6:
		system("color 06");
		break;
	case 7:
		system("color 07");
		break;
	case 8:
		system("color 12");
		break;
	case 9:
		system("color 14");
		break;
	case 10:
		system("color 15");
		break;
	case 11:
		system("color 16");
		break;
	case 12:
		system("color 21");
		break;
	case 13:
		system("color 24");
		break;
	case 14:
		system("color 25");
		break;
	case 15:
		system("color 26");
		break;
	case 16:
		system("color 40");
		break;
	case 17:
		system("color 41");
		break;
	case 18:
		system("color 42");
		break;
	case 19:
		system("color 46");
		break;
	case 20:
		system("color 51");
		break;
	case 21:
		system("color 52");
		break;
	}
	fclose(fp1);
	printf("请问您需要设置颜色吗?\n");
	printf("请确认(Y/N):");
	scanf(" %c", &choice);
	if (choice == 'Y' || choice == 'y')
	{
		colormenu1();
		//system("pause");
		printf("请选择你想要的颜色:");
		int color;
		struct color c = {};
		// 读取保存的颜色
		FILE* fp;
		fp = fopen("color.txt", "w");
		if (fp == NULL)
		{
			exit(0);
		}
		else {
			// 设置控制台颜色
			system("color 0");
			scanf_s("%d", &color);
			fwrite(&color, sizeof(struct color), 1, fp);
			switch (color) {
			case 1:
				system("color 00");
				break;

			case 2:
				system("color 01");
				break;
			case 3:
				system("color 02");
				break;
			case 4:
				system("color 04");
				break;
			case 5:
				system("color 05");
				break;
			case 6:
				system("color 06");
				break;
			case 7:
				system("color 07");
				break;
			case 8:
				system("color 12");
				break;
			case 9:
				system("color 14");
				break;
			case 10:
				system("color 15");
				break;
			case 11:
				system("color 16");
				break;
			case 12:
				system("color 21");
				break;
			case 13:
				system("color 24");
				break;
			case 14:
				system("color 25");
				break;
			case 15:
				system("color 26");
				break;
			case 16:
				system("color 40");
				break;
			case 17:
				system("color 41");
				break;
			case 18:
				system("color 42");
				break;
			case 19:
				system("color 46");
				break;
			case 20:
				system("color 51");
				break;
			case 21:
				system("color 52");
				break;
			}
			fclose(fp);
			printf("\n");
			printf("       修改成功！      \n");
			printf("\n");
			printf("是否还要继续修改？\n");
			scanf("%c", &choice2);
			if (choice2 == 'y' || choice2 == 'Y')
			{
				colormenu1();
			}
			else
			{
				printf("请按任意键继续\n");

				//ystem("cls");
				system("cls");
				menu3();
			}




		}
	}
	else
	{
		system("cls");
		menu3();
	}
	return 0;
}


int validateRYID(int _IDD)
{
	struct imb ida;
	FILE* fp;
	fp = fopen("JIAQIAN", "r");
	if (fp == NULL)
	{
		printf("\t\t\t系统错误，请重试...");
		exit(0);//读取失败推出
	}
	fread(&ida, sizeof(struct imb), 1, fp);
	while (!feof(fp))//读取文件到末尾
	{
		if (ida.id1 == _IDD)
		{
			fclose(fp);//关闭文件
			return 1;
			break;
		}
		fread(&ida, sizeof(struct imb), 1, fp);
	}
	fclose(fp);
	return 0;

}
void Money()
{
	char nnn;
	FILE* fp;
	struct imb c;
	fp = fopen("JIAQIAN", "ab");//读文件方式打开文件
	if (fp == NULL)
	{
		printf("\t\t\t系统错误，请您重试........");
		exit(0);//读取失败退出
	}
qqID:
	printf("\n\t请输入要写入的人员信息...\n");
	printf("\t\t\t\t   人员的编号:");
	scanf("%d", &c.id1);//判断输入的和录入的编号是否重复
	if (validateRYID(c.id1) == 1)//验证编号是否重复，重复重新输入
	{
		printf("\t\t\t\t此编号已被使用，请您重新输入......");
		goto qqID;//goto语句跳转
	}
	printf("\t\t\t\t   请输入职位:");
	scanf("%s", c.zhiwei);
	printf("\t\t\t\t   请输入名字:");
	scanf("%s", c.name);
	printf("\t\t\t\t   请输入工资:");
	scanf("%d", &c.qq);
	fwrite(&c, sizeof(struct imb), 1, fp);//写入方式到文件
	fclose(fp);//关闭文件
	printf("\t\t\t\t\t\t  物品信息已入库成功!!!\n");
	printf("\n您想继续吗?(y/n)");
	scanf(" %c", &nnn);
	if (nnn == 'Y' || nnn == 'y')
	{
		Money();//继续递归调用
	}
	else
	{
		system("cls");
		menu3();//清屏后调用菜单
	}
}
LPBUTTON creatbutton(int x, int y, int w, int h, const char* str)
{
	LPBUTTON button1 = (LPBUTTON)malloc(sizeof(BUTTON));
	assert(button1);
	button1->x = x;
	button1->y = y;
	button1->h = h;
	button1->w = w;
	button1->color = RGB(224, 24, 24);
	int length = strlen(str) + 1;
	button1->text = (char*)malloc(sizeof(char) * length);
	assert(button1->text);
	strcpy_s(button1->text, length, str);
	return button1;
}
void setbutton(LPBUTTON button)
{
	setbkmode(TRANSPARENT);
	setfillcolor(button->color);
	fillrectangle(button->x, button->y, button->x + button->w, button->y + button->h);
	settextstyle(15, 0, "楷体");
	settextcolor(BLACK);
	int wet = textwidth(button->text);
	int het = textheight(button->text);
	int xx = button->x + (button->w - wet) / 2;
	int yy = button->y + (button->h - het) / 2;
	outtextxy(xx, yy, button->text);
}
int inbutton(LPBUTTON button, ExMessage m)
{
	if (m.x > button->x && m.x<button->x + button->w && m.y>button->y && m.y < button->h + button->y)
	{
		button->color = RGB(23, 233, 233);
		return 1;
	}
	else
	{
		button->color = RGB(224, 24, 24);
		return 0;
	}
}
int music()
{
	initgraph(400, 400);
	IMAGE mm;
	loadimage(&mm, "./was.jpg", 400, 400 - 25);
	LPBUTTON play = creatbutton(0, 0, 100, 25, "播放音乐");
	LPBUTTON pause = creatbutton(100, 0, 100, 25, "暂停音乐");
	LPBUTTON  resume = creatbutton(200, 0, 100, 25, "继续音乐");
	LPBUTTON close = creatbutton(300, 0, 100, 25, "关闭音乐");
	BeginBatchDraw();
	while (1)
	{
		putimage(0, 25, &mm);
		setbutton(play);
		setbutton(pause);
		setbutton(resume);
		setbutton(close);
		ExMessage m;
		peekmessage(&m, EM_MOUSE);
		if (inbutton(play, m) && m.message == WM_LBUTTONDOWN)
		{
			mciSendString("play D:\\picture\\Ikun.mp3", NULL, 0, NULL);
		}
		if (inbutton(pause, m) && m.message == WM_LBUTTONDOWN)
		{
			mciSendString("pause D:\\picture\\Ikun.mp3", NULL, 0, NULL);
		}
		if (inbutton(resume, m) && m.message == WM_LBUTTONDOWN)
		{
			mciSendString("resume D:\\picture\\Ikun.mp3", NULL, 0, NULL);
		}
		if (inbutton(close, m) && m.message == WM_LBUTTONDOWN)
		{
			mciSendString("close D:\\picture\\Ikun.mp3", NULL, 0, NULL);
		}
		FlushBatchDraw();
	}
	EndBatchDraw();
	closegraph();
	return 0;
}
