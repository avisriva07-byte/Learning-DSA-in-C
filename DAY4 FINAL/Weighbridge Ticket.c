
#include <stdio.h>
#include <stdlib.h>

struct Ticket {
    int ticketNumber;
    char registration[20];
    float grossWeight;
    float tareWeight;
};

float calculateNetWeight(struct Ticket *t) {
    return t->grossWeight - t->tareWeight;
}


void printTicket(struct Ticket *t) {
    printf("%d %s gross %.2f tare %.2f\n",
           t->ticketNumber,
           t->registration,
           t->grossWeight,
           t->tareWeight);
}

int main() {
    int N;

    if (scanf("%d", &N) != 1) {
        printf("INVALID COUNT\n");
        return 0;
    }

    if (N <= 0 || N > 100000) {
        printf("INVALID COUNT\n");
        return 0;
    }

    struct Ticket *tickets =
        (struct Ticket *)malloc(N * sizeof(struct Ticket));

    if (tickets == NULL) {
        return 1;
    }

    for (int i = 0; i < N; i++) {
        if (scanf("%d %19s %f %f",
                  &tickets[i].ticketNumber,
                  tickets[i].registration,
                  &tickets[i].grossWeight,
                  &tickets[i].tareWeight) != 4) {
            free(tickets);
            return 0;
        }
    }

    float totalNetWeight = 0.0f;
    int heaviestIndex = 0;

    printf("\nWEIGHBRIDGE DAY BOOK\n");

    for (int i = 0; i < N; i++) {
        printTicket(&tickets[i]);

        float net = calculateNetWeight(&tickets[i]);

        printf("net %.2f\n", net);

        totalNetWeight += net;

        if (i == 0 ||
            net > calculateNetWeight(&tickets[heaviestIndex])) {
            heaviestIndex = i;
        }
    }

    printf("Tickets: %d\n", N);
    printf("Total net weight (kg): %.2f\n", totalNetWeight);

    printf("Heaviest net load: ticket %d %s\n",
           tickets[heaviestIndex].ticketNumber,
           tickets[heaviestIndex].registration);

    printf("%.2f\n",
           calculateNetWeight(&tickets[heaviestIndex]));

    free(tickets);

    return 0;
}
