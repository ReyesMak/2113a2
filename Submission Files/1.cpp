//Include the necessary libraries
#include <iostream>

//Declare maximum dimension in the matrix
const int MAXDIM = 10;


using namespace std;

//Function to read user's input of matrix
void read_matrix(int matrix[][MAXDIM] ,int &dim){
  cin >> dim;
  for (int row=0; row<dim ; ++row){
  	for (int col=0; col<dim; ++col){
        //Store user's integer input of the matrix into a 2D array
        cin >> matrix[row][col];
    }
  }
}

//Function to display the processed matrix
void display_inner_cw_rotated(int matrix[][MAXDIM] ,int dim){
  //Both the numbers of displayed column and row decrease by 2
  //Display the inverted matrix firstly by incrementing the column from 1 to dim-2
  for (int col=1; col<dim-1; ++col){
    //Display the inverted matrix secondly by decrementing row from dim-2 to 1
    for (int row=dim-2; row>0; --row){
      cout << matrix[row][col] << " ";
      //Display an additional line when the display of the inverted matrix is completed
      if (row==1){
        cout << endl;
      }
    }
  }
}

//Main function
int main()
{
  //Declare the 2D array with the size of {MAXDIM} x {MAXDIM}
  int matrix[MAXDIM][MAXDIM]{};
  //Declare an integer storing the value of the dimension of the matrix
  int dim = 0;
  //Call read_matrix function and pass {dim} and {matrix} by reference
  read_matrix(matrix, dim);
  //Call display_inner_cw_rotated function and pass {dim} and {matrix} by reference
  display_inner_cw_rotated(matrix, dim);
  return 0;
}
