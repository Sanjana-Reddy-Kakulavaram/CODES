#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<char, int> pci;


pci getPairForm(string s)
{
    pci p;
    int hyphens = 0;
    int num = 0;
    for(int i=0; i<s.length(); i++)
    {
        if(s[i] == '-') hyphens++;
        if(hyphens == 1)
        {
            if(s[i] == 'N' || s[i] == 'S' || s[i] == 'E' || s[i] == 'W')
                p.first = s[i];
        }
        if(hyphens == 3)
        {
            if(s[i] >= '0' && s[i] <= '9')
            {
                num = num*10 + (s[i]-'0');
            }
        }
    }
    p.second = num;
    return p;
}

int main()
{
    vector<pci> v;
    pci p;
    map<int, vector<pci>> mp;
    string str;
    int north=0, south=0, west=0, east=0;
    int day = 0;
    getline(cin, str);
    string s = "";
    for(int i=0; i<int(str.length()); i++)
    {
        if(str[i] == '$')
        {
            s = "";
            v.clear();
            day++;
            continue;
        }
        if(str[i] == ':')
        {
            p = getPairForm(s);
            // v.push_back(s);
            v.push_back(p);
            s = "";
            continue;
        }
        if(str[i] == ';') 
        {
            p = getPairForm(s);
            // v.push_back(s);
            v.push_back(p);
            s = "";
            mp[day] = v;
            continue;
        }
        s += str[i];
    }
    if(s.length() > 0)
    {
        p = getPairForm(s);
        // v.push_back(s);
        v.push_back(p);
        mp[day] = v;
    }
    int attacks = 0;
    int nm=0, sm=0, em=0, wm=0;
    for(auto x : mp)
    {
        // cout<<day<<": ";
        nm = north; sm = south; em = east; wm = west;
        for(auto k : x.second) 
        {
            if(k.first == 'N')
            {
                if(north < k.second)
                {
                    attacks++;
                    nm = max(nm, k.second);
                }
            }
            else if(k.first == 'S')
            {
                if(south < k.second)
                {
                    attacks++;
                    sm = max(sm, k.second);
                }
            }
            else if(k.first == 'E')
            {
                if(east < k.second)
                {
                    attacks++;
                    em = max(em, k.second);
                }
            }
            else
            {
                if(west < k.second)
                {
                    attacks++;
                    wm = max(wm, k.second);
                }
            }
            // cout<<k.first<<"->"<<k.second<<" , ";
        }
        north = nm; south = sm; east = em; west = wm;
        // cout<<"\n";
    }
    cout<<attacks<<"\n";
    return 0;
}