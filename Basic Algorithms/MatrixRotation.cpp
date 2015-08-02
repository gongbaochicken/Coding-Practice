/*Matrix Rotation

For this problem, you will be writing a program which 
performs a 90 degree clockwise rotation of a 10x10 matrix.
There is nothing special about a 10x10 matrix---I just need
to fix the matrix size, since we have not learned about dynamic
memory allocation yet, so we do not have the knowledge needed
to read in any size of matrix.

To keep the input processing simple, the matrix will be a matrix
of characters (so you will have something like
  char matrix[10][10]
in your program), which will be read from a file.  Each line
in the input file should contain 10 characters (plus a newline).

Requirements:
=============
  - Your program will take one command line argument, a string
    specifying the input file to read.
  - The input file should contain 10 lines, each of which
    have 10 (non-newline) characters (plus a newline).
  - Your program should then rotate this 90 degrees clockwise,
    and print the result on stdout.
    Note that sample.txt provides sample input, and 
    sample.out provides sample output.
  - If there are any errors, your program should print an
    appropriate message to stderr, and exit with EXIT_FAILURE.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


void rotation(FILE* f, char mat[][10]){
  char a[10][10];
  for(int i = 0; i< 10; i++){
    int j = 0;
    while((a[i][j] = fgetc(f)) != '\n'){
  j++;
    }
    for(int i = 0; i < 10; i++){
      for(int j = 0; j < 10; j++){
  mat[i][j] = a[9-j][i];
  mat[9-j][i] = a[9-i][9-j];
  mat[9-i][9-j] = a[j][9-i];
  mat[j][9-i] = a[i][j];
      }
    }
  }
}
 
int main(int argc, char ** argv){
    char mat[10][10];
    if(argc != 2){
      fprintf(stderr, "Please input correctly: give the fileName.\n");
    }
    FILE *f = fopen(argv[1], "r");
    if(f == NULL){
      perror("Cloud not  open the file\n");
      return EXIT_FAILURE;
    }
    rotation(f, mat);
    for(int i = 0; i < 10; i++){
      for(int j = 0; j < 10; j++){
  printf("%c", mat[i][j]);
      }
      printf("\n");
    }
    if(fclose(f) != 0){
      perror("Cloud not close the file.");
      return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
 }    









