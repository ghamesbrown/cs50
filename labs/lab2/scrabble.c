#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int computeScore(char *word);

int main(void){
	char *word1 = malloc(sizeof(char)), *word2 = malloc(sizeof(char));

	printf("Player 1: ");
	scanf("%s", word1);
	printf("Player 2: ");
	scanf("%s", word2);

	int score1 = computeScore(word1);
	int score2 = computeScore(word2);

	if (score1 > score2){
		printf("Player 1 is the winner!\n");
	}
	else if (score2 > score1) {
		printf("Player 2 is the winner!\n");
	}
	else{
		printf("Tie!\n");
	}
	return 0;
}

int computeScore(char *word){
	int score = 0, len = strlen(word);
	for(int i = 0; i < len; i++){
		if(isupper(word[i])){
			score += POINTS[word[i] - 65];
		}
		else if(islower(word[i])){
			score += POINTS[word[i] - 97];
		}
		else{
			score += 1;
		}
	}
	return score;
}

