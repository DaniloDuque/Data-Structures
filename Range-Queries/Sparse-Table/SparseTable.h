class SparseTable{

private:

    vector<vector<int>> spt;
    function<int(int, int)> fun;

public:

    SparseTable(vector<int> &arr, function<int(int, int)> oper){
        fun = oper;
        int n = arr.size(), K = 32-__builtin_clz(n);
        spt.assign(K, vector<int>(n, 0));
        for(int i = 0; i<n; ++i) spt[0][i] = arr[i];
        for(int k = 1; k<K; ++k)
            for(int i = 0; i<=n-(1<<k); ++i)
                spt[k][i] = fun(spt[k-1][i], spt[k-1][i+(1<<(k-1))]); 
    }

    int query(int i, int j){
        if(i > j) swap(i, j);
        int k = 31-__builtin_clz(j-i);
        return fun(spt[k][i], spt[k][j-(1<<k)]);
    }

};
