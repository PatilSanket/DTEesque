#include<stdio.h>
#include<string.h>

int compare(char str1[],char str2[]);

typedef struct student
{
   char name[20];
   int marks;
   char pref[3][6];
   char clg[6];
}STUD;

int main()
{
  STUD st[3]={0},temp;
  int i=0,j=0,k=0,p=0,diff=0;

  for(i=0;i<3;i++)
  {
     printf("Enter name of student %d:\n",i+1);
     scanf("%s",st[i].name);
     
     printf("Enter marks of student %d:\n",i+1);
     scanf("%d",&st[i].marks);
  
     printf("Enter preferences:\n");
     for(j=0;j<3;j++)
     {
       scanf("%s",st[i].pref[j]);
     }
  }

  for(i=0;i<2;i++)
  {
     for(j=0;j<2-i;j++)
     {
        if(st[j].marks<st[j+1].marks)
        {
            temp=st[j];
            st[j]=st[j+1];
            st[j+1]=temp;
        }
     }
  }  

  printf("Students with descending order of marks scored:\n");
  for(i=0;i<3;i++) 
  {
      printf("%s\n",st[i].name);
  }
  
  for(i=0;i<6;i++)
  st[0].clg[i]=st[0].pref[0][i];

  printf("%s got %s\n",st[0].name,st[0].clg);

  for(i=1;i<3;i++)
  { 
      for(k=0;k<3;k++)
      {
           for(p=0;p<i;p++)
           {
                 diff=compare(st[p].clg,st[i].pref[k]);
                 //printf("%d\n",diff);
                 if(diff==1)
                    continue;
                else if(diff==0)
                {
                    break;
                }
           }
           if(p==i)
           {
             for(j=0;j<6;j++)
             {
                st[i].clg[j]=st[i].pref[k][j];
             }
             break; 
          }  
           else 
             continue;
      }            
     printf("%s got %s\n",st[i].name,st[i].clg);
  }
  /*for(i=1;i<3;i++)
  {
   for(k=1;k<3-i;k++)
   {
    diff=compare(st[k-1].clg,st[k].clg);
    if(diff==0)
    {
      for(j=0;j<6;j++)
      st[k].clg[j]=st[k].pref[0][j];
    }
    else
      for(j=0;j<6;j++)
      st[k].clg[j]=st[k].pref[1][j];
    printf("%s got %s\n",st[k].name,st[k].clg);
   }
  }

   if(diff==0)
         {
           for(j=0;j<6;j++)
           st[i].clg[j]=st[i].pref[k][j]; 
         }
         else
         {
           for(j=0;j<6;j++)
           st[i].clg[j]=st[i].pref[k][j];


      {
                     for(j=0;j<6;j++)
                     st[i].clg[j]=st[i].pref[k][j]; 
                     break;
                 }*/  
         

  return 0;
}

int compare(char str1[],char str2[])
{
  int i=0;

  for(i=0;(i<strlen(str1))&&(i<strlen(str2));i++)
  {
     if(str1[i]==str2[i])
        continue;     
     else
        break;
  }
  if((i==strlen(str1))||(i==strlen(str2)))
   return 0;
  else
   return 1;
}



























 
