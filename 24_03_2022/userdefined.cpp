#include<iostream>
using namespace std;

namespace counternamespace{
    int upperbound;
    int lowerbound;
    class counter{
        int count;
        public:
        counter(int n){
            if(n<=upperbound)count=n;
            else count=upperbound;
        }
        void reset(int n){
            if(n<=upperbound)count=n;
        }
        int run(){
            if(count>lowerbound)return count--;
            else return lowerbound;
        }
    };

}
using namespace counternamespace;
int main(){
    upperbound=100;
    lowerbound=0;
    counternamespace::counter ob1(10);
    int i;
    do{
        i=ob1.run();
        cout<<i<<" ";
    }while(i>lowerbound);
    cout<<endl;
    counternamespace::counter ob2(20);
    do{
        i=ob2.run();
        cout<<i<<" ";
    }while(i>counternamespace::lowerbound);cout<<endl;
    ob2.reset(100);
    counternamespace::lowerbound=90;
    do{
        i=ob2.run();
        cout<<i<<" ";
    }while(i>counternamespace::lowerbound);
}