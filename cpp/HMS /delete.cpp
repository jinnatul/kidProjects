
#include<bits/stdc++.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
 

using namespace std;

int main()
{
    char arr[20],id[20],name[20],age[20],specilast[20],experience[20],city[20],visit_tk[20],visit_time[20];

    FILE * morol;
    FILE * morol1;
    morol = fopen("doctor.txt","r");
    morol1 =  fopen("doc.txt","a");
    cin>>arr;

    while(fscanf(morol,"%s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\n",id,name,age,specilast,experience,city,visit_tk,visit_time)!=EOF){
         
         if(strcmp(arr,id)==0){
            continue;
         }
         else{

            fprintf(morol1, "%s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\n",id,name,age,specilast,experience,city,visit_tk,visit_time );
         }   
     
        
    }

    fclose(morol);
    fclose(morol1);


}
 
