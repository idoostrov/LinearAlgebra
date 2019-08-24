//
// Created by talth on 08/08/2019.
//

#include "LLL.h"

mpz_class mpz_round(mpq_class mpq)
{
    mpz_class num, den, tmp;
    num = mpq.get_num();
    den = mpq.get_den();
    tmp = num/den;
    if(mpq > tmp)
    {
        if(mpq - tmp < 0.5)
            return tmp;
        else
            return tmp + 1;
    }
    else
    {
        if(tmp - mpq < 0.5)
            return tmp;
        return tmp - 1;
    }
}

Matrix<mpz_class>& LLL(Matrix<mpz_class>& mat, float delta) {

    clock_t start = clock();

    Matrix<mpq_class> M(mat.getWidth(), mat.getLength());
    for (int i = 0; i < mat.getWidth(); ++i) {
        for (int j = 0; j < mat.getLength(); ++j) {
            M[i][j] = mat[i][j];
        }
    }

    clock_t after = clock();
    cout << "time for copying: " << (double(after - start) / CLOCKS_PER_SEC) << endl;


    Matrix<mpq_class> ortho(M);
    ortho = GramSchmidt(ortho);

    int k = 1;
    while (k < M.getWidth()) {
        for (int j = k - 1; j >= 0; j--) {
            if (ortho[j].get_norm_squared() != 0) {
                if (abs((M[k] * ortho[j])) / ortho[j].get_norm_squared() > 0.5) {
                    M[k] -= M[j] * mpz_round((M[k] * ortho[j]) / ortho[j].get_norm_squared());
//M[k] = M[k] - M[j]*((M[k]*ortho[j])/ ortho[j].get_norm_squared());
                    ortho = GramSchmidt(M);
                }
            }
        }
        if (ortho[k - 1].get_norm_squared() != 0) {
            if (ortho[k].get_norm_squared() >= (delta - (M[k] * ortho[k - 1] / ortho[k - 1].get_norm_squared()) *
                                                        (M[k] * ortho[k - 1] / ortho[k - 1].get_norm_squared())) *
                                               (ortho[k - 1].get_norm_squared()))
                k++;
            else {
                M.swap(k, k - 1);
                ortho = GramSchmidt(M);
                k = max(k - 1, 1);
            }
        } else
            k++;

    }

    clock_t after2 = clock();
    cout << "time for LLL: " << (double(after2 - after) / CLOCKS_PER_SEC) << endl;


    for (int i = 0; i < mat.getWidth(); ++i) {
        for (int j = 0; j < mat.getLength(); ++j) {
            mat[i][j] = M[i][j];
        }
    }

    clock_t after3 = clock();
    cout << "time for copying: " << (double(after3 - after2) / CLOCKS_PER_SEC) << endl;

    return mat;

}

