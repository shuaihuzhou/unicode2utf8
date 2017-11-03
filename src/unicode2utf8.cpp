#include "../include/unicode2utf8.h"
#include "../include/split.h"
#include<algorithm>

std::string unicode2utf8(const char* str)
{
    std::vector<varray> vtr; 
    split(str,vtr,'\\');
    int vsize = vtr.size();
    
    std::string result=""; 
    int s=0;
    for(s = 0; s < vsize; s++)
    {
        char* tr = vtr[s].ch;
        int len = strlen(tr);
        int j=0;
        char uni[4];
        for(int i=0; i<len; i++)
        {
            if(tr[i] == '\\')
            {
                i++;
                continue;
            }
            else if(tr[i] >= '0' && tr[i] <= '9')
            {
                uni[j++] = tr[i] - '0';
            }
            else if(tr[i] >= 'a' && tr[i] <= 'z')
            {
                uni[j++] = tr[i] - 'a' + 10;
            }
            else if(tr[i] >= 'A' && tr[i] <= 'Z')
            {
                uni[j++] = tr[i] - 'A' + 10;
            }
            else
            {
                continue;
            }

        }
        unsigned int ch[3];
        ch[0] = 0xe0 + (uni[0]);
        ch[1] = 0x80 + ((uni[1] & 0x0c)<<2) + ((uni[1] & 0x03)<<2) + ((uni[2] & 0x0c)>>2);
        ch[2] = 0x80 + ((uni[2] & 0x03)<<4) + (uni[3]);
        unsigned int iresult = ch[0] * 256 * 256 + ch[1] * 256 + ch[2];
        
        char* cresult = (char*)&iresult;
        std::reverse(cresult,cresult+strlen(cresult));
        std::string tempstring(cresult);
        result += tempstring + vtr[s].st;
    }
    return result;
}
