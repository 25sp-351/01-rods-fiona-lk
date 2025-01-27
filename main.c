// Fiona Keaney
// fionakeaney@csu.fullerton.edu

#include <stdio.h>

// recursion
int cutRod(int l, int price[], int cutList[], int *index){
    // base case if no length yet
    if (l == 0) return 0;

    int maxProfit = 0;
    int bestCut = 0;

    // iterations
    for (int i =1; i <= l; i++) {
        int currentProfit = price[i - 1] + cutRod(l - 1, price, cutList, index);

        if (currentProfit > maxProfit){
            maxProfit = currentProfit;
            bestCut = i;
        }
    }

    cutList[(*index)++] = bestCut;
    return maxProfit;
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