#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

using namespace std;

string ord="",par;
int pingsize=10000,pingthreads=1;
string pingsite="UnSet";
int last=0;
string lan="en"; 

int sti(string a)
{
	int n=1,sum=0;
	for(int i=a.size()-1;i>=0;i--)
	{
		sum=sum+(a[i]-'0')*n;
		n=n*10;
	}
	return sum;
}

string its(int a)
{
	string s="";
	int n=10;
	while(a!=0)
	{
		s=char((a%10)+'0')+s;
		n=n*10;
		a=a/10;
	}
	return s;
 }
 
void color(bool r,bool g,bool b)
{
	HANDLE he;
	he=GetStdHandle(STD_OUTPUT_HANDLE);
	if(r==1&&g==0&&b==0)	SetConsoleTextAttribute(he,FOREGROUND_RED);
	if(r==0&&g==1&&b==0)	SetConsoleTextAttribute(he,FOREGROUND_GREEN);
	if(r==0&&g==0&&b==1)	SetConsoleTextAttribute(he,FOREGROUND_BLUE);
	if(r==1&&g==1&&b==0)	SetConsoleTextAttribute(he,FOREGROUND_RED | FOREGROUND_GREEN);
	if(r==1&&g==1&&b==1)	SetConsoleTextAttribute(he,FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	if(r==1&&g==0&&b==1)	SetConsoleTextAttribute(he,FOREGROUND_RED | FOREGROUND_BLUE);
	if(r==0&&g==1&&b==1)	SetConsoleTextAttribute(he,FOREGROUND_GREEN | FOREGROUND_BLUE);
	return;
}
 
void logo(bool model)
{
	if(model==true)
	{
		cout << "*****|---------|*****" << endl;
		cout << "     |";
	}
	color(1,1,0);
    cout << "P";
    color(0,1,1);
    cout << "I";
    color(1,0,1);
    cout << "N";
    color(1,1,1);
    cout << "G";
    cout << " "; 
    color(1,1,1);
    cout << "T";
	color(1,0,1);
	cout << "O";
	color(0,1,1);
	cout << "O";
	color(1,1,0);
	cout << "L";
	if(model==true)
	{
		color(1,1,1);
		cout << "|"<<endl;
		cout << "*****|---------|*****" << endl;
		cout << endl;
		return;
	}
	else
	{
		color(0,1,0);
		cout << " >> " ;
		color(1,1,1);
		return;
	}
}

void help()
{
	if(lan=="en")
		SetConsoleTitle("Ping-Tool # By waterblock79");
	if(lan=="ch")
		SetConsoleTitle("拼图Ping工具 # By waterblock79");
	color(0,1,1);
	if(lan=="en") 
		cout << "_____COMMEND LIST_____" << endl;
	if(lan=="ch")
		cout << "_____控制命令列表_____" << endl;
	cout << "|" << endl;
	cout << "|__";
	color(1,1,0);
	if(lan=="en")
		cout << "SET PING SIZE -- ";
	if(lan=="ch")
		cout << "设置Ping包大小 -- ";
	color(1,0,1);
	if(lan=="en")
		cout << "setsize [size]" << endl;
	if(lan=="ch")
		cout << "setsize [大小]" << endl;
	color(0,1,1);
	cout << "|" << endl;
	cout << "|__";
	color(1,1,0);
	if(lan=="en")
		cout << "SET PING WEBSITE OR IP -- ";
	if(lan=="ch")
		cout << "设置需要Ping的网址或者IP -- ";
	color(1,0,1);
	if(lan=="en")
		cout << "setip [website/ip]" << endl;
	if(lan=="ch")
		cout << "setip [网址或IP]" << endl;
	color(0,1,1);
	cout << "|" << endl;
	cout << "|__";
	color(1,1,0);
	if(lan=="en")
		cout << "SET PING THREADS -- ";
	if(lan=="ch")
		cout << "设置Ping线程 -- "; 
	color(1,0,1);
	if(lan=="en")
		cout << "setthread [threads]" << endl;
	if(lan=="ch")
		cout << "setthread [线程数]" << endl;
	color(0,1,1);
	cout << "|" << endl;
	cout << "|__";
	color(1,1,0);
	if(lan=="en")
		cout << "STATE -- ";
	if(lan=="ch")
		cout << "协议与声明 -- ";
	color(1,0,1);
	cout << "state" << endl;
	color(0,1,1);
	cout << "|" << endl;
	cout << "|__";
	color(1,1,0);
	if(lan=="en")
		cout << "START PING -- ";
	if(lan=="ch")
		cout << "开始Ping -- ";
	color(1,0,1);
	cout << "start" << endl;
	color(0,1,1);
	cout << "|" << endl;
	cout << "|__";
	color(1,1,0);
	if(lan=="en")
		cout << "STOP PING -- ";
	if(lan=="ch")
		cout << "停止Ping -- ";
	color(1,0,1);
	cout << "stop" << endl;
	color(0,1,1);
	cout << "|" << endl;
	cout << "|__";
	color(1,1,0);
	if(lan=="en")
		cout << "VIEW THE PING PARAMETER -- ";
	if(lan=="ch")
		cout << "查看Ping参数 -- ";
	color(1,0,1);
	cout << "view" << endl;
	color(0,1,1);
	cout << "|" << endl;
	cout << "|__";
	color(1,1,0);
	if(lan=="en")
		cout << "SET LANGUAGE -- ";
	if(lan=="ch")
		cout << "设置语言 -- ";
	color(1,0,1);
	cout << "language" << endl;
	color(0,1,1);
	cout << "|" << endl;
	cout << "|____________________" << endl;
	cout << endl;
	return;
 } 
 
void line(int i,int pingthreads)
{
	if(i*10.0/pingthreads<1&&last==0)
	{
		system("cls");
		color(0,1,0);
		cout << "              PING STARTING       " << endl; 
		color(1,1,1);
		cout << "         [>          ] starting..." << endl;
		last++;
	}
	else
	{
		if(i*10.0/pingthreads>1&&i*10.0/pingthreads<3&&last==1)
		{
			system("cls");
			color(0,1,0);
			cout << "              PING STARTING       " << endl; 
			color(1,1,1);
			cout << "         [==>        ] starting..." << endl;
			last++;
		}	
		else
		{
			if(i*10.0/pingthreads>1&&i*10.0/pingthreads<3&&last==2)
			{
				system("cls");
				color(0,1,0);
				cout << "              PING STARTING       " << endl; 
				color(1,1,1);
				cout << "         [====>      ] starting..." << endl;
				last++;
			}
			else
			{
				if(i*10.0/pingthreads>3&&i*10.0/pingthreads<5&&last==3)
				{
					system("cls");
					color(0,1,0);
					cout << "              PING STARTING       " << endl; 
					color(1,1,1);
					cout << "         [======>    ] starting..." << endl;
					last++;
					}
				else
				{
					if(i*10.0/pingthreads>5&&i*10.0/pingthreads<7&&last==4)
					{
						system("cls");
						color(0,1,0);
						cout << "              PING STARTING       " << endl; 
						color(1,1,1);
						cout << "         [========>  ] starting..." << endl;
						last++;
					}
					else
					{
						if(i*10.0/pingthreads>7&&i*10.0/pingthreads<9&&last==5)
						{
							system("cls");
							color(0,1,0);
							cout << "              PING STARTING       " << endl; 
							color(1,1,1);
							cout << "         [=========> ] starting..." << endl;
							last++;
						}
						else
						{ 
							if(i*10.0/pingthreads>9&&last==6)
							{
								system("cls");
								color(0,1,0);
								cout << "              PING STARTING       " << endl; 
								color(1,1,1);
								cout << "         [===========] OK" << endl;
								last++;
							}
						} 
					}
				}
			}
		}
	}
}
 
int main()
{
	logo(true);
	help();
	for(int qwer=0;1==1;qwer++)
	{
		logo(false);
		cin >> ord;
		if(ord=="state") 
		{
			color(0,0,1);
			cout << "======================================================" << endl;
			if(lan=="en")
			{
				color(1,1,1);
				cout << "This project is using GNU General Public License v3.0." << endl;
				cout << "You can use the order ";
				color(0,0,1);
				cout << "'lincense'";
				color(1,1,1);
				cout << " to view the Lincense" << endl;
				color(1,0,0);
				cout << "**All consequences caused by your use of this tool have nothing to do with this author, you will bear all legal responsibilities.**" << endl;
				color(1,1,1);
				cout << "##You can use order ";
				color(0,0,1);
				cout << "'github'";
				color(1,1,1);
				cout << " to watch the project on github!" << endl;
				cout << "Ｂｙ　ｗａｔｅｒｂｌｏｃｋ７９　ｏｎ　ｇｉｔｈｕｂ" << endl;
				color(0,0,1);
			}
			if(lan=="ch")
			{
				color(1,1,1);
				cout << "该工程使用GNU通用公共许可证v3.0." << endl;
				cout << "你可以使用指令: ";
				color(0,0,1);
				cout << "'lincense'";
				color(1,1,1);
				cout << " 来查看GNU通用公共许可证v3.0" << endl;
				color(1,0,0);
				cout << "**您使用该工具造成的任何后果均与该工具作者无关，您将承担全部责任**" << endl;
				color(1,1,1);
				cout << "##你可以使用指令: ";
				color(0,0,1);
				cout << "'github'";
				color(1,1,1);
				cout << " 来查看这个工程在GitHub上！" << endl;
				cout << "工程由来自ｇｉｔｈｕｂ的ｗａｔｅｒｂｌｏｃｋ７９制作" << endl;
				color(0,0,1);
			}
			cout << "======================================================" << endl;
			color(1,1,1);
			continue;
		}
		if(ord=="start") 
		{
			if(pingsite!="UnSet")
			{
				string comm;
				char* c=new char[1005];
				char command[1005]={};
				comm="start /min ping "+pingsite+" -t -l "+its(pingsize);
				strcpy(command,comm.c_str());
				last=0;
				for(int i=0;i<pingthreads;i++)
				{
					system(command);
					line(i,pingthreads);
				}
				system("cls");
				logo(true);
				help();
				if(lan=="en")
				{
					color(0,1,0);
					cout << "[SUCCESS]";
					color(1,1,1);
					cout << "Ping start successful." << endl;
					color(0,1,0);
					cout << "[INFO]";
					color(1,1,1);
					cout << "PingSize=" << pingsize << endl;
					color(0,1,0);
					cout << "[INFO]";
					color(1,1,1);
					cout << "PingSite=" << pingsite << endl;
					color(0,1,0);
					cout << "[INFO]";
					color(1,1,1);
					cout << "PingThreads=" << pingthreads << endl;
				 }
				if(lan=="ch")
				{
					color(0,1,0);
					cout << "[成功]";
					color(1,1,1);
					cout << "成功开始Ping！" << endl;
					color(0,1,0);
					cout << "[信息]";
					color(1,1,1);
					cout << "Ping包大小=" << pingsize << endl;
					color(0,1,0);
					cout << "[信息]";
					color(1,1,1);
					cout << "Ping的网址或IP=" << pingsite << endl;
					color(0,1,0);
					cout << "[信息]";
					color(1,1,1);
					cout << "Ping线程=" << pingthreads << endl;
				}
				continue;
			}
			else
			{
				if(lan=="en")
				{
					color(1,0,0);
					cout << "[ERROR]";
					color(1,1,1);
					cout << "You Never Set What WebSite or IP You Want To PING!" << endl;
				}
				if(lan=="ch")
				{
					color(1,0,0);
					cout << "[错误]";
					color(1,1,1);
					cout << "你没有设置你要Ping的IP或网址！" << endl;
				}
			}
			continue;
		}
		if(ord=="stop") 
		{
			system("taskkill /f /im ping.exe");
			cout << "====================" << endl;
			if(lan=="en")
			{
				color(0,1,0);
				cout << "[SUCCESS]";
				color(1,1,1);
				cout << "PING HAS BEEN STOPPED" << endl;
			}
			if(lan=="ch")
			{
				color(0,1,0);
				cout << "[成功]";
				color(1,1,1);
				cout << "Ping已被停止" << endl;
			}
			continue;
		}
		if(ord=="view") 
		{
			if(lan=="en")
			{
				cout << "PingSize=" << pingsize << endl;
				cout << "PingSite=" << pingsite << endl;
				cout << "PingThreads=" << pingthreads << endl;
			}
			if(lan=="ch")
			{
				cout << "Ping包大小=" << pingsize << endl;
				cout << "Ping的网址或IP=" << pingsite << endl;
				cout << "Ping线程数=" << pingthreads << endl;
			}
			continue;
		}
		if(ord=="lincense") 
		{
			system("start https://github.com/waterblock79/Ping-Tool/blob/master/LICENSE");
			continue;
		}
		if(ord=="github") 
		{
			system("start https://github.com/waterblock79/Ping-Tool");
			continue;
		}
		if(ord=="language")
		{
			color(1,0,1);
			cout << "   LanguageList   " << endl;
			cout << "| Language | Code |" << endl;
			color(0,0,1);
			cout << "   ENGLISH    en" << endl;
			color(0,1,0);
			cout << "    中文      ch" << endl;
			color(1,1,1);
			cout << "Please input the language code >> " ;
			cin >> lan;
			if(lan=="en"||lan=="ch")
			{
				system("cls");
				logo(true);
				help();
				if(lan=="en")
				{
					color(0,1,0);
					cout << "[SUCCESS]";
					color(1,1,1);
					cout << "Set the Language=English" << endl;
				}
				if(lan=="ch")
				{
					color(0,1,0);
					cout << "[成功]";
					color(1,1,1);
					cout << "已设置语言为(简体)中文。" << endl;
				}
				logo(false);
				continue;
			}
			else
			{
				lan="en";
				color(1,0,0);
				cout << "[WRONG]";
				color(1,1,1);
				cout << "Wrong language code!" << endl;
			}
		}
		if(ord!="setsize"&&ord!="setip"&&ord!="setthread"&&ord!="language")
		{
			if(lan=="en")
			{
				color(1,0,0);
				cout << "[ERROR]";
				color(1,1,1);
				cout << "wrong command" << endl;
			}
			if(lan=="ch")
			{
				color(1,0,0);
				cout << "[错误]";
				color(1,1,1);
				cout << "错误的指令" << endl;
			}
			continue;
		}
		//------ 
		cin >> par;
			if(ord=="setsize") 
			{
				pingsize=sti(par);
				if(pingsize>65500||pingsize<32)
				{
					if(lan=="en")
					{
						color(1,0,0);
						cout << "[ERROR]";
						color(1,1,1);
						cout << "Ping size must between 32 and 65500!" << endl;
					}
					if(lan=="ch")
					{
						color(1,0,0);
						cout << "[错误]";
						color(1,1,1);
						cout << "Ping包大小必须介于32和65500之间" << endl;
					}
					pingsize=10000;
				} 
				else
				{
					pingsize=sti(par);
					if(lan=="en")
					{
						color(0,1,0);
						cout << "[SUCCESS]";
						color(1,1,1);
						cout << "Set the ping size=" << pingsize << " (Bytes)" << endl;
					}
					if(lan=="ch")
					{
						color(0,1,0);
						cout << "[成功]";
						color(1,1,1);
						cout << "已设置Ping包大小为=" << pingsize << " (比特)" << endl;
					}
				}
				continue;
			}
			if(ord=="setip") 
			{
				pingsite=par;
				if(lan=="en")
				{
					color(0,1,0);
					cout << "[SUCCESS]";
					color(1,1,1);
					cout << "Set the ping website or IP:" << pingsite << endl;
				}
				if(lan=="ch")
				{
					color(0,1,0);
					cout << "[成功]";
					color(1,1,1);
					cout << "已设置Ping目标网址或IP为" << pingsite << endl;
				}
				continue;
			}
			if(ord=="setthread") 
			{
				pingthreads=sti(par);
				if(lan=="en")
				{
					color(0,1,0); 
					cout << "[SUCCESS]";
					color(1,1,1);
			 		cout << "Set ping threads=" << pingthreads << endl;
			 		if(pingthreads>200)
			 			cout << "Please make sure your computer won't be collapse!" << endl;
				}
				if(lan=="ch")
				{
					color(0,1,0); 
					cout << "[成功]";
					color(1,1,1);
			 		cout << "设置Ping线程为 " << pingthreads << endl;
			 		if(pingthreads>200)
				 		cout << "请确保您的电脑不会因为线程过多而崩溃！" << endl;
				}
			 	continue;
			}
			if(lan=="en")
			{
				color(1,0,0);
				cout << "[ERROR]";
				color(1,1,1);
				cout << "wrong command" << endl;
			}
			if(lan=="ch")
			{
				color(1,0,0);
				cout << "[错误]";
				color(1,1,1);
				cout << "错误的指令" << endl;
			}
		ord="";
	}
	return 0;
}
