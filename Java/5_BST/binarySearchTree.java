public class binarySearchTree implements bstInterface {
    
    Node root; // Begining node
	    //  Constructor
	binarySearchTree() { root = null; }


    //          Defining functions
    
    //  1. INSERT ( Add element to right or left )
    public void insert(Integer value){ root = insert(root, value);}
    private Node insert(Node n, Integer value) {
        if(n == null)
            n = new Node(value);
        else {
            if(value <= n.data)
                n.left = insert(n.left, value);
            else
                n.right = insert(n.right, value);
        }
        return n;
    }
    
    
    //  2. DELETE 
	//	(i)   Deleting no child element
		public delete(Integer value){ }
	//	(ii)  Deleting 1 child element	
    
    //	(iii) Deleting 2 child element	
    
    
    //  3. SEARCH 
    public boolean contains(Integer value) { return contains(root, value);}
    private boolean contains(Node n, Integer value) {
        if(n == null)
            return false;
        else {
            if(value.equals(n.data))
                return true;
            else if(value < n.data)
                return contains(n.left, value);
            else
                return contains(n.right, value);
        }
    }
    
    
    //  4. Finding Maximum 
    public void maxm() { maxm(root); }
    private void maxm(Node temp) {
    	while(temp.right!=null) {
    		temp = temp.right;
    	}
    	System.out.print("\nMaximum value is ");
    	System.out.print(temp.data);
    }
    
    
    //  5. Finding Minimum 
    public void minm() { minm(root); }
    private void minm(Node temp) {
    	while(temp.left!=null) {
    		temp = temp.left;
    	}
    	System.out.print("\nMaximum value is ");
    	System.out.print(temp.data);
    }  
    
    
    //  6. PRINT ( Display elements )
    public void printInOrder() { printInOrder(root);}
    private void printInOrder(Node n) {
        if(n != null) {
            printInOrder(n.left);
            System.out.print(n.data + " ");
            printInOrder(n.right);
        }
    }
}