#include "equal-paths.h"
using namespace std;


// You may add any prototypes of helper functions here


int leaf(Node * root)
{
	// if (root == NULL)
	// {
	// 	return 0;
	// }
    if (root -> left == nullptr && root -> right == nullptr)
    {
        return 0;
    }
    else if (root -> left == nullptr)
    {
				return 1 + leaf(root -> right);

    }
		else
		{
				return 1 + leaf(root->left);

		}
  return 0;
}

bool isSameHeight(int maxheight, int currHeight, Node* n)
{

    if (n -> left == nullptr && n -> right == nullptr)
    {
        if (currHeight != maxheight)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    if (n -> left == nullptr)
    {
        return isSameHeight(maxheight, currHeight + 1, n -> right);
    }
    else if (n -> right == nullptr)
    {
        return isSameHeight(maxheight,currHeight + 1, n -> left);
    }
    else
    {
        return isSameHeight(maxheight, currHeight + 1, n-> left) && isSameHeight(maxheight,currHeight + 1, n -> right);

    }
	
}   

bool equalPaths(Node * root)
{
		if (root == NULL)
		{
			return true;
		}
    // Add your code below
    int height =  leaf(root);
    return isSameHeight(height, 0, root);

}

