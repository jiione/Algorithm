import java.io.*;
import java.util.*;

public class Main {
    static final int MAXV = 100;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int[] A = new int[N];
        {
            String[] s = br.readLine().split(" ");
            for (int i = 0; i < N; i++) A[i] = Integer.parseInt(s[i]);
        }

        int M = Integer.parseInt(br.readLine());
        int[] B = new int[M];
        {
            String[] s = br.readLine().split(" ");
            for (int i = 0; i < M; i++) B[i] = Integer.parseInt(s[i]);
        }

        int[][] nextA = buildNext(A, MAXV);
        int[][] nextB = buildNext(B, MAXV);

        List<Integer> ans = new ArrayList<>();
        int ia = 0, ib = 0;

        while (ia < N && ib < M) {
            boolean picked = false;
            for (int v = MAXV; v >= 1; v--) {
                int pa = nextA[ia][v];
                if (pa == -1) continue;
                int pb = nextB[ib][v];
                if (pb == -1) continue;

                ans.add(v);
                ia = pa + 1;
                ib = pb + 1;
                picked = true;
                break; // 다음 자리도 최댓값부터 다시 탐색
            }
            if (!picked) break;
        }

        StringBuilder sb = new StringBuilder();
        sb.append(ans.size()).append('\n');
        for (int i = 0; i < ans.size(); i++) {
            if (i > 0) sb.append(' ');
            sb.append(ans.get(i));
        }
        System.out.println(sb);
    }

    // next[i][v] = i 이상에서 v가 처음 나오는 인덱스, 없으면 -1
    static int[][] buildNext(int[] arr, int MAXV) {
        int L = arr.length;
        int[][] next = new int[L + 1][MAXV + 1];
        for (int v = 1; v <= MAXV; v++) next[L][v] = -1;     // 경계

        for (int i = L - 1; i >= 0; i--) {
            // 다음 상태를 복사
            for (int v = 1; v <= MAXV; v++) next[i][v] = next[i + 1][v];
            // 현재 값 위치 등록
            next[i][arr[i]] = i;
        }
        return next;
    }
}
