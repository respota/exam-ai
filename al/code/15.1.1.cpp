#include <iostream>
using namespace std;
int memorizedCutRodAux(int p[], int n, int r[])
{
    int q;//�������ֵ
    if (r[n] >= 0)
        return r[n];//�������ֵ�Ƿ���֪
    if (n == 0)
        q = 0;//n=0ʱ����������
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
    cout << "���������Զ����·�������������ֵΪ��" << q;
    return 0;
}
