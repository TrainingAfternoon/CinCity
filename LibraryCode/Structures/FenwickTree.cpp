struct FenwickTree{
    vector<int> arr;
    int n;

    FenwickTree(int size){
        n = size;
        arr.assign(size,0);
    }

    int sum(int k){
        int s = 0;
        int ik = k+1;
        while(ik>=1){
            s+=arr[ik-1];
            ik-= ik & -ik;
        }
        return s;
    }

    int sum(int l, int r){
        return sum(r) - sum(l-1);
    }

    void update(int k, int x){
        int ik = k+1;
        while(ik <= n){
            arr[ik-1]+=x;
            ik+= ik & -ik;
        }
    }
};
