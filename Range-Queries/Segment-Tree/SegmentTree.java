import java.util.function.BinaryOperator;

class SegmentTree {

    private int[] st;
    private int n, NEUT;
    private BinaryOperator<Integer> fun;

    private void init(int k, int s, int e, int[] a) {
        if (s + 1 == e) { st[k] = a[s]; return; }
        int m = (s + e) >> 1;
        init(k << 1, s, m, a); init((k << 1) + 1, m, e, a);
        st[k] = fun.apply(st[k << 1], st[(k << 1) + 1]);
    }

    private void upd(int k, int s, int e, int p, int v) {
        if (s + 1 == e) { st[k] = v; return; }
        int m = (s + e) >> 1;
        if (p < m) upd(k << 1, s, m, p, v); else upd((k << 1) + 1, m, e, p, v);
        st[k] = fun.apply(st[k << 1], st[(k << 1) + 1]);
    }

    private int query(int k, int s, int e, int a, int b) {
        if (s >= b || e <= a) return NEUT;
        if (s >= a && e <= b) return st[k];
        int m = (s + e) >> 1;
        return fun.apply(query(k << 1, s, m, a, b), query((k << 1) + 1, m, e, a, b));
    }

    public SegmentTree(int sz, int neut, BinaryOperator<Integer> oper) {
        n = sz; NEUT = neut; st = new int[4 * n + 5]; fun = oper;
        for (int i = 0; i < st.length; i++) st[i] = NEUT;
    }

    public void init(int[] a) { init(1, 0, n, a); }
    public void upd(int i, int v) { upd(1, 0, n, i, v); }
    public int query(int i, int j) { return query(1, 0, n, i, j); }
}

