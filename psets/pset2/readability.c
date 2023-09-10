#include <string.h>
#include <stdio.h>
#include "cs50.h"
#include <math.h>
#include <ctype.h>

int count_word(string text, int len);
int count_sent(string text, int len);
int count_letter(string text, int len);

int main(void)
{
	// L is the average number of letter per 100 words
	// S is the average number of sentence per 100 words
	string text = get_string("Text: ");
	int len = strlen(text);

	int index = 0.0588 * (float)(count_letter(text, len) * 100 / count_word(text, len)) - 0.296 
		* (float)(count_sent(text, len) * 100 / count_word(text, len)) - 15.8;

	if(index == 16 || index > 16)
		printf("Grade 16+\n");

	else if(index < 1)
		printf("Before Grade 1\n");

	else
		printf("Grade %d\n", index);
}

int count_word(string text, int len){
	
	int word = 1;
	for(int i = 0; i < len; i++){
		if(isspace(text[i]))
			word++;
	}
	return word;
}

int count_sent(string text, int len){
	int sent = 0;

	for(int i = 0; i < len; i++){
		if(text[i] == '!' || text[i] == '?' || text[i] == '.')
			sent++;
	}
	return sent;
}

int count_letter(string text, int len){

	int letters = 0;

	for(int i = 0; i < len; i++){
		if(isalpha(text[i]))
			letters++;
	}
	return letters;
}
