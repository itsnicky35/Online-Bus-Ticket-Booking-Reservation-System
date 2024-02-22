#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int destination,travels,timing;
int lowerberth_seat,upperberth_seat;
char seat_no[36][5];
int seat_count=0;

struct ticket{
    int destination;
    float lower_berth;
    float upper_berth;
    int tickets[5][3][2];
    int available_seats[5][3][6][6];
}s[5];

char places[5][100]={"CHENNAI","BENGALORE","HYDERABAD","KOCHI","VIZAG"};
char agency[5][100]={"MBT TRAVELS","RKT TOURS AND TRAVELS","VKV TRAVELS","EXCEL TRAVELS","RED EXPRESS"};

struct timing{
    char timing[3][20];
}t[5];

void show_timings(int travels);
void database();
int receipt();
void booking();
void seats();
void show_timings(int travels);
void choose_travels();
void show_seatavailability();

void database(){
    //chennai database
    s[0].destination=1;
    s[0].lower_berth=750.00;
    s[0].upper_berth=600.00;
    for(int i=0;i<5;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<2;k++){
                s[0].tickets[i][j][k]=18;
            }
        }
    }
    
    //BENGALURU database
    s[1].destination=2;
    s[1].lower_berth=900.00;
    s[1].upper_berth=750.00;
    for(int i=0;i<5;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<2;k++){
                s[1].tickets[i][j][k]=18;
            }
        }
    }
    //HYDERABAD database
    s[2].destination=3;
    s[2].lower_berth=2500.00;
    s[2].upper_berth=2300.00;
    for(int i=0;i<5;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<2;k++){
                s[2].tickets[i][j][k]=18;
            }
        }
    }
    //KOCHI database
    s[3].destination=4;
    s[3].lower_berth=1300.00;
    s[3].upper_berth=1000.00;
    for(int i=0;i<5;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<2;k++){
                s[3].tickets[i][j][k]=18;
            }
        }
    }
    //VIZAG database
    s[4].destination=5;
    s[4].lower_berth=3000.00;
    s[4].upper_berth=2800.00;
    for(int i=0;i<5;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<2;k++){
                s[4].tickets[i][j][k]=18;
            }
        }
    }
    
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            for(int k=0;k<3;k++){
                for(int row=0;row<6;row++){
                    for(int col=0;col<6;col++){
                        s[i].available_seats[j][k][row][col]=1;
                    }
                }
            }
        }
    }
    strcpy(t[0].timing[0],"09:00 AM");
    strcpy(t[0].timing[1],"01:00 PM");
    strcpy(t[0].timing[2],"05:00 PM");
    strcpy(t[1].timing[0],"10:00 AM");
    strcpy(t[1].timing[1],"02:00 PM");
    strcpy(t[1].timing[2],"04:00 PM");
    strcpy(t[2].timing[0],"08:30 AM");
    strcpy(t[2].timing[1],"11:00 AM");
    strcpy(t[2].timing[2],"03:00 PM");
    strcpy(t[3].timing[0],"12:00 PM");
    strcpy(t[3].timing[1],"04:00 PM");
    strcpy(t[3].timing[2],"10:00 PM");
    strcpy(t[4].timing[0],"01:30 PM");
    strcpy(t[4].timing[1],"06:00 PM");
    strcpy(t[4].timing[2],"10:00 PM");
    
    
}

void begin(){
    //int destination;
    printf("1.CHENNAI\n2.BENGALORE\n3.HYDERABAD\n4.KOCHI\n5.VIZAG\n");
    DESTINATION:
    printf("ENTER DESTINATION:");
    scanf("%d",&destination);
    destination--;
    if(destination>=0 && destination<=4)
        choose_travels();
    else{
        printf("************* PLEASE ENTER CORRECT OPTION *************\n");
        goto DESTINATION;
    }
        
}

void choose_travels(){
    printf("\n1.MBT TRAVELS\n2.RKT TOURS AND TRAVELS\n3.VKV TRAVELS\n4.EXCEL TRAVELS\n5.RED EXPRESS\n");
    //int travels;
    TRAVELS:
    printf("CHOOOSE THE TRAVELS:");
    scanf("%d",&travels);
    travels--;
    if(travels>=0 && travels<=4){
    printf("\n");
    show_timings(travels);
    }
    else{
        printf("************* PLEASE ENTER CORRECT CHOICE *************\n");
        goto TRAVELS;
    }
        
}

void show_timings(int travels){
   // int timing;
    A:
    for(int i=0;i<3;i++){
        printf("%d. %s\n",i+1,t[travels].timing[i]);
    }
    TIMING:
    printf("CHOOSE TIMINGS (IF YOU WANT TO CHANGE TRAVELS ENTER 5):");
    scanf("%d",&timing);
    if((timing<=3 && timing>=1)||timing==5){
        if(timing==5)
            choose_travels();
        else{
            timing--;
            if(((s[destination].tickets[travels][timing][0])+(s[destination].tickets[travels][timing][1]))<=0){
                printf("********** SORRY NO SEATS AVAILABLE. **********\n********** PLEASE CHOOSE ANOTHER TIMING **********\n");
                goto A;
            }
            seats();
        }
    }
    else{
        printf("************* PLEASE CHOOSE CORRECT OPTION *************\n");
        goto TIMING;        
    }

}

void seats(){
    printf("\n------------------- SEAT AVAILABILITY -------------------\n");
    printf("TOTAL NO OF SEATS AVAILABLE : %d\n",(s[destination].tickets[travels][timing][0])+(s[destination].tickets[travels][timing][1]));
    printf("TOTAL NO OF LOWERBERTH SEATS : %d\n",(s[destination].tickets[travels][timing][0]));
    printf("TOTAL NO OF UPPERBERTH SEATS : %d\n\n",(s[destination].tickets[travels][timing][1]));
    
    show_seatavailability();

}

void show_seatavailability(){
    printf("LOWER BERTH\tUPPER BERTH\n\n");
    for(int row=0;row<6;row++){
        for(int col=0;col<6;col++){
            if(col==1 || col==4)
                printf("  ");
            if(col==3)
                printf("\t");
            if(s[destination].available_seats[travels][timing][row][col]==0)
                printf("-- ");
            else
                printf("%c%d ",65+row,col);
        }printf("\n");
    }
    printf("\n");
    printf("LOWER BERTH PRICE : %.2f\n",s[destination].lower_berth);
    printf("UPPER BERTH PRICE : %.2f\n",s[destination].upper_berth);
    booking();
}

void booking(){
    A:
    printf("ENTER NO OF LOWER BERTH SEATS :");
    int error=1;
    scanf("%d",&lowerberth_seat);
    printf("ENTER NO OF UPPERBERTH SEATS :");
    scanf("%d",&upperberth_seat);
    if(lowerberth_seat>s[destination].tickets[travels][timing][0]){
        printf("PLEASE ENTER THE NUMBER OF LOWERBERTH SEATS LESS THAN %d\n",(s[destination].tickets[travels][timing][0])+1);
        error=0;
    }
    if((upperberth_seat>s[0].tickets[travels][timing][1])){
        printf("PLEASE ENTER THE NUMBER OF UPPERBERTH SEATS LESS THAN %d\n",(s[destination].tickets[travels][timing][1])+1);
        error=0;
    }
    if(error){
        s[destination].tickets[travels][timing][0]=s[destination].tickets[travels][timing][0]-lowerberth_seat;
        s[destination].tickets[travels][timing][1]=s[destination].tickets[travels][timing][1]-upperberth_seat;
        int temp=1,column_no,row_no;
        char str[5],str1[2];
        POINT1:
        while(temp<=lowerberth_seat){
            printf("CHOOSE LOWERBERTH SEAT %d :",temp);
            scanf("%s",str);
            row_no=toupper(str[0]);
            str1[0]=str[1];
            str1[1]=str[2];
            column_no=atoi(str1);
            if(s[destination].available_seats[travels][timing][row_no-65][column_no]==1 && column_no<3){
                s[destination].available_seats[travels][timing][row_no-65][column_no]=0;
                strcpy(seat_no[seat_count],str);
                seat_count++;
            }
            else{
                printf("INVALID SEAT PLEASE CHOOSE AVAILABLE SEATS...");
                goto POINT1;
            }
            temp++;
        }
        temp=1;
        POINT2:
        while(temp<=upperberth_seat){
            printf("CHOOSE UPPERBERTH SEAT %d :",temp);
            scanf("%s",str);
            row_no=toupper(str[0]);
            str1[0]=str[1];
            str1[1]=str[2];
            column_no=atoi(str1);
            if(s[destination].available_seats[travels][timing][row_no-65][column_no]==1 && column_no>2){
                s[destination].available_seats[travels][timing][row_no-65][column_no]=0;
                strcpy(seat_no[seat_count],str);
                seat_count++;
            }
            else{
                printf("INVALID SEAT PLEASE CHOOSE AVAILABLE SEATS...");
                goto POINT2;
            }
            temp++;
        }
        printf("REGISTRATION SUCCESSFULL...\n");
        receipt();
    }
    else
        goto A;
    
}

int receipt(){
    int v=21;
    int choice;
    printf("\n===========================================================\n");
    printf("\tFROM : TRICHY\n");
    printf("\tTO   : %s\n",places[destination]);
    printf("\tTRAVELS : %s\n",agency[travels]);
    printf("\tTIME : %s\n",t[travels].timing[timing]);
    printf("\tSEATS NO : ");
    for(int i=0;i<seat_count;i++){
        printf("%s ",seat_no[i]);
    }printf("\n"); 
    seat_count=0;
    printf("\tLOWER BERTH SEATS : %d = %.2f\n",lowerberth_seat,s[destination].lower_berth * lowerberth_seat);
    printf("\tUPPER BERTH SEATS : %d = %.2f\n",upperberth_seat,s[destination].upper_berth * upperberth_seat);
    printf("\tTOTAL AMOUNT : %.2f\n",(s[destination].lower_berth * lowerberth_seat)+(s[destination].upper_berth * upperberth_seat));
    printf("\n===========================================================\n");

    printf("DO YOU WANT TO CONTINUE: YES(1) OR NO(0) : ");
    scanf("%d",&choice);
    if(choice)
        begin();
    else{
        printf("\n____________________________________________________________\n");
        printf("\n\tTHANK YOU...\n");
        printf("\tHAVE A WONDERFUL JOURNEY !!!\n");
        printf("____________________________________________________________\n");

        return 0;
    }

}

int main(){
    printf("======================================================\n");
    printf("\t\t     TICKET TRACK\n");
    printf("======================================================\n");
    database();
    begin();
}














