// Fiona Keaney
// fionakeaney@csu.fullerton.edu

// recursion
int cutRod(int l, int price[]){
    // base case
    if (l == 0) return 0;

    int maxProfit = 0;

    // iterations
    for (int i =1; i <= l; i++) {
        int currentProfit = price[i - 1] + cutRod(l - 1, price);

        if (currentProfit > maxProfit){
            maxProfit = currentProfit;
        }
    }

    return maxProfit;
}

int main(char *argv[]){
    int rodLength = atoi(argv[1]);
}