#include<vector>
using namespace std;

void doone(int a){
    vector<int> something(a);
    for(int i = 0; i < a; i++){
        something[i] = something[i] + 100;
    }
}

void dotwo(int a){
    vector<int> something(a);
    for(int i = 1; i <= 2 * a; i++){
        something[i] = something[i] * 100;
    }
}

void dothree(int c){
    vector<int> something(c);
    for(int i = 1; i < c; i++){
        something[i] = something[i] / 2;
    }
}
int main(){
    int a, b, c;
    a = 1e5;
    b = 1e5;
    c = 1e5;

    doone(a);
    dotwo(b);
    dothree(c);

    return 0;
}