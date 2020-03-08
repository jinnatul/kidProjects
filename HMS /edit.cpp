#include<bits/stdc++.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
 

using namespace std;

int main()
{
    char search_id[20],id[20],name[20],age[20],specilast[20],experience[20],city[20],visit_tk[20],visit_time[20];
    char id1[20],name1[20],age1[20],specilast1[20],experience1[20],city1[20],visit_tk1[20],visit_time1[20];

    FILE * morol;
    FILE * morol1;
    morol = fopen("doctor.txt","r");
    morol1 =  fopen("doc.txt","a");
    cout<<"search id : ";#include<bits/stdc++.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
 

using namespace std;

int main()
{
    char search_id[20],id[20],name[20],age[20],specilast[20],experience[20],city[20],visit_tk[20],visit_time[20];
    char id1[20],name1[20],age1[20],specilast1[20],experience1[20],city1[20],visit_tk1[20],visit_time1[20];

    FILE * morol;
    FILE * morol1;
    morol = fopen("doctor.txt","r");
    morol1 =  fopen("doc.txt","a");
    cout<<"search id : ";
    cin>>search_id;

    while(fscanf(morol,"%s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\n",id,name,age,specilast,experience,city,visit_tk,visit_time)!=EOF){
         
         if(strcmp(search_id, id)==0){
           
           cout<<"1--> change name : "<<endl;
           cout<<"2--> change age : "<<endl;
           cout<<"3--> change specilast : "<<endl;
           cout<<"4--> change experience : "<<endl;
           cout<<"5--> change city : "<<endl;
           cout<<"6--> change visit_tk : "<<endl;
           cout<<"7--> change visit_time : "<<endl;
           int n;
           cin>>n;
           if(n==1){

              cout<<"input new name : ";
               cin >> name1;
               fprintf(morol1, "%s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\n",id, name1,age,specilast,experience,city,visit_tk,visit_time);
           }          

           }
            else{

               fprintf(morol1, "%s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\n",id, name,age,specilast,experience,city,visit_tk,visit_time);
           }
         }
        /* else{

            fprintf(morol1, "%s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\n",id,name,age,specilast,experience,city,visit_tk,visit_time );
         }   
  */   

    fclose(morol);
    fclose(morol1);


}
 

    cin>>search_id;

    while(fscanf(morol,"%s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\n",id,name,age,specilast,experience,city,visit_tk,visit_time)!=EOF){
         
         if(strcmp(search_id, id)==0){
           
           cout<<"1--> change name : "<<endl;
           cout<<"2--> change age : "<<endl;
           cout<<"3--> change specilast : "<<endl;
           cout<<"4--> change experience : "<<endl;
           cout<<"5--> change city : "<<endl;
           cout<<"6--> change visit_tk : "<<endl;
           cout<<"7--> change visit_time : "<<endl;
           int n;
           cin>>n;
           if(n==1){

              cout<<"input new name : ";
               cin >> name1;
               fprintf(morol1, "%s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\n",id, name1,age,specilast,experience,city,visit_tk,visit_time);
           }          

           }
            else{

               fprintf(morol1, "%s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\n",id, name,age,specilast,experience,city,visit_tk,visit_time);
           }
         }
        /* else{

            fprintf(morol1, "%s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\n",id,name,age,specilast,experience,city,visit_tk,visit_time );
         }   
  */   

    fclose(morol);
    fclose(morol1);


}
 
