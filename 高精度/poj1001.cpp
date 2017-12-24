#include <iostream>
#include <cstring>
#include <string>
using namespace std;
string cal(string,string);
int final_float_pos(int, int);
int main(){
    int r;
    string num;
    while(cin>>num>>r){
        int n[10000],i,num_length,float_pos;
        string ans,ans0;
        num_length = num.length();
        float_pos = num_length - 1;
        // string<char>::iterator p;
        for(string::iterator p=num.begin();p!=num.end();p++){
            if(*p == '.'){
                num.erase(p);
                break;
            }
            float_pos --;
        }
        for (i=0;i<num.length();i++){
            n[i] = num[num.length()-1-i];
        }
        ans0 = ans = num;
        if(r==0){
            cout<<1;
        }
        else{
            for(i=1;i<r;i++){
                ans = cal(ans0,num);
                ans0 = ans;
            }
            ans.insert(ans.length() - final_float_pos(float_pos, r), ".");
            while(*ans.begin() == '0'){
                ans.erase(ans.begin());
            }
            while(*(ans.end()-1) == '0'){
                ans.erase((ans.end()-1));
            }
            if(*(ans.end()-1) == '.'){
                ans.erase(ans.end()-1);
            }
            if(ans.length() == 0){
                cout<<0;
            }
            else{
                cout<<ans;
            }
        }
        cout<<endl;

    }
    return 0;
}
string cal(string num1, string num2){
    int n1[10000]={0},n2[10000]={0},ans[10000]={0},i,j,pos;
    for (i=0;i<num1.length();i++){
        n1[i] = num1[num1.length()-1-i] - '0';
    }
    for (i=0;i<num2.length();i++){
        n2[i] = num2[num2.length()-1-i] - '0';
    }
    for (i=0;i<num1.length();i++){
        for (j=0;j<num2.length();j++){
            ans[j+i] += n1[i] * n2[j];
            ans[i+j+1] += ans[i+j]/10;
            ans[i+j] = ans[i+j]%10;
        }
    }
    //for (i=0;i<num.length();i++){
      //  ans[i+1] += ans[i]/10;
        //ans[i] = ans[i]%10;
    //}
    pos = num1.length()+num2.length()-1;
    while(ans[pos]>=10){
        ans[pos+1] += ans[pos]/10;
        ans[pos] = ans[pos]%10;
        pos ++;
    }
    string str = "";
    for(i=0;i<=pos;i++){
        str += (ans[pos-i]%10 + '0');
    }
    return str;
}
int final_float_pos(int float_pos, int r){
    // int base = 2;
    // cout<<"float_pos=="<<float_pos;
    // for(int i=0;i<r;i++){
       // float_pos *= 2;
    // }
    // cout<<"final_float_pos=="<<float_pos<<endl;
    return float_pos * r;
}
