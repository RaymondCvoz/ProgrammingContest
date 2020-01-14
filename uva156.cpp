#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <cctype>

std::map <std::string,int> cnt;
std::vector <std::string> words;

std::string modify(const std::string &s)
{
    std::string ans = s;
    for(int i = 0;i < ans.length();i++)
    {
        ans[i] = tolower(ans[i]);
    }
    std::sort(ans.begin(),ans.end());
    return ans;
}

int main()
{
    std::string s;
    while(std::cin >> s)
    {
        if(s[0] == '#') break;
        words.push_back(s);
        std::string r = modify(s);
        if(cnt.count(r) == 0) cnt[r] = 0;
        cnt[r]++;
    }
    std::vector <std::string> ans;
    for(int i = 0;i < words.size();i++)
    {
        if(cnt[modify(words[i])] == 1) ans.push_back(words[i]);
    }
    std::sort(ans.begin(),ans.end());
    for(int i = 0;i < ans.size();i++)
    {
        std::cout << ans[i] << "\n";
    }
    return 0;
}