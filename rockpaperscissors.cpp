
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

//ENUMERATIONS

enum Weapon {ROCK, PAPER, SCISSORS, BAD_WEAPON};

// FUNCTION DECLARATIONS

void print_instructions();
Weapon get_player_weapon();
Weapon get_computer_weapon();
string get_weapon_name(Weapon);
string get_winning_message(Weapon);
string get_losing_message(Weapon);
Weapon get_winning_weapon(Weapon);
int randint(int);



int main() {

	/* Seed pseudorandom number generator */

	srand( time(NULL) );

	/* Define state variables */

	Weapon computer_weapon;
	Weapon player_weapon;
    
	bool game_over = false;

	char play_again = 'N';

	int game_count = 0;
	int win_count = 0;

	/* Print Instructions */

	print_instructions();

	/* Main Game Loop */

	while ( !game_over ) {

		/* Increment Game Counter (once per turn) */

		++game_count;

		/* Get Player/Computer Weapon Choices */

		computer_weapon = get_computer_weapon();
		player_weapon = get_player_weapon();

		/* Print Weapon Choices */

		cout << "\nPlayer Picked: " << get_weapon_name(player_weapon) << '\n';
		cout << "Computer Picked: " << get_weapon_name(computer_weapon) << '\n';

		/* Check Draw, Win, or Lose */

		if ( player_weapon == computer_weapon ) {

			/* Draw */

			cout << "IT'S A DRAW!\n\n";

		}

		else if ( player_weapon == get_winning_weapon(computer_weapon) ) {

			/* Player Wins (increment win counter) */

			cout << "PLAYER WINS: " << get_winning_message(player_weapon) << "\n\n";
			++win_count;

		}

		else {

			/* Player Loses */

			cout << "COMPUTER WINS: " << get_losing_message(player_weapon) << "\n\n";

		}

		/* Prompt User to Play Again */

		cout << "PLAY AGAIN? ('Y' or 'N'): ";
		cin >> play_again;

		play_again = toupper(play_again);

		if ( play_again == 'N' ) {

			/* If No, Flip "Game Over" Flag */

			game_over = true;

		}

	}

	/* Game is Over: Output Game/Win Counters */

	cout << "\nYou won " << win_count << " out of " << game_count << " game(s)!\n";
	cout << "THANKS FOR PLAYING!\n\n";

	return 0;

} // End main()} 






void print_instructions(){

cout << "\nWELCOME TO PAPER-ROCK-SCISSORS!\n\n";
cout << "This is a game for two players, which you will be playing\n";
cout << "against the computer.  With each game, both players will\n";
cout << "select one of the following weapons: PAPER, ROCK, or SCISSORS.\n";
cout << "The winner is determined as follows:\n\n";
cout << "* If both players select the same weapon, the game is a tie.\n";
cout << "* ROCK blunts SCISSORS, so the player who selects ROCK wins.\n";
cout << "* PAPER wraps ROCK, so the player who selects PAPER wins.\n";
cout << "* SCISSORS cuts PAPER, so the player who selects SCISSORS wins.\n\n";
cout << "With each turn, select 'R' for ROCK, 'P' for PAPER, or 'S' for\n";
cout << "SCISSORS, and then press ENTER.  You may quit at any time.\n\n";
}	// end print_instructions	


// random number generator 
int randint(int max){
return (rand() % max);

} // end randint()
		
		
// Get PLayer Weapon

Weapon get_player_weapon(){
	
Weapon player_weapon;
char player_choice;

bool weapon_selected = false;

//* loop until valid weapon is selected 

while (!weapon_selected){


cout << "Choose Weapon ('R', 'P', or 'S'): ";

cin >> player_choice;

player_choice = toupper(player_choice);

switch (player_choice ){

case 'R':// rock //

	player_weapon = ROCK;
	
	weapon_selected = true;
break;
	
case 'P': // paper //
	player_weapon = PAPER;
    
	weapon_selected = true;
	break;

case 'S': // Scissor //
	player_weapon = SCISSORS;
	
	weapon_selected = true;
	break;

default:
	 cout << "Sorry that is not a choice please try again: \n";
		break;
}	
}
return player_weapon;
}
	
//Computer Weapon selection	

Weapon get_computer_weapon(){



// random number generator 


long  seed = time(NULL); // gets current time
		srand(seed);
		
		// Computer's random selection
		int computer_choice = randint(3);
		
		//DEBUG: cout << computer << endl;
		
		      //seed = time(0);
       // srand(seed); //For the random generator.
        
computer_choice = randint(3) % 3 + 1; //Computers pick.
		

Weapon computer_weapon;

switch (computer_choice){
	
case '0':// rock
computer_weapon = ROCK;	

break;

case '1'://paper

computer_weapon = PAPER;

break;

case '2'://Scissors

computer_weapon = SCISSORS;
break;

default:
	computer_weapon = BAD_WEAPON;

	
	
}
// return weapon choice	
return computer_weapon;	
}










string get_weapon_name(Weapon weapon){
	
	// returns name of weapon object as string
	
	
	
	string name ;
	
	switch (weapon){
		
	case ROCK: 
	name = ROCK;
	break;
	
	case PAPER:
	name = PAPER;
	break;
	
	case SCISSORS:
	name = SCISSORS;
	break;
}
return name;
} // end weapon name()
		
	
string get_winning_message(Weapon weapon){
	string message;
	
	switch(weapon){
		
	case ROCK:
	message = "Rock Blunts Scissors";
	break;
	
	case PAPER:
	message = "PAPER WRAPS ROCK";
	break;
	
	case SCISSORS:
		message = "SCISSORS CUTS PAPER";
		break;
		
		
		default:
			message = "*** ERROR: UNKNOWN WEAPON! ***";
			
		}
		
		return message;
	}


string get_losing_message(Weapon weapon){
	string message;
	
	switch(weapon){
		
	case ROCK:
	message = "PAPER WRAPS ROCK";
	break;
	
	case PAPER:
	message = "SCISSORS CUT PAPER";
	break;
	
	case SCISSORS:
		message = "ROCK BLUNTS SCISSORS";
		break;
		
		
		default:
			message = "*** ERROR: UNKNOWN WEAPON! ***";
			
		}
		
		return message;
	
}

Weapon get_winning_weapon(Weapon weapon){
	// for every possible weapon choice by the computer, return the weapon that would
	// be needed by the player to defeat it.
	Weapon winning_weapon;
	
	switch (weapon){
		
		case ROCK:
			winning_weapon = PAPER;
			break;
			
			
			
		case PAPER:
			winning_weapon = SCISSORS;
			break;
			
		
		case SCISSORS:
			winning_weapon = ROCK;
			break;
			
			default: 
			winning_weapon = BAD_WEAPON;
			
	}
	return winning_weapon;
}
	
	




