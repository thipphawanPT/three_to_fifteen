#ifndef _PLAYSYSTEM_H_
#define _PLAYSYSTEM_H_


void play_system();
int check_number(std::vector<int> &vec);

/* Check turn function 
*  int round - get the round to figure out whose turn
*  odd round is for player 1 and even round is for player 2.
*  return number 1 and 2 for identify player.
*/
int check_turn(int round);
int check_winner(std::vector<int> &vec1,std::vector<int> &vec2, int round);


#endif