#include <stdio.h>
// max line length
#define MAXLINE 1000

int getaline();
void copy();
void printer();

main()
{
// initalize variables
int len;
int max;
char line[MAXLINE];
char longest[MAXLINE];
printf("[User presses Ctrl-D to send EOF]\n");

// length of longest line stored here
max = 0;

// while the length of the line is greater than 0

while ((len = getaline(line, MAXLINE)) > 0)

if (len > max){

max = len;

// copy the line
copy (longest, line);

}

if (max > 0)
printer(longest);
printf("Modified Longest Line: %s", longest);

return 0;

}

// This function prints the longest string with X's for vowels

void printer(char to[]){

int i;

i = 0;

// while not at the last element of array

while (to[i] != '\0')
// check if current array element is a vowel
switch (to[i]){
// if it is a vowel

case 'a': case'i': case'e': case'o': case 'u':
case 'A': case 'I': case'E': case 'O': case 'U':
// replace the value with 'X'
to[i] = 'X';

i++;
break;

// If the element is a constant, break

default:
i++;
break;
}

}

//getaline: read a line into s, return length
int getaline(char s[], int lim)

{
int c, i;
for (i=0; i < lim-1 && (c=getchar()) != EOF && c!='\n'; ++i)
s[i] = c;
if (c == '\n'){
s[i] = c;
++i;

}
s[i] = '\0';
return i;

}

// copy 'from' into 'to'; assuming to is big enough

void copy(char to[], char from[])
{

int i;
i = 0;
// while not last element, copy the element to to from

while ((to[i] = from[i]) != '\0')

++i;

}
