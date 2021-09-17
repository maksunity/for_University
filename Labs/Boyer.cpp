bool Boer_Moor(string str)
{
    string key;
    int str_size = str.size();
    int key_size = key.size();
    if (str_size != 0 && key_size != 0 && str_size > key_size)
    {
        int i, pos;
        int arr[256];
        for (i = 0; i < 256; i++)
        {
            arr[i] = key_size;
        }
        for (i = key_size - 1; i >= 0; i--)
        {
            if (arr[(short)(key[i])] == key_size)
            {
                arr[(short)(key[i])] = key_size - i - 1;
            }
        }
        pos = key_size - 1;
        while (pos < str_size)
            if (key[key_size - 1] != str_size[pos])
            {
                pos = pos + arr[(short)(str_size[pos])];
            }
            else
            {
                for (i = key_size - 2; i >= 0; i--)
                {
                    if (key[i] != str_size[pos - key_size + i + 1])
                    {
                        pos += arr[(short)(str_size[pos - key_size + i + 1])] - 1;
                        break;
                    }
                    else if (i == 0)
                    {
                        return true;
                    }
                }
            }
    }
    return false;
}