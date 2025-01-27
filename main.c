// Fiona Keaney
// fionakeaney@csu.fullerton.edu

#include <stdio.h>

// recursion
int cut_rod(int rod_length, int price[], int cut_list[], int *cut_count) {
    // base case if no length yet
    if (rod_length == 0)
        return 0;

    int max_profit = 0;
    int best_cut   = 0;

    // iterations
    for (int i = 1; i <= rod_length; i++) {
        int current_profit =
            price[i - 1] + cutRod(rod_length - i, price, cut_list, cut_count);

        if (current_profit > max_profit) {
            max_profit = current_profit;
            best_cut   = i;
        }
    }

    cut_list[(*cut_count)++] = best_cut;
    return max_profit;
}

void print_results(int cut_list[], int cut_count, int price[], int rod_length) {
    int total_value = 0;
    int length_used = 0;

    int counts[50] = {0};
    for (int i = 0; i < cut_count; i++) {
        counts[cut_list[i] - 1]++;
        length_used += cut_list[i];
    }

    for (int i = 0; i < 50; i++) {
        if (counts[i] > 0) {
            int value = counts[i] * price[i];
            total_value += value;
            printf("%d @ %d = %d\n", counts[i], i + 1, value);
        }
    }

    int remainder = rod_length - length_used;
    printf("Remainder: %d\n", remainder);

    printf("Value: %d\n", total_value);
}

int main(char *argv[]) {
    int rod_length = atoi(argv[1]);

    int prices[50];  // assuming max of 50
    int count = 0;

    while (scanf("%d", &prices[count]) != EOF)
        count++;

    int cut_list[rod_length];
    int cut_count = 0;

    cut_rod(rod_length, prices, cut_list, &cut_count);
    print_results(cut_list, prices, cut_list, &cut_count);

    return 0;
}