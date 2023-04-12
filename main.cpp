//Elleson Tran
//Roberts
//Scared Donkey Program
//A program that generates a scenerio where donkey walks across a bridge
//FINAL

#include <iostream>
#include<ctime>
#include <cstdlib>

using namespace std;

int main() {

  cout<<endl<<"1 - View single simulation"<<endl<<"2 - Run statistics over trials"<<endl<<"3 - Quit"<<endl<<endl;//prompts the menu
  int user;
  cin>>user;
  
  int bridgeLength, donkey, leftSide, rightSide, steps1, greatest, fewest;
  int steps, totalSteps = 0;


  srand(time(0));

  while (user !=3){
    if (user == 1){//single simulation
      cout<<endl<<"Bridge Length:";
      cin>>bridgeLength;

      if ((bridgeLength % 2) == 0){ //even bridge length
        donkey = bridgeLength / 2;
        leftSide = bridgeLength - (donkey + 1);
        rightSide = bridgeLength - donkey;
      }
      if ((bridgeLength % 2) == 1){//odd bridge length
        donkey = (bridgeLength / 2) + 1;
        leftSide = bridgeLength - donkey; 
        rightSide = bridgeLength - donkey;
      }

      while (leftSide != 0 || rightSide != bridgeLength){
        cout<<endl<<"step "<<steps<<": |";
        for (int x = 1; x <= leftSide; ++x){
          cout<<" ";
        }

        cout<<"*";//donkey

        for (int x = 1; x <= rightSide; ++x){
          cout<<" ";
        }

        cout<<"|"<<endl;//end of the bridge
        
        int randomNums = rand()%2;

        if (randomNums == 0){//donkey moves left
          leftSide = leftSide - 1;
          rightSide = rightSide + 1;
          steps = steps + 1;
        }
        if (randomNums == 1){//donkey moves right
          leftSide = leftSide + 1;
          rightSide = rightSide - 1;
          steps = steps + 1;
        }
        if(leftSide == -1 || rightSide == -1){//once the donkey gets to the other side
          steps = steps + 1;
          cout<<endl<<"step "<<steps<<": |";
          for (int x = 1; x <= bridgeLength; ++x){
            cout<<" ";
          }
          cout<<"|"<<endl;
          break;
        }          
      }

      cout<<endl<<"Total Steps Taken: "<<steps<<endl;
    }

    if (user == 2){//second simulation
      cout<<endl<<"Bridge Length:";
      cin>>bridgeLength;
      
      if ((bridgeLength % 2) == 0){ //even bridge length
        donkey = bridgeLength / 2;
        leftSide = bridgeLength - (donkey + 1);
        rightSide = bridgeLength - donkey;
      }
      if ((bridgeLength % 2) == 1){//odd bridge length
        donkey = (bridgeLength / 2) + 1;
        leftSide = bridgeLength - donkey; 
        rightSide = bridgeLength - donkey;
      }
        for (int x = 1; x <= 50; ++x){
        while (leftSide != 0 || rightSide != bridgeLength){

        int randomNums = rand()%2;

        if (randomNums == 0){//donkey moves left
          leftSide = leftSide - 1;
          rightSide = rightSide + 1;
          steps = steps + 1;
        }
        if (randomNums == 1){//donkey moves right
          leftSide = leftSide + 1;
          rightSide = rightSide - 1;
          steps = steps + 1;
        }
        if(leftSide == -1 || rightSide == -1){//once the donkey gets to the other side
          steps = steps + 1;
          totalSteps = totalSteps + steps;
          if(steps < steps1){
            fewest = steps;
          }
          if(steps > steps1){
            greatest = steps;
          }
          steps1 = steps;
          steps = 0;
        break;
        }          
      }     
      }
    
      cout<<"Statistics Over 50 Trials"<<endl;

      cout<<endl<<"Average Steps Taken:"<<totalSteps / 50<<endl;
      cout<<"Greatest # of Steps Taken:"<<greatest<<endl;
      cout<<"Fewest # of Steps Taken:"<<fewest<<endl;
      break;

      }

    if(user == 3){
      cout<<"Bye!";
    }

    
}
}
