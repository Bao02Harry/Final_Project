//Khai bao thu vien
#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <string.h>
#include<conio.h>
#include<stdio.h>
#include<time.h>
using namespace std;
//---------------------------------BANG MAU-----------------------------------------

#define ColorCode_Back			0
#define ColorCode_DarkBlue		1
#define ColorCode_DarkGreen		2
#define ColorCode_DarkCyan		3
#define ColorCode_DarkRed		4
#define ColorCode_DarkPink		5
#define ColorCode_DarkYellow	6
#define ColorCode_DarkWhite		7
#define ColorCode_Grey			8
#define ColorCode_Blue			9
#define ColorCode_Green			10
#define ColorCode_Cyan			11
#define ColorCode_Red			12
#define ColorCode_Pink			13
#define ColorCode_Yellow		14
#define ColorCode_White			15

#define default_ColorCode		7
// struct
//  No, Teacher ID, First Name, Last Name, Gender, Social ID, Faculty, Password
struct Teacher{
    string No, First_Name, Last_Name, Gender, Social_ID, Faculty;
	string Teacher_ID,Password;
};
//    No,Student ID,First Name,Last Name,Gender,Date of Birth,Social ID,Class,Password
struct Student{
    string No,First_Name,Last_Name,Gender,Date_of_Birth,Social_ID,Class;
    string Student_ID,Password;
};
//---------------------------------------------Su dung mau--------------------------------------
void TextColor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}
//toa do
void gotoxy(int x,int y)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD tinh = {x,y} ;
	SetConsoleCursorPosition(mau,tinh ) ;
}
// to mau 
void tomau(int x, int y, string a, int color)
{
	gotoxy(x,y);
	TextColor(color);
	cout<<a;
	TextColor(7);
}
//---------------------------------------------Ma hoa mat khau khi dang nhap---------------------------------------
void Mahoa_MK(char b[10])
{
	char ch;
	int dem=0;
	while((ch=getch())!=13){
		if((ch>='a'&&ch<='z')||(ch>='A' && ch<='Z')||(ch>='0' && ch<='9')){
				cout<<"*";
				b[dem++]=ch;

		}else
		if(ch==8)
			if(dem>0){
				cout<<"\b \b";
				dem--;
			}
				
	}
	b[dem]=0;
}
//---------------------------------------------Cap nhat thoi gian--------------------------------------
string ThoiGian()
{
   // tra ve date/time hien tai dua tren system hien tai
   time_t hientai = time(0);
   
   // chuyen doi hientai thanh dang chuoi
    string thoigian = ctime(&hientai);

  return thoigian;
}
//-----------------------------------------------Thong tin tai khoan------------------------------------
//---------------------------------------------Kiem tra so du trong tai khoan---------------------------
/*
void ThongTinStudent(Student student,char user[10]){
    fstream file;
    file.open("Students.csv",ios::in);
	string No,First_Name,Last_Name,Gender,Date_of_Birth,Social_ID,Class;
	char Student_ID[10],Password[10];
	while(!file.eof())
	{
	    getline(file,No,',');
	    file.getline(Student_ID,10,',');
	    getline(file,First_Name,',');
	    getline(file,Last_Name,',');
	    getline(file,Gender,',');
	    getline(file,Date_of_Birth,',');
	    getline(file,Social_ID,',');
	    getline(file,Class,',');
	    file.getline(Password,10);
	    if(strcmp( Student_ID, user) == 0)
	   	{
	    	student.No=No;
	    	student.Student_ID=Student_ID;
	    	student.First_Name=First_Name;
	    	student.Last_Name=Last_Name;
	    	student.Gender=Gender;
	    	student.Date_of_Birth=Date_of_Birth;
	    	student.Social_ID=Social_ID;
	    	student.Class=Class;
	    	student.Password=Password;
	    	break;
	    }
	}
	file.close();

}
void ThongTinTeacher(Teacher teacher,char user[10]){
    fstream file;
    file.open("Teachers.csv",ios::in);
	string No, First_Name, Last_Name, Gender, Social_ID, Faculty;
	char Teacher_ID[10],Password[10];
	while(!file.eof())
	{
	    getline(file,No,',');
	    file.getline(Teacher_ID,10,',');
	    getline(file,First_Name,',');
	    getline(file,Last_Name,',');
	    getline(file,Gender,',');
	    getline(file,Social_ID,',');
	    getline(file,Faculty,',');
	    file.getline(Password,10);
	    if(strcmp( Teacher_ID, user) == 0 )
	   	{
	    	teacher.No=No;
	    	teacher.Teacher_ID=Teacher_ID;
	    	teacher.First_Name=First_Name;
	    	teacher.Last_Name=Last_Name;
	    	teacher.Gender=Gender;
	    	teacher.Social_ID=Social_ID;
	    	teacher.Faculty=Faculty;
	    	teacher.Password=Password;
	    	break;
	    }
	}
	file.close();
}
*/
int main(){ 
	int select;
	char user[10];
	char password[10];
	int input=0;
    int false_n=0;
    fstream file;
    do{
	        system("cls");
			tomau(15,4,"**************************************",14);
			tomau(15,6,"**",14);
			tomau(25,6,"     LOGIN",10);
			tomau(50,6,"**",14);
			tomau(15,8,"**************************************",14);
			cin.ignore();
			tomau(15,12,"User: ",10);
			cin.getline(user,10);
			tomau(15,15,"Password: ",10); Mahoa_MK(password);
			tomau(15,18,"Type:   1. Teacher   2. Student  ",10);
			tomau(15,21,"input select:  ",10);
			cin>>input;
			tomau(15,24,"Dang kiem tra thong tin...",11);
			Sleep(1000);
            if(input==1){
				  file.open("Teachers.csv",ios::in);
				  string No, First_Name, Last_Name, Gender, Social_ID, Faculty;
				  char Teacher_ID[10],Password[10];
	  			  while(!file.eof())
	  			  {
	    			  getline(file,No,',');
	    			  file.getline(Teacher_ID,10,',');
	    			  getline(file,First_Name,',');
	    			  getline(file,Last_Name,',');
	    			  getline(file,Gender,',');
	    			  getline(file,Social_ID,',');
	    			  getline(file,Faculty,',');
	    			  file.getline(Password,10);
	    			  if(strcmp( Teacher_ID, user) == 0 && strcmp(Password,password) == 0)
	   				  {
	    			       false_n=1;
	    			    	tomau(15,24,"DANG NHAP THANH CONG!!! ",10);
	     			        break;
	     			   }
	   			   }
	   			   file.close();
	   			   int dem=0;
	   		       if(false_n==0)
					{
							dem++;
							if(dem<3)
							{
									char phim_ESC;
									tomau(15,24,"Tai khoan hoac mat khau sai. vui long nhap lai!!!\a\a ",10);	
									tomau(15,2,"Tiep tuc: Phim bat ki (tru ESC)",9);
									tomau(60,2,"Thoat : ESC",9);
									phim_ESC = _getch();
									if(phim_ESC == 27)
									{
										system("cls");
										return 0;
								
									}
							
							}
							if(dem==3)
							{
								cout << "\n\t\tBAN DA THOAT KHOI CHUONG TRINH\a\a";
								return 0;
							}
						} 
	   			    tomau(15,27,"Tiep tuc (Nhan enter)",14);
					cout<<endl;
					TextColor(0);
					system("pause");
			}else if(input==2){
				  file.open("Students.csv",ios::in);
				  string No,First_Name,Last_Name,Gender,Date_of_Birth,Social_ID,Class;
				  char Student_ID[10],Password[10];
	  			  while(!file.eof())
	  			  {
	    			  getline(file,No,',');
	    			  file.getline(Student_ID,10,',');
	    			  getline(file,First_Name,',');
	    			  getline(file,Last_Name,',');
	    			  getline(file,Gender,',');
	    			  getline(file,Date_of_Birth,',');
	    			  getline(file,Social_ID,',');
	    			  getline(file,Class,',');
	      			  file.getline(Password,10);
	      			  if(strcmp( Student_ID, user) == 0 && strcmp(Password,password) == 0)
	   				  {
	    			       false_n=1;
	    			    	tomau(15,24,"DANG NHAP THANH CONG!!! ",10);
	     			        break;
	     			   }
	   			   }
	   			   file.close();
	   			   int dem=0;
	   		       if(false_n==0)
					{
							dem++;
							if(dem<3)
							{
									char phim_ESC;
									tomau(15,24,"Tai khoan hoac mat khau sai. vui long nhap lai!!!\a\a ",10);	
									tomau(15,2,"Tiep tuc: Phim bat ki (tru ESC)",9);
									tomau(60,2,"Thoat : ESC",9);
									phim_ESC = _getch();
									if(phim_ESC == 27)
									{
										system("cls");
										return 0;
								
									}
							
							}
							if(dem==3)
							{
								cout << "\n\t\tBAN DA THOAT KHOI CHUONG TRINH\a\a";
								return 0;
							}
						} 
	   			    tomau(15,27,"Tiep tuc (Nhan enter)",14);
					cout<<endl;
					TextColor(0);
					system("pause");
			} 
			else
			{
				char phim_ESC;
				tomau(15,24,"Lua chon khong dung. Vui long thu lai\a\a ",10);	
				tomau(15,2,"Tiep tuc: Phim bat ki (tru ESC)",9);
				tomau(60,2,"Thoat : ESC",9);
				phim_ESC = _getch();
				if(phim_ESC == 27)
				{
					system("cls");
					return 0;
								
				}									
			}		    
	 
	}while(false_n==0);
	// trang ca nhan
	if(input==1){
		int key;
			while (true)
			{
					system("cls");
		     		tomau(15,2,"*************************************************",14);
		     		tomau(15,4,"**",14);
		     		tomau(20,4," Teacher "+string(user),10);
		     		tomau(62,4,"**",14);
		     		tomau(15,6,"*************************************************",14);
		     		tomau(15,8,"1.  THONG TIN TAI KHOAN",15);
		     		tomau(15,10,"2.   ",15);
		     		tomau(15,12,"3.   ",15);
		     		tomau(15,14,"4.   ",15);
		     		tomau(15,16,"0.Thoat  ",15);
		     		tomau(15,18,"nhap lua chon cua ban :  ",14); cin >> key;
		            switch(key)
		            {
					    case 1:
		     				Sleep(500);
		     				system("cls");
				   			tomau(15,4,"**************************************",14);
							tomau(15,6,"**",14);
							tomau(25,6," THONG TIN TAI KHOAN",12);
							tomau(50,6,"**",14);
							tomau(15,8,"**************************************",14);
							tomau(15,11,"No, Teacher ID, First Name, Last Name, Gender, Social ID, Faculty, Password ",13);
							 fstream file;
							    file.open("Teachers.csv",ios::in);
								string No, First_Name, Last_Name, Gender, Social_ID, Faculty;
								char Teacher_ID[10],Password[10];
								while(!file.eof())
								{
								    getline(file,No,',');
								    file.getline(Teacher_ID,10,',');
								    getline(file,First_Name,',');
								    getline(file,Last_Name,',');
								    getline(file,Gender,',');
								    getline(file,Social_ID,',');
								    getline(file,Faculty,',');
								    file.getline(Password,10);
								    if(strcmp( Teacher_ID, user) == 0 )
								   	{
								    	tomau(15,14,No+"-"+Teacher_ID+"-"+First_Name+"-"+Last_Name
										+"-"+Gender+"-"+Social_ID+"-"+Faculty+"-"+Password,13);
								    	break;
								    }
								}
								file.close();
							tomau(15,17,"Bam phim bat ky de tiep tuc ",13);
							_getch();
							break;	
						
					
					}
		    }
		
	} else if(input==2){
	       int key;
			while (true)
			{
					system("cls");
		     		tomau(15,2,"*************************************************",14);
		     		tomau(15,4,"**",14);
		     		tomau(20,4," Teacher "+string(user),10);
		     		tomau(62,4,"**",14);
		     		tomau(15,6,"*************************************************",14);
		     		tomau(15,8,"1.  THONG TIN TAI KHOAN",15);
		     		tomau(15,10,"2.   ",15);
		     		tomau(15,12,"3.   ",15);
		     		tomau(15,14,"4.   ",15);
		     		tomau(15,16,"0.Thoat  ",15);
		     		tomau(15,18,"nhap lua chon cua ban :  ",14); cin >> key;
		            switch(key)
		            {
					    case 1:
		     				Sleep(500);
		     				system("cls");
				   			tomau(15,4,"**************************************",14);
							tomau(15,6,"**",14);
							tomau(25,6," THONG TIN TAI KHOAN",12);
							tomau(50,6,"**",14);
							tomau(15,8,"**************************************",14);
							 tomau(15,11," No,Student ID,First Name,Last Name,Gender,Date of Birth,Social ID,Class,Password ",13);
							       fstream file;
						    file.open("Students.csv",ios::in);
							string No,First_Name,Last_Name,Gender,Date_of_Birth,Social_ID,Class;
							char Student_ID[10],Password[10];
							while(!file.eof())
							{
							    getline(file,No,',');
							    file.getline(Student_ID,10,',');
							    getline(file,First_Name,',');
							    getline(file,Last_Name,',');
							    getline(file,Gender,',');
							    getline(file,Date_of_Birth,',');
							    getline(file,Social_ID,',');
							    getline(file,Class,',');
							    file.getline(Password,10);
							    if(strcmp( Student_ID, user) == 0)
							   	{
							    	 tomau(15,14,No+"-"+Student_ID+"-"+First_Name+"-"+Last_Name+"-"+Gender+"-"+Date_of_Birth
							    	 +"-"+Social_ID+"-"+Class+"-"+Password,13);
							    	break;
							    }
							}
							file.close();
							tomau(15,17,"Bam phim bat ky de tiep tuc ",13);
							_getch();
							break;	
					    
					}
		    }
	}
	

	 system("pause");
	 return 0;
}














