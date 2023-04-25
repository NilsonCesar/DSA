public class UnionFindWithArray {
	private int[] id, sz;
	private int n;

	public UnionFindWithArray(int n) {
		this.n = n;
		this.id = new int[n];
		this.sz = new int[n];

		for(int i = 0; i < n; i++) {
			this.id[i] = i;
			this.sz[i] = 1;
		}
	}

	private int root(int p) {
		if(id[p] == p) return p;
		return id[p] = root(id[p]);
	}

	public void union(int p, int q) {
		int i = root(p);
		int j = root(q);

		if(i == j) return;
		if(sz[i] < sz[j]) {
			id[i] = j;
			sz[j] += sz[i];
		} else {
			id[j] = i;
			sz[i] += sz[j];
		}
	}

	public boolean connected(int p, int q) { return root(p) == root(q); }

}