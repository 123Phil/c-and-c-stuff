// Phillip Stewart
// codeEval challenge
// Compares two standard poker hands

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

enum { HIGH=0,PAIR,TWOPAIR,TOK,STRAIGHT,FLUSH,FULLH,FOK,SF,RF };
enum { TEN=10,JACK,QUEEN,KING,ACE };
enum { DRAW=0,LEFT,RIGHT };

typedef char card[2];

class Hand {
	card chars[5];
	int v[5];
	int suits[5];
	int hand_value;

public:
	Hand(std::string line){
		std::stringstream ss(line);
		for(int i=0;i<5;i++) ss >> chars[i];
		init_values();
		hand_value = sort_and_value();
	}

	void init_values(){
		for (int i=0; i<5; i++) {
			if (chars[i][0] >= '2' && chars[i][0] <= '9') v[i] = chars[i][0] - '0';
			else switch (chars[i][0]) {
				case 'T': v[i] = TEN;   break;
				case 'J': v[i] = JACK;  break;
				case 'Q': v[i] = QUEEN; break;
				case 'K': v[i] = KING;  break;
				case 'A': v[i] = ACE;   break;
			}
			switch(chars[i][1]) {
				case 'S': suits[i] = 0;break;
				case 'C': suits[i] = 1;break;
				case 'H': suits[i] = 2;break;
				case 'D': suits[i] = 3;break;
			}
		}
	}
	
	int sort_and_value() {
		std::sort(v, v+5);
		
		bool f = is_flush();
		bool s = is_straight();
		
		if (f && s) {
			if (v[4] == ACE) return RF;
			else return SF;
		}
		else if (v[0] == v[1] && v[0] == v[2] && v[0] == v[3]) {
			std::swap(v[0], v[4]);
			return FOK;
		}
		else if (v[1] == v[2] && v[1] == v[3] && v[1] == v[4]) {
			return FOK;
		}
		else if (check_fh()) {
			return FULLH;
		}
		else if (f) { return FLUSH; }
		else if (s) { return STRAIGHT; }
		else if (check_tok()) {
			return TOK;
		}
		else if (check_tp()) {
			return TWOPAIR;
		}
		else if (check_p()) {
			return PAIR;
		}
		else {
			return HIGH;
		}
	}
	
	bool is_flush() {
		for (int i=1;i<5;i++) if(suits[0]!=suits[i]) return false;
		return true;
	}
	
	bool is_straight() {
		int num = v[0]+1;
		bool s = true;
		for (int i = 1; i < 5; i++,num++) if (num != v[i]) s = false;
		return s;
	}
	
	bool check_fh() {
		if (v[0] == v[1] && v[0] == v[2] && v[3] == v[4]) {
			std::swap(v[0], v[4]);
			std::swap(v[1], v[3]);
			return true;
		}
		else if (v[0] == v[1] && v[2] == v[3] && v[3] == v[4]) {
			return true;
		}
		return false;
	}
	
	bool check_tok() {
		if (v[0] == v[1] && v[0] == v[2]) {
			std::swap(v[0], v[3]);
			std::swap(v[1], v[4]);
			return true;
		}
		else if (v[1] == v[2] && v[1] == v[3]) {
			std::swap(v[1], v[4]);
			return true;
		}
		else if (v[2] == v[3] && v[2] == v[4]) {
			return true;
		}
		return false;
	}
	
	bool check_tp() {
		if (v[0] == v[1] && v[2] == v[3]) {
			std::swap(v[2], v[4]);
			std::swap(v[2], v[0]);
			return true;
		}
		else if (v[0] == v[1] && v[3] == v[4]) {
			std::swap(v[0], v[2]);
			return true;
		}
		else if (v[1] == v[2] && v[3] == v[4]) {
			return true;
		}
		return false;
	}
	
	bool check_p() {
		if (v[0] == v[1]) {
			std::rotate(v, v + 2, v + 5);
			return true;
		}
		else if (v[1] == v[2]) {
			std::swap(v[1], v[3]);
			std::swap(v[2], v[4]);
			return true;
		}
		else if (v[2] == v[3]) {
			std::swap(v[2], v[4]);
			return true;
		}
		else if (v[3] == v[4]) {
			return true;
		}		
		return false;
	}
	
	int get_hand_value() {
		return hand_value;
	}
	
	int val(int x) {
		return v[x];
	}
};


int compare(Hand left, Hand right){
	int lv = left.get_hand_value();
	int rv = right.get_hand_value();
	
	if (lv > rv) return LEFT;
	else if (rv > lv) return RIGHT;
	else {
		for (int i=4; i >= 0; i--) {
			//???
			if (left.val(i) > right.val(i)) return LEFT;
			else if (right.val(i) > left.val(i)) return RIGHT;
		}
		return DRAW;
	}
}


int main(int argc, char* argv[])
{

	if (argc != 2)
		{
		std::cout << "Usage ...";
		return 0;
		}
	
	std::ifstream fp(argv[1]);
	std::string line;
	std::string sub;
	int i, outcome;
	
	while(!fp.eof())
		{
			getline(fp, line);
			if (line.size() < 3) break;
			
			i = 14;
			sub = line.substr(i+1);
			line.erase(i);
			
			Hand left(line);
			Hand right(sub);
			
			outcome = compare(left, right);
			switch(outcome) {
				case LEFT:  std::cout<<"left\n"; break;
				case RIGHT: std::cout<<"right\n";break;
				case DRAW:  std::cout<<"none\n"; break;
			}
		}
	
	fp.close();
	return 0;
}
