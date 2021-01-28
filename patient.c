#include <stdio.h>
#include <stdlib.h>
void storePatientData(int choice); // function prototype
// file pointer
FILE *file;

char filename[30],district[20],condition[20],gender[10],date[30],fname[30],sname[30],username[40];
int flag = 0 , cases,choice;

void main(){
   printf("\n***********Welcome to Covid-19 Management and Reporting System*****************\n");
   printf("\n1.Addpatient (One patient at a time).");
   printf("\n2.Addpatient list (Store multiple patients).\n");
   printf("\nEnter your choice:");
   scanf("%d",&choice);
//    Store patients.
   storePatientData(choice);
}

// patients data
void storePatientData(int choice){
    switch (choice){
        case 1:
            printf("Enter your username:");
            scanf("%s",username);

            printf("Enter your district:");
            scanf("%s",district);
            // Store one patient data.
             printf("\nEnter your patient's name eg::(mugamba bruno):");
            scanf("%s %s",fname,sname);

            printf("\nEnter patient's gender:");
            scanf("%s",gender);

             printf("\nEnter the date of confirmation eg(dd-mm-yy):");
            scanf("%s",date);

            printf("\nEnter the patient's condition eg(symptomatic or asymptomatic):");
            scanf("%s",condition);
             printf("\n***********You have successfuly added one patient***************\n");
        break;

    case 2:
             printf("\nEnter the file name eg::(example.txt):");
             scanf("%s",filename);

            printf("Enter the number of patients to store in the file:");
            scanf("%d",&cases);

            file = fopen(filename,"w");

            if(file == NULL){
                perror("Error in creating the file!");
                exit(1);

            }else{
                // health official's information
                    printf("\n***********Health Official's Data***********\n");

                printf("\nEnter your username:");
                    scanf("%s",username);

                    printf("\nEnter your home district:");
                    scanf("%s",district);
                printf("\n***************************************\n");
                while(flag < cases && !feof(stdin)){
                    printf("\n***********Patient record[%d]***********\n",flag+1);
                    printf("\nEnter your patient's name eg::(mugamba bruno):");
                    scanf("%s %s",fname,sname);

                    printf("\nEnter patient's gender:");
                    scanf("%s",gender);

                    printf("\nEnter the date of confirmation eg(dd-mm-yy):");
                    scanf("%s",date);

                    printf("\nEnter the patient's condition eg(symptomatic or asymptomatic):");
                    scanf("%s",condition);

                    // Storing the data into the file.
                    fprintf(file,"%s %-2s %-4s %-2s %-4s %-2s\n",fname,sname,gender,date,condition,username);
                    printf("\n***********************************************************************\n");
                    flag++;
                }
                    printf("\n***********You have successfull stored %d patients in %s.**************\n",cases,filename);

            }
        break;
    };
}