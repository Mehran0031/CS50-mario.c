#include <stdio.h>
#include <cs50.h>
#include <math.h>
 

int main(void) 
{
    float money;
    // set money:
    do 
    {
        printf("How much change is owned?\n");
        money = GetFloat();
    }
    while ( money < 0.009);
    
    int money_long =  (int) ceil(money * 1000);
        
    int coin25 = ceil(money_long / 250); 
    money_long = money_long - (coin25 * 250);
    
    int coin10 = ceil(money_long / 100);
    money_long = money_long - (coin10 * 100);
    
    int coin5 = ceil(money_long / 50);
    money_long = money_long - (coin5 * 50);
     
    int coin1 = ceil(money_long / 10);
    money_long = money_long - (coin1 * 10);
    
    int count_coins = coin25 + coin10 + coin5 + coin1;
    
    // round:
    // printf("   money3: %i\n    money: %i\n   coin 25: %i\n   coin 10: %i\n   coin 5: %i\n   coin 1: %i\n   coins_need:\n%i\n",money3,money2,coin25,coin10,coin5,coin1,count_coins);
    printf("%i\n",count_coins);
}