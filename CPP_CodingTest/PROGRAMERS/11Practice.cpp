#include <vector>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;
using int64 = long long;

int64 Stoi(string& str)
{
    int64 ans = 0;
    int64 now = 1;
    for (int i = str.size()-1; i>=0; i--)
    {
        ans += (str[i]-'0')*now;
        now *= 10;
    }
    return ans;
}

bool IsPrime(int64 n)
{
    if (n<=1) return false;
    if(n%2==0)
        return n==2? true: false;
    for (int64 i = 3; i*i<= n; i += 2)
    {
        if (n%i==0) return false;
    }
    return true;
}

string GetK(int& n, const int& k) //k<= 10
{
    string str;
   
    while (n)
    {
        str.push_back(n% k + '0');
        n /= k;
    }
    ::reverse(str.begin(), str.end());
    return str;
}

int solution(int n, int k) {

    int answer = 0;
    string str = GetK(n,k);
    
    for (auto left = str.begin(); left != str.end();)
    {
        auto right = ::find(left, str.end(), '0');
        string sub = str.substr(left-str.begin(), right-left);
        if(IsPrime( Stoi(sub)))
            answer++;
        left = right == str.end() ? right : right+1;
    }

    return answer;
}
