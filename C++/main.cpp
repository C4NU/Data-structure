#include <iostream>

using namespace std;

class Matrix
{
    int matrix[8][8];
public:
    Matrix();
    int mostOnes();
};

Matrix::Matrix()
{
    for(int i=0; i<7; i++)
    {
        for(int j=0; j<7; j++)
        {
            cin>>matrix[i][j];
        }
    }
}

int Matrix::mostOnes()
{
    int max = 0;
    
    for(int i=0; i<7; i++)
    {
        for(int j=0; j<7; j++)
        {
            if(matrix[i][j+1] == 0)
                max = j;
            break;
        }
    }
    
    return max;
}


int main()
{
    Matrix M;
    
    cout<<M.mostOnes();
}
