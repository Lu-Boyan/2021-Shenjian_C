/*1953609 Èí¼ş Íõå°Í¢*/
#include <iostream>
using namespace std;
int tj_strlen(const char str[])
{
	int i;
	for (i = 0; str[i] != '\0'; i++)
		;
	return i;
}
int tj_strcat(char s1[], const char s2[])
{
	int k=tj_strlen(s1);
	int j = 0;
	for (; s2[j] != '\0'; k++,j++)
	{
		s1[k] = s2[j];
	}
	s1[k] = '\0';
	return 0;
}
int tj_strncat(char s1[], const char s2[], const int len)
{
	int k = tj_strlen(s1);
	int j = 0;
	if (len <= tj_strlen(s2))
	{
		for (int i = k; i < k+len; i++)
		{
			s1[i] = s2[j];
			j++;
		}
	}
	else
		tj_strcat(s1, s2);
	return 0;
}
int tj_strcpy(char s1[], const char s2[])
{
	int j = 0;
	for (int i = 0; i <= tj_strlen(s2); i++, j++)
		s1[j] = s2[i];
	return 0;
}
int tj_strncpy(char s1[], const char s2[], const int len)
{
	int k = tj_strlen(s2);
	int j = 0;
	if (len <= k)
	{
		for (int i = 0; i < len; i++)
		{
			if (s2[i] == '\0')
				i++;
			s1[j] = s2[i];
			j++;
		}
	}
	else
	{
		for (int i = 0; i < k; i++, j++)
		{
			if (s2[i] == '\0')
				i++;
			s1[j] = s2[i];
		}
	}
	return 0;
}
int tj_strcmp(const char s1[], const char s2[])
{
	int i = 0;
	for (; s1[i] == s2[i]&&s1[i]!='\0'&&s2[i]!='\0';i++)
		;
	return s1[i] - s2[i];
}
int tj_strcasecmp(const char s1[], const char s2[])
{
	int i = 0;
	for (; s1[i] != '\0' && s2[i] != '\0';i++)
	{
		if (s1[i] != s2[i])
		{
			if (s1[i] >= 'a' && s1[i] <= 'z' && s1[i] - s2[i] == 32)
				continue;
			else if (s1[i] >= 'A' && s1[i] <= 'Z' && s1[i] - s2[i] == -32)
				continue;
			else
			{
				if (s1[i] >= 'A' && s1[i] <= 'Z')
					return s1[i] - s2[i] + 32;
				else if (s2[i] >= 'A' && s2[i] <= 'Z')
					return s1[i] - s2[i] - 32;
				else
					return s1[i] - s2[i];
			}		
		}
	}	
	return s1[i] - s2[i];
}
int tj_strncmp(const char s1[], const char s2[], const int len)
{
	int i = 0;
	for (; s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0'&&i<len; i++)
		;
	if (i == len)
		return 0;
	else
		return s1[i] - s2[i];
}
int tj_strcasencmp(const char s1[], const char s2[], const int len)
{
	int i = 0;
	for (; s1[i] != '\0' && s2[i] != '\0' && i < len; i++)
	{
		if (s1[i] != s2[i])
		{
			if (s1[i] >= 'a' && s1[i] <= 'z' && s1[i] - s2[i] == 32)
				continue;
			else if (s1[i] >= 'A' && s1[i] <= 'Z' && s1[i] - s2[i] == -32)
				continue;
			else
			{
				if (s1[i] >= 'A' && s1[i] <= 'Z')
					return s1[i] - s2[i] + 32;
				else if (s2[i] >= 'A' && s2[i] <= 'Z')
					return s1[i] - s2[i] - 32;
				else
					return s1[i] - s2[i];
			}
		}
	}
	if (i == len)
		return 0;
	else
		return s1[i] - s2[i];
}
int tj_strupr(char str[])
{
	for (int i = 0; i < tj_strlen(str); i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
	}
	return 0;
}
int tj_strlwr(char str[])
{
	for (int i = 0; i < tj_strlen(str); i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
	}
	return 0;
}
int tj_strchr(const char str[], const char ch)
{
	for (int i = 0; i < tj_strlen(str); i++)
	{
		if (str[i] == ch)
			return i + 1;
	}
	return 0;
}
int tj_strstr(const char str[], const char substr[])
{
	int tag = -1;
	for (int i = 0; i < tj_strlen(str); i++)
	{
		if (str[i] == substr[0])
		{
			for (int j = 0; j < tj_strlen(substr); j++)
			{
				if (str[i + j] != substr[j])
				{
					tag = 1;
					break;
				}
			}
			if (tag == -1)
				return i + 1;
			else
				tag = -1;
		}
	}
	return 0;
}
int tj_strrchr(const char str[], const char ch)
{
	int j = 0;
	for (int i = tj_strlen(str); i >=0; i--,j++)
	{
		if (str[i] == ch)
			return  tj_strlen(str) - j + 1;
	}
	return 0;
}
int tj_strrstr(const char str[], const char substr[])
{
	int tag = -1, j = 0;
	for (int i = tj_strlen(str)- tj_strlen(substr); i >= 0; i--, j++)
	{
		if (str[i] == substr[0])
		{
			for (int j = 0; j < tj_strlen(substr); j++)
			{
				if (str[i + j] != substr[j])
				{
					tag = 1;
					break;
				}
			}
			if (tag == -1)
				return i + 1;
			else
				tag = -1;
		}
	}
	return 0;
}
int tj_strrev(char str[])
{
	int mid = (tj_strlen(str) + 1) / 2;
	for (int i = 0; i < mid; i++)
	{
		int tmp=str[i];
		str[i] = str[tj_strlen(str) - i-1];
		str[tj_strlen(str) - i-1] = tmp;
	}
	return 0;
}
