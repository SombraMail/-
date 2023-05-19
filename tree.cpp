#include <iostream>

using namespace std;

typedef struct tree {
	int value;
	struct tree* left;
	struct tree* right;
} tree_element;

tree_element* create_tree_element(int i);
void insert_into_tree(tree_element* root, tree_element* elem);
void leaves(tree_element* cur_elem, int rootV);
void show(tree_element* cur_elem, tree_element* root,string space, string newline, int flag);


tree_element* create_tree_element(int i) {
	tree_element* elem = new tree_element;
	elem->value = i;
	elem->left = NULL;
	elem->right = NULL;
	return elem;
}

void insert_into_tree(tree_element* root, tree_element* elem) {
	if (elem->value < root->value) 
	{// идем в левое поддерево
		if (root->left == NULL)
		{
			root->left = elem;
		}
		else
		{
			insert_into_tree(root->left, elem);
		}
	}
	else 
	{// идем в правое поддерево
		if (root->right == NULL)
		{
			root->right = elem;
		}
		else
		{
			insert_into_tree(root->right, elem);
		}
	}
}

void leaves(tree_element* cur_elem, int rootV) {
	if (cur_elem->left != NULL) {
		leaves(cur_elem->left, rootV);
	}
	if (cur_elem->left == NULL && cur_elem->right == NULL) 
	{
		cout << "Leaf = " << cur_elem->value << endl;
		cout << "minus root = " << cur_elem->value - rootV<<endl;
		cout << endl;
	}
	if (cur_elem->right != NULL) {
		leaves(cur_elem->right, rootV);
	}
}

void show(tree_element* cur_elem, tree_element* root, string space, string newline, int flag)
{	
	if ((cur_elem->left != NULL || cur_elem->right != NULL) && cur_elem == root && flag == 0)
	{
		cout << space << cur_elem->value << endl << "                        " << "/" << "       " << "\\" << endl << "                     " << cur_elem->left->value << "           " << cur_elem->right->value;
		
	}
	else if((cur_elem->left != NULL || cur_elem->right != NULL) && cur_elem != root && flag == 0)
	{	
	cout << newline<< space << "/" << " " << "\\" << endl << "                  " << cur_elem->left->value << "     " << cur_elem->right->value;
	}
	else if ((cur_elem->left != NULL && cur_elem->right != NULL) && flag == 1)
	{
		cout << newline << space << "/" << " " << "\\" ;
		cout << endl << space << "                          " << "/" << "   " << "\\";
		cout << endl <<"                              "<< cur_elem->left->value << "      " << cur_elem->right->value;
	}

	if (cur_elem->left != NULL && cur_elem->right != NULL) {
		show(cur_elem->left,root,"                     ", "\n",0);
		show(cur_elem->right, root, "      ", "",1);
		
	}
	
}

int main(){
	int a[6] = {2,-2,1,-1,3,-3};
	int R = 1;
	tree_element* root = create_tree_element(R);
	for (int i = 0; i < 6; i++) {
		tree_element* el = create_tree_element(a[i]);
		insert_into_tree(root, el);
	}
	leaves(root, R);
	cout << endl;
	cout << endl;
	show(root, root, "                            ", "",0);
	return 0;
}
