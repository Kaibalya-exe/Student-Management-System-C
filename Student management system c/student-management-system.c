//Student Management System.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student 
{
    char name[50];
    int ph_num ;
    char section[10];
    int year;
    char batch[10];
    char course[50];
    char USN[15] ;
    float CGPA ;
    char email[300];

};

int login(char username[] , char password[])
{
    if (strcmp(username , "Admin12345") == 0 && strcmp(password , "Admin005") == 0)
    {
        printf("Login Successfull , Welcome %s" , username);
    }
    else if (strcmp(username , "Student123") == 0 && strcmp(password , "Student005") == 0)
    {
        printf("Login Successfull , Welcome %s" , username);
    }
    else 
    {
        printf("Invalid Username or Password! Please try again");
    }
    
    return 0;
}

int add_student()
{
    FILE *f = fopen("students.dat" , "ab"); 
    if (f == NULL)
{
    printf("Error opening file!\n");
    return 0;
}
    struct student s ;
    
    printf("Enter student's name : ");
    scanf(" %49[^\n]" , s.name);
    
    printf("Enter student's section : ");
    scanf("%s" , s.section);
    
    printf("Enter student's year : ");
    scanf("%d" , &s.year);
    
    printf("Enter student's batch : ");
    scanf(" %9[^\n]", s.batch);
    
    printf("Enter student's course : ");
    scanf(" %49[^\n]", s.course);
    
    printf("Enter student's USN : ");
    scanf("%s" , s.USN);
    
    printf("Enter Student's CGPA : ");
    scanf("%f" , &s.CGPA);
    
    printf("Enter student's Email : ");
    scanf("%s" , s.email);
    
    printf("Enter student's Phone Number : ");
    scanf("%d" , &s.ph_num);
    
    fwrite(&s , sizeof(s) , 1 , f);
    fclose(f);
    
    printf("Student's Information Successfully Added!\n");
    
    return 0;
}

int view_all_student()
{
    FILE *f = fopen("students.dat" , "rb");
    struct student s;
    
    if (f == NULL )
    {
        printf("No Student Record Found.\n");
        return 0;
    }
    while (fread(&s , sizeof(s) , 1 , f))
    {
        printf("\n------------------------\n");
        printf("\nName : %s\n", s.name);
        printf("Section : %s\n" , s.section);
        printf("Year : %d\n" , s.year);
        printf("Batch : %s\n" , s.batch);
        printf("Course : %s\n" , s.course);
        printf("USN : %s\n" , s.USN);
        printf("CGPA : %.2f\n" , s.CGPA);
        printf("Email : %s\n" , s.email);
        printf("Phone Number : %d\n" , s.ph_num);
    }
    
    fclose(f);
    
    return 0;
}

int search_student()
{
    FILE *f = fopen("students.dat" , "rb");
    if (f == NULL)
{
    printf("No Student Record Found.\n");
    return 0;
}
    struct student s;
    char Usn[20] , found = 0;
    
    printf("Enter Student's USN : ");
    scanf("%s" , Usn);
    
    while (fread(&s , sizeof(s) , 1 , f))
    {
        if (strcmp(s.USN, Usn) == 0)
        {
            printf("Result Found!\n");
            printf("\nName : %s\n", s.name);
            printf("Section : %s\n" , s.section);
            printf("Year : %d\n" , s.year);
            printf("Batch : %s\n" , s.batch);
            printf("Course : %s\n" , s.course);
            printf("USN : %s\n" , s.USN);
            printf("CGPA : %.2f\n" , s.CGPA);
            printf("Email : %s\n" , s.email);
            printf("Phone Number : %d\n" , s.ph_num);
            
         found = 1 ;
         break;
        }
    }
        if (!found)
        {
         printf("Not Found!\n");
        }
    fclose(f);
 return 0 ;
}

//Students Limited Info Access :

int Sview_all_student()
{
    FILE *f = fopen("students.dat" , "rb");
    struct student s;
    
    if (f == NULL )
    {
        printf("No Student Record Found.\n");
        return 0;
    }
    while (fread(&s , sizeof(s) , 1 , f))
    {
        printf("\n------------------------\n");
        printf("\nName : %s\n", s.name);
        printf("Year : %d\n" , s.year);
        printf("Batch : %s\n" , s.batch);
        printf("Course : %s\n" , s.course);
        printf("USN : %s\n" , s.USN);
    }
    
    fclose(f);
    
    return 0;
}

//Students Limited Search Info :

int Ssearch_student()
{
    FILE *f = fopen("students.dat" , "rb");
    if (f == NULL)
{
    printf("No Student Record Found.\n");
    return 0;
}
    struct student s;
    char Usn[20] , found = 0;
    
    printf("Enter Student's USN : ");
    scanf("%s" , Usn);
    
    while (fread(&s , sizeof(s) , 1 , f))
    {
        if (strcmp(s.USN, Usn) == 0)
        {
            printf("Result Found!\n");
            printf("\nName : %s\n", s.name);
            printf("Year : %d\n" , s.year);
            printf("Batch : %s\n" , s.batch);
            printf("Course : %s\n" , s.course);
            printf("USN : %s\n" , s.USN);
            
         found = 1 ;
         break;
        }
    }
        if (!found)
        {
         printf("Not Found!\n");
        }
    fclose(f);
 return 0 ;
}

int user(char username[] , char password[])
{
    int choice ;
    
    //Admin Access :
    
    if (strcmp(username , "Admin12345") == 0 && strcmp(password , "Admin005") == 0)
    {
      while(1)
      {
        printf("\n1. Add student information.\n");
        printf("2. view all student information.\n");
        printf("3. search student by USN. \n");
        printf("4. Exit.\n");
        printf("What would you like to do (select the number) : \n");
        scanf("%d" , &choice);
        
        
        switch (choice)
        {
            case 1:
              add_student();
              break;
            case 2: 
              view_all_student(); 
              break;
            case 3: 
              search_student(); 
              break;
            case 4:
              printf("Exiting...");
              exit(0); 
              break;
            default:
              printf("Invalid Input.");
        }
      }
    }
    
    //Student Access :
    
    if (strcmp(username , "Student123") == 0 && strcmp(password , "Student005") == 0)
    {
        while(1)
        {
            printf("\n1.View All Student Information.\n");
            printf("2.Search Student by USN.\n");
            printf("3.Exit.\n");
            printf("What would you like to do (select the number) : \n");
            scanf("%d" , &choice);
            
            switch(choice)
            {
                case 1:
                Sview_all_student();
                break;
                
                case 2:
                Ssearch_student();
                break;
                
                case 3:
                printf("Exiting...");
                exit(0);
                break;
                
                default:
                 printf("Invalid Input , Try Again!");
            }
        }
    }
    
    return 0 ;
}

int main()
{
    char username[20];
    char password[20];
    
    printf("------Login Portal------\n");
    printf("Enter your username : ");
    scanf("%s" , username);
    printf("Enter the password : ");
    scanf("%s", password);
    
    login(username , password);
    user(username , password);
    
    return 0;
}