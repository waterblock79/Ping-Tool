#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

using namespace std;

string ord="",par;
int pingsize=10000,pingthreads=1;
string pingsite="UnSet";

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
		s=char(a%n+'0')+s;
		n=n*10;
		a=a/10;
	}
	return s;
 }
 
void logo(bool model)
{
	HANDLE he;
	he=GetStdHandle(STD_OUTPUT_HANDLE);
	if(model==true)
	{
		cout << "*****|---------|*****" << endl;
		cout << "     |";
	}
	SetConsoleTextAttribute(he,FOREGROUND_RED | FOREGROUND_GREEN);
    cout << "P";
    SetConsoleTextAttribute(he,FOREGROUND_GREEN | FOREGROUND_BLUE);
    cout << "I";
    SetConsoleTextAttribute(he,FOREGROUND_BLUE | FOREGROUND_RED);
    cout << "N";
    SetConsoleTextAttribute(he,FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    cout << "G";
    cout << " "; 
    SetConsoleTextAttribute(he,FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    cout << "T";
	SetConsoleTextAttribute(he,FOREGROUND_BLUE | FOREGROUND_RED);
	cout << "O";
	SetConsoleTextAttribute(he,FOREGROUND_GREEN | FOREGROUND_BLUE);
	cout << "O";
	SetConsoleTextAttribute(he,FOREGROUND_RED | FOREGROUND_GREEN);
	cout << "L";
	if(model==true)
	{
		cout << "|"<<endl;
		cout << "*****|---------|*****" << endl;
		return;
	}
	else
	{
		SetConsoleTextAttribute(he,FOREGROUND_GREEN);
		cout << " >> " ;
		SetConsoleTextAttribute(he,FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		return;
	}
}

void help()
{
	SetConsoleTitle("Ping-Tool # By waterblock79");
	HANDLE he;
	he=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(he,FOREGROUND_GREEN | FOREGROUND_BLUE); 
	cout << "_____ORDER LIST_____" << endl;
	cout << "|" << endl;
	cout << "|__";
	SetConsoleTextAttribute(he,FOREGROUND_GREEN | FOREGROUND_RED); 
	cout << "SET PING SIZE -- ";
	SetConsoleTextAttribute(he,FOREGROUND_RED | FOREGROUND_BLUE); 
	cout << "ps [size]" << endl;
	SetConsoleTextAttribute(he,FOREGROUND_GREEN | FOREGROUND_BLUE); 
	cout << "|" << endl;
	cout << "|__";
	SetConsoleTextAttribute(he,FOREGROUND_GREEN | FOREGROUND_RED); 
	cout << "SET PING WEBSITE OR IP -- ";
	SetConsoleTextAttribute(he,FOREGROUND_RED | FOREGROUND_BLUE); 
	cout << "pw [website/ip]" << endl;
	SetConsoleTextAttribute(he,FOREGROUND_GREEN | FOREGROUND_BLUE); 
	cout << "|" << endl;
	cout << "|__";
	SetConsoleTextAttribute(he,FOREGROUND_GREEN | FOREGROUND_RED); 
	cout << "SET PING THREADS -- ";
	SetConsoleTextAttribute(he,FOREGROUND_RED | FOREGROUND_BLUE); 
	cout << "pt [threads]" << endl;
	SetConsoleTextAttribute(he,FOREGROUND_GREEN | FOREGROUND_BLUE); 
	cout << "|" << endl;
	cout << "|__";
	SetConsoleTextAttribute(he,FOREGROUND_GREEN | FOREGROUND_RED); 
	cout << "STATE -- ";
	SetConsoleTextAttribute(he,FOREGROUND_RED | FOREGROUND_BLUE); 
	cout << "state 0" << endl;
	SetConsoleTextAttribute(he,FOREGROUND_GREEN | FOREGROUND_BLUE); 
	cout << "|" << endl;
	cout << "|__";
	SetConsoleTextAttribute(he,FOREGROUND_GREEN | FOREGROUND_RED); 
	cout << "START PING -- ";
	SetConsoleTextAttribute(he,FOREGROUND_RED | FOREGROUND_BLUE); 
	cout << "start 0" << endl;
	SetConsoleTextAttribute(he,FOREGROUND_GREEN | FOREGROUND_BLUE); 
	cout << "|" << endl;
	cout << "|__";
	SetConsoleTextAttribute(he,FOREGROUND_GREEN | FOREGROUND_RED); 
	cout << "STOP PING -- ";
	SetConsoleTextAttribute(he,FOREGROUND_RED | FOREGROUND_BLUE); 
	cout << "stop 0" << endl;
	SetConsoleTextAttribute(he,FOREGROUND_GREEN | FOREGROUND_BLUE);
	cout << "|" << endl;
	cout << "|__";
	SetConsoleTextAttribute(he,FOREGROUND_GREEN | FOREGROUND_RED); 
	cout << "VIEW THE PARAMETER -- ";
	SetConsoleTextAttribute(he,FOREGROUND_RED | FOREGROUND_BLUE); 
	cout << "view 0" << endl;
	SetConsoleTextAttribute(he,FOREGROUND_GREEN | FOREGROUND_BLUE); 
	cout << "|" << endl;
	cout << "|__________________" << endl;
	cout << endl;
 } 
 
int main()
{
	logo(true); 
	help();
	for(int qwer=0;1==1;qwer++)
	{
		logo(false);
		cin >> ord >> par;
			if(ord=="ps") 
			{
				pingsize=sti(par);
				if(pingsize>65500||pingsize<32)
				{
					cout << "WRONG:Ping Size Must Between 32 and 65500!" << endl;
					pingsize=10000;
				} 
				else
				{
					pingsize=sti(par);
					cout << "Success Set Ping Size=" << pingsize << " (Bytes)" << endl;
				}
				continue;
			}
			if(ord=="pw") 
			{
				pingsite=par;
				cout << "Success Set Ping Website or IP:" << pingsite << endl;
				continue;
			}
			if(ord=="pt") 
			{
				pingthreads=sti(par);
			 	cout << "Success Set Ping Threads:" << pingthreads << endl;
			 	if(pingthreads>200)
			 		cout << "Please Make Sure Your Computer Won't Be Collapse!" << endl;
			 	continue;
			}
			if(ord=="state") 
			{
				cout << "This project is using GNU General Public License v3.0." << endl;
				cout << "You can use the order 'lincense 0' to view the Lincense" << endl;
				cout << "**All consequences caused by your use of this tool have nothing to do with this author, you will bear all legal responsibilities.**" << endl;
				cout << "##You can use order 'github 0' to watch the project on github!" << endl;
				cout << "£Â£ù¡¡£÷£á£ô£å£ò£â£ì£ï£ã£ë£·£¹¡¡£ï£î¡¡£ç£é£ô£è£õ£â" << endl;
				continue;
			}
			if(ord=="start") 
			{
				if(pingsize!=-1&&pingthreads!=-1&&pingsite!="UnSet")
				{
					string comm;
					char* c=new char[1005];
					char command[1005]={};
					comm="start /min ping "+pingsite+" -t -l "+its(pingsize-1);
					strcpy(command,comm.c_str());
					for(int i=0;i<pingthreads;i++)
					{
						system(command);
					}
				}
				else
				{
					cout << "You Never Set What WebSite or IP You Want To PING!" << endl;
				}
				continue;
			}
			if(ord=="stop") 
			{
				system("taskkill /f /im ping.exe");
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
			if(ord=="help") 
			{
				help();
				continue;
			}
			cout << "WRONG ORDER!Use order 'help 0' to get help!" << endl;//default 
		ord="";
	}
	return 0;
}
