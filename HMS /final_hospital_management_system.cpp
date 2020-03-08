/***
  * Name Jinnat Morol
  * Date : 10/12/17
***/

#include<bits/stdc++.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include <conio.h>
#include <stdlib.h>

using namespace std;


int login();
int back_main();
int admin_choose_opction();
int reception_choose_opction();
int main_back_admin();
int opction_select_admin();

int admin_main_menu();
int admin_developer_information();
int admin_reception_staff_information();
int patient_display_admin();
int patient_search_admin();
int patient_search_admin_display();
int admin_exit();

int reception_main_menu();
int doctor_search_reception();
int doctor_search_reception_display();
int reception_exit();
int opction_select_reception();

int doctor_database();
int doctor_search();
int doctor_search_display();
int doctor_add();
int doctor_update();
int doctor_delete();

int staff_database();
int staff_add();
int staff_search();
int staff_search_display();
int staff_update();
int staff_delete();

int patient_database();
int patient_add();
int patient_update();
int patient_search();
int patient_search_display();
int patient_delete();

float time(){

  time_t rawtime;
  struct tm * timeinfo;
  time (&rawtime);
  timeinfo = localtime (&rawtime);

  printf ("\n\t\t\t\t\t\t\t\t\t\t\t\tClock : %s\n", asctime(timeinfo));
}




int main()
{
    system("cls");
    system("COLOR 3F");
    
    cout<<"\n******************************************************************************************************************************** \n"<<endl;
    cout<<"\t\t\t\t\t\t\tWELCOME TO FATEMA HOSPITAL MANAGEMENT SYSTEM\t\n"<<endl;
    cout<<"\n******************************************************************************************************************************** \n"<<endl;
   
    time();
   
    cout<<"\n\t 1--> Admin Part : "<<endl;
   
    cout<<"\n\t 2--> Reception Part : "<<endl;
   
    cout<<"\n******************************************************************************************************************************** \n"<<endl;
    
    login();


 }
 

int back_main(){
    
    cout<<"\n\t\t 1--> Admin Part : "<<endl;
   
    cout<<"\n\t\t 2--> Reception Part : "<<endl;
   
    cout<<"\n******************************************************************************************************************************** \n"<<endl;

    login();

}

int login(){              //   start log in function

        int choose;

        cout<<"\n\tChoose Opction : ";
        cin>>choose;
  
 

if(choose == 1){         // start  admin registaction & log in 
        
        system("cls");
        system("COLOR 3F");

        cout<<"\n******************************************************************************************************************************** \n"<<endl;
        cout<<"\t\t\t\t\t\t\tWELCOME TO FATEMA HOSPITAL MANAGEMENT SYSTEM\t\n"<<endl;
        cout<<"\n******************************************************************************************************************************** \n"<<endl;        
        time();
        
        char uname[30],upass[20],back_password[30],back_nam[30], a, name[50], pass[30],email[20],phone_number[20], gender[20];
        int ck,i,f;
       
        
        cout<<"\n\t1--> Admin Registration."<<endl;
        
        cout<<"\n\t2--> Forgot Registration"<<endl;
        
        cout<<"\n\t3--> Admin Log in."<<endl;
        
       
        cout<<"\n\n\tChoose Opction : ";
        int ad;
        cin >> ad;

        if(ad==1){

            char hide_pass_admin[20],aaa;
 
          
           FILE *fptr;

           fptr = fopen("regis_admin.txt", "a");      
          
           if(fptr == NULL)
           {
               cout<<"\nError!"<<endl;
               exit(1);
           }
           // registrationh
          
           cout<<"\n\tAdmin registration.....\n"<<endl;
          
           cout<<"\n\tEnter username for Admin : " ;
           cin>>name;
           
           cout<<"\n\tEnter password for Admin : ";
           
            for(i=0;;){  //infinite loop

                  aaa=getch();//stores char typed in a
                
           
                if((aaa >= 'a'&& aaa <= 'z')||(aaa >= 'A' && aaa <= 'Z')||(aaa >= '0' && aaa <= '9'))
                //check if a is numeric or alphabet
                {
                    hide_pass_admin[i]=aaa;//stores a in pass
                    ++i;
                    cout<<"*";
                }
               
            
                if(aaa =='\b' && i >=1)//if user typed backspace
                //i should be greater than 1.
                {
                    cout<<"\b \b";//rub the character behind the cursor.
                    --i;
                }
               
            
                if(aaa =='\r')//if enter is pressed
                {
                    hide_pass_admin[i]='\0';//null means end of string.
                    break;//break the loop
                }
            }
           
           cout<<"\n\n\tEnter Email for Admin : ";
           cin>> email;
           
           cout<<"\n\tEnter Phone Number for Admin : ";
           cin>> phone_number;
           
           cout<<"\n\tEnter Gender for Admin : ";
          
           cout<<"\n\n\t\t1--> Male."<<endl;
          
           cout<<"\n\t\t2--> Female."<<endl;

           cout<<"\n\tChoose Opction : --> ";
           
           int gf;
           cin>> gf;
           
           if(gf==1){

            char gender2[20]="male";
           
           fprintf(fptr,"\n%s\t %s\t %s\t %s\t %s\n", name,  hide_pass_admin, email, phone_number, gender2);
         
          }
         
          else if(gf==2){

            char gender3[20]="female";

            fprintf(fptr,"\n%s\t %s\t %s\t %s\t %s\n", name,  hide_pass_admin, email, phone_number, gender3);
         
          }
           
           fclose(fptr);


                   int www;
                   cout<<"\n******************************************************************************************************************************** \n"<<endl;                  
                    cout<<"\n\tBack to Main Menu to press 1--> ";
                   cin >> www;
                   
                   if(www == 1){

                   system("cls");
                   
                   cout<<"\n******************************************************************************************************************************** \n"<<endl;
                   cout<<"\t\t\t\t\t\t\tWELCOME TO FATEMA HOSPITAL MANAGEMENT SYSTEM\t\n"<<endl;
                   cout<<"\n******************************************************************************************************************************** \n"<<endl; 
                    back_main();                 //wrong password so call back_main function
 
                 }// close registraction


        }

     
        else if(ad==2){        // start forget registraction
           
           char hide_pass_admin_forget[20],as;

           FILE *fptr;
           FILE *fptr2;

           fptr = fopen("regis_admin.txt", "r");
           fptr2 = fopen("exchange_regis_admin.txt", "a");       
          
           if(fptr2 == NULL)
           {
               cout<<"\nError!"<<endl;
               exit(1);
           }
           // registrationh
          
           cout<<"\n\tAdmin registration.....\n"<<endl;
          
           cout<<"\n\tEnter username for Admin : " ;
           cin>>name;
           
           cout<<"\n\tEnter password for Admin : ";
          
           for(i=0;;){  //infinite loop

                  as = getch();//stores char typed in a
                
           
                if((as >= 'a'&& as <= 'z') || (as >='A' && as <='Z') || (as >='0' && as <='9'))
                //check if a is numeric or alphabet
                {
                    hide_pass_admin_forget[i]=as;//stores a in pass
                    ++i;
                    cout<<"*";
                }
               
            
                if(as =='\b'&&i>=1)//if user typed backspace
                //i should be greater than 1.
                {
                    cout<<"\b \b";//rub the character behind the cursor.
                    --i;
                }
               
            
                if(as =='\r')//if enter is pressed
                {
                    hide_pass_admin_forget[i]='\0';//null means end of string.
                    break;//break the loop
                }
            }
           
           cout<<"\n\n\tEnter Email for Admin : ";
           cin>> email;
           
           cout<<"\n\tEnter Phone Number for Admin : ";
           cin>> phone_number;
           
           cout<<"\n\tEnter Gender for Admin : ";
          
           cout<<"\n\n\t\t1--> Male."<<endl;
           cout<<"\n\t\t2--> Female."<<endl;

           cout<<"\n\tChoose Opction : --> ";
           
           int gf;
         
           cin>> gf;
           
           if(gf==1){

            char gender4[20]="male";
           
           fprintf(fptr2,"\n%s\t %s\t %s\t %s\t %s\n", name,  hide_pass_admin_forget, email, phone_number, gender4);
         
          }
        
          else if(gf==2){

            char gender5[20]="female";

            fprintf(fptr2,"\n%s\t %s\t %s\t %s\t %s\n", name,  hide_pass_admin_forget, email, phone_number, gender5);
          }
          
           
           fclose(fptr2);
           fclose(fptr);

          remove("regis_admin.txt");
          rename("exchange_regis_admin.txt", "regis_admin.txt"); 


                   int wwww;
                  
                   cout<<"\n******************************************************************************************************************************** \n"<<endl;                   
                   cout<<"\n\tBack to Main Menu to press 1--> ";
                   
                   cin >> wwww;
                   
                   if(wwww == 1){

                   system("cls");
                   
                   cout<<"\n******************************************************************************************************************************** \n"<<endl;
                   cout<<"\t\t\t\t\t\t\tWELCOME TO FATEMA HOSPITAL MANAGEMENT SYSTEM\t\n"<<endl;
                   cout<<"\n******************************************************************************************************************************** \n"<<endl;
 
                    back_main(); 
          

              }   // close forget registraction

        }

        else if(ad == 3){          // start log in

           FILE *fptr;
           fptr = fopen("regis_admin.txt", "r");
           
        
           if(fptr == NULL)
           {
               cout<<"\nError!"<<endl;
               exit(1);
           }
           
           char uname3[20],name3[20],password3[20],aa,pass[20];
           
           int i1,f1,ck3;

           cout<<"\n\tNow login This System .....\n"<<endl;
          
           cout<<"\n\tEnter username : ";
           cin>>uname3;
           
           cout<<"\n\tEnter password : ";
         
          
           while(fscanf(fptr,"%s %s\n",name3,password3)!=EOF)
                {
                    
                f1 = strcmp(name3,uname3);
           

              for(i1=0;;){  //infinite loop

                    aa=getch();//stores char typed in a
               
           
                if((aa>='a'&& aa<='z')||(aa>='A'&& aa<='Z')||(aa>='0'&& aa<='9'))
                //check if a is numeric or alphabet
                {
                    pass[i1]=aa;//stores a in pass
                    ++i1;
                    cout<<"*";
                }
                
           
                if(aa =='\b'&& i1>=1)//if user typed backspace
                //i should be greater than 1.
                {
                    cout<<"\b \b";//rub the character behind the cursor.
                    --i1;
                }
                
         
                if(aa =='\r')//if enter is pressed
                {
                    pass[i1]='\0';//null means end of string.
                    break;//break the loop
                }
            }
          
   
         
            ck3=strcmp(pass,password3);
            
              fclose(fptr); 
            }
            
        
            if(ck3==0 && f1==0){

                 system("cls");
               
                cout<<"\n******************************************************************************************************************************** \n"<<endl;
                cout<<"\t\t\t\t\t\t\tWELCOME TO FATEMA HOSPITAL MANAGEMENT SYSTEM\t\n"<<endl;
                cout<<"\n******************************************************************************************************************************** \n"<<endl;
               
                time();

               admin_choose_opction();
            
            }
       
            else{
                
                system("cls");
                
                cout<<"\n******************************************************************************************************************************** \n"<<endl;
                cout<<"\t\t\t\t\t\t\tWELCOME TO FATEMA HOSPITAL MANAGEMENT SYSTEM\t\n"<<endl;
                cout<<"\n******************************************************************************************************************************** \n"<<endl;
                
                time();
               
                cout<<"\n\n\tWrong Password and Now enter right requirements\n"<<endl;
                //pass[0]='\0';
               // uname[0]='\0';

                back_main();                 //wrong password so call back_main function
            }



        }  //close log in

 }   // close  admin registaction & log in n 
   

//reception part checking name and password
//in this code
//log in reception
else if (choose==2){      //  reception part registraction and log in

         system("cls");
         system("COLOR 3F");

        cout<<"\n******************************************************************************************************************************** \n"<<endl;
        cout<<"\t\t\t\t\t\t\tWELCOME TO FATEMA HOSPITAL MANAGEMENT SYSTEM\t\n"<<endl;
        cout<<"\n******************************************************************************************************************************** \n"<<endl;
        
        time();
        
      
        char uname[30],upass[20],back_password[30],back_nam[30], a, name[50], pass[30],email[20],phone_number[20], gender[20];
       
       
        int ck,i,f;
       
        cout<<"\n\t1--> Reception Registration."<<endl;
       
        cout<<"\n\t2--> Forgot Registration"<<endl;
        
        cout<<"\n\t3--> Reception Log in."<<endl;
       
        
        cout<<"\n\tChoose Opction : ";
        int ad1;
        cin >> ad1;

        
        if(ad1==1){          //  start registraction reception

          char hide_pass_reception[20],bb;
 
           FILE *fptr;
           fptr = fopen("regis_reception.txt", "a");
         
           if(fptr == NULL)
           {
               cout<<"\nError!"<<endl;
               exit(1);
           }
           // registrationh
         
           cout<<"\n\tReception registration.....\n"<<endl;
          
           cout<<"\n\tEnter username for Reception : " ;
           cin>>name;
          
           cout<<"\n\tEnter password for Reception : ";
            
           for(i=0;;){  //infinite loop

                  bb=getch();//stores char typed in a
                
           
                if((bb >= 'a'&& bb <= 'z')||(bb >= 'A' && bb <= 'Z')||(bb >= '0' && bb <= '9'))
                //check if a is numeric or alphabet
                {
                    hide_pass_reception[i] = bb;//stores a in pass
                    ++i;
                    cout<<"*";
                }
               
            
                if(bb =='\b' && i >=1)//if user typed backspace
                //i should be greater than 1.
                {
                    cout<<"\b \b";//rub the character behind the cursor.
                    --i;
                }
               
            
                if(bb =='\r')//if enter is pressed
                {
                    hide_pass_reception[i]='\0';//null means end of string.
                   
                    break;//break the loop
                }
            }
           
           cout<<"\n\n\tEnter Email for Reception : ";
           cin>> email;
           
           cout<<"\n\tEnter Phone Number for Reception : ";
           cin>> phone_number;
           
           cout<<"\n\tEnter Gender for Reception : ";
            
           cout<<"\n\n\t\t1--> Male."<<endl;
           cout<<"\n\t\t2--> Female."<<endl;

           cout<<"\n\tChoose Opction : --> ";
           
           int fg;
           cin>> fg;
           
           if(fg==1){

            char gender6[20]="male";
           
           fprintf(fptr,"\n%s\t %s\t %s\t %s\t %s\n", name,  hide_pass_reception, email, phone_number, gender6);
          }
         
          else if(fg==2){

            char gender7[20]="female";

            fprintf(fptr,"\n%s\t %s\t %s\t %s\t %s\n", name,  hide_pass_reception, email, phone_number, gender7);
          }
 
           fclose(fptr);

                  int we;
                 
                   cout<<"\n******************************************************************************************************************************** \n"<<endl;
                   cout<<"\n\tBack to Main Menu to press 1--> ";
                   cin >> we;
                   
                   if(we == 1){

                   system("cls");
                   
                   cout<<"\n******************************************************************************************************************************** \n"<<endl;
                   cout<<"\t\t\t\t\t\t\tWELCOME TO FATEMA HOSPITAL MANAGEMENT SYSTEM\t\n"<<endl;
                  cout<<"\n******************************************************************************************************************************** \n"<<endl;
 
                    back_main(); 
            
                }    //  close registraction reception

        }

        else if(ad1==2){       // start forget reception
           
           char hide_pass_forget_reception[20],bs;

           FILE *fptr4;
           FILE *fptr3;

           fptr4 = fopen("regis_reception.txt", "a");
           fptr3 = fopen("exchange_regis_reception.txt", "a");
         
           if(fptr3 == NULL)
           {
               cout<<"\nError!"<<endl;
               exit(1);
           }
           // registrationh
         
           cout<<"\n\tReception registration.....\n"<<endl;
          
           cout<<"\n\tEnter username for Reception : " ;
           cin>>name;
          
           cout<<"\n\tEnter password for Reception : ";
           
           for(i=0;;){  //infinite loop

                  bs = getch();//stores char typed in a
                
           
                if((bs >= 'a'&& bs <= 'z') || (bs >='A' && bs <='Z') || (bs >='0' && bs <='9'))
                //check if a is numeric or alphabet
                {
                    hide_pass_forget_reception[i] = bs;//stores a in pass
                    ++i;
                    cout<<"*";
                }
               
            
                if(bs =='\b' && i>=1)//if user typed backspace
                //i should be greater than 1.
                {
                    cout<<"\b \b";//rub the character behind the cursor.
                    --i;
                }
               
            
                if(bs =='\r')//if enter is pressed
                {
                    hide_pass_forget_reception[i]='\0';//null means end of string.
                    break;//break the loop
                }
            } 


           cout<<"\n\n\tEnter Email for Reception : ";
           cin>> email;
           
           cout<<"\n\tEnter Phone Number for Reception : ";
           cin>> phone_number;
           
           cout<<"\n\tEnter Gender for Reception : ";
          
           cout<<"\n\n\t\t1--> Male."<<endl;
           cout<<"\n\t\t2--> Female."<<endl;

           cout<<"\n\tChoose Opction : --> ";
           
           int gf2;
           cin>> gf2;
           
           if(gf2==1){

            char gender8[20]="male";
           
           fprintf(fptr3,"\n%s\t %s\t %s\t %s\t %s\n", name,  hide_pass_forget_reception, email, phone_number, gender8);
          
          }
         
          else if(gf2==2){

            char gender9[20]="female";

            fprintf(fptr3,"\n%s\t %s\t %s\t %s\t %s\n", name,  hide_pass_forget_reception, email, phone_number, gender9);
          }
           
        
           fclose(fptr3);
           fclose(fptr4);

           remove("regis_reception.txt");
           rename("exchange_regis_reception.txt", "regis_reception.txt"); 

                  int we1;
                   cout<<"\n******************************************************************************************************************************** \n"<<endl;
                   cout<<"\n\tBack to Main Menu to press 1--> ";
                   cin >> we1;
                   
                   if(we1 == 1){

                   system("cls");
                   
                   cout<<"\n******************************************************************************************************************************** \n"<<endl;
                   cout<<"\t\t\t\t\t\t\tWELCOME TO FATEMA HOSPITAL MANAGEMENT SYSTEM\t\n"<<endl;
                   cout<<"\n******************************************************************************************************************************** \n"<<endl;
 
                    back_main(); 
               
          
            }  // close forget rag in reception

        }
 
         else if(ad1 == 3){      // start log in reception

           FILE *fptr;
           fptr = fopen("regis_reception.txt", "r");
          
          
           if(fptr == NULL)
           {
               cout<<"\nError!"<<endl;
               exit(1);
           }
           
           char uname3[20],name3[20],password3[20],aa,pass[20];
           int i1,f1,ck3;

          
           cout<<"\n\tNow login This System .....\n"<<endl;
           
           cout<<"\n\tEnter username : ";
           cin>>uname3;
           
           cout<<"\n\tEnter password : ";
           
          
           while(fscanf(fptr,"%s %s\n",name3,password3)!=EOF)
                {
                    
                f1 = strcmp(name3,uname3);
            
           
              for(i1=0;;){  //infinite loop

                    aa=getch();//stores char typed in a
                
            
                if((aa>='a'&& aa<='z')||(aa>='A'&& aa<='Z')||(aa>='0'&& aa<='9'))
                //check if a is numeric or alphabet
                {
                    pass[i1]=aa;//stores a in pass
                    ++i1;
                    cout<<"*";
                }
               
            
                if(aa =='\b'&& i1>=1)//if user typed backspace
                //i should be greater than 1.
                {
                    cout<<"\b \b";//rub the character behind the cursor.
                    --i1;
                }
               
            
                if(aa =='\r')//if enter is pressed
                {
                    pass[i1]='\0';//null means end of string.
                    break;//break the loop
                }
            }
          
   
            ck3=strcmp(pass,password3);
          
           fclose(fptr); 
          
          }
         
            if(ck3==0 && f1==0){

                system("cls");
               
                cout<<"\n******************************************************************************************************************************** \n"<<endl;
                cout<<"\t\t\t\t\t\t\tWELCOME TO FATEMA HOSPITAL MANAGEMENT SYSTEM\t\n"<<endl;
                cout<<"\n******************************************************************************************************************************** \n"<<endl;
               
                time();
              
                reception_choose_opction();
            }
          
            else{
               
                system("cls");
               
                cout<<"\n******************************************************************************************************************************** \n"<<endl;
                cout<<"\t\t\t\t\t\t\tWELCOME TO FATEMA HOSPITAL MANAGEMENT SYSTEM\t\n"<<endl;
                cout<<"\n******************************************************************************************************************************** \n"<<endl;
                
                time();
               
                cout<<"\n\n\tWrong Password and Now enter right requirements\n"<<endl;
                //pass[0]='\0';
               // uname[0]='\0';

                back_main();                 //wrong password so call back_main function
            }



        } // end log in

}   //   close reception registraction & log in


}     //   close log in function





int admin_choose_opction(){       //    start admin choose opction function

    system("COLOR 3F");

    cout<<"\n\n\t\t1--> Main Menu"<<endl;
   
    cout<<"\n\t\t2--> Developer Information"<<endl;

    cout<<"\n\t\t3--> Reception login Staff Information"<<endl;
   
    cout<<"\n\t\t4--> Exit"<<endl;
   
    cout<<"\n******************************************************************************************************************************** \n"<<endl;
    
    opction_select_admin();

}


int opction_select_admin(){      // start opction select opction admin

    int ck;
   
    cout<<"\tchoose Opction : ";
    cin>>ck;

    switch(ck){

        case 1:
        admin_main_menu();
        break;

        case 2:
        admin_developer_information();
        break;

        case 3:
        admin_reception_staff_information();
        break;

        case 4:
        admin_exit();
    }

}    // close opction select opction admin


int admin_reception_staff_information(){


        system("cls");
        system("COLOR 3F");

        cout<<"\n******************************************************************************************************************************** \n"<<endl;
        cout<<"\t\t\t\t\t\t\tRegistraction Reception Staff Informaction.\t\n"<<endl;
        cout<<"\n******************************************************************************************************************************** \n"<<endl;
       
        time();

      char ree_name[20], ree_password[20], ree_email[20], ree_number[20], ree_gender[20];

      FILE * morol;
      morol = fopen("regis_reception.txt","r");

      while(fscanf(morol,"%s\t %s\t %s\t %s\t %s\n",ree_name, ree_password, ree_email, ree_number, ree_gender)!=EOF){
        

        printf("\n\n\tReception staff Name : %s\n", ree_name);
       
        printf("\n\tReception staff Email : %s\n", ree_email);
       
        printf("\n\tReception staff Number : %s\n", ree_number);
      
        printf("\n\tReception staff Gender : %s\n", ree_gender);
 
      }

      fclose(morol);

                int kd;
                
                cout<<"\n******************************************************************************************************************************** \n"<<endl;
                cout<<"\n\tBack to Main Menu to press 1--> ";
                cin>>kd;
                          
                if(kd==1){

                system("cls");
                          
               cout<<"\n******************************************************************************************************************************** \n"<<endl;
               cout<<"\t\t\t\t\t\t\tWELCOME TO FATEMA HOSPITAL MANAGEMENT SYSTEM\t\n"<<endl;
               cout<<"\n******************************************************************************************************************************** \n"<<endl;
                          
               admin_choose_opction();
                           
           }


}


int admin_exit(){
     
     cout<<"\n\tLog out this system....."<<endl;

     cout<<"\n\tIf Choose Again LOG IN This System so Enter --> 1  or EXIT  this System so Enter  AnyKey... ";
     int gg;
     cin>>gg;
     if(gg==1){
    
     main();

}

}


int admin_main_menu(){
       
        system("cls");
        system("COLOR 3F");

        cout<<"\n******************************************************************************************************************************** \n"<<endl;
        cout<<"\t\t\t\t\t\t\t\tADMIN MAIN MENU\t\n"<<endl;
        cout<<"\n******************************************************************************************************************************** \n"<<endl;
       
        time();
       
       
        cout<<"\n\t\t1--> Enter into Doctor's File.\n"<<endl;
       
        cout<<"\t\t2--> Search Any Present Information From File.\n"<<endl;
       
        cout<<"\t\t3--> Enter into Stuf File.\n"<<endl;
       
        cout<<"\t\t4--> Exit.\n"<<endl;
        
        cout<<"\n******************************************************************************************************************************** \n"<<endl;
        int main_choose;
       
       
        cout<<"\n\tChoose Opction : ";
        cin>>main_choose;

       
        if(main_choose==1){

            doctor_database();

        } 

        else if(main_choose==2){     // search any patient informaction start now admin
             
             patient_search_admin();
        }   // search any patient informaction close  now  admin
 
        else if(main_choose==3){   //start stuf database now admin 

            staff_database();

        }          

        // staff of this line
        else if(main_choose==4){   // exit

        system("cls");
       
        cout<<"\n******************************************************************************************************************************** \n"<<endl;
        cout<<"\t\t\t\t\t\t\tWELCOME TO FATEMA HOSPITAL MANAGEMENT SYSTEM\t\n"<<endl;
        cout<<"\n******************************************************************************************************************************** \n"<<endl;
        
            admin_choose_opction();// back to admin_choose_opction function
        }
    } //main menu ck == 1 now   stop
  


 
int patient_search_admin_display(){

         

                           system("cls");
                           system("COLOR 3F");

                           cout<<"\n******************************************************************************************************************************** \n"<<endl;
                           cout<<"\t\t\t\t\t\t\tDisplay All Patient Information\n"<<endl;
                           cout<<"\n******************************************************************************************************************************** \n"<<endl;
                           
                           time();

                            char ser_id[20],id1[20],name1[20],age1[20],problem1[20], phone1[20], city1[20], admission_date1[20], dischange_date1[20], next_consultation_date1[20], present_bills1[20], present_report1[20];

                           FILE *morol;
                           morol = fopen("present1.txt","r");
                       
                       if(morol == NULL){

                         printf("Error!");
                           exit(1);
                        }   
                       cout<<"\n\tAll Patient Id From File : ";

                     while(fscanf(morol,"%s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\n", id1, name1, age1, problem1, phone1, city1, admission_date1, dischange_date1, next_consultation_date1, present_bills1, present_report1 )!=EOF){
                        
                       
                     	cout<<id1<<"   ";
                     }
                     fclose(morol);
                          
                           


}

int patient_search_admin(){
         
                       
                       patient_search_admin_display();

                       cout<<"\n\n\tSearch Information..."<<endl;
 
                       char ser_id[20],id1[20],name1[20],age1[20],problem1[20], phone1[20], city1[20], admission_date1[20], dischange_date1[20], next_consultation_date1[20], present_bills1[20], present_report1[20];

                       cout<<"\n\tSearch Patient Id : ";
                       cin >> ser_id;
                      
                       FILE *morol;
                       morol = fopen("present1.txt","r");
                       
                       if(morol == NULL){

                         printf("Error!");
                           exit(1);
                        }   
                     
                     while(fscanf(morol,"%s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\n", id1, name1, age1, problem1, phone1, city1, admission_date1, dischange_date1, next_consultation_date1, present_bills1, present_report1 )!=EOF){
                     
                  int dk;
                 
                  dk = strcmp(id1, ser_id);
                 // cout<<dk<<endl;
                  //cout<<id1<<endl;
                  //cout<<ser_id<<endl;
                  
                  if(dk == 0){
                
                  cout<<"\n\tPatient Information : \n"<<endl;
                 
                  cout<< "\n\t\tPatient Id : " << id1 <<endl;
                 
                  cout<< "\n\t\tPatient Name : " << name1 <<endl;
                 
                  cout<< "\n\t\tPatient Age : "<< age1 <<endl;
                 
                  cout<< "\n\t\tPatient problem : "<< problem1 <<endl;
                 
                  cout<< "\n\t\tPatient Phone Number : "<< phone1 <<endl;
                 
                  cout<< "\n\t\tPatient City : "<< city1 <<endl;
                 
                  cout<< "\n\t\tPatient Admission_date : "<< admission_date1 <<endl;
                
                  cout<< "\n\t\tPatient Dischange_date : "<< dischange_date1 <<endl;
                
                  cout<< "\n\t\tPatient Next_consultation_date : "<< next_consultation_date1 <<endl;
                
                  cout<< "\n\t\tPatient Present_bills : "<< present_bills1 <<endl;
                
                  cout<< "\n\t\tPatient Present_report : "<< present_report1 <<endl;
                 
                  break;           
                 
                 }
 
             }
             fclose(morol);

                   int w;
                   cout<<"\n******************************************************************************************************************************** \n"<<endl;
                   cout<<"\n\tBack to Main Menu to press 1--> ";
                   cin>>w;
                
                  if(w==1){

                   system("cls");
                  
                   cout<<"\n******************************************************************************************************************************** \n"<<endl;
                   cout<<"\t\t\t\t\t\t\tWELCOME TO FATEMA HOSPITAL MANAGEMENT SYSTEM\t\n"<<endl;
                  cout<<"\n******************************************************************************************************************************** \n"<<endl;
                  
                   admin_main_menu();

                }


}


int  doctor_search_display(){

             system("cls");
             system("COLOR 3F");
             
             cout<<"\n******************************************************************************************************************************** \n"<<endl;
             cout<<"\t\t\t\t\t\t\tSee All Doctor's Information\n"<<endl;
             cout<<"\n******************************************************************************************************************************** \n"<<endl;
             
             time();
            
             char id[20], name[20], age[20], specilast[20], experience[20], city[20], visit_tk[20], visit_time[20], search[20];

            FILE *doctor;

            doctor = fopen("doctor.txt","r");
              
               if(doctor == NULL){

                  printf("Error!");
                  exit(1);
                
                }
              
              cout<<"\n\tAll Doctor Id From File : ";

             while(fscanf(doctor,"%s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\n", id, name, age, specilast, experience, city, visit_tk, visit_time)!=EOF){
                   
                   cout<<id<<"  ";

             }
                 fclose(doctor);
                
         
 
}

int doctor_search(){
 
 
             doctor_search_display();

             cout<<"\n\n\tSearch Information : "<<endl;

             char id[20], name[20], age[20], specilast[20], experience[20], city[20], visit_tk[20], visit_time[20], search[20];
              
               cout<<"\n\tSearch Doctor Id : ";
               cin>>search;
            
             FILE *doctor;

            doctor = fopen("doctor.txt","r");
              
               if(doctor == NULL){

                  printf("Error!");
                  exit(1);
                
                }
             
             while(fscanf(doctor,"%s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\n", id, name, age, specilast, experience, city, visit_tk, visit_time)!=EOF){
 
                 int ck=0;
                 ck = strcmp(id, search);
            
             if(ck==0){
                 
                  cout<<"\n\tDoctor Information : \n"<<endl;
                 
                  cout<< "\n\t\tDoctor Id : " << id <<endl;
                 
                  cout<< "\n\t\tDoctor Name : " << name <<endl;
                 
                  cout<< "\n\t\tDoctor Age : "<< age <<endl;
                 
                  cout<< "\n\t\tDoctor Specilast : "<<specilast <<endl;
                 
                  cout<< "\n\t\tDoctor Experience Years : "<<experience <<endl;
                 
                  cout<< "\n\t\tDoctor City : "<<city <<endl;
                 
                  cout<< "\n\t\tDoctor Visti_tk : "<<visit_tk <<endl;
                 
                  cout<< "\n\t\tDoctor Visit_time : "<<visit_time <<endl;
                    break;           
                 }

             }

             fclose(doctor); 

                int u;
               cout<<"\n******************************************************************************************************************************** \n"<<endl;
                  
                   cout<<"\n\tBack to Main Menu to press 1--> ";
                   cin>>u;
                  
                  if(u==1){

                   system("cls");
                  
                   cout<<"\n******************************************************************************************************************************** \n"<<endl;
                   cout<<"\t\t\t\t\t\t\tWELCOME TO FATEMA HOSPITAL MANAGEMENT SYSTEM\t\n"<<endl;
                   cout<<"\n******************************************************************************************************************************** \n"<<endl;
                 
                     doctor_database();


            }

}



int doctor_add(){
  
 
           doctor_search_display();
           
           cout<<"\n\n\tAdd Doctor Information : "<<endl;
          char dr_id[10], dr_name[15],dr_age[10] ,dr_Specilast[15], dr_Experience[10],dr_City[10],dr_Visti_tk[10],dr_visit_time[20];
 
          FILE *doctor;
          doctor = (fopen("doctor.txt", "a"));
         
         
            if(doctor == NULL){
               
                printf("Error!");
                exit(1);
            }

               cout<<"\n\tDoctor Id : ";
               cin>>dr_id;
              
               cout<<"\n\tDoctor Name : ";
               cin>>dr_name;
              
               cout<<"\n\tDoctor Age : ";
               cin>>dr_age;
             
               cout<<"\n\tDoctor Specilast : ";
               cin>>dr_Specilast;
             
               cout<<"\n\tDoctor Experience Years : ";
               cin>>dr_Experience;
              
               cout<<"\n\tDoctor City : ";
               cin>>dr_City;
              
               cout<<"\n\tDoctor Visti_tk : ";
               cin>>dr_Visti_tk;
              
               cout<<"\n\tDoctor Visit_time : ";
               cin>>dr_visit_time;
   
        
            fprintf(doctor, "\n%s\t %s\t    %s\t    %s\t %s\t %s\t %s\t %s\n",dr_id, dr_name, dr_age, dr_Specilast, dr_Experience, dr_City, dr_Visti_tk, dr_visit_time);

            fclose(doctor);

            int h;
            cout<<"\n******************************************************************************************************************************** \n"<<endl;
                 cout<<"\n\tBack to Main Menu to press 1--> ";
                 cin>>h;
          
                 if(h==1){
      
           system("cls");
       
        cout<<"\n******************************************************************************************************************************** \n"<<endl;
        cout<<"\t\t\t\t\t\t\tWELCOME TO FATEMA HOSPITAL MANAGEMENT SYSTEM\t\n"<<endl;
        cout<<"\n******************************************************************************************************************************** \n"<<endl;
           
            doctor_database();
        } 
       

}



int doctor_update(){

   
                 doctor_search_display();

                 char search_id[20], id[20], name[20], age[20], specilast[20], experience[20], city[20], visit_tk[20], visit_time[20];
                 
                 char name1[20], age1[20], specilast1[20], experience1[20], city1[20], visit_tk1[20], visit_time1[20];

                    FILE * doctor;
                    FILE * doctor2;
                   
                    doctor = fopen("doctor.txt","r");
                    doctor2 =  fopen("doc_exchange.txt","a");
                    
                    cout<<"\n\n\tSearch Edit Doctor Id : ";
                    cin>>search_id;

              
                    while(fscanf(doctor,"%s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\n",id, name, age, specilast, experience, city, visit_tk, visit_time)!=EOF){
         

                 if(strcmp(search_id, id)==0){
                   
                   cout<<"\n\t\t1--> Change name : "<<endl;
                  
                   cout<<"\n\t\t2--> Change age : "<<endl;
                  
                   cout<<"\n\t\t3--> Change specilast : "<<endl;
                  
                   cout<<"\n\t\t4--> Change experience : "<<endl;
                  
                   cout<<"\n\t\t5--> Change city : "<<endl;
                 
                   cout<<"\n\t\t6--> Change visit_tk : "<<endl;
               
                   cout<<"\n\t\t7--> Change visit_time : "<<endl;

                   int n5;

                   cout<<"\n\tChoose Opction : ";
                   cin >> n5;

                   if(n5 == 1){

                      cout<<"\n\tPrevious Name : ";
                      printf("%s\n", name);

                      cout<<"\n\tUpdate  Name : ";
                      
                       cin >> name1;
                      
                       fprintf(doctor2, "%s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\n",id, name1, age, specilast, experience, city, visit_tk, visit_time);
                   }

                   else if(n5 == 2){
                       
                      cout<<"\n\tPrevious Age : ";
                      
                      printf("%s\n", age);
                      
                       cout<<"\n\tUpdate Age : ";
                      
                       cin >> age1;
                      
                       fprintf(doctor2, "%s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\n",id, name, age1, specilast, experience, city, visit_tk, visit_time);
                   
                   }

                   else if(n5 == 3){

                       cout<<"\n\tPrevious Specilast : ";

                       printf("%s\n", specilast);
 
                       cout<<"\n\tUpdate Specilast : ";
                       
                       cin >> specilast1;
                       
                       fprintf(doctor2, "%s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\n",id, name, age, specilast1, experience, city, visit_tk, visit_time);
                   
                   }

                   else if(n5 == 4){

                      cout<<"\n\tPrevious Experience Year : ";
                      printf("%s\n", experience);
 
                       cout<<"\n\tUpdate  Experience : ";
                      
                       cin >> experience1;
                      
                       fprintf(doctor2, "%s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\n",id, name, age, specilast, experience1, city, visit_tk, visit_time);
                   
                   }

                  else if(n5 == 5){

                    cout<<"\n\tPrevious City : ";

                    printf("%s\n", city);
  
                       cout<<"\n\tUpdate City : ";
                      
                       cin >> city1;
                      
                       fprintf(doctor2, "%s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\n",id, name, age, specilast, experience, city1, visit_tk, visit_time);
                   
                   }

                   else if(n5 == 6){

                    cout<<"\n\tPrevious Visit Tk: ";

                    printf("%s\n", visit_tk);
 
                       cout<<"\n\tUpdate Visit Tk : ";
                      
                       cin >> visit_tk1;
                      
                       fprintf(doctor2, "%s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\n",id, name, age, specilast, experience, city, visit_tk1, visit_time);
                   
                   }

                    else if(n5 == 7){
                       
                       cout<<"\n\tPrevious Visit Time : ";

                       printf("%s\n", visit_time);

                       cout<<"\n\tUpdate  Visit Time : ";
                      
                       cin >> visit_time1;
                      
                       fprintf(doctor2, "%s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\n",id, name, age, specilast, experience, city, visit_tk, visit_time1);
                   
                   }
                     
           }
            
            else{

               fprintf(doctor2, "%s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\n",id, name, age, specilast, experience, city, visit_tk, visit_time);
          
           }
        
         }

            fclose(doctor);
            fclose(doctor2);
           
            remove("doctor.txt");                        // source file
            rename("doc_exchange.txt","doctor.txt");   // exchange file

            int gg;
            cout<<"\n******************************************************************************************************************************** \n"<<endl;
            cout<<"\n\tBack to Main Menu to press 1--> ";
             
             cin>>gg;
            
                 if(gg==1){

           system("cls");
        
        cout<<"\n******************************************************************************************************************************** \n"<<endl;
        cout<<"\t\t\t\t\t\t\tWELCOME TO FATEMA HOSPITAL MANAGEMENT SYSTEM\t\n"<<endl;
        cout<<"\n******************************************************************************************************************************** \n"<<endl;
           
             doctor_database();
        } 


}



int doctor_delete(){

      
            doctor_search_display();

          

             char search_id[20],id[20],name[20],age[20],specilast[20],experience[20],city[20],visit_tk[20],visit_time[20];

            FILE * morol;
            FILE * morol1;
            
            morol = fopen("doctor.txt","r");
            morol1 =  fopen("doc.txt","a");

            cout<<"\n\n\tDelete Doctor ID Search : ";
            cin>>search_id;

            while(fscanf(morol,"%s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\n",id,name,age,specilast,experience,city,visit_tk,visit_time)!=EOF){
         
            if(strcmp(search_id,id)==0){
                 
                   continue;
            }
            
            else{

            fprintf(morol1, "%s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\n",id,name,age,specilast,experience,city,visit_tk,visit_time );
           
            }          
        }
            fclose(morol);
            fclose(morol1);
            
            remove("doctor.txt");   // source file
            rename("doc.txt","doctor.txt");  // exchange file

            int t;
               
                cout<<"\n******************************************************************************************************************************** \n"<<endl;
                
                   cout<<"\n\tBack to Main Menu to press 1--> ";
                   cin>>t;
                 
                  if(t==1){

                   system("cls");
                  
                   cout<<"\n******************************************************************************************************************************** \n"<<endl;
                   cout<<"\t\t\t\t\t\t\tWELCOME TO FATEMA HOSPITAL MANAGEMENT SYSTEM\t\n"<<endl;
                   cout<<"\n******************************************************************************************************************************** \n"<<endl;
                   
                     doctor_database();
                }

}





 int doctor_database(){

            system("cls");
            system("COLOR 3F");

            cout<<"\n******************************************************************************************************************************** \n"<<endl;
            cout<<"\t\t\t\t\t\t\t\tDoctor's Database\t\n"<<endl;
            cout<<"\n******************************************************************************************************************************** \n"<<endl;
           
             time();
           
            cout<<"\n\t\t1--> Add new Doctor's Information In File.\n"<<endl;            
           
            cout<<"\t\t2--> Update Doctor Information In File.\n"<<endl;
           
            cout<<"\t\t3--> Search Any Doctor Information From File.\n"<<endl;
           
            cout<<"\t\t4--> Delete Any Doctor Information From File.\n"<<endl;
          
            cout<<"\t\t5--> Exit.\n"<<endl;
           
            cout<<"\n******************************************************************************************************************************** \n"<<endl;
        
        int main_choose_doctor;
        
       
        cout<<"\n\tChoose Opction : ";
        cin>>main_choose_doctor; 

       
        if(main_choose_doctor==1){    // start add  new doctor informaction

            doctor_add();
          
        }  // / end add  new doctor informaction     
       
        else if(main_choose_doctor==2){    // start edit doctor informaction from database

            doctor_update();

        }    // end edit doctor informaction from database admin
 

        else if(main_choose_doctor==3){   // start  search doctor informaction

            doctor_search();

        }  // close search doctor informaction

        else if(main_choose_doctor==4){     //start delete any doctor in data base

            doctor_delete();

        } // close delete any doctor in data base

        else if(main_choose_doctor==5){  // back main menu start 
             
             system("cls");
            
             cout<<"\n******************************************************************************************************************************** \n"<<endl;
             cout<<"\t\t\t\t\t\t\tWELCOME TO FATEMA HOSPITAL MANAGEMENT SYSTEM\n"<<endl;
             cout<<"\n******************************************************************************************************************************** \n"<<endl;
             
            admin_choose_opction();

        }  // back main menu close 


 }


int admin_developer_information(){

        system("cls");
        system("COLOR 3F");
        
        cout<<"\n******************************************************************************************************************************** \n"<<endl;
        cout<<"\t\t\t\t\t\t\tDeveloper Information\t\n"<<endl;
        cout<<"\n******************************************************************************************************************************** \n"<<endl;
        
        time();
        
        cout<<"\n\tName : Md : Zinnatul Islam Morol."<<endl;
      
        cout<<"\n\tEmail : morolswediu@gmail.com"<<endl;
       
        cout<<"\n\tPhone Number : 01793696177"<<endl;
       
        cout<<"\n\tSWE_DIU_(22 Batch)"<<endl;
       
        cout<<"\n\t3rd Semester ( Section : C1 )"<<endl;

        cout<<"\n\tUsing Tools : "<<endl;

        cout<<"\n\t\t1--> Sublime Text ( MinGW Compailer )."<<endl;

        cout<<"\n\t\t2--> CodeBlocks."<<endl;

        cout<<"\n\t\t3--> File ( .txt )"<<endl;

        cout<<"\n\t\t4--> Language : C & C++"<<endl;
       
        cout<<"\n\n\tInstruction Help : Lamisha Rawshan (Class Madam)"<<endl;


                int h9;
                
                cout<<"\n******************************************************************************************************************************** \n"<<endl;
               
                cout<<"\n\tBack to Main Menu to press 1--> ";
                cin>>h9;
              
                if(h9==1){

                 system("cls");
                
                 cout<<"\n******************************************************************************************************************************** \n"<<endl;
                 cout<<"\t\t\t\t\t\t\tWELCOME TO FATEMA HOSPITAL MANAGEMENT SYSTEM\t\n"<<endl;
                 cout<<"\n******************************************************************************************************************************** \n"<<endl;
                
                 admin_choose_opction();

                }


}


int staff_add(){

                staff_search_display();

                cout<<"\n\n\tAdd Staff Information : "<<endl;
               
                 char staff_id[10], staff_name[15],staff_work[15] ,staff_salary[15], staff_in_out[20];
 
                 FILE *staff1;
                 staff1 = (fopen("staff.txt", "a"));
         
                 if(staff1 == NULL){
               
                  printf("Error!");
                  exit(1);
             
                 }

               cout<<"\n\tStaff Id : ";
               cin>>staff_id;
              
               cout<<"\n\tStaff Name : ";
               cin>>staff_name;
               
               cout<<"\n\tStaff work : ";
               cin>>staff_work;
              
               cout<<"\n\tStaff Salary : ";
               cin>>staff_salary;
              
               cout<<"\n\tStaff In_Out : ";
               cin>>staff_in_out;
              
               fprintf(staff1, "\n%s\t  %s\t  %s\t  %s\t  %s",staff_id, staff_name, staff_work, staff_salary, staff_in_out);

               fclose(staff1); 
              
               int p;
              
                cout<<"\n******************************************************************************************************************************** \n"<<endl;
                 cout<<"\n\tBack to Main Menu to press 1--> ";
                 
                 cin>>p;
                 if(p==1){

                system("cls");
                
                cout<<"\n******************************************************************************************************************************** \n"<<endl;
                cout<<"\t\t\t\t\t\t\tWELCOME TO FATEMA HOSPITAL MANAGEMENT SYSTEM\t\n"<<endl;
                cout<<"\n******************************************************************************************************************************** \n"<<endl;
           
                 staff_database();
                 
                }
           

}

 
int staff_search_display(){
      

             system("cls");
             system("COLOR 3F");
             
             cout<<"\n******************************************************************************************************************************** \n"<<endl;
             cout<<"\t\t\t\t\t\t\tDisplay All Staff's Information\n"<<endl;
             cout<<"\n******************************************************************************************************************************** \n"<<endl;
            
             time();
            
            char searc[20], id4[20], name4[20], work4[20], salary4[20], in_out4[20];

            FILE *staff1;

                staff1 = fopen("staff.txt", "r");
               
                if(staff1 == NULL)
                {
                   printf("Error!");
                   exit(1);
                }
               //comparison
              
              cout<<"\tAll Staff Id From File : ";
               while(fscanf(staff1,"%s\t %s\t %s\t %s\t %s\n", id4, name4, work4, salary4, in_out4) !=EOF){

                    cout<<id4<<"  ";
               }
                 
              fclose(staff1);
                 
                

}


int staff_search(){
 

                staff_search_display();

                cout<<"\n\n\tSearch Information : "<<endl;
               
                char searc[20], id4[20], name4[20], work4[20], salary4[20], in_out4[20];
             
                cout <<"\n\tSearch Staff Id : ";                                   
                cin >> searc;  
                          
                FILE *staff1;

                staff1 = fopen("staff.txt", "r");
               
                if(staff1 == NULL)
                {
                   printf("Error!");
                   exit(1);
                }
               //comparison
             
               while(fscanf(staff1,"%s\t %s\t %s\t %s\t %s\n", id4, name4, work4, salary4, in_out4) !=EOF){
             
                int uk;
                uk = strcmp( id4, searc);
                 
           if(uk==0){

             cout<<"\n\tStaff Information : \n" << endl;
            
             cout<< "\n\t\tStaff Id : " << id4 << endl;
            
             cout<< "\n\t\tStaff Name : " <<  name4 << endl;
            
             cout<< "\n\t\tStaff Work : "<< work4 << endl;
            
             cout<< "\n\t\tStaff Salary : "<< salary4 << endl;
             
             cout<< "\n\t\tStaff In_Out : "<< in_out4 << endl;
             break;

           }

      }
        fclose(staff1);

        int h;
        cout<<"\n******************************************************************************************************************************** \n"<<endl;
        
        cout<<"\n\tBack to Main Menu to press 1--> ";
        cin>>h;
       
        if(h==1){

         system("cls");
        
         cout<<"\n******************************************************************************************************************************** \n"<<endl;
         cout<<"\t\t\t\t\t\t\tWELCOME TO FATEMA HOSPITAL MANAGEMENT SYSTEM\t\n"<<endl;
         cout<<"\n******************************************************************************************************************************** \n"<<endl;
        
         staff_database();

       } 


}


int staff_update(){   
 
 
                    staff_search_display();

                    char search_id[20], id[20], name[20], work[20], selary[20], in_out[20];
                    char name1[20], work1[20], selary1[20], in_out1[20];

                    FILE * staff1;
                    FILE * staff2;
                   
                    staff1 = fopen("staff.txt","r");
                    staff2 =  fopen("staff_exchange.txt","a");
                    
                    cout<<"\n\n\tSearch UPDATE STAFF Id : ";
                    cin>>search_id;

                    while(fscanf(staff1,"%s\t %s\t %s\t %s\t %s\n",id, name, work, selary, in_out )!=EOF){
                         
                         if(strcmp(search_id, id)==0){
                           
                           cout<<"\n\t\t1--> Change Name : "<<endl;
                          
                           cout<<"\n\t\t2--> Change Work : "<<endl;
                          
                           cout<<"\n\t\t3--> Change Selary : "<<endl;
                          
                           cout<<"\n\t\t4--> Change In_Out : "<<endl;

                           int n6;
                          
                           cout<<"\n\tChoose Opction : ";
                           cin >> n6;

                           if(n6 == 1){

                            cout<<"\n\tPrevious Name : ";

                            printf("%s\n", name);
 
                               cout<<"\n\tUpdate Name : ";
                              
                               cin >> name1;
                              
                               fprintf(staff2, "%s\t %s\t %s\t %s\t %s\n",id, name1, work, selary, in_out);
                           }
                         
                           else if(n6 == 2){

                            cout<<"\n\tPrevious Work : ";

                            printf("%s\n", work);

                               cout<<"\n\tUpdate Work : ";
                            
                               cin >> work1;
                             
                               fprintf(staff2, "%s\t %s\t %s\t %s\t %s\n",id, name, work1, selary, in_out);
                           
                           }
                         
                           else if(n6 == 3){

                            cout<<"\n\tPrevious Selary : ";

                            printf("%s\n", selary);

                               cout<<"\n\tUpdate Selary : ";
                             
                               cin >> selary1;
                             
                               fprintf(staff2, "%s\t %s\t %s\t %s\t %s\n",id, name,  work, selary1, in_out);
                           
                           }
                          
                           else if(n6 == 4){

                            cout<<"\n\tPrevious In_Out  : ";

                            printf("%s\n", in_out);

                               cout<<"\n\tUpdate In_Out : ";
                            
                               cin >> in_out1;
                             
                               fprintf(staff2, "%s\t %s\t %s\t %s\t %s\n",id, name,  work, selary, in_out1);
                           
                           }
                          
                                     
                           }
                            else{

                               fprintf(staff2, "%s\t %s\t %s\t %s\t %s\n",id, name,  work, selary, in_out);
                           }
                         }

                    fclose(staff1);
                    fclose(staff2);
                   
                    remove("staff.txt");
                    rename("staff_exchange.txt","staff.txt");

                int h6;
                
                cout<<"\n******************************************************************************************************************************** \n"<<endl;
                cout<<"\n\tBack to Main Menu to press 1--> ";
                cin>>h6;
                
                if(h6==1){

                 system("cls");
                 
                 cout<<"\n******************************************************************************************************************************** \n"<<endl;
                 cout<<"\t\t\t\t\t\t\tWELCOME TO FATEMA HOSPITAL MANAGEMENT SYSTEM\t\n"<<endl;
                 cout<<"\n******************************************************************************************************************************** \n"<<endl;
                 
                 staff_database();

            }


}


int staff_delete(){

                 staff_search_display();

           
                char search_id[20],id[20],name[20],work[20],selary[20],in_out[20];

                    FILE * staff1;
                    FILE * staff2;
                   
                    staff1 = fopen("staff.txt","r");
                    staff2 =  fopen("staff_exchange.txt","a");

                    cout<<"\n\n\tDelete Staff ID Search : ";
                    cin>>search_id;

                    while(fscanf(staff1,"%s\t %s\t %s\t %s\t %s\n", id, name, work, selary, in_out )!=EOF){
                         
                         if(strcmp(search_id,id)==0){
                            continue;
                         }
                         else{

                            fprintf(staff2, "%s\t %s\t %s\t %s\t %s\n",id, name, work, selary, in_out );
                         }   
                     
                        
                    }
                    
                    fclose(staff1);
                    fclose(staff2);
                   
                    remove("staff.txt"); // source file in staff
                    rename("staff_exchange.txt","staff.txt");   // exchange file name in staff

                int h1;
                cout<<"\n******************************************************************************************************************************** \n"<<endl;
                cout<<"\n\tBack to Main Menu to press 1--> ";
                cin>>h1;
               
                if(h1==1){

                 system("cls");
                cout<<"\n******************************************************************************************************************************** \n"<<endl;
                 cout<<"\t\t\t\t\t\t\tWELCOME TO FATEMA HOSPITAL MANAGEMENT SYSTEM\t\n"<<endl;
                cout<<"\n******************************************************************************************************************************** \n"<<endl;
                
                 staff_database();

       } 

}


int staff_database(){           //      start staff database 


            system("cls");
            system("COLOR 3F");

            cout<<"\n******************************************************************************************************************************** \n"<<endl;
            cout<<"\t\t\t\t\t\t\t\tStuf DataBase\t\n"<<endl;
            cout<<"\n******************************************************************************************************************************** \n"<<endl;
            
            time();
            
            cout<<"\n\t\t1--> Add new Staff In File."<<endl;
           
            cout<<"\n\t\t2--> Search Staff Information From File."<<endl;
           
            cout<<"\n\t\t3--> Update Staff Information From File."<<endl;
           
            cout<<"\n\t\t4--> Delete Any staff Information From File. "<<endl;
           
            cout<<"\n\t\t5--> Exit"<<endl;
            
            int staff;
            cout<<"\n******************************************************************************************************************************** \n"<<endl;
            
            cout<<"\n\tChoose Opction : ";
            cin>>staff;

            if(staff==1){   // start add new staff informaction now admin

                staff_add();
          
            }     // close add new staff informaction now admin
            else if(staff==2){   // start search staff informaction in database in admin 

               staff_search();
               
            }   // close search staff informaction in database in admin 

            else if(staff == 3){    // start edit staff information in database in admin

               staff_update();
 
            }   // close edit staff information in database in admin
  
             else if(staff == 4){     // start delete staff informaction in database in admin 

               staff_delete();

            }        // close delete staff informaction in database in admin 

             else if(staff==5){   // start back main in admin

             system("cls");
             
             cout<<"\n******************************************************************************************************************************** \n"<<endl;
             cout<<"\t\t\t\t\t\t\tWELCOME TO FATEMA HOSPITAL MANAGEMENT SYSTEM\n"<<endl;
             cout<<"\n******************************************************************************************************************************** \n"<<endl;
             
             admin_choose_opction();

          }  // close back main in admin
 

}     //   colse staff database








int reception_choose_opction(){              

    cout<<"\n\n\t\t1--> Main Menu"<<endl;

    cout<<"\n\t\t2--> Exit"<<endl;

    cout<<"\n******************************************************************************************************************************** \n"<<endl;
    
    opction_select_reception();
}


int reception_exit(){
  
    cout<<"\n\tLog out this system....."<<endl;

     cout<<"\n\tIf Choose Again LOG IN This System so Enter --> 1  or EXIT  this System so Enter  AnyKey... ";
     int ggg;
     cin>>ggg;
     
     if(ggg==1){

      main();
}

}

int opction_select_reception(){

    int dk;
    
    cout<<"\tchoose Opction : ";    
    cin>>dk;

    switch(dk){
           
           case 1:
           reception_main_menu();
           break;

           case 2:
           reception_exit();
           break;

    }

}

int reception_main_menu(){

        system("cls");
        system("COLOR 3F");

        cout<<"\n******************************************************************************************************************************** \n"<<endl;
        cout<<"\t\t\t\t\t\t\t\tReception Main Menu\t\n"<<endl;
       cout<<"\n******************************************************************************************************************************** \n"<<endl;
       
        time();
 
        cout<<"\t\t1--> Search Doctor Information From File\n"<<endl;
       
        cout<<"\t\t2--> Enter into Patient's File.\n"<<endl;
       
        cout<<"\t\t3--> Exit\n"<<endl;
        
        cout<<"\n******************************************************************************************************************************** \n"<<endl;
        cout<<"\n\tChoose Opction : ";
       
        int ck_reception;
        cin>>ck_reception;
 
  // close  display all doctor informaction  recption

     if(ck_reception==1){    // start any search doctor informaction reception

              doctor_search_reception();
     
     }   // close any search doctor informaction reception

     else if(ck_reception == 2){   //start patient informaction in database in rescption

        patient_database();

    }
   
    else if(ck_reception==3){
           
            system("cls");
        
            cout<<"\n******************************************************************************************************************************** \n"<<endl;
            cout<<"\t\t\t\t\t\t\tWELCOME TO FATEMA HOSPITAL MANAGEMENT SYSTEM\t\n"<<endl;
            cout<<"\n******************************************************************************************************************************** \n"<<endl;
           
            reception_choose_opction();
        }

}// ck == 1 close now



int doctor_search_reception_display(){

       
            system("cls");
            system("COLOR 3F");
            
            cout<<"\n******************************************************************************************************************************** \n"<<endl;
            cout<<"\t\t\t\t\t\t\t\tAll Doctor Information From Database\t\n"<<endl;
            cout<<"\n******************************************************************************************************************************** \n"<<endl;
           
            time();

            char id[20], name[20], age[20], specilast[20], experience[20], city[20], visit_tk[20], visit_time[20], search[20];
           
           
               FILE *doctor;

               doctor = fopen("doctor.txt","r");
             
               if(doctor == NULL){

                  printf("Error!");
                
                  exit(1);
               
                }
             
             cout<<"\tAll Doctor Id From File : ";

             while(fscanf(doctor,"%s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\n", id, name, age, specilast, experience, city, visit_tk, visit_time)!=EOF){
                  
                  cout<<id<<"  "; 

             }
               
            fclose(doctor);
          
 

}


int doctor_search_reception(){

               doctor_search_reception_display();

               cout<<"\n\n\tSearch Information..."<<endl;

               char id[20], name[20], age[20], specilast[20], experience[20], city[20], visit_tk[20], visit_time[20], search[20];
            
               cout<<"\n\tSearch Doctor Id : ";
               cin>>search;
              
               FILE *doctor;

               doctor = fopen("doctor.txt","r");
             
               if(doctor == NULL){

                  printf("Error!");
                
                  exit(1);
               
                }
           
             while(fscanf(doctor,"%s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\n", id, name, age, specilast, experience, city, visit_tk, visit_time)!=EOF){
 
                 int ck=0;
                 ck = strcmp(id, search);
              
                 if(ck==0){
                
                  cout<<"\n\tDoctor Information : \n"<<endl;
                 
                  cout<< "\n\t\tDoctor Id : " << id <<endl;
                 
                  cout<< "\n\t\tDoctor Name : " << name <<endl;
                 
                  cout<< "\n\t\tDoctor Age : "<< age <<endl;
                
                  cout<< "\n\t\tDoctor Specilast : "<<specilast <<endl;
                 
                  cout<< "\n\t\tDoctor Experience Years : "<<experience <<endl;
                 
                  cout<< "\n\t\tDoctor City : "<<city <<endl;
                 
                  cout<< "\n\t\tDoctor Visti_tk : "<<visit_tk <<endl;
                 
                  cout<< "\n\t\tDoctor Visit_time : "<<visit_time <<endl;
                 
                    break;           
                 }
 
             }
            
             fclose(doctor);

                    int r;
                    cout<<"\n******************************************************************************************************************************** \n"<<endl;
                    cout<<"\n\tBack to Main Menu to press 1--> ";
                  
                   cin>>r;
                  if(r==1){

                   system("cls");
                  
                   cout<<"\n******************************************************************************************************************************** \n"<<endl;
                   cout<<"\t\t\t\t\t\t\tWELCOME TO FATEMA HOSPITAL MANAGEMENT SYSTEM\t\n"<<endl;
                   cout<<"\n******************************************************************************************************************************** \n"<<endl;
                  
                   reception_main_menu();


            }


}
 

int patient_add(){


                           patient_search_display();

                           cout<<"\n\n\tAdd Patient Information : "<<endl;
                         
                           char pr_id[10], pr_name[15],pr_age[10] ,pr_problem[15], pr_phone[10], pr_City[10], pr_admission_date[10], pr_discharge_date[20], pr_next_date[20], pr_bill[20], pr_report[20];
 
                           FILE *morol;
                           morol = (fopen("present1.txt", "a"));
         
                           if(morol== NULL){
               
                              printf("Error!");
                              exit(1);
                            }

                           cout<<"\n\tPatient Id : ";
                           cin>>pr_id;
                           
                           cout<<"\n\tPatient Name : ";
                           cin>>pr_name;
                          
                           cout<<"\n\tPatient Age : ";
                           cin>>pr_age;
                           
                           cout<<"\n\tPatient problem : ";
                           cin>>pr_problem;
                          
                           cout<<"\n\tPatient phone NUmber : ";
                           cin>>pr_phone;
                          
                           cout<<"\n\tPatient City : ";
                           cin>>pr_City;
                           
                           cout<<"\n\tPatient  Admission_date : ";
                           cin>>pr_admission_date;
                          
                           cout<<"\n\tPatient Discharge_date : ";
                           cin>>pr_discharge_date;
                           
                           cout<<"\n\tPatient  Next Consultation date : ";
                           cin>>pr_next_date;
                          
                           cout<<"\n\tPatient Bills : ";
                           cin>>pr_bill;
                           
                           cout<<"\n\tPatient Report : ";
                           cin>>pr_report;

                           fprintf(morol, "%s\t  %s\t  %s\t  %s\t %s\t  %s\t  %s\t  %s\t  %s\t  %s\t  %s\n",pr_id, pr_name, pr_age, pr_problem, pr_phone, pr_City, pr_admission_date, pr_discharge_date, pr_next_date, pr_bill, pr_report);

                           fclose(morol);
                           
                           int h;
                       
                           cout<<"\n******************************************************************************************************************************** \n"<<endl;
                          
                           cout<<"\n\tBack to Main Menu to press 1--> ";
                           cin>>h;
                           if(h==1){

                           system("cls");
                          
                           cout<<"\n******************************************************************************************************************************** \n"<<endl;
                           cout<<"\t\t\t\t\t\t\tWELCOME TO FATEMA HOSPITAL MANAGEMENT SYSTEM\t\n"<<endl;
                           cout<<"\n******************************************************************************************************************************** \n"<<endl;
                         
                           patient_database();
                         
                          } 


}

int patient_update(){


                    patient_search_display();

                    char search_id[20], pr_id[20], pr_name[15],pr_age[10] ,pr_problem[15], pr_phone[10], pr_City[10], pr_admission_date[10], pr_discharge_date[20], pr_next_date[20], pr_bill[20], pr_report[20];
                   
                    char pr_name1[15],pr_age1[10] ,pr_problem1[15], pr_phone1[10], pr_City1[10], pr_admission_date1[10], pr_discharge_date1[20], pr_next_date1[20], pr_bill1[20], pr_report1[20];

                    FILE * morol5;
                    FILE * morol6;
                    
                    morol5 = fopen("present1.txt","r");
                    morol6 =  fopen("patient_exchange.txt","a");
                   
                    cout<<"\n\n\tSearch Edit Patient Id : ";
                    cin>>search_id;

                    while(fscanf(morol5,"%s\t  %s\t  %s\t  %s\t %s\t  %s\t  %s\t  %s\t  %s\t  %s\t  %s\n",pr_id, pr_name, pr_age, pr_problem, pr_phone, pr_City, pr_admission_date, pr_discharge_date, pr_next_date, pr_bill, pr_report)!=EOF){
                         
                         if(strcmp(search_id, pr_id)==0){
                           
                           cout<<"\n\t\t1--> Change Name : "<<endl;
                         
                           cout<<"\n\t\t2--> Change Age : "<<endl;
                         
                           cout<<"\n\t\t3--> Change Problem : "<<endl;
                         
                           cout<<"\n\t\t4--> Change Phone : "<<endl;
                         
                           cout<<"\n\t\t5--> Change City : "<<endl;
                         
                           cout<<"\n\t\t6--> Change Admission Date : "<<endl;
                         
                           cout<<"\n\t\t7--> Change Discharge Date : "<<endl;
                         
                           cout<<"\n\t\t8--> Change Next Councling Date : "<<endl;
                         
                           cout<<"\n\t\t9--> Change Bills : "<<endl;
                         
                           cout<<"\n\t\t10--> Change Report : "<<endl;

                           int n7;
                           cout<<"\n\tChoose Opction : ";
                           cin >> n7;

                       if(n7 == 1){

                        cout<<"\n\tPrevious Name : ";

                        printf("%s\n", pr_name);

                          cout<<"\n\tUpdate Name : ";
                        
                           cin >> pr_name1;
                         
                           fprintf(morol6, "%s\t  %s\t  %s\t  %s\t %s\t  %s\t  %s\t  %s\t  %s\t  %s\t  %s\n",pr_id, pr_name1, pr_age, pr_problem, pr_phone, pr_City, pr_admission_date, pr_discharge_date, pr_next_date, pr_bill, pr_report);
                       }
     
                       else if(n7 == 2){

                         cout<<"\n\tPrevious Age : ";

                         printf("%s\n", pr_age);

                          cout<<"\n\tUpdate Age : ";
                         
                           cin >> pr_age1;
                         
                           fprintf(morol6, "%s\t  %s\t  %s\t  %s\t %s\t  %s\t  %s\t  %s\t  %s\t  %s\t  %s\n",pr_id, pr_name, pr_age1, pr_problem, pr_phone, pr_City, pr_admission_date, pr_discharge_date, pr_next_date, pr_bill, pr_report);
                       }
     
                      else if(n7 == 3){

                        cout<<"\n\tPrevious Problem  : ";

                        printf("%s\n", pr_problem);

                          cout<<"\n\tUpdate Problem : ";
                         
                           cin >> pr_problem1;
                          
                           fprintf(morol6, "%s\t  %s\t  %s\t  %s\t %s\t  %s\t  %s\t  %s\t  %s\t  %s\t  %s\n",pr_id, pr_name, pr_age, pr_problem1, pr_phone, pr_City, pr_admission_date, pr_discharge_date, pr_next_date, pr_bill, pr_report);
                       }
   
                      else if(n7 == 4){

                         cout<<"\n\tPrevious Phone Number  : ";

                         printf("%s\n", pr_phone);

                          cout<<"\n\tUpdate Phone Number : ";
                         
                           cin >> pr_phone1;
                          
                           fprintf(morol6, "%s\t  %s\t  %s\t  %s\t %s\t  %s\t  %s\t  %s\t  %s\t  %s\t  %s\n",pr_id, pr_name, pr_age, pr_problem, pr_phone1, pr_City, pr_admission_date, pr_discharge_date, pr_next_date, pr_bill, pr_report);
                       }
     
                      else if(n7 == 5){

                        cout<<"\n\tPrevious City Name : ";

                        printf("%s\n", pr_City);

                          cout<<"\n\tUpdate City Name : ";
                         
                           cin >> pr_City1;
                         
                           fprintf(morol6, "%s\t  %s\t  %s\t  %s\t %s\t  %s\t  %s\t  %s\t  %s\t  %s\t  %s\n",pr_id, pr_name, pr_age, pr_problem, pr_phone, pr_City1, pr_admission_date, pr_discharge_date, pr_next_date, pr_bill, pr_report);
                       }
    
                      else if(n7 == 6){

                         cout<<"\n\tPrevious Admission Date : ";

                         printf("%s\n", pr_admission_date);

                          cout<<"\n\tUpdate Admission Date : ";
                          
                           cin >> pr_admission_date1;
                          
                           fprintf(morol6, "%s\t  %s\t  %s\t  %s\t %s\t  %s\t  %s\t  %s\t  %s\t  %s\t  %s\n",pr_id, pr_name, pr_age, pr_problem, pr_phone, pr_City, pr_admission_date1, pr_discharge_date, pr_next_date, pr_bill, pr_report);
                       }
 
                      else if(n7 == 7){

                        cout<<"\n\tPrevious Discharge Date : ";

                        printf("%s\n", pr_discharge_date);

                          cout<<"\n\tUpdate Discharge Date : ";
                         
                           cin >> pr_discharge_date1;
                          
                           fprintf(morol6, "%s\t  %s\t  %s\t  %s\t %s\t  %s\t  %s\t  %s\t  %s\t  %s\t  %s\n",pr_id, pr_name, pr_age, pr_problem, pr_phone, pr_City, pr_admission_date, pr_discharge_date1, pr_next_date, pr_bill, pr_report);
                       }
   
                      else if(n7 == 8){

                         cout<<"\n\tPrevious Next Councling Date : ";

                         printf("%s\n", pr_next_date);

                          cout<<"\n\tUpdate Next Councling Date : ";
                         
                           cin >> pr_next_date1;
                          
                           fprintf(morol6, "%s\t  %s\t  %s\t  %s\t %s\t  %s\t  %s\t  %s\t  %s\t  %s\t  %s\n",pr_id, pr_name, pr_age, pr_problem, pr_phone, pr_City, pr_admission_date, pr_discharge_date, pr_next_date1, pr_bill, pr_report);
                       }
   
                      else if(n7 == 9){

                        cout<<"\n\tPrevious Bills : ";

                        printf("%s\n", pr_bill);

                           cout<<"\n\tUpdate Bills : ";
                          
                           cin >> pr_bill1;
                           
                           fprintf(morol6, "%s\t  %s\t  %s\t  %s\t %s\t  %s\t  %s\t  %s\t  %s\t  %s\t  %s\n",pr_id, pr_name, pr_age, pr_problem, pr_phone, pr_City, pr_admission_date, pr_discharge_date, pr_next_date, pr_bill1, pr_report);
                       }
    
                      else if(n7 == 10){

                        cout<<"\n\tPrevious Report Information : ";

                        printf("%s\n", pr_report);

                           cout<<"\n\tUpdate Report Information : ";
                          
                           cin >> pr_report1;
                         
                          fprintf(morol6, "%s\t  %s\t  %s\t  %s\t %s\t  %s\t  %s\t  %s\t  %s\t  %s\t  %s\n",pr_id, pr_name, pr_age, pr_problem, pr_phone, pr_City, pr_admission_date, pr_discharge_date, pr_next_date, pr_bill, pr_report1);
                       }
                      
                                 
                       }
                        else{

                          fprintf(morol6, "%s\t  %s\t  %s\t  %s\t %s\t  %s\t  %s\t  %s\t  %s\t  %s\t  %s\n",pr_id, pr_name, pr_age, pr_problem, pr_phone, pr_City, pr_admission_date, pr_discharge_date, pr_next_date, pr_bill, pr_report);
                         }
                     }

                   fclose(morol6);
                   fclose(morol5);
                  
                   remove("present1.txt");   // source code
                   rename("patient_exchange.txt","present1.txt");  // exchange file

                   int ww;
                   cout<<"\n******************************************************************************************************************************** \n"<<endl;
                   cout<<"\n\tBack to Main Menu to press 1--> ";
                   cin >> ww;
                   
                   if(ww == 1){

                   system("cls");
                   
                   cout<<"\n******************************************************************************************************************************** \n"<<endl;
                   cout<<"\t\t\t\t\t\t\tWELCOME TO FATEMA HOSPITAL MANAGEMENT SYSTEM\t\n"<<endl;
                   cout<<"\n******************************************************************************************************************************** \n"<<endl;
                   
                    patient_database();

                }
 

}


int patient_search_display(){

      
                           system("cls");
                          
                           cout<<"\n******************************************************************************************************************************** \n"<<endl;
                           cout<<"\t\t\t\t\t\t\tDisplay Patient Information From Database\n"<<endl;
                           cout<<"\n******************************************************************************************************************************** \n"<<endl;
                         
                           time();
                              
                          char ser_id[20],id1[20],name1[20],age1[20],problem1[20], phone1[20], city1[20], admission_date1[20], dischange_date1[20], next_consultation_date1[20], present_bills1[20], present_report1[20];
                        
                       FILE *morol;
                      
                       morol = fopen("present1.txt","r");
                      
                       if(morol == NULL){

                         printf("Error!");
                           exit(1);
                        }   
                    
                     cout<<"\tAll Patient Id From File : ";

                     while(fscanf(morol,"%s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\n", id1, name1, age1, problem1, phone1, city1, admission_date1, dischange_date1, next_consultation_date1, present_bills1, present_report1 )!=EOF){
                        
                             cout<<id1<<"  ";
                        }
                        
                        fclose(morol);
     
}


int patient_search(){
 
 
                       patient_search_display();
                       
                       cout<<"\n\n\tSearch Information : "<<endl;

                       char ser_id[20],id1[20],name1[20],age1[20],problem1[20], phone1[20], city1[20], admission_date1[20], dischange_date1[20], next_consultation_date1[20], present_bills1[20], present_report1[20];

                       cout<<"\n\tSearch Patient Id : ";
                       cin >> ser_id;
                      
                       FILE *morol;
                      
                       morol = fopen("present1.txt","r");
                      
                       if(morol == NULL){

                         printf("Error!");
                           exit(1);
                        }   
                   
                     while(fscanf(morol,"%s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\n", id1, name1, age1, problem1, phone1, city1, admission_date1, dischange_date1, next_consultation_date1, present_bills1, present_report1 )!=EOF){
                     
                  int dk;
                 
                  dk = strcmp(id1, ser_id);
                 // cout<<dk<<endl;
                  //cout<<id1<<endl;
                  //cout<<ser_id<<endl;
                  
                  if(dk == 0){
                 
                  cout<<"\n\tPatient Information : \n"<<endl;
                 
                  cout<< "\n\t\tPatient Id : " << id1 <<endl;
                  
                  cout<< "\n\t\tPatient Name : " << name1 <<endl;
                  
                  cout<< "\n\t\tPatient Age : "<< age1 <<endl;
                  
                  cout<< "\n\t\tPatient problem : "<< problem1 <<endl;
                  
                  cout<< "\n\t\tPatient Phone Number : "<< phone1 <<endl;
                 
                  cout<< "\n\t\tPatient City : "<< city1 <<endl;
                 
                  cout<< "\n\t\tPatient Admission_date : "<< admission_date1 <<endl;
                 
                  cout<< "\n\t\tPatient Dischange_date : "<< dischange_date1 <<endl;
                 
                  cout<< "\n\t\tPatient Next_consultation_date : "<< next_consultation_date1 <<endl;
                 
                  cout<< "\n\t\tPatient Present_bills : "<< present_bills1 <<endl;
                 
                  cout<< "\n\t\tPatient Present_report : "<< present_report1 <<endl;
                 
                            
                 }
 
             }
             
             fclose(morol);

                   int w;
                   cout<<"\n******************************************************************************************************************************** \n"<<endl;
                   cout<<"\n\tBack to Main Menu to press 1--> ";
                   cin>>w;
                 
                  if(w==1){

                   system("cls");
                  
                   cout<<"\n******************************************************************************************************************************** \n"<<endl;
                   cout<<"\t\t\t\t\t\t\tWELCOME TO FATEMA HOSPITAL MANAGEMENT SYSTEM\t\n"<<endl;
                   cout<<"\n******************************************************************************************************************************** \n"<<endl;
                  
                   patient_database();

                }

}


int patient_delete(){

    
                      patient_search_display();

                      char search_id[20],id1[20],name1[20],age1[20],problem1[20], phone1[20], city1[20], admission_date1[20], dischange_date1[20], next_consultation_date1[20], present_bills1[20], present_report1[20];

                        FILE * morol;
                        FILE * morol2;
                      
                        morol = fopen("present1.txt","r");
                        morol2 =  fopen("patient_exchange.txt","a");

                        cout<<"\n\n\tDelete Patient ID Search : ";
                        cin>>search_id;

                        while(fscanf(morol,"%s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\n", id1, name1, age1, problem1, phone1, city1, admission_date1, dischange_date1, next_consultation_date1, present_bills1, present_report1 )!=EOF){
                             
                             if(strcmp(search_id,id1)==0){
                               
                                continue;
                             }
                            
                             else{

                                fprintf(morol2, "%s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\n", id1, name1, age1, problem1, phone1, city1, admission_date1, dischange_date1, next_consultation_date1, present_bills1, present_report1 );
                             }   
                         
                            
                        }

                        fclose(morol);
                        fclose(morol2);

                        remove("present1.txt");
                        rename("patient_exchange.txt","present1.txt");

                   int uu;
                  
                   cout<<"\n******************************************************************************************************************************** \n"<<endl;
                   cout<<"\n\tBack to Main Menu to press 1--> ";
                   cin>>uu;
                 
                  if(uu==1){

                   system("cls");
                  
                   cout<<"\n******************************************************************************************************************************** \n"<<endl;
                   cout<<"\t\t\t\t\t\t\tWELCOME TO FATEMA HOSPITAL MANAGEMENT SYSTEM\t\n"<<endl;
                   cout<<"\n******************************************************************************************************************************** \n"<<endl;
                   
                     patient_database();

                }


}



int patient_database(){
  
            system("cls");
            system("COLOR 3F");

            cout<<"\n******************************************************************************************************************************** \n"<<endl;
            cout<<"\t\t\t\t\t\t\t\tPatient Database\t\n"<<endl;
            cout<<"\n******************************************************************************************************************************** \n"<<endl;
           
            time();
           
            cout<<"\n\t\t1--> Add PATIENT Information In File.\n"<<endl;
           
            cout<<"\t\t2--> Update PATIENT Information From File.\n"<<endl;
           
            cout<<"\t\t3--> Search PATIENT Information From File.\n"<<endl;
            
            cout<<"\t\t4--> Delete Any PATIENT Information From File.\n"<<endl;
           
            cout<<"\t\t5--> Exit.\n"<<endl;
            
            cout<<"\n******************************************************************************************************************************** \n"<<endl;
        
                     int main_choose_patient;
                    
                     cout<<"\n\tChoose Opction : ";
                     cin>>main_choose_patient;
                    
               
                if(main_choose_patient==1){   // start add new doctor informaction from database in reception

                       patient_add();

                         
                } // close add present informaction reception
              
                else if(main_choose_patient==2){    // start Edit patient informaction in reception

                       patient_update();
 
                } // close Edit patient informaction in reception
                  
                else if(main_choose_patient==3){  // start search patient informaction in reception

                        patient_search();
                         
                }  // close search patient informaction in reception

                else if(main_choose_patient==4){   // start delete any patient informaction from database reception

                       patient_delete();
                 
                }   // close delete any patient informaction from database reception
 
                else if(main_choose_patient==5){   // start back main in reception
                      
                        system("cls");
                       
                        cout<<"\n******************************************************************************************************************************** \n"<<endl;
                        cout<<"\t\t\t\t\t\t\tWELCOME TO FATEMA HOSPITAL MANAGEMENT SYSTEM\t\n"<<endl;
                        cout<<"\n******************************************************************************************************************************** \n"<<endl;
                        
                       reception_main_menu();
            
              
               }   // close back main in reception


 }