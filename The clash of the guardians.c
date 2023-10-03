#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 50


// Define Player structure
struct Player{
	char name [N];
	int  hp; //hp = health points
};
// Define Card structure 
struct Card{
	char name[N];
	char type[N];
	int  hp; //hp = health points
	int  attack;
	int  defense;
};
// Define History structure
struct History{
	
};


int main(){
	
	FILE *file;
	
	file = fopen("Cards.txt", "r");
	
	if (file == NULL){
		perror("Error opening file.\n");
		return 1;
	}
	
	struct Card cards[100];
	
	int read = 0;
	int records = 0;
	do
	{
		read = fscanf(file,
					  "%49[^,],%49[^,],%d,%d,%d",
					  cards[records].name,
					  cards[records].type,
					  &cards[records].hp,
					  &cards[records].attack,
					  &cards[records].defense);
					  
		if (read == 5){
			records++;
		}
		if (read != 5 && !feof(file)){
			printf("File format incorrect.\n");
			return 1;
		}
		if (ferror(file)){
			printf("Error reading file.\n");
			return 1;
		}
					  
	}while(!feof(file)); //read the file until the end is reached
	
	fclose(file);
	
	printf("\n%d records read.\n",records);
	
	for (int i = 0;i < records; i++){
		printf("%s,%s,%d,%d,%d",
			   cards[i].name,
			   cards[i].type,
			   cards[i].hp,
			   cards[i].attack,
			   cards[i].defense);	
	}
	
	return 0;
}
