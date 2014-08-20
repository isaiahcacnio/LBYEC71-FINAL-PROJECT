//Final Project by IJ Cacnio and Abram Veloria
//libraries
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

//PROTOTYPE DECLARATIONS
    void setcolor(unsigned short int color,unsigned short int bg);
    void gotoxy( int x, int y );
    void border();
    void bordword();
    void design();
    void quitMenu();
    void helpMenu();
    void trackExpenseMenu();
    int checkExpenseArray();
	void mainMenu();
	void addExpenseMenu();
	void checkcategory();
	void checkdate();
	void freshNext();
	void historyStatisticsMenu();
	void editExpenseMenu();
	int main();
    
//typedefs - string arrays
	typedef char string15[16];
	typedef char string30[31];
	
//structure
    struct expense
    {
    int pk;
    int month;
	int day;
	int year;
	string15 category;
	float expense;
    };

// print colors in text - NET BASED
	void setcolor(unsigned short int color,unsigned short int bg)
	{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),((bg*16)+(color)));
	}

//coordinates - NET BASED 
	void gotoxy(int x,int y)
	{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = {x,y} ;
	SetConsoleCursorPosition( hStdout, position ) ;
	}
    
//border creation + clearscreen + MenuNaming
	void bordword(string30 word)
	{
	int start = 70-strlen(word)+2;
	int ctr = strlen(word)+2;
	int x;
	setcolor(10,0);
	gotoxy(start,21);
	printf("%c",201);
	for(x=1;x<=ctr;x++)
		printf("%c",205);
	printf("%c", 187);
	gotoxy(start,22);
	printf("%c",185);
	printf(" %s ",word);
	printf("%c",204);
	gotoxy(start,23);    
	printf("%c",200);
	for(x=1;x<=ctr;x++)
		printf("%c",205);
	printf("%c", 188);
	printf("\n");
	}    
	void border()
	{
	system("cls");
	int x,y; 
	gotoxy(2,1);
	//top
	setcolor(10,0);
	printf("%c",201);
	for(x=1;x<=74;x++)
		printf("%c",205);
	printf("%c", 187);
	printf("\n");
	//side
	for(y=1;y<=20;y++)
		{
		printf("  %c",186);
		for(x=3;x<=76;x++)
			printf(" ");
		printf("%c",186);
		printf("\n");
		}
	//bottom
	printf("  %c",200);
	for(x=1;x<=74;x++)
		printf("%c",205);
	printf("%c", 188);
	printf("\n");
	}    

//ascii art generated through net
	void design(int desChoice)
	{
	setcolor(12,0);
	
		switch(desChoice)
		{
		case 1: {
				gotoxy(23,2); printf("  ____ ___  ________   ____   ____   ______ ____    ");
				gotoxy(23,3); printf("_/ __ \\\\  \\/  \\____ \\_/ __ \\ /    \\ /  ____/ __ \\   ");
				gotoxy(23,4); printf("\\  ___/ >    <|  |_> \\  ___/|   |  \\\\___ \\\\  ___/   ");
				gotoxy(23,5); printf(" \\___  /__/\\_ |   __/ \\___  |___|  /____  >\\___  >  ");
				gotoxy(23,6); printf("   __\\/      \\|__|        \\/ __  \\/__   \\/     \\/   ");
				gotoxy(23,7); printf(" _/  |_____________    ____ |  | _|__| ____   ____  ");
				gotoxy(23,8); printf(" \\   __\\_  __ \\__  \\ _/ ___\\|  |/ |  |/    \\ / ___\\ ");
				gotoxy(23,9); printf("  |  |  |  | \\// __ \\\\  \\___|    <|  |   |  / /_/  >");
				gotoxy(23,10); printf("  |__|  |__|  (____  /\\___  |__|_ |__|___|  \\___  / ");
				gotoxy(23,11); printf("                   \\/     \\/ __  \\/       \\/_____/  ");
				gotoxy(23,12); printf("        _________.__. ______/  |_  ____   _____     ");
				gotoxy(23,13); printf("       /  ___<   |  |/  ___\\   ___/ __ \\ /     \\    ");
				gotoxy(23,14); printf("       \\___ \\ \\___  |\\___ \\ |  | \\  ___/|  Y Y  \\   ");
				gotoxy(23,15); printf("      /____  >/ ____/____  >|__|  \\___  |__|_|  /   ");
				gotoxy(23,16); printf("           \\/ \\/         \\/           \\/      \\/    ");
				}break;
		case 2: {
				}break;
		}
	}

    void mainMenu(struct expense *expense)
    {
	border();
	bordword("Main Menu");
	design(1);
	setcolor(10,0);
	
    char choicemenu;
	string15 dummy;
	
	gotoxy(7,13); printf("[A] Track Expense");
	gotoxy(7,15); printf("[B] Help");
	gotoxy(7,17); printf("[C] Quit");
	gotoxy(7,19); printf("Choose an Option: ");
	scanf("%c", &choicemenu);
	gets(dummy);

	switch(choicemenu)
		{
		case 'a':
		case 'A': trackExpenseMenu(expense); break;
		case 'b':
		case 'B': helpMenu(expense); break;
		case 'c':
		case 'C': quitMenu(expense); break;
		case 'x':
		case 'X': mainMenu(expense); break;
		default: gotoxy(57,17); printf("Invalid Choice.");
				 gotoxy(44,19); system("Pause");
	 			  mainMenu(expense); break;
		}	
    }
    
    void trackExpenseMenu(struct expense *expense)
    {
    border();
	bordword("Tracking Expense Menu");
    char choicemenu;
	string15 dummy;
	
	gotoxy(7,11); printf("[A] Add New Expense \n");
	gotoxy(7,13); printf("[B] Edit Expense \n");
	gotoxy(7,15); printf("[C] History & Statistics \n");
	gotoxy(7,17); printf("[D] Go Back One Step. \n");
	gotoxy(7,19); printf("Choose an Option: ");
	scanf("%c", &choicemenu);
	gets(dummy);

	switch(choicemenu)
		{
		case 'a':
		case 'A': addExpenseMenu(expense); break;
		case 'b':
		case 'B': editExpenseMenu(expense); break; 
		case 'c':
		case 'C': historyStatisticsMenu(expense); break;
		case 'd':
		case 'D': mainMenu(expense); break;
		case 'x':
		case 'X': mainMenu(expense); break;
		default: gotoxy(57,17); printf("Invalid Choice.");
				 gotoxy(44,19); system("Pause");
	 			  mainMenu(expense); break;
		}
	}

	int checkExpenseArray(struct expense *expense)
	{
	int expenseFlag = 0;
	
	while((expense+expenseFlag)->day != 0)
		expenseFlag++;
				
	return expenseFlag;
	}

	void addExpenseMenu(struct expense *expense)
	{
	border();
	bordword("Add Expense");
	
    int date, expenseFlag;
	float money;
	string15 category, dummy;
	char choiceCat;
	
	expenseFlag = checkExpenseArray(expense);

	gotoxy(7,11); printf("Expense: ");
	scanf("%f", &money);
	gets(dummy);
	
	//money checker, if true -> goes to categoryChecker, else repeat
    	if(money>0)
        		{
				(expense+expenseFlag)->expense = money;
      			checkcategory(expense, expenseFlag);
				}
    	else
        		{
        		gotoxy(40,18); printf("Invalid Expense Input.");
        		gotoxy(40,19);system("Pause");
        		addExpenseMenu(expense);
        		}
	}
	
	void checkcategory(struct expense *expense, int expenseFlag)
	{
		char choiceCat;
		string15 dummy;
		border();
		bordword("Add Expense");
	
		gotoxy(35,7); printf("A. Clothes");
		gotoxy(35,9); printf("B. Food");	
		gotoxy(35,11); printf("C. Entertainment");
		gotoxy(35,13); printf("D. Fuel");
		gotoxy(35,15); printf("E. General");	
		gotoxy(35,17); printf("F. Gifts");
		gotoxy(55,7); printf("G. Holidays");
		gotoxy(55,9); printf("H. Kids");	
		gotoxy(55,11); printf("I. Shopping");
		gotoxy(55,13); printf("J. Sports");
		gotoxy(55,15); printf("K. Travel");	
			
		gotoxy(7,11);printf("Expense: %.2f", (expense+expenseFlag)->expense);
		gotoxy(7,13);printf("Category: "); 
		scanf("%c", &choiceCat);
		gets(dummy);
	
	//category choice checker, if true -> copies categories to structure array, else(default) repeat
		switch(choiceCat)
			{
			case 'a':
			case 'A': strcpy((expense+expenseFlag)->category, "Clothes"); break;
			case 'b':
			case 'B': strcpy((expense+expenseFlag)->category, "Food"); break;
			case 'c':
			case 'C': strcpy((expense+expenseFlag)->category, "Entertainment");break;
			case 'd':
			case 'D': strcpy((expense+expenseFlag)->category, "Fuel"); break;
			case 'e':
			case 'E': strcpy((expense+expenseFlag)->category, "General"); break;
			case 'f':
			case 'F': strcpy((expense+expenseFlag)->category, "Gifts"); break;
			case 'g':
			case 'G': strcpy((expense+expenseFlag)->category, "Holidays"); break;
			case 'h':
			case 'H': strcpy((expense+expenseFlag)->category, "Kids"); break;
			case 'i':
			case 'I': strcpy((expense+expenseFlag)->category, "Shopping"); break;
			case 'j':
			case 'J': strcpy((expense+expenseFlag)->category, "Sports"); break;
			case 'k':
			case 'K': strcpy((expense+expenseFlag)->category, "Travel"); break;
			default:  gotoxy(40,18); printf("Invalid Category");
					  gotoxy(40,19);system("Pause"); 
					  checkcategory(expense, expenseFlag); break;
			}
		checkdate(expense, expenseFlag);
	}

	void checkdate(struct expense *expense, int expenseFlag)
	{
    	border();
   		bordword("Add Expense");
		int date;
		gotoxy(7,11);printf("Expense: %.2f", (expense+expenseFlag)->expense);
		gotoxy(7,13);printf("Category: %s", (expense+expenseFlag)->category); 
  		gotoxy(7,15); printf("Input Date: ");
  		gotoxy(7,16); printf("Format: MMDDYYYY");
 		gotoxy(20,15); scanf("%d",&date);
		(expense+expenseFlag)->year = date%10000;
		date/=10000;
		(expense+expenseFlag)->day = date%100;
		date/=100;
		(expense+expenseFlag)->month = date;
		//date checker having year 2011 as the lowest year possible
		//leap year
	    	if((expense+expenseFlag)->year % 4 == 0 && (expense+expenseFlag)->year >=2011)
		  	{ 
				if((expense+expenseFlag)->month >= 1 && (expense+expenseFlag)->month <=12)
			 	{ 
			 	switch((expense+expenseFlag)->month)
					{
					case 1 :
					case 3 :
					case 5 :
					case 7 :
					case 8 : 
					case 10:
					case 12: if((expense+expenseFlag)->day >=1 && (expense+expenseFlag)->day <=31)
								{ 
								freshNext(expense, expenseFlag);//going to next
								}
							else
								{
								gotoxy(40,18); printf("Please Enter Valid Date. ");
								gotoxy(40,19); system("pause");
								checkdate(expense, expenseFlag);
								}
								break;
					case 4:
					case 6:
					case 9:
					case 11: if((expense+expenseFlag)->day >=1 && (expense+expenseFlag)->day <=30)
								{ 
								freshNext(expense, expenseFlag);//going to next
								}
							else
								{
								gotoxy(40,18); printf("Please Enter Valid Date. ");
								gotoxy(40,19); system("pause");
						    	checkdate(expense, expenseFlag);
								}
								break;
					case 2:  if((expense+expenseFlag)->day >=1 && (expense+expenseFlag)->day <=29)
								{ 
								freshNext(expense, expenseFlag);//going to next
								}
							else
								{
								gotoxy(40,18); printf("Please Enter Valid Date. ");
								gotoxy(40,19); system("pause");
								checkdate(expense, expenseFlag);
								}
							break;
					}
				}
				else
				{ 
				gotoxy(40,18); printf("Please Enter Valid Date. ");
				gotoxy(40,19); system("pause");
				checkdate(expense, expenseFlag);
				}
			}
  //not leap year
			else 
			if((expense+expenseFlag)->year % 4 != 0 && (expense+expenseFlag)->year >=2011)
			{ 
				if((expense+expenseFlag)->month >= 1 && (expense+expenseFlag)->month <=12)
				{ 
					switch((expense+expenseFlag)->month)
					{
					case 1:
					case 3:
					case 5:
					case 7:
					case 8:
					case 10:
					case 12: if((expense+expenseFlag)->day >=1 && (expense+expenseFlag)->day <=31)
								{ 
								freshNext(expense, expenseFlag);//going to next
								}
							else
								{ 
								gotoxy(40,18); printf("Please Enter Valid Date. ");
								gotoxy(40,19); system("pause");
								checkdate(expense, expenseFlag);
								}
							break;
					case 4:
					case 6:
					case 9:
					case 11: if((expense+expenseFlag)->day >=1 && (expense+expenseFlag)->day <=30)
								{ 
								freshNext(expense, expenseFlag);//going to next
								}
							else
								{
						        gotoxy(40,18); printf("Please Enter Valid Date. ");
								gotoxy(40,19); system("pause");
								checkdate(expense, expenseFlag);
								}
								break;
					case 2: if((expense+expenseFlag)->day >=1 && (expense+expenseFlag)->day <=28)
								{ 
								freshNext(expense, expenseFlag);//going to next
								}
							else
							{ 
								gotoxy(40,18); printf("Please Enter Valid Date. ");
								gotoxy(40,19); system("pause");
								checkdate(expense, expenseFlag);
							}
							break;
        			 }
				}
			else
				{ 
				gotoxy(40,18); printf("Please Enter Valid Date. ");
				gotoxy(40,19); system("pause");
				checkdate(expense, expenseFlag);
				}
			}
		else
			{ 
			gotoxy(40,18); printf("Please Enter Valid Date. ");
			gotoxy(40,19); system("pause");
			checkdate(expense, expenseFlag);
			}
        }


	void freshNext(struct expense *expense, int expenseFlag)
	{
	string30 dummy;
	
	(expense+expenseFlag+1)->month = 0;
	(expense+expenseFlag+1)->day = 0;
	(expense+expenseFlag+1)->year = 0;
	(expense+expenseFlag+1)->expense = 0;
	(expense+expenseFlag+1)->category[0] = 0;
	
	gotoxy(10,18); printf("Expense Added.");
	gotoxy(10,19); system("PAUSE");
	gets(dummy);
	
	mainMenu(expense);
	}
	
	void editExpenseMenu(struct expense *expense)
	{
		border();
		bordword("Edit Expense Menu");

		gotoxy(10,11); system("PAUSE");	
	}

	void historyStatisticsMenu(struct expense *expense)
	{
		
		int Flag1 = 0, Flag2 = 1, Flag3 = 2, Flag4 = 3, Flag5 = 4, Flag6 = 5, Flag7 = 6, Flag8 = 7, Flag9 = 8;
		char choice;
		float total = 0;
		int i=0;
		string30 dummy;
	do{
						
		border();
		bordword("History & Statistics Menu");
		gotoxy(7,3); printf("%d    Date: %d/%d/%d    Expense: %.2f    %s", (expense+Flag1)->pk, (expense+Flag1)->month, (expense+Flag1)->day, (expense+Flag1)->year, (expense+Flag1)->expense, (expense+Flag1)->category);
		gotoxy(7,5); printf("%d    Date: %d/%d/%d    Expense: %.2f    %s", (expense+Flag2)->pk, (expense+Flag2)->month, (expense+Flag2)->day, (expense+Flag2)->year, (expense+Flag2)->expense, (expense+Flag2)->category);
		gotoxy(7,7); printf("%d    Date: %d/%d/%d    Expense: %.2f    %s", (expense+Flag3)->pk, (expense+Flag3)->month, (expense+Flag3)->day, (expense+Flag3)->year, (expense+Flag3)->expense, (expense+Flag3)->category);
		gotoxy(7,9); printf("%d    Date: %d/%d/%d    Expense: %.2f    %s", (expense+Flag4)->pk, (expense+Flag4)->month, (expense+Flag4)->day, (expense+Flag4)->year, (expense+Flag4)->expense, (expense+Flag4)->category);
		gotoxy(7,11); printf("%d    Date: %d/%d/%d    Expense: %.2f    %s", (expense+Flag5)->pk, (expense+Flag5)->month, (expense+Flag5)->day, (expense+Flag5)->year, (expense+Flag5)->expense, (expense+Flag5)->category);
		gotoxy(7,13); printf("%d    Date: %d/%d/%d    Expense: %.2f    %s", (expense+Flag6)->pk, (expense+Flag6)->month, (expense+Flag6)->day, (expense+Flag6)->year, (expense+Flag6)->expense, (expense+Flag6)->category);
		gotoxy(7,15); printf("%d    Date: %d/%d/%d    Expense: %.2f    %s", (expense+Flag7)->pk, (expense+Flag7)->month, (expense+Flag7)->day, (expense+Flag7)->year, (expense+Flag7)->expense, (expense+Flag7)->category);
		gotoxy(7,17); printf("%d    Date: %d/%d/%d    Expense: %.2f    %s", (expense+Flag8)->pk, (expense+Flag8)->month, (expense+Flag8)->day, (expense+Flag8)->year, (expense+Flag8)->expense, (expense+Flag8)->category);
		gotoxy(7,19); printf("%d    Date: %d/%d/%d    Expense: %.2f    %s", (expense+Flag9)->pk, (expense+Flag9)->month, (expense+Flag9)->day, (expense+Flag9)->year, (expense+Flag9)->expense, (expense+Flag9)->category);
		
		for(i = 0; i < 15; i++){
			total += (expense+i)->expense;
		}
		
		gotoxy(24,22); printf("Total: %.2f", total); 
		
		
		gotoxy(43,20); printf("[N]ext | [P]revious | [E]xit : ");
		scanf("%c",&choice);
		gets(dummy);
		
		
		switch(choice)
		{
		case 'n':
		case 'N': if(Flag9 == 998)
					{printf("Invalid Catalogue");
					 system("PAUSE");
					 historyStatisticsMenu(expense);
					}
				  else 
				  	{Flag1+=9;
				  	 Flag2+=9;
				  	 Flag3+=9;
				  	 Flag4+=9;
				  	 Flag5+=9;
				  	 Flag6+=9;
				  	 Flag7+=9;
				  	 Flag8+=9;
				  	 Flag9+=9;			  	 
				  	}
					break;
		case 'p':
		case 'P': if(Flag1 == 0)
					{printf("Invalid Catalogue");
					 system("PAUSE");
					 historyStatisticsMenu(expense);
					}
				  else 
				  	{Flag1-=9;
				  	 Flag2-=9;
				  	 Flag3-=9;
				  	 Flag4-=9;
				  	 Flag5-=9;
				  	 Flag6-=9;
				  	 Flag7-=9;
				  	 Flag8-=9;
				  	 Flag9-=9;
					  }
					break;
		case 'e':
		case 'E': trackExpenseMenu(expense); break;
		case 'x':
		case 'X': mainMenu(expense); break;
		default: {gotoxy(30,21); printf("Invalid Input.");
				  gotoxy(28,22);system("Pause"); 
				  historyStatisticsMenu(expense);
					} break;
		}
	}while(Flag1 != 999);
	}
	
    void helpMenu(struct expense *expense)
    {
    	border();
    	bordword("Help Menu");
		gotoxy(31,9); 
        printf("A program made by");
        gotoxy(28,11);
        printf("Isaiah John P. Cacnio");
        gotoxy(33,13);
        printf("Abram Veloria");
        gotoxy(25,15); 
        system("PAUSE");
    }
    
    void quitMenu(struct expense *expense)
	{
	border();
	bordword("Exit Menu");

	char input;
	string15 dummy;
	do 
		{
		setcolor(9,0);
		gotoxy(27,10); 
		printf("Are You SURE!?<Y/N>: ");
		scanf("%c", &input);
		if(input=='Y'||input=='y')
    			{
    			gotoxy(16,10); 
				printf("Thank You For Using the Expense Tracking System!");
    			free(expense);
    			gotoxy(24,15); 
				system("PAUSE"); 
				exit(1);
    			}
		else if(input=='N'||input=='n')
        		{
        		gets(dummy);
        		mainMenu(expense);
        		}
		}     
	while (TRUE); 
	}
    
    
    main()
    {
	struct expense *ptr;
    struct expense expense[1000];
    int ctr = 0;
    for(ctr=0;ctr<1000;ctr++)
    {
   	(expense+ctr)->pk = ctr;
    (expense+ctr)->month = 0;
	(expense+ctr)->day = 0;
	(expense+ctr)->year = 0;
	(expense+ctr)->expense = 0;
	(expense+ctr)->category[0] = 0;
	}
    
	ptr = &expense;
/*	
	expense->month = 0;
	expense->day = 0;
	expense->year = 0;
	expense->expense = 0;
	expense->category[0] = 0;
*/
		
	do
		{
		mainMenu(ptr);
		}
    	while(TRUE);
    }
