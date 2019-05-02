#include "LLL.h"
#include <math.h>

Matrix& GramSchmidt(Matrix& M)
{
    for(int i=0; i<M.getLength(); i++)
    {
        Array_Vector v(M[i]);
        for(int j=0; j<i; j++)
        {
            v = v - (M[j] * (M[j]*M[i] / int( sqrt(M[j].norm()))));
        }
        M[i] = v;
    }
    return M;
}


Matrix& LLL(Matrix& M, float delta)
{
    Matrix ortho = GramSchmidt(M);
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

int main()
{
	int len, wid, tmp;
	cin >> len;
	cin >> wid;
	Matrix mat(len, wid);
	for (int i = 0; i < len; i++)
		for (int j = 0; j < wid; j++)
		{
			cin >> tmp;
			mat[i].set(j, tmp);
		}

	cout << mat;
	cout << "det=";
	cout << mat.deter();
	cout << "\n";
	mat = LLL(mat, 0.75);
	cout << mat;
	cout << "det=";
	cout << mat.deter();
	cout << "\n";
	cin >> tmp;
	return 0;
}
