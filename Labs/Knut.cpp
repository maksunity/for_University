#include <iostream>
#include <string>

using namespace std;

// простой поиск образца в строке
// возвращает индекс начала образца в строке или -1, если не найден
int find(char *example, char *str)
{
    // i-с какого места строки  ищем
    // j-с какого места образца ищем
    for (int i = 0; str[i]; ++i)
    {
        for (int j = 0;; ++j)
        {
            if (!example[j])
                return i; // образец найден
            if (str[i + j] != example[j])
                break;
        }
        // пока не найден, продолжим внешний цикл
    }
    // образца нет
    return -1;
}


bool KMP(string str, string obr)
{
	int i, j, k;
	bool res = 0;
	int d = str.size();
	int e = obr.size();
    
	j = 0;
	k = -1;

	int *pf = new int[1000];
	pf[0] = -1;
	while (j < e-1)
	{
		while (k >= 0 && obr[j] != obr[k])
			k = pf[k];
		j++;
		k++;
		if (obr[j] == obr[k])
			pf[j] = pf[k];
		else
			pf[j] = k;
	}
	i = 0;
	j = 0;
	while (j < e && i < d)
	{
		while (j >= 0 && str[i] != obr[j])
			j = pf[j];
		i++;
		j++;
	}
	delete[] pf;
	if (j == e)
		res = 1;
	return res;
}