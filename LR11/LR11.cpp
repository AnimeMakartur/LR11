#include <stdio.h>
#include <stdlib.h>
#define LETTERLEN 150
#define WORDLEN 4

char* lineLength(char* pLett) {
	//int length = 0;
	while (*pLett != '\0') {
		//length++;
		pLett++;
	}
	return pLett;
}

int main()
{
	char letter[LETTERLEN+1], * pLett;
	char letterCopy[LETTERLEN+1], * pLettCopy;
	char word[WORDLEN], * pWord;
	printf("Enter a line of text, maximum %d:\n", LETTERLEN);
	gets_s(letter, LETTERLEN);
	pLett = letter;
	pLettCopy = letterCopy;	
	printf("Enter a word to search for, length of word is 3:\n");
	gets_s(word, WORDLEN);
	pWord = word;
	if (lineLength(pWord)- pWord <3) {
		printf("The length of the line is too short\n");
		return 1;
	}
	int found = 0;
	int isInLetter = 0;
	for (int i = 2 ; letter[i] != '\0'; i++, pLettCopy++) {
		isInLetter = *pLett == word[0] && *(pLett + 1) == word[1] && *(pLett + 2) == word[2];
		if (isInLetter) {
			*pLettCopy = 'X';
			pLett += 3;
			found++;
		}
		else {
			*pLettCopy = *pLett;
			pLett++;
		}
	}
	if (found == 0) {
		printf("The \"%s\" was not found in the line.\n", word);
		return 0;
	}
	*pLettCopy = '\0';
	pLettCopy = letterCopy;
	pLett = letter;
	//for ( ; *pLettCopy ;)
	//do
	//{
	//	*pLett++ = *pLettCopy++;
	//	//pLett++;
	//	//pLettCopy++;
	//} while (*(pLett - 1));
	while (*pLett++ = *pLettCopy++);
	//*pLett = '\0';
	printf("The \"%s\" was found %d times.\n", word, found);
	printf("The line after removing the word is:\n");
	printf("%s\n", letterCopy);
	return 0;
}

