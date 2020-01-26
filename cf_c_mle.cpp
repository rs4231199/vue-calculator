#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int p = 31;
const int m = 1e9 + 9;


int main()
{

    ios_base::sync_with_stdio(false);cin.tie(NULL);

    int N;
    cin>>N;
 
    // vector<string> hash;
    string s[N];
    vector<vector<ll>> hashmap(N);
 
    for(int i=0;i<N;i++){
        string in;
        cin>>in;
        s[i]=in;
        ll p_pow = 1;
        ll hash_value = 0;
        hashmap[i].push_back(0);
        for (char c : in) {
            hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
            p_pow = (p_pow * p) % m;
            hashmap[i].push_back(hash_value);
        }
 
    }
    int Q;
    cin>>Q;
 
    for (int i = 0; i < Q;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
 
        string s1=s[a-1];
        string s2=s[b-1];
        string s3=s[c-1];
 
        int minl=min(s1.length(),min(s2.length(),s3.length()));
 
        int start=0;
        int end=minl;
//BINARY SEARCH
        while (start <= end)
        {
            int mid = start + (end - start)/2;

            if (hashmap[a-1][mid] == hashmap[b-1][mid] && hashmap[b-1][mid] == hashmap[c-1][mid]) 
            {
                ans = mid;
                start = mid + 1;
            }

            else
            {
                end=mid-1;
            }
        }

        cout << ans << endl;

    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
 
int main()
{
 
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    
    int N;
    cin>>N;
 
    string hash[N];
    
    unordered_map<int,unordered_map<int,int> >hashmap;
 
    for(int i=0;i<N;i++){
        string in;
        cin>>in;
        hash[i]=in;
        unordered_map<int,int> temp;
        const int p = 31;
        ll p_pow = 1;
        const int m = 1e9 + 9;
        temp[1] = (in[0] - 'a' + 1);
        for (int j = 2; j <=in.length() ; j++)
        {
            temp[j] = ((ll)temp[j-1] + (in[j-1] - 'a' + 1) * p_pow) % m;
            p_pow = (p_pow * p) % m;
        }
        hashmap[i]=temp;
        
    }   
 
    int Q;
    cin>>Q;
 
    for (int i = 0; i < Q;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
 
        string s1=hash[a-1];
        string s2=hash[b-1];
        string s3=hash[c-1];
 
        int minl=min(s1.length(),min(s2.length(),s3.length()));
 
        int start=0;
        int end=minl;
        int ans = 0;
        if (s1[0] != s2[0] || s2[0] != s3[0]) {
            cout << 0 << endl;
            continue;
        }
//BINARY SEARCH
        while (start <= end)
        {
            int mid = (start + end)/2;
 
            if (hashmap[a-1][mid] == hashmap[b-1][mid] && hashmap[b-1][mid] == hashmap[c-1][mid]) {
                ans = mid;
                start = mid + 1;
            }
 
            else{
                end=mid-1;
            }
        }
 
        cout << ans << endl;
 
    }
 
    return 0;
}