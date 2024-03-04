2
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <conio.h>
#define MAX_SIZE_USER_NAME 30
#define MAX_SIZE_PASSWORD  10
#define MAX_ROOMS 30
#define b 100
#define a 500
#define n1 15
#define V 12

// ANSI escape codes for text color
#define BLUE_TEXT    "\x1b[34m"
#define RESET_TEXT   "\x1b[0m"

void drawBlueASCIIArt() {
    printf(BLUE_TEXT);
    printf(" _____ _____ _   _______ _____ _____ _____  _   _ \n");
    printf("|_   _|  _  | | | | ___ \\_   _|  ___/  __ \\| | | |\n");
    printf("  | | | | | | | | | |_/ / | | | |__ | /  \\/| |_| |\n");
    printf("  | | | | | | | | |    /  | | |  __|| |    |  _  |\n");
    printf("  | | \\ \\_/ / |_| | |\\ \\  | | | |___| \\__/\\| | | |\n");
    printf("  \\_/  \\___/ \\___/\\_| \\_| \\_/ \\____/ \\____/\\_| |_/\n");
    printf(RESET_TEXT);
    printf("\n");
}




void drawBlueASCIIArt();

typedef struct Node
{
    char agency_name[30];
    char d_name[20];
    char source[20];
    char des[20];
    int d_no;
    char name[20];
    char address[20];
    int p_no;
    struct Node* next;
} Node;

Node *head1 = NULL;
struct place
{
    char place[50];
    int d;
    int id;
};

struct store
{
    char text[a];
};

typedef struct room_booking
{
    char name[20];
    int age;
    char gender[8];
    char phno[20];
    
    struct room_booking *next;
} node;

node *head=NULL;

/

int create_acc();
void booking_details();
void add_node(char [], char[], int, char [20]);

char placeName[50];
int src=0,i,e;
char pla[20];
char pos[10];
struct food
{
    char foodname[20];
    int famt;
    int qty;
    struct food *next2;
};

// };

// Function to display the food menu
void food_menu()
{
    printf("\n|==========================================================|");
    printf("\n|\t\t               **FOOD MENU**                      |");
    printf("\n|==========================================================|");
    printf("\n|1: PIZZA                             200                    |\n");
    printf("|2: SANDWICH                          50                     |\n");
    printf("|3: BURGER                            150                    |\n");
    printf("|4: DESSERT                           100                    |\n");
    printf("|5: IDLI                              50                     |\n");
    printf("|6: DOSA                              80                     |\n");
    printf("\n===========================================================|");
}

struct food *head32 = NULL;
int total_food_amt = 0;

// Function to add food to the order
void addfood(int food, int qty)
{
    int food_amt = 0;
    struct food* newptr = (struct food*)malloc(sizeof(struct food));

    if (food == 1)
    {
        strcpy(newptr->foodname, "PIZZA");
        newptr->famt = 200;
    }
    else if (food == 2)
    {
        strcpy(newptr->foodname, "SANDWICH");
        newptr->famt = 50;
    }
    else if (food == 3)
    {
        strcpy(newptr->foodname, "BURGER");
        newptr->famt = 150;
    }
    else if (food == 4)
    {
        strcpy(newptr->foodname, "DESSERT");
        newptr->famt = 100;
    }
    else if (food == 5)
    {
        strcpy(newptr->foodname, "IDLI");
        newptr->famt = 50;
    }
    else if (food == 6)
    {
        strcpy(newptr->foodname, "DOSA");
        newptr->famt = 80;
    }

    newptr->qty = qty;
    newptr->next2 = NULL;

    food_amt = newptr->famt * newptr->qty;
    total_food_amt += food_amt;

    if (head32 == NULL)
    {
        head32 = newptr;
    }
    else
    {
        struct food* ptr = head32;
        while (ptr->next2 != NULL)
        {
            ptr = ptr->next2;
        }
        ptr->next2 = newptr;
    }
}

// Function to place a food order
void food_order()
{
    int food;
    int qty;

    do
    {
        food_menu();
        printf("\nEnter the digit of the food item (1-6): ");
        printf("\nPLEASE ENTER 0 WHEN YOU WANT TO STOP ORDERING.");
        scanf("%d", &food);
        if (food != 0)
        {
            printf("\nEnter the quantity: ");
            scanf("%d", &qty);
            addfood(food, qty);
        }
    }
    while (food != 0);

    printf("\n\nFOOD ORDERED SUCCESSFULLY.");
    printf("\n\nIT WILL BE DELIVERED VERY SOON!");
    printf("\n\nTOTAL AMOUNT TO BE PAID DURING DELIVERY IS RS %d", total_food_amt);
}

// Function to display the food order
void food_display()
{
    FILE *fp;
    fp=fopen("food.txt","a");

    if (total_food_amt == 0)
    {
        printf("\nNO FOOD ORDERED, PLEASE ORDER FOOD FIRST.");
        fprintf(fp,"\nNO FOOD ORDERED, PLEASE ORDER FOOD FIRST.");

    }
    else
    {
        printf("\nTOTAL AMOUNT IS RS %d", total_food_amt);
        fprintf(fp,"\nTOTAL AMOUNT IS RS %d", total_food_amt);


        for (struct food* temp = head32; temp != NULL; temp = temp->next2)
        {
            printf("\nFOOD NAME       : %s", temp->foodname);
            fprintf(fp,"\nFOOD NAME       : %s", temp->foodname);
            printf("\nFOOD QUANTITY   : %d", temp->qty);
             fprintf(fp,"\nFOOD QUANTITY   : %d", temp->qty);
        }
    }
}

void create(char l[10],char m[20],int d)
{
    Node *newnode = (Node*)malloc(sizeof(Node));

    strcpy(newnode->agency_name,l);
    strcpy(newnode->d_name,m);
    newnode->d_no=d;

    printf("\nENTER THE DETAILS TO TRAVELL IN->->%s",newnode->agency_name);
    printf("\n ENTER THE NAME:->");
    scanf("\n");
    gets(newnode->name);
    printf("\n ENTER THE SOURCE:->");
    scanf("\n");
    gets(newnode->source);
    printf("\n ENTER THE DESTINATION:->");
    scanf("\n");
    gets(newnode->des);
    printf("\nENTER THE ADDRESS:->");
    scanf("\n");
    gets(newnode->address);
    printf("\nENTER THE PHONE NUMBER:->");
    scanf("%d", &newnode->p_no);

    if (head1 == NULL)
    {
        head1 = newnode;  // If list is empty, make newnode the head1
        newnode->next = NULL;
    }
    else
    {
        Node *temp1 = head1;
        while (temp1->next != NULL)
        {
            temp1 = temp1->next;  // Traverse to the last node
        }
        temp1->next = newnode;  // Add newnode at the end
        newnode->next = NULL;
    }
}


void display1()
{
    FILE *fp;
    fp=fopen("www.txt","a");
    Node *temp1 = head1;
    if (temp1 == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        while (temp1 != NULL)
        {
            printf("\n THE DETAILS ARE:->");
            fprintf(fp,"\n THE DETAILS ARE->");
            printf("\nAGENCY NAME:%s",temp1->agency_name);
            fprintf(fp,"\nAGENCY NAME:%s",temp1->agency_name);
            printf("\nDRIVER NAME:%s",temp1->d_name);
            fprintf(fp,"\nDRIVER NAME:%s",temp1->d_name);
            printf("\nDRIVERS NUMBER:%d",temp1->d_no);
            fprintf(fp,"\nDRIVERS NUMBER:%d",temp1->d_no);
            printf("\nCUSTOMER NAME:%s",temp1->name);
            fprintf(fp,"\nCUSTOMER NAME:%s",temp1->name);
            printf("\nSOURCE:%s",temp1->source);
            fprintf(fp,"\nSOURCE:%s",temp1->source);
            printf("\nDESTINATION:%s",temp1->des);
            fprintf(fp,"\nDESTINATION:%s",temp1->des);

            printf("\nCUSTOMER ADDRESS:%s",temp1->address);
            fprintf(fp,"\nCUSTOMER ADDRESS:%s",temp1->address);
            printf("\nCUSTOMER PHONE NUMBER:%d",temp1->p_no);
            fprintf(fp,"\nCUSTOMER PHONE NUMBER:%d",temp1->p_no);
            temp1 = temp1->next;
        }
        fclose(fp);
        printf("\n");
        return;
    }
}
void agency()
{
    int ch=0;
    printf("\n1.RAJU RIKSHA");
    printf("\n2.PAPPU HORSE SERVICE");
    printf("\n3.JAIHIND E_RIKSHA");
    printf("\n4.ROYAL HORSE SERVICES");
    printf("\n5.ROYAL MATHERAN HORSE");
    printf("\n6.AZAD HINDH eRIKSHA");
    printf("\n7.JAVED HANDPULLED RIKSHAS");
    printf("\n8.PULL RIKSHA SERVICES");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        create("RAJU_RIKSHA","MOHAN",7865475436);
        break;
    case 2:
        create("PAPPU HORSE SERVICE","ABDUL",6753429854);
        break;
    case 3:
        create("JAIHIND E_RIKSHA","RAJIV",7853464732);
        break;
    case 4:
        create("ROYAL HORSE SERVICES","JAIDEV",9876578976);
        break;
    case 5:
        create("ROYAL MATHERAN HORSE","RAGHAV",8745678634);
        break;
    case 6:
        create("AZAD HINDH eRIKSHA","SUNIL",6683454322);
        break;
    case 7:
        create("JAVED HANDPULLED RIKSHAS","SALIM",4565387899);
        break;
    case 8:
        create("PULL RIKSHA SERVICES","GAUTHAM",7685943212);
        break;

    }

}
// Function to check if username already exists
int isUsernameExists(const char *username)
{
    FILE *file = fopen("register.txt", "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error opening file\n");
        exit(1);
    }

    char existingUsername[MAX_SIZE_USER_NAME];
    while (fscanf(file, "%s", existingUsername) != EOF)
    {
        if (strcmp(username, existingUsername) == 0)
        {
            fclose(file);
            return 1; // Username exists
        }
    }

    fclose(file);
    return 0; // Username does not exist
}


// Function to create a new account
int create_acc()
{
    char username[MAX_SIZE_USER_NAME];
    char password[MAX_SIZE_PASSWORD];

    printf("\n\n\n\t\t\t\tUsername:");
    getchar(); // Clear input buffer
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = '\0'; // Remove newline character

    if (isUsernameExists(username))
    {
        printf("\n\tUsername already exists. Please choose a different username.\n");
        create_acc();
        return 0;
    }

    printf("\n\t\t\t\tPassword:");
    fgets(password, MAX_SIZE_PASSWORD, stdin);
    //getPassword(password, MAX_SIZE_PASSWORD);

    //getPassword(password, MAX_SIZE_PASSWORD);

    FILE *file = fopen("register.txt", "a");

    if (file == NULL)
    {
        fprintf(stderr, "\n\n\n\t\t\t\tError opening file\n");
        exit(1);
    }

    fprintf(file, "%s %s\n", username, password);
    fclose(file);

    printf("\n\t\t\t\tWelcome!");
    sleep(3);

    system("clear || cls");
    return 1;
}

void getPassword(char *password, int max_length)
{
    int i = 0;
    char ch;

    while (1)
    {
        ch = getch(); // Get a single character without displaying it
        if (ch == 13 || ch == 10)   // Enter key
        {
            password[i] = '\0';
            break;
        }
        else if (ch == 8 && i > 0)     // Backspace key
        {
            i--;
            printf("\b \b"); // Move the cursor back and erase the character
        }
        else if (i < max_length - 1)
        {
            password[i] = ch;
            i++;
            printf("*");
        }
    }
    printf("\n");
}

// Function to authenticate a user
int loginUser()
{
    char username[MAX_SIZE_USER_NAME];
    char password[MAX_SIZE_PASSWORD];

    printf("Enter your username: ");
    scanf("%s", username);


    if (!isUsernameExists(username))
    {
        printf("Username does not exist. Please register first.\n");
        return 0;
    }

    printf("Enter your password: ");
    //scanf("%s", password);
    getPassword(password, MAX_SIZE_PASSWORD);
    //fgets(password, MAX_SIZE_PASSWORD, stdin);

    FILE *file = fopen("register.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file for reading.\n");
        return 0;
    }

    char storedPassword[MAX_SIZE_USER_NAME + MAX_SIZE_PASSWORD];

    while (fscanf(file, "%s %s", username, storedPassword) != EOF)
    {
        if (strcmp(storedPassword, password) == 0)
        {
            fclose(file);
            printf("Login successful. Welcome! %s!\n", username);
            booking_details();
            printf("\nROOM BOOKED.");
            sleep(2);

            return 1;
        }
    }

    fclose(file);
    printf("Incorrect password. Please try again.\n");
    return 0;
}

int ppl,room=0;
char room_type[MAX_ROOMS][20];
int amount=0;

void booking_details()
{
    int age2;
    char nm[20],gen[8];
    char phone1[20],phone2[20],room_book[20];
    //long long int phone1,phone2;


    printf("Enter the number of rooms:");
    scanf("%d",&room);
    for(int i=1; i<=room; i++)
    {
        int amt=0;
        printf("\nEnter the type of room(AC/NON-AC)\t");
        printf("\nAC : RS 2000\tNON-AC : RS 1500\t");
        fflush(stdin);
        gets(room_book);
        //room_type[i]=room_book;
        strcpy(room_type[i], room_book);
        strlwr(room_book);
        if(strcmp(room_book,"ac")==0)
        {
            amt=2000;
        }
        else if(strcmp(room_book,"non-ac")==0)
        {
            amt=1500;
        }
        amount=amt+amount;
    }

    printf("Enter the number of persons:");
    scanf("%d",&ppl);

    for(int i=1; i<=ppl; i++)
    {
        printf("Enter the name of %d :",i);
        fflush(stdin);
        gets(nm);

        printf("Enter the gender of %d :",i);
        fflush(stdin);
        gets(gen);

        printf("Enter the age of %d :",i);
        fflush(stdin);
        scanf("%d",&age2);

        int count=0;

        int j=1;
        do
        {
            printf("Enter the phone number of :");
            fflush(stdin);
            gets(phone1);

            count = strlen(phone1);
            if(count>10 || count<10)
            {
                printf("\nInvalid phone number.Please re-enter!\n\n");
            }
            else
            {
                printf("\nDetails Saved.");
                printf("\n\t");
                // break;
            }


        }
        while(count!=10);

        add_node(nm,gen,age2,phone1);
    }
}


//Insert at end
void add_node(char nm[20],char gen[8],int age, char phone[20])
{
    node *newptr=NULL, *ptr;
    newptr=(node*)malloc(sizeof(node));
    strcpy(newptr->name,nm);
    strcpy(newptr->gender,gen);
    newptr->age=age;
    strcpy(newptr->phno,phone);
    //newptr->phno=phone;
    newptr->next=NULL;

    if(head==NULL)
    {
        head = newptr;
    }
    else
    {
        ptr=head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=newptr;
    }
}


void display(char room_type[MAX_ROOMS][20])
{
    FILE *fp;
    fp=fopen("store1.txt","a");
    int c;
    if(room==0)
    {
        printf("\nNO ROOMS BOOKED!");
    }

    else
    {
        for (c = 1; a <= room; c++)
            printf("\n\t\tROOM NUMBER %d : %s", a, room_type[c]);
        fprintf(fp,"\n\t\tROOM NUMBER %d : %s", a, room_type[c]);

        printf("\n\t\tTOTAL AMOUNT PAID : %d ",amount);
        fprintf(fp,"\n\t\tTOTAL AMOUNT PAID : %d ",amount);
        printf("\n\t\tROOM BOOKED BY:");
        fprintf(fp,"\n\t\tROOM BOOKED BY:");


        for (node *temp = head; temp != NULL; temp = temp->next)
        {
            printf("\n\t\tNAME     : %s", temp->name);
            fprintf(fp,"\n\t\tNAME     : %s", temp->name);
            printf("\n\t\tGENDER   : %s", temp->gender);
            fprintf(fp,"\n\t\tGENDER   : %s", temp->gender);
            printf("\n\t\tAGE      : %d", temp->age);
            fprintf(fp,"\n\t\tAGE      : %d", temp->age);
            printf("\n\t\tPHONE NO : %s", temp->phno);
            fprintf(fp,"\n\t\tPHONE NO : %s", temp->phno);
            printf("\n\n");
            fprintf(fp,"\n\n");
        }
    }
}


void delete_room()
{
    if (room == 0)
    {
        printf("\nNO ROOMS BOOKED!\n");
    }
    else
    {
        printf("\nEnter the room you want to delete: ");
        char del_room[20];
        scanf("%s", del_room);

        strlwr(del_room);
        if(strcmp(del_room,"ac")==0)
        {
            amount=amount-2000;
        }
        else if(strcmp(del_room,"non-ac")==0)
        {
            amount=amount-1500;
        }

        int i;
        for (i = 1; i <= room; i++)
        {
            if (strcmp(room_type[i], del_room) == 0)
            {
                break;  // Found the room to delete
            }
        }

        if (i > room)
        {
            printf("\nRoom not found!\n");
        }
        else
        {
            // Move rooms after the deleted one to fill the gap
            for (int j = i; j < room; j++)
            {
                strcpy(room_type[j], room_type[j + 1]);
            }
            room--;

            printf("\nRoom %s deleted successfully!\n", del_room);
        }
    }
}


struct place p[V]= {{"Neral Matheran Toy Train",0,0},
    {"Louisa Point",1,1},
    {"Sharlott lake",2,2},
    {"Monkey point",3,3},
    {"Shivaji's ladder",4,4},
    {"Manorama point",5,5},
    {"One tree hill point",6,6},
    {"Ambarnath Temple",7,7},
    {"Honeymoon Point",8,8},
    {"Dhodani Waterfalls",9,9},
    {"Paymaster Park",10,10},
    {"Khandala Point",11,11}
},temp;

int minDistance(int dist[], bool sptSet[])
{
    int min = INT_MAX;
    int min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)

            min = dist[v], min_index = v;
    return min_index;
}


void printSolution(int dist[],int q)
{
    int i,j;

    // Clearing Screen
    system("cls");

    // Calling heading() function
    drawBlueASCIIArt();

    for(i=0; i<V; i++)
    {
        p[i].d=dist[i];//moving all the distences from variable dist to structure variabl d to sort distence
    }

    printf("\nNEAREST PLACES FROM : %s \n",p[q].place);

    sort(p,p[V].d);


    for (int i=1; i<V; i++)
    {
        printf("\n[%s]->->->->{%d KM}\n",p[i].place,p[i].d);
        printf("\n");
    }

}
void sort(struct place p[V], int c[V])  // No need for return type and extra array argument
{
    int i, j, min;
    for (i = 0; i < V - 1; i++)    // Iterate up to n-2 to avoid out-of-bounds access
    {
        min = i;
        for (j = i + 1; j < V; j++)    // Inner loop should iterate up to n
        {
            if (p[j].d < p[min].d)
            {
                min = j;
            }
        }
        // Swap only if a smaller element was found
        if (min != i)
        {
            struct place temp = p[i];
            p[i] = p[min];
            p[min] = temp;
        }
    }
}


void dijkstra(int graph[V][V], int src)
{

    int q=src;
    int dist[V];
    bool sptSet[V];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

// Distance of source vertex from itself is always 0
    dist[src] = 0;

// Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++)
    {

// Pick the minimum distance vertex from the set of
// vertices not yet processed. u is always equal to
// src in the first iteration.
        int u = minDistance(dist, sptSet);
// Mark the picked vertex as processed
        sptSet[u] = true;
// Update dist value of the adjacent vertices of the
// picked vertex.
        for (int v = 0; v < V; v++)
// Update dist[v] only if is not in sptSet,
// there is an edge from u to v, and total
// weight of path from src to v through u is
// smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v]
                    && dist[u] != INT_MAX
                    && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];

    }

// print the constructed distance array
    printSolution(dist,q);
}


void range()
{
    int min,j;
    struct array
    {


        int num;
        char name[50];
    };

    struct array p[50]=
    {
        {2408, "The Byke Heritage Resort Matheran"},{2409,"Westend Hotel Matheran"},
        { 2283, "Sun N Shade Resort"},{1800, "Royal Hotel Matheran"},{5065,"Guru prasad cottage"},
        {1727, "Alexander Heritage And Rainforest Resort"},{3627,"Hotel Panorama"},
        {3512,"Horseland Hotel And Mountain"},{3309,"Adamo The Resort, Matheran"},
        {4680,"Lords Central Hotel"},{4440,"Gujarat Bhavan Hotel,Matheran"},{6100,"Usha Ascot"},
        {6174,"Radha Cottage Heritage Resort"},{6222,"Rangoli Retreat"},{5062,"Hotel Gulshan Heritage"},
    },temp;
    for (i = 0; i < V - 1; i++)
    {
        // Iterate up to n-2 to avoid out-of-bounds access
        min = i;
        for (j = i + 1; j < V; j++)
        {
            // Inner loop should iterate up to n
            if (p[j].num < p[min].num)
            {
                min = j;
            }
        }
        // Swap only if a smaller element was found
        if (min != i)
        {
            temp = p[i];
            p[i] = p[min];
            p[min] = temp;
        }
    }

    // Clearing Screen
    system("cls");

    // Calling heading() function
    drawBlueASCIIArt();

    printf("\nENTER THE RANGES OF HOTEL YOU ARE SEARCHING FOR:");
    int s,q;
    scanf("%d%d",&s,&q);
    printf("\n ALL THE HOTELS OF THE RANGE BETWEEN %d TO %d ARE:->",s,q);
    for(int i=0; i<n1; i++)
    {
        if(p[i].num >=s && p[i].num <=q)
        {
            printf("\n%s------->%d RS\n",p[i].name,p[i].num);

        }
    }
}

int entry(int graph[V][V],char pla[20])
{
    int src=0,i;
    int s=strlen(pla);
    for(i=0; i<s; i++)
    {
        if((strcmp(pla,p[i].place))==0)
        {
            src=i;
            break;
        }
    }

    dijkstra(graph,src);
    return 0;

}

//kmp pattern matching algoriyhm
void prefixSuffixArray(char* pat, int M, int* pps)
{
    int length = 0;
    pps[0] = 0;
    int i = 1;
    while (i < M)
    {
        if (pat[i] == pat[length])
        {
            length++;
            pps[i] = length;
            i++;
        }
        else
        {
            if (length != 0)
                length = pps[length - 1];
            else
            {
                pps[i] = 0;
                i++;
            }
        }
    }
}

void kmp(char* text, char* pattern)
{
    int M = strlen(pattern);
    int N = strlen(text);
    int pps[M];
    prefixSuffixArray(pattern, M, pps);
    int i = 0;
    int j = 0;
    while (i < N)
    {
        if (pattern[j] == text[i])
        {
            j++;
            i++;
        }
        if (j == M)
        {
            // printf("Found pattern at index %d \n", i - j);
            printf("%s\n", text);
            return;
            j = pps[j - 1];
        }
        else if (i < N && pattern[j] != text[i])
        {
            if (j != 0)
                j = pps[j - 1];
            else
                i = i + 1;
        }
    }
}


int file(char pos[10])
{
    FILE *fp;

    struct store stores[b];
    int store_count = 0;
    char line[a];

    fp=fopen("booking.txt", "r");

    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }

    while (fgets(line, a, fp) != NULL)
    {
        // Remove trailing newline if present
        line[strcspn(line, "\n")] = '\0';

        // Check for empty line (store separator)
        if (strlen(line) == 0)
        {
            continue;
        }

        strcpy(stores[store_count].text, line);
        store_count++;

    }

    fclose(fp);

    for (int i = 0; i < store_count; i++)
    {
        kmp(stores[i].text, pos);

    }
    return 0;
}


// void heading()
// {
//     printf("##############################################################");
//     printf("########################################################\n");
//     printf("\t\t\t\t***DIGITAL EVOLUTION OF MATHERAN***\n");
//     printf("\t\t\t***Vaccination Certificate "
//            "Is Necessary For Travel Purpose***\n\n");
//     printf("##############################################################");
//     printf("########################################################\n");
// }


void booking()
{
    int ch;
    do
    {
        printf("\n1.FIND ME A HOTEL");
        //  printf("\n2:CREATE ACCOUNT");
        printf("\n2:BOOK A ROOM");
        printf("\n3:DETAILS OF THE ROOM");
        printf("\n4:DELETE THE ROOM BOOKING");
        printf("\n5:FOOD ORDER ");
        printf("\n6:FOOD ORDER DISPLAY");
        printf("\n7.EXIT");
        printf("\nSELECT YOUR REQUIRENMENT:");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            range();
            break;

        case 2:
            system("cls");
            drawBlueASCIIArt();
            //loginUser();
            booking_details();
            break;
        case 3:
            system("cls");
            drawBlueASCIIArt();
            display(room_type);
            break;
        case 4:
            system("cls");
            drawBlueASCIIArt();
            // printf("\n\t\t\tVISIT AGAIN!!");
            //printf("\n\n\t\t\tTHANK YOU!!");
            //sleep(3);
            //exit(0);
            delete_room();
            break;

        case 5:
            food_order();
            break;

        case 6:
            food_display();
            break;


        case 7:
            system("cls");
            drawBlueASCIIArt();
            //exit(0);

            return;
            break;
        default:
            printf("\n enter the valid choice");

        }

    }
    while(ch!=7);
}
void travelling(int graph[V][V])
{
    char pla[20];
    char pos[10];
    int ch;

    do
    {
        printf("\n1.SEARCH FOR THE PLACES NEAR BY ME");
        printf("\n2.FIND WHAT IS SPECIAL IN THE PLACE");
        printf("\n3.BOOK A TRANSPORT HERE:");
        printf("\n4.SHOW ME THE BOOKING DETAILS:");
        printf("\n5.EXIT");
        printf("\nSELECT YOUR REQUIRENMENT:");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            system("cls");
            drawBlueASCIIArt();
            printf("\n WHERE YOUR ARE:->");
            scanf("\n");
            gets(pla);

            entry(graph,pla);
            break;

        case 2:
            system("cls");
            drawBlueASCIIArt();
            printf("\nENTER THE PLACE:->");
            scanf("\n");
            gets(pos);
            file(pos);
            break;
        case 3:
            system("cls");
            drawBlueASCIIArt();
            agency();
            break;
        case 4:
            system("cls");
            drawBlueASCIIArt();
            display1();
            break;

        case 5:
            system("cls");
            drawBlueASCIIArt();
            //printf("\n\t\t\tVISIT AGAIN!!");
            //printf("\n\n\t\t\tTHANK YOU!!");
            sleep(3);
            //exit(0);

            return;
            break;

        }
    }
    while(ch!=3);
}

void menu1(int graph[V][V])
{
    int ch;
    do
    {

        // printf("\nCREATE ACCOUNT");
        printf("\n1.CHECK FOR THE TRANSPORTATION AND TOURISM HERE");
        printf("\n2.CHECH FOR THE HOTELS HERE");
        printf("\n3.EXIT");
        printf("\nSELECT YOUR REQUIRENMENT:");
        scanf("%d",&ch);
        switch(ch)
        {

        case 1:
            system("cls");
            drawBlueASCIIArt();
            // loginUser();
            travelling(graph);
            break;

        case 2:
            system("cls");
            drawBlueASCIIArt();
            booking();
            break;

        case 3:
            system("cls");
            drawBlueASCIIArt();
            printf("\n\t\t\t\t\t\tVISIT AGAIN!!");
            printf("\n\n\t\t\t\t\tTHANK YOU!!");
            sleep(3);
            exit(0);
            break;
        default:
            printf("\n ENTER THE VALID CHOICE!\nPLEASE RE-ENTER");
        }
    }
    while(ch!=3);
}


// char placeName[50];
//     int src=0,i,e;
//     char pla[20];
//     char pos[10];

// driver's code
int main()
{

    drawBlueASCIIArt();

    int graph[V][V] = {  {0,9999,9999,9999,9999,9999,9999,9999,4,64,9999,9999},
        {9999,0,950,9999,9999,9999,9999,9999,50,9999,9999,9999},
        {9999,950,0,9999,9999,9999,9999,41,950,9999,9999,2},
        {9999,9999,9999,0,9999,4,9999,9999,2,66,9999,9999},
        {9999,9999,20,9999,0,9999,2,9999,9999,9999,9999,2},
        {9999,9999,9999,4,9999,0,9999,9999,9999,61,9999,9999},
        {9999,9999,9999,9999,2,9999,0,9999,9999,9999,9999,3},
        {9999,9999,41,9999,9999,9999,9999,0,9999,9999,9999,40},
        {4,50,950,2,9999,9999,9999,9999,0,9999,1,9999},
        {64,9999,9999,66,9999,61,9999,9999,9999,0,65,9999},
        {9999,9999,9999,9999,9999,9999,9999,9999,1,65,0,2},
        {9999,9999,2,9999,2,9999,3,40,9999,9999,9999,0}
    };

    printf("\n");

    int opt;
    int ch1,ch2;
    printf("\n1:CREATE ACCOUNT\t 2:LOGIN ACCOUNT\n");
    printf("\nEnter your choice:");
    fflush(stdin);
    scanf("%d",&opt);
    // printf("CREATE A ACCOUNT HERE");
    // create_acc();
    if(opt==1)
    {
        ch1=create_acc();
    }
    else if(opt==2)
        ch2=create_acc();

    if(ch1==1 || ch2==1)
    {
        menu1(graph);
    }


    else
    {
        printf("\nENTER YOUR DETAILS TO CREATE A NEW ACCOUNT");
        create_acc();
        menu1(graph);
    }


    // else if (opt<1 || opt>2){
    //     printf("\nInvalid no.");
    // }

    return 0;
}


