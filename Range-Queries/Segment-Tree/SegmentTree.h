template<typename T>
class SegmentTree{

private:
    vector<T> st; 
    int n; 
    T NEUT;
    function<T(T, T)> fun;

    void init(int k, int s, int e, T *a){
        if(s+1 == e) { st[k] = a[s]; return; }
        int m = (s+e) >> 1;
        init(k<<1, s, m, a); 
        init((k<<1)+1, m, e, a);
        st[k] = fun(st[k<<1], st[(k<<1)+1]);
    }

    void upd(int k, int s, int e, int p, T v){
        if(s+1 == e) { st[k] = v; return; }
        int m = (s+e) >> 1;
        (p < m) ? upd(k<<1, s, m, p, v) : upd((k<<1)+1, m, e, p, v);
        st[k] = fun(st[k<<1], st[(k<<1)+1]);
    }

    T query(int k, int s, int e, int a, int b){
        if(s >= b || e <= a) return NEUT;
        if(s >= a && e <= b) return st[k];
        int m = (s+e) >> 1;
        return fun(query(k<<1, s, m, a, b), query((k<<1)+1, m, e, a, b));
    }

public:
    SegmentTree(int sz, T neut, function<T(T, T)> oper) {
        n = sz; NEUT = neut; 
        st.assign(4 * n + 5, NEUT); 
        fun = oper; 
    }
    
    void init(T *a) { init(1, 0, n, a); }
    void upd(int i, T v) { upd(1, 0, n, i, v); }
    T query(int i, int j) { return query(1, 0, n, i, j); }
};
