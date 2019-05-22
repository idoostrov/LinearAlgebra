#include "LLL.h"
#include <math.h>


template <typename T>
Matrix<T>& GramSchmidt(Matrix<T>& M)
{
    for(int i=0; i<M.getLength(); i++)
    {
        Array_Vector<T> v(M[i]);
        for(int j=0; j<i; j++)
        {
            v = v - (M[j] * (M[j]*M[i] / int( sqrt(M[j].norm()))));
        }
        M[i] = v;
    }
    return M;
}

template <typename T>
Matrix<T>& LLL(Matrix<T>& M, float delta)
{
    Matrix<T> ortho = GramSchmidt(M);
    int k = 1;
    while(k < M.getLength())
    {
        for(int j = k-1; j>=0; j--)
        {
            if((M[k]*ortho[j])/ ortho[j].norm() > 0.5)
            {
                M[k] = M[k] - M[j]*((M[k]*ortho[j])/ ortho[j].norm());
                ortho = GramSchmidt(M);
            }
        }
        if(ortho[k].norm() >= (delta - (M[k]*ortho[k-1]/ortho[k-1].norm())*(M[k]*ortho[k-1]/ortho[k-1].norm()))*(ortho[k-1].norm()))
            k++;
        else
        {
            M.swap(k, k-1);
            ortho = GramSchmidt(M);
            if(k < 1)
                k= 1;
        }
        
    }


    return M;
    
}

