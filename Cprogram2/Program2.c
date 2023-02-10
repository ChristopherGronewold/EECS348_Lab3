#include <stdio.h>

int main(void)
{
    int score, input;
    int td2, td1, td, fg, saf;
    printf("Enter 0 or 1 to STOP\n");
    printf("Enter the NFL score: ");
    scanf("%d", &input);
    while (input > 1)
    {
        for (td2 = 0; td2 <= input/8; td2++) {
            for (td1 = 0; td1 <= input/7; td1++) {
                for (td = 0; td <= input/6; td++) {
                    for (fg = 0; fg <= input/3; fg++) {
                        for (saf = 0; saf <= input/2; saf++) {
                            score = td2*8 + td1*7 + td*6 + fg*3 + saf*2;
                            if (score == input) {
                                printf("%d TD+2pt, %d TD+FG, %d TD, %d 3ptFG, %d Safety\n", td2, td1, td, fg, saf);
                            }
                        }
                    }
                }
            }
        }

        printf("Enter a score: ");
        scanf("%d", &input);
    }
    printf("Input must be more than 1. Program ending.");
    return 0;
}
