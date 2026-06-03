package struct;

public class UnionFind {

    private int[] fd;

    private int count;

    public UnionFind(int size){
        count = size;
        fd = new int[size];
        for(int i = 0; i < size; i++){
            fd[i] = i;
        }
    }

    public void join(int a, int b){
        if(isSame(a,b)){
            return;
        }
        fd[getRoot(a)]=fd[getRoot(b)];
    }

    public int getRoot(int a){
        if(a == fd[a]){
            return a;
        }
        int root = getRoot(fd[a]);
        fd[a] = root;
        return root;
    }

    public boolean isSame(int a, int b){
        return getRoot(a) == getRoot(b);
    }
}
