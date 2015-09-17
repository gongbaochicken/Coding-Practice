public class Union_Find(){
	int[] list;
	public uion_find(int N){
		list = new int[N];
		for(int i = 0; i < N; i++){
			list[i] = i;
		}
	}

	public int findroot(int i){
		if(list[i] == i) return i;
		list[i] == list[list[i]];
		return findroot(list[i]);
	}

	public boolean isConnect(int p, int q){
		int rootp = findroot(p);
		int rootq = findroot(q);
		return rootq == rootp;
	}

	public void union(int p, int q){
		list[findroot(q)] = findroot(p);
	}
}