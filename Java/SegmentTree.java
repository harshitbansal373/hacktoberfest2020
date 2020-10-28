

public class SegmentTree {
	
	public static void main(String args[]) {
		
		int a[] = {1,3,2,-2,4,5};
		int n = a.length;
		
		int sizeOfTreeArray = 4*n + 1;
		int[] segmentTree = new int[sizeOfTreeArray];
		int[] lazy = new int[sizeOfTreeArray];
		
		buildTree(a, segmentTree, 1, 0, n-1);
		
		int minimum = query(segmentTree, 1, 0, n-1, 1, 4);
		System.out.println(minimum);
		
		updateRange(segmentTree, 1, 0,n-1 , 4, 1, 4);
		
		for (int i = 0; i < segmentTree.length; i++) {
			System.out.print(segmentTree[i] + " ");
		}
		
		minimum = query(segmentTree, 1, 0, n-1, 1, 4);
		
		System.out.println("\n" + minimum);
		
		
	}
	
	private static void updateNode(int[] tree, int index, int s, int e, int value, int i) {
		
		if(i < s || i > e) {
			return;
		}
		
		if(s == e) {
			if(s == i) {
				tree[index] = value;
				return;
			}else {
				return;
			}
		}
		
		int mid = (s + e)/2;
		
		updateNode(tree, index*2, s, mid, value, i);
		updateNode(tree, index*2+1, mid+1, e, value, i);
		
		int left = tree[index*2];
		int right = tree[index*2+1];
		
		tree[index] = Math.min(left, right);
		
	}
	
private static void updateRange(int[] tree, int index, int s, int e, int value, int rs, int re) {
		
		if(re < s || rs > e) {
			return;
		}
		
		if(s == e) {
			if(rs <= s && s <= re) {
				tree[index] = value;
				return;
			}else {
				return;
			}
		}
		
		int mid = (s + e)/2;
		
		updateNode(tree, index*2, s, mid, value, i);
		updateNode(tree, index*2+1, mid+1, e, value, i);
		
		int left = tree[index*2];
		int right = tree[index*2+1];
		
		tree[index] = Math.min(left, right);
		
	}
	
	private static int query(int[] tree,int index, int s, int e, int qs, int qe) {
		
		// no overlap
		if(qs > e || qe < s) {
			return Integer.MAX_VALUE;
		}
		
		// complete overlap
		if(qs <= s && qe >= e) {
			return tree[index];
		}
		
		int mid = (s + e)/2;
		
		int left = query(tree, index*2, s, mid, qs, qe);
		int right = query(tree, index*2 + 1, mid + 1, e, qs, qe);
		
		return Math.min(left, right);
		
	}

	private static void buildTree(int[] a, int[] segmentTree, int index, int s, int e) {
		
		if(s > e) {
			return;
		}
		
		if(s == e) {
			segmentTree[index] = a[s];
			return;
		}
		
		int mid = (s + e)/2;
		
		buildTree(a, segmentTree, index*2, s, mid);
		buildTree(a, segmentTree, index*2 + 1, mid + 1, e);
		
		int left = segmentTree[index*2];
		int right = segmentTree[index*2 + 1];
		
		segmentTree[index] = Math.min(left, right);
		
		
	}

}
