#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

void merge(vector<PII>& segs) {
    vector<PII> res;

    sort(segs.begin(), segs.end());

    int st = -2e9, ed = -2e9;
    for(auto seg : segs)
        if(ed < seg.first) {
            if(st != -2e9) res.push_back({ st, ed });
            st = seg.first, ed = seg.second;
        } else
            ed = max(ed, seg.second);

    if(st != -2e9) res.push_back({ st, ed });

    segs = res;
}

int main() {
    int n;
    scanf("%d", &n);

    vector<PII> segs;
    for(int i = 0; i < n; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        segs.push_back({ l, r });
    }

    merge(segs);

    cout << segs.size() << endl;

    return 0;
}

/*
作者：yxc
链接：https://www.acwing.com/activity/content/code/content/40108/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/