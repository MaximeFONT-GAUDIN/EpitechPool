int my_strlen(char const *str)
{
    int i = 0;
    
    for (; str[i] != 0; i++);
    return (i);
}

int main(void)
{
    return (my_strlen("il y a 37 caractere dans cette phrase"));
}