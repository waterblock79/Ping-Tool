#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

using namespace std;

string ord="",par;
int pingsize,pingthreads;
string pingsite;

int sti(string a)
{
	int n=1,sum;
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

int main()
{
	SetConsoleTitle("PING TOOL");
	HANDLE he;
	he=GetStdHandle(STD_OUTPUT_HANDLE);
	logo(true);
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
	cout << "|__________________" << endl;
	cout << endl;
	for(int qwer=0;1==1;qwer++)
	{
		logo(false);
		cin >> ord >> par;
		if(ord=="ps")
		{
			pingsize=sti(par);
			cout << "Success Set Ping Size=" << pingsize << endl;
		}
		else
		{
			if(ord=="pw")
			{
				pingsite=par;
				cout << "Success Set Ping Website or IP:" << pingsite << endl;
			} 
			else
			{
				if(ord=="pt")
			 	{
			 		pingthreads=sti(par);
			 		cout << "Success Set Ping Threads:" << pingthreads << endl;
				}
				else
				{
					if(ord=="state")
					{
						cout << "This project is using GNU General Public License v3.0." << endl;
						cout << "You can use the order 'lincense 0' to view the Lincense" << endl;
						cout << "**All consequences caused by your use of this tool have nothing to do with this author, you will bear all legal responsibilities.**" << endl;
						cout << "##You can use order 'github 0' to watch the project on github!" << endl;
						cout << "£Â£ù¡¡£÷£á£ô£å£ò£â£ì£ï£ã£ë£·£¹¡¡£ï£î¡¡£ç£é£ô£è£õ£â" << endl;
					}
					else
					{
						if(ord=="start")
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
							if(ord=="stop")
							{
								system("taskkill /f /im ping.exe");
								cout << "PING HAS BEEN STOPPED" << endl;
							}
							else
							{
								if(ord=="lincense")
								{
									system("start https://github.com/waterblock79/Ping-Tool/blob/master/LICENSE");
								}
								else
								{ 
									if(ord=="github")
									{
										system("start https://github.com/waterblock79/Ping-Tool");
									}
									else
									{
										cout << "WRONG ORDER!" << endl;
									}
								} 
							}
						}
					}
				}
			}
		}
		ord="";
	}
	return 0;
}
