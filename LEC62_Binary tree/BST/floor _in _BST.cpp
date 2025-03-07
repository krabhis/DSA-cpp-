class Solution{
public:
    int floor(Node* root, int x) {
        if (root == NULL) return -1;
        
        int floor = -1;
        
        while (root) {
            if (root->data == x) {
                return root->data;
            } 
            else if (root->data < x) {
                floor = root->data;
                root = root->right;
            } 
            else {
                root = root->left;
            }
        }
        
        return floor;
    }
};

//make fllor variable and conditions pe check kr floor ko update kro aur aage badho