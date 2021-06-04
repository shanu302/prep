// We have to track Head, grand_parent , parent and this is done using morris traversal. 
//https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/
// This function should return head to the DLL
class Solution
{
    public: 
   
    Node * bToDLL(Node *root)
    {   Node *grand_parent=NULL;
        bool f=0;
        Node *head=root;
        Node* parent=NULL;
        while(root!=NULL)
        {   parent=root;
            if(root->left)
            {   root=root->left;
                Node* temp=root;
                while(temp->right)
                {   temp=temp->right;
                }
                if(!grand_parent)
                {   parent->left=NULL;
                    temp->right=parent;
                }
                else
                {   grand_parent->right=root;
                    parent->left=NULL;
                    temp->right=parent;
                }
            }
            else
            {   if(f==0)
                {   head=root;
                    f=1;
                }
                root=root->right;
                grand_parent=parent;
            }
        }
        Node *dummy=head;
        while(dummy->right)
        {   dummy->right->left=dummy;
            dummy=dummy->right;
        }
        return head;
    }
};
