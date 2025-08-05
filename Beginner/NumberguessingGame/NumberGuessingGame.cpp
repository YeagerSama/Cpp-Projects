#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

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

    cout<<"Enter a number between 1 to "<< n <<endl;

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


    //Create an input object check wether the score is the bestscore or not
    ifstream read("bestScore.txt");
    if(!read.is_open()){
        cout<<"The file is not opening or does not exist\n";
    }

    int input;
    read>>input;

    if(attempts<input){
        ofstream file("bestScore.txt");
        file<<attempts;
        cout<<"You have beat the High Score !!!"<<endl;
        cout<<attempts<<endl;
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

    return 0;

}
