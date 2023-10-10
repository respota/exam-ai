#include <iostream>
using namespace std;
int memorizedCutRodAux(int p[], int n, int r[])
{
    int q;//最大收益值
    if (r[n] >= 0)
        return r[n];//检查所需值是否已知
    if (n == 0)
        q = 0;//n=0时不会有收益
    else
    {
        q = -1;
        for (int i = 0; i < n; ++i)
            q = max(q, p[i] + memorizedCutRodAux(p, n - i - 1, r));
    }
    r[n] = q;
    return q;
}

int memorizedCutRod(int p[], int n)
{
    int *r = new int(n+1);
    for (int i = 0; i <= n; ++i)
        r[i] = -1;
    return memorizedCutRodAux(p, n, r);
}

int main()
{
    int p[10] = { 1,5,8,9,10,17,17,20,24,30 };
    int q = memorizedCutRod(p, 4);
    cout << "带备忘的自顶向下方法的最优收益值为：" << q;
    return 0;
}
