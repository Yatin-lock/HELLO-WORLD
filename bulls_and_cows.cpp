#include<bits/stdc++.h>
using namespace std;
class parsing { 
               
	// Private section 
	public: vector<int> arr;   
	        set<int> s;
	        int number,track;
	 
	  void parse()
	  { 
	    while(number)
	     { arr.push_back(number%10);
	       s.insert(number%10);
	       number/=10;
	       track++;
		 }
		 if(track!=4)
		 { throw invalid_argument("enter a 4 digit number");
		 }
	  } // modifier function.
};
class calc : public parsing { int bulls,cows;
	public:
		calc(int number)
		{this->number=number;
		 track=0;    
		 bulls=0;cows=0;
		}
	 int CowsAndBulls(calc player)
	 {
	 	for(int i=0;i<4;i++)
	 	 { if(player.arr[i]==arr[i])
	 	  { bulls++;
		   }
		  else if(s.find(player.arr[i])!=s.end())
		  { cows++;
		  }}
		  cout<<"\x1b[1A"<<"\t\t  | "<<bulls<<"B"<<cows<<"C\n";
		 return bulls;	
	 }
		

};
// complete
int main()
{ cout<<"\t\t\tWELCOME TO COWS AND BULLS GAME ITS A TWO PLAYER GAME\n\t\t\t\t"; 
  system("pause");
  label :
  system("cls");
  cout<<"Enter a 4 digit number for player 1\n";
  int np1;
  cin>>np1;
  calc p(np1);
  try{
  p.parse();}
  catch(invalid_argument s)
  { cout<<endl<<s.what();
   for(long wait=0;wait<200000000;wait++);
    goto label;
  }
system("cls");
cout<<"Guesses(max : 20) | cows and bulls\n";
string line(34,'-');
cout<<line<<endl;
int guesses=20;
while(guesses)
{ int guess;
  cin>>guess;
  calc p1(guess);
  p1.parse();
 int bulls= p1.CowsAndBulls(p);
 
  if(bulls==4)
  { system("cls"); 
   
   cout<<"correct guess!"<<"Your total score : "<<guesses<<endl;
   system("pause");
   break;
  }
	guesses--;
}

if(guesses==0)
{  system("cls");
   
   cout<<"oops no correct match Your total score : "<<guesses<<endl;
  system("pause");
}
 return 0;
}
