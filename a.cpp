#include "heads.h"

int main() {
    int data_count, data_size, n;
    cin >> data_count;
    while (data_count--) {
        cin >> data_size;
        vector<int> data0, data1;
        for(int i = 0; i < data_size; ++ i) {
            cin >> n;
            if (i % 2 == 0) data0.push_back(n);
            else    data1.push_back(n);
        }
        sort(data0.begin(), data0.end());
        sort(data1.begin(), data1.end());

        //judge
        int ret = true;
        for(int i = 0; i < data0.size(); ++ i) {
            if (data0[i] > data1[i]) {
                ret = false;
                break;
            }
        }
        cout << (ret ? "YES" : "NO") << endl;
    }

    return 0;
}