class NumArray {
public:
    int n;
    vector<int> vals;
    vector<int> tree;
    void build(int l,int r,int node){
        if(l==r){tree[node]=vals[l];return;}
        else{
            int mid=l+(r-l)/2;
            build(l,mid,2*node);
            build(mid+1,r,2*node+1);
            tree[node]=tree[2*node]+tree[2*node+1];
            return;
        }
    }
    void treeupd(int index,int val,int sl,int sr,int node){
        int mid=sl+(sr-sl)/2;
        if(sl==sr){tree[node]=val;}
        else if(index>mid){
            treeupd(index,val,mid+1,sr,2*node+1);
        }
        else 
        //if(index<mid){
        {
            treeupd(index,val,sl,mid,2*node);
        }
        if(sl!=sr){tree[node]=tree[2*node]+tree[2*node+1];}
    }
    int range(int l,int r,int sl,int sr,int node){
        if(l>sr){return 0;}
        if(r<sl){return 0;}
        if(l<=sl && r>=sr){return tree[node];}
        else{
            int mid=sl+(sr-sl)/2;
            return range(l,r,sl,mid,2*node)+range(l,r,mid+1,sr,2*node+1);
        }
    }

    NumArray(vector<int>& nums) {
        vals=nums;
        n=vals.size();
        tree.resize(4*n);
        build(0,n-1,1);
    }
    
    void update(int index, int val) {
        treeupd(index,val,0,n-1,1);
    }
    
    int sumRange(int left, int right) {
        return range(left,right,0,n-1,1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */