#include <iostream>
#include <vector>

using namespace std;

vector<int> inorder;
vector<int> postorder;

void preorder(int inStart, int inEnd, int postStart, int postEnd) {
	if (inStart == inEnd) {
		cout << inorder[inStart] << " ";
		return;
	}
	if (inStart > inEnd) {
		return;
	}
	int root = postorder[postEnd];
	int left = inStart;
	for (; left < inEnd; left++) {
		if (root == inorder[left]) break;
	}
	int leftSize = left - inStart - 1;
	cout << root << " ";
	preorder(inStart, inStart + leftSize, postStart, postStart + leftSize);
	preorder(inStart + leftSize + 2, inEnd, postStart + leftSize + 1, postEnd - 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	inorder.resize(n);
	postorder.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> inorder[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> postorder[i];
	}

	preorder(0, n - 1, 0, n - 1);
	return 0;
}