#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

/*Global Variables */
int row = 24;
int col = 80;
int k = 0, i,j;
int life = 1;
int death = 0;
int grid[24][80];
int temp[24][80]; // new array for the world when it gets updated.

void draw();


/*
checks if the cell is alive or dead,
  and or if has neighbor */
int main(int argc,char *argv[]){

  int input,input2;



   printf("%d\n", k++);
   // makes the first world.
  for (j = 0; j < row; j++) {
    for (i = 0; i < col; i++) {

      grid[j][i] = death;
      temp[j][i] = death;

      printf("%d",grid[j][i]);
    }
    printf("\n");
   }

  /*Takes in the User Input*/
  // does not take double digits... when coppied
  for(i =1; i < argc; i+=2){
    input = atoi(argv[i]);
    input2 = atoi(argv[i+1]);
    grid[input2][input] = life;
  }
  draw();

  return 0;
}

void draw(){
   while(1){
    printf("%d\n", k++);
  // Check, if cells around are alive.
    /*Attempt to create life...*/
    // issue here is that the count is at 180, and it is going out of bounds.


    for(j = 0; j < row; j++){
      for(i = 0; i < col; i++){
	// count is neighbors ** IMPORTANT**
	   int count = 0;

	   int j1=( j-1)%24, i1= (i-1)%80,j2=(j+1)%24 ,i2=(i+1)%80;

	   /*counting the neighbors*/
	     	count =grid[j2][i]
		  +grid[j2][i2]
		  +grid[j2][i1]
		  +grid[j][i2]

		  +grid[j][i1]
		  +grid[j1][i1]
		  +grid[j1][i2]
		  +grid[j1][i];


		/*rules For the Game*/
		if(grid[j][i] == life && (count == 0 || count == 1)){
		  temp[j][i] = death;
		}
		else if(grid[j][i]==life &&(count ==2 || count ==3)){
		  temp[j][i] = life;
		}
		else if(grid[j][i] == life &&  count >= 4){
		  temp[j][i] = death;
		}
		else if(grid[j][i] == death && count == 3){
		  temp[j][i] = life;
		}

      }

    }


    for(j = 0; j <row ; j++){
      for(i = 0; i <col ; i++){
	 printf("%d", grid[j][i]);
      }
      printf("\n");
    }
    //copy the array grid(old) to array temp(new)
    /*Attempt to copy the Array's*/

    for(j = 0; j < row ; j++){
      for(i= 0; i < col ; i++){
	  grid[j][i] = temp[j][i];
      }
    }//increased/decrease(when testing) by 2 threes
    usleep(83333);
  }

}
