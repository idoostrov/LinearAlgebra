#include "LLL.h"
#include <math.h>

Matrix GramScmidt(Matrix M)
{(
    for(int i=0; i<M.wid; i++)
    {
        Array_Vector v = Matrix[i];
        for(int j=0; j<i; j++)
        {
            v = v - (M[j] * (M[j]*M[i] / int( sqrt(M[j].norm()))));
        }
        m[i] = v;
    }
    return M;
}


Matrix LLL(Matrix M, float delta)
{
    Matrix ortho = GramScmidt(M);
    int k = 1;
    while(k <= M.wid)
    {
        for(int j = k-1; j>=0; j--)
        {
            if((M[k]*ortho[j])/ ortho[j].norm() > 0.5)
            {
                M[k] = M[k] - M[j]*((M[k]*ortho[j])/ ortho[j].norm());
                ortho = GramScmidt(M);
            }
        }
        if(ortho[k].norm() >= (delta - (M[k]*ortho[k-1]/ortho[k-1].norm())*(M[k]*ortho[k-1]/ortho[k-1].norm()))*(ortho[k-1].norm()))
            k++;
        else
        {
            M.swap(k, k-1);
            ortho = GramScmidt(M);
            if(k < 1)
                k= 1;
        }
        
    }


    return M;
    
}