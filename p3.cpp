// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int hasIndx(int n,int x){
    return n%x;
}
int has(char ch,int x){
    return ch%x;
    
}

int main() {
    int n,x;
    char ch;
    
    cout<<"Enter the Table Size :"<<endl;
    cin>>x;
    if(x==0){
        cout<<"Table size cannot be zero"<<endl;
        return 0;
    }
    cout<<"Enter the key value :"<<endl;
    cin>>ch;
    cout<<"Has Index = "<<has(ch,x)<<endl;
    

    return 0;
}

//OUTPUT:
// Enter the Table Size :
// 10
// Enter the key value :
// BUSHRA
// Has Index = 6
