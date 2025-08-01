#include<iostream>
#include<vector>
using namespace std;

// This vector will store the guesses that the user makes and displays them at the end
void print(vector<int>& guesses, int attempts){

    for(int i=0;i<=attempts;i++){
        cout<<guesses[i]<<" ";
    }
    cout<<endl;

    return;
}

void guessingGame(int n){

    int num;
    vector<int> guesses(n);

    srand(time(0));
    int genNum = rand() % n + 1;

    int attempts=0;

    cout<<"Enter a number between 1 to n \n";

    while (true)
    {
        cout<<"What is your guess?\n"<<endl;
        cin>>num;

        guesses[attempts]=num;

        if(genNum==num){
            cout<<"You won in "<<attempts<<" tries. YAYAYAYAY!!!"<<endl;
            break;
        }
        else if(num<genNum)
            cout<<"Too low, try again"<<endl;
        else
            cout<<"Too high, try again "<<endl;
        
        attempts++;
    }
    
    print(guesses, attempts);

    return;

}



int main(){

    int input;

    cout<< "Enter \n";
    cout<<"0 : To Play the game\n";
    cout<<"1 : To Quit"<<endl;
    cin>>input;

    int difficulty;

    switch (input)
    {
    case 0: cout<<"Enter the difficulty - 0 for Easy, 1 for Moderate ,2 for Hard\n";
            cin>>difficulty;
            switch (difficulty)
            {
            case 0:guessingGame(10);
                break;
            case 1:guessingGame(100);
                break;
            case 2:guessingGame(1000);
                break;
            default:cout<<"Uh-Oh Invalid Input\n";
            }
            break;
    case 1:cout<<"Goodbye friend...\n";
            return 0;

    default: cout<<"Uh-Oh Invalid Input"<<endl;
    }

    void print();

    return 0;

}
