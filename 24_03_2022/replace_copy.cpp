#include<iostream>
#include<algorithm>
#include<vector>
// using namespace std::cout;
int main(){
    char str[]=" I love C++ ' '  programming   language \n  '  '  ";
    std::vector<char> v,v2(30);
    int i;
    for(i=0;str[i];i++)
    v.push_back(str[i]);
    std::cout<<"Input sequence:\n";
    for(i=0;str[i];i++)
    std::cout<<v[i];
    std::cout<<std::endl;
    std::replace_copy(v.begin(),v.end(),v2.begin(),' ',':');
    std::cout<<"Result after removing spaces:\n";
    for(i=0;i<v2.size();i++)
    std::cout<<v2[i];
    std::cout<<std::endl;
}