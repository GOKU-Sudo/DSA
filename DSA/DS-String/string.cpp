#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cstdlib>
using namespace std;

int main(){
    string a ="abc";
    cout<<sizeof(a)<<endl;
    cout<<a.length()<<endl;

    string *s=new string;
    *s="abcdefghijklmno";
    cout<<s<<endl;   
    cout<<*s<<endl;   
    cout<<sizeof(*s)<<endl;
    cout<<(*s).length()<<endl;

    vector<string>v;
    v.push_back("asd");
    v.push_back("hi");
    v.push_back("hello");
    sort(v.begin(),v.end());//sorting content
    for (int i = 0; i<v.size(); i++)
    {   sort(v[i].begin(),v[i].end()); //sorting individual elements too
        cout<<v[i]<<endl;
    }
    

    // string s2;
    // getline(cin,s2);
    // cout<<s2<<endl;

    string s3="";
    cout<<s3.size()<<endl;
    cout<<s3.length()<<endl;

    cout<<(*s).substr(0)<<endl;
    cout<<(*s).substr(10)<<endl;
    cout<<(*s).substr(0,10)<<endl;

    cout<<(*s).find('d')<<endl;

    int p=56;
    string s4=to_string(p);
    cout<<s4<<endl;
    s4.push_back('1');// works in strings too, push back only single char
    cout<<s4<<endl;

    cout<<atoi(s4.c_str()); //convert a string argument to an integer
    return 0;
    
}