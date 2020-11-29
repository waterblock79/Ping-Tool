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
	SetConsoleTitle("Ping-Tool # By waterblock79");
	color(0,1,1);
	cout << "_____COMMEND LIST_____" << endl;
	cout << "|" << endl;
	cout << "|__";
	color(1,1,0);
	cout << "SET PING SIZE -- ";
	color(1,0,1);
	cout << "setsize [size]" << endl;
	color(0,1,1);
	cout << "|" << endl;
	cout << "|__";
	color(1,1,0);
	cout << "SET PING WEBSITE OR IP -- ";
	color(1,0,1);
	cout << "setip [website/ip]" << endl;
	color(0,1,1);
	cout << "|" << endl;
	cout << "|__";
	 color(1,1,0);
	cout << "SET PING THREADS -- ";
	color(1,0,1);
	cout << "setthread [threads]" << endl;
	color(0,1,1);
	cout << "|" << endl;
	cout << "|__";
	color(1,1,0);
	cout << "MULTI STATE -- ";
	color(1,0,1);
	cout << "state" << endl;
	color(0,1,1);
	cout << "|" << endl;
	cout << "|__";
	color(1,1,0);
	cout << "START PING -- ";
	color(1,0,1);
	cout << "start" << endl;
	color(0,1,1);
	cout << "|" << endl;
	cout << "|__";
	color(1,1,0);
	cout << "STOP PING -- ";
	color(1,0,1);
	cout << "stop" << endl;
	color(0,1,1);
	cout << "|" << endl;
	cout << "|__";
	color(1,1,0);
	cout << "VIEW THE PARAMETER -- ";
	color(1,0,1);
	cout << "view" << endl;
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
		cout << "[>          ] starting..." << endl;
		last++;
	}
	else
	{
		if(i*10.0/pingthreads>1&&i*10.0/pingthreads<3&&last==1)
		{
			system("cls");
			cout << "[==>        ] starting..." << endl;
			last++;
		}	
		else
		{
			if(i*10.0/pingthreads>1&&i*10.0/pingthreads<3&&last==2)
			{
				system("cls");
				cout << "[====>      ] starting..." << endl;
				last++;
			}
			else
			{
				if(i*10.0/pingthreads>3&&i*10.0/pingthreads<5&&last==3)
				{
					system("cls");
					cout << "[======>    ] starting..." << endl;
					last++;
					}
				else
				{
					if(i*10.0/pingthreads>5&&i*10.0/pingthreads<7&&last==4)
					{
						system("cls");
						cout << "[========>  ] starting..." << endl;
						last++;
					}
					else
					{
						if(i*10.0/pingthreads>7&&i*10.0/pingthreads<9&&last==5)
						{
							system("cls");
							cout << "[=========> ] starting..." << endl;
							last++;
						}
						else
						{ 
							if(i*10.0/pingthreads>9&&last==6)
							{
								system("cls");
								cout << "[===========] OK" << endl;
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
			color(1,1,1);
			cout << "This project is using GNU General Public License v3.0." << endl;
			cout << "You can use the order ";
			color(0,0,1);
			cout << "'lincense'";
			color(1,1,1);
			cout << " to view the Lincense" << endl;
			cout << "**All consequences caused by your use of this tool have nothing to do with this author, you will bear all legal responsibilities.**" << endl;
			cout << "##You can use order ";
			color(0,0,1);
			cout << "'github'";
			color(1,1,1);
			cout << " to watch the project on github!" << endl;
			cout << "£Â£ù¡¡£÷£á£ô£å£ò£â£ì£ï£ã£ë£·£¹¡¡£ï£î¡¡£ç£é£ô£è£õ£â" << endl;
			color(0,0,1);
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
				color(0,1,0);
				cout << "[SUCCESS]";//default 
				color(1,1,1);
				cout << "Ping start successful.Try to use 'view'!" << endl;
			}
			else
			{
				color(1,0,0);
				cout << "[ERROR]";//default 
				color(1,1,1);
				cout << "You Never Set What WebSite or IP You Want To PING!" << endl;
			}
			continue;
		}
		if(ord=="stop") 
		{
			system("taskkill /f /im ping.exe");
			cout << "====================" << endl;
			color(0,1,0);
			cout << "[SUCCESS]";//default 
			color(1,1,1);
			cout << "PING HAS BEEN STOPPED" << endl;
			continue;
		}
		if(ord=="view") 
		{
			cout << "PingSize=" << pingsize << endl;
			cout << "PingSite=" << pingsite << endl;
			cout << "PingThreads=" << pingthreads << endl;
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
		if(ord!="setsize"&&ord!="setip"&&ord!="setthread")
		{
			color(1,0,0);
			cout << "[ERROR]";//default 
			color(1,1,1);
			cout << "wrong command" << endl;
			continue;
		}
		//------ 
		cin >> par;
			if(ord=="setsize") 
			{
				pingsize=sti(par);
				if(pingsize>65500||pingsize<32)
				{
					color(1,0,0);
					cout << "[ERROR]";//default 
					color(1,1,1);
					cout << "Ping size must between 32 and 65500!" << endl;
					pingsize=10000;
				} 
				else
				{
					pingsize=sti(par);
					color(0,1,0);
					cout << "[SUCCESS]";//default 
					color(1,1,1);
					cout << "Set the ping size=" << pingsize << " (Bytes)" << endl;
				}
				continue;
			}
			if(ord=="setip") 
			{
				pingsite=par;
				color(0,1,0);
				cout << "[SUCCESS]";//default 
				color(1,1,1);
				cout << "Set the ping website or IP:" << pingsite << endl;
				continue;
			}
			if(ord=="setthread") 
			{
				pingthreads=sti(par);
				color(0,1,0);
				cout << "[SUCCESS]";//default 
				color(1,1,1);
			 	cout << "Set ping threads:" << pingthreads << endl;
			 	if(pingthreads>200)
			 		cout << "Please make sure your computer won't be collapse!" << endl;
			 	continue;
			}
			color(1,0,0);
			cout << "[ERROR]";//default 
			color(1,1,1);
			cout << "wrong command" << endl;
		ord="";
	}
	return 0;
}
