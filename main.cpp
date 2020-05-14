/******************************
* 
*   Created By- Ayush Sharma
*
*******************************/

#include<iostream>
#include<string>
#include<stdlib.h>
#include<conio.h>
#include<fstream>


using namespace std;

int score=0; //Score of the user

struct Question
{    
    string question, ans1, ans2, ans3, ans4;
    char correct_ans;
};


void Interface()
{
	cout<<"\n\n\t\t\t"
	    <<R"(
                   _____              ____  _    _ _____ ______
                  / ____|_     _     / __ \| |  | |_   _|___  /
                 | |   _| |_ _| |_  | |  | | |  | | | |    / / 
                 | |  |_   _|_   _| | |  | | |  | | | |   / /  
                 | |____|_|   |_|   | |__| | |__| |_| |_ / /__ 
                  \_____|            \___\_\\____/|_____/_____|
          
            )";

    cout<<"\n\n\t\t\tWelcome to the C++ Quiz!"; 
    cout<<"\n\n\t\t\tEnter your Name : ";

    string p_name;
    cin>>p_name; 

    system("cls");

    cout<<"\n\nHello "<<p_name<<","
        <<"\n\nYou will be prompted with the questions having four options."
        <<"\n\nFor each correct answer you will get +4 points."
        <<"\nFor each wrong answer you will get 0 points."
        <<"\n\nDo you wish to start the quiz (Y/N) : ";

        char respond;    // Respond By the user to start or exit the quiz

        cin>>respond;


        if(respond=='y'||respond=='Y') {
        	cout<<"\nPress Enter to start Quiz.";
            getch();

            system("cls");
        }

        else {
          cout<<"\n\nGOOD BYE! Press enter to exit...";
          getch();
          exit(0);
        }
          

}


int main()
{

	Question obj2; //Object of struct Question

	fstream fin("questions.csv",ios::in);

	

	Interface();
     
    string line; // To read line from .csv file 
	
	if(!fin)
		cerr<<"\nError Opening file containing Questions.";
	else
	{
		while(getline(fin,line,'\n'))
		{
			
			getline(fin,obj2.question,',');

			  cout<<"\n\nQ. "<<obj2.question<<"\n\n";

			getline(fin,obj2.ans1,',');

			  cout<<"A. "<<obj2.ans1<<'\n';

			getline(fin,obj2.ans2,',');

			  cout<<"B. "<<obj2.ans2<<'\n';

			getline(fin,obj2.ans3,',');

			  cout<<"C. "<<obj2.ans3<<'\n';

 			getline(fin,obj2.ans4,',');

 			  cout<<"D. "<<obj2.ans4<<'\n';

			fin>>obj2.correct_ans;

			
			char choice;  //Choice Variable for taking answer from the user
             cout<<"\n\nEnter your answer (a,b,c,d) : ";
	         cin>>choice;
	           

	         if(choice==obj2.correct_ans)
	         {
	         	cout<<"\n\nCORRECT!";
	         	score += 4;
	         	cout<<"\nPress Enter to continue...";
	         	getch();
	         }
	         else {
	         	std::cout<<"\n\nWrong Answer."
	                     <<"\nThe correct answer is : "<<obj2.correct_ans
	                     <<"\nPress Enter to continue...";
	                     getch();
	         } 

	         system("cls");           
		}

	}

	

    if(score > 6)                    // Change your Passing score Accordingly
	cout<<"\n\n\t\t\t"<<R"(

        __     ______  _    _   _____         _____ _____ ______ _____  
        \ \   / / __ \| |  | | |  __ \ /\    / ____/ ____|  ____|  __ \ 
         \ \_/ / |  | | |  | | | |__) /  \  | (___| (___ | |__  | |  | |
          \   /| |  | | |  | | |  ___/ /\ \  \___ \\___ \|  __| | |  | |
           | | | |__| | |__| | | |  / ____ \ ____) |___) | |____| |__| |
           |_|  \____/ \____/  |_| /_/    \_\_____/_____/|______|_____/ 
                                                                 

                          )";
    else
      cout<<"\nYou Failed !";

      getch();
      return 0;                      
      
}