## Disjoint Set （并查集）

**参考资料**

- B站UP主-**正月点灯笼**的视频。[BV13t411v7Fs](https://www.bilibili.com/video/BV13t411v7Fs)

- [Union-Find算法详解 - labuladong的算法小抄](https://labuladong.gitbook.io/algo/shu-ju-jie-gou-xi-lie/2.4-shou-ba-shou-she-ji-shu-ju-jie-gou/unionfind-suan-fa-xiang-jie)


**模板**

```cpp
class Union_Find {  // 在《算法·第四版》里也叫做 union find
private:
	int cnt;  // 连通分量的个数
	vector<int> parent;  // 存储一棵树
	vector<int> rank;  // 记录树的「重量」
public:
	// 构造函数，n 为图的「节点」总数
	Union_Find( int n ) : rank( vector<int>( n, 1 ) ), parent( vector<int>( n ) ) {
		cnt = n;
		for ( int i = 0; i < n; ++i )  // 父节点指针初始指向自身
			parent[i] = i;
	}

	void to_union( int p, int q ) {
		int rootP = find_root( p );
		int rootQ = find_root( q );

		if ( rootP == rootQ )  // 祖先节点相同
			return;

		// 小树接到大树下面，较平衡
		if ( rank[rootP] > rank[rootQ] ) {
			parent[rootQ] = rootP;  // rootQ 的父节点为（指向） rootP
			rank[rootP] += rank[rootQ];
		} else {
			parent[rootP] = rootQ;
			rank[rootQ] += rank[rootP];
		}
		
		--cnt;
	}

	bool connected( int p, int q ) {
		int rootP = find_root( p );
		int rootQ = find_root( q );
		// 处于同一棵树上的节点，相互连通
		return rootP == rootQ;
	}

	// 返回节点 x 的根节点
	int find_root( int x ) {
		while ( parent[x] != x ) {
			parent[x] = parent[parent[x]];  // 路径压缩。避免极端情况下，退化为一条长链
			x = parent[x];
		}

		return x;
	}

	int count() {
		return cnt;
	}
};
```