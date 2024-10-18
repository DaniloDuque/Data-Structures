template<typename T>
class SparseTable{

private:

    vector<vector<T>> spt;
    function<T(T, T)> fun;

public:

    SparseTable(vector<T> &arr, function<T(T, T)> oper){
        fun = oper;
        int n = arr.size(), K = 32-__builtin_clz(n);
        spt.assign(K, vector<T>(n, 0));
        for(int i = 0; i<n; ++i) spt[0][i] = arr[i];
        for(int k = 1; k<K; ++k)
            for(int i = 0; i<=n-(1<<k); ++i)
                spt[k][i] = fun(spt[k-1][i], spt[k-1][i+(1<<(k-1))]); 
    }

    T query(int i, int j){
        if(i > j) swap(i, j);
        int k = 31-__builtin_clz(j-i);
        return fun(spt[k][i], spt[k][j-(1<<k)]);
    }

};
