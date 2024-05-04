//Authors: Chris Aboujaoude & Maurice Davis-Batton
//Date Due: May 7th, 2024
//Purpose: Erinstagram!

#include <stdio.h>
//use these macros for 2D array max sizes
#define ROWMAX 50
#define COLMAX 50

//function prototypes to go here
void loadImage();
void displayImage();
void cropImage();
void dimImage();
void brightenImage();
void saveImage();

int main(){

	int mainMenuChoice;
	
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
			//function to open the file
			break;
			
			case 2:
			//should just actually display image, will be a function
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
void loadImage(){

}
void displayImage(){

}
void cropImage(){

}
void dimImage(){

}
void brightenImage(){

}
void saveImage(){

}

