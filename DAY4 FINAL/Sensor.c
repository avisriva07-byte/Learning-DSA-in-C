#include <stdio.h>

union Value {
    float temperature;
    char door;
    long pulses;
};

struct Reading {
    int sensorID;
    char kind;
    union Value value;
};

struct AllFields {
    int sensorID;
    char kind;
    float temperature;
    char door;
    long pulses;
};

int main() {
    int N;
    scanf("%d", &N);

    if (N <= 0 || N > 1000) {
        printf("INVALID COUNT\n");
        return 0;
    }

    struct Reading readings[1000];

    for (int i = 0; i < N; i++) {
        scanf("%d %c", &readings[i].sensorID,
              &readings[i].kind);

        switch (readings[i].kind) {
            case 'T':
                scanf("%f", &readings[i].value.temperature);
                break;

            case 'D':
                scanf(" %c", &readings[i].value.door);
                break;

            case 'P':
                scanf("%ld", &readings[i].value.pulses);
                break;

            default:
                printf("INVALID KIND\n");
                return 0;
        }
    }

    printf("\nSENSOR REPORT\n");

    for (int i = 0; i < N; i++) {
        switch (readings[i].kind) {
            case 'T':
                printf("Sensor %d temperature %.2f C\n",
                       readings[i].sensorID,
                       readings[i].value.temperature);
                break;

            case 'D':
                printf("Sensor %d door %s\n",
                       readings[i].sensorID,
                       readings[i].value.door == 'O'
                           ? "OPEN" : "CLOSED");
                break;

            case 'P':
                printf("Sensor %d pulses %ld\n",
                       readings[i].sensorID,
                       readings[i].value.pulses);
                break;
        }
    }

    printf("sizeof(union Value): %zu\n", sizeof(union Value));
    printf("sizeof(Reading) with union: %zu\n",
           sizeof(struct Reading));
    printf("sizeof(Reading) with all fields: %zu\n",
           sizeof(struct AllFields));
    printf("Bytes saved per record: %zu\n",
           sizeof(struct AllFields) - sizeof(struct Reading));

    return 0;
}