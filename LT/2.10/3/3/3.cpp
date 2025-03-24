
#include <iostream>
using namespace std;


int main()
{
	Tree T = NULL;
	inputTree(T);
	cout << "\nNLR: "; NLR(T);
	cout << "\nLRN: "; LRN(T);
	cout << "\nLNR: "; LNR(T);

	cout << "\nLeaf nodes: "; listLeafs(T);
	cout << "\nInternal nodes: "; listInternalNodes(T, 0); //co de san tham so thu 2 cho ai co nhu cau dung, SV khong dung tham so thu 2 nay cung khong sao
	cout << "\nNodes with one child: "; listNodesWithOneChild(T);
	cout << "\nNodes with two children: "; listNodesWithTwoChildren(T);

	return 0;
}
