#include<bits/stdc++.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include <time.h>
#include <conio.h>
#define PI 3.14159265

using namespace std;
 
char manager_name[15]="jinnatul";
char manager_pas[20]="swediu";

char morol_name[15]="morol";
char morol_pass[20]="1234";

char arif_name[15]="arif";
char arif_pass[20]="5678";

char jubaer_name[15]="jubaer";
char jubaer_pass[20]="5466";


int login();
int reception_information();
int back_main();
int doctor_list();
int doctor_list2();
int patient_history();
int laboratory();
int laboratory2();
int operation_list();
int operation_list2();
int blood_bank();
int blood_bank2();
int staff_scheduling();
int reception_choose();
int new_back_select_manager();
int new_back_select_reception();
int notices();
int notices2();
int manager_choose();
int Calculator();
int Developer_information();
int addition();
int subtraction();
int multiplication();
int back_calculator();
int choose_calculator();
int Discount();
float division();
float power();
float square_root();
float sin();
float cos();
float tan();
float log();
float log10();

float time(){

  time_t rawtime;
  struct tm * timeinfo;
  time (&rawtime);
  timeinfo = localtime (&rawtime);

  printf ("\t\t\t\t\tClock : %s\n", asctime(timeinfo));
}

int main()
{
    cout<<"\n*****Welcome To Our Hospital Management System*****\t\n"<<endl;
    time();
    cout<<"\n\t 1--> Manager log in"<<endl;
    cout<<"\n\t 2--> Reception log in"<<endl;
    
    login();


 }

int back_main(){
    
    cout<<"\n\t\t 1--> Manager log in"<<endl;
    cout<<"\n\t\t 2--> Reception log in"<<endl;
    login();

}

int login(){

        int choose,b,f,ck,i;
        char a;
        char mana_check_name[15];
        char pass[20];
        char pass1[20];
        char pass2[20];
        char pass3[20];

        cout<<"\n\tEnter your choose : ";
        cin>>choose;
  
        
//manager part checking name and password
//in this code
//log in manager

if(choose == 1){
        
        system("cls");

        cout<<"\n*****Welcome to Manager Log In Part : *****"<<endl;
        
        cout<<"\n\tEnter Manager Name : ";
        cin>>mana_check_name;

        cout<<"\n\tEnter Manager Password : ";
      //  cin>>mana_check_pass;

        f = strcmp(manager_name,mana_check_name);
    
      for(i=0;;){  //infinite loop

            a=getch();//stores char typed in a
        if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))
        //check if a is numeric or alphabet
        {
            pass[i]=a;//stores a in pass
            ++i;
            cout<<"*";
        }
        if(a=='\b'&&i>=1)//if user typed backspace
        //i should be greater than 1.
        {
            cout<<"\b \b";//rub the character behind the cursor.
            --i;
        }
        if(a=='\r')//if enter is pressed
        {
            pass[i]='\0';//null means end of string.
            break;//break the loop
        }
    }
 
    ck=0;
    ck=strcmp(pass,manager_pas);
    if(ck==0 && f==0){
        manager_choose();
    }
    else{
        cout<<"\t\n\nWrong Password and Now enter right requirements\n"<<endl;
        pass[0]='\0';
        mana_check_name[0]='\0';

        back_main();                 //wrong password so call back_main function
    }
 }




//reception part checking name and password
//in this code
//log in reception

else if (choose==2){
       char rec_check_name[20];
 
       int n,m,i,j,q,p,r;

       system("cls");

       cout<<"\n*****Welcome to Reception Log In Part : *****"<<endl;
 
       cout<<"\n\t1--> Morol : "<<endl;
       cout<<"\n\t2--> Arif Mia : "<<endl;
       cout<<"\n\t3--> Jubaer Hossain : "<<endl;

       cout<<"\n\tEnter your choose : ";
       cin>>r;






//first reception check password star

       if(r==1){
        
        system("cls");

        cout<<"\n\tMorol Log in Page : "<<endl;

        cout<<"\n\t\tEnter Reception Staff Name : ";
        cin>>rec_check_name;

        cout<<"\n\t\tEnter Reception Staff Password : ";

        n=strcmp(morol_name, rec_check_name);
    
    char pass1[32],p;//to store password.
    int j = 0,ck1;
 
    for(j=0;;)//infinite loop
    {
        p=getch();//stores char typed in a
        if((p>='a'&&p<='z')||(p>='A'&&p<='Z')||(p>='0'&&p<='9'))
        //check if a is numeric or alphabet
        {
            pass1[j]=p;//stores a in pass
            ++j;
            cout<<"*";
        }
        if(p=='\b'&&j>=1)//if user typed backspace
        //i should be greater than 1.
        {
            cout<<"\b \b";//rub the character behind the cursor.
            --j;
        }
        if(p=='\r')//if enter is pressed
        {
            pass1[j]='\0';//null means end of string.
            break;//break the loop
        }
    }
 
    ck1=0;
    ck1=strcmp(pass1,morol_pass);

    if(ck1==0 && n==0){
        reception_choose();
    }
          else{
             cout<<"\n\tWrong Password and Now enter right requirements\n"<<endl;
              pass1[0]='\0';
              rec_check_name[0]='\0';
             back_main();                 //wrong password so call back_main function
    
        }

}





//second reception check password star

       if(r==2){
        
        system("cls");
        cout<<"\n\tArif Mia Log in Page : "<<endl;

        cout<<"\n\t\tEnter Reception Staff Name : ";
        cin>>rec_check_name;

        cout<<"\n\t\tEnter Reception Staff Password : ";
 
        i=strcmp(arif_name,rec_check_name);
        char pass2[32],r;//to store password.
        int s = 0,ck2;
 
        for(s=0;;){//infinite loop
 
        r=getch();//stores char typed in a
        if((r>='a'&& r<='z')||(r>='A'&& r<='Z')||(r>='0'&& r<='9'))
        //check if a is numeric or alphabet
        {
            pass2[s]=r;//stores a in pass
            ++s;
            cout<<"*";
        }
        if(r=='\b'&&s>=1)//if user typed backspace
        //i should be greater than 1.
        {
            cout<<"\b \b";//rub the character behind the cursor.
            --s;
        }
        if(r=='\r')//if enter is pressed
        {
            pass2[s]='\0';//null means end of string.
            break;//break the loop
        }
    }
 
    ck2=0;
    ck2=strcmp(pass2,arif_pass);
    if(ck2==0 && i==0){
        reception_choose();
    }
      else{
         cout<<"\n\tWrong Password and Now enter right requirements\n"<<endl;
//empty check string name and password
         pass2[0]='\0';
         rec_check_name[0]='\0';

          back_main();                 //wrong password so call back_main function
    
   }

   }





//3rd reception check password star

       if(r==3){
        
        system("cls");

        cout<<"\n\tJubaer Hossain Log in Page : "<<endl;

        cout<<"\n\t\tEnter Reception Staff Name : ";
        cin>>rec_check_name;

        cout<<"\n\t\tEnter Reception Staff Password : ";

         p=strcmp(jubaer_name,rec_check_name);
         char pass3[32],k;//to store password.
         int t = 0,ck3;
 
        for(t=0;;){//infinite loop
 
        k=getch();//stores char typed in a

        if((k>='a'&& k<='z')||(k>='A'&& k<='Z')||(k>='0'&& k<='9'))
        //check if a is numeric or alphabet
        {
            pass3[t]=k;//stores a in pass
            ++t;
            cout<<"*";
        }

        if(k=='\b'&&t>=1)//if user typed backspace
        //i should be greater than 1.
        {
            cout<<"\b \b";//rub the character behind the cursor.
            --t;
        }

        if(k=='\r')//if enter is pressed
        {
            pass3[t]='\0';//null means end of string.
            break;//break the loop
        }
    }
 
    ck3=0;
    ck3=strcmp(pass3,jubaer_pass);
    if(ck3==0 && p==0){
        reception_choose();
    }
        else{
        cout<<"\n\tWrong Password and Now enter right requirements\n"<<endl;

        pass3[0]='\0';
        rec_check_name[0]='\0';
        back_main();                 //wrong password so call back_main function
    
   }

}

}

}


//manager choose

int manager_choose(){
         
        system("cls");

        cout<<"\n***Main Page in Manager : ***\n"<<endl;
        time();
        cout<<"\n\t1 -> Check Reception_information\n"<<endl;
        cout<<"\t2 -> Check Doctor_list\n"<<endl;
        cout<<"\t3 -> Check Patient_history\n"<<endl;
        cout<<"\t4 -> Check Laboratory\n"<<endl;
        cout<<"\t5 -> Check Operation_List\n"<<endl;
        cout<<"\t6 -> Check Blood_Bank\n"<<endl;
        cout<<"\t7 -> Check Staff_Scheduling\n"<<endl;
        cout<<"\t8 -> Check Notices\n"<<endl;
        cout<<"\t9 -> Check Developer_information\n"<<endl;
      
        cout<<"\n\tChoose enter number : ";
        int c;
        cin>>c;
        switch(c){
            case 1:
            reception_information();
            break;
            case 2:
            doctor_list();
            break;
            case 3:
            patient_history();
            break;
            case 4:
            laboratory();
            break;
            case 5:
            operation_list();
            break;
            case 6:
            blood_bank();
            break;
            case 7:
            staff_scheduling();
            break;
            case 8:
            notices();
            break;
            case 9:
            Developer_information();
            break;
           
            default :
            cout<<"\twrong enter so back to main page"<<endl;
            back_main();
 
        }
}


int new_back_select_manager(){

    cout<<"\tBack Main Page in Manager so Enter press : 1 or  Exit This system so Enter press Any key ----> ";
    int n;
    cin>>n;
    if(n==1){
        manager_choose();
    }
    else{
        cout<<"\n\tExit system : "<<endl;
    }
}

//reception chosse

int reception_choose(){
        system("cls");

        cout<<"\n***Main Page in Reception : ***\n"<<endl;
        time(); 

        cout<<"\n\t1 -> Check Doctor_list"<<endl;
        cout<<"\n\t2 -> Check Laboratory"<<endl;
        cout<<"\n\t3 -> Check Operation_List"<<endl;
        cout<<"\n\t4 -> Check Blood_Bank"<<endl;
        cout<<"\n\t5 -> Check Notices"<<endl;
        cout<<"\n\t6 -> Calculator\n"<<endl;

        cout<<"\n\tChoose enter number : ";
        int c;
        cin>>c;
        switch(c){

            case 1:
            doctor_list2();
            break;
            case 2:
            laboratory2();
            break;
            case 3:
            operation_list2();
            break;
            case 4:
            blood_bank2();
            break;
            case 5:
            notices2();
            break;
            case 6:
            Calculator();
            break;

            default :
            cout<<"\twrong enter so back to main page"<<endl;
            back_main();
 
        }
}

int new_back_select_reception(){

    cout<<"\tBack Main Page in Reception so Enter press : 1 or  Exit This system so Enter press Any key ----> ";
    int n;
    cin>>n;
    if(n==1){
        reception_choose();
    }
    else{
        cout<<"\tExit system : "<<endl;
    }
}

//manager part in this code
//number 1 manager

int reception_information(){
    
    system("cls");

    cout<<"*****Reception_Information list in our Hospital*****\n"<<endl;
    time();
    cout<<"\n\tStaff_Scheduling : "<<endl;
    cout<<"\n\t\tName :             Phone_number :      Email :            Entry_Time : "<<endl;
    cout<<"\n\t\tMorol              01722567865         karim@gmail.com    8.00 AM To 4 PM"<<endl;
    cout<<"\n\t\tArif Mia           01722567866         raju@gmail.com     4 PM To 12 AM"<<endl;
    cout<<"\n\t\tJubaer hosian      01722567867         mamun@gmail.com    12 AM To 8 AM\n"<<endl;

    new_back_select_manager();

}

//number 2 manager
int doctor_list(){

    system("cls");

    cout<<"\n*****Doctor list in our Hospital*****\n"<<endl;
    time();
    cout<<"\n\tDoctor Name :                 Department Name :           visit Price : \n"<<endl;
    cout<<"\tProf. Dr. Md. Samsul Arfin    ( Gastroenterology )          700 tk\n"<<endl;
    cout<<"\tProf. Dr. Sanawar Hossain     ( Radiology )                 800 tk\n"<<endl;    
    cout<<"\tDr Ranadhir Kumar Kundu       ( Anesthesiology )            600 tk\n"<<endl;   
    cout<<"\tDr. Fazle Rabbi Mohammed      ( Respiratory Medicine )      700 tk\n"<<endl;
    cout<<"\tDr. A M Rejaus Satter         ( Neuro Surgery )             800 tk\n"<<endl;
    cout<<"\tDr. Raihan Rabbani            ( Internal Medicine )         600 tk\n"<<endl;
    cout<<"\tDr. Sharmin Haque             ( ICU )                       800 tk\n"<<endl;
    cout<<"\tDr. Syeda Ishrat Jahan        ( Dermatology )               700 tk\n"<<endl;
    cout<<"\tDr. Sufia Nasrin Rita         ( Dental Care )               600 tk\n"<<endl;
    cout<<"\tDr. Mahbub Mansur             ( Cardiology )                800 tk\n"<<endl;
    cout<<"\tDr. Raihan Mansur             ( spine )                     900 tk\n"<<endl;

    new_back_select_manager();

}

//number 3
int patient_history(){
    system("cls");

    cout<<"\n*****Daily patient history list in our Hospital*****\n"<<endl;
    time();
    cout<<"\n\tLast 20 patient history in Today : "<<endl;
    cout<<"\n\t\tPatient_Name :      Dr._Name :                   Total_Visit :    Last_Visit_Date :  Patient_Problem : "<<endl;
    cout<<"\n\t\tBarsha Akter        Dr. Sufia Nasrin Rita        3 Times          10/11/2017         Dental Care"<<endl;
    cout<<"\n\t\tSumon Mia           Dr. A M Rejaus Satter        2 Times          10/11/2017         Neuro Surgery"<<endl;
    cout<<"\n\t\tLaboni Akter        Prof. Dr. Md. Samsul Arfin   2 Times          10/11/2017         Gastroenterology"<<endl;
    cout<<"\n\t\tShamim Akter        Dr Ranadhir Kumar Kundu      3 Times          10/11/2017         Anesthesiology"<<endl;
    cout<<"\n\t\tSabbir Mia          Dr. Raihan Mansur            2 Times          10/11/2017         spine"<<endl;
    cout<<"\n\t\tFardin Mia          Dr. Sufia Nasrin Rita        2 Times          10/11/2017         Dental Care"<<endl;
    cout<<"\n\t\tAnamika Akter       Dr. Raihan Mansur            3 Times          10/11/2017         spine"<<endl;
    cout<<"\n\t\tTripty Akter        Dr. Mahbub Mansur            3 Times          10/11/2017         cardiology"<<endl;
    cout<<"\n\t\tSadiya Akter        Dr. Sufia Nasrin Rita        3 Times          10/11/2017         Dental Care"<<endl;
    cout<<"\n\t\tManik Mia           Dr. A M Rejaus Satter        2 Times          10/11/2017         Neuro Surgery"<<endl;
    cout<<"\n\t\tKorim Mia           Prof. Dr. Md. Samsul Arfin   2 Times          10/11/2017         Gastroenterology"<<endl;
    cout<<"\n\t\tShamim Akter        Dr Ranadhir Kumar Kundu      3 Times          10/11/2017         Anesthesiology"<<endl;
    cout<<"\n\t\tSabbir Mia          Dr. Raihan Mansur            2 Times          10/11/2017         spine"<<endl;
    cout<<"\n\t\tArif Mia            Dr. Sufia Nasrin Rita        2 Times          10/11/2017         Dental Care"<<endl;
    cout<<"\n\t\tRuma Akter          Dr. Raihan Mansur            3 Times          10/11/2017         spine"<<endl;
    cout<<"\n\t\tAnika Akter         Dr. Mahbub Mansur            3 Times          10/11/2017         cardiology"<<endl;  
    cout<<"\n\t\tFardin Mia          Dr. Sufia Nasrin Rita        2 Times          10/11/2017         Dental Care"<<endl;
    cout<<"\n\t\tAnamika Akter       Dr. Raihan Mansur            3 Times          10/11/2017         spine"<<endl;
    cout<<"\n\t\tTripty Akter        Dr. Mahbub Mansur            3 Times          10/11/2017         cardiology\n"<<endl;

    new_back_select_manager();
}

// number 4
int laboratory(){
    
    system("cls");

    cout<<"\n*****laboratory list in our Hospital*****\n"<<endl;
    time();
    cout<<"\n\t1--> X-Ray : "<<endl;

    cout<<"\n\n\t\tTest Name :                  Price in (BD) : "<<endl;

    cout<<"\n\n\t\tSkull B/V                    700 tk"<<endl;
    cout<<"\n\t\tSella Turcica                400 tk"<<endl;
    cout<<"\n\t\tBoth Hip joint B/V           1000 tk"<<endl;
    cout<<"\n\t\tLeg B/V                      400 tk"<<endl;
    cout<<"\n\t\tPortable X-Ray               300 tk"<<endl;
    cout<<"\n\t\tAdditional X-Ray Report      100 tk\n\n"<<endl;
    
    cout<<"\t2--> MRI : "<<endl;

    cout<<"\n\n\t\tMRI OF BRAIN                 5000 tk"<<endl;
    cout<<"\n\t\tMRI OF LUMBAR SPINE          4500 tk"<<endl;
    cout<<"\n\t\tMRI OF RT/LT FOOT            3800 tk"<<endl;
    cout<<"\n\t\tMRI OF THORACIC SPINE        4700 tk\n\n"<<endl;

    cout<<"\t3--> Pathology : "<<endl;

    cout<<"\n\n\t\tBlood Group                  100 tk"<<endl;
    cout<<"\n\t\tHb%                          120 tk"<<endl;
    cout<<"\n\t\tUrine                        250 tk\n\n"<<endl;

    cout<<"\t4--> Ultra Sonogram : "<<endl;

    cout<<"\n\n\t\tWhole abdomen                1100 tk"<<endl;
    cout<<"\n\t\tGuided procedure             2000 tk"<<endl;
    cout<<"\n\t\tKidneys & Adrenals           800 tk"<<endl;
    cout<<"\n\t\tThyroid                      1000 tk"<<endl;
    cout<<"\n\t\tTVS                          1300 tk\n\n"<<endl;

    cout<<"\t5--> Other test : "<<endl;

    cout<<"\n\n\t\tLiver Function Test          900 tk"<<endl;
    cout<<"\n\t\tSodium                       250 tk"<<endl;
    cout<<"\n\t\tLDH test                     700 tk"<<endl;
    cout<<"\n\t\tTotal Protein                300 tk\n"<<endl;

    new_back_select_manager();
}

// number 5
int operation_list(){

    system("cls");

    cout<<"\n*****Operation_Information list in our Hospital*****\n"<<endl;
    time();
    cout<<"\n\n\tOperaction Name :                           Standard_Price :    Deluxe_Price :   Suite_Price :   Duraction :"<<endl;
    cout<<"\n\tNormal Delivery Package :                   25,500              30,000           35,000          3 Days"<<endl;
    cout<<"\n\tCaesarian Delivery Package - High Risk      60,500              70,500           90,500          4 Days"<<endl;
    cout<<"\n\tVaginal Hysterectomy Package                50,500              57,500           70,500          4 Days"<<endl;
    cout<<"\n\tMyomectomy (Abdominal) Package              40,500              50,500           57,500          4 Days"<<endl;
    cout<<"\n\tSpine Pacage                                35,500              45,500           55,500          4 Days"<<endl;
    cout<<"\n\tCurettage With Cervical Biopsy              15,000                                               12 Hour"<<endl;
    cout<<"\n\tDilatation and Curettage( Day Care )        18,000                                               12 Hour"<<endl;
    cout<<"\n\tDental                                      4,000                                                2 Hour\n"<<endl;
    new_back_select_manager();
}

// number 6
int blood_bank(){
    
    system("cls");

    cout<<"\n*****Blood_Bank list in our Hospital*****\n"<<endl;
    time();
    cout<<"\n\n\t\tItem Name :                           Price in (BD) : "<<endl;
    cout<<"\n\t\tBlood for Grouping & Rh Typing        350 tk"<<endl;
    cout<<"\n\t\tWhole Blood                           1900 tk"<<endl;
    cout<<"\n\t\tPacked Cell                           1700 tk"<<endl;
    cout<<"\n\t\tSaline Cross Match                    800 tk"<<endl;
    cout<<"\n\t\tCompatibility Report                  400 tk"<<endl;
    cout<<"\n\t\tDirect Coomb's Test                   450 tk"<<endl;
    cout<<"\n\t\tFresh Plasma                          1800 tk\n"<<endl;

    cout<<"\n\t(*) Atfirst you need solid information in this, Then we check your informaction ,Then we give blood\n"<<endl;
    cout<<"\n\n\t\tItem Name :                           Price in (BD) : "<<endl;
    cout<<"\n\t\tA(+)                                  1000 tk"<<endl;
    cout<<"\n\t\tA(-)                                  1500 tk"<<endl;
    cout<<"\n\t\tB(+)                                  800 tk"<<endl;
    cout<<"\n\t\tB(-)                                  1400 tk"<<endl; 
    cout<<"\n\t\tAB(+)                                 1000 tk"<<endl;
    cout<<"\n\t\tAB(-)                                 1100 tk"<<endl;
    cout<<"\n\t\tO(+)                                  1200 tk"<<endl;
    cout<<"\n\t\tO(-)                                  1600 tk\n"<<endl;

    new_back_select_manager();
}

// number 7
int staff_scheduling(){
    
    system("cls");

    cout<<"\n*****Day Staff_Scheduling list in our Hospital*****\n"<<endl;
    time();

    cout<<"\n\t\tStaff Name :               Work : \n"<<endl;
    cout<<"\n\t\tBarsha Akter              (Nurse)"<<endl;
    cout<<"\n\t\tRodela Akter              (Nurse)"<<endl;
    cout<<"\n\t\tNawrin Akter              (Nurse)"<<endl;
    cout<<"\n\t\tSumon Mia                 (word boy)"<<endl;
    cout<<"\n\t\tAnik Mia                  (word boy)"<<endl;
    cout<<"\n\t\tRohan Mia                 (cleaner)"<<endl;
    cout<<"\n\t\tSumi Akter                (cleaner)\n"<<endl;

    cout<<"\n*****Night Staff_Scheduling list in our Hospital*****"<<endl;

    cout<<"\n\t\tLaboni Akter              (Nurse)"<<endl;
    cout<<"\n\t\tEva Akter                 (Nurse)"<<endl;
    cout<<"\n\t\tOrpa Akter                (Nurse)"<<endl;
    cout<<"\n\t\tKabir Islam               (word boy)"<<endl;
    cout<<"\n\t\tRahim Mia                 (word boy)"<<endl;
    cout<<"\n\t\tRifat Mia                 (cleaner)"<<endl;
    cout<<"\n\t\tSorna Akter               (cleaner)\n"<<endl;

    new_back_select_manager();
}

// number 8
int notices(){

    system("cls");

    cout<<"\n*****NOTICS in Our Hospital*****\n"<<endl;
    time();
    cout<<"\n\t\t1--> No Cell Phone While in Triage and Patient Rooms"<<endl;
    cout<<"\n\t\t2--> No Smoking Within 25 Feet of Building Entrance"<<endl;
    cout<<"\n\t\t3--> Don't talking loudly"<<endl;
    cout<<"\n\t\t4--> If have any query then contact the information desk\n"<<endl;
    cout<<"\n\t\tHelp Line : ( 16334 ) 24 Hours or (01858492168-9)\n"<<endl; 

    new_back_select_manager();
}

// number 9
int Developer_information(){

    system("cls");

    cout<<"\n*****Developer_Information*****\n"<<endl;
    time();
    cout<<"\n\tProject_Developer : "<<endl;
    cout<<"\n\n\t\tMd : Zinnatul Islam Morol"<<endl;
    cout<<"\n\t\tEmail : morolswediu@gmail.com"<<endl;
    cout<<"\n\t\tCell number: 01793696177"<<endl;
    cout<<"\n\t\tSWE_DIU_(22 Batch)"<<endl;
    cout<<"\n\t\t3rd Semester ( Section : C1 )"<<endl;
    cout<<"\n\n\t\tInstruction Help : Lamisha Rawshan (Class Madam)\n"<<endl;
    
    new_back_select_manager();

}


//reception part in this code
//number 1 reception


int doctor_list2(){

    system("cls");

    cout<<"\n*****Doctor list in our Hospital*****\n"<<endl;
    time();
    cout<<"\n\tDoctor Name :                 Department Name :           visit Price : \n"<<endl;
    cout<<"\tProf. Dr. Md. Samsul Arfin    ( Gastroenterology )          700 tk\n"<<endl;
    cout<<"\tProf. Dr. Sanawar Hossain     ( Radiology )                 800 tk\n"<<endl;    
    cout<<"\tDr Ranadhir Kumar Kundu       ( Anesthesiology )            600 tk\n"<<endl;   
    cout<<"\tDr. Fazle Rabbi Mohammed      ( Respiratory Medicine )      700 tk\n"<<endl;
    cout<<"\tDr. A M Rejaus Satter         ( Neuro Surgery )             800 tk\n"<<endl;
    cout<<"\tDr. Raihan Rabbani            ( Internal Medicine )         600 tk\n"<<endl;
    cout<<"\tDr. Sharmin Haque             ( ICU )                       800 tk\n"<<endl;
    cout<<"\tDr. Syeda Ishrat Jahan        ( Dermatology )               700 tk\n"<<endl;
    cout<<"\tDr. Sufia Nasrin Rita         ( Dental Care )               600 tk\n"<<endl;
    cout<<"\tDr. Mahbub Mansur             ( Cardiology )                800 tk\n"<<endl;
    cout<<"\tDr. Raihan Mansur             ( spine )                     900 tk\n"<<endl;
    new_back_select_reception();

}

//number 2 reception
int laboratory2(){
    
    system("cls");

    cout<<"\n*****laboratory list in our Hospital*****\n"<<endl;
    time();
    cout<<"\n\t1--> X-Ray : "<<endl;

    cout<<"\n\n\t\tTest Name :                  Price in (BD) : "<<endl;

    cout<<"\n\n\t\tSkull B/V                    700 tk"<<endl;
    cout<<"\n\t\tSella Turcica                400 tk"<<endl;
    cout<<"\n\t\tBoth Hip joint B/V           1000 tk"<<endl;
    cout<<"\n\t\tLeg B/V                      400 tk"<<endl;
    cout<<"\n\t\tPortable X-Ray               300 tk"<<endl;
    cout<<"\n\t\tAdditional X-Ray Report      100 tk\n\n"<<endl;
    
    cout<<"\t2--> MRI : "<<endl;

    cout<<"\n\n\t\tMRI OF BRAIN                 5000 tk"<<endl;
    cout<<"\n\t\tMRI OF LUMBAR SPINE          4500 tk"<<endl;
    cout<<"\n\t\tMRI OF RT/LT FOOT            3800 tk"<<endl;
    cout<<"\n\t\tMRI OF THORACIC SPINE        4700 tk\n\n"<<endl;

    cout<<"\t3--> Pathology : "<<endl;

    cout<<"\n\n\t\tBlood Group                  100 tk"<<endl;
    cout<<"\n\t\tHb%                          120 tk"<<endl;
    cout<<"\n\t\tUrine                        250 tk\n\n"<<endl;

    cout<<"\t4--> Ultra Sonogram : "<<endl;

    cout<<"\n\n\t\tWhole abdomen                1100 tk"<<endl;
    cout<<"\n\t\tGuided procedure             2000 tk"<<endl;
    cout<<"\n\t\tKidneys & Adrenals           800 tk"<<endl;
    cout<<"\n\t\tThyroid                      1000 tk"<<endl;
    cout<<"\n\t\tTVS                          1300 tk\n\n"<<endl;

    cout<<"\t5--> Other test : "<<endl;

    cout<<"\n\n\t\tLiver Function Test          900 tk"<<endl;
    cout<<"\n\t\tSodium                       250 tk"<<endl;
    cout<<"\n\t\tLDH test                     700 tk"<<endl;
    cout<<"\n\t\tTotal Protein                300 tk\n"<<endl;

    new_back_select_reception();
}

//number 3 reception
int operation_list2(){

    system("cls");

    cout<<"\n*****Operation_Information list in our Hospital*****\n"<<endl;
    time();
    cout<<"\n\n\tOperaction Name :                           Standard_Price :    Deluxe_Price :   Suite_Price :   Duraction :"<<endl;
    cout<<"\n\tNormal Delivery Package :                   25,500              30,000           35,000          3 Days"<<endl;
    cout<<"\n\tCaesarian Delivery Package - High Risk      60,500              70,500           90,500          4 Days"<<endl;
    cout<<"\n\tVaginal Hysterectomy Package                50,500              57,500           70,500          4 Days"<<endl;
    cout<<"\n\tMyomectomy (Abdominal) Package              40,500              50,500           57,500          4 Days"<<endl;
    cout<<"\n\tSpine Pacage                                35,500              45,500           55,500          4 Days"<<endl;
    cout<<"\n\tCurettage With Cervical Biopsy              15,000                                               12 Hour"<<endl;
    cout<<"\n\tDilatation and Curettage( Day Care )        18,000                                               12 Hour"<<endl;
    cout<<"\n\tDental                                      4,000                                                2 Hour\n"<<endl;
  
    new_back_select_reception();
}

//number 4 reception
int blood_bank2(){
    
    system("cls");

    cout<<"\n*****Blood_Bank list in our Hospital*****\n"<<endl;
    time();
    cout<<"\n\n\t\tItem Name :                           Price in (BD) : "<<endl;
    cout<<"\n\t\tBlood for Grouping & Rh Typing        350 tk"<<endl;
    cout<<"\n\t\tWhole Blood                           1900 tk"<<endl;
    cout<<"\n\t\tPacked Cell                           1700 tk"<<endl;
    cout<<"\n\t\tSaline Cross Match                    800 tk"<<endl;
    cout<<"\n\t\tCompatibility Report                  400 tk"<<endl;
    cout<<"\n\t\tDirect Coomb's Test                   450 tk"<<endl;
    cout<<"\n\t\tFresh Plasma                          1800 tk\n"<<endl;

    cout<<"\n\t(*) Atfirst you need solid information in this, Then we check your informaction ,Then we give blood\n"<<endl;
    cout<<"\n\n\t\tItem Name :                           Price in (BD) : "<<endl;
    cout<<"\n\t\tA(+)                                  1000 tk"<<endl;
    cout<<"\n\t\tA(-)                                  1500 tk"<<endl;
    cout<<"\n\t\tB(+)                                  800 tk"<<endl;
    cout<<"\n\t\tB(-)                                  1400 tk"<<endl; 
    cout<<"\n\t\tAB(+)                                 1000 tk"<<endl;
    cout<<"\n\t\tAB(-)                                 1100 tk"<<endl;
    cout<<"\n\t\tO(+)                                  1200 tk"<<endl;
    cout<<"\n\t\tO(-)                                  1600 tk\n"<<endl;

    new_back_select_reception();
}

//number 5 reception
int notices2(){

    system("cls");

    cout<<"\n*****NOTICS in Our Hospital*****\n"<<endl;
    time();
    cout<<"\n\t\t1--> No Cell Phone While in Triage and Patient Rooms"<<endl;
    cout<<"\n\t\t2--> No Smoking Within 25 Feet of Building Entrance"<<endl;
    cout<<"\n\t\t3--> Don't talking loudly"<<endl;
    cout<<"\n\t\t4--> If have any query then contact the information desk\n"<<endl;
    cout<<"\n\t\tHelp Line : ( 16334 ) 24 Hours or (01858492168-9)\n"<<endl; 

    new_back_select_reception();
}

//number 6 reception
int Calculator(){

    system("cls");

    cout<<"\n*****Calculator*****\n"<<endl;
    time();
    choose_calculator();

}


int choose_calculator(){
    int n,t;
    cout<<"\n\t1--> Choose Standard mode to press 1 : "<<endl;
    cout<<"\n\t2--> Scientific mode to press 2 : "<<endl;
    cout<<"\n\tseelect opction : ";
    cin>>t;

    if(t==1){

    system("cls");

    cout<<"\n\tStandard Mode\n"<<endl;
    time();
    printf("\n\t\t1--> calculate addition\n");
    printf("\n\t\t2--> calculate subtraction\n");
    printf("\n\t\t3--> calculate  multiplication\n");
    printf("\n\t\t4--> calculate division\n");
    printf("\n\t\t5--> calculate Discount_Then_Total_price\n");

    printf("\n\t\tseelect opction : ");
    scanf("%d",&n);

    switch(n){

        case 1:
        addition();
        break;
        case 2:
        subtraction();
        break;
        case 3:
        multiplication();
        break;
        case 4:
        division();
        break;
        case 5:
        Discount();
        break;

}

}

else if(t==2)
{
   int g;
   system("cls");

    cout<<"\n\tScientific Mode\n"<<endl;
    time();
    printf("\n\t\t1--> calculate power\n");
    printf("\n\t\t2--> calculate square root operation\n");
    printf("\n\t\t3--> calculate sin\n");
    printf("\n\t\t4--> calculate cos\n");
    printf("\n\t\t5--> calculate tan\n");
    printf("\n\t\t6--> calculate log\n");
    printf("\n\t\t7--> calculate log10\n");
   
    printf("\n\t\tseelect opction : ");
    scanf("%d",&g);

    switch(g){

        case 1:
        power();
        break;
        case 2:
        square_root();
        break;
        case 3:
        sin();
        break;
        case 4:
        cos();
        break;
        case 5:
        tan();
        break;
        case 6:
        log();
        break;
        case 7:
        log10();
        break;
    }

}

}


int back_calculator(){
    int n;
    cout<<"\nBack to calculate to press 1 or Exit system to press any key : --> ";
    cin>>n;
    if(n==1){
       choose_calculator();
    }
}

//calculate code
int addition(){

    system("cls");

    cout<<"\nCalculate Addition : \n"<<endl;
    time();

    int i,sum,n;
 
    printf("\n\tHow to number Calculate : ");
    cin>>n;
    int arr[n];
    cout<<"\n\tPress number : ";
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    sum=0;
    for(i=0;i<n;i++){
        sum+=arr[i];
    }
    cout<<"\n\tTotal sum is : "<<sum<<endl;
    
    back_calculator();
}


int Discount(){   

    system("cls");

    cout<<"\nCalculate Discount : \n"<<endl;
    time();

    int i,sum,n;
    double b,dis,s,total;
 
    printf("\n\tHow to number Calculate : ");
    cin>>n;
    int arr[n];
    cout<<"\n\tPress number : ";
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    sum=0;
    for(i=0;i<n;i++){
        sum+=arr[i];
    }
    cout<<"\n\tHow persen Discount : ";
    cin>>b;
    s=b/100.0;
    dis=sum*s;
    total=sum-dis;
    cout<<"\n\tDiscount_Then_Total_number : ";
    cout<<total<<endl;

    back_calculator();
}


int subtraction(){

    system("cls");
    
    cout<<"\nCalculate Subtraction : \n"<<endl;
    time();
    int i,substraction,n;
 
    printf("\n\tHow to number Calculate : ");
    cin>>n;
    int arr[n];
    cout<<"\n\tPress number : ";
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    substraction=0;
    for(i=0;i<n;i++){
        substraction-=arr[i];
    }
    cout<<"\n\tTotal substraction is : "<<substraction<<endl;
    
     back_calculator();
}


int multiplication(){

    system("cls");
    
    cout<<"\nCalculate Multiplication : \n"<<endl;
    time();

    int i,multi,n;
 
    printf("\n\tHow to number Calculate : ");
    cin>>n;
    int arr[n];
    cout<<"\n\tPress number : ";
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    multi=1;
    for(i=0;i<n;i++){
        multi*=arr[i];
    }
    cout<<"\n\tTotal multiplication is : "<<multi<<endl;

     back_calculator();
}


float division(){

    system("cls");
    
    cout<<"\nCalculate Division : \n"<<endl;
    time();

    float a,b,c;
    printf("\n\tInput 2 number : ");
    scanf("%f %f", &a, &b);
    if(b!=0){
    c = a/b;
    printf("\n\tDivision : %.2f\n",c);
}
else{
    printf("\n\tMath error\n");
}
    back_calculator();
}


float power(){

    system("cls");

    cout<<"\nCalculate Power : \n"<<endl;
    time();

    float a,b,c;
    printf("\n\tInput 2 number example 1st numer is base and 2nd number is power : ");
    scanf("%f %f", &a, &b);
    c = pow(a,b);
    printf("\n\tPower : %.2f\n",c);

    back_calculator();
}


float square_root(){

    system("cls");
    
    cout<<"\nCalculate Square_root : \n"<<endl;
    time();

    float a,b,c;
    printf("\n\tInput 1 number : ");
    scanf("%f", &a);
    c = sqrt(a);
    printf("\n\tSquare_root : %.2f\n",c);

    back_calculator();
}


float sin(){

    system("cls");

    cout<<"\nCalculate Sin : \n"<<endl;
    time();

  float a, result;
  printf("\n\tInput 1 number : ");
  scanf("%f",&a);
  result = sin (a*PI/180);
  printf ("\n\tThe sine of %.2f Degrees is %.2f.\n", a, result );

    back_calculator();
}


float cos(){

    system("cls");
  
  cout<<"\nCalculate Cos : \n"<<endl;
  time();

  float a, result;
  printf("\n\tInput 1 number : ");
  scanf("%f",&a);
  result = cos (a*PI/180);
  printf ("\n\tThe sine of %.2f Degrees is %.2f.\n", a, result );

  back_calculator();
}


float tan(){
    system("cls");

  cout<<"\nCalculate Tan : \n"<<endl;
  time();

  float a, result;
  printf("\n\tInput 1 number : ");
  scanf("%f",&a);
  result = tan (a*PI/180);
  printf ("\n\tThe sine of %.2f Degrees is %.2f.\n", a, result );

  back_calculator();
}


float log(){

    system("cls");

  cout<<"\nCalculate Log : \n"<<endl;
  time();

  float a, result;
  printf("\n\tInput 1 number : ");
  scanf("%f",&a);
  result = log (a);
  printf ("\n\tLog(%.2f) = %.2f\n", a, result );

  back_calculator();
}


float log10(){
    system("cls");

  cout<<"\nCalculate Log10 : \n"<<endl;
  time();

  float a, result;
  printf("\n\tInput 1 number : ");
  scanf("%f",&a);
  result = log10(a);
  printf ("\n\tLog10(%.2f) = %.2f\n", a, result );

  back_calculator();
}