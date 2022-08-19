#include<iostream>
#include<queue>
using namespace std;

class node{
public:
	int data;
	node* left;
	node* right;

	node(int d){
		data = d;
		left = NULL;
		right = NULL;
	}
};

node* buildTree(){
	int d;
	cin>>d;
	if(d == -1){
		return NULL;
	}

	node* root = new node(d);
	root->left = buildTree();
	root->right = buildTree();

	return root;
}

void printPre(node* root){
	if(root == NULL){
		return;
	}

	cout<<root->data<<" ";
	printPre(root->left);
	printPre(root->right);
	return;
}

void printInorder(node* root){
	if(root==NULL){
		return;
	}

	printInorder(root->left);
	cout<<root->data<<" ";
	printInorder(root->right);
}

void printPostorder(node* root){
	if(root==NULL){
		return;
	}

	printPostorder(root->left);
	printPostorder(root->right);
	cout<<root->data<<" ";
}

int height(node* root){
	if (root == NULL)
	{
		return 0;
	}

	int ls = height(root->left);
	int rs = height(root->right);

	return max(ls, rs) + 1;
}

void printKthLevel(node* root, int k){
	if (root==NULL)
	{
		return;
	}
	if(k==1){
		cout<<root->data<<" ";
		return;
	}

	printKthLevel(root->left, k-1);
	printKthLevel(root->right, k-1);
	return;
}

void printLevelOrder(node* root){
	int H = height(root);

	for(int i=1; i<=H; i++){
		printKthLevel(root, i);
		cout<<endl;
	}
}

void bfs(node* root){
	queue<node*> q;
	q.push(root);

	while(!q.empty()){
		node* f = q.front();
		cout<<f->data<<" ";
		q.pop();

		if(f->left){
			q.push(f->left);
		}
		if(f->right){
			q.push(f->right);
		}
	}
	return;
}

void bfsWithNewLine(node* root){
	queue<node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		node* f = q.front();
		if(f==NULL){
			cout<<endl;
			q.pop();
			if(!q.empty()){
				q.push(NULL);
			}
		}
		else{
			cout<<f->data<<" ";
			q.pop();
			if(f->left){
				q.push(f->left);
			}
			if(f->right){
				q.push(f->right);
			}
		}
	}

}

int countNodes(node* root){
	if(root == NULL){
		return 0;
	}

	int left = countNodes(root->left);
	int right = countNodes(root->right);

	return left + right + 1;
}

int sumOfNodes(node* root){
	if(root == NULL){
		return 0;
	}

	int left = sumOfNodes(root->left);
	int right = sumOfNodes(root->right);

	return left + right + root->data;
}

int diameter(node* root){
	if(root == NULL){
		return 0;
	}

	int lh = height(root->left);
	int rh = height(root->right);

	int option1 = lh + rh;

	int option2 = diameter(root->left);
	int option3 = diameter(root->right);

	return max(option1, max(option2, option3)); 
}

class Pair{
public:
	int diameter;
	int height;
};

Pair fastDiameter(node* root){
	Pair p;
	if(root == NULL){
		p.height = p.diameter = 0;
		return p;
	}

	Pair left = fastDiameter(root->left);
	Pair right = fastDiameter(root->right);
	p.height = max(left.height, right.height) + 1;
	p.diameter = max(left.height + right.height, max(left.diameter, right.diameter));
	return p;
}

int replaceBysumOfChildNodes(node* root){
	if(root == NULL){
		return 0;
	}

	if(root->left == NULL && root->right == NULL){
		return root->data;
	}

	int leftSum = replaceBysumOfChildNodes(root->left);
	int rightSum = replaceBysumOfChildNodes(root->right);

	int currNodeData = root->data;
	root->data = leftSum + rightSum;

	return root->data + currNodeData;
}

class HBPair{
public:
	int height;
	bool balanced;
};

HBPair isHeightBalanced(node* root){
	HBPair p;
	if(root == NULL){
		p.height = 0;
		p.balanced = true;
		return p;
	}

	HBPair left = isHeightBalanced(root->left);
	HBPair right = isHeightBalanced(root->right);

	bool heightCheck = abs(left.height - right.height) <=1;
	p.height = max(left.height, right.height) + 1;
	if(heightCheck && left.balanced && right.balanced){
		p.balanced = true;
	}
	else{
		p.balanced = false;
	}
	return p;
}

node* buildTreeFromArray(int* arr, int s, int e){
	if(s>e){
		return NULL;
	}

	int mid = (s+e)/2;
	node* root = new node(arr[mid]);

	root->left = buildTreeFromArray(arr, s, mid - 1);
	root->right = buildTreeFromArray(arr, mid + 1, e);

	return root;
}

node* buildFromTraversal(int* in, int* pre, int s, int e){
	static int i = 0;

	if(s>e){
		return NULL;
	}

	node* root = new node(pre[i]);
	int index = -1;
	for(int j=s; j <=e; j++){
		if(in[j] == pre[i]){
			index = j;
			break;
		}
	}

	i++; //move i to next index in pre array
	root->left = buildFromTraversal(in, pre, s, index-1);
	root->left = buildFromTraversal(in, pre, index+1, e);
	return root;
}

void printRightView(node* root, int level, int &maxLevel){
	if(root == NULL){
		return;
	}

	if(level > maxLevel){
		cout<<root->data<<" ";
		maxLevel = level;
	}

	printRightView(root->right, level + 1, maxLevel);
	printRightView(root->left, level + 1, maxLevel);
	return;
}

void printLeftView(node* root, int level, int &maxLevel){
	if(root==NULL){
		return;
	}

	if(level > maxLevel){
		cout<<root->data<<" ";
		maxLevel= level;
	}

	printLeftView(root->left, level + 1, maxLevel);
	printLeftView(root->right, level+1, maxLevel);
	return;
}

node* lca(node* root, int a, int b){
	if(root == NULL){
		return NULL;
	}

	if(root->data == a || root->data==b){
		return root;
	}

	node* leftans = lca(root->left,a , b);
	node* rightans = lca(root->right, a,b);

	if(leftans!=NULL and rightans!=NULL){
		return root;
	}

	if(leftans!=NULL){
		return leftans;
	}
	return rightans;
}

int main(int argc, char const *argv[])
{

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	node* root = buildTree();
	cout<<"Preorder: ";
	printPre(root);
	cout<<endl<<"Inorder: ";
	printInorder(root);
	cout<<endl<<"Postorder: ";
	printPostorder(root);
	cout<<endl;
	cout<<"Height of binary tree: "<<height(root)<<endl;
	cout<<"Level Order recursive: 👇"<<endl;
	printLevelOrder(root);
	cout<<"Level Order BFS: ";
	bfs(root);
	cout<<endl<<"Level order with new line BFS:👇"<<endl;
	bfsWithNewLine(root);
	// cout<<"Number of nodes: "<<countNodes(root)<<endl;
	// cout<<"Sum of nodes: "<<sumOfNodes(root)<<endl;
	// cout<<"Diameter in O(N^2): "<<diameter(root)<<endl;
	// cout<<"Diameter in O(N): "<<fastDiameter(root).diameter<<endl;
	// cout<<"Replacing by sum of child nodes: 👇"<<endl;
	// replaceBysumOfChildNodes(root);
	// bfsWithNewLine(root);
	// HBPair p = isHeightBalanced(root);
	// cout<<"Height: "<<p.height<<", "<<"Balanced: "<<(p.balanced? "Yes": "Nope")<<endl;

	// int arr[] = {1,2,3,4,5,6,7};
	// node * root1 = buildTreeFromArray(arr, 0, 6);
	// cout<<"height balanced tree from array: "<<endl;
	// bfsWithNewLine(root1);

	// int in[] = {3,2,8,4,1,6,7,5};
	// int pre[] = {1,2,3,4,8,5,6,7};

	// int n = sizeof(in)/sizeof(int);
	// node* root2 = buildFromTraversal(in, pre, 0, n-1);
	// cout<<endl;
	// bfsWithNewLine(root2);

	int maxLevel = -1;
	cout<<"Right view: ";
	printRightView(root, 0, maxLevel);
	cout<<endl<<"Left view: ";
	int leftMaxLevel = -1;
	printLeftView(root, 0, leftMaxLevel);
	cout<<"Lca of 1 and 7 is: "<<lca(root, 1, 7)->data<<endl;


	return 0;
}

//8 10 1 -1 -1 6 4 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
//3 5 -1 1 -1 -1 4 2 -1 -1 -1