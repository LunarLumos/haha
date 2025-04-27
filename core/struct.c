#include<stdio.h>
struct Student{
    int id;
    float cgpa;
    char name[20];

};
int main(){
    struct Student s;
    printf("Enter your ID:\n");
    scanf("%d",&s.id);
    printf("Enter your Name:\n");
    scanf("%s",&s.name);
    printf("Enter your CGPA\n");
    scanf("%f",&s.cgpa);
    printf("Name: %s    ID: %d  CGPA: %.2f",s.name,s.id,s.cgpa);    
}