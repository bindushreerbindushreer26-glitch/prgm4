#include<stdio.h>
#include<stdlib.h>
struct day{
char *dayname;
int date;
char *activity;
};
void create (struct day *day){
day->dayname=(char*)malloc(sizeof (char)*20);
day->activity=(char*)malloc(sizeof (char)*100);
printf("enter the day name:");
scanf("%s",day->dayname);
printf("entr the date");
scanf("%d",day->date);
printf("enter the activity for the day:");
scanf("%[^\n]",day->activity);
}
void read (struct day*calendar,int size){
for(int i=0;i<size;i++){
   printf("enter deatials of day %d:\n",i+1);
    create(&calendar[i]);
}}
void display(struct day*calendar,int size){
printf("\n week activity details:\n");
for(int i=0;i<size;i++){
    printf("day%d:\n",i+1);
    printf("day name:%s\n",calendar[i].dayname);
    printf("date:%d\n",calendar[i].date);
    printf("activity:%s\n",calendar[i].activity);
}}
void freememory(struct day *calendar,int size){
for(int i=0;i<size;i++){
    free(calendar[i].dayname);
     free(calendar[i].activity);
}
}
int main(){
int size;
printf("enter the number of days in the week");
scanf("%d",&size);
struct day*calendar=(struct day*)malloc(sizeof(struct day)*size);
if (calendar=NULL){
    printf("memory allocation failed exiting program\n");
    return 1;

}
read(calendar,size);
display(calendar,size);
freememory(calendar,size);
free(calendar);
return 0;
}
