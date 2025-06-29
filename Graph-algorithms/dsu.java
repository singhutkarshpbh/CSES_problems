import java.util.*;
public class dsu{
  dsu{
    int parent[];
    int size[];
    dsu(int n){
      parent=new int[n+1];
      size=new int[n+1];
      for(int i=0;i<=n;i++){
        parent[i]=i;
        size[i]=1;
      }
    }
    int getParent(int u){
      if(u!=parent[u]) return parent[u]=getParent(u);
      return parent[u];
    }
    void union(int u,int v){
      int p1=getParent(u);
      int p2=getParent(v);
      if(p1==p2) return ;
      if(size[p1]>size[p2]){
        size[p1]+=size[p2];
        parent[p2]=p1;
      }
      else{
        size[p2]+=size[p1];
        parent[p1]=p2;
      }
    }
  }
  public static void main(String[]args){
    Scanner sc=new Scanner(System.in);
    int n=sc.nextInt();
    dsu d=new dsu(n);
  }
}
