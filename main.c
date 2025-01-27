// Fiona Keaney
// fionakeaney@csu.fullerton.edu

#include <stdio.h>

// recursion
int cutRod(int rodLength, int price[], int cutList[], int *cutCount){
    // base case if no length yet
    if (rodLength == 0) return 0;

    int maxProfit = 0;
    int bestCut = 0;

    // iterations
    for (int i =1; i <= rodLength; i++) {
        int currentProfit = price[i - 1] + cutRod(l - 1, price, cutList, cutCount);

        if (currentProfit > maxProfit){
            maxProfit = currentProfit;
            bestCut = i;
        }
    }

    cutList[(*cutCount)++] = bestCut;
    return maxProfit;
}

void printResults(int cutList[], int cutCount, int price[], int rodLength) {

}

int main(char *argv[]){
    int rodLength = atoi(argv[1]);

    int prices[50];
    int count = 0;

    while (scanf("%d", &prices[count]) != EOF) {
        count++;
    }

    int cutList[rodLength];
    int cutCount = 0;

    cutRod(rodLength, prices, cutList, &cutCount);

    return 0;
}