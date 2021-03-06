/* 1953609 软件 王灏廷 */

#include <cstdio>   //NULL
//不再允许包含任何系统头文件

/* ----- 不允许定义任何形式的全局变量/全部数组/只读全局变量/宏定义!!!!! ----- */

/* 函数实现部分，{ }内的东西可以任意调整，目前的return只是一个示例，可改变 */
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strlen(const char *str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int i = 0;
    if (str == NULL)
        return 0;
    for (; *str != '\0'; str++, i++)
        ;
    return i;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strcat(char *s1, const char *s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    char* p = s1;
    if (s1 == NULL)
        return p;
    for (; *s1 != '\0'; s1++)
        ;
    if (s2 == NULL)
        return p;
    for (; *s2 != '\0'; s1++, s2++)
    {
        *s1 = *s2;
    }    
    *s1 = *s2;
    return p;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strncat(char *s1, const char *s2, const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    char* p = s1;
    int i = len;
    if (s1 == NULL)
        return p;
    for (; *s1 != '\0'; s1++)
        ;
    if (s2 == NULL)
        return p;
    for (; i>0&& *s2 != '\0'; s1++, s2++,i--)
    {
        *s1 = *s2;
    }
    *s1 = '\0';
    return p;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strcpy(char *s1, const char *s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    char* p = s1;
    if (s1 == NULL)
        return p;
    if (s2 == NULL)
    {
        *s1 = '\0';
        return p;
    }
    for (; *s2 != '\0'; s1++, s2++)
    {
        *s1 = *s2;
    }
    *s1 = *s2;
    return p;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strncpy(char *s1, const char *s2, const int len)
{
    char* p = s1;
    int i = len;
    if (s1 == NULL)
        return p;
    if (s2 == NULL)
        return p;
    for (; i > 0 && *s2 != '\0'; i--, s1++, s2++)
    {
        *s1 = *s2;
    }
    return p;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcmp(const char *s1, const char *s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (s1 == NULL&& s2 != NULL)
        return -1;
    if (s2 == NULL&&s1!= NULL)
        return 1;
    if (s1 == NULL && s2 == NULL)
        return 0;
    for (; *s1 != '\0' || *s2 != '\0'; s1++, s2++)
    {
        if (*s1 != *s2)
            return *s1 - *s2;
    }
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcasecmp(const char *s1, const char *s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (s1 == NULL && s2 != NULL)
        return -1;
    if (s2 == NULL && s1 != NULL)
        return 1;
    if (s1 == NULL && s2 == NULL)
        return 0;
    for (; *s1 != '\0' || *s2 != '\0'; s1++,s2++)
    {
        if (*s1 != *s2)
        {
            if (*s1 >= 'a' && *s1 <= 'z' && *s1 - *s2 == 32)
                continue;
            else if (*s1 >= 'A' && *s1 <= 'Z' && *s1 - *s2 == -32)
                continue;
            else
            {
                if (*s1 >= 'A' && *s1 <= 'Z')
                    return *s1 - *s2 + 32;
                else if (*s2 >= 'A' && *s2 <= 'Z')
                    return *s1 - *s2 - 32;
                else
                    return *s1 - *s2;
            }
        }
    }
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strncmp(const char *s1, const char *s2, const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int i = len;
    if (s1 == NULL && s2 != NULL)
        return -1;
    if (s2 == NULL && s1 != NULL)
        return 1;
    if (s1 == NULL && s2 == NULL)
        return 0;
    for (; (*s1 != '\0' || *s2 != '\0')&&i>0;i--,s1++, s2++)
    {
        if (*s1 != *s2)
            return *s1 - *s2;
    }
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcasencmp(const char *s1, const char *s2, const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int i = len;
    if (s1 == NULL && s2 != NULL)
        return -1;
    if (s2 == NULL && s1 != NULL)
        return 1;
    if (s1 == NULL && s2 == NULL)
        return 0;
    for (; (*s1 != '\0' || *s2 != '\0') && i > 0; i--, s1++, s2++)
    {
        if (*s1 != *s2)
        {
            if (*s1 >= 'a' && *s1 <= 'z' && *s1 - *s2 == 32)
                continue;
            else if (*s1 >= 'A' && *s1 <= 'Z' && *s1 - *s2 == -32)
                continue;
            else
            {
                if (*s1 >= 'A' && *s1 <= 'Z')
                    return *s1 - *s2 + 32;
                else if (*s2 >= 'A' && *s2 <= 'Z')
                    return *s1 - *s2 - 32;
                else
                    return *s1 - *s2;
            }
        }
    }
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strupr(char *str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    char* p = str;
    if (str == NULL)
        return p;
    for (; *str != '\0'; str++)
    {
        if (*str >= 'a' && *str <= 'z')
            *str -= 32;
    }
    return p;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strlwr(char *str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    char* p = str;
    if (str == NULL)
        return p;
    for (; *str != '\0'; str++)
    {
        if (*str >= 'A' && *str <= 'Z')
            *str += 32;
    }
    return p;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strchr(const char *str, const char ch)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == NULL)
        return 0;
    for (int i = 1; *str != '\0'; str++, i++)
    {
        if (*str == ch)
            return i;
    }
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strstr(const char *str, const char *substr)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int tag = -1;
    if (str == NULL || substr == NULL)
        return 0;
    if (tj_strlen(substr) > tj_strlen(str))
        return 0;
    for (int i = 1;*str != '\0'&&*substr != '\0'; str++,i++)
    {
        if (*str == *substr)
        {
            for (int j = 0;*str != '\0' && *substr != '\0'; substr++,str++,j++)
            {
                if (*str!= *substr)
                {
                    substr -= j;
                    str -= j;
                    tag = 1;
                    break;
                }
            }
            if (tag == -1)
                return i;
            else
                tag = -1;
        }
    }
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrchr(const char *str, const char ch)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == NULL)
        return 0;
    int len = tj_strlen(str);
    str += tj_strlen(str)-1;
    for (int i = 0; i < len; i++, str--)
    {
        if (*str == ch)
            return len - i;
    }
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrstr(const char *str, const char *substr)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int tag = -1;
    if (str == NULL || substr == NULL)
        return 0;
    if (tj_strlen(substr) > tj_strlen(str))
        return 0;
    int len = tj_strlen(str);
    str += tj_strlen(str) - 1;
    for (int i = 0; i < len; i++, str--)
    {
        if (*str == *substr)
        {
            for (int j = 0; *str != '\0' && *substr != '\0'; substr++, str++, j++)
            {
                if (*str != *substr)
                {
                    substr -= j;
                    str -= j;
                    tag = 1;
                    break;
                }
            }
            if (tag == -1)
                return len - i;
            else
                tag = -1;
        }
    }
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strrev(char* str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == NULL)
        return NULL;
    char* t = str, * p = str;
    char tmp;
    t += tj_strlen(str) - 1;
    for (; str < t; str++, t--)
    {
        tmp = *str;
        *str = *t;
        *t = tmp;
    }
    return p;
}
