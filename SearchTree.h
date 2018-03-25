#pragma once 

typedef char SearchTreeType;

typedef struct SearchTreeNode {
	SearchTreeType key; // ¹Ø¼üÂë 
	struct SearchTreeNode* lchild;
	struct SearchTreeNode* rchild;
} SearchTreeNode;

void SearchTreeInit(SearchTreeNode** root);

void SearchTreeInsert(SearchTreeNode** root, SearchTreeType key);

SearchTreeNode* SearchTreeFind(SearchTreeNode* root,SearchTreeType to_find);

void SearchTreeRemove(SearchTreeNode** root, SearchTreeType key);