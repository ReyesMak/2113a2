#include <iostream>

const int MAXDIM = 10;

//------DO NOT CHANGE ANYTHING ABOVE THIS LINE-------

using namespace std;

void read_matrix(int matrix[][MAXDIM] ,int &dim){
  cin >> dim;
  for (int row=0 ; row<dim ; ++row){
    for (int col=0; col<dim ; ++col){
        cin >> matrix[row][col];
    }
  }
}

void display_inner_cw_rotated(int matrix[][MAXDIM] ,int dim){
  for (int col=1; col<dim-1; ++col){
    for (int row=dim-2; row>0; --row){
      cout << matrix[row][col] << " ";
      if (row==1){
        cout << endl;
      }
    }
  }
}

//------DO NOT CHANGE ANYTHING BELOW THIS LINE-------

int main()
{
  int matrix[MAXDIM][MAXDIM]{};
  int dim = 0;

  read_matrix(matrix, dim);
  display_inner_cw_rotated(matrix, dim);
  return 0;
}
