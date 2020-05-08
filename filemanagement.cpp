#include<iostream>
#include<windows.h>
#include<fstream>
#include<stdlib.h>
#include<conio.h>
#include<dirent.h>
#include<time.h>	
using namespace std;

string sourcePath;
string destinationPath;	
COORD coord={0,0};


void gotoxy(int x,int y)
{
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
bool fexists(string filename) 
{
  ifstream ifile(filename.c_str());
  return (bool)ifile;
}
class date		//class current date and time of system
{
	
	
	public:
		int aday,amonth,ayear,ahour,amin,asec;
	void date_times()
	{
		SYSTEMTIME t;		//pre defined in time.h header
 		GetLocalTime(&t);
		aday=t.wDay,amonth=t.wMonth,ayear=t.wYear,ahour=t.wHour,amin=t.wMinute,asec=t.wSecond;
		
	}
};
char *date_time()
{
	time_t t;
	time(&t);
	char *loc=ctime(&t);
	return loc;	//returns local time and date
}
void scroll_note()	//welcome note
{
		system("color FC");
	int j,i,x,y,k=0;
	
	for(i=0;i<30;i++)
	{
		gotoxy(i,13);cout<<" ";
		cout<<"WELCOME TO";
		Sleep(40);
	}

	for(j=67;j>40;j--)
	{
		gotoxy(j,13);
		cout<<"FILE MANAGEMENT";cout<<"            ";
		Sleep(40);
	}

	
	gotoxy(30,13);cout<<"WELCOME TO";
	gotoxy(41,13);cout<<"FILE MANAGEMENT";

	for(int j=90;j>=0;j--)
	{
		gotoxy(j,20);cout<<"|";
		gotoxy(j,4);cout<<"|";
		Sleep(20);
	}
		gotoxy(30,2);
	char s[20];
	strcpy(s,date_time());
	cout<<s;
	gotoxy(55,23);cout<<"made by:-Gopal swami";
      
     	
	Sleep(1000);

}

void call()
{ 
		char op;
		int i;
		op=getche();
		system("cls");
		gotoxy(40,11);
		cout<<"please wait";
		for(i=51;i<58;i++)
		{
			gotoxy(i,11);
			Sleep(100);
			cout<<".";
			
		}
		Sleep(200);
		system("cls");
}

void frame()
{
	int i,j=70;
	for(i=20;i<70,j>19;i++,j--)
	{
		gotoxy(i,6);
		Sleep(10);
		cout<<"*";
		gotoxy(j,18);
		Sleep(10);
		cout<<"*";
	}
	for(i=7,j=17;i<18,j>6;i++,j--)
	{
		gotoxy(20,j);
		Sleep(30);
		cout<<"*";
		gotoxy(70,i);
		Sleep(30);
		cout<<"*";
	}
		gotoxy(33,6);
	char s[20];
	strcpy(s,date_time());
	cout<<s;
}


void frame_fix()
{
	int i,j=79;
	for(i = 20;i<80,j>=20;i++,j--)
	{
		gotoxy(i,3);
		cout<<"_";
		gotoxy(j,20);
		cout<<"_";
	}
	
}

int listFiles()
{ system("cls");

 cout<<"enter source path:-";
 
cin>>sourcePath;

system("COLOR 4F");
	int done, i=1;
	DIR *dir;
	dirent *pdir;
	const char * c = sourcePath.c_str();
	dir=opendir(c);
 if(dir)
 {
		     	while(pdir=readdir(dir))
	{    gotoxy(20,i);
		cout<<pdir->d_name<<endl;
		i++;
	}

	closedir(dir);}	
	else if(ENOENT==errno)
	{
		cout<<"Directory doesn't exist"<<endl;
	}
	else {
	cout<<"open directory failed some other reason"<<endl;
	}
	int n;
	cout<<"DO you want to see another listfile press '1'";
	cin>>n;
	if(n==1)
	listFiles();
else{
		system("cls");
		cout<<"PRESS ANY KEY TO BACK IN MAIN MENU:-";
}
}
int copypath(string);
int path(string ,string);
int copyFile(string sourcePath,string destinationPath,string s,string t)
{   system("cls");
    	frame_fix();
	system("COLOR 5F");
		gotoxy(28,4);
	cout<<s<<" file path:-";
	gotoxy(46,4);
	cout<<sourcePath;
	gotoxy(28,6);
	cout<<t<<" file path:-";
	gotoxy(46,6);
	cout<<destinationPath;
	FILE* f_src;
	FILE* f_dest;
	 gotoxy(28,8);
		cout<<"Please input file name=";
		string filename;
		gotoxy(51,8);
		cin>>filename;
		
		string c1 = sourcePath+"\\"+filename;
		string c2 = destinationPath+"\\"+filename;
	
	if(!fexists(c1))
	{
		gotoxy(28,10);
		cout<<"File not present"<<endl;
        //return 0;
	}
	
else{
gotoxy(28,10);
	 cout<<c1; 
	 gotoxy(28,11);cout<<"to";
	 gotoxy(28,12);
	cout<<c2;	
    
	
	f_src = fopen(c1.c_str(), "r");
	
	f_dest = fopen(c2.c_str(), "w");
	
	
	int tmp;
	while(!feof(f_src))
	{
		tmp = fgetc(f_src);
		fputc(tmp,f_dest);
	}
	fclose(f_src);
	fclose(f_dest);}
		int ch;
	gotoxy(26,13);
	cout<<"-:Do you want to copy another file press '1':-";
	gotoxy(28,14);cout<<"1)same path";
	gotoxy(28,15);cout<<"2)Different path";
	gotoxy(28,16);
	cin>>ch;
	if(ch==1)
	{
		copyFile(sourcePath,destinationPath,s,t);
	}
	else if(ch==2)
     {copypath(s);
     path(s,t);
	 }
	 	 /*system("cls");
		gotoxy(38,12);
		cout<<"PRESS ANY KEY TO BACK IN MAIN MENU";
	*/

return 1;
}
int delpath();
int deleteFiles( string sourcePath)
{
    system("cls");
    system("COLOR 3F");
    frame_fix();
		gotoxy(28,6);
	cout<<"Deleted file path:-";
	gotoxy(48,6);
	cout<<sourcePath;
	string filename;
	gotoxy(28,8);
	cout<<"Please provide filename="<<endl;
	gotoxy(52,8);
	cin>>filename;
	string filepath = sourcePath+"\\"+filename;
	if(remove(filepath.c_str()) != 0){
		gotoxy(30,11);
		cout<<"Error in removing file"<<endl;
	}
	else{gotoxy(30,11);
		cout<<"File successfully deleted"<<endl;
	}
	int ch;
	gotoxy(28,13);
	cout<<"-:do you want to delete another file press:-";
	gotoxy(26,14);cout<<"1)Same path";
	gotoxy(28,15);cout<<"2)Diffrent path";
	gotoxy(28,16);
	cin>>ch;
	if(ch==1)
	{
		deleteFiles(sourcePath);
	}
	else if(ch==2)
	{system("cls");
	delpath();
	}
		
	return 1;
}
int getSelectedOption();
int delpath()
{  frame_fix();
 	gotoxy(28,6);
	cout<<"Enter deleted file path:-";
	gotoxy(54,6);
	cin>>sourcePath;
	DIR *dir;
	const char * c = sourcePath.c_str();
	dir=opendir(c);
 if(dir)
 {deleteFiles(sourcePath);
 closedir(dir);}	
	else if(ENOENT==errno)
	{   gotoxy(28,8);
		cout<<"Directory doesn't exist"<<endl;
		int ch;
	gotoxy(28,10);
	cout<<"Do u to want another try press '1'="<<endl;
	gotoxy(63,10);cin>>ch;
	if(ch==1)
	{system("cls");
	delpath();
	}
      	}
	else {gotoxy(28,8);
	cout<<"open directory failed some other reason"<<endl;
	int ch;
	gotoxy(28,10);
	cout<<"Do u to want another try press '1'="<<endl;
	gotoxy(63,10);cin>>ch;
	if(ch==1)
	{system("cls");
	delpath();
	}}
	 system("cls");
		gotoxy(28,12);
		cout<<"PRESS ANY KEY TO BACK IN MAIN MENU";
      	call();
	  	getSelectedOption();
return 0;
}
int path(string s,string t)
{system("cls");
int ch;
	frame_fix();
        gotoxy(28,7);
    	cout<<"enter "<<t<<" path:-";
    	gotoxy(52,7);cin>>destinationPath;
    	DIR *d;
	const char * c= destinationPath.c_str();
	d=opendir(c);
	if(d)
	{closedir(d);
		copyFile(sourcePath,destinationPath,s,t);
    }
    else if(ENOENT==errno)
	{   gotoxy(28,8);
		cout<<"Directory doesn't exist"<<endl;
		int ch;
	gotoxy(28,10);
	cout<<"Do u to want another try press '1'="<<endl;
	gotoxy(63,10);cin>>ch;
	if(ch==1)
	{system("cls");
	path(s,t);
	
    }}
    	else {gotoxy(28,8);
	cout<<"open directory failed some other reason"<<endl;
	
	gotoxy(28,10);
	cout<<"Do u to want another try press '1'="<<endl;
	gotoxy(63,10);cin>>ch;
	if(ch==1)
	{system("cls");
	path(s,t);
	}}
		 system("cls");
		gotoxy(28,12);
		cout<<"PRESS ANY KEY TO BACK IN MAIN MENU";
      	call();
	  	getSelectedOption();
return 0;
}
int copypath(string s)
{	frame_fix();
 gotoxy(28,6);
	cout<<"Enter "<<s<<" path:-";
	gotoxy(53,6);
	cin>>sourcePath;
	int ch;
	DIR *dir;
	const char * c = sourcePath.c_str();
	dir=opendir(c);
 if(dir)
 { closedir(dir);
 }	
	else if(ENOENT==errno)
	{   gotoxy(28,8);
		cout<<"Directory doesn't exist"<<endl;
		
	gotoxy(28,10);
	cout<<"Do u to want another try press '1'="<<endl;
	gotoxy(63,10);cin>>ch;
	if(ch==1)
	{system("cls");
	copypath(s);
	}else
	{ system("cls");
		gotoxy(28,12);
		cout<<"PRESS ANY KEY TO BACK IN MAIN MENU";
      	call();
	  	getSelectedOption();
		  }  	}
	else {gotoxy(28,8);
	cout<<"open directory failed some other reason"<<endl;
	
	gotoxy(28,10);
	cout<<"Do u to want another try press '1'="<<endl;
	gotoxy(63,10);cin>>ch;
	if(ch==1)
	{system("cls");
	copypath(s);
	}else{
	 system("cls");
		gotoxy(28,12);
		cout<<"PRESS ANY KEY TO BACK IN MAIN MENU";
      	call();
	  	getSelectedOption();
}}
	
return 0;
}
int getSelectedOption()
{
	system("COLOR 2F");
	frame();
	gotoxy(33,3);
	cout<<"~~~~~~FILE MANAGEMENT~~~~~~";
	gotoxy(35,8);
	cout<< "1 - List all files"<<endl;
	gotoxy(35,10);
	cout<< "2 - Delete File"<<endl;
	gotoxy(35,12);
	cout<< "3 - Take Backup"<<endl;
	gotoxy(35,14);
	cout<< "4 - Take Restore"<<endl;
	gotoxy(35,16);
	cout<< "5 - Exit";
	gotoxy(35,20);
	cout<< "Please select operation:-"<<endl;
	int option;
	string s="source",t="backup"; 
	gotoxy(60,20);
	cin>>option;
	
	if(option == 1)
	{   
		listFiles();
		call();
		getSelectedOption(); 
	}
	
	if(option == 2)
	{  system("cls");
system("COLOR 3F");
	 delpath();
	}
	
	if(option == 3)
	{   system("cls");
	   frame_fix();
	system("COLOR 5F");
 		
   	copypath(s);
   	path(s,t);
	}
	if(option == 4)
	{ system("cls");
		frame_fix();
		system("COLOR 6F");
		t="restore";
		copypath(s);
		path(s,t);
	}
	if(option == 5){int i;
		system("cls");
		gotoxy(40,11);
		cout<<"please wait";
		for(i=52;i<58;i++)
		{ 	Sleep(100);
		gotoxy(i,11);
			cout<<".";
		
		}
		
		system("cls");
		Sleep(100);
		gotoxy(40,11);
		cout<<"Exiting";
		for(i=47;i<53;i++)
		{   	Sleep(100);
		 gotoxy(i,11);
			cout<<".";
		
		}
	gotoxy(40,11);
		cout<<"Press enter to close....";
		
		getch();
	}

	return 0;
	
}
int main()
{ 
    scroll_note();
    system("cls");
    gotoxy(28,3);
	getSelectedOption();
	return 0;
}








