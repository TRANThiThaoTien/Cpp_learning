////
////  main.cpp
////  ForStudy
////
////  Created by Cao Bui on 16/03/2018.
////  Copyright © 2018 Thi Thao Tien. All rights reserved.
////  Guessing game
//
//#include <iostream>
//#include <ctime>
//using namespace std;
//
//int main(int argc, const char * argv[]) {
//    
//    int number_input(0);
//    int random_number(0);
//    int times(0);
//    srand((int)time(0));
//    random_number = rand()%100+1;
//    //cout << random_number << endl;
//    //cout << random << endl;
//    cout << "Enter a number : " << endl;
//    cin >> number_input;
//    while (number_input!= random_number) {
//        if (number_input < random_number) {
//            cout << "The code is higher than the number guessed" << endl;
//            cout << "Enter another value" << endl;
//            cin >> number_input;
//            times++;
//        }
//        else{
//            cout << "The code is lowwer than the number guessed" << endl;
//            cout << "Enter another value" << endl;
//            cin >> number_input;
//            times++;
//        }
//    }
//    cout << "You win the game in " << times << "turns" << endl;
//    
//    
//    return 0;
//}
