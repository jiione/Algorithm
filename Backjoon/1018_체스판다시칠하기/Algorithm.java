import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int row, column;
        row=s.nextInt();
        column=s.nextInt();
        s.nextLine();
        String str;
        String tmp1="WBWBWBWB";
        String tmp2="BWBWBWBW";
        ArrayList<String> list= new ArrayList<>();
        ArrayList<String> s_black=new ArrayList<>();
        ArrayList<String> s_white=new ArrayList<>();
        for (int i=0;i<row;i++){
            str=s.nextLine();
            list.add(str);
        }
        for(int i=0;i<8;i++){
            if(i%2==0){
                s_black.add(tmp2);
                s_white.add(tmp1);
            }
            else{
                s_black.add(tmp1);
                s_white.add(tmp2);
            }
        }
        int check_w=0;
        int check_b=0;
        int min=1000;
        String in,w,b;
        for(int i=0;i<row-7;i++){
            for(int j=0;j<column-7;j++){
                check_w=0;
                check_b=0;
                for(int x=0;x<8;x++){
                    w=s_white.get(x);
                    b=s_black.get(x);
                    in=list.get(i+x);
                    for(int y=0;y<8;y++){
                        if(in.charAt(j+y)!=b.charAt(y)) check_b++;
                        if(in.charAt(j+y)!=w.charAt(y)) check_w++;
                    }
                }
                if(min>=check_b) min=check_b;
                if(min>=check_w) min=check_w;
            }
        }
        System.out.println(min);
    }
}
