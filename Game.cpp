#include <iostream>
#include <vector>

using namespace std;

struct Riddle {
    string question;
    string answer;
};

class MysteryGame {
private:
    vector<Riddle> riddles;
    int currentRiddle;

public:
    MysteryGame() {
        riddles.push_back({"I speak without a mouth and hear without ears. I have no body, but I come alive with the wind. What am I?", "echo"});
        riddles.push_back({"The more of me you take, the more you leave behind. What am I?", "footsteps"});
        riddles.push_back({"I have keys but open no locks. I have space but no room. You can enter, but you can't go outside. What am I?", "keyboard"});
        currentRiddle = 0;
    }

    void start() {
        cout << "You find yourself trapped in a dark, mysterious mansion. A voice echoes: \"Solve my riddles to escape.\"" << endl;
        while (currentRiddle < riddles.size()) {
            cout << "\nRiddle: " << riddles[currentRiddle].question << endl;
            cout << "Your answer: ";
            string userAnswer;
            getline(cin, userAnswer);
            
            if (userAnswer == riddles[currentRiddle].answer) {
                cout << "Correct! You move forward..." << endl;
                currentRiddle++;
            } else {
                if (currentRiddle == riddles.size() - 1) {
                    cout << "Wrong! The doors slam shut. You are trapped here forever..." << endl;
                    return;
                }
                cout << "Wrong answer. Try again..." << endl;
            }
        }
        cout << "Congratulations! You solved all the riddles and escaped the mansion!" << endl;
    }
};

int main() {
    MysteryGame game;
    game.start();
    return 0;
}
