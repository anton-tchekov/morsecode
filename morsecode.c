#include "morsecode.h"
#include <string.h>

struct
{
	char Char;
	char *Morse;
}
static const table[] =
{
	{ .Char = 'A', .Morse = ".-"    },
	{ .Char = 'B', .Morse = "-..."  },
	{ .Char = 'C', .Morse = "-.-."  },
	{ .Char = 'D', .Morse = "-.."   },
	{ .Char = 'E', .Morse = "."     },
	{ .Char = 'F', .Morse = "..-."  },
	{ .Char = 'G', .Morse = "--."   },
	{ .Char = 'H', .Morse = "...."  },
	{ .Char = 'I', .Morse = ".."    },
	{ .Char = 'J', .Morse = ".---"  },
	{ .Char = 'K', .Morse = "-.-"   },
	{ .Char = 'L', .Morse = ".-.."  },
	{ .Char = 'M', .Morse = "--"    },
	{ .Char = 'N', .Morse = "-."    },
	{ .Char = 'O', .Morse = "---"   },
	{ .Char = 'P', .Morse = ".--."  },
	{ .Char = 'Q', .Morse = "--.-"  },
	{ .Char = 'R', .Morse = ".-."   },
	{ .Char = 'S', .Morse = "..."   },
	{ .Char = 'T', .Morse = "-"     },
	{ .Char = 'U', .Morse = "..-"   },
	{ .Char = 'V', .Morse = "...-"  },
	{ .Char = 'W', .Morse = ".--"   },
	{ .Char = 'X', .Morse = "-..-"  },
	{ .Char = 'Y', .Morse = "-.--"  },
	{ .Char = 'Z', .Morse = "--.."  },
	{ .Char = '0', .Morse = "-----" },
	{ .Char = '1', .Morse = ".----" },
	{ .Char = '2', .Morse = "..---" },
	{ .Char = '3', .Morse = "...--" },
	{ .Char = '4', .Morse = "....-" },
	{ .Char = '5', .Morse = "....." },
	{ .Char = '6', .Morse = "-...." },
	{ .Char = '7', .Morse = "--..." },
	{ .Char = '8', .Morse = "---.." },
	{ .Char = '9', .Morse = "----." }
};

char *morse_decode(const char *restrict morse, char *restrict txt)
{
	char buf[6], c, *ret = txt;
	int idx = 0, i;
	while(*morse)
	{
		idx = 0;
		while((c = *morse++) != '/' && c)
		{
			buf[idx++] = c;
		}

		buf[idx] = '\0';
		for(i = 0; i < sizeof(table) / sizeof(*table); ++i)
		{
			if(strcmp(buf, table[i].Morse) == 0)
			{
				*txt++ = table[i].Char;
			}
		}
	}

	*txt = '\0';
	return ret;
}

char *morse_encode(const char *restrict txt, char *restrict morse)
{
	char *ret = morse;
	int t, i;
	for(; *txt; ++txt)
	{
		for(t = 0; t < sizeof(table) / sizeof(*table); ++t)
		{
			if(table[t].Char == *txt)
			{
				for(i = 0; table[t].Morse[i]; ++i)
				{
					*morse++ = table[t].Morse[i];
				}

				*morse++ = '/';
				break;
			}
		}
	}

	*(morse - 1) = '\0';
	return ret;
}
