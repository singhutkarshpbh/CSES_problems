import java.util.*;
public class Manachar {
    public static class manachar{
        int p[];
        void run_manachar(String sb){
            char s[]=sb.toCharArray();
            int n=s.length;
            System.out.println(sb.toString());
            p=new int[n];
            Arrays.fill(p,1);
            int l=1;
            int r=1;
            for(int i=1;i<n;i++){
                int mirror=l+r-i;
                if(r-i>=0 && mirror>=0 && mirror<n){
                    p[i]=Math.max(0,Math.min(r-i,p[l+r-i]));
                }
                while(i+p[i]<n && i-p[i]>=0 && s[i-p[i]]==s[i+p[i]]){
                    p[i]++;
                }
                if(i+p[i]>r){
                    l=i-p[i];
                    r=i+p[i];
                }
            }
            for(int it:p){
                System.out.print(it+" ");
            }
        }
        void build(String s){
            StringBuilder sb=new StringBuilder();
            sb.append("#");
            for(int i=0;i<s.length();i++){
                sb.append(s.charAt(i));
                sb.append("#");
            }
            run_manachar(sb.toString());
        }
        int getLongest(int cen,boolean odd){
            int pos=2*cen+1+(!odd?1:0);
            return p[pos]-1;
        }
        boolean checkPalin(int l,int r){
            if(r-l+1<=getLongest((l+r)/2,l%2==r%2)) return true;
            else return false;
        }
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        String s=sc.next();
        Manachar m=new manachar();
        m.build(s);
        

    }
}
