#include "LLL.h"
#include <math.h>


template <typename T>
Matrix<T>& GramSchmidt(Matrix<T>& M)
{
    for(int i=0; i<M.getWidth(); i++)
    {
        Array_Vector<T> v(M[i]);
        cout << "i = " << i << "and v= " << v;
        for(int j=0; j<i; j++)
        {
            if(i==2 && j==1)
            {
                cout << M;
                cout << M[i] << "\n" << M[j] << "\n" << M[i]*M[j] << endl;
                cout << "V = " << v;
                cout << v - (M[j] * (M[j]*M[i] / M[j].get_norm_squared()));
            }
            v = v - (M[j] * (M[j]*M[i] / M[j].get_norm_squared()));
            if(i==2 && j==0)
                cout << v;
            //cout << "i = " << i << ", j = " << j << "\n" << M ;
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
            if((M[k]*ortho[j])/ ortho[j].get_norm_squared() > 0.5)
            {
                M[k] = M[k] - M[j]*((M[k]*ortho[j])/ ortho[j].get_norm_squared());
                ortho = GramSchmidt(M);
            }
        }
        if(ortho[k].get_norm_squared() >= (delta - (M[k]*ortho[k-1]/ortho[k-1].get_norm_squared())*(M[k]*ortho[k-1]/ortho[k-1].get_norm_squared()))*(ortho[k-1].get_norm_squared()))
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

