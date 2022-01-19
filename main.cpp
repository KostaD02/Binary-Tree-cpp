#include <iostream>

using namespace std;

template <typename T> class Node { 
	public: 
		T data; 
		Node* left; 
		Node* right;
};

template <typename T> class BinTree{
	private:
		Node<T> *root;
		void insert(T key,Node<T> *leaf){
			if(key<leaf->data){
				if(leaf->left != NULL){
					insert(key,leaf->left);
				}else{
					leaf->left = new Node<T>;
					leaf->left->data = key;
					leaf->left->left = NULL;
					leaf->left->right = NULL;
					length+=1;
				}
			}else if(key>=leaf->data){
				if(leaf->right != NULL){
					insert(key,leaf->right);
				}else{
					leaf->right = new Node<T>;
					leaf->right->data = key;
					leaf->right->right = NULL;
					leaf->right->left = NULL;
					length+=1;
				}
			}
		}
		void destroyTree(Node<T> *leaf){
			if(leaf != NULL){
				destroyTree(leaf->left);
				destroyTree(leaf->right);
				delete leaf;
			}
		}
		void inorderPrint(Node<T> *leaf){
			if(leaf != NULL){
				inorderPrint(leaf->left);
				cout<<leaf->data<<"  ";
				inorderPrint(leaf->right);
			}else{
				cout<<" There is no element";
			}
		}
		void postorderPrint(Node<T> *leaf){
			if(leaf != NULL){
				inorderPrint(leaf->left);
				inorderPrint(leaf->right);
				cout<<leaf->data<<"  ";
			}else{
				cout<<" There is no element";
			}
		}
		void preoderPrint(Node<T> *leaf){
			if(leaf != NULL){
				cout<<leaf->data<<"  ";
				inorderPrint(leaf->left);
				inorderPrint(leaf->right);
			}else{
				cout<<" There is no element";
			}
		}
		Node<T> *search(T key,Node<T> *leaf){
			if(leaf != NULL){
				if(key == leaf->data){
					return leaf;
				}
				if(key<leaf->value){
					return search(key,leaf->left);
				}else{
					return search(key,leaf->right);
				}
			}else{
				return NULL;
			}
		}
	public:
		unsigned int length;
		BinTree(){
			root = NULL;
			length = 0;
		}
		~BinTree(){
			destroyTree();
		}
		void insert(T key){
			if(root != NULL){
				insert(key,root);
			}else{
				root = new Node<T>;
				root->data = key;
				root->left = NULL;
				root->right = NULL;
				length+=1;
			}
		}		
		void destroyTree(){
			destroyTree(root);
		}
		void inorderPrint(){
			inorderPrint(root);
			cout<<endl;
		}
		void postorderPrint(){
			postorderPrint(root);
			cout<<endl;
		}
		void preoderPrint(){
			preoderPrint(root);
			cout<<endl;
		}
		Node<T> *search(T key){
			return search(key,root);
		}
		unsigned int getLength(){
			return length;
		}		
};

int main(int argc, char** argv) {
	BinTree<int> *binTree = new BinTree<int>;
	for(int i=1;i<=5;i++){
		binTree->insert(i);
	}
	cout<<" Inorder : ";
	binTree->inorderPrint();
	cout<<" Preorder : ";
	binTree->preoderPrint();
	cout<<" Postorder : ";
	binTree->postorderPrint();
	cout<<" Length : "<<binTree->length<<endl;
	return 0;
}