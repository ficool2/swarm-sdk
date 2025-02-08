#include <string.h>

int	_V_strlen( const char *str )
{
	return strlen( str );
}

void _V_memmove(void* dest, const void* src, int count)
{
	memmove(dest, src, count);
}

int V_strnicmp(const char* str1, const char* str2, int n)
{
	const unsigned char* s1 = (const unsigned char*)str1;
	const unsigned char* s2 = (const unsigned char*)str2;
	for (; n > 0 && *s1; --n, ++s1, ++s2)
	{
		if (*s1 != *s2)
		{
			// in ascii char set, lowercase = uppercase | 0x20
			unsigned char c1 = *s1 | 0x20;
			unsigned char c2 = *s2 | 0x20;
			if (c1 != c2 || (unsigned char)(c1 - 'a') > ('z' - 'a'))
			{
				// if non-ascii mismatch, fall back to CRT for locale
				if ((c1 | c2) >= 0x80) return strnicmp((const char*)s1, (const char*)s2, n);
				// ascii mismatch. only use the | 0x20 value if alphabetic.
				if ((unsigned char)(c1 - 'a') > ('z' - 'a')) c1 = *s1;
				if ((unsigned char)(c2 - 'a') > ('z' - 'a')) c2 = *s2;
				return c1 > c2 ? 1 : -1;
			}
		}
	}
	return (n > 0 && *s2) ? -1 : 0;
}


