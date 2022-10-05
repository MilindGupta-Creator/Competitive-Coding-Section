import java.util.LinkedList;
import java.util.Queue;

class BST{
    int info;
    BST right,left,root;
    BST(){
        this.root=null;
    }
    BST(int info){
        this.info=info;
        this.left=null;
        this.right=null;
    }

    void insert(int info){
        BST n=new BST(info);
        if(root==null){
            root=n;
            return;
        }
        BST prev=null,ptr=root;
        while(ptr!=null){
            prev=ptr;
            if(ptr.info<n.info){
                ptr=ptr.right;
            }
            else{
                ptr=ptr.left;
            }
        }
        if(n.info>prev.info){
            prev.right=n;
        }
        else{
            prev.left=n;
        }
    }

    BST insertRec(BST root,int info){ //insert node recursively
        if(root==null){
            root=new BST(info);
            return root;
        }
        if(info>root.info){
            root.right=insertRec(root.right,info);
        }
        else{
            root.left=insertRec(root.left,info);
        }
        return root;
    }

    int search(int info){
        if(root==null){
            return -1;
        }
        BST ptr=root;
        while(ptr!=null && ptr.info!=info){
            if(ptr.info<info){
                ptr=ptr.right;
            }
            else{
                ptr=ptr.left;
            }
        }
        if(ptr==null){
            return -1;
        }
        return ptr.info;
    }

    void delete(int info){  //corrected 
        if(root==null){
            System.out.println("Underflow");
            return;
        }
        else if(root.info==info){
            if(root.left==null && root.right==null){  //no child
                root=null;
            }
            else if(root.left!=null && root.right==null){  //one left child
                root=root.left;
            }
            else if(root.left==null && root.right!=null){   //one right child
                root=root.right;
            }
            else if(root.left!=null && root.right!=null){ //two childs
                BST pre=root.right,ptr=root.right;   //approach is to find smallest in right subtree(inorder successor)
                while(ptr.left!=null){
                    pre=ptr;
                    ptr=ptr.left;
                }
                if(ptr==pre){
                    root.info=ptr.info;
                    root.right=ptr.right;
                }
                else{
                    root.info=ptr.info;
                    pre.left=ptr.right;
                }
            }
        }
        else{
            BST ptr=root;
            BST pre=root;
            while(ptr!=null && ptr.info!=info){
                pre=ptr;
                if(ptr.info<info){
                    ptr=ptr.right;
                }
                else{
                    ptr=ptr.left;
                }
            }
            if(ptr==null){
                System.out.println("No such Element");
                return;
            }
            if(ptr.right==null && ptr.left==null){  //leaf node
            if(ptr==pre.right){
                pre.right=null;
              }  
            else{
                pre.left=null;
              }     
            }
            else if(ptr.left!=null && ptr.right==null){ //one left child
                if(ptr==pre.right){
                    pre.right=ptr.left;
                }
                else{
                    pre.left=ptr.left;
                }
            }
            else if(ptr.left==null && ptr.right!=null){ //one right child
                if(ptr==pre.right){
                    pre.right=ptr.right;
                }
                else{
                    pre.left=ptr.right;
                }
            }
            else if(ptr.left!=null && ptr.right!=null){ //two childs  
                pre=ptr;
                ptr=pre.left;
                BST l=pre.left; //here is the approach to find largest in left subtree (inorder predecessor)
                while(l.right!=null){
                    ptr=l;
                    l=l.right;
                }
                if(l==ptr){
                    pre.info=l.info;
                    pre.left=l.left;
                }
                else{
                    pre.info=l.info;
                    ptr.right=l.left;                    
                }
            }
        }
    }

    BST deleteRec(BST root,int key){
        if(root==null){
            return null;
        }
        else if(key<root.info){
            root.left=deleteRec(root.left,key);
        }
        else if(key>root.info){
            root.right=deleteRec(root.right, key);
        }
        else{
            BST temp=null;
            if(root.left==null && root.right==null){
                return null;
            }
            else if(root.left!=null){
                temp=root.left;
                return temp;
            }
            else if(root.left==null){
                temp=root.right;
                return temp;
            }
            else{
                temp=maxnode(root);
                root.info=temp.info;
                root.left=deleteRec(root.left, temp.info);
            }
        }
        return root;
    }

    BST maxnode(BST root){
        BST curr=root;
        while(curr.right!=null){
            root=root.right;
        }
        return root;
    }

    int height(BST n){
        if(n==null){
            return 0;      //return -1; this is for height=depth-1 , return 0 is used for most of the cases,problem will rise in printlevelorderlevelwise
        }
        else{
            int lh=height(n.left);
            int rh=height(n.right);
            if(lh>rh){
                return lh+1;
            }
            else{
                return rh+1;
            }
        }
    }

    int depth(BST n){
        if(n==null){
            return 0;
        }
        else{
            int lh=depth(n.left);
            int rh=depth(n.right);
            if(lh>rh){
                return lh+1;
            }
            else{
                return rh+1;
            }
        }
    }
    
    int BalanceFactor(BST n){
        if(n==null)
              return -1;
        else{
                  int lh=height(n.left);
                  int rh=height(n.right);
                  return lh-rh;
            }
    }

    Boolean isBalanced(BST n){
        if(n==null){
            return true;
        }
        int lh=height(n.left);
        int rh=height(n.right);
        if((lh-rh>=-1) && (lh-rh<=1) && isBalanced(n.left) && isBalanced(n.right)){
            return true;
        } 
        else{
            return false;
        }
    }

    BST NCA(BST root,int n1,int n2){  //nearest/lowest common ancestor ie.nearest lowest common ancestor if one of node is ancestor include it
        if(root==null)
            return null;
        if(n1>root.info && n2>root.info){
            return NCA(root.right, n1, n2);
        }
        if(n1<root.info && n2<root.info){
            return NCA(root.left, n1, n2);
        }
        // if((root.info>n1 && root.info<n2) || (root.info<n1 && root.info>n1)){
        //     return root;
        // }
        // if(root.info==n1 || root.info==n2){
        //     return root;
        // }
        return root;
    }

    BST LCA(BST root,int n1,int n2){  //least common ancestor //practice on gfg
        if(root==null){
            return null;
        }
        if((root.info>n1 && root.info<n2) || (root.info<n1 && root.info>n1)){
            return root;
        }
        if(n1>root.info && n2>root.info){
            return root;
        }
        if(root.left.info!=n1 || root.left.info!=n2){
            return LCA(root.left, n1, n2);
        }
        else{
            return root;
        }
    }

    void LLR(BST root){    // Leaf nodes left to right
        if(root==null){
            return;
        }
        if(root.left==null && root.right==null){
            System.out.print(root.info+" ");
        }
        if(root.left!=null){
            LLR(root.left);
        }
        if(root.right!=null){
            LLR(root.right);
        }
    }

    void LRL(BST root){     // Leaf nodes right to left
        if(root!=null){
            if(root.right==null && root.left==null){
                System.out.print(root.info+" ");
            }
            if(root.right!=null){
                LRL(root.right);
            }
            if(root.left!=null){
                LRL(root.left);
            }
        }
    }

    BST mirror(BST root){
        if(root==null){
            return null;
        }
        BST l=mirror(root.left);
        BST r=mirror(root.right);
        root.left=r;
        root.right=l;
        return root;
    }
//////////////////////////////////////////////////////
    void printExterior(BST root){   //print boundary/exterior elements anticlockwise
        System.out.print(root.info+" ");
        leftarm(root.left);
        LLR(root);
        rightarm(root.right);
    }

    void leftarm(BST root){
        if(root==null){
            return;
        }
        if(root.right==null && root.left==null){
            return;
        }
        System.out.print(root.info+" ");
        if(root.left==null && root.right!=null){
            leftarm(root.right);
        }
        else{
            leftarm(root.left);
        }
    }

    void rightarm(BST root){
        if(root==null){
            return;
        }
        if(root.left==null && root.right==null){
            return;     
        }
        if(root.left!=null && root.right==null){
            rightarm(root.left);
        }
        else{
            rightarm(root.right);
        }
        System.out.print(root.info+" ");
    }
 //////////////////////////////////////////////////// 

 //$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ 
    void printLevelOrderLevelWise(BST root){  //recursive approach
        int height=height(root);
        for(int i=1;i<=height;i++){
            levelwise(root,i);
            System.out.println(); //remove this for output in one line
        }
    }

    void printLevelOrderLevelWiseReverse(BST root){
        int height=height(root);
        for(int i=height;i>=1;i--){
            levelwise(root, i);
            System.out.println(); 
        }
    }
    void levelwise(BST root,int l){
        if(root==null){
            return;
        }
        if(l==1){
            System.out.print(root.info+" ");
        }
        else if(l>1){
            levelwise(root.left, l-1);
            levelwise(root.right, l-1);
        }
    }
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$   

//######################################################
    void spiralprint(BST root){    //recursive approach for spiral traverse
        int height=height(root);
        int flag=1;
        for(int i=1;i<=height;i++){
            if(flag==0){
                levelwiseleftToright(root,i);
                flag=1;
            }
            else{
                levelwiserightToleft(root, i);
                flag=0;
            }            
            System.out.println(); 
        }
    }

    void spiralprintReverse(BST root){
        int height=height(root);
        int flag=1;
        for(int i=height;i>=1;i--){
            if(flag==1){
                levelwiseleftToright(root,i);
                flag=0;
            }
            else{
                levelwiserightToleft(root, i);
                flag=1;
            }            
            System.out.println(); 
        }
    }

    void levelwiseleftToright(BST root,int l){
        if(root==null){
            return;
        }
        if(l==1){
            System.out.print(root.info+" ");
        }
        else if(l>1){
            levelwiseleftToright(root.left, l-1);
            levelwiseleftToright(root.right, l-1);
        }
    }

    void levelwiserightToleft(BST root,int l){
        if(root==null){
            return;
        }
        if(l==1){
            System.out.print(root.info+" ");
        }
        else if(l>1){
            levelwiserightToleft(root.right, l-1);
            levelwiserightToleft(root.left, l-1);
        }
    }
//#####################################################

    BST rightRotate(BST root){
        if(root==null){
            return null;
        }
        if(root.left!=null){
            BST temp=root;
            root=root.left;
            temp.left=root.right;
            root.right=temp;
        }
        return root;
    }

    BST rightRotate(int data){
        if(root==null){
            return null;
        }
        if(root.info==data){
            if(root.left!=null){
                BST l=root.left;
                root.left=l.right;
                l.right=root;
                root=l;
            }
        }
        else{
            BST pre=root,ptr=root;
            while(ptr.info!=data){
                pre=ptr;
                if(data>ptr.info){
                    ptr=ptr.right;
                }
                else{
                    ptr=ptr.left;
                }
            }
            if(ptr!=null && ptr.left!=null){
                BST l=ptr.left;
                ptr.left=l.right;
                l.right=ptr;
                if(ptr.info<pre.info){
                    pre.left=l;
                }
                else{
                    pre.right=l;
                }
            }
        }
        return root;
    }

    BST rightSkew(BST root) {  //some error in output
        if (root == null) {
            return null;
        }
        while (root.left != null) {
            BST temp = root;
            root = root.left;
            temp.left = root.right;
            root.right = temp;
        }
        return root;
    }

    BST leftRotate(BST root){
        if(root==null){
            return null;
        }
        if(root.right!=null){
            BST temp=root;
            root=root.right;
            temp.right=root.left;
            root.left=temp;
        }
        return root;
    }

    // BST leftRotate(int data){
    //     if(root==null){
    //         return null;
    //     }
    //     if(root.info==data && root.right!=null){
    //         BST r=root.right; 
    //         root.right=r.left;
                       
    //     }
    // }

    BST leftSkew(BST root){ //there is some error in output
        if(root==null){
            return null;
        }
        while(root.right!=null){
            BST temp=root;
            root=root.right;
            temp.right=root.left;
            root.left=temp;
        }
        return root;
    }

}

class BinarySearchTree {
    static void printInternalNodes(BST root){
        if(root==null){
            return;
        }
        Queue<BST> q = new LinkedList<>();
        q.add(root);
        while (!q.isEmpty()) {
            BST curr = q.peek();
            q.remove();
            if(curr.right!=null || curr.left!=null){
                System.out.print(curr.info + " ");
            }
            if (curr.left != null) {
                q.add(curr.left);
            }
            if (curr.right != null) {
                q.add(curr.right);
            }
        }
    }

    static void printLevelOrder(BST root) {  //without recursion
        if(root==null){
            return;
        }
        Queue<BST> q = new LinkedList<>();
        q.add(root);
        while (!q.isEmpty()) {
            BST curr = q.peek();
            q.remove();
            System.out.print(curr.info + " ");
            if (curr.left != null) {
                q.add(curr.left);
            }
            if (curr.right != null) {
                q.add(curr.right);
            }
        }
    }

    static void printLevelOrderLineByLine(BST root){ //this is without recursion
        if(root==null){
            return;
        }
        Queue<BST> q=new LinkedList<>();
        q.add(root);
        q.add(null);
        while(!q.isEmpty()){
            BST curr=q.peek();
            q.remove();
            if(curr==null){
                if(!q.isEmpty()){
                    q.add(null);
                    System.out.println();
                }
            }
            else{
                if(curr.left!=null){
                    q.add(curr.left);
                }
                if(curr.right!=null){
                    q.add(curr.right);
                }
                System.out.print(curr.info+" ");
            }
        }
    }

    static void printInorder(BST root){ 
        if(root!=null){
            printInorder(root.left);
            System.out.print(root.info+" ");
            printInorder(root.right);
        }
    }

    static void printPreorder(BST root){
        if(root!=null){
            System.out.print(root.info+" ");
            printPreorder(root.left);
            printPreorder(root.right);
        }
    }

    static void printPostorder(BST root){
        if(root!=null){
            printPostorder(root.left);
            printPostorder(root.right);
            System.out.print(root.info+" ");
        }
    }

    static BST sortedArrayToBinary(int arr[],int start,int end){
        if(start>end)
            return null;
        int mid=(start+end)/2;
        BST x=new BST(arr[mid]);
        x.left=sortedArrayToBinary(arr, start, mid-1);
        x.right=sortedArrayToBinary(arr, mid+1, end);
        return x;
    }

    public static void main(String[] args) {
        BST t=new BST();
        t.insert(5);
        t.insert(6);
        t.insert(12);
        t.insert(22);
        t.insert(3);
        t.insert(2);
        t.insert(45);
        t.insert(53);
        t.insert(122);
        t.insert(7);
        System.out.println("Height of tree is "+t.height(t.root));
        System.out.println("Depth of tree is "+t.depth(t.root));
        System.out.println("BalanceFactor of tree is "+t.BalanceFactor(t.root));
        System.out.println(t.search(7));
        System.out.println(t.isBalanced(t.root));
        System.out.println(t.search(2));
        System.out.println(t.search(122));
        System.out.println(t.search(18));
        System.out.println(t.search(45));
        printPreorder(t.root);
        System.out.println();
        printPostorder(t.root);
        System.out.println();
        System.out.println("Before deleting: ");
        printInorder(t.root);
        t.delete(45);
        t.delete(5);  //problem is after deleting root node
        t.delete(22);
        System.out.println();
        System.out.println("After deleting 45,5,22: ");
        printInorder(t.root);
        t.delete(2); //solved
        t.delete(3);
        System.out.println();
        System.out.println("After deleting 2,3: ");
        printInorder(t.root);  
        System.out.println();
        System.out.println("Exterior Nodes");
        t.printExterior(t.root); //bug
        BST x=new BST();
        x.insert(10);
        x.insert(9);
        x.insert(11);
        System.out.println(x.BalanceFactor(x.root));
        System.out.println(x.isBalanced(x.root));
        System.out.println((x.LCA(x.root, 9, 11)).info);
        x.insert(34);
        x.insert(54);
        x.insert(12);
        x.insert(22);
        x.insert(5);
        x.insert(6);
        x.LLR(x.root);
        System.out.println();
        x.LRL(x.root);
        System.out.println();
        printPreorder(x.root);
        BST mirrorx=x.mirror(x.root);
        System.out.println("Mirror image of x ");
        printPreorder(mirrorx);
        System.out.println();
        x.printExterior(x.root);
        BST y=new BST();
        y.insert(20);
        y.insert(10);
        y.insert(12);
        y.insert(8);
        y.insert(13);
        y.insert(22);
        y.insert(24);
        y.insert(26);
        System.out.println();
        y.printExterior(y.root);  
        System.out.println();
        BST test=new BST();
        test.insert(30);
        test.insert(15);
        test.insert(25);  
        test.insert(24);  
        test.insert(18);  
        test.insert(19);  
        test.insert(40);  
        test.insert(35);  
        test.insert(34);  
        test.insert(36);  
        test.insert(37);  
        test.insert(54);
        test.insert(13);
        test.insert(11);
        test.insert(65);
        test.insert(62);
        test.insert(86);
        test.insert(2);
        test.insert(26);
        test.insert(56);
        test.insert(87);
        test.insert(43);
        test.insert(73);
        test.insert(82);
        test.insert(97);
        test.insert(101);
        test.insert(80);
        test.insert(99);
        test.insert(91);
        test.insert(82);
        test.insert(110);
        test.insert(53);
        test.insert(27);
        test.insert(21);
        test.insert(66);
        test.insert(26);
        test.insert(32);
        test.insert(23);
        test.printExterior(test.root); 
        System.out.println();
        printLevelOrder(test.root); 
        System.out.println();
        printInternalNodes(test.root);
        System.out.println();
        test.LLR(test.root);
        System.out.println();
        test.printLevelOrderLevelWise(test.root);
        System.out.println();
        printLevelOrderLineByLine(test.root);
        System.out.println();
        System.out.println();
        test.printLevelOrderLevelWiseReverse(test.root);
        System.out.println();
        test.spiralprint(test.root);
        System.out.println();
        test.spiralprintReverse(test.root);
        System.out.println("Before rotation: ");
        printInorder(test.root);
        System.out.println();
        printLevelOrderLineByLine(test.root);
        System.out.println("\nAfter rotation: ");
        BST r=test.rightRotate(test.root);
        printInorder(r);
        System.out.println();
        printLevelOrderLineByLine(r);
        BST rs=test.rightSkew(test.root);
        System.out.println("\nRightSkew tree");
        printInorder(rs);
        System.out.println();
        printLevelOrderLineByLine(rs);
        BST l=test.leftRotate(test.root);
        BST ls=test.leftSkew(test.root);
        System.out.println("\nleft rotate");
        printInorder(l);
        System.out.println();
        printLevelOrderLineByLine(l);
        System.out.println("\nleft skew");
        printInorder(ls);
        System.out.println();
        printLevelOrderLineByLine(ls);
        System.out.println("\n");
        BST p=new BST();
        p.insert(20);
        p.insert(15);
        p.insert(16);
        p.insert(19);
        p.insert(18);
        printLevelOrder(p.root);
        p.delete(20);
        System.out.println();
        printLevelOrder(p.root);
        BST st=new BST(20);
        st.insertRec(st,11);
        st.insertRec(st, 25);
        st.insertRec(st,62);
        System.out.println("\n");
        printInorder(st);
        BST f=new BST();
        f.insert(10);
        f.insert(14);
        f.insert(5);
        System.out.println("\n"+f.BalanceFactor(f.root));
        System.out.println(f.height(f.root));
        f.insert(3);
        f.insert(17);
        f.insert(18);
        f.insert(11);
        f.insert(9);
        f.insert(6);
        f.insert(8);
        f.insert(2);
        f.insert(34);
        f.insert(12);
        f.insert(24);
        printInorder(f.root);
        System.out.println();
        f.printLevelOrderLevelWise(f.root);
        BST fn=f.rightRotate(8);
        printInorder(fn);
        System.out.println("\n");
        int arr[]={1,2,3,4,5,6,7,8,9};
        BST atb=sortedArrayToBinary(arr, 0, 8);
        printLevelOrderLineByLine(atb);
    }    
}
