#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0

#define TOTAL_CHAR 88

int password_length = 8;
int number_option = TRUE;
int special_char_option = TRUE;
int uppercase_option = TRUE;
int lowercase_option = TRUE;
int number_of_char = TOTAL_CHAR;

char* tab_of_char;

int calcul_number_of_char() {
	int number_of_char = TOTAL_CHAR;

	if(!number_option)
		number_of_char -= 10;
	if(!special_char_option)
		number_of_char -= 27;
	if(!uppercase_option)
		number_of_char -= 26;
	if(!lowercase_option)
		number_of_char -= 26;

	return number_of_char;
}

int is_password_include_lowercase(char* password) {
	int i;
	for(i=0;i<password_length;i++) {
		if(islower(password[i]))
			return 1;
	}
	return 0;
}

int is_password_include_uppercase(char* password) {
	int i;
	for(i=0;i<password_length;i++) {
		if(isupper(password[i]))
			return 1;
	}
	return 0;
}

int is_password_include_special_char(char* password) {
	int i;
	for(i=0;i<password_length;i++) {
		if(ispunct(password[i]))
			return 1;
	}
	return 0;
}

int is_password_include_number(char* password) {
	int i;
	for(i=0;i<password_length;i++) {
		if(isdigit(password[i]))
			return 1;
	}
	return 0;
}

int is_approve_password(char* password) {
        if(number_option)
                if(!is_password_include_number(password))
                        return 0;
        if(special_char_option)
                if(!is_password_include_special_char(password))
                        return 0;
        if(uppercase_option)
                if(!is_password_include_uppercase(password))
                        return 0;
        if(lowercase_option)
                if(!is_password_include_lowercase(password))
                        return 0;

        return 1;
}

void print_password(char* str) {
	int i = 0;
	while(str[i]) {
		printf("%c",str[i]);
		i++;
	}
	printf("\n");
}

int add_number(char* tab, int i) {
	tab[i++] = '0';
	tab[i++] = '1';
	tab[i++] = '2';
	tab[i++] = '3';
	tab[i++] = '4';
	tab[i++] = '5';
	tab[i++] = '6';
	tab[i++] = '7';
	tab[i++] = '8';
	tab[i++] = '9';

	return i;
}

int add_special_char(char* tab, int i) {
	tab[i++] = '~';
	tab[i++] = '!';
	tab[i++] = '@';
	tab[i++] = '#';
	tab[i++] = '$';
	tab[i++] = '%';
	tab[i++] = '^';
	tab[i++] = '&';
	tab[i++] = '*';

	tab[i++] = '(';
	tab[i++] = ')';
	tab[i++] = '-';
	tab[i++] = '=';
	tab[i++] = '+';
	tab[i++] = '[';
	tab[i++] = ']';
	tab[i++] = '{';

	tab[i++] = '}';
	tab[i++] = ';';
	tab[i++] = ':';
	tab[i++] = ',';
	tab[i++] = '.';
	tab[i++] = '<';
	tab[i++] = '>';
	tab[i++] = '/';
	tab[i++] = '?';

	return i;
}

int add_uppercase(char* tab, int i) {
	tab[i++] = 'A';
	tab[i++] = 'B';
        tab[i++] = 'C';
        tab[i++] = 'D';
        tab[i++] = 'E';
        tab[i++] = 'F';
        tab[i++] = 'G';
        tab[i++] = 'H';
        tab[i++] = 'I';
        tab[i++] = 'J';
	tab[i++] = 'K';
        tab[i++] = 'L';
        tab[i++] = 'M';
        tab[i++] = 'N';
        tab[i++] = 'O';
        tab[i++] = 'P';
        tab[i++] = 'Q';
        tab[i++] = 'R';
        tab[i++] = 'S';
	tab[i++] = 'T';
        tab[i++] = 'U';
        tab[i++] = 'V';
        tab[i++] = 'W';
        tab[i++] = 'X';
        tab[i++] = 'Y';
        tab[i++] = 'Z';

	return i;
}

int add_lowercase(char* tab, int i) {
	tab[i++] = 'a';
        tab[i++] = 'b';
        tab[i++] = 'c';
        tab[i++] = 'd';
        tab[i++] = 'e';
        tab[i++] = 'f';
        tab[i++] = 'g';
        tab[i++] = 'h';
        tab[i++] = 'i';
        tab[i++] = 'j';
        tab[i++] = 'k';
        tab[i++] = 'l';
        tab[i++] = 'm';
        tab[i++] = 'n';
        tab[i++] = 'o';
        tab[i++] = 'p';
        tab[i++] = 'q';
        tab[i++] = 'r';
        tab[i++] = 's';
        tab[i++] = 't';
        tab[i++] = 'u';
        tab[i++] = 'v';
        tab[i++] = 'w';
        tab[i++] = 'x';
        tab[i++] = 'y';
        tab[i++] = 'z';

        return i;
}

void swap(char* tab, int a, int b) {
	char tmp;
	tmp = tab[a];
	tab[a]= tab[b];
	tab[b] = tmp;
}

void shuffle_tab(char* tab) {
	int i;
	int random_number;
	
	for(i=0;i<number_of_char;i++) {
		random_number = rand()%number_of_char;
		swap(tab, i, random_number);
	}
}

void init_tab_of_char(char* tab) {
	int offset = 0;

	if(number_option)
		offset = add_number(tab, offset);
	if(special_char_option)
		offset = add_special_char(tab, offset);
	if(uppercase_option)
		offset = add_uppercase(tab, offset);
	if(lowercase_option)
		offset = add_lowercase(tab, offset);

	shuffle_tab(tab);
}

int main() {
	int i;
	int random_number;
	
	srand(time(NULL));

	number_of_char = calcul_number_of_char();
	tab_of_char = malloc(number_of_char * sizeof(char));

	init_tab_of_char(tab_of_char);

	char* password = malloc(password_length * sizeof(char));
	
	do {
		for(i=0;i<password_length;i++) {
			random_number = rand()%number_of_char;
			password[i] = tab_of_char[random_number];
		}		
	} while(!is_approve_password(password));
	
	print_password(password);	
	return EXIT_SUCCESS;
}
