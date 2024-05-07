//Authors: Chris Aboujaoude & Maurice Davis-Batton
//Date Due: May 7th, 2024
//Purpose: Erinstagram!

#include <stdio.h>
//use these macros for 2D array max sizes
#define ROWMAX 21
#define COLMAX 21

//function prototypes to go here
void loadImage(char *fiel, char numDump[][COLMAX]);
void displayImage(char numDump[][COLMAX]);
void cropImage();
void dimImage(char numDump[][COLMAX]);
void brightenImage(char numDump[][COLMAX]);
void saveImage();

//universal check to see if loadImage was used
int imageExists = 0;

int main(){

	int mainMenuChoice, editMenuChoice; 
	char imageArray[ROWMAX][COLMAX] = {'\0'};
	//makes any dead space in a file not fitting the max nonexistent
	char fileName[50];
	//string to read user input for file
	
	do{
		printf("\nI Can't Believe It's Not Adobe!\n");
		printf("1: Load Image\n");
		printf("2: Display Image\n");
		printf("3: Edit Image\n");
		printf("0: Exit\n\n");
		printf("Select one of the above options: ");
		scanf("%d", &mainMenuChoice);
		
		switch(mainMenuChoice){
			case 1:
			printf("\nPlease input the name of the image (text) file: ");
			scanf("%s", fileName);
			
			loadImage(fileName, imageArray);
			break;
			
			case 2:
			if(imageExists != 1){
				printf("\nCan't display anything if there's nothing to display!\n");
				//checks to see if loadImage was used
			}
			else{
			displayImage(imageArray);
			}
			break;
			
			case 3:
			if(imageExists != 1){
				printf("\nCan't edit anything if there's nothing to edit!\n");
				//another loadImage checkpoint
			}
			else{
			printf("\nEDITING MENU\n");
			printf("1: Crop Image\n");
			printf("2: Dim Image\n");
			printf("3: Brighten Image\n");
			printf("0: Return\n\n");
			printf("Select one of the above options: ");
			scanf("%d", &editMenuChoice);
			
			switch(editMenuChoice){
				case 1:
				printf("In progress");
				break;
				
				case 2:
				dimImage(imageArray);
				displayImage(imageArray);
				break;
				
				case 3:
				brightenImage(imageArray);
				displayImage(imageArray);
				break;
				
				case 0:
				break;
				
				default:
				printf("\nThat wasn't a valid input. Returning to main menu.\n");
				break;
			}
			}
			break;
			
			case 0: 
			printf("\nAuf wiedersehen. (That means goodbye.)\n\n");
			break;
			
			default:
			printf("\nHmm, it appears that's an invalid input. You should try again.\n");
			break;
		}
		
	}while(mainMenuChoice != 0);

	return 0;
}

//function definitions to go here
void loadImage(char *fiel, char numDump[][COLMAX]){
	FILE *flie = fopen(fiel, "r");
	
	if(flie == NULL){
		printf("\nThat file doesn't exist. Did you include the extension?\n");
		return;
	}
	
	for(int x = 0; x < ROWMAX; x++){
		for(int y = 0; y < COLMAX; y++){
			fscanf(flie, "%c", &numDump[x][y]);
		}
	}
	printf("\nFile found! Open sesame!\n");
	imageExists = 1;
	//this is a workaround bool, changes only if file exists
	
	fclose(flie);
}

void displayImage(char numDump[][COLMAX]){
	for(int x = 0; x < ROWMAX; x++){
		for(int y = 0; y < COLMAX; y++){
			switch(numDump[x][y]){
				case '0':
				printf(" ");
				break;
				
				case '1':
				printf(".");
				break;
				
				case '2':
				printf("o");
				break;
				
				case '3':
				printf("O");
				break;
				
				case '4':
				printf("0");
				break;
			}
		}
		printf("\n");
	}
}

void cropImage(){

}

void dimImage(char numDump[][COLMAX]){
	for(int x = 0; x < ROWMAX; x++){
		for(int y = 0; y < COLMAX; y++){
			switch(numDump[x][y]){
				case '0':
				numDump[x][y] = 'O';
				break;
				
				case 'O':
				numDump[x][y] = 'o';
				break;
				
				case 'o':
				numDump[x][y] = '.';
				break;
				
				case '.':
				numDump[x][y] = ' ';
				break;
				
				case ' ':
				numDump[x][y] = ' ';
				break;
			}
		}
	}
}

void brightenImage(char numDump[][COLMAX]){
	for(int x = 0; x < ROWMAX; x++){
		for(int y = 0; y < COLMAX; y++){
			switch(numDump[x][y]){
				case ' ':
				numDump[x][y] = '.';
				break;
				
				case '.':
				numDump[x][y] = 'o';
				break;
				
				case 'o':
				numDump[x][y] = 'O';
				break;
				
				case 'O':
				numDump[x][y] = '0';
				break;
				
				case '0':
				numDump[x][y] = '0';
				break;
			}
		}
	}
}

void saveImage(){

}

