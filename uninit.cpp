#include<iostream>
#include<string>

using namespace std;

int main() {
    string st, s;
    st = 'L';
    s = "LRLRLRLR";
    st += s;
    st += 'R';

    int ans = -1, val, ind = 0;

    for (int i = 0; i < st.length(); i++) {
        if (st[i] == 'R') {
            val = i;
            ans = max(ans, val);
            break;
        }
    }

    ind = val;

    for(int i =  val + 1; i < st.length(); i++) {
        if (st[i] == 'R') {
            int pp = i - ind;
            ind = i;
            ans = max(ans, pp);
        }
    }

    cout << ans << endl;
}