#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
void rules();
int main()
{
    string playerName;
    int balance, bettingAmount, guess, dice;
    char choice;
    srand(time(0));
    cout << "WELCOME TO THE GAME\n";
    cout << "Type your name : \n";
    getline(cin, playerName);
    cout << "Enter the starting balance to play game : Rs\n";
    cin >> balance;
    do
    {
        system("cls");
        rules();
        cout << "\nYour current balance is Rs " << balance << "\n";
        do
        {
            cout << "Hello, " << playerName << ", enter amount to bet : Rs";
            cin >> bettingAmount;
            if (bettingAmount > balance)
                cout << "Betting balance can't be more than current balance! Please Re-enter your balance...";
        } while (bettingAmount > balance);
        do
        {
            cout << "Guess any betting number between 1 & 10 :";
            cin >> guess;
            if (guess <= 0 || guess > 10)
                cout << "\nNumber should be between 1 to 10\n"
                     << "Re-enter number:\n ";
        } while (guess <= 0 || guess > 10);
        dice = rand() % 10 + 1;
        if (dice == guess)
        {
            cout << "\n\nYou are in luck!! You have won Rs." << bettingAmount * 10;
            balance = balance + bettingAmount * 10;
        }
        else
        {
            cout << "Oops, better luck next time !! You lost $ " << bettingAmount << "\n";
            balance = balance - bettingAmount;
        }
        cout << "\nThe winning number was : " << dice << "\n";
        cout << playerName << ", You have balance of $ " << balance << "\n";
        if (balance == 0)
        {
            cout << "You have no money to play ";
            break;
        }
        cout << "\n\n-->Do you want to play again (y/n)? ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');
    cout << "\nThanks for playing the game. Your balance is $ " << balance << "\n";
    return 0;
}
void rules()
{
    system("cls");
    cout << "Rules to follow\n";
    cout << "1. Choose a number between 1 to 10\n";
    cout << "2. Winner gets 10 times of the money bet\n";
    cout << "3. Wrong bet, and you lose the amount you bet\n";
}