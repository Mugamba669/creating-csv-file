#include<stdio.h>
	int n;
	int i;
	int id;
	double balance;
	char name[100];
	char gender[10];
	char date[100];
	char intro[100] = "----------------Covid-19 Management Reporting System-----------------";
	char user[100];
	char codition[100];
	char official[100] = "Health Official username:";
		
	FILE *cfPtr;
	
void main(){
	printf("\n----------------Covid-19 Management Reporting System-----------------\n");
	printf("\nEnter the number of patient records :");
	scanf("%d",&n);
	
	if((cfPtr = fopen("treat.txt","w")) == NULL){
		
		printf("File couldn`t be loaded.");
		
	}else{
		
		printf("\t\n-------------------Health Official use-------------\n");
		printf("Enter your username: ");
		scanf("%s",&user);
			
		printf("\t\t-----Patient Details------\n");
	
		for(i = 0; i < n && !feof(stdin); i++){
			printf("\nRecord[%d]\n",i+1);
		printf("\nPatient`s name:");
		scanf("%s",&name);
		
		printf("\nDate of identification:");
		scanf("%s",&date);
		
		printf("\nGender:");
		scanf("%s",&gender);
		
		printf("\nPatient`s condition (symptomatic and asymptomatic):");
		scanf("%s",&codition);
		printf("\t\n----------------------------------------------------------------------------------\n\n");
		
		//details......
				
				fprintf(cfPtr,"%d,%s,%s,%s,%s\n",id,name,date,gender,codition);
			}
			fclose(cfPtr);
		}
}
// gu3vdidi

