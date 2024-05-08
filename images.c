//Authors: Chris Aboujaoude & Maurice Davis-Batton
//Date Due: May 7th, 2024
//Purpose: Erinstagram!

#include <stdio.h>
//use these macros for 2D array max sizes
#define ROWMAX 21
#define COLMAX 21

//function prototypes to go here
void loadImage(char *fiel, char numDump[][COLMAX], int* rowsPtr, int* colsPtr);
void displayImage(char numDump[][COLMAX], int rows, int cols);
void cropImage(char numDump[][COLMAX], int rows, int cols);
void dimImage(char numDump[][COLMAX], int rows, int cols);
void brightenImage(char numDump[][COLMAX], int rows, int cols);
void saveImage(char *feil, char numDump[][COLMAX], int rows, int cols);

//universal check to see if loadImage was used
int imageExists = 0;

int main(){

	int mainMenuChoice, editMenuChoice;
	char saveChoice;
	char imageArray[ROWMAX][COLMAX] = {'\0'};
	//makes any dead space in a file not fitting the max nonexistent
	char fileName[50], newFile[50];
	//string to read user input for file
	int rowsMain, colsMain;
	
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
			
			loadImage(fileName, imageArray, &rowsMain, &colsMain);
			break;
			
			case 2:
			if(imageExists != 1){
				printf("\nCan't display anything if there's nothing to display!\n");
				//checks to see if loadImage was used
			}
			else{
			displayImage(imageArray, rowsMain, colsMain);
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
				cropImage(imageArray, rowsMain, colsMain);
				break;
				
				case 2:
				dimImage(imageArray, rowsMain, colsMain);
				break;
				
				case 3:
				brightenImage(imageArray, rowsMain, colsMain);
				break;
				
				case 0:
				break;
				
				default:
				printf("\nThat wasn't a valid input. Returning to main menu.\n");
				break;
			}
			printf("Would you like to save your new image?(Y/N): ");
				scanf(" %c", &saveChoice);
				if(saveChoice == 'Y' || 'y'){
					printf("\nEnter your image's name (include the extension): ");
					scanf("%s", newFile);
					saveImage(newFile, imageArray, rowsMain, colsMain);
				}
			break;
			}
			
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
void loadImage(char *fiel, char numDump[][COLMAX], int* rowsPtr, int* colsPtr){
	FILE *flie = fopen(fiel, "r");
	int rows = 0;
	int cols = 0;
	int colsMax = 0;
	
	if(flie == NULL){
		printf("\nThat file doesn't exist. Did you include the extension?\n");
		return;
	}
	printf("\n");
	while(fscanf(flie, "%c", &numDump[rows][cols]) == 1){
		if(numDump[rows][cols] == '\n'){
			rows++;
			if(cols > colsMax){
				colsMax = cols;
			}
			cols = 0;
		}
		else{
			cols++;
		}
	}
	*rowsPtr = rows;
	*colsPtr = colsMax;
	
	printf("\nFile found! Open sesame!\n");
	imageExists = 1;
	//this is a workaround bool, changes only if file exists
	
	fclose(flie);
}

void displayImage(char numDump[][COLMAX], int rows, int cols){
	printf("\n");
	for(int x = 0; x < rows; x++){
		for(int y = 0; y < cols; y++){
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

void cropImage(char numDump[][COLMAX], int rows, int cols){
	int rowTop;
	int rowBot;
	int colLeft;
	int colRight;

	printf("\nWhat would you like the top row to be? (from 1 to %d): ", rows);
	scanf("%d", &rowTop);
	while(rowTop > rows || rowTop < 1){
		printf("You're not adding to the image, try again: ");
		scanf("%d", &rowTop);
	}
	printf("What would you like the bottom row to be? (from %d to %d): ", rowTop, rows);
	scanf("%d", &rowBot);
	while(rowBot > rows || rowBot < 1){
		printf("You're not adding to the image, try again: ");
		scanf("%d", &rowBot);
	}
	printf("What would you like the left column to be? (from 1 to %d): ", cols);
	scanf("%d", &colLeft);
	while(rowTop > cols || colLeft < 1){
		printf("You're not adding to the image, try again: ");
		scanf("%d", &colLeft);
	}
	printf("What would you like the right column to be? (from %d to %d): ", colLeft, cols);
	scanf("%d", &colRight);
	while(rowTop > cols || colRight < 1){
		printf("You're not adding to the image, try again: ");
		scanf("%d", &colRight);
	}
	printf("\n");
	
	for(int x = rowTop - 1; x < rowBot; x++){
		for(int y = colLeft - 1; y < colRight; y++){
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

void dimImage(char numDump[][COLMAX], int rows, int cols){
	for(int x = 0; x < rows; x++){
		for(int y = 0; y < cols; y++){
			switch(numDump[x][y]){
				case '4': 
				printf("O");
				break;
				
				case '3':
				printf("o");
				break;
				
				case '2':
				printf(".");
				break;
				
				case '1':
				printf(" ");
				break;
				
				case '0':
				printf(" ");
				break;
			}
		}
		printf("\n");
	}
}

void brightenImage(char numDump[][COLMAX], int rows, int cols){
	for(int x = 0; x < rows; x++){
		for(int y = 0; y < cols; y++){
			switch(numDump[x][y]){
				case '4': 
				printf("0");
				break;
				
				case '3':
				printf("0");
				break;
				
				case '2':
				printf("O");
				break;
				
				case '1':
				printf("o");
				break;
				
				case '0':
				printf(".");
				break;
			}
		}
		printf("\n");
	}
}

void saveImage(char *feil, char numDump[][COLMAX], int rows, int cols){
	FILE *foil = fopen(feil, "w");
	if(foil == NULL){
		printf("Let me get my glasses because I can't seem to find this file.");
		return;
	}
	for(int x = 0; x < rows; x++){
		for(int y = 0; y < cols; y++){
			fprintf(foil, "%c", numDump[x][y]);
		}
		fprintf(foil, "\n");
	}
	fclose(foil);
}

