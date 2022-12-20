import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int num,ps;
        num=s.nextInt();
        ArrayList<Integer> list= new ArrayList<>();
        for(int i=0;i<num;i++){
            ps=s.nextInt();
            list.add(ps);
        }
        s.nextLine();
        int a,b;
        a=s.nextInt();
        b=s.nextInt();
        long result=0;
        int remain;
        for(int i=0;i<num;i++)
        {
            if(list.get(i)<=a) result++;
            else{
                remain=list.get(i)-a;
                result++;
                result+=remain/b;
                if(remain%b!=0)result++;
            }
        }
        System.out.println(result);
    }
}
