//name :- yash jain
#include <iostream>
#include<deque>
using namespace std;
// int queue(int *size){
//     int array[*size];
// }
// void queue_insert(int *num){

// }
// int main(){

//}//
int main(){
    int a,b,c,j=0;
    int g=0;
    int l=NULL;
    deque<int> d1;
    for(int i=0;i<7;i++){
        cin>>a;
        d1.push_back(a);
    }
    while(d1.size()!=2)
    {
    for(int i=0;i<3;i++)
    {
        b=d1.at(i);
        if(g<=b){
            g=b;
        }
        if(l>=b || l==NULL){
            l=b;
        }
    }
    cout<<"["<<l<<","<<g<<"]";
    l=NULL;
    d1.pop_front();
    cout<<endl;
    j++;
    }
}