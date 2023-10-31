#include<bits/stdc++.h>
using namespace std;
vector<int> v;


void generatePrintBinary(int n)
{
  
   for(int i=1;i<=n;i++){
       string str="";
       int temp=i;
       while(temp){
           if(temp&1){str=to_string(1)+str;}
           else{str=to_string(0)+str;}
            
           temp=temp>>1;
       }
       v.push_back(stoi(str));

   }

   for(auto it : v){
    cout << it << endl;
   }

}

int main(){
    generatePrintBinary(65);

    return 0;
}