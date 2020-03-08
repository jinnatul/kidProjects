#include <stdio.h>

int project();
int day();
int isLeapYear( int year );        /* True if leap year */
int leapYears( int year );         /* The number of leap year */
int todayOf( int y, int m, int d); /* The number of days since the beginning of the year */
long days( int y, int m, int d);   /* Total number of days */
void calendar(int y, int m);       /* display calendar at m y */
int fm(int date, int month, int year);
int day_of_week(int date, int month, int year);

int project(){
    int year,month;

    printf("Enter the month and year: ");
    scanf("%d %d", &month, &year);

    calendar(year, month);

    return 0;
}

int isLeapYear( int y ) /* True if leap year */
{
    return(y % 400 == 0) || ((y % 4 == 0) && (y % 100 != 0));
}

int leapYears( int y ) /* The number of leap year */
{
    return y/4 - y/100 + y/400;
}

int todayOf( int y, int m, int d) /* The number of days since the beginning of the year */
{
    static int DayOfMonth[] = 
        { -1/*dummy*/,0,31,59,90,120,151,181,212,243,273,304,334};

    return DayOfMonth[m] + d + ((m>2 && isLeapYear(y))? 1 : 0);
}

long days( int y, int m, int d) /* Total number of days */
{
    int lastYear;

    lastYear = y - 1;

    return 365L * lastYear + leapYears(lastYear) + todayOf(y,m,d);
}

void calendar(int y, int m) /* display calendar at m y */
{
    const char *NameOfMonth[] = { NULL/*dummp*/,
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    char Week[] = "Su Mo Tu We Th Fr Sa";
    int DayOfMonth[] =
        { -1/*dummy*/,31,28,31,30,31,30,31,31,30,31,30,31 };
    int weekOfTopDay;
    int i,day;

    weekOfTopDay = days(y, m, 1) % 7;
    if(isLeapYear(y))
        DayOfMonth[2] = 29;
    printf("\n     %s %d\n%s\n", NameOfMonth[m], y, Week);

    for(i=0;i<weekOfTopDay;i++)
        printf("   ");
    for(i=weekOfTopDay,day=1;day <= DayOfMonth[m];i++,day++){
        printf("%2d ",day);
        if(i % 7 == 6)
            printf("\n");
    }   
    printf("\n");
}





int main(){
    
    printf("1--> calendar : \n");
    printf("2--> Weak Day print : \n");
    int nn;
    scanf("%d",&nn);
    if(nn==1){
     
     project();
 }
 else if(nn==2){
     day();
 }

}

int day(){

   int date, month, year;
 
   printf("\nEnter the year ");
   scanf("%d", &year);
 
   printf("\nEnter the month ");
   scanf("%d", &month);
 
   printf("\nEnter the date ");
   scanf("%d", &date);
 
   day_of_week(date, month, year);


}


int fm(int date, int month, int year) {
   int fmonth, leap;
 
   //leap function 1 for leap & 0 for non-leap
   if ((year % 100 == 0) && (year % 400 != 0))
      leap = 0;
   else if (year % 4 == 0)
      leap = 1;
   else
      leap = 0;
 
   fmonth = 3 + (2 - leap) * ((month + 2) / (2 * month))
         + (5 * month + month / 9) / 2;
 
   //bring it in range of 0 to 6
   fmonth = fmonth % 7;
 
   return fmonth;
}
 
//----------------------------------------------
int day_of_week(int date, int month, int year) {
 
   int dayOfWeek;
   int YY = year % 100;
   int century = year / 100;
 
   printf("\nDate: %d/%d/%d \n", date, month, year);
 
   dayOfWeek = 1.25 * YY + fm(date, month, year) + date - 2 * (century % 4);
 
   //remainder on division by 7
   dayOfWeek = dayOfWeek % 7;
 
   switch (dayOfWeek) {
      case 0:
         printf("weekday = Saturday");
         break;
      case 1:
         printf("weekday = Sunday");
         break;
      case 2:
         printf("weekday = Monday");
         break;
      case 3:
         printf("weekday = Tuesday");
         break;
      case 4:
         printf("weekday = Wednesday");
         break;
      case 5:
         printf("weekday = Thursday");
         break;
      case 6:
         printf("weekday = Friday");
         break;
      default:
         printf("Incorrect data");
   }
   return 0;
}