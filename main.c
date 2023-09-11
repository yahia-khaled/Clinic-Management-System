#include<stdio.h>
#include"STD_TYPES.h"

typedef struct 
{
	u8 age;
	u8 gender ;
	u8 name[30];
	u16 ID;
}patient_t;

typedef struct
{
u8 status;
patient_t patient;	
}slot;

patient_t patients [20];
slot slots[5];
u8 numPatients = 0;
u8 intial = 1;
u8 numReservation = 0;
u8 numRestPatient = 0;

void add_new_patient(void);
u8 found_ID (u16 ID,u8 * index);
void edit_patient_record(void);
void reserve_slot(void);
void cancle_reservation(void);
void view_patient_record(void);
void show_reservation(void);

int main(void)
{
	u8 choice,tries ,operation;
	s16 check_password;
	while(1)
	{
		
	printf("to enter admin mode enter 1\n");
	printf("to enter user mode enter 2\n");
	printf("your choice : ");
	scanf(" %u",&choice);
	
	//error occur
	
	
	printf("debugging \n");
	
	if(choice == 1)
	{
		tries = 0;
		for(u8 i = 0 ; i < 3 ; i++)
		{
			
		printf("enter password :");
		scanf("%u",&check_password);
		if(check_password != 1234)
		{
			printf("incorrect password \n");
			tries++;
		if(tries == 3)
			return;		
		}
		else
		{
			break;
		}
		
		}		
		
		printf("1) add_new_patient\n");
		printf("2) edit_patient_record \n");
		printf("3) reserve_slot \n");
		printf("4) cancle_reservation \n");
		printf("your choice : ");
		scanf(" %u",&operation);
		switch(operation)
		{
			case 1 : add_new_patient(); break;
			case 2 : edit_patient_record(); break;
			case 3 : reserve_slot(); break;
			case 4 : cancle_reservation(); break;
			default: printf("invalid operation \n"); break;
		}
	}
	else if (choice == 2)
	{
		printf("1) view patient record \n");
		printf("2) view today's reservation \n");
		
		printf("your choice : ");
		scanf("%u",&operation);
		switch(operation)
		{
			case 1 : 
			view_patient_record();
			break;
			case 2 :
			show_reservation();
			break;
			default:
			printf("invalid choice \n");
			break;
		}
		continue;
	}
	else
	{
		printf("invalid choice \n");
		continue;
	}
	
	}
}

void add_new_patient(void)
{
	u8 patient_index;
	patient_t newPatient;
	printf("Enter name: ");
    scanf(" %s", newPatient.name);
    
    printf("Enter age: ");
    scanf(" %d", &newPatient.age);
    
    printf("Enter gender (M/F): ");
    scanf(" %c", &newPatient.gender);
    
    printf("Enter ID: ");
    scanf(" %d", &newPatient.ID);
    
	if(found_ID(newPatient.ID,&patient_index))
	{
		printf("ID is already exist \n");
		return;
	}
 
    patients[numPatients] = newPatient;
    numPatients++;
	numRestPatient++;
}
u8 found_ID (u16 ID,u8 * index)
{
	for(int i = 0 ; i < numPatients ; i++)
	{
		if(patients[i].ID == ID)
		{
			*index = i;
			return 1;
		}
	}
	return 0;
}

void edit_patient_record(void)
{
	u16 target_ID;
	u8 index,found = 0;
	if(numPatients == 0)
	{
		printf("there is no patient \n");
		return;
	}
	printf("enter ID : ");
	scanf("%u",&target_ID);
	for(u8 i = 0 ; i < numPatients ; i++)
	{
		if(target_ID == patients[i].ID )
		{
			index = i;
			found = 1;
			break;
		}
	}
	if(found)
	{
		u8 option;
		while(1)
		{
			printf("enter 1 to edit name \n");
			printf("enter 2 to edit age \n");
			printf("enter 3 to edit gender \n");
			printf("enter 4 to exit \n");
			printf("your choice : ");
			scanf("%u",&option);
			switch(option)
			{
				case 1 :
				printf("name : %s \n",patients[index].name);
				printf("enter new name : ");
				scanf("%s",patients[index].name);
				break;
				case 2 : 
				printf("age : %u \n",patients[index].age);
				printf("enter new age : ");
				scanf("%u",&patients[index].age);
				break;
				case 3 :
				printf("gender : %u \n",patients[index].gender);
				printf("enter new gender : ");
				scanf("%c",&patients[index].gender);
				break;
				case 4 :
				printf("exit \n");
				return;
				break;
				default :
				printf("invalid choice \n");
				break;
			}
			
		}
	}
	else
	{
		printf("ID is not exist \n");
		return;
	}
}
void reserve_slot(void)
{
	u8 numSlot,available_slot = 0,patient_index;
	u16 patient_id;
	if(numPatients == 0)
	{
		printf("there is no patient \n");
		return;
	}
	if(numRestPatient <= 0)
	{
		printf("there is no patient available for reservation \n");
		return;
	}
	if(intial)
	{
		for(u8 i = 0 ; i< 5 ; i++)
		{
			slots[i].status = 0;
		}
		intial = 0;
	}
	printf("available slot : \n");
	for(u8 i = 0 ; i < 5 ; i++)
	{
		if(slots[i].status == 0)
		{
			available_slot =1;
			switch(i)
			{
				case 0 :
				printf("0) 2pm to 2:30pm \n");
				break;
				case 1 : 
				printf("1) 2:30pm to 3pm \n");
				break;
				case 2 :
				printf("2) 3pm to 3:30pm \n");
				break;
				case 3 :
				printf("3) 4pm to 4:30pm \n");
				break;
				case 4 :
				printf("4) 4:30pm to 5pm \n");
				break;
				
			}
		}
	}
	if(!available_slot)
	{
		printf("no available slot \n");
		return;
	}
	while(1)
	{
	printf("enter slot number : ");
	scanf("%u",&numSlot);
	if(slots[numSlot].status)
	{
		printf("slot is not available \n");
	}
	else
	{
		break;
	}
	}
	while(1)
	{
		
	printf("enter patient ID : ");
	scanf(" %u",&patient_id);
	if(found_ID(patient_id,&patient_index))
	{
		break;
	}
	else
	{
		printf("not available ID \n");
	}
	}
	slots[numSlot].status = 1;							//reserve slot
	slots[numSlot].patient = patients[patient_index];
	numReservation++;
	numRestPatient--;
}
void cancle_reservation(void)
{
	u8 patient_index,target_ID;
	if(numReservation == 0)
	{
		printf("there is no reservation \n");
		return;
	}
	while(1)
	{
	printf("enter the id : ");
	scanf("%u",&target_ID);
	if(found_ID(target_ID,&patient_index))
	{
		u8 index_slot;
		for(u8 i = 0 ; i < 5 ; i++)
		{
			if(slots[i].patient.ID == target_ID)
			{
				slots[i].status = 0;
				numReservation--;
				numRestPatient++;
				return;
			}
		}
	}
	else
	{
		printf("ID is not exist \n");
	}
	}
}

void view_patient_record(void)
{
	u16 view_ID ;
	u8 patient_index;
	if(numPatients == 0)
	{
		printf("there is no patient \n");
		
	}
	printf("enter ID : ");
	scanf(" %u",&view_ID);
	if(found_ID(view_ID,&patient_index))
	{
		printf("name : %s \n",patients[patient_index].name);
		printf("gender : %c \n",patients[patient_index].gender);
		printf("age : %u \n",patients[patient_index].age);
		
		
	}
	else
	{
		printf("ID is not exist \n");
		
	}
	
}
void show_reservation(void)
{
	if(numReservation == 0)
	{
		printf("there is no reservation \n");
		return;
	}
	for(u8 i = 0 ; i < 5 ; i++)
	{
		if(slots[i].status)
		{
			switch(i)
			{
				case 0 :
				printf("0) 2pm to 2:30pm \n");
				break;
				case 1 : 
				printf("1) 2:30pm to 3pm \n");
				break;
				case 2 :
				printf("2) 3pm to 3:30pm \n");
				break;
				case 3 :
				printf("3) 4pm to 4:30pm \n");
				break;
				case 4 :
				printf("4) 4:30pm to 5pm \n");
				break;
				
			}
			printf("patient ID : %u \n",slots[i].patient.ID);
		}
	}
	
}