#include <stdio.h>
#include <limits.h>

int maxProfit(int prices[], int pricesSize) {
    if (pricesSize < 2) {
        return 0;
    }

    int min_price = INT_MAX;
    int max_profit = 0;

    for (int i = 0; i < pricesSize; i++) {
            if (prices[i] < min_price) {
            min_price = prices[i];
        } 
          else {
            int current_profit = prices[i] - min_price;
            if (current_profit > max_profit) {
                max_profit = current_profit;
        }
    }
}
    return max_profit;
}

 int main() {
    int prices[100];
    int days;
    printf("No of Days: ");
    scanf("%d", &days);


    for(int i=0; i<days; i++) 
    {
    scanf("%d", &prices[i]);
    }

    for(int i=0; i<days; i++) 
    {
        printf("%d", prices[i]);
        printf(" ");
    }
   
    
    int result = maxProfit(prices, days);
    printf("\nMaximum Profit: %d\n", result); 
    
    return 0;
}