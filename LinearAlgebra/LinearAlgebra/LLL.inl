#include "LLL.h"
#include <math.h>


template <typename T>
Matrix<T> GramSchmidt(Matrix<T>& m)
{
    Matrix<T> M(m);
    for(int i=0; i<M.getWidth(); i++)
    {
        Array_Vector<T> v(M[i]);
        for(int j=0; j<i; j++)
        {
            v = v - (M[j] * (M[j]*M[i] / M[j].get_norm_squared()));
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
    while(k < M.getWidth())
    {
        for(int j = k-1; j>=0; j--)
        {
            if(abs(long((M[k]*ortho[j])))/ ortho[j].get_norm_squared() > 0.5) // added cast to long
            {
                M[k] = M[k] - M[j]*round(((M[k]*ortho[j])/ ortho[j].get_norm_squared()));
                ortho = GramSchmidt(M);
            }
        }
        if(ortho[k].get_norm_squared() >= (delta - (M[k]*ortho[k-1]/ortho[k-1].get_norm_squared())*(M[k]*ortho[k-1]/ortho[k-1].get_norm_squared()))*(ortho[k-1].get_norm_squared()))
            k++;
        else
        {
            M.swap(k, k-1);
            ortho = GramSchmidt(M);
            k = max(k-1, 1);
        }
        
    }
    return M;
    
}

