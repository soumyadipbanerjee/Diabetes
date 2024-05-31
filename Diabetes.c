#include <stdio.h>

#define NUM_PATIENTS 10

int predict_diabetes(int glucose, int bmi, int age) {
    int score = 0;
    if (glucose > 120) score++;
    if (bmi > 25) score++;
    if (age > 45) score++;
    return score > 1 ? 1 : 0;
}

int main() {
    int glucose_levels[NUM_PATIENTS] = {85, 140, 90, 200, 110, 180, 75, 130, 100, 150};
    int bmis[NUM_PATIENTS] = {22, 30, 19, 28, 24, 35, 18, 29, 23, 32};
    int ages[NUM_PATIENTS] = {25, 50, 35, 60, 40, 55, 30, 48, 38, 52};
    int predictions[NUM_PATIENTS];

    for (int i = 0; i < NUM_PATIENTS; i++) {
        predictions[i] = predict_diabetes(glucose_levels[i], bmis[i], ages[i]);
    }

    printf("Glucose\tBMI\tAge\tPrediction\n");
    printf("-------\t---\t---\t----------\n");
    for (int i = 0; i < NUM_PATIENTS; i++) {
        printf("%d\t%d\t%d\t%s\n", glucose_levels[i], bmis[i], ages[i], predictions[i] ? "Diabetes" : "No Diabetes");
    }

    return 0;
}
