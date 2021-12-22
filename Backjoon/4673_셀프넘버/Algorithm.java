public class Algorithm {
    public static void main(String[] args) {
        int[] count=new int[10001];
        int num;
        int sum;
        for(int i=1;i<=10000;i++){
            num=i;
            sum=i;
            for(int j=0;num!=0;j++){
                sum+=num%10;
                num/=10;
            }
            if(sum<=10000) count[sum]=1;
        }
        for(int i=1;i<=10000;i++){
            if(count[i]!=1) System.out.println(i);
        }
    }
}
