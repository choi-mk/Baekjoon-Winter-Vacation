#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    int i = 1;

    while(1){
        cin >> str;

        string stck;
        int size = 0;
        for(const char& bracket : str){
            if(bracket=='-') return 0;
            else if(bracket=='{'){
                size++;
                stck.push_back('{');
            }
            else{
                if(size > 0 && stck[size - 1] == '{'){
                    size--;
                    stck.pop_back();
                }
                else{
                    size++;
                    stck.push_back('}');
                }
            }
        }

        if(size==0) printf("%d. 0\n", i);
        else{
            int result = 0;
            for(int j=0; j<size; j++){
                if(stck[j++]==stck[j]) result++;
                else result+=2;
            }
            printf("%d. %d\n", i, result);
        }
        i++;
    }

    return 0;
}