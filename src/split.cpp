#include "../include/split.h"
#include<string>

void split(const char* str, std::vector<varray> &vtr, char ch)
{
    std::string s(str);
    int start = 0, end = 0;
    varray xt;
    while(end != std::string::npos)
    {
        if(end > start)
        {
            for(int i=0; i<6; i++)
            {
                xt.ch[i] = s[start+i];
            }
            if(end - start > 6)
            {
                xt.st = s.substr(start+6, end-start-6); 
            }
            vtr.push_back(xt);
            memset(xt.ch,0,sizeof(xt.ch));
            xt.st.clear();
        }
        start = end;
        end = s.find('\\', end+1);
    }
    for(int i=0; i<6; i++)
    {
        xt.ch[i] = s[start+i];
    }
    if(s.size() - start > 6)
    {
        xt.st = s.substr(start+6, s.size()-start-6); 
    }
    vtr.push_back(xt); 
    memset(xt.ch,0,sizeof(xt.ch));
    xt.st.clear();
}
