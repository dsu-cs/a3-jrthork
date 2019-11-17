#pragma once

// include this library to use NULL, otherwise use nullptr instead
#include <cstddef>
#include <iostream>
#include "node.hpp"

template<class T>
class BST{
public:
    // Constructor for the BST class, creates an empty tree
    BST(void);
    // Destructor for the BST class, destroys the tree
    ~BST(void);
    // Inserts data into the tree
    // param: The data to be inserted into the tree
    void insert(T);
    // Removes data from the tree
    // param: The data to be removed from the tree
    void remove(T);
    // Performs an inorder traversal
    // returns: pointer to a vector containing the tree traversal
    std::vector<T> *inorder(void);
    // Performs an postorder traversal
    // returns: pointer to a vector containing the tree traversal
    std::vector<T> *postorder(void);
    // Performs an preorder traversal
    // returns: pointer to a vector containing the tree traversal
    std::vector<T> *preorder(void);
    // Searches the tree for a given value
    // param: the data to search for
    // returns: a pointer to the node containing the data or NULL if the data
    //          was not found
    Node<T> *search(T);
    // Gets the current number of nodes in the tree
    // returns: the number of nodes in the tree
    int get_size(void);
private:
    // the root node of the tree
    Node<T> *root;
    // the number of nodes in the tree
    int node_count;
};

template<class T>
BST<T>::BST()
{
    root = NULL;
    node_count = 0;
}

template<class T>
BST<T>::~BST()
{
    root = NULL;
    while(root != NULL)
    {
        remove(root->get_data());
    }
}

template<class T>
 std::vector<T> * BST<T>::inorder()
{
    	std::vector<T> *vec = new std::vector<T>;
	int size = get_size();
	Node<T> *cur = root; 
	if(cur == NULL)
	{
		return vec;
	}
	
		cur->get_left();
		vec->push_back(cur->get_data());
		cur->get_right();
	
    return vec;
}


template<class T>
 std::vector<T> * BST<T>::preorder()
{
    	std::vector<T> *vec = new std::vector<T>;
    	Node<T> *cur = root;
	
	vec->push_back(cur->get_data());
	cur->get_left();
	cur->get_right();
return vec;
}


template<class T>
 std::vector<T> * BST<T>::postorder()
{
    std::vector<T> *vec = new std::vector<T>;
	Node<T> *cur = root;
	cur->get_left();
	cur->get_right();
	vec->push_back(cur->get_data());
    return vec;
}

template<class T>
void BST<T>::insert(T new_data)
{
	Node<T> *cur;
	Node<T> *tmp;
	if(root == NULL)
	{
		root->set_data(new_data);
	}
	else 
	{
		cur = root;
		while(cur != NULL)
		{
			if(new_data < cur->get_data())
			{
				if(cur->get_left() == NULL)
				{
					tmp->set_data(new_data);
					cur->set_left(tmp);
					cur = NULL;
					delete(tmp);
				}
				else
				{
					cur = cur->get_left();
				}
			}
			else
			{
				if(cur->get_right() == NULL)
				{
					tmp->set_data(new_data);
					cur->set_right(tmp);
					cur = NULL;
					delete(tmp);
				}
				else
				{
					cur = cur->get_right();
				}
			}
		}
		
	}
		
	++node_count;
}


template<class T>
Node<T> *BST<T>::search(T val)
{
	Node<T> *cur = root;
	while(cur != NULL)
	{
		if(val == cur->get_data())
		{
			return cur;
		}
		else if(val < cur->get_data())
		{
			cur = cur->get_left();
		}
		else
		{
			cur = cur->get_right();
		}
	}
	return NULL;	
	
}



template<class T>
void BST<T>::remove(T val)
{
	Node<T> *suc;
	Node<T> *cur;
	cur = search(val);
	Node<T> *tmp;
	if(cur->get_left() == NULL && cur->get_right() == NULL)
	{
		delete(cur);
	}
	else if(cur->get_left() != NULL && cur->get_right() == NULL)
	{
		tmp->set_left(cur);
		tmp->set_left(cur->get_left());
		delete(cur);
	}
	else if(cur->get_left() == NULL && cur->get_right() != NULL)
	{
		tmp->set_right(cur);
		tmp->set_right(cur->get_right());
		delete(cur);
	}
	else if(cur->get_left() != NULL && cur->get_right() != NULL)
	{
		
		suc = cur->get_right();
		while(suc->get_left() != NULL)
		{
			suc = suc->get_left();
		}	
		tmp = suc;
		delete(suc);
		cur = tmp;
	}	
}



template<class T>
int BST<T>::get_size()
{
	int size = node_count;
	return size;
}
