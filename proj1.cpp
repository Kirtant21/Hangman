
/*
** Title: K238Project1.cpp
** Author: Kirtan Thakkar
** Date: 2/16/2021
** Course/Section: CMSC 202 section 10 (SP21)
*/

#include <iostream>
#include <fstream>
#include <string>
//#include <cstring>
using namespace std;

// Project prototypes *****



 string randWord (string arr[], int size); // Array function
 void display (string str); // sets up the output
 void missedLetters (char INPUT[], int count); // makes a list of failed guesses and prints the list as game goes on.
 bool anyAttemptLeft (int failedAttempts); // checks for the attempts and tell weather the game can be played or not.
 bool inputCheck(char Input); // checks if the Input is a valid charecter or not.
 bool Declaration (bool win); // shows the results and asks the user if they want to play the game again or not.    
 bool checkWinning (char letters[], string correctWord); // checks if the user won or not.

// Main function *****

 int main() {

   string wordCheck, chosenWord, words[10000];
   int count;
   bool play;
   char Decision;


   
   
   do{

     cout << "\n Welcome to UMBC word guess \n" << endl;
     
   count = 0;
     
   ifstream myfile ("words.txt");
     
   if (myfile.is_open())
     {
      
       while(myfile >>words[count] )
	 {
	 
	   count++;

	   
	 }

       cout << " Your file was imported!\n" << endl;

       cout << "\t" << count << " words imported.\n " << endl;

       
    }else{

      cout << "\n\n\t Unable to open the file" << endl;

        }

 
   chosenWord = randWord (words, 4000);

   display(chosenWord); 

   
   cout << "\n Would you like to play one more game? y/n: " << endl;
   cin >> Decision;


   
   if (Decision == 'y' || Decision == 'Y')
     {
       play = true;
      
     }else{

     if (Decision == 'n' || Decision == 'N')
       {
	 cout << "\n";
	 
	 cout << " ***                                                     &  XXXXX    XXXXXXX " << endl;
	 cout << " *****       ********   ####  ####      @@@@@   &&&&&   &&     XXX  XXXXX    " << endl;
	 cout << " *******     ********   ####  ####     @@@@@@   &&&&&& &&&       XXXXXX      " << endl;
	 cout << " **********     #       #########     @@@ @@@   &&&   &&&&        XXXX       " << endl;
	 cout << " *******        #       ##     ##    @@    @@   &&     &&&     XXXXX XXX     " << endl;
	 cout << " *****          #       #       #   @       @   &       &&  XXXXXX     XXXX  " << endl;
	 cout << " ***                                                                         " << endl;
	 cout << "         ******************** GAME OVER **************************           " << endl;
	 
	 play = false;

      }
   }


   }while(play);

     
   return 0;

 }


   // OTHER FUNCTIONS **************

   // ******** Function 1 *********

 
 void display (string str)
{

  string wordPicked = str;
  char input, space = ' ', dash[30], missedIt[6];  
  int remain = 0, addAsAttempt = 0, At_Position_In_Word, wordLength = wordPicked.length();
  bool winningCheck = false, rightChar, gameOn = true, inputOk = false;
  
  

  
  cout << "\n chosen word is - " << wordPicked << endl;
  cout << "\n Ok. I am thinking of a word with " << wordLength << " letters. " << endl;
  cout << " " << wordLength << " remain letters. " << endl;

  
    for (int a = 0; a < wordLength; a++)
     {
       remain++;
       
       dash[a] = '_';
       cout << space << dash[a] ;       

     }



   do{


  
     gameOn = anyAttemptLeft(addAsAttempt);


     
     if(gameOn)
       {
	 missedLetters(missedIt, addAsAttempt);
         

	 while(!inputOk)// makes sure the validation of input.
	 {

	 cout << "\n\n Enter the letter you would like to guess: ";
	 cin >> input;


	  inputOk = inputCheck(input);
 
	 
	   }
       }
     
     
      for (int i = 0; i < wordLength; i++) // Loop checks the word to match the input 
       {
		 
	 if (input == wordPicked.at(i))// puts the input in array to display as a right answer.
	 {
	   
	   remain--;

	   dash[i] = input;
	   
	     
	   }      

       }



      cout << "\n";

      cout << " " << remain << " letter remains. \n" << endl;


      
      
      for(int p = 0; p < wordLength; p++) // prints the array with all the correct words entered by user (with dashes)
	{
	  
	  cout << space << dash[p];
	  
	}

      
      for (int k = 0; k < wordLength; k++) // loops through the word again to determind the attempts and other aspects needed.
	   {
	     if (input != wordPicked.at(k))
	       {
		 
		 rightChar = false; // boolean turns false when the input is not matched

	       }else{

	       rightChar = true; // boolean turns true if the input is matched

		k = wordLength;

	         }

	     }
	     


      if (!rightChar)
	{
	  
	  cout << "\n There are no " << input << " in the puzzle. " << endl;

	  missedIt[addAsAttempt] = input;// makes the list of missed guesses

    

	  addAsAttempt++; 

	  inputOk = false; // to keep the while (input validation loop) running everytime   

	}else{


	if (rightChar)
	  {

	    winningCheck = checkWinning(dash, wordPicked); 

	   
	    if (!winningCheck)
	      {
		inputOk = false;
		gameOn = true;
	      }
	    else
	      {
		gameOn = false;

	      }
	  }
      }


      
           
   }while(gameOn);

   
   Declaration(winningCheck);


}

        // ********* Function 2 *********


bool inputCheck(char Input) // checks and makes sure that the input is valid. 
{

  char checkList1[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
  char checkList2[] = {'1','2','3','4','5','6','7','8','9','0'};
  char checkList3[] = {' ','@','#','$','%','^','&','*','(',')','[',']','{','}','_','-','=','+','?','/',',','.','<','>','~','`'};
    
    
  for(int i = 0; i < 30; i++) // runs input through different lists of in-valid charecter lists to determin the validity of the input.
      {

	if (Input == checkList1[i])
	 {
	  
	  cout << " Please enter a lower case letter." << endl;

	  return false;
	  
	 }else{

	       
	       if(Input == checkList2[i])
       {

	cout << " Numbers are not part of this word. " << endl;
	cout << " Please enter a letter." << endl;
	
	return false;
       }else{
	     if (Input == checkList3[i])
	       {

		cout << " **No special charecters**" << endl;
		cout << " Please enter a valid character. " << endl;
		return false;
		
	       }

	       }
       
      }
  
      }


    
return true;
              
}



void missedLetters (char INPUT[], int count){ // stores and prints the list of wrong guesses 

  
  int attempt = 6;

  
  if(count == 0)
    {
      cout << "\n Missed letters: none" << endl;

    }else{

    attempt = attempt - count;


    cout << "\n\n you have " << attempt << " bad guesses left. " << endl;
    cout << " Missed letters: ";
  

    for (int i = 0; i < count; i++)
    {
      cout << INPUT[i] << ", ";
    }


  }
}






     // ******* Function 3 ********




bool anyAttemptLeft (int failedAttempts) // checks for any attempts left, if no attempts are left it returns false.
{

  bool gameOff = false;
  
     int count = failedAttempts;

     if (count <= 5 && count >= 0)
       {

         return true;

       }else{

       Declaration(gameOff);

       return false;

       
     }


}


    // ******** Function 4 ********

string randWord (string arr[], int size) // takes in the array of words imported from the file and selects a random word from this list.
{

  srand(time(NULL));
  
  int  randNum = rand() % 3000 + 1;
  string chosenWord = arr[randNum];




  return chosenWord;
  
}





bool checkWinning ( char letters[], string correctWord) // this function checks if all the letters are matched, if so it'll return true.
{

 
  bool Done = true; // Done mean Game Done
  
  for(int z = 0; z <= correctWord.length(); z++) // checks for dashes in the array, if there is any dashes, that means the game is still on. 
    {
      
      if(letters[z] == '_')
	{

	  Done = false;

	  z = correctWord.length() + 1;
	}
    }


  
  if(Done) // once Done = true it checks all the letters guessed by user (stored in array) and loops through the word to determin win or lose.

    {

 for(int c = 0; c <= correctWord.length(); c++)
   {
      
     if(correctWord.at(c) == letters[c])
       {

	
	 cout << letters[c] ;

	 return true;

       }

   }	          

    }

  

  return false;
}




bool Declaration (bool win) // Declares the win or lose.
{
  cout << "\n Debugged: inside Declaration. " << endl;
  


  cout << " win boolean value: " << win << endl;
  
  if (win)
    {

     cout << endl;
     cout << "*******************************************" << endl;
     cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
     cout << "      Congrats!! you won the game!!        " << endl;
     cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
     cout << "*******************************************" << endl;

    }else{

    cout << " #######################" << endl;
    cout << "        you lose!       " << endl;
    cout << " #######################" << endl;

    }

  
    return false;
 }
