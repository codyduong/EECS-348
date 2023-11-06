#include <stdio.h>

// Define the different scoring plays.
#define TWO_POINT_CONVERSION 8
#define ONE_POINT_CONVERSION 7
#define TOUCHDOWN 6
#define FIELD_GOAL 3
#define SAFETY 2

int calculateScoreFromCombination(int *combination)
{
  // Assume 5 elements, otherwise SegFault LOL!
  return combination[0] * TWO_POINT_CONVERSION + combination[1] * ONE_POINT_CONVERSION + combination[2] * TOUCHDOWN + combination[3] * FIELD_GOAL + combination[4] * SAFETY;
}

// Print all possible combinations of scoring plays that can result in the given score.
void printCombinations(int score)
{
  int combination[5];
  combination[0] = 0; // TD+2pt
  combination[1] = 0; // TD+1pt
  combination[2] = 0; // TD
  combination[3] = 0; // FG
  combination[4] = 0; // Safety

  // Iterate over all possible combinations of scoring plays.
  printf("Possible combinations of scoring plays:\n");
  while (1)
  {
    if (calculateScoreFromCombination(combination) == score)
    {
      printf("%d TD+2pt, %d TD+1pt, %d TD, %d FG, %d Safety\n", combination[0], combination[1], combination[2], combination[3], combination[4]);
    }

    // Increment Safety first to match ordering in sample output.
    combination[4]++;

    if (combination[4] * SAFETY > score)
    {
      combination[4] = 0;
      combination[3]++;
    }

    if (combination[3] * FIELD_GOAL > score)
    {
      combination[3] = 0;
      combination[2]++;
    }

    if (combination[2] * TOUCHDOWN > score)
    {
      combination[2] = 0;
      combination[1]++;
    }

    if (combination[1] * ONE_POINT_CONVERSION > score)
    {
      combination[1] = 0;
      combination[0]++;
    }

    if (combination[0] * TWO_POINT_CONVERSION > score)
    {
      // We know we are done if we have two point conversion is already over max score, just exit.
      break;
    }
  }
}

int main()
{
  while (1)
  {
    int score;
    printf("Enter 0 or 1 to STOP\n");
    printf("Enter the NFL score: ");
    scanf("%d", &score);

    // Explode the program on negative scores.
    if (score < 0)
    {
      printf("Invalid score.\n");
      return 1;
    }
    else if (score <= 1)
    {
      // Exit on 0 or 1
      return 0;
    }

    printCombinations(score);
    printf("\n");
  }

  return 0;
}