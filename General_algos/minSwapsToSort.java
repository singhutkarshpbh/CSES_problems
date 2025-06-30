package CSES_problems.General_algos;

import java.util.*;

public class minSwapsToSort {
    static void dis(int arr[],int st,int end){
        for(int i=st;i<end;i++){
            System.out.print(arr[i]+" ");
        }
        System.out.println();
    }
    static int minSwapsToSort(int arr[]){
        int n=arr.length;
        int temp[]=arr.clone();
        Arrays.sort(temp);
        Map<Integer,Integer> mp=new HashMap<>();
        int swap=0;
        for(int i=0;i<n;i++) mp.put(arr[i],i);
        for(int i=0;i<n;i++){
            if(arr[i]!=temp[i]){
                int idx=mp.get(temp[i]);
                int data=arr[i];
                arr[i]=temp[i];
                arr[idx]=data;
                mp.put(data,idx);
                swap++;
            }
        }
        return swap;
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int arr[]=new int[n];
        for(int i=0;i<n;i++){
            arr[i]=sc.nextInt();
        }
        dis(arr,0,n);
        int x=minSwapsToSort(arr);
        System.out.println(x);
        dis(arr,0,n);

    }
}