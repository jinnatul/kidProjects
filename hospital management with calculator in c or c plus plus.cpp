#include<bits/stdc++.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#define PI 3.14159265

using namespace std;

char manager_name[15]="jinnatul";
char manager_password[10]="1234";

char reception1_name[15]="morol";
char reception2_name[15]="arif";
char reception3_name[15]="jubaer";
char reception_password[10]="5678"; 

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


int main()
{
    cout<<"\n*****Welcome To Our Hospital Management System*****\t"<<endl;
    cout<<"\n\t 1--> Manager log in"<<endl;
    cout<<"\n\t 2--> Reception log in"<<endl;
    login();


 }

int back_main(){
    
    cout<<"\t\t 1--> Manager log in\t"<<endl;
    cout<<"\t\t 2--> Reception log in\t"<<endl;
    login();

}

int login(){

        int choose,a,b;
        char mana_check_name[15];
        char mana_check_pass[10];
        cout<<"\n\tEnter your choose : ";
        cin>>choose;
//log in manager

if(choose == 1){

        cout<<"\n*****Welcome to Manager Log In Part : *****"<<endl;
        
        cout<<"\n\tEnter Manager Name : ";
        cin>>mana_check_name;

        cout<<"\n\tEnter Manager Password : ";
        cin>>mana_check_pass;

        a=strcmp(manager_name,mana_check_name);
        b=strcmp(manager_password,mana_check_pass);

        if(a==0 && b==0){                          // compaire 2 string      

        manager_choose();
        
    }
    else{
        cout<<"\tWrong Password and Now enter right requirements"<<endl;
        back_main();                 //wrong password so call back_main function
    }
 }

//log in reception

else if (choose==2){
       char rec_check_name[20];
       char rec_check_pass[20];
       int n,m,i,j,q,p;
       cout<<"\n*****Welcome to Reception Log In Part : *****"<<endl;
        
        cout<<"\n\tEnter Reception Staff Name : ";
        cin>>rec_check_name;

        cout<<"\n\tEnter Reception Staff Password : ";
        cin>>rec_check_pass;

        n=strcmp(reception1_name,rec_check_name);
        m=strcmp(reception_password,rec_check_pass);
        i=strcmp(reception2_name,rec_check_name);
        j=strcmp(reception_password,rec_check_pass);
        p=strcmp(reception3_name,rec_check_name);
        q=strcmp(reception_password,rec_check_pass);     

        if((n==0 && m==0) || (i==0 && j==0) || (p==0 && q==0)){                          // compaire 2 string      

        reception_choose();
        
    }
    else{
        cout<<"\tWrong Password and Now enter right requirements"<<endl;
        back_main();                 //wrong password so call back_main function
    }

}

}

int manager_choose(){

        cout<<"\n***Main Page in Manager : ***"<<endl;
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
        cout<<"\tExit system : "<<endl;
    }
}

int reception_choose(){

        cout<<"\n***Main Page in Reception : ***"<<endl;
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

//number 1 manager
int reception_information(){

    cout<<"*****\nReception_Information list in our Hospital*****"<<endl;
    cout<<"\n\tStaff_Scheduling : "<<endl;
    cout<<"\n\t\tName :             Phone_number :      Email :            Entry_Time : "<<endl;
    cout<<"\n\t\tKarim Mia          01722567865         karim@gmail.com    8.00 AM To 4 PM"<<endl;
    cout<<"\n\t\tRaju Mia           01722567866         raju@gmail.com     4 PM To 12 AM"<<endl;
    cout<<"\n\t\tMamun Mia          01722567867         mamun@gmail.com    12 AM To 8 AM\n"<<endl;

    new_back_select_manager();

}
//number 2 manager
int doctor_list(){

    cout<<"\n*****Doctor list in our Hospital*****"<<endl;
    cout<<"\n\tDoctor Name :                 Department Name : \n"<<endl;
    cout<<"\tProf. Dr. Md. Samsul Arfin    ( Gastroenterology )\n"<<endl;
    cout<<"\tProf. Dr. Sanawar Hossain     ( Radiology )"<<endl;    
    cout<<"\n\tDr Ranadhir Kumar Kundu       ( Anesthesiology )\n"<<endl;   
    cout<<"\tDr. Fazle Rabbi Mohammed      ( Respiratory Medicine )\n"<<endl;
    cout<<"\tDr. A M Rejaus Satter         ( Neuro Surgery )\n"<<endl;
    cout<<"\tDr. Raihan Rabbani            ( Internal Medicine )\n"<<endl;
    cout<<"\tDr. Sharmin Haque             ( ICU )\n"<<endl;
    cout<<"\tDr. Syeda Ishrat Jahan        ( Dermatology )\n"<<endl;
    cout<<"\tDr. Sufia Nasrin Rita         ( Dental Care )\n"<<endl;
    cout<<"\tDr. Mahbub Mansur             ( Cardiology )\n"<<endl;
    cout<<"\tDr. Raihan Mansur             ( spine )\n"<<endl;

    new_back_select_manager();

}

//number 3
int patient_history(){
    cout<<"\n*****Daily patient history list in our Hospital*****"<<endl;
    cout<<"\n\tLast 20 patient history in Today : "<<endl;
    cout<<"\n\t\tPatient_Name :      Dr._Name :                   Total_Visit :    Last_Visit_Date :  Patient_Problem : "<<endl;
    cout<<"\n\t\tBarsha Akter        Dr. Sufia Nasrin Rita        3 Times          10/11/2017         Dental Care"<<endl;
    cout<<"\n\t\tSumon Mia           Dr. A M Rejaus Satter        2 Times          10/11/2017         Neuro Surgery"<<endl;
    cout<<"\n\t\tLaboni Akter        Prof. Dr. Md. Samsul Arfin   2 Times          10/11/2017         Gastroenterology"<<endl;
    cout<<"\n\t\tShamim Akter        Dr Ranadhir Kumar Kundu      3 Times          10/11/2017         Anesthesiology"<<endl;
    cout<<"\n\t\tSabbir Mia          Dr. Raihan Mansur            2 Times          10/11/2017         spine"<<endl;
    cout<<"\n\t\tFardin Mia          Dr. Sufia Nasrin Rita        2 Times          10/11/2017         Dental Care"<<endl;
    cout<<"\n\t\tAnamika Akter       Dr. Raihan Mansur            3 Times          10/11/2017         spine"<<endl;
    cout<<"\n\t\tTripty Akter        Dr. Mahbub Mansur            3 Times          10/11/2017         ardiology"<<endl;
    cout<<"\n\t\tSadiya Akter        Dr. Sufia Nasrin Rita        3 Times          10/11/2017         Dental Care"<<endl;
    cout<<"\n\t\tManik Mia           Dr. A M Rejaus Satter        2 Times          10/11/2017         Neuro Surgery"<<endl;
    cout<<"\n\t\tKorim Mia           Prof. Dr. Md. Samsul Arfin   2 Times          10/11/2017         Gastroenterology"<<endl;
    cout<<"\n\t\tShamim Akter        Dr Ranadhir Kumar Kundu      3 Times          10/11/2017         Anesthesiology"<<endl;
    cout<<"\n\t\tSabbir Mia          Dr. Raihan Mansur            2 Times          10/11/2017         spine"<<endl;
    cout<<"\n\t\tArif Mia            Dr. Sufia Nasrin Rita        2 Times          10/11/2017         Dental Care"<<endl;
    cout<<"\n\t\tRuma Akter          Dr. Raihan Mansur            3 Times          10/11/2017         spine"<<endl;
    cout<<"\n\t\tAnika Akter         Dr. Mahbub Mansur            3 Times          10/11/2017         ardiology"<<endl;  
    cout<<"\n\t\tFardin Mia          Dr. Sufia Nasrin Rita        2 Times          10/11/2017         Dental Care"<<endl;
    cout<<"\n\t\tAnamika Akter       Dr. Raihan Mansur            3 Times          10/11/2017         spine"<<endl;
    cout<<"\n\t\tTripty Akter        Dr. Mahbub Mansur            3 Times          10/11/2017         ardiology\n"<<endl;

    new_back_select_manager();
}
// number 4
int laboratory(){

    cout<<"\n*****laboratory list in our Hospital*****"<<endl;
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
    cout<<"\n*****Operation_Information list in our Hospital*****"<<endl;
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

    cout<<"\n*****Blood_Bank list in our Hospital*****"<<endl;
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

    cout<<"\n*****Day Staff_Scheduling list in our Hospital*****"<<endl;

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

    cout<<"\n*****NOTICS in Our Hospital*****"<<endl;
    cout<<"\n\t\t1--> No Cell Phone While in Triage and Patient Rooms"<<endl;
    cout<<"\n\t\t2--> No Smoking Within 25 Feet of Building Entrance"<<endl;
    cout<<"\n\t\t3--> Don't talking loudly"<<endl;
    cout<<"\n\t\t4--> If have any query then contact the information desk\n"<<endl;
    cout<<"\n\t\tHelp Line : ( 16334 ) 24 Hours or (01858492168-9)\n"<<endl; 

    new_back_select_manager();
}
// number 9
int Developer_information(){

    cout<<"\n*****Developer_Information*****"<<endl;
    cout<<"\n\tProject_Developer : "<<endl;
    cout<<"\n\n\t\tMd : Zinnatul Islam Morol"<<endl;
    cout<<"\n\t\tEmail : morolswediu@gmail.com"<<endl;
    cout<<"\n\t\tCell number: 01793696177"<<endl;
    cout<<"\n\t\tSWE_DIU_(22 Batch)"<<endl;
    cout<<"\n\t\t3rd Semester ( Section : C1 )"<<endl;
    cout<<"\n\n\t\tInstruction Help : Lamisha Rawshan (Class Madam)\n"<<endl;
    
    new_back_select_manager();

}

//number 1 reception
int doctor_list2(){

    cout<<"\n*****Doctor list in our Hospital*****"<<endl;
    cout<<"\n\tDoctor Name :                 Department Name : \n"<<endl;
    cout<<"\tProf. Dr. Md. Samsul Arfin    ( Gastroenterology )\n"<<endl;
    cout<<"\tProf. Dr. Sanawar Hossain     ( Radiology )"<<endl;    
    cout<<"\n\tDr Ranadhir Kumar Kundu       ( Anesthesiology )\n"<<endl;   
    cout<<"\tDr. Fazle Rabbi Mohammed      ( Respiratory Medicine )\n"<<endl;
    cout<<"\tDr. A M Rejaus Satter         ( Neuro Surgery )\n"<<endl;
    cout<<"\tDr. Raihan Rabbani            ( Internal Medicine )\n"<<endl;
    cout<<"\tDr. Sharmin Haque             ( ICU )\n"<<endl;
    cout<<"\tDr. Syeda Ishrat Jahan        ( Dermatology )\n"<<endl;
    cout<<"\tDr. Sufia Nasrin Rita         ( Dental Care )\n"<<endl;
    cout<<"\tDr. Mahbub Mansur             ( Cardiology )\n"<<endl;
    cout<<"\tDr. Raihan Mansur             ( spine )\n"<<endl;

    new_back_select_reception();

}

//number 2 reception
int laboratory2(){

    cout<<"\n*****laboratory list in our Hospital*****"<<endl;
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
    cout<<"\n*****Operation_Information list in our Hospital*****"<<endl;
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

    cout<<"\n*****Blood_Bank list in our Hospital*****"<<endl;
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

    cout<<"\n*****NOTICS in Our Hospital*****"<<endl;
    cout<<"\n\t\t1--> No Cell Phone While in Triage and Patient Rooms"<<endl;
    cout<<"\n\t\t2--> No Smoking Within 25 Feet of Building Entrance"<<endl;
    cout<<"\n\t\t3--> Don't talking loudly"<<endl;
    cout<<"\n\t\t4--> If have any query then contact the information desk\n"<<endl;
    cout<<"\n\t\tHelp Line : ( 16334 ) 24 Hours or (01858492168-9)\n"<<endl; 

    new_back_select_reception();
}
//number 6 reception
int Calculator(){

   
    cout<<"\n*****Calculator*****"<<endl;
    choose_calculator();

}

int choose_calculator(){
    int n,t;
    cout<<"\n\t1--> Choose Standard mode to press 1 : "<<endl;
    cout<<"\n\t2--> Scientific mode to press 2 : "<<endl;
    cout<<"\n\tseelect opction : ";
    cin>>t;

    if(t==1){
    cout<<"\n\tStandard Mode"<<endl;
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
    cout<<"\n\tScientific Mode\n"<<endl;
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
int addition(){
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
    total=sum=dis;
    cout<<"\n\tDiscount_Then_Total_number : ";
    cout<<total<<endl;
}

int subtraction(){
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
    float a,b,c;
    printf("\n\tInput 2 number example 1st numer is base and 2nd number is power : ");
    scanf("%f %f", &a, &b);
    c = pow(a,b);
    printf("\n\tPower : %.2f\n",c);

    back_calculator();
}

float square_root(){
    float a,b,c;
    printf("\n\tInput 1 number : ");
    scanf("%f", &a);
    c = sqrt(a);
    printf("\n\tSquare_root : %.2f\n",c);

    back_calculator();
}

float sin(){
  float a, result;
  printf("\n\tInput 1 number : ");
  scanf("%f",&a);
  result = sin (a*PI/180);
  printf ("\n\tThe sine of %.2f Degrees is %.2f.\n", a, result );

    back_calculator();
}

float cos(){
  float a, result;
  printf("\n\tInput 1 number : ");
  scanf("%f",&a);
  result = cos (a*PI/180);
  printf ("\n\tThe sine of %.2f Degrees is %.2f.\n", a, result );

  back_calculator();
}

float tan(){
  float a, result;
  printf("\n\tInput 1 number : ");
  scanf("%f",&a);
  result = tan (a*PI/180);
  printf ("\n\tThe sine of %.2f Degrees is %.2f.\n", a, result );

  back_calculator();
}

float log(){
  float a, result;
  printf("\n\tInput 1 number : ");
  scanf("%f",&a);
  result = log (a);
  printf ("\n\tLog(%.2f) = %.2f\n", a, result );

  back_calculator();
}

float log10(){
  float a, result;
  printf("\n\tInput 1 number : ");
  scanf("%f",&a);
  result = log10(a);
  printf ("\n\tLog10(%.2f) = %.2f\n", a, result );

  back_calculator();
}