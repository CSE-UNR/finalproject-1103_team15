//Authors: Chris Aboujaoude & Maurice Davis-Batton
//Date Due: May 7th, 2024
//Purpose: Erinstagram!

#include <stdio.h>
//use these macros for 2D array max sizes
#define ROWMAX 30
#define COLMAX 30

//function prototypes to go here
void loadImage(char *fiel, int numDump[][COLMAX]);
void displayImage(int numDump[][COLMAX]);
void cropImage();
void dimImage();
void brightenImage();
void saveImage();

//universal check to see if loadImage was used
int imageExists = 0;

int main(){

	int mainMenuChoice, 
	imageArray[ROWMAX][COLMAX] = {0};
	//image array set to 0 to stop junk values from printing
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
			//loads the file, but prints a 30x30 array of zeros instead
			break;
			
			case 2:
			if(imageExists != 1){
				printf("\nCan't display anything if there's nothing to display!\n");
				//checks to see if loadImage was used
			}
			else{
			displayImage(imageArray);
			//displays loaded file on the front end of 30x30 array of zeros, don't know why
			}
			break;
			
			case 3:
			//probably a function for another menu, leading to editing
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
void loadImage(char *fiel, int numDump[][COLMAX]){
	FILE *flie = fopen(fiel, "r");
	
	if(flie == NULL){
		printf("\nThat file doesn't exist. Did you include the extension?\n");
		return;
	}
	
	for(int x = 0; x < ROWMAX; x++){
		for(int y = 0; y < COLMAX; y++){
			fscanf(flie, "%d", &numDump[x][y]);
		}
	}
	printf("\nFile found! Open sesame!\n");
	imageExists = 1;
	//this is a workaround bool, changes only if file exists
	
	fclose(flie);
}

void displayImage(int numDump[][COLMAX]){
	for(int x = 0; x < ROWMAX; x++){
		for(int y = 0; y < COLMAX; y++){
			printf("%d", numDump[x][y]);
		}
		printf("\n");
	}
}

void cropImage(){

}

void dimImage(){

}

void brightenImage(){

}

void saveImage(){

}

